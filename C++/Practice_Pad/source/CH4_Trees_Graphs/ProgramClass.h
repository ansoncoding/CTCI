#ifndef PROGRAM_CLASS_H
#define PROGRAM_CLASS_H
#include "GraphArrayList.h"

#include <iostream>
using namespace std;

class Program {
private:
	GraphAL<string> modules;
	bool build_helper(set<string>& built, GraphAL<string>& copy, vector<string>& retval) const;
public:
	Program(const GraphAL<string>& other) {
		modules = GraphAL<string>(other);
	}
	Program(string* mods, int length) {
		modules = GraphAL<string>(mods, length);	
	}
	bool build(vector<string> & retval) const;
	bool addDependency(string a, string b);
	void print() const;
};

bool Program::build_helper(set<string>& built, GraphAL<string>& copy, vector<string>& retval) const {

	bool change = false;
	vector<string> new_rm = vector<string>();
	for (auto it = copy.begin(); it != copy.end(); it++) {

		GNode<string>* temp = it->second;
		
		if (temp->links.empty()) { //no dependencies can be immediately built
			built.insert(temp->data);
			retval.push_back(temp->data);
			change = true;
			new_rm.push_back(temp->data);
		}
	}
	for (int i = 0; i < new_rm.size(); i++) {
		copy.remove(new_rm.at(i));
	}
	
	if (copy.isEmpty()) {
		return true;
	}

	if (change) {
		return build_helper(built, copy, retval);
	}
	
	return copy.isEmpty();
}

bool Program::build(vector<string>& retval) const {
	GraphAL<string> copy = modules; // make a copy we don't want to change the modules setup
	set<string> built = set<string>();
	
	return build_helper(built, copy, retval);
}

// a depends on b
bool Program::addDependency(string a, string b) {
	return modules.addEdge(a, b, false);
}

void Program::print() const {
	modules.print();
}

#endif
