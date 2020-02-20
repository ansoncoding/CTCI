#include "pch.h"
#include "Graph.h"


GraphAL<string> g = GraphAL<string>();

string graph_data[] = { "jane", "jack", "mike", "lisa", "lola", "lora", "anna", "lily" };
string graph_data2[] = { "jay",  "jam",  "zak",  "rex",  "amy",  "jac",  "ida",  "eve" };

int N4 = 8;

TEST(TestGraph, InsertAndIsConnected) {

	GraphAL<string> g = GraphAL<string>();
	
	for (int i = 0; i < N4; i++) {
		set<int> s = set<int>();
		s.insert(i % N4);
		s.insert((i + 1) % N4);
		s.insert((i + 2) % N4);
		GNode<string> gnode = GNode<string>(i, graph_data[i], s);
		g.insert(gnode);
	}

	for (int i = N4; i < N4 + N4; i++) {
		GNode<string> gnode = GNode<string>(i, graph_data2[i - N4]);
		g.insert(gnode);
	}
	vector<int> ret_path;
	for (int i = 0; i < N4; i++) {
		EXPECT_TRUE(g.isConnected(graph_data[i], graph_data[i], ret_path)); //everyone is connected to themselves
	}
	
	for (int i = 0; i < N4; i++) {
		for (int j = 0; j < N4; j++) {
			EXPECT_TRUE(g.isConnected(graph_data[i], graph_data[j], ret_path)); //everyone is connected to everyone in graph_data
		}
	}

	for (int i = 0; i < N4; i++) {
		for (int j = N4; j < N4 + N4; j++) {

			EXPECT_FALSE(g.isConnected(graph_data[i], graph_data[j], ret_path)); // ppl in graph_data are not connected to those in graph_data2
		}
	}
	for (int i = N4; i < N4 + N4; i++) {
		for (int j = N4; j < N4 + N4; j++) {

			if (i == j) //everyone knows themselves this test is done already
				continue;

			EXPECT_FALSE(g.isConnected(graph_data[i], graph_data[j], ret_path)); // ppl in graph_data2 are not connected to each other
		}
	}
}

TEST(TestGraph, Remove) {

	for (int i = 0; i < N4; i++) {
		set<int> s = set<int>();
		s.insert(i % N4);
		s.insert((i + 1) % N4);
		s.insert((i + 2) % N4);
		GNode<string> gnode = GNode<string>(i, graph_data[i], s);
		g.insert(gnode);
	}
	vector<int> ret_path;
	for (int r = 0; r < N4; r++) {
		g.remove(graph_data[r]);
		for (int i = r; i < N4; i++) {
			EXPECT_FALSE(g.isConnected(graph_data[r], graph_data[i], ret_path));
		}
	}
}


TEST(TestGraph, CopyConstructor) {
	GraphAL<string> g = GraphAL<string>();

	for (int i = 0; i < N4; i++) {
		set<int> s = set<int>();
		s.insert(i % N4);
		s.insert((i + 1) % N4);
		s.insert((i + 2) % N4);
		GNode<string> gnode = GNode<string>(i, graph_data[i], s);
		g.insert(gnode);
	}

	GraphAL<string> copy(g);
	vector<int> ret_path;
	for (int i = 0; i < N4; i++) {
		EXPECT_TRUE(copy.isConnected(graph_data[i], graph_data[i], ret_path)); //everyone is connected to themselves
	}
}

TEST(TestGraph, AssignmentOperator) {
	GraphAL<string> g = GraphAL<string>();

	for (int i = 0; i < N4; i++) {
		set<int> s = set<int>();
		s.insert(i % N4);
		s.insert((i + 1) % N4);
		s.insert((i + 2) % N4);
		GNode<string> gnode = GNode<string>(i, graph_data[i], s);
		g.insert(gnode);
	}

	GraphAL<string> copy = g;
	vector<int> ret_path;
	for (int i = 0; i < N4; i++) {
		EXPECT_TRUE(copy.isConnected(graph_data[i], graph_data[i], ret_path)); //everyone is connected to themselves
	}
}
