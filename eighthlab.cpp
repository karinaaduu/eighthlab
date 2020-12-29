#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int** zamena(int** A, int n, int m);
int** input(int** A, int n);
void output(int** A, int n);
void deletem(int** A, int n);

int main()
{
	setlocale(0, "");
	int n, i, m;
	cout << "������� ����������� ���������� �������= ";
	cin >> n;
	int** A = new int* [n];
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	int** B = new int* [n];
	for (i = 0; i < n; i++) {
		B[i] = new int[n];
	}	
	A = input(A, n);
	cout << "�������� ������� A[n][n] ����� ���: " << endl;
	output(A, n);
	if (n % 2 == 1) {
		m = (n - 3) / 2 + 1;
		B = zamena(A, n, m);
		cout << "������� �� ����������� ���������� ���������� ������� ����� A[m][m]= "<<A[m][m]<<endl;
	}
	else {
		m = (n - 2) / 2;
		B = zamena(A, n, m);
		cout << "��� ��� ������� ������� ������, �� �� ����������� ��� �������� ��������"<<endl;
	}
	cout << " ������, ���������� ������� B[n][n] ����� ���:" << endl;
	output(B,n);	
	deletem(A, n);
	deletem(B, n);
	system("pause");
	return 0;
}

int** zamena(int** A, int n, int m)
{    
	int i, j,k, x;
	int** c = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		c[i] = new int[n];
	}
	
	for (i = 0; i < n; i++)                //���������� �������� ������� 
	{
		for (j = 0; j < n; j++)            
		{
			c[i][j] = A[i][j];
		}
	}
	    k = 1;	
		for (j = 0; j < m; j++) {          //������������ ������� �����
			for (i = k; i < n - k; i++)    //������������ ����� �����, ������ ����
			{
				c[i][n - k] = A[i][j];    //������� ����� �������� � ������ ������� ����� �������

			}
			k = k + 1;
		}
		k = 1;
		if (n % 2 == 1)
			x = m;
		else x = m + 1;      //���� ������� ������� �������, �� ������ ������� ������ ���� ������ ���� ��������� ����������
			for (j = n - k; j > x; j--)      //������������ ������ ������
			{
				for (i = k; i < n - k; i++)  //������������ ����� ������, ������ ����
				{
					c[i][k - 1] = A[i][j];   //������� ������ �������� � ����� ������� ����� �������
				}
				k = k + 1;
			}
		return c;
}
 
int** input(int** A, int n)                  //���������� ������� ��������� ��������
{
	int i, j;
	srand(time(NULL));	              
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			A[i][j] = rand()%11;
		}
	}
	return A;
}

void output(int** A, int n)                            //������� ��� ������ �������
{ 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << A[i][j];
		}
		cout << endl;
	}
	cout<<endl;
}

void deletem(int** A, int n)          //�������� ������������� �������
{
	for (int i = 0; i < n; i++) {
		delete[] A[i];
	} delete[] A;
}

