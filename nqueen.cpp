#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int count;

    // Helper function to check if placing a queen is valid
    bool isValid(vector<int>& positions, int row, int col) {
        for (int i = 0; i < row; ++i) {
            int prevCol = positions[i];
            if (prevCol == col || abs(prevCol - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    // Recursive backtracking to find solutions
    void solve(int n, int row, vector<int>& positions) {
        if (row == n) {
            ++count;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(positions, row, col)) {
                positions[row] = col;
                solve(n, row + 1, positions);
                positions[row] = -1; // Backtrack
            }
        }
    }

public:
    NQueens() : count(0) {}

    int totalNQueens(int n) {
        vector<int> positions(n, -1); // Tracks queen positions per row
        solve(n, 0, positions);
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    NQueens solver;
    int result = solver.totalNQueens(n);

    cout << "Number of distinct solutions: " << result << endl;

    return 0;
}
