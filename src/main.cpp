#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border);

template<typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto it_border = find_if(begin(elements), end (elements),[border](const T& t) {
		return t > border;
	});
	vector<T> result;

	for (auto i = it_border; i != end(elements); ++i) {
		result.push_back(*i);
	}
	sort(begin(result), end(result));
	return result;
}

int main() {
	for (int x : FindGreaterElements(set<int> { 1, 5, 7, 8 }, 5)) {
		cout << x << " ";
	}
	cout << endl;

	string to_find = "Python";
	cout << FindGreaterElements(set<string> { "C", "C++" }, to_find).size()
			<< endl;
	return 0;
}
