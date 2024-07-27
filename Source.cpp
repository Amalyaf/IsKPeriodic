#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(string str, int k)
{
	//если длина строки и число k не кратны, следовательно строка сама не может быть кратна этому числу
	if (str.size() % k != 0)
	{
		return false;
	}

	//создаём массив periodic для хранения подстроки длиной k
	char* periodic = new char[k];

	for (int i = 0; i < k; i++)
	{
		periodic[i] = str[i];
	}

	int j = 0;
	for (int i = k; i < str.size(); i++)
	{
		if (str[i] != periodic[j])
		{
			delete[]periodic;
			return false;
		}
		j++;
		if (j == k)
		{
			j = 0;
		}
	}

	delete[]periodic;
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
		getline(cin,str);
		cout << "Введите число k:" << endl;
		cin >> k;
		int length = str.size();

		if (k <= 0)
		{
			cout<<"Число k должно быть больше нуля!" << endl;
		}
		else if (k > length)
		{
			cout << "Число k не должно быть больше длины строки!" << endl;
		}
		else if (IsKPeriodic(str, k))
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
		cin.get();//убирает оставшийся в потоке символ перехода на новую строку
	}
	return 0;
}