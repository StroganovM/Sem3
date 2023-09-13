#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <vector>


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
	float get_sredball(){
		return srednyball;
	}
	std::string get_funding() {
		return funding;
	}
	std::string get_stipuha() {
		return stipuha;
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
private:
	std:: vector<Student> students;
	std::string archive_name;

public:
	archive(std::string name) : archive_name(name) {}

	~archive() {}

	void add(const Student& student) {
		students.push_back(student);
	}

	void find(const FIO& a) {
		int index = 0;
		int counter = 0;
		for (int i = 0; i < students.size(); i++) {
			if (a == students[i].get_student_FIO()) {
				 index = i;
				 std::cout << students[index] << std::endl;
			}
			
			else {
				system("cls");
				std::cout << "not found" << std::endl;
			}
		}
		
		
	}
		
	
	bool deletestudent(int id) {
		auto it = remove_if(students.begin(), students.end(), [id](Student& student) {
			return student.get_id() == id;
			});
		if (it != students.end()) {
			students.erase(it, students.end());
			return true;
		}
		return false;
	}
	
	void display() {
		std::cout << "Archive (sorted by name): " << archive_name << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		std::cout << "Student ID  |  Full Name          |  Average score  |  Budget  |  Scholarship" << std::endl;
		std::cout << "--------------------------------------------------------------------------" << std::endl;
		for (auto& student : students) {
			std::cout << student.get_id() << "          |  " << student.get_FIO() << "          |  " << student.get_sredball()
				<< "  |  " << student.get_funding()  << "  |  "
				<< student.get_stipuha()  << std::endl;
		}
	}
	
	
	
	
};
int main() {
	int choose = 0;
	Student new_student;
	archive studentArchive("Student Archive");
	FIO student;
	int index = 0, sid=0;
	while (true) {
		std::cout << "1.Add a new student.\n2.Show the list.\n3.Search student.\n4.Remove.\n5.Exit\nYour choise:";
		std::cin >> choose;
		switch (choose) {
		case 1:

			std::cin >> new_student;
			studentArchive.add(new_student);
			choose = 0;
			break;
		case 2:
			studentArchive.display();
			std::cout << "\n";
			system("pause");
			choose = 0;
			break;
		case 3:
			std::cin >> student;
			studentArchive.find(student);
			choose = 0;
			system("pause");
			break;
		case 4:
			std::cout << "Input num of sudbillet: ";
			std::cin >> sid;
			studentArchive.deletestudent(sid);
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