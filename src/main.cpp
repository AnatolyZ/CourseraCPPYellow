#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream& operator <<(ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class T>
ostream& operator <<(ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class K, class V>
ostream& operator <<(ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = { }) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template<class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		} catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};
/*
class Person {
public:
	// Вы можете вставлять сюда различные реализации класса,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	void ChangeFirstName(int year, const string& first_name) {
	}
	void ChangeLastName(int year, const string& last_name) {
	}
	string GetFullName(int year) {
	}
};
*/
void TestIncognito() {
	{
		Person p;
		AssertEqual(p.GetFullName(1), "Incognito");
	}
	{
		Person p;
		p.ChangeFirstName(3, "Masha");
		p.ChangeLastName(6, "Misha");
		AssertEqual(p.GetFullName(1), "Incognito");
	}
}
void TestOnlyLast() {
	{
		Person p;
		p.ChangeLastName(3, "Misha");
		AssertEqual(p.GetFullName(20), "Misha with unknown first name");
	}
	{
		Person p;
		p.ChangeFirstName(30, "Misha");
		p.ChangeLastName(6, "Masha");
		AssertEqual(p.GetFullName(9), "Masha with unknown first name");
	}
	{
		Person p;
		p.ChangeLastName(3, "Masha");
		p.ChangeLastName(6, "Misha");
		p.ChangeLastName(8, "Masha");
		p.ChangeLastName(10, "Misha");
		AssertEqual(p.GetFullName(56), "Misha with unknown first name");
	}
	{
		Person p;
		p.ChangeLastName(3, "Masha");
		p.ChangeLastName(6, "Misha");
		p.ChangeLastName(8, "Masha");
		p.ChangeLastName(10, "Misha");
		AssertEqual(p.GetFullName(9), "Masha with unknown first name");
	}
	{
		Person p;
		p.ChangeLastName(3, "Masha");
		p.ChangeLastName(6, "Misha");
		p.ChangeLastName(8, "Masha");
		p.ChangeFirstName(10, "Misha");
		AssertEqual(p.GetFullName(9), "Masha with unknown first name");
	}
}

void TestOnlyFirst() {
	{
		Person p;
		p.ChangeFirstName(3, "Misha");
		AssertEqual(p.GetFullName(20), "Misha with unknown last name");
	}
	{
		Person p;
		p.ChangeFirstName(3, "Misha");
		p.ChangeLastName(60, "Masha");
		AssertEqual(p.GetFullName(20), "Misha with unknown last name");
	}
	{
		Person p;
		p.ChangeFirstName(3, "Masha");
		p.ChangeFirstName(6, "Misha");
		p.ChangeFirstName(8, "Masha");
		p.ChangeFirstName(10, "Misha");
		AssertEqual(p.GetFullName(56), "Misha with unknown last name");
	}
	{
		Person p;
		p.ChangeFirstName(3, "Masha");
		p.ChangeFirstName(6, "Misha");
		p.ChangeFirstName(8, "Masha");
		p.ChangeFirstName(10, "Misha");
		AssertEqual(p.GetFullName(9), "Masha with unknown last name");
	}
	{
		Person p;
		p.ChangeFirstName(3, "Masha");
		p.ChangeFirstName(6, "Misha");
		p.ChangeFirstName(8, "Masha");
		p.ChangeLastName(10, "Misha");
		AssertEqual(p.GetFullName(9), "Masha with unknown last name");
	}
}

void TestFull() {
	{
		Person p;
		p.ChangeFirstName(1, "Bob");
		p.ChangeLastName(4, "Bush");
		AssertEqual(p.GetFullName(9), "Bob Bush");
	}
	{
		Person p;
		p.ChangeFirstName(1, "Bob");
		p.ChangeLastName(4, "Bush");
		p.ChangeFirstName(7, "Bob2");
		p.ChangeLastName(9, "Bush2");
		AssertEqual(p.GetFullName(9), "Bob2 Bush2");
	}
	{
		Person p;
		p.ChangeFirstName(1, "Bob");
		p.ChangeLastName(4, "Bush");
		p.ChangeFirstName(7, "Bob2");
		p.ChangeLastName(9, "Bush2");
		AssertEqual(p.GetFullName(7), "Bob2 Bush");
	}
}

int main() {
	TestRunner runner;
	runner.RunTest(TestIncognito,"TestIncognito");
	runner.RunTest(TestOnlyFirst,"TestOnlyFirst");
	runner.RunTest(TestOnlyLast,"TestOnlyLast");
	runner.RunTest(TestFull,"TestFull");
	return 0;
}
