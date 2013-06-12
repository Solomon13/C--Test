// lab4_Alena.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int** InitMatrix(int &n);
void MainMenu(int &n, int ** mas);
int** DefaultInit(int n);
int FindSolution(int n, int **mas);
void Print(int n, int **mas);

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 6;
	int **mas;
	
	mas = DefaultInit(n);
	MainMenu(n, mas);
	system("pause");
	for(int i = 0; i < n; i++)
	{
		delete []mas[i];
	}
	return 0;
}

int** InitMatrix(int &n)
{
	cout<<"*****Function Init Function*****"<<endl;
	cout<<"Write n = ";
	cin>>n;
	int **res = new int *[n];
	for(int i = 0; i < n; i++)
	{
		res[i] = new int [n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<"Write element i = "<<i<<" j = "<<j<<'\t';
			cin>>res[i][j];
		}
		cout<<endl;
	}

	return res;
}

void MainMenu(int &n, int ** mas)
{
	bool exit = false;
	int op = 0;
	while(!exit)
	{
		cout<<"*****Main Menu*****"<<endl;
		cout<<"1.\tInit Matrix"<<endl;
		cout<<"2.\tSolve 8 variant"<<endl;
		cout<<"3.\tPrint matrix"<<endl;
		cout<<"Other. Exit"<<endl;
		cin>>op;

		switch(op)
		{
			case 1:
				mas = InitMatrix(n);
				break;
			case 2:
				{
					Print(n,mas);
					int sum = FindSolution(n, mas);
					cout<<"Result is = "<<sum<<endl;
				}break;
			case 3: Print(n,mas); break;
			default: exit = true;
		}
	}
}

int** DefaultInit(int n)
{
	int **res = new int *[n];
	for(int i = 0; i < n; i++)
	{
		res[i] = new int [n];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			res[i][j] = rand()%10;
		}
	}

	return res;
}

int FindSolution(int n, int **mas)
{
	int sum = 0;
	for(int i = n-1; i >=0; i--)
	{
		for(int j = i; j >= (n - i -1); j--)
		{
			sum += mas[i][j];
		}
	}

	return sum;
}

void Print(int n, int **mas)
{
	cout<<"Printing function"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<mas[i][j]<<'\t';
		}
		cout<<endl;
	}
}