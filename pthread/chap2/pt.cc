#include <pthread.h>
#include <unistd.h> //UnixStandard, for sleep
#include <iostream> 

void *thread_routine(void *arg)
{
  std::cout << "from a thread(pthread_self)" << pthread_self() 
     << std::endl;
  sleep(3); //in second
  return arg;
}

int main()
{
  pthread_t thread_id;
  void *thread_result;
  int status;

  std::cout << "test" << std::endl;
  pthread_create(&thread_id, NULL, thread_routine, NULL);
  std::cout << "thread_id:" << thread_id << std::endl;
  status = pthread_join(thread_id, &thread_result);
  std::cout << "status is:" << status << std::endl;
  return 0;
}
