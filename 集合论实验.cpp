#include <iostream>
using namespace std;
int arr[100][100];
int a[2][100];
int main()
{
	int Reflexive(int n);
	int Symmetry(int n);
	int Transitivity(int n);
	int n, m;

	cout << "���������Χ:";
	cin >> m;
	cout << "�������Ԫ�����:";
	cin >> n;
	cout << "�����������Ԫ��:";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
		arr[a[i][0]][a[i][1]] = 1;
	}
	if (Reflexive(m))
		cout << "�����Է���" << endl;
	else
		cout << "���з��Է���" << endl;
	if (Symmetry(n))
		cout << "���жԳ���" << endl;
	else
		cout << "���з��Գ���" << endl;
	if (Transitivity(n))
		cout << "���д�����" << endl;
	else
		cout << "�����д�����" << endl;
	return 0;
}
int Reflexive(int m)
{
	for (int i = 0; i < m; i++)
		if (arr[i][i] == 0)
			return 0;
	return 1;
}
int Symmetry(int n)
{
	for (int i = 0; i < n; i++)
		if (arr[a[i][1]][a[i][0]] == 0)
			return 0;
	return 1;
}
int Transitivity(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][1] == a[j][0])
				if (arr[a[i][0]][a[j][1]] == 0)
					return 0;
		}
	}
	return 1;
}
