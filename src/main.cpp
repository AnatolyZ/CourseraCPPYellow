#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
		RandomIt range_end, const string& prefix) {
	string s(prefix);
	return equal_range(range_begin, range_end, s,
			[s](const auto& str1,const auto& str2) {
				return str1.substr(0,s.size()) < str2.substr(0,s.size());
			});
}

int main() {
	const vector<string> sorted_strings =
			{ "moscow", "motovilikha", "murmansk" };

	const auto mo_result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " "
			<< (mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result = FindStartsWith(begin(sorted_strings),
			end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " "
			<< (na_result.second - begin(sorted_strings)) << endl;

	return 0;
}
