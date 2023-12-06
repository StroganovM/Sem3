#include <iostream>
#include <string>
#include <vector>
#include <list>
double power(double x, int n) {
	int i = 0;
	double res = 1;
	while (i < n) {
		res= res*x;
		i++;
	}
	return res;
}
double power(double x, float n) {
	int i = 0;
	double res = 1;
	while (i < n) {
		res = res * x;
		i++;
	}
	return res;
}
int factorial(int x){
	int res = 1;
	if (x == 0) {
		return 1;
	}
	else {
		for (int i = 1; i <= x; i++) {
			res = res * i;
		}
	}
	return res;
}
double CalcSin(float x) {
	double sin = 0;
	for (int i = 0; i <=12; i++) {
		sin = sin + power(-1.0, i) * power(x, (2 * i+1)) / factorial(2 * i+1);
	}
	return sin;
}
double CalcCos(float x) {
	double cos =0 ;
	for (int i = 0; i <= 10; i++) {
		cos = cos + power(-1.0, i) * power(x, (2 * i)) / factorial(2 * i);
	}
	return cos;
}

double CalcTg(float x) {
	double res = CalcSin(x) / CalcCos(x);
	return res;
}
double CalcCtg(float x) {
	double res = CalcCos(x) / CalcSin(x);
	return res;
}
double CalcLn(float x) {
	float y = x + 1;
	double ln = 0;
	for (int i = 0; i <= 8; i++) {
		ln = ln + power(-1.0, i) * (power(y, i+1) / i+1);
	}
	return ln;
}

int main() {
	double res,  x =3.14/4;
	double y=2;
	res = CalcTg(x);
	std::cout << res << "\n";
	return 0;
}