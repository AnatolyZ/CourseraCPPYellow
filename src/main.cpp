#include <iostream>
#include <queue>

using namespace std;

int main() {
	int initial_value;
	cin >> initial_value;
	int n;
	cin >> n;
	queue<pair<char, int>> equation_order;
	while (n) {
		char operation;
		cin >> operation;
		int value;
		cin >> value;
		equation_order.push(make_pair(operation, value));
		--n;
	}
	n = equation_order.size();
	string result;
	result += to_string(initial_value);
	char last_operation = '*';
	int parentheses_amount = 0;
	while (n) {
		pair<char, int> tmp_pair = equation_order.front();
		equation_order.pop();
		if ((last_operation == '-' || last_operation == '+')
				&& (tmp_pair.first == '*' || tmp_pair.first == '/')) {
			++parentheses_amount;
			result.push_back(')');
			result.push_back(' ');
			result.push_back(tmp_pair.first);
			result.push_back(' ');
			result += to_string(tmp_pair.second);
		} else {
			result.push_back(' ');
			result.push_back(tmp_pair.first);
			result.push_back(' ');
			result += to_string(tmp_pair.second);
		}
		last_operation = tmp_pair.first;
		--n;
	}
	result.insert(0, parentheses_amount, '(');
	cout << result;
	return 0;
}
