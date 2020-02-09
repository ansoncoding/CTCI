#include "pch.h"
#include "AnimalShelter.h"
#include <iostream>

using namespace std;

void AnimalShelter::copy(const AnimalShelter& other) {
	cats = other.cats;
	dogs = other.dogs;
}

AnimalShelter::AnimalShelter() {

}
AnimalShelter::~AnimalShelter() {

}
AnimalShelter::AnimalShelter(const AnimalShelter& other) {
	copy(other);
}
AnimalShelter& AnimalShelter::operator=(const AnimalShelter& other) {
	if (&other != this) {
		copy(other);
	}
	return *this;
}

void AnimalShelter::enqueue(AnimalType t) {
	currentID++;
	Animal a = Animal(t, currentID);
	
	if (t == dog) {
		dogs.append(a);
	}
	else {
		cats.append(a);
	}
}

Animal* AnimalShelter::dequeueAny() {
	if (cats.isEmpty() && dogs.isEmpty()) {
		cerr << "No animals in animal shelter" << endl;
		return nullptr;
	}
	else if (cats.isEmpty()) {
		Animal *retval = new Animal(dogs.peek()); // make a copy before returning.
		dogs.remove();
		return retval;
	}
	else if (dogs.isEmpty()) {
		Animal* retval = new Animal(cats.peek());
		cats.remove();
		return retval;
	}
	else {
		
		Animal cat = cats.peek();
		Animal dog = dogs.peek();
		Animal *retval = cat.isOlderThan(dog) ? new Animal(cat) : new Animal(dog);
		if (cat.ID < dog.ID) {
			cats.remove();
		}
		else {
			dogs.remove();
		}
		return retval;
	}
}
Animal* AnimalShelter::dequeueDog() {
	if (dogs.isEmpty()) {
		cerr << "No more dogs at shelter" << endl;
		return nullptr;
	}
	Animal* retval = new Animal(dogs.peek());
	dogs.remove();
	return retval;
}

Animal* AnimalShelter::dequeueCat() {
	if (cats.isEmpty()) {
		cerr << "No more cats at shelter" << endl;
		return nullptr;
	}
	Animal* retval = new Animal(cats.peek());
	cats.remove();
	return retval;
}