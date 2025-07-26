#include <iostream>
using namespace std;

int main() {
    int a, b, temp;

    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    // Swap using a temporary variable
    temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swapping:\n";
    cout << "First number (a) = " << a << endl;
    cout << "Second number (b) = " << b << endl;

    return 0;
}
