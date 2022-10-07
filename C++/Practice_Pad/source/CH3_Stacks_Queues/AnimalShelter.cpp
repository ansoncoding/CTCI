#include "pch.h"
#include "AnimalShelter.h"
#include <iostream>

using namespace std;

void AnimalShelter::copy(const AnimalShelter& other) {
	cats = other.cats;
	dogs = other.dogs;
	nextID = other.nextID;
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

	Animal a = Animal(t, nextID);
	
	if (t == dog) {
		dogs.append(a);
	}
	else {
		cats.append(a);
	}
	nextID++;
}

Animal AnimalShelter::dequeueAny() {
	if (cats.isEmpty() && dogs.isEmpty()) {
		throw OutofAnimalsException("No more animals");
	}
	else if (cats.isEmpty()) {
		Animal retval = Animal(dogs.peek()); // make a copy before returning.
		dogs.remove();
		return retval;
	}
	else if (dogs.isEmpty()) {
		Animal retval = Animal(cats.peek());
		cats.remove();
		return retval;
	}
	else {
		
		Animal cat = cats.peek();
		Animal dog = dogs.peek();
		Animal retval = cat.isOlderThan(dog) ? Animal(cat) : Animal(dog);
		if (cat.ID < dog.ID) {
			cats.remove();
		}
		else {
			dogs.remove();
		}
		return retval;
	}
}

Animal AnimalShelter::dequeueDog() {
	if (dogs.isEmpty()) {
		throw OutofAnimalsException("No more dogs");
	}
	Animal retval = Animal(dogs.peek());
	dogs.remove();
	return retval;
}

Animal AnimalShelter::dequeueCat() {
	if (cats.isEmpty()) {
		throw OutofAnimalsException("No more cats");
	}
	Animal retval = Animal(cats.peek());
	cats.remove();
	return retval;
}