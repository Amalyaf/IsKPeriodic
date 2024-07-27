#include <iostream>
#include <string>
using namespace std;

//Входными данными для функции IsKPeriodic являются строка, которую нужно проверить, и число K, 
//которое представляет собой длину подстроки, повторяющейся в строке с заданной кратностью.

bool IsKPeriodic(string str, int k)
{
	int length = str.size();
	if (k > length)
	{
		cout << "Число k не должно быть больше длины строки!" << endl;
		return false;
	}
	if (k <= 0)
	{
		cout << "Число k должно быть больше нуля!" << endl;
		return false;
	}

	//если длина строки и число k не кратны, следовательно строка сама не может быть кратна этому числу
	if (length % k != 0)
	{
		return false;
	}

	int i = 0;
	//создаём массив periodic для хранения подстроки длиной k
	char* periodic = new char[k];

	for (i = 0; i < k; i++)
	{
		periodic[i] = str[i];
	}

	int j = 0;
	for (i = k; i < length; i++)
	{
		if (str[i] != periodic[j])
		{
			return false;
		}
		j++;
		if (j >= k)
		{
			j = 0;
		}
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "");
	string str;
	int k;

	char contin = 'y';
	while (contin=='y')
	{
		cout << "Введите строку:" << endl;
		cin.get(); //убирает оставшийся в потоке символ перехода на новую строку
		getline(cin,str);
		cout << "Введите число k:" << endl;
		cin >> k;
		if (IsKPeriodic(str, k))
		{
			cout << "Строка кратна числу " << k << endl;
		}
		else
		{
			cout << "Строка не кратна числу " << k << endl;
		}

		cout << "\nХотите продолжить? (y/n)" << endl;
		cin >> contin;
		cout << endl;
	}
	
	return 0;
}