#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> temp_list;
	unsigned int N;
	cin >> N;
	int64_t sum = 0;
	for (unsigned int i = 0; i < N; ++i){
		int v;
		cin >> v;
		temp_list.push_back(v);
		sum += v;
	}
	int64_t mean = sum / (int)temp_list.size();
	vector<int> result;
	for (unsigned int i = 0; i < N; ++i){
		if (temp_list[i] > mean){
			result.push_back(i);
		}
	}

	cout << result.size() << endl;
	//cout << mean << ' ' << sum << endl;
	for (const auto& i: result){
		cout << i << ' ';
	}
	return 0;
}
