#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }

    int findParent(vector<int> &parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int u, int v) {
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), compareEdges);
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0;
        cout << "Edges in MST:" << endl;
        for (Edge &edge : edges) {
            int rootU = findParent(parent, edge.u);
            int rootV = findParent(parent, edge.v);

            if (rootU != rootV) {
                cout << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
                mstWeight += edge.weight;
                unionSets(parent, rank, rootU, rootV);
            }
        }

        cout << "Total Weight of MST: " << mstWeight << endl;
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

    g.kruskalMST();
    return 0;
}
