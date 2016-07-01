#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <set>
#include "Observer.h"

class Observable {
public:
	  virtual void add_observer(Observer& o)    { observers.insert(&o); }
	  virtual void delete_observer(Observer& o) { observers.erase(&o); }

	  virtual void notify_observers() {
		  for(auto& o : observers)
			  o->update(this);
	  }

	  virtual ~Observable() {}
private:
	std::set<Observer*> observers;
};



#endif /* OBSERVABLE_H_ */
