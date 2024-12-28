#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(1, n, k, combination, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; ++i) {
            combination.push_back(i);
            backtrack(i + 1, n, k, combination, result);
            combination.pop_back(); // Backtrack
        }
    }
};

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    vector<vector<int>> combinations = solution.combine(n, k);

    cout << "All possible combinations: \n";
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
