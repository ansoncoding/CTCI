#include "pch.h"

#include "HashTable.h"

TEST(HashTableTests, InsertElements) {
	HashTable ht = HashTable();
	string d[5] = { "Hi", "how", "are", "you", "?" };
	for (unsigned int i = 0; i < 5; i++) {
		ht.insert(d[i]);
	}
	for (unsigned int i = 0; i < 5; i++) {
		EXPECT_TRUE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, InsertMoreElements) {
	HashTable ht = HashTable();
	string d[] = { 
		"Hi", "how", "are", "you", "?",
		"Great!", "Awesome!", "Great to be alive!", "Why", "did", 
		"the", "chicken", "cross", "the", "road", 
		"?", "Because", "it", "wanted", "to", 
		"!", "Knock!", "Knock!", "Who's", "there", 
		"?", "The", "chicken!", "Ahahah", "So.", 
		"Not.", "Funny."
	};
	for (unsigned int i = 0; i < 32; i++) {
		ht.insert(d[i]);
	}
	for (unsigned int i = 0; i < 32; i++) {
		EXPECT_TRUE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, RemoveElements) {
	HashTable ht = HashTable();
	string d[] = { "Hi", "how", "are", "you", "?" };
	for (unsigned int i = 0; i < 5; i++) {
		ht.insert(d[i]);
	}
	for (unsigned int i = 0; i < 5; i++) {
		ht.remove(d[i]);
		EXPECT_FALSE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, CopyConstructor) {

	//HashTable ht = HashTable();
	//string d[] = { "Hi", "how", "are", "you", "?" };
	//for (unsigned int i = 0; i < 5; i++) {
	//	ht.insert(d[i]);
	//}

	//ht.print();

	//HashTable ht_copy(ht);
	//for (unsigned int i = 0; i < 5; i++) {
	//	EXPECT_TRUE(ht_copy.contains(d[i]));
	//}
}

