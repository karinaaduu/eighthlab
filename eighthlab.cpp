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
	cout << "Введите размерность квадратной матрицы= ";
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
	cout << "Заданная матрица A[n][n] имеет вид: " << endl;
	output(A, n);
	if (n % 2 == 1) {
		m = (n - 3) / 2 + 1;
		B = zamena(A, n, m);
		cout << "Элемент на пересечении диагоналей квадратной матрицы равен A[m][m]= "<<A[m][m]<<endl;
	}
	else {
		m = (n - 2) / 2;
		B = zamena(A, n, m);
		cout << "Так как порядок матрицы четный, то на пересечении нет никакого элемента"<<endl;
	}
	cout << " Значит, замененная матрица B[n][n] имеет вид:" << endl;
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
	
	for (i = 0; i < n; i++)                //копируется заданная матрица 
	{
		for (j = 0; j < n; j++)            
		{
			c[i][j] = A[i][j];
		}
	}
	    k = 1;	
		for (j = 0; j < m; j++) {          //перебираются столбцы слева
			for (i = k; i < n - k; i++)    //перебираются рядки слева, сверху вниз
			{
				c[i][n - k] = A[i][j];    //перенос левых значений в правую сторону новой матрицы

			}
			k = k + 1;
		}
		k = 1;
		if (n % 2 == 1)
			x = m;
		else x = m + 1;      //если матрица четного порядка, то правая сторона должна быть правее двух элементов посередине
			for (j = n - k; j > x; j--)      //перебираются стобцы справа
			{
				for (i = k; i < n - k; i++)  //перебираются рядки справа, сверзу вниз
				{
					c[i][k - 1] = A[i][j];   //перенос правых значений в левую сторону новой матрицы
				}
				k = k + 1;
			}
		return c;
}
 
int** input(int** A, int n)                  //присвоение массиву рандомных значений
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

void output(int** A, int n)                            //функция для вывода массива
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

void deletem(int** A, int n)          //удаление динамического массива
{
	for (int i = 0; i < n; i++) {
		delete[] A[i];
	} delete[] A;
}

