#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

bool f(int n) {
	return n > 0;
}

int main() {
	set<int> s = { 1, 5, 6, 7, -4, -1, 6 };
	vector<int> v;
//--------------------

	v.assign(begin(s), end(s));
	auto it = remove_if(begin(v), end(v), f);
	v.erase(it, end(v));

//--------------------
	for (const auto& i : v) {
		cout << i << ' ';
	}
	return 0;
}
