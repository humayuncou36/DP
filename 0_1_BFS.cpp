#include <bits/stdc++.h>
using namespace std;

// Method to implement 0-1 BFS Algorithm
void bfs_01(vector<vector<pair<int, int> > >& graph,
            vector<int>& dist, int vertex_source)
{
    // Initializing the distance of vertex_source node
    // from itself as 0
    dist[vertex_source] = 0;
    deque<int> dq;
    dq.push_front(vertex_source);
    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        // Checking all the neighbors for relaxation
        for (auto edge : graph[node]) {
            int childNode = edge.first;
            int weight = edge.second;

            // If the neighbor can be relaxed
            if (dist[childNode] > dist[node] + weight) {
                dist[childNode] = dist[node] + weight;

                // If the edge weight is 1,
                  // push it at the back of deque
                if (weight)
                    dq.push_back(childNode);

                // If the edge weight is 0,
                  // push it at the front of deque
                else
                    dq.push_front(childNode);
            }
        }
    }
}

int main()
{
    // Inputs
    int V = 6, E = 7, vertex_source = 0;
    vector<vector<pair<int, int> > > graph(V);
    vector<vector<int> > edges{ { 0, 1, 1 }, { 1, 2, 1 },
                                { 2, 3, 1 }, { 3, 4, 1 },
                                { 4, 5, 0 }, { 5, 0, 0 },
                                { 1, 4, 1 } };
    // Representing the graph as adjacent list
    for (auto edge : edges) {
        graph[edge[0]].push_back({ edge[1], edge[2] });
        graph[edge[1]].push_back({ edge[0], edge[2] });
    }
    // dist array to store distance of all nodes
    // from vertex_source node
    vector<int> dist(V, 1e9);
    bfs_01(graph, dist, vertex_source);
    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    return 0;
}

