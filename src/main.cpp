#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> SplitIntoWords(const string& s);

vector<string> SplitIntoWords(const string& s){
	vector<string> result;
	auto tmp_it = begin(s);
	while (tmp_it != end(s)){
		auto it = s.find(' ');
		result.push_back({tmp_it,it});

	}
	return result;
}

int main() {

	return 0;
}
