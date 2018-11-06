#include <iostream>
#include <queue>

using namespace std;


int main() {
	int initial_value;
	cin >> initial_value;
	int n;
	cin >> n;
	queue<pair<char,int>> equation_order;
	while (n){
		char operation;
		cin >> operation;
		int value;
		cin >> value;
		equation_order.push(make_pair(operation,value));
		--n;
	}
	n = equation_order.size();
	string result;
	result.insert(0,n,'(');
	result += to_string(initial_value);
	while (n) {
		pair<char,int>tmp_pair = equation_order.front();
		equation_order.pop();
		result.push_back(')');
		result.push_back(' ');
		result.push_back(tmp_pair.first);
		result.push_back(' ');
		result += to_string(tmp_pair.second);
		--n;
	}
	cout << result;
	return 0;
}
