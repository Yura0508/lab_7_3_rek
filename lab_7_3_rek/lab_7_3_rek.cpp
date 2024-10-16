// lab_7_3_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void InputRows(int** a, const int rowCount, const int colCount, int rowNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void FindEqualRowsAndCols(int** a, const int n, int k);
int SumRowsWithNegative(int** a, const int n, int i);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int n;

    cout << "Enter size of matrix (n x n): ";
    cin >> n;


    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];


    InputRows(a, n, n, 0);
    cout << endl;
    PrintRows(a, n, n, 0);
    cout << endl;


    FindEqualRowsAndCols(a, n, 0);
    cout << endl;


    int sum = SumRowsWithNegative(a, n, 0);
    cout << "Sum of rows containing at least one negative element: " << sum << endl;


    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo) {
    if (rowNo < rowCount) {
        for (int colNo = 0; colNo < colCount; colNo++) {
            cout << "a[" << rowNo << "][" << colNo << "] = ";
            cin >> a[rowNo][colNo];
        }
        cout << endl;
        InputRows(a, rowCount, colCount, rowNo + 1);
    }
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    if (rowNo < rowCount) {
        for (int colNo = 0; colNo < colCount; colNo++) {
            cout << setw(4) << a[rowNo][colNo];
        }
        cout << endl;
        PrintRows(a, rowCount, colCount, rowNo + 1);
    }
}

void FindEqualRowsAndCols(int** a, int n, int k) {
    if (k < n) {
        bool equal = true;
        for (int j = 0; j < n; j++) {
            if (a[k][j] != a[j][k]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            cout << "Row " << k << " is equal to Column " << k << endl;
        }
        FindEqualRowsAndCols(a, n, k + 1);
    }
}

int SumRowsWithNegative(int** a, const int n, int i) {
    if (i < n) {
        int sum = 0;
        bool hasNegative = false;
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
        }
        return sum + SumRowsWithNegative(a, n, i + 1);
    }
    return 0;
}
