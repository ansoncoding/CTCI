#ifndef ANIMAL_SHELTER_H
#define ANIMAL_SHELTER_H
#include "LinkedListQueue.h"
#include <exception>
#include <string>

using namespace std;

enum AnimalType {any, cat, dog };


class OutofAnimalsException : public exception
	{
	private:
		std::string m_error;
	public:
		OutofAnimalsException(std::string error)
			: m_error(error){}
		const char* getError() { return m_error.c_str(); }
};


class Animal {
public:
	Animal() {
		cat_or_dog = any;
		ID = 0;
	}
	string getString() {
		switch (cat_or_dog) {
		case any: return "any";
		case cat: return "cat";
		case dog: return "dog";
		default: return "any";
		}
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
	unsigned int nextID = 0;
	void copy(const AnimalShelter & other);
public:
	AnimalShelter();
	~AnimalShelter();
	AnimalShelter(const AnimalShelter & other);
	AnimalShelter& operator=(const AnimalShelter& other);
	void enqueue(AnimalType a);
	Animal dequeueAny();
	Animal dequeueDog();
	Animal dequeueCat();
};

#endif