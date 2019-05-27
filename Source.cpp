#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int CntEvensInOctal(int x);
bool IsLess(int lhs, int rhs);
void quickSort(int l, int r, int* data);
int arr_uniq(int matrix[], int & size, int*arr);


int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	int* row_size = new int[n];
	int** matrix = new int*[n];
	for (int i = 0; i < n; ++i) {
		cin >> row_size[i];
		matrix[i] = new int[row_size[i]];
	}

	srand(time(nullptr));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < row_size[i]; ++j) {
			matrix[i][j] = rand() % 10;
			if (j > 0 && matrix[i][j] == matrix[i][j - 1]) --j;
		}
	}

	cout << "Matrix:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < row_size[i]; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; ++i) {
		int k = arr_uniq(matrix[i], row_size[i], arr);
		quickSort(0, k-1, matrix[i]);
	}

	cout << "Sorted matrix:" << endl;
	for (int i = 0; i < n; ++i) {
		int k = arr_uniq(matrix[i], row_size[i], arr);
		for (int j = 0; j < k; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


int CntEvensInOctal(int x) {
	int res = 0;
	while (x != 0) {
		int bit = x % 8;
		if (bit % 2 == 0) {
			++res;
		}
		x /= 8;
	}

	return res;
}


bool IsLess(int lhs, int rhs) {
	return CntEvensInOctal(lhs) < CntEvensInOctal(rhs);
}

void quickSort(int l, int r, int* data) {
	int i = l, j = r;
	int ind = l + std::rand() % (r - l + 1);
	int x = data[ind];
	do {
		while (IsLess(data[i], x)) ++i;
		while (IsLess(x, data[j])) --j;
		if (i <= j) {
			std::swap(data[i], data[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j) quickSort(l, j, data);
	if (i < r) quickSort(i, r, data);
}

int arr_uniq(int matrix[], int & size, int* arr)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (matrix[i] == matrix[j])
				{
					swap(matrix[size - 1], matrix[j]);
					size--;
				}
			}
		}
	}
	return size;
}
