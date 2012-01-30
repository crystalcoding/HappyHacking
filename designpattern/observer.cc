#include <list>
#include <string>
#include <iostream>

class Subject;

class Observer {
public:
  virtual ~Observer();
  //virtual void update(Subject* theChangedSubject) = 0;
  virtual void update() = 0;
protected:
  Observer();
};

Observer::Observer() {}
Observer::~Observer() {}

class Subject {
public:
  virtual ~Subject();
  
  virtual void Attach(Observer*);
  virtual void Detach(Observer*);
  virtual void Notify();
protected:
  Subject();
private:
  std::list<Observer*> *_observers;
};

Subject::Subject() {}
Subject::~Subject() {}

void Subject::Attach(Observer* observer){
  _observers->push_front(observer);
}

void Subject::Detach(Observer* observer){
  _observers->remove(observer); //really remove?
}

void Subject::Notify(){
  //std::cout << "Notify() is called" << std::endl;
  std::list<Observer*>::const_iterator obs_iterator;
  for(obs_iterator = _observers->begin();
      obs_iterator != _observers->end(); ++obs_iterator){
    //std::cout << "in the loop of Notify()" << std::endl;
    (*obs_iterator)->update(); //note, update(this), take parameter
  }
}

class Victoria: public Subject {
public:
  Victoria();

  virtual std::string getMessage();

  void doing_meeting(std::string);
private:
  std::string _message;
};

Victoria::Victoria() {}

std::string Victoria::getMessage(){
  return _message;
}

void Victoria::doing_meeting(std::string result="meeting result"){
  _message = result;
  Notify();
}

class emily: public Observer {
public:
  emily(Victoria*);
  virtual ~emily();
  void update();

private:
  Victoria* _subject;
};

emily::emily(Victoria* s){
  _subject = s;
  _subject->Attach(this);
}

emily::~emily(){
  _subject->Detach(this);
}

void emily::update(){
  std::cout << "emily get an update:" << _subject->getMessage() << std::endl;  
}

class sister: public Observer {
public:
  sister(Victoria*);
  ~sister();
  void update();
private:
  Victoria* _subject;
};

sister::sister(Victoria* s){
  _subject = s;
  _subject->Attach(this);
}

sister::~sister(){
  _subject->Detach(this);
}

void sister::update(){
  std::cout << "sister get an update:" << _subject->getMessage() << std::endl;
}

int main(){
  Victoria* vt = new Victoria();
  emily* e_observer = new emily(vt);
  sister* s_observer = new sister(vt);

  int dummy;
  std::cout << "ready to send notify, enter something..." << std::endl;
  std::cin >> dummy;
  //now CEO of Victoria has a meeting
  vt->doing_meeting();
  std::cin >> dummy;

  delete e_observer;
  delete s_observer;
}
