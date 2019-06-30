#pragma once
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

template<typename T = int, int rows = 2, int cols = 3>
class Matrix
{
private:
	T matrix[rows][cols];
	static int counter;
public:
	Matrix(T value = T())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = value;
			}
		}
		++counter;
	}
	void Show() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
	T GetMax() const
	{
		T max = T();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] > max)
					max = matrix[i][j];
			}
		}
		return max;
	}
	T GetMin() const
	{
		T min = T();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] < min)
					min = matrix[i][j];
			}
		}
		return min;
	}
	tuple<int, int> Search(const T& elem)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == elem)
					return { i, j };
			}
		}
		return { -1, -1 };
	}
	T& operator() (int row, int col)
	{
		static T errorValue = T();
		if (row > rows || col > cols)
			return errorValue;
		else
			return matrix[row][col];
	}
	T Sum() const
	{
		T sum = T();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				sum += matrix[i][j];
			}
		}
		return sum;
	}

	template<typename T, int rows, int cols>
	friend ostream& operator<<(ostream & out, const Matrix<T, rows, cols> & matrix);
	template<typename T, int rows, int cols>
	friend istream& operator>>(istream & in, Matrix<T, rows, cols> & m);

	Matrix operator+(const Matrix & two)
	{
		Matrix<T, rows, cols> res;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res.matrix[i][j] = matrix[i][j] + two.matrix[i][j];
			}
		}
		return res;
	}
	Matrix operator+(T value)
	{
		Matrix<T, rows, cols> res;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res.matrix[i][j] = matrix[i][j] + value;
			}
		}
		return res;
	}
	template<typename T, int rows, int cols>
	friend Matrix<T, rows, cols> operator+(T value, const Matrix<T, rows, cols> & two);

	Matrix& operator+=(T value)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] += value;
			}
		}
		return *this;
	}
	operator T() const
	{
		return Sum();
	}

	template<typename T, int rows, int cols>
	friend bool operator==(const Matrix<T, rows, cols> & one, const Matrix<T, rows, cols> & two);

	static int getNumArrays()
	{
		return counter;
	}
};

template<typename T, int rows, int cols>
int Matrix<T, rows, cols> ::counter = 0;

template<typename T, int rows, int cols>
ostream& operator<<(ostream & out, const Matrix<T, rows, cols> & m)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			out << m.matrix[i][j] << "\t";
		}
		out << endl;
	}
	return out;
}
template<typename T, int rows, int cols>
istream& operator>>(istream & in, Matrix<T, rows, cols> & m)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter [" << i << "][" << j << "] element: ";
			in >> m.matrix[i][j];
		}
	}
	return in;
}
template<typename T, int rows, int cols>
Matrix<T, rows, cols> operator+(T value, const Matrix<T, rows, cols> & two)
{
	Matrix<T, rows, cols> res;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			res.matrix[i][j] = two.matrix[i][j] + value;
		}
	}
	return res;
}
template<typename T, int rows, int cols>
bool operator==(const Matrix<T, rows, cols> & one, const Matrix<T, rows, cols> & two)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (one.matrix[i][j] != two.matrix[i][j])
				return false;
		}
	}
	return true;
}
template<typename T, int rows, int cols>
bool operator!=(const Matrix<T, rows, cols>& one, const Matrix<T, rows, cols>& two)
{
	return !(one == two);
}