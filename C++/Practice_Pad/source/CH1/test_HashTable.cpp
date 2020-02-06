#include "pch.h"

#include "HashTable.h"

TEST(HashTableTests, InsertElements) {
	HashTable ht = HashTable();
	string d[] = { "Hi", "how", "are", "you", "?" };
	for (int i = 0; i < d->length(); i++) {
		ht.insert(d[i]);
	}

	for (int i = 0; i < d->length(); i++) {
		EXPECT_TRUE(ht.contains(d[i]));
	}
}

TEST(HashTableTests, InsertMoreElements) {
	HashTable ht = HashTable();
	string d[] = { 
		"Hi", "how", "are", "you", "?",
		"Great!", "Awesome!", "Great to be alive!",
		"Why", "did", "the", "chicken", "cross", "the", "road", "?",
		"Because", "it", "wanted", "to", "!",
		"Knock!", "Knock!", "Who's", "there", "?",
		"The", "chicken!", "Ahahah", "So.", "Not.", "Funny."
	};
	for (int i = 0; i < d->length(); i++) {
		ht.insert(d[i]);
	}

	for (int i = 0; i < d->length(); i++) {
		EXPECT_TRUE(ht.contains(d[i]));
	}
}