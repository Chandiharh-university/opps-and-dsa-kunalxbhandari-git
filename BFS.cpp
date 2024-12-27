#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjList;

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS starting from node 0: ";
    g.BFS(0);
    return 0;
}
