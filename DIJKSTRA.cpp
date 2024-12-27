#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

define INF 1e9

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
    }

    void dijkstra(int start) {
        vector<int> dist(V, INF);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &[weight, v] : adjList[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    g.dijkstra(0);
    return 0;
}
