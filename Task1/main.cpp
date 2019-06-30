#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template<typename T, int rows, int cols>
void Print(T(&Matrix)[rows][cols])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T, int rows, int cols>
void Init(T(&Matrix)[rows][cols])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << "Enter [" << i << "][" << j << "] element: ";
			cin >> Matrix[i][j];
		}
	}
}
template<typename T, int rows, int cols>
void InitAuto(T(&Matrix)[rows][cols])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			Matrix[i][j] = rand() % 100;
		}
	}
}
template<typename T, int rows, int cols>
pair<T, pair<int, int>> Max(T(&Matrix)[rows][cols])
{
	T max = Matrix[0][0];
	pair<int, int> index;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (Matrix[i][j] > max)
			{
				max = Matrix[i][j];
				index = { i, j };
			}
		}
	}
	return { max, index };
}

int main()
{
	srand(time(nullptr));
	const int ROWS = 3, COLS = 5;
	int matrix[ROWS][COLS];
	InitAuto(matrix);
	Print(matrix);
	auto res = Max(matrix);
	cout << "Max element: " << res.first << " index [" << res.second.first << "][" << res.second.second << "]" << endl;
	system("pause");
	return 0;
}