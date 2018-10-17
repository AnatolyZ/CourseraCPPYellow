#pragma once

#include <string>
#include <iostream>
#include "assert_.h"
using namespace std;

class TestRunner {
public:
	template<class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (runtime_error& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
	}
	~TestRunner();
private:
	int fail_count = 0;
};
