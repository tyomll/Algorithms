#include <iostream>
using namespace std;

const int N = 10;
int a[N][N], b[N][N], mult[N][N] = {0}, r1, c1, r2, c2;

int main() {

	cout << "Enter rows and columns for first matrix: ";
	cin >> r1 >> c1;
	cout << "Enter rows and columns for second matrix: ";
	cin >> r2 >> c2;

	while (c1 != r2) {
		cout << "Error! column of first matrix not equal to row of second." << endl;

		cout << "Enter rows and columns for first matrix: ";
		cin >> r1 >> c1;

		cout << "Enter rows and columns for second matrix: ";
		cin >> r2 >> c2;
	}
	cout << endl;

	cout << "Enter Elements of Matrix 1: " << endl;
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			cout << "Enter Elements a: " << i + 1 << j + 1 << ": ";
			cin >> a[i][j];
		}
	}

	cout << endl;


	cout << "Enter Elements of Matrix 2: " << endl;
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			cout << "Enter Elements a: " << i + 1 << j + 1 << ": ";
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			for (int k = 0; k < c1; k++) {
				mult[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {	
			cout << mult[i][j] << " ";
			if(j == c2-1)
				cout << endl;
		}
	}
	return 0;
}
