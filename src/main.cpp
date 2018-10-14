#include <iostream>
#include <vector>
#include <map>
using namespace std;

//functions declarations
template <typename T>
T Sqr(const T& x);
template <typename T>
vector<T> operator* (vector<T>& lhs, vector<T>& rhs);
template <typename T1, typename T2>
pair<T1,T2> operator* (const pair<T1,T2>& lhs,const pair<T1,T2>& rhs);
template <typename key, typename value>
map<key,value> operator* (const map<key,value>& lhs,const map<key,value>& rhs);
//------------

template <typename T>
vector<T> operator* (const vector<T>& lhs,const vector<T>& rhs){
	if (lhs.size() != rhs.size()) throw invalid_argument("");
	vector<T> result(rhs.size());
	for(unsigned int i = 0; i < rhs.size(); ++i){
		result[i] = lhs.at(i)*rhs.at(i);
	}
	return result;
}

template <typename T1, typename T2>
pair<T1,T2> operator* (const pair<T1,T2>& lhs,const pair<T1,T2>& rhs){
	pair<T1,T2> result;
	result.first = lhs.first * rhs.first;
	result.second = lhs.second * rhs.second;
	return result;
}

template <typename key, typename value>
map<key,value> operator* (const map<key,value>& lhs,const map<key,value>& rhs){
	if (lhs.size() != rhs.size()) throw invalid_argument("");
	map<key,value> result;
	for(const auto& i:lhs){
		result[i.first] = lhs.at(i.first)*rhs.at(i.first);
	}
	return result;
}

//functions implementation
template <typename T>
T Sqr(const T& x){
	return x * x;
}



int main() {
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = { { 4, { 2, 2 } }, { 7, { 4, 3 } } };
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second
				<< endl;
	}

	return 0;
}
