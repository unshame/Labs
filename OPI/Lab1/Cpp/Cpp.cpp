#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

typedef long long int64;


int64 Factorial(int64 a) {
	if (a <= 1)
		return 1;

	int64 res = a;

	while (--a > 0) {
		res = res * a;
	}

	return res;
}

//  Negative roots lel
double PowWithNegative(double n, double pow) {

	if (n < 0) {
		return std::pow(n * -1, pow) * -1;
	}
	else {
		return std::pow(n, pow);
	}
}

// http://www.1728.org/cubic2.htm
// b = 0, c = 0
string SolveKindOfCubic(double a, double d) {

	string x1 = "", x2 = "", x3 = "";

	double g = d / a;

	double hsqrt = std::sqrt(g * g / 4);

	double pow = 1.0 / 3.0;

	double s = -(g / 2) + hsqrt;
	s = PowWithNegative(s, pow);

	double u = -(g / 2) - hsqrt;
	u = PowWithNegative(u, pow);

	x1 = std::to_string(s + u);
	// ((S+U) - (b/(3*a)))
	x2 = std::to_string((-1 * (s + u) / 2)) + " + i*" + std::to_string(((s - u) / 2) * std::pow(3, 0.5));
	// -(S + U)/2 - (b/3a) + i*(S-U)*(3)^.5
	x3 = std::to_string((-1 * (s + u) / 2)) + " - i*" + std::to_string(((s - u) / 2) * std::pow(3, 0.5));

	return "x1 = " + x1 + ";\nx2 = " + x2 + ";\nx3 = " + x3;
}

static int64 CountEvenColPositiveCells(int64** matrix, int64 n, int64 m) {
	int64 count = 0;

	for (int64 i = 1; i < n; i = i + 2) {
		for (int64 k = 0; k < m; k++) {
			if (matrix[i][k] > 0) {
				count++;
			}
		}
	}

	return count;
}

int64** ReadMatrix(std::ifstream& input, int64 n, int64 m) {
	int64** res = new int64*[n];
	for (int64 i = 0; i < n; i++) {
		res[i] = new int64[m];
		for (int64 k = 0; k < m; k++) {
			input >>  res[i][k];
			cout << res[i][k] << " ";
		}
		cout << endl;
	}
	return res;
}

int main(int argc, char *argv[])
{
	string path = argc > 2 ? argv[2] : "D:\\VSProjects\\repos\\OPI\\Lab1\\Debug\\input.txt";
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		cout << "FUCK";
		return 1;
	}

	int64 n1 = argc > 3 ? std::atol(argv[3]) : 5;
	int64 n2 = argc > 4 ? std::atol(argv[4]) : 6;

	int amount;
	input >> amount;

	while (amount--) {

		cout << "T(5, 5)\n";
		int64** m1 = ReadMatrix(input, n1, n1);
		cout << "D(6, 6)\n";
		int64** m2 = ReadMatrix(input, n2, n2);
		cout << endl;

		int64 c1, c2;
		c1 = CountEvenColPositiveCells(m1, n1, n1);
		c2 = CountEvenColPositiveCells(m2, n2, n2);
		cout << "a = " << c1 << endl;
		cout << "b = " << c2 << endl;

		double a = 3 * Factorial(c1 + c2);
		double d = 2 * Factorial(c1);

		cout << "Solving cubic equiation for a = " << a << "; b = 0; c = 0; d = " << d << ";\n";
		cout << SolveKindOfCubic(a, d);
		cout << "\n\n";

		for (int64 i = 0; i < n1; i++){
			delete m1[i];
		}
		for (int64 i = 0; i < n2; i++) {
			delete m2[i];
		}
		delete m1;
		delete m2;
	}

	input.close();

	return 0;
}
