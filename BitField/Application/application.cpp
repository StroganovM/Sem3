#include"BitField.h"
#include"set.h"
#include<iostream>
int main() {
	setlocale(LC_ALL, "RUS");
	TSet a(1);
	TSet b(1);
	int choose = 0;
	while (choose != 8) {
		std::cout<<"����:\n"<< "A:" << a << "\nB:" << b << "\n"<<  "1) ������ ��������� A;\n" << "2) ������ ��������� B;\n" << "3) ����� ����������� �������� A + B;\n" <<
			"4) ����� �������� ��������� A � B;\n" << "5) ����� ����������� �������� A * B;\n" << "6) ����� ���������� ���������;\n" <<
			"7) ��������� ���������������� ������;\n" << "8) �����;\n"  "\n��� ����:";

		std::cin >> choose;
		system("cls");
		if (choose == 1) {
			int size;
			std::cout << "������� ������ ��������� �:";
			std::cin >> size;
			TSet tmp(size + 1);
			std::cout << "������� �������� A:";
			std::cin >> tmp;
			a=tmp;

			system("cls");
		}
		else if (choose == 2) {
			int size;
			std::cout << "������� ������ ��������� B:";
			std::cin >> size;
			TSet tmp(size + 1);
			std::cout << "������� �������� B:";
			std::cin >> tmp;
			b = tmp;
			system("cls");
		}
		else if (choose == 3) {
			if (a.GetMaxPower() == 1 && b.GetMaxPower() == 1) {
				std::cout << "��������� �� �����������������\n";
				system("pause");
			}
			else {
				std::cout << "A+B = { " << a + b << "}";
				system("pause");

			}
			system("cls");
		}
		else if (choose == 4) {
			if (a.GetMaxPower() == 1 && b.GetMaxPower() == 1) {
				std::cout << "��������� �� �����������������\n";
				system("pause");
			}
			else {
				TSet tmp = ~b;
				std::cout << "A-B = { " << a * tmp << "}";
				system("pause");

			}
			system("cls");
		}
		else if (choose == 5) {
			if (a.GetMaxPower() == 1 && b.GetMaxPower() == 1) {
				std::cout << "��������� �� �����������������\n";
				system("pause");
			}
			else {
				std::cout << "A*B = { " << a * b << "}";
				system("pause");

			}
			system("cls");
		}
		else if (choose == 6) {
			int sec_choose = 0;
			std::cout << "\t1. ����� ���������� A;\n\t2. ����� ���������� B;\n" << "��� ����:";
			std::cin >> sec_choose;
			system("cls");
			if (sec_choose == 1) {
				if (a.GetMaxPower() == 1) {
					std::cout << "��������� � �� ����������������\n";
					system("pause");
				}
				else {
					std::cout << "!A = { " << ~a << "}";
					system("pause");

				}
				system("cls");
			}
			else if (sec_choose == 2) {
				if (b.GetMaxPower() == 1) {
					std::cout << "��������� B �� ����������������\n";
					system("pause");
				}
				else {
					std::cout << "!B = { " << ~b << "}";
					system("pause");

				}
				system("cls");
			}
		}
		else if (choose == 7) {
			int n;
			system("cls");

#define USE_SET 1
#if USE_SET == 1
			int k = 0;
			std::cout << "������� ���������������� ������ �� ������������ ��������� ������ ���������\n";
			std::cout << "������ ����������.\n" << "������� ������� ������� ����� ��������:";
			std::cin >> n;
			std::cout << "���������:";
			TSet rest(n);
			TSet res(n);
			res = ~rest;
			for (int i = 2; i <= sqrt(n - 1); i++) {
				if (res.IsMember(i) == 1) {
					for (int j = 2; i * j <= n - 1; j++) {
						res.DelElem(i * j);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (res.IsMember(i) == 1) {
					k++;
				}
			}
			std::cout << res << "\n� ������ " << n << " ������ " << k << " ������� �����.\n";
			system("pause");
			system("cls");
#else
			int k = 0;
			std::cout << "������� ���������������� ������ �� ������������ ��������� ������ ������� ����\n";
			std::cout << "������ ����������.\n" << "������� ������� ������� ����� ��������:";
			std::cin >> n;
			std::cout << "���������:";
			TBitField rest(n);
			TBitField res(n);
			res = ~rest;
			for (int i = 2; i <=sqrt( n - 1); i++) {
				if (res.test(i) == 1) {
					for (int j = 2; i * j <= n - 1; j++) {
						res.reset(i * j);
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (res.test(i) == 1) {
					k++;
				}
			}
			std::cout << res << "\n� ������ " << n << " ������ " << k << " ������� �����.\n";
				system("pause");
			system("cls");
#endif
		}
		

	}

	return 0;
}