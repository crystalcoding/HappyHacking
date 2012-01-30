#include <vector>
#include <string>
#include <iostream>

//extern "C" {
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <fcntl.h>
#include <time.h>
//}

class directory_monitor {

public:
  directory_monitor() {}
  directory_monitor(const char* path) {}

  void start()
  {
    kq = kqueue();
    if (kq == -1) 
      std::cout << "cannot create kqueue" << std::endl;
    else
      std::cout << "kqueue value: " << kq << std::endl;

    //struct kevent filter;
    struct kevent *triggered;
    //int status = kevent(kq, &filter, 1, &triggered, 1, NULL);
    
    struct timespec ts;
    ts.tv_sec = 3;
    ts.tv_nsec = 0;
    print_event(ev);
    for(;;){
      
      //re-initialized ev's filter and flags, and fflags?
      add_event(ev, fd, EVFILT_VNODE, 
                    EV_ADD|EV_ENABLE|EV_CLEAR,
		    NOTE_WRITE|NOTE_RENAME ,  0, 0);
      //what is this line!!!!!!!!!!!!!
      
      ev_triggered = (struct kevent*)malloc(sizeof(struct kevent*));
      if (!ev_triggered){
	std::cout << "cannot allocated ev_triggered" << std::endl;
	exit(1);
      }
	
      int status = kevent(kq, ev,1 , ev, 1, &ts);
      print_event(ev);
      std::cout << "status: " << status << std::endl;
      if (status < 0)
	std::cout << "kevent() error" << std::endl;
      if (status == 0){
	/*timeout*/
	std::cout << "kevent() timeout " << std::endl;

      }
      else {
	std::cout << "kevent() detects change(s) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        if (ev->filter & EVFILT_VNODE)
	  std::cout << "EVFILT_VNOTE event" << std::endl;
	/*
	if ( ev_triggered->flags & NOTE_WRITE)
	  std::cout << "NOTE_RENAME triggered" << std::endl;
	else if ( ev_triggered->flags & NOTE_FORK)
	  std::cout << "NOTE_FORK triggered" << std::endl;
	else {
	  std::cout << "triggered.flags: "			\
		    << std::hex << ev->flags << std::endl;
	

	  print_event(ev);
	  std::cout << "------" << std::endl;
          print_event(ev_triggered);
        }
	*/
      }
	free(ev_triggered);
	ev_triggered = 0;
    }
  }
  void add_event(struct kevent* evt, int fdt, short filter, 
                u_short flag, u_int fflags, intptr_t data, void *udata)
  {
    ev = evt;
    fd = fdt;
    EV_SET(evt, fd, filter,
                flag, fflags , 0, 0);
  }
  //keep the last three argumetns for future use

  void print_event(struct kevent* event)
  {
    std::cout << "fd:" << event->ident << std::endl;
    std::cout << "filter:" << event->filter << std::endl;
    std::cout << "flags:" << event->flags << std::endl;
    std::cout << "fflags:" << event->fflags << std::endl;

  }
  
  ~directory_monitor() 
  {
    free(ev);
    ev = 0;
    //remember to free the memory
  }

private:
  int kq;
  struct kevent *ev;
  int fd;
  struct kevent *ev_triggered; //stored the triggered events
  std::vector<std::string> file_list;
  //vector<struct kevent> kevent_list;
  

  
};

int main( /*int argc, int* argv[] */)
{
  //struct kevent k; //can't use "kevent k" ?
 
  const char* path = "/150gb/150gb-bps/download/test";
  directory_monitor monitor(path);
  int fd = open(path, O_RDONLY);
  if (fd == -1 ) {
    std::cout << "fd open failed" << std::endl;
    exit(1);
  }
  struct kevent *ev;
  ev =  (struct kevent*)malloc(sizeof(struct kevent));
  if (!ev)
    std::cout << "couldn't allocate memory for kevents" << std::endl;
  monitor.add_event(ev, fd, EVFILT_VNODE, 
                    EV_ADD|EV_ENABLE|EV_CLEAR,
		    NOTE_WRITE|NOTE_RENAME|NOTE_DELETE ,  0, 0);
  monitor.start();
}
