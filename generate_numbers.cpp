#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to generate numbers with a given sum
vector<int> generateNumbersWithSum(int totalSum, int numTerms) {
    vector<int> result(numTerms, 0);

    if (numTerms <= 0 || totalSum < 0) {
        cerr << "Invalid input: numTerms must be > 0 and totalSum must be >= 0." << endl;
        return result;
    }

    // Distribute the sum among terms evenly
    int baseValue = totalSum / numTerms;
    int remainder = totalSum % numTerms;

    // Fill the result array
    for (int i = 0; i < numTerms; ++i) {
        result[i] = baseValue;
    }

    // Distribute the remainder
    for (int i = 0; i < remainder; ++i) {
        result[i]++;
    }

    return result;
}

int main() {
    int totalSum, numTerms;

    // Input the total sum and the number of terms
    cout << "Enter the total sum: ";
    cin >> totalSum;
    cout << "Enter the number of terms: ";
    cin >> numTerms;

    // Generate the numbers
    vector<int> numbers = generateNumbersWithSum(totalSum, numTerms);

    // Output the result
    cout << "Numbers with the given sum: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
