#include "test_runner.h"
#include "phone_number.h"

void TestPhoneNumber() {
	{
		PhoneNumber pn("+7-920-3091706");
		AssertEqual(pn.GetCountryCode(),"7", "Countru code");
		AssertEqual(pn.GetCityCode(),"920","Country code");
		AssertEqual(pn.GetLocalNumber(),"3091706","Local number");
		AssertEqual(pn.GetInternationalNumber(),"+7-920-3091706","Full number");
	}
    AssertEqual(1, 1, "Just to check that Assert works");
}

int main() {
    TestRunner tr;
    tr.RunTest(TestPhoneNumber, "TestPhoneNumber");
    return 0;
}

