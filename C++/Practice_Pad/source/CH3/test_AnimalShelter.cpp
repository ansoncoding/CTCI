#include "pch.h"
#include "AnimalShelter.h"

AnimalType d[] = { cat, dog, cat, cat, cat, dog, cat, dog, dog };
TEST(AnimalShelterTests, EnqueueDequeueAny) {
	AnimalShelter a = AnimalShelter();
	for (int i = 0; i < 9; i++) {
		a.enqueue(d[i]);
	}

	Animal * retval;
	for (int i = 0; i < 9; i++) {
		retval = a.dequeueAny();
		EXPECT_EQ(retval->cat_or_dog, d[i]);
		EXPECT_EQ(retval->ID, i);
	}
}

TEST(AnimalShelterTests, EnqueueDequeueCat) {
	AnimalShelter a = AnimalShelter();
	a.enqueue(cat);
	Animal* retval;
	retval = a.dequeueCat();
	EXPECT_EQ(retval->cat_or_dog, cat);
	EXPECT_EQ(retval->ID, 0);

	for (int i = 0; i < 9; i++) {
		a.enqueue(d[i]);
	}
	int soln_ids[] = { 1, 3, 4, 5, 7 }; // add 1 because of the first enqueue and dequeue
	for (int i = 0; i < 5; i++) {
		retval = a.dequeueCat();
		EXPECT_EQ(retval->cat_or_dog, cat);
		EXPECT_EQ(retval->ID, soln_ids[i]);
	}
	EXPECT_THROW(a.dequeueCat(), OutofAnimalsException);
}

TEST(AnimalShelterTests, EnqueueDequeueDog) {
	AnimalShelter a = AnimalShelter();
	a.enqueue(dog);
	Animal* retval;
	retval = a.dequeueDog();
	EXPECT_EQ(retval->cat_or_dog, dog);

	for (int i = 0; i < 9; i++) {
		a.enqueue(d[i]);
	}

	int soln_ids[] = { 2, 6, 8, 9 }; // add 1 because of the first enqueue and dequeue
	for (int i = 0; i < 4; i++) {
		retval = a.dequeueDog();
		EXPECT_EQ(retval->cat_or_dog, dog);
		EXPECT_EQ(retval->ID, soln_ids[i]);
	}
	EXPECT_THROW(a.dequeueDog(), OutofAnimalsException);
}

TEST(AnimalShelterTests, Exceptions) {
	AnimalShelter a = AnimalShelter();
	EXPECT_THROW(a.dequeueAny(), OutofAnimalsException);

	a.enqueue(dog);
	EXPECT_THROW(a.dequeueCat(), OutofAnimalsException);

	a.dequeueAny();

	a.enqueue(cat);
	EXPECT_THROW(a.dequeueDog(), OutofAnimalsException);
}
