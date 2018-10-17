

#include <iostream>
#include <sstream>
#include <exception>

#include "phone_number.h"
using namespace std;

PhoneNumber::PhoneNumber(const string &international_number){
	bool OK = true;
	istringstream ss(international_number);

	string country_code;
	OK = OK && (ss.peek() == '+');
	ss.ignore(1);
	OK = OK && (getline(ss,country_code,'-'));

	string city_code;
	OK = OK && (getline(ss,city_code,'-'));

	string local_number;
	OK = OK && (getline(ss,local_number));

	OK = OK && ss.eof();
	if (OK) {
		country_code_ = country_code;
		city_code_ = city_code;
		local_number_ = local_number;
	} else {
		throw invalid_argument("Wrong number format.");
	}
}
string PhoneNumber::GetCountryCode() const{
	return country_code_;
}
string PhoneNumber::GetCityCode() const{
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}



