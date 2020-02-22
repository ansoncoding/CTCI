#include "pch.h"
#include "ProgramClass.h"

TEST(TestProgramClass, Build) {

	string program_data[] = { "a", "b", "c", "d", "e", "f" };
	
	Program p = Program(program_data, 6);

	vector<string> retpath = vector<string>();
	p.addDependency("d", "a");
	p.addDependency("b", "f");
	p.addDependency("d", "b");
	p.addDependency("a", "f");
	p.addDependency("c", "d");

	ASSERT_TRUE(p.build(retpath));	
}

TEST(TestProgramClass, BuildCircular) {

	string program_data[] = { "a", "b", "c", "d", "e", "f" };

	Program p = Program(program_data, 6);

	vector<string> retpath = vector<string>();
	p.addDependency("d", "a");
	p.addDependency("a", "d");
	p.addDependency("d", "b");
	p.addDependency("a", "f");
	p.addDependency("c", "d");

	ASSERT_FALSE(p.build(retpath));
}
