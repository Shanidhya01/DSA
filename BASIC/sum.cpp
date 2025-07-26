#include <iostream>
using namespace std;

int main() {
    int first_number, second_number, sum;

    cout << "Enter two integers: ";
    cin >> first_number >> second_number;

    // Calculate the sum of the two numbers
    sum = first_number + second_number;

    // Display the result
    cout << first_number << " + " << second_number << " = " << sum;

    return 0;
}
