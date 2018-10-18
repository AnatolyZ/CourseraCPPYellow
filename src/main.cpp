#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers,
		int border) {
	 const auto first_not_less = numbers.lower_bound(border);

	  // ���� ��������� ����� ��� �� ������� �������� �� ������ border
	  // ��� ���������, �� �� ��� �������� �����
	  if (first_not_less == numbers.begin()) {
	    return first_not_less;
	  }

	  // ���� ���������, �� ������� border, ��� � set �� ����, �� ���������� �����
	  // �������� �� ��������� �������, ������� border
	  // prev -> http://ru.cppreference.com/w/cpp/iterator/prev
	  const auto last_less = prev(first_not_less);
	  if (first_not_less == numbers.end()) {
	    return last_less;
	  }

	  // ���������� ��� ���������-��������� � ������� ���,
	  // ��� ������� ����� � ��������
	  const bool is_left = (border - *last_less <= *first_not_less - border);
	  return is_left ? last_less : first_not_less;


}

// set<int>::const_iterator �
// ��� ���������� ��� ������������ ��������� ����� �����

int main() {
	set<int> numbers = { 1,7};
	cout    << *FindNearestElement(numbers, 0) << " "
			<< *FindNearestElement(numbers, 3) << " "
			<< *FindNearestElement(numbers, 1) << " "
			<< *FindNearestElement(numbers, 6) << " "
			<< *FindNearestElement(numbers, 7) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}

