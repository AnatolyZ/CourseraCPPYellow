#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle: public Figure {
public:
	Triangle(const string& name, const double& side_a, const double& side_b,
			const double& side_c) :
			name_(name), side_a_(side_a), side_b_(side_b), side_c_(side_c) {
	}
	string Name() const override {
		return name_;
	}
	double Perimeter() const override {
		return side_a_ + side_b_ + side_c_;
	}
	double Area() const override {
		double p = this->Perimeter() / 2;
		return sqrt(p * (p - side_a_) * (p - side_b_) * (p - side_c_));
	}
private:
	const string name_;
	const double side_a_;
	const double side_b_;
	const double side_c_;
};

class Rect: public Figure {
public:
	Rect(const string& name, const double& width, const double& heigth) :
			name_(name), width_(width), height_(heigth) {
	}
	string Name() const override {
		return name_;
	}
	double Perimeter() const override {
		return 2 * width_ + 2 * height_;
	}
	double Area() const override {
		return width_ * height_;
	}
private:
	const string name_;
	const double width_;
	const double height_;
};

class Circle: public Figure {
public:
	Circle(const string& name, const double& r) :
			name_(name), r_(r) {
	}
	string Name() const override {
		return name_;
	}
	double Perimeter() const override {
		return 2 * 3.14 * r_;
	}
	double Area() const override {
		return 3.14 * r_ * r_;
	}
private:
	const string name_;
	const double r_;

};

shared_ptr<Figure> CreateFigure(istringstream& is) {
	string name;
	is >> name;
	if (name == "RECT") {
		double w, h;
		is >> w >> h;
		return make_shared<Rect>(name, w, h);
	} else if (name == "TRIANGLE") {
		double a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(name, a, b, c);
	} else {
		double r;
		is >> r;
		return make_shared<Circle>(name,r);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line);) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3) << current_figure->Name()
						<< " " << current_figure->Perimeter() << " "
						<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
