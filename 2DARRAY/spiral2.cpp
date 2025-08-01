// leetcode 54
#include<iostream>
using namespace std;
int main(){
    int m, n;
    cout << "Enter the number of rows for the matrix: ";
    cin >> m;
    cout << "Enter the number of columns for the matrix: ";
    cin >> n;
    int arr[m][n];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int tne = n * m;
    int count = 0;
    int minr = 0;
    int minc = 0;
    int maxc = n - 1;
    int maxr = m - 1;
    while (minr <= maxr && minc <= maxc)
    {
        // Right
        for (int j = minc; j <= maxc && count < tne; j++)
        {
            cout << arr[minr][j] << " ";
            count++;
        }
        minr++;
        // Down
        for (int i = minr; i <= maxr && count < tne; i++)
        {
            cout << arr[i][maxc] << " ";
            count++;
        }
        maxc--;
        // Left
        for (int j = maxc; j >= minc && count < tne; j--)
        {
            cout << arr[maxr][j] << " ";
            count++;
        }
        maxr--;
        // up
        for (int i = maxr; i >= minr && count < tne; i--)
        {
            cout << arr[i][minc] << " ";
            count++;
        }
        minc++;
    }
    return 0;
}