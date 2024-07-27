#include <iostream>
#include <string>
using namespace std;

//�������� ������� ��� ������� IsKPeriodic �������� ������, ������� ����� ���������, � ����� K, 
//������� ������������ ����� ����� ���������, ������������� � ������ � �������� ����������.

bool IsKPeriodic(string str, int k)
{
	int length = str.size();
	if (k > length)
	{
		cout << "����� k �� ������ ���� ������ ����� ������!" << endl;
		return false;
	}
	if (k <= 0)
	{
		cout << "����� k ������ ���� ������ ����!" << endl;
		return false;
	}

	//���� ����� ������ � ����� k �� ������, ������������� ������ ���� �� ����� ���� ������ ����� �����
	if (length % k != 0)
	{
		return false;
	}

	int i = 0;
	//������ ������ periodic ��� �������� ��������� ������ k
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
		cout << "������� ������:" << endl;
		cin.get(); //������� ���������� � ������ ������ �������� �� ����� ������
		getline(cin,str);
		cout << "������� ����� k:" << endl;
		cin >> k;
		if (IsKPeriodic(str, k))
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
	}
	
	return 0;
}