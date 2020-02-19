#include "pch.h"
#include "Graph.h"


GraphAL<string> g = GraphAL<string>();
string graph_data[] = { "jane", "jack", "mike", "lisa", "lola", "lora", "amy", "lily" };
int N4 = 5;

TEST(TestGraph, Insert) {

	for (int i = 0; i < N4; i++) {
		LinkedListQ<int> ll = LinkedListQ<int>();
		ll.append(i);
		ll.append(i + 1);
		ll.append(i + 2);
		GNode<string> gnode = GNode<string>(i, graph_data[i], ll);
		g.insert(gnode);
	}
		
	EXPECT_TRUE(g.isConnected("jane", "jack"));
	EXPECT_TRUE(g.isConnected("jane", "mike"));
	EXPECT_TRUE(g.isConnected("jane", "jane"));

	EXPECT_FALSE(g.isConnected("jane", "lily"));
	EXPECT_FALSE(g.isConnected("jane", "lisa"));
	EXPECT_FALSE(g.isConnected("jane", "lola"));
	EXPECT_FALSE(g.isConnected("jane", "lora"));

}

TEST(TestGraph, RemoveMin) {

	
}


TEST(TestGraph, CopyConstructor) {

}

TEST(TestGraph, AssignmentOperator) {

}
