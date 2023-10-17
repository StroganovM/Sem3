#include"BitField.h"
#include"set.h"
#include<iostream>
int main() {
	setlocale(LC_ALL, "RUS");
	TSet a(1);
	TSet b(1);
	int choose = 0;
	while (choose != 8) {
		std::cout<<"МЕНЮ:\n"<< "A:" << a << "\nB:" << b << "\n"<<  "1) Задать множество A;\n" << "2) Задать множество B;\n" << "3) Найти объединение множеств A + B;\n" <<
			"4) Найти разность множества A – B;\n" << "5) Найти пересечение множеств A * B;\n" << "6) Найти дополнение множества;\n" <<
			"7) Запустить демонстрационный пример;\n" << "8) Выход;\n"  "\nВаш ввод:";

		std::cin >> choose;
		system("cls");
		if (choose == 1) {
			int size;
			std::cout << "Введите размер множества А:";
			std::cin >> size;
			TSet tmp(size + 1);
			std::cout << "Введите элементы A:";
			std::cin >> tmp;
			a=tmp;

			system("cls");
		}
		else if (choose == 2) {
			int size;
			std::cout << "Введите размер множества B:";
			std::cin >> size;
			TSet tmp(size + 1);
			std::cout << "Введите элементы B:";
			std::cin >> tmp;
			b = tmp;
			system("cls");
		}
		else if (choose == 3) {
			if (a.GetMaxPower() == 1 && b.GetMaxPower() == 1) {
				std::cout << "Множества не инициализированны\n";
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
				std::cout << "Множества не инициализированны\n";
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
				std::cout << "Множества не инициализированны\n";
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
			std::cout << "\t1. Найти дополнение A;\n\t2. Найти дополнение B;\n" << "Ваш ввод:";
			std::cin >> sec_choose;
			system("cls");
			if (sec_choose == 1) {
				if (a.GetMaxPower() == 1) {
					std::cout << "Множество А не инициализировано\n";
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
					std::cout << "Множество B не инициализировано\n";
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
			std::cout << "Запущен демонстрационный пример на тестирование структуры данных множество\n";
			std::cout << "Решето Эратосфена.\n" << "Введите верхнюю границу целых значений:";
			std::cin >> n;
			std::cout << "Результат:";
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
			std::cout << res << "\nВ первых " << n << " числах " << k << " простых чисел.\n";
			system("pause");
			system("cls");
#else
			int k = 0;
			std::cout << "Запущен демонстрационный пример на тестирование структуры данных битовое поле\n";
			std::cout << "Решето Эратосфена.\n" << "Введите верхнюю границу целых значений:";
			std::cin >> n;
			std::cout << "Результат:";
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
			std::cout << res << "\nВ первых " << n << " числах " << k << " простых чисел.\n";
				system("pause");
			system("cls");
#endif
		}
		

	}

	return 0;
}