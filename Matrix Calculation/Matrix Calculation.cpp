// Mathematic Group Project (Matrix)
#include <iostream>
#include <iomanip>
using namespace std;
const int ROW = 100, COLUMN = 100;
void inputmatrix(int, int*, int*, int*, int*, float matrix1[ROW][COLUMN], float matrix2[ROW][COLUMN]);
void addsubtractMatrix(int*, int*, int*, int*, float matrix1[ROW][COLUMN], float matrix2[ROW][COLUMN]);
void multipleMatrix(int*, int*, int*, int*, float matrix1[ROW][COLUMN], float matrix2[ROW][COLUMN]);
void traceMatrix(int*, int*, float matrix1[ROW][COLUMN]);
void transposeMatrix(int*, int*, float matrix1[ROW][COLUMN]);

int main()
{
	int operation = 0,rowA = 0,columnA = 0, rowB = 0, columnB= 0;
	float matrixA[ROW][COLUMN] = {}, matrixB[ROW][COLUMN] = {};
	cout << "Hello, which calculation would you like to perform?\n";
	cout << "Enter 1 for Addition and Subtraction\nEnter 2 for Multiplication\nEnter 3 for Trace\nEnter 4 for Transpose\n";
	cin >> operation;
	if (operation == 1)
	{
		inputmatrix(operation, &rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
		addsubtractMatrix(&rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
	}
	else if(operation == 2)
	{
		inputmatrix(operation, &rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
		multipleMatrix(&rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
	}
	else if (operation == 3)
	{
		inputmatrix(operation, &rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
		traceMatrix(&rowA, &columnA, matrixA);
	}
	else if (operation == 4)
	{
		inputmatrix(operation, &rowA, &columnA, &rowB, &columnB, matrixA, matrixB);
		transposeMatrix(&rowA, &columnA, matrixA);
	}
	else
	{
		cout << "\nInvalid Operation!\n";
		cout << "Please enter 1 - 4 only\n";
	}
}
void inputmatrix(int op, int* rowA, int* columnA, int* rowB, int* columnB, float matrixA[ROW][COLUMN], float matrixB[ROW][COLUMN])
{
	if (op == 1 || op == 2)
	{
		float result[ROW][COLUMN] = {};
		//Matrix A
		cout << "Input Matrix A,\n";
		cout << "How many rows?\n";
		cin >> *rowA;
		cout << "How many columns?\n";
		cin >> *columnA;
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnA; j++)
			{
				cout << "Enter R" << i + 1 << "C" << j + 1 << " ";
				cin >> matrixA[i][j];
			}
			cout << "\n";
		}
		cout << "Matrix A:\n";
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnA; j++)
			{
				cout << setw(3);
				cout << matrixA[i][j] << " ";
			}
			cout << "\n";
		}
		//Matrix B
		cout << "\nInput Matrix B,\n";
		cout << "How many rows?\n";
		cin >> *rowB;
		cout << "How many columns?\n";
		cin >> *columnB;
		for (int i = 0; i < *rowB; i++)
		{
			for (int j = 0; j < *columnB; j++)
			{
				cout << "Enter R" << i + 1 << "C" << j + 1 << " ";
				cin >> matrixB[i][j];
			}
			cout << "\n";
		}
		cout << "Matrix B:\n";
		for (int i = 0; i < *rowB; i++)
		{
			for (int j = 0; j < *columnB; j++)
			{
				cout << setw(3);
				cout << matrixB[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		//input Matrix A
		cout << "Input Matrix A,\n";
		cout << "How many rows?\n";
		cin >> *rowA;
		cout << "How many columns?\n";
		cin >> *columnA;
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnA; j++)
			{
				cout << "Enter R" << i + 1 << "C" << j + 1 << " ";
				cin >> matrixA[i][j];
			}
			cout << "\n";
		}
		cout << "Matrix A:\n";
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnA; j++)
			{
				cout << setw(3);
				cout << matrixA[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
void addsubtractMatrix(int* rowA, int* columnA, int* rowB, int* columnB, float matrixA[ROW][COLUMN], float matrixB[ROW][COLUMN])
{
	int choice = 0, result[ROW][COLUMN];
	//check for compatibilty
	if ((*rowA == *rowB) && (*columnA == *columnB))
	{
		cout << "choose an operation : \n1 addition\n2 subtraction\n";
		cin >> choice;
		switch (choice)
		{
		case (1):
			cout << "Adding the two matrix to form the third matrix .....\n";
			for (int i = 0; i < *rowA; i++)
			{
				for (int j = 0; j < *columnB; j++)
				{
					result[i][j] = matrixA[i][j] + matrixB[i][j];
				}
			}
			cout << "The two matrix added successfully...!!";
			cout << "The new matrix will be :\n";
			for (int i = 0; i < *rowA; i++)
			{
				for (int j = 0; j < *columnB; j++)
				{
					cout << setw(3);
					cout << result[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		case (2):
			cout << "Subtracting the two matrix to form the third matrix .....\n";
			for (int i = 0; i < *rowA; i++)
			{
				for (int j = 0; j < *columnB; j++)
				{
					result[i][j] = matrixA[i][j] - matrixB[i][j];
				}
			}
			cout << "The two matrix subtracted successfully...!!";
			cout << "The new matrix will be :\n";
			for (int i = 0; i < *rowA; i++)
			{
				for (int j = 0; j < *columnB; j++)
				{
					cout << setw(3);
					cout << result[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}
	else
	{
		cout << "\nInvalid Operation!\n";
		cout << "Row and column of Matrix A must be same with row and column of Matrix B to perform matrix addition and subtraction.\n";
	}
	
}
void multipleMatrix(int* rowA, int* columnA, int* rowB, int* columnB, float matrixA[ROW][COLUMN], float matrixB[ROW][COLUMN])
{
	//check compatibility
	float total = 0, result[ROW][COLUMN];
	if (*columnA == *rowB)
	{
		for (int i = 0; i < *rowA; i++)
		{
			int clmn = 0;
			for (int j = 0; j < *columnB; j++)
			{
				for (int k = 0; k < *columnA; k++)
				{
					total += matrixA[i][k] * matrixB[k][clmn];
				}
				result[i][j] = total;
				total = 0;
				clmn++;
			}
		}
		cout << "\nResult:\n";
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnB; j++)
			{
				cout << setw(3);
				cout << result[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "\nIncompatible matrices for multiplication!\n";
		cout << "Number of columns for Matrix A must be the same as number of rows for Matrix B\n";
	}
}
void traceMatrix(int* rowA, int* columnA, float matrixA[ROW][COLUMN])
{

	float trace = 0;
	//Check Compatibility
	if (*rowA == *columnA && *rowA != 1)
	{
		for (int i = 0; i < *rowA; i++)
		{
			for (int j = 0; j < *columnA; j++)
			{
				if (i + j == 0 || (i * 10 + j) % 11 == 0)
				{
					trace += matrixA[i][j];
				}
			}
		}
		cout << "\nThe trace of matrix A is: " << trace;
	}
	else
	{
		cout << "\nInvalid!\n";
		cout << "Matrix A must be square matrix to find the matrix 's trace\n";
	}
}
void transposeMatrix(int* rowA, int* columnA, float matrixA[ROW][COLUMN])
{
	// Finding the transpose
	float trans[ROW][COLUMN];
	for (int i = 0; i < *rowA; ++i)
		for (int j = 0; j < *columnA; ++j)
		{
			trans[j][i] = matrixA[i][j];
		}
	// Displaying the transpose
	cout << endl << "Transpose of Matrix A: " << endl;
	for (int i = 0; i < *columnA; ++i)
	{
		for (int j = 0; j < *rowA; ++j)
		{
			cout << setw(3);
			cout << trans[i][j] << " ";
		}
		cout << "\n";
	}	
}

