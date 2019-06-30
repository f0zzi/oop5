#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix<> m_int(3);
	Matrix<double> m_double(3.2);
	Matrix<string> m_string("test");

	cout << "m_int.Show():" << endl;
	m_int.Show();
	cout << "m_double.Show():" << endl;
	m_double.Show();
	cout << "m_double.Show():" << endl;
	m_string.Show();
	cout << endl;
	cout << "m_int.Search(1):" << endl;
	auto res_i = m_int.Search(1);
	cout << "Res: (" << get<0>(res_i) << "," << get<1>(res_i) << ")" << endl;
	cout << endl;

	cout << "m_double.Search(3.2):" << endl;
	auto res_d = m_double.Search(3.2);
	cout << "Res: (" << get<0>(res_d) << "," << get<1>(res_d) << ")" << endl;
	cout << endl;

	cout << "m_string.Search(\"test\"):" << endl;
	auto res_s = m_string.Search("test");
	cout << "Res: (" << get<0>(res_s) << "," << get<1>(res_s) << ")" << endl;
	cout << endl;

	cout << "m_int(1, 1) = 99" << endl;
	m_int(1, 1) = 99;
	cout << "m_double(1, 1) = 99" << endl;
	m_double(1, 1) = 99;
	cout << "m_string(1, 1) = \"check\"" << endl;
	m_string(1, 1) = "check";
	cout << "cout << m_int(1, 1) << endl;" << endl;
	cout << m_int(1, 1) << endl;
	cout << "m_int.Sum():" << endl;
	cout << m_int.Sum() << endl;
	cout << " m_double.Sum():" << endl;
	cout << m_double.Sum() << endl;
	cout << "m_string.Sum():" << endl;
	cout << m_string.Sum() << endl;
	cout << endl;

	cout << "Enter elements of int matrix:" << endl;
	cin >> m_int;
	cout << "Enter elements of double matrix:" << endl;
	cin >> m_double;
	cout << "Enter elements of string matrix:" << endl;
	cin >> m_string;
	cout << endl;

	cout << "int matrix:" << endl;
	cout << m_int << endl;
	cout << "double matrix:" << endl;
	cout << m_double << endl;
	cout << "string matrix:" << endl;
	cout << m_string << endl;
	cout << endl;

	Matrix<> m_int2;
	m_int2 = 3 + m_int;
	cout << m_int + m_int2;
	cout << m_string + "sd";
	m_string += "add";
	cout << m_string;
	cout << m_int2;
	m_int2 += 10;
	cout << m_int2;
	cout << int(m_int2) << endl;
	cout << double(m_double) << endl;
	cout << string(m_string) << endl;
	cout << boolalpha << (m_int == m_int2) << endl;
	cout << boolalpha << (m_int != m_int2) << endl;
	cout << "Number of objects Matrix: " << Matrix<>::getNumArrays() << endl;
	system("pause");
	return 0;
}