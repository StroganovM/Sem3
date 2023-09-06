#include <iostream>
class FIO {
	std::string name, surname, lastname;
public:
	FIO() {
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
	}
	FIO(std::string _name, std::string _surname, std::string _lastname) :name(_name), surname(_surname), lastname(_lastname) {}
	FIO(const FIO& a) :name(a.name), surname(a.surname), lastname(a.lastname) {}
	FIO& operator =(FIO& a) {
		if (this != &a) {
			FIO tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(FIO& a) {
		std::swap(this->name, a.name);
		std::swap(this->surname, a.surname);
		std::swap(this->lastname, a.lastname);
	}
	friend std::ostream& operator << (std::ostream& out, const FIO& a);
	friend std::istream& operator>>(std::istream& in, FIO& a);
	friend bool operator ==(const FIO& a, const FIO& b) {
		return (a.name == b.name) && (a.surname == b.surname) && (a.lastname == b.lastname);
	}
};
std::ostream& operator << (std::ostream& out, const FIO& a) {
	out << a.name << " " << a.surname << " " << a.lastname;
	return out;
}
std::istream& operator>>(std::istream& input, FIO& a) {
	std::cout << "Input name: ";
	input >> a.name;
	std::cout << "Input surname: ";
	input >> a.surname;
	std::cout << "Input lastname: ";
	input >> a.lastname;
	return input;
}
class Student {
	FIO student;
	int id;
	float srednyball;
	bool stipuha;
	bool funding;
public:
	Student() {
		id = 0;
		srednyball = 1.1;
		stipuha = 0;
		funding = 0;
	}Student(FIO _student, int _id, float _sredball, bool _stipuha, bool _funding)
	{}
	Student(const Student& a) : student(a.student), id(a.id), srednyball(a.srednyball), stipuha(a.stipuha), funding(a.funding)
	{}
	Student& operator =(Student& a) {
		if (this != &a) {
			Student tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(Student& a) {
		student.swap(a.student);
		std::swap(this->id, a.id);
		std::swap(this->srednyball, a.srednyball);
		std::swap(this->stipuha, a.stipuha);
		std::swap(this->funding, a.funding);
	}
	friend std::ostream& operator << (std::ostream& out, const Student& a);
	friend std::istream& operator >>(std::istream& in, Student& a);
	friend bool operator ==(const Student& a, const Student& b) {
		return   (a.student == b.student) && (a.id == b.id) && (a.srednyball == b.srednyball) && (a.stipuha == b.stipuha) && (a.funding == b.funding);
	}
	FIO get_FIO() {
		return student;
	}
};
std::ostream& operator << (std::ostream& out, const Student& a) {
	out << "\nFIO Student:\n" << a.student << "\nStudents bilet: " << a.id << "\nStipendia: " << a.stipuha << "\nFunding" << a.funding;
	return out;
}
std::istream& operator>>(std::istream& input, Student& a) {
	std::cout << "Input FIO Student:\n";
	input >> a.student;
	std::cout << "Input number of students bilet: ";
	input >> a.id;
	std::cout << "Input stipendia: ";
	input >> a.stipuha;
	std::cout << "Input funding: ";
	input >> a.funding;

	return input;
}