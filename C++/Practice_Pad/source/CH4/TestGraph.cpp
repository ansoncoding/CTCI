#include "pch.h"
#include "Graph.h"


GraphAL<string> g = GraphAL<string>();

string graph_data[] = { "jane", "jack", "mike", "lisa", "lola", "lora", "anna", "lily" };
string graph_data2[] = { "jay",  "jam",  "zak",  "rex",  "amy",  "jac",  "ida",  "eve" };

int N4 = 8;

TEST(TestGraph, InsertAndConnect) {

	GraphAL<string> g = GraphAL<string>();
	
	for (int i = 0; i < N4; i++) {
		LinkedListQ<int> ll = LinkedListQ<int>();
		ll.append(i % N4);
		ll.append((i + 1) % N4);
		ll.append((i + 2) % N4);
		GNode<string> gnode = GNode<string>(i, graph_data[i], ll);
		g.insert(gnode);
	}
	for (int i = N4; i < N4 + N4; i++) {
		GNode<string> gnode = GNode<string>(i, graph_data2[i - N4]);
		g.insert(gnode);
	}
	
	for (int i = 0; i < N4; i++) {
		EXPECT_TRUE(g.isConnected(graph_data[i], graph_data[i])); //everyone is connected to themselves
	}
	
	for (int i = 0; i < N4; i++) {
		for (int j = 0; j < N4; j++) {
			EXPECT_TRUE(g.isConnected(graph_data[i], graph_data[(i + j) % N4])); //everyone is connected to everyone in graph_data
		}
	}

	for (int i = 0; i < N4; i++) {
		for (int j = N4; j < N4 + N4; j++) {

			EXPECT_FALSE(g.isConnected(graph_data[i], graph_data[j])); // people in graph_data are not connected to people in graph_data2
		}
	}
}

TEST(TestGraph, RemoveMin) {

	
}


TEST(TestGraph, CopyConstructor) {

}

TEST(TestGraph, AssignmentOperator) {

}
