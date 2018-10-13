#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
public:
	Matrix (){
		rows = 0;
		columns = 0;
	}
	Matrix (int r, int c){
		if (r < 0 || c < 0) throw out_of_range("Rows and columns number may be positive only.");
		rows = r;
		columns = c;
		matrix.resize(rows, vector<int>(columns, 0));
	}
	void Reset (int r, int c){
		if (r < 0 || c < 0) throw out_of_range("Rows and columns number may be positive only.");
		rows = r;
		columns = c;
		matrix.assign(rows, vector<int>(columns, 0));
	}
	unsigned int GetNumRows() const{
		return rows;
	}
	unsigned int GetNumColumns() const{
		return columns;
	}
	int At(unsigned int r,unsigned int c) const {
		if (r >= rows || c >= columns) throw out_of_range("Cell is out of range");
		return matrix[r][c];
	}
	int& At(unsigned int r,unsigned int c) {
			if (r >= rows || c >= columns) throw out_of_range("Cell is out of range");
			return matrix[r][c];
		}
private:
	unsigned int rows;
	unsigned int columns;
	vector<vector<int>> matrix;
};
istream& operator>> (istream& input, Matrix& m){
	int r,c;
	input >> r >> c;
	try{
		m = Matrix(r,c);
		for (unsigned int i = 0; i < m.GetNumRows(); ++i){
			for (unsigned int j = 0; j < m.GetNumColumns(); ++j){
				if (!(input >> m.At(i,j))) {
					m.Reset(m.GetNumRows(),m.GetNumColumns());
					throw invalid_argument("Wrong matrix format");
				}
			}
		}
	} catch (exception& ex){
			cout << ex.what() << endl;
			return input;
		}
	return input;
}

ostream& operator<< (ostream& output, const Matrix& m){
	output << m.GetNumRows() << ' ' << m.GetNumColumns() << endl;
	for (unsigned int i = 0; i < m.GetNumRows(); ++i){
			for (unsigned int j = 0; j < m.GetNumColumns(); ++j){
				output << m.At(i,j) << ' ';
			}
			output << endl;
		}
	return output;
}

bool operator== (Matrix lhs, Matrix rhs){
	if ((lhs.GetNumRows() != rhs.GetNumRows())
			|| (lhs.GetNumColumns() != rhs.GetNumColumns())){
		return false;
	}
	for (unsigned int i = 0; i < lhs.GetNumRows(); ++i){
		for (unsigned int j = 0; j < lhs.GetNumColumns(); ++j){
			if (lhs.At(i,j) != rhs.At(i,j)){
				return false;
			}
		}
	}
	return true;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs){
	if ((lhs.GetNumRows() != rhs.GetNumRows())
				|| (lhs.GetNumColumns() != rhs.GetNumColumns())){
			throw invalid_argument("Discrepancy of matrixes sizes");
		}
	Matrix result(lhs.GetNumRows(),lhs.GetNumColumns());
	for (unsigned int i = 0; i < lhs.GetNumRows(); ++i){
			for (unsigned int j = 0; j < lhs.GetNumColumns(); ++j){
				result.At(i,j) = lhs.At(i,j) + rhs.At(i,j);
			}
		}
	return result;
}
// Реализуйте здесь
// * класс Matrix
// *     оператор ввода для класса Matrix из потока istream
// *     оператор вывода класса Matrix в поток ostream
// *     оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
  Matrix one;
 // Matrix two;

  cin >> one;
  cout << one ;
  return 0;
}
