#ifndef ANIMAL_SHELTER_H
#define ANIMAL_SHELTER_H
#include "LinkedListQueue.h"

enum AnimalType { cat, dog };
class Animal {
public:
	Animal() {
		cat_or_dog = cat;
		ID = 0;
	}
	Animal(AnimalType t, unsigned int ID) {
		cat_or_dog = t;
		this->ID = ID;
	}
	Animal(const Animal& other) {
		cat_or_dog = other.cat_or_dog;
		ID = other.ID;
	}
	Animal& operator=(const Animal& other) {
		if (&other != this) {
			cat_or_dog = other.cat_or_dog;
			ID = other.ID;
		}
		return *this;
	}
	bool isOlderThan(Animal a) {
		return (ID < a.ID);
	}
	int ID;
	AnimalType cat_or_dog;
};

class AnimalShelter {
	
private:
	LinkedListQ<Animal> cats;
	LinkedListQ<Animal> dogs;
	unsigned int currentID = 0;
	void copy(const AnimalShelter & other);
public:
	AnimalShelter();
	~AnimalShelter();
	AnimalShelter(const AnimalShelter & other);
	AnimalShelter& operator=(const AnimalShelter& other);
	void enqueue(AnimalType a);
	Animal * dequeueAny();
	Animal * dequeueDog();
	Animal * dequeueCat();
};

#endif