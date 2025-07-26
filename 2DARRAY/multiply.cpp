#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of rows for the first matrix: ";
    cin >> m;
    cout << "Enter the number of columns for the first matrix: ";
    cin >> n;

    int arr[m][n];
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int p, q;
    cout << "Enter the number of rows for the second matrix: ";
    cin >> p;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> q;

    if (n != p) {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    int brr[p][q];
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> brr[i][j];
        }
    }

    int c[m][q] = {0};  // Initialize the result matrix with zeros

    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {  // Note: loop till 'n' as arr[i][k] and brr[k][j]
                c[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
