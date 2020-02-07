#include "pch.h"
#include "HashTable.h"

TEST(HashTableTests, InsertElements) {

	string d[] = { "These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "hashtable", "." };
	HashTable ht = HashTable();
	for (unsigned int i = 0; i < 12; i++) {
		ht.insert(d[i]);
		EXPECT_TRUE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, RemoveElements) {

	string d[] = { "These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "hashtable", "." };
	HashTable ht = HashTable();
	for (unsigned int i = 0; i < 12; i++) {
		ht.insert(d[i]);
	}

	for (unsigned int i = 0; i < 12; i++) {
		ht.remove(d[i]);
		EXPECT_FALSE(ht.contains(d[i]));
	}
}

// this way we can ensure at least some linkedlists will have 1+ elements
TEST(HashTableTests, InsertMoreThanCapacity) {

	string d[] = { 
		"These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "hashtable", ".",
		"Here", "are", "some", "more", "to", "test", "the", "linked", "list", "mechanism", "!",
		"1", "2", "some", "numbers", "provide", "more", "data", "variety", "3", "4"};
	HashTable ht = HashTable();
	for (unsigned int i = 0; i < 33; i++) {
		ht.insert(d[i]);
		EXPECT_TRUE(ht.contains(d[i]));
	}

	for (unsigned int i = 0; i < 33; i++) {
		ht.remove(d[i]);
		EXPECT_FALSE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, CopyConstructor) {

	string d[] = { "These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "hashtable", "." };
	HashTable ht = HashTable();
	
	for (unsigned int i = 0; i < 12; i++) {
		ht.insert(d[i]);
	}

	HashTable copy(ht);
	for (unsigned int i = 0; i < 12; i++) {
		EXPECT_TRUE(copy.contains(d[i]));
	}
}

TEST(HashTableTests, AssignmentOperator) {

	string d[] = { "These", "are", "the", "strings", "I", "want", "to", "insert", "into", "the", "hashtable", "." };
	HashTable ht = HashTable();

	for (unsigned int i = 0; i < 12; i++) {
		ht.insert(d[i]);
	}

	HashTable copy = ht;
	for (unsigned int i = 0; i < 12; i++) {
		EXPECT_TRUE(copy.contains(d[i]));
	}
}