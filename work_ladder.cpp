#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class WordLadder {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> results;
        if (dict.find(endWord) == dict.end()) return results;

        unordered_map<string, vector<string>> graph;
        buildGraph(beginWord, endWord, dict, graph);

        vector<string> path = {beginWord};
        dfs(beginWord, endWord, graph, path, results);

        return results;
    }

private:
    void buildGraph(const string& beginWord, const string& endWord, unordered_set<string>& dict, unordered_map<string, vector<string>>& graph) {
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);

        bool found = false;
        while (!currentLevel.empty() && !found) {
            for (const string& word : currentLevel) {
                dict.erase(word);
            }

            unordered_set<string> nextLevel;
            for (const string& word : currentLevel) {
                string temp = word;
                for (size_t i = 0; i < temp.size(); ++i) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.find(temp) != dict.end()) {
                            graph[word].push_back(temp);
                            nextLevel.insert(temp);
                            if (temp == endWord) {
                                found = true;
                            }
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            currentLevel = move(nextLevel);
        }
    }

    void dfs(const string& current, const string& endWord, unordered_map<string, vector<string>>& graph, vector<string>& path, vector<vector<string>>& results) {
        if (current == endWord) {
            results.push_back(path);
            return;
        }

        for (const string& neighbor : graph[current]) {
            path.push_back(neighbor);
            dfs(neighbor, endWord, graph, path, results);
            path.pop_back();
        }
    }
};

int main() {
    string beginWord, endWord;
    int n;

    cout << "Enter the begin word: ";
    cin >> beginWord;
    cout << "Enter the end word: ";
    cin >> endWord;
    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    vector<string> wordList(n);
    cout << "Enter the words in the dictionary: \n";
    for (int i = 0; i < n; ++i) {
        cin >> wordList[i];
    }

    WordLadder solver;
    vector<vector<string>> results = solver.findLadders(beginWord, endWord, wordList);

    cout << "Shortest transformation sequences: \n";
    for (const auto& sequence : results) {
        for (const auto& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
