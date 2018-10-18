#include <map>
#include <string>
#include <algorithm>
#include "person.h"

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

	auto it = names.upper_bound(year);
	if (it != begin(names)){
		name = (--it)->second;
	}
	return name;
}
void Person::ChangeFirstName(int year, const string& first_name) {
	first_names[year] = first_name;
}
void Person::ChangeLastName(int year, const string& last_name) {
	last_names[year] = last_name;
}
string Person::GetFullName(int year) {
	// получаем имя и фамилию по состоянию на год year
	const string first_name = FindNameByYear(first_names, year);
	const string last_name = FindNameByYear(last_names, year);

	// если и имя, и фамилия неизвестны
	if (first_name.empty() && last_name.empty()) {
		return "Incognito";

	// если неизвестно только имя
	} else if (first_name.empty()) {
		return last_name + " with unknown first name";

	// если неизвестна только фамилия
	} else if (last_name.empty()) {
		return first_name + " with unknown last name";

	// если известны и имя, и фамилия
	} else {
		return first_name + " " + last_name;
	}
}

