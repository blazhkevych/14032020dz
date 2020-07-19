/*
Домашнее задание № 11
Курс «Язык программирования C»
Встреча №21 Тема : Функции.Передача массивов внутрь функции.
Домашнее задание
Задание 1 : Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) и вычисляет разность в днях между этими датами.Для решения этой задачи необходимо также написать функцию, которая определяет, является ли год високосным.
#include <iostream>
#include <windows.h>
using namespace std;
bool LeapYear(int year)
{
	bool res = false;
	if (year % 4 == 0)
		res = true;
	if (year % 100 == 0)
		res = false;
	if (year % 400 == 0)
		res = true;
	return res;
}
int Date(int d, int m, int y)
{
	int k = d;
	switch (m - 1)
	{
	case 12: k += 31;
	case 11: k += 30;
	case 10: k += 31;
	case  9: k += 30;
	case  8: k += 31;
	case  7: k += 31;
	case  6: k += 30;
	case  5: k += 31;
	case  4: k += 30;
	case  3: k += 31;
	case  2: if (LeapYear(y)) k += 29; else k += 28;
	case  1: k += 31;
	}
	k += (y - 1) * 365 + ((y - 1) / 4);
	return k;
}
int Difference(int d1, int d2, int m1, int m2, int y1, int y2)
{
	int k = Date(d1, m1, y1) - Date(d2, m2, y2);
	return k;
}
int main()
{
	SetConsoleOutputCP(1251);
	int d1, d2, m1, m2, y1, y2;
	cout << "Введите первый день: ";
	cin >> d2;
	cout << "Введите первый месяц: ";
	cin >> m2;
	cout << "Введите первый год: ";
	cin >> y2;
	cout << "Введите второй день: ";
	cin >> d1;
	cout << "Введите второй месяц: ";
	cin >> m1;
	cout << "Введите второй год: ";
	cin >> y1;
	cout << "Разность в днях между этими датами составляет " << Difference(d1, d2, m1, m2, y1, y2) << " дней.\n";
	system("PAUSE");
}
*/
/*
Задание 2: Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
#include <iostream>
using namespace std;
const int SIZE = 3;
double Average(int array[][SIZE])
{
	double SUMMA = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			SUMMA += array[i][j];
	return SUMMA / (SIZE * SIZE);
}
void PrintArray(int array[][SIZE])
{
	cout << "Array" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << array[i][j] << "\t";
		cout << endl;
	}
}
void SetArray(int array[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			array[i][j] = rand() % 100;
}
int main()
{
	int a[SIZE][SIZE];
	SetArray(a);
	PrintArray(a);
	cout << "Average = " << Average(a) << endl;
	system("pause");
	return 0;
}
*/
/*
Задание 3: Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int RandInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	return min + rand() % (max - min + 1);
}
void SetRndArray1D(int arr[], int n, int min, int max)
{
	for (size_t i = 0; i < n; i++)
		arr[i] = RandInt(min, max);
}
void ShowArray1D(int arr[], int n)
{
	for (size_t i = 0; i < n; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}
int PositiveArrayElement(int arr[], int n)
{
	int PosEl = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			PosEl++;
	}
	return PosEl;
}
int NegativeArrayElement(int arr[], int n)
{
	int NegEl = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			NegEl++;
	}
	return NegEl;
}
int ZeroArrayElement(int arr[], int n)
{
	int ZerEl = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			ZerEl++;
	}
	return ZerEl;
}
int main()
{
	SetConsoleOutputCP(1251);
	int const size = 100;
	srand(time(0));
	int arr[size]{ 0 };
	int min = -10, max = 10;
	cout << "Введите размер массива: ";
	int n;
	cin >> n;
	SetRndArray1D(arr, n, min, max);
	RandInt(min, max);
	cout << "Массив: " << endl;
	ShowArray1D(arr, n);
	cout << "В передаваемом функции массиве элементов:\n\n- положительных: " << PositiveArrayElement(arr, n) << endl;
	cout << "- отрицательых: " << NegativeArrayElement(arr, n) << endl;
	cout << "- нулевых: " << ZeroArrayElement(arr, n) << endl;
}
*/