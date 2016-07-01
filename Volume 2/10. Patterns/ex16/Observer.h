/*
Create a minimal Observer-Observable design in two classes,
without base classes and without the extra arguments in Observer.h
and the member functions in Observable.h. Just create the bare minimum
in the two classes, and then demonstrate your design by creating one
Observable and many Observers and cause the Observable to update the Observers.
*/

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observable;

class Observer {
public:
	virtual void update(Observable* o) = 0;
	virtual ~Observer() {}
};

#endif /* OBSERVER_H_ */
