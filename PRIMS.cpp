#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 1e9

typedef pair<int, int> Edge;

class Graph {
public:
    int V;
    vector<vector<Edge>> adjList;

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({weight, v});
        adjList[v].push_back({weight, u});
    }

    void primMST() {
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        vector<bool> inMST(V, false);
        vector<int> key(V, INF);
        int start = 0;
        pq.push({0, start});
        key[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &[weight, v] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "Minimum Spanning Tree weights: ";
        for (int weight : key) {
            cout << weight << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();
    return 0;
}
