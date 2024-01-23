#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

long long factorial(int n) {
	if (n == 0 || n == 1) return 1;
	long long result = 1;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

void main() {
	int n;
	cout << "Enter figure size: "; cin >> n;

	int wide = 0;
	long long f0 = 1, f1 = 1, f2 = 1;

	for (int i = 0; i <= n; ++i) {
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;
	}

	//calculate the width advance 
	while (f1 != 0) {
		f1 /= 10;
		wide++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			long long C = factorial(i) / (factorial(j) * factorial(i - j));
			cout << C;
			int Cwide = 0;
			// calculate the number of digits in C
			while (C != 0) {
				C /= 10;
				Cwide++;
			}
			// print spaces after C
			for (int s = 0; s <= (wide - Cwide); s++) {
				cout << " ";
			}
		}
		cout << endl;
	}
}