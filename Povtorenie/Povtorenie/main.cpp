#include <iostream>
#include <stdlib.h> 
#include <time.h>
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
	std::string stipuha;
	std::string funding;
public:
	Student() {
		id = 0;
		srednyball = 0.0;
		stipuha = "no";
		funding = "no";
	}
	Student(FIO _student, int _id, float _sredball, std::string _stipuha, std::string _funding)
	{}
	Student(const Student& a) : student(a.student), id(a.id), srednyball(a.srednyball), stipuha(a.stipuha), funding(a.funding)
	{}
	Student& operator =(const Student& a) {
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
	FIO get_student_FIO() {
		return student;
	}
	
	friend std::ostream& operator << (std::ostream& out, const Student& a);
	friend std::istream& operator >>(std::istream& in, Student& a);
	friend bool operator ==(const Student& a, const Student& b) {
		return   (a.student == b.student) && (a.id == b.id) && (a.srednyball == b.srednyball) && (a.stipuha == b.stipuha) && (a.funding == b.funding);
	}
	FIO get_FIO() {
		return student;
	}
	int get_id() {
		return id;
	}
	int GetRandomNumber()
	{
		srand(time(NULL));
		int num = 10000000 + rand() % (99999999 - 10000000 + 1);

		return num;
	}

};
std::ostream& operator << (std::ostream& out, const Student& a) {
	out << "\nFIO Student:\n" << a.student << "\nStudents bilet: " << a.id << "\nStipendia: " << a.stipuha << "\nFunding: " << a.funding << "\nSredny ball: "<< a.srednyball;
	return out;
}
std::istream& operator>>(std::istream& input, Student& a) {
	std::cout << "Input FIO Student:\n";
	input >> a.student;
	//std::cout << "Input number of students bilet: ";
	//input >> a.id;
	a.id = a.GetRandomNumber();
	std::cout << "Input stipendia: ";
	input >> a.stipuha;
	
	std::cout << "Input funding: ";
	input >> a.funding;
	std::cout << "Input sredball: ";
	input >> a.srednyball;
	return input;
}
class archive {
	int capacity;
	int size;
	Student* list;
public:
	archive() : size(0), capacity(5) {
		list = new Student[capacity];
	}
	archive(int _capacity) :
		size(0), capacity(_capacity)
	{
		list = new Student[capacity];
	}
	archive(const archive& a) :
		size(a.size), capacity(a.capacity), list(a.list)
	{}
	~archive() {
		delete[] list;
		list = nullptr;
	}

	void add(const Student& a) {
		if (size >= capacity) {
			int new_capacity = capacity * 2;
			Student* new_list = new Student[new_capacity];
			for (int i = 0; i < capacity; i++) {
				new_list[i] = list[i];
			}
			delete[] list;
			list = new_list;
			capacity = new_capacity;
		}
		list[size] = a;
		size++;
	}
	void search_student(const FIO& a) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (a == list[i].get_student_FIO()) {
				counter++;
			}
		}
		int* doc_list = new int[counter];
		int counter1 = 0;
		if (counter != 0) {
			for (int i = 0; i < size; i++) {
				if (a == list[i].get_student_FIO()) {
					doc_list[counter1] = i;
					counter1++;
				}
			}
			for (int i = 0; i < counter1; i++) {
				std::cout << "\n" << doc_list[i] + 1 << ") " << list[i];
			}

		}
		else {
			std::cout << "not found";
		}
	}
	void remove(int _count) {
		int index = _count - 1;
		for (int i = index; i < size - 1; i++) {
			if (list[i].get_id() == _count) {
				list[i] = list[i + 1];
			}
			
		}
		size--;
	}
	
	void display() {
		for (int i = 0; i < size; i++) {
			std::cout << "\n" << i + 1 << ") " << list[i];
		}
	}
};
int main() {
	int choose = 0;
	Student new_student;
	archive baza;
	FIO student;
	int index = 0, sid=0;
	while (true) {
		std::cout << "1.Add a new student.\n2.Show the list.\n3.Search student.\n4.Remove.\n5.Exit\nYour choise:";
		std::cin >> choose;
		switch (choose) {
		case 1:

			std::cin >> new_student;
			baza.add(new_student);
			choose = 0;
			break;
		case 2:
			baza.display();
			std::cout << "\n";
			system("pause");
			choose = 0;
			break;
		case 3:
			
			std::cin >> student;
			baza.search_student(student);
			choose = 0;
			system("pause");
			break;
		case 4:
			std::cout << "Input num of sudbillet: ";
			std::cin >> sid;
			baza.remove(sid);
			choose = 0;
			break;
		case 5:
			return 0;
		}
		system("cls");
	}
	std::cout << "Bye-bye";
	return 0;
}