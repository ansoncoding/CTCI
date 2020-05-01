#include "pch.h"
#include "Performance.h"

using namespace std;

template <typename T, typename T2>

auto add(T a, T2 b) -> decltype(a+b) {
	return a + b;
}

class M {
private:
	int m_data;
	
public:
	M(int data) {
		m_data = data;
	}
	void print() const {
		cout << m_data << endl;
	}
	friend M operator+(const M& a, const M& b) {
		return (a.m_data + b.m_data);
	}
};
int main() {
	{
		Timer timer;
		M v1 = M(2);
		M v2 = M(3);
		M out1 = v1 + v2;
		M out2 = add(v1, v2);
		cout << add(1.2, 2) << endl;
		out1.print();
		out2.print();
		
	}
}

