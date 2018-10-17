#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s);

vector<string> SplitIntoWords(const string& s){
	vector<string> result;
	auto tmp_it = begin(s);

	while (tmp_it != end(s)){
		auto it = find(tmp_it, end(s),' ');
		result.push_back({tmp_it,it});
		if (it != end(s)){
			tmp_it = ++it;
		} else break;
	}
	return result;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
