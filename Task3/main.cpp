#include <iostream>
using namespace std;

template<typename T>
struct result
{
	T minimum, maximum;
};

template <typename T>
result<T> max_min(const std::initializer_list<T>& list)
{
	result<T> res = { *list.begin(), *list.begin() };
	for (T element : list)
	{
		if (res.maximum < element)
			res.maximum = element;
		else if (res.minimum > element)
			res.minimum = element;
	}
	return res;
}
template <typename T>
pair<T,T> max_min_pair(const std::initializer_list<T>& list)
{
	pair<T, T> res{*list.begin(), *list.begin()};
	for (T element : list)
	{
		if (res.second < element)
			res.second = element;
		else if (res.first > element)
			res.first = element;
	}
	return res;
}

int main()
{
	initializer_list<int> list = { 44, 2, 3, 4, 5, 1, 5, 44, 3 };
	auto res = max_min(list);
	cout << "Struct. Min: " << res.minimum << " Max: " << res.maximum << endl;
	auto res_pair = max_min_pair(list);
	cout << "Pair.   Min: " << res_pair.first << " Max: " << res_pair.second << endl;
	system("pause");
	return 0;
}