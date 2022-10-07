#include "pch.h"
#include "HashTable.h"

TEST(HashTableTests, putElements) {
	HashTable ht = HashTable();
	
	string v[5] = { "Hi", "how", "are", "you", "?" };
	for (unsigned int i = 0; i < 5; i++) {
		ht.put(to_string(i), v[i]);
	}
	for (unsigned int i = 0; i < 5; i++) {
		EXPECT_TRUE(ht.containsKey(to_string(i)));
		EXPECT_TRUE(ht.containsVal(v[i]));
	
		string retval = ht.get(to_string(i));
		EXPECT_TRUE(retval == v[i]);
	
	}
	EXPECT_FALSE(ht.containsKey("v"));
	EXPECT_FALSE(ht.containsVal("v"));
}

TEST(HashTableTests, putMoreElements) {
	HashTable ht = HashTable();
	string v[] = { 
		"Hi", "how", "are", "you", "?",
		"Great!", "Awesome!", "Great to be alive!", "Why", "did", 
		"the", "chicken", "cross", "the", "road", 
		"?", "Because", "it", "wanted", "to", 
		"!", "Knock!", "Knock!", "Who's", "there", 
		"?", "The", "chicken!", "Ahahah", "So.", 
		"Not.", "Funny."
	};
	for (unsigned int i = 0; i < 32; i++) {
		ht.put(to_string(i), v[i]);
	}
	for (unsigned int i = 0; i < 32; i++) {
		EXPECT_TRUE(ht.containsKey(to_string(i)));
		EXPECT_TRUE(ht.containsVal(v[i]));
	}
	for (unsigned int i = 0; i < 32; i++) {
		string retval = ht.get(to_string(i));
		EXPECT_TRUE(retval == v[i]);
	}
}

TEST(HashTableTests, RemoveElements) {
	HashTable ht = HashTable();
	string v[] = { "Hi", "how", "are", "you", "?" };
	for (unsigned int i = 0; i < 5; i++) {
		ht.put(to_string(i), v[i]);
	}
	for (unsigned int i = 0; i < 5; i++) {
		ht.remove(to_string(i));
		EXPECT_FALSE(ht.containsKey(to_string(i)));
		EXPECT_FALSE(ht.containsVal(v[i]));
	}
}

TEST(HashTableTests, SameKeyDiffVal) {

	string v1[] = { "These", "are", "the", "strings", "." };
	string v2[] = { "Oh", "look", "they", "have", "changed" };

	HashTable ht = HashTable();
	for (unsigned int i = 0; i < 5; i++) {
		ht.put(to_string(i), v1[i]);
		EXPECT_TRUE(ht.containsKey(to_string(i)));
		EXPECT_TRUE(ht.containsVal(v1[i]));
	}
	
	// insert the values from v2 using same keys, they should replace the valus from v1
	for (unsigned int i = 0; i < 5; i++) {
		ht.put(to_string(i), v2[i]);
		EXPECT_TRUE(ht.containsKey(to_string(i)));
		EXPECT_TRUE(ht.containsVal(v2[i]));
		EXPECT_FALSE(ht.containsVal(v1[i]));
	}
}

// this way we can ensure at least some vectors will have 1+ elements
TEST(HashTableTests, putMoreThanCapacity) {

	string v[] = { 
		"These", "are", "the", "strings", "I", "want", "to", "put", "into", "the", "hashtable", ".",
		"Here", "are", "some", "more", "to", "test", "the", "linked", "list", "mechanism", "!",
		"1", "2", "some", "numbers", "provide", "more", "data", "variety", "3", "4"};
	HashTable ht = HashTable();
	for (unsigned int i = 0; i < 33; i++) {
		ht.put(to_string(i), v[i]);
		EXPECT_TRUE(ht.containsVal(v[i]));
	}
	ht.print();
	for (unsigned int i = 0; i < 33; i++) {
		ht.remove(to_string(i));
		EXPECT_FALSE(ht.containsKey(to_string(i)));
	}
}

TEST(HashTableTests, CopyConstructor) {

	string v[] = { "These", "are", "the", "strings", "I", "want", "to", "put", "into", "the", "hashtable", "." };
	HashTable ht = HashTable();
	
	for (unsigned int i = 0; i < 12; i++) {
		ht.put(to_string(i), v[i]);
	}

	HashTable copy(ht);
	for (unsigned int i = 0; i < 12; i++) {
		EXPECT_TRUE(copy.containsVal(v[i]));
		EXPECT_TRUE(copy.containsKey(to_string(i)));
	}
}

TEST(HashTableTests, AssignmentOperator) {
	
	string v[] = { "These", "are", "the", "strings", "I", "want", "to", "put", "into", "the", "hashtable", "." };
	
	HashTable copy;
	{
		HashTable ht = HashTable();

		for (unsigned int i = 0; i < 12; i++) {
			ht.put(to_string(i), v[i]);
		}

		copy = ht;
	}
	for (unsigned int i = 0; i < 12; i++) {
		EXPECT_TRUE(copy.containsVal(v[i]));
		EXPECT_TRUE(copy.containsKey(to_string(i)));
	}
}