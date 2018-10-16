
#include <iostream>
#include <algorithm>
#include "sum_reverse_sort.h"
using namespace std;

int Sum(int x, int y){
	return x+y;
}
string Reverse(string s){
	unsigned int size = s.size();
	string result(s);
	for(unsigned int i = 0; i < size; ++i){
		result[size-1-i] = s[i];
	}
	return result;
}
void Sort(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
}

