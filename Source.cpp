#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(string str, int k)
{
	//���� ����� ������ � ����� k �� ������, ������������� ������ ���� �� ����� ���� ������ ����� �����
	if (str.size() % k != 0)
	{
		return false;
	}

	//������ ������ periodic ��� �������� ��������� ������ k
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
		cout << "������� ������:" << endl;
		getline(cin,str);
		cout << "������� ����� k:" << endl;
		cin >> k;
		int length = str.size();

		if (k <= 0)
		{
			cout<<"����� k ������ ���� ������ ����!" << endl;
		}
		else if (k > length)
		{
			cout << "����� k �� ������ ���� ������ ����� ������!" << endl;
		}
		else if (IsKPeriodic(str, k))
		{
			cout << "������ ������ ����� " << k << endl;
		}
		else
		{
			cout << "������ �� ������ ����� " << k << endl;
		}

		cout << "\n������ ����������? (y/n)" << endl;
		cin >> contin;
		cout << endl;
		cin.get();//������� ���������� � ������ ������ �������� �� ����� ������
	}
	return 0;
}