#ifndef PERFORMANCE_H
#define PERFORMANCE_H
#include <chrono>
#include <iostream>

using namespace std;
class Timer {
private:
	chrono::time_point<chrono::high_resolution_clock> m_start;
	void Stop() {
		chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();
		long long startTime = chrono::time_point_cast<chrono::microseconds>(m_start).time_since_epoch().count();
		long long endTime = chrono::time_point_cast<chrono::microseconds>(end).time_since_epoch().count();
		long long duration = endTime - startTime;
		double ms = duration / 1000.0;
		cout << "Duration " << duration << "us (" << ms << " ms)" << endl;
	}
public:
	Timer() {
		m_start = chrono::high_resolution_clock::now();
	}
	~Timer() {
		Stop();
	}
};
#endif

#pragma once
