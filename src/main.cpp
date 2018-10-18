#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void FillVector(vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = v.size() - i;
	}
}

void PrintVector(const vector<int>& v) {
	for (const auto& i : v) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	size_t n;
	cin >> n;
	vector<int> vec(n);
	FillVector(vec);
	PrintVector(vec);

	while (prev_permutation(begin(vec), end(vec))) {
		PrintVector(vec);
	}
	return 0;
}
