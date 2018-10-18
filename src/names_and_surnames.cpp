#include <map>
#include <string>
#include "names_and_surnames.h"

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // изначально имя неизвестно

  // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
  for (const auto& item : names) {
    // если очередной год не больше данного, обновляем имя
    if (item.first <= year) {
      name = item.second;
    } else {
      // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
      break;
    }
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


