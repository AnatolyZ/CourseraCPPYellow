#include "person.h"
#include "test_runner.h"

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
	TestRunner tr;
	tr.RunTest(TestOnlyLast, "TestOnlyLast");
	tr.RunTest(TestOnlyFirst, "TestOnlyFirst");
	tr.RunTest(TestFull, "TestFull");

	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : { 1900, 1965, 1990 }) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : { 1969, 1970 }) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : { 1969, 1970 }) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}

