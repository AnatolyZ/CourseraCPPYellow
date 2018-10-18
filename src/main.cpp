
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if ((range_end - range_begin) >= 2) {
		vector<typename RandomIt::value_type> elements(range_begin, range_end);
		auto third1_it = begin(elements) + (elements.size()/3);
		auto third2_it = third1_it + (elements.size()/3);
		MergeSort(begin(elements), third1_it);
		MergeSort(third1_it, third2_it);
		MergeSort(third2_it, end(elements));
		vector<typename RandomIt::value_type> tmp;
		merge(begin(elements), third1_it, third1_it, third2_it,back_inserter(tmp));
		merge(begin(tmp), end(tmp), third2_it, end(elements), range_begin);
	}
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
