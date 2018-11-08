#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& name, const string& type) :
			name_(name), type_(type) {
	}
	virtual void Walk(const string& destination) const {
		cout << type_ << ": " << name_ << " walks to: " << destination << endl;
	}

	string Name() const {
		return name_;
	}
	string Type() const {
		return type_;
	}

protected:
	const string name_;
	const string type_;
};

class Student: public Person {
public:

	Student(const string& name, const string& favourite_song) :
			Person(name, "Student"), favourite_song_(favourite_song) {
	}

	void Learn() const {
		cout << "Student: " << name_ << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		cout << "Student: " << name_ << " walks to: " << destination << endl;
		cout << "Student: " << name_ << " sings a song: " << favourite_song_
				<< endl;
	}

	void SingSong() const {
		cout << "Student: " << name_ << " sings a song: " << favourite_song_
				<< endl;
	}

private:
	string favourite_song_;
};

class Teacher: public Person {
public:

	Teacher(const string& name, const string& subject) :
			Person(name, "Teacher"), subject_(subject) {
	}

	void Teach() {
		cout << "Teacher: " << name_ << " teaches: " << subject_ << endl;
	}

private:
	string subject_;
};

class Policeman: public Person {
public:
	Policeman(const string& name) :
			Person(name, "Policeman") {
	}

	void Check(Person p) {
		cout << "Policeman: " << name_ << " checks " << p.Type() << ". "
				<< p.Type() << "'s name is: " << p.Name() << endl;
	}
};

void VisitPlaces(const Person& p, const vector<string>& places) {
	for (const auto& pi : places) {
		p.Walk(pi);
	}
}



int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
