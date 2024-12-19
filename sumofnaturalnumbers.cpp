#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    // Using the formula for the sum of the first n natural numbers
    int sum = n * (n + 1) / 2;

    cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;

    return 0;
}
