#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// ���������� �����
// * ����� Matrix
// * �������� ����� ��� ������ Matrix �� ������ istream
// * �������� ������ ������ Matrix � ����� ostream
// * �������� �������� �� ��������� ���� �������� ������ Matrix
// * �������� �������� ���� �������� ������ Matrix

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
