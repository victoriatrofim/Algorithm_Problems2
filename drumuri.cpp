#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// Dijkstra's algorithm function to find the shortest paths from start
void dijkstra(int start, vector<long long>& d,
vector<vector<pair<int, int> > >& adj) {
    // Min-heap priority queue to store the min distance node
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                                        greater<pair<long long, int> > > pq;

    // Init the distance for start node with 0
    d[start] = 0;
    // Push start node in pq
    pq.push(make_pair(0, start));

    // Process priority queue until it's empty
    while (!pq.empty()) {
        // Get the node with the smallest distance
        pair<long long, int> top = pq.top();
        long long current_d = top.first;
        int current_node = top.second;
        pq.pop();

        // If current dist in greater than the one we already have, skip it
        if (current_d > d[current_node]) continue;

        // Iterate over neighbour nodes
        for (size_t i = 0; i < adj[current_node].size(); ++i) {
            pair<int, int> edge = adj[current_node][i];
            int neigh = edge.first;
            // calculate potential new dist
            long long newDistance = current_d + edge.second;

            // If shorter path to neighbour is found, update the distance
            if (newDistance < d[neigh]) {
                d[neigh] = newDistance;
                // Push it into the queue the new dist for neighbour
                pq.push(make_pair(newDistance, neigh));
            }
        }
    }
}

int main() {
    int n, m;
    // Constant that will be the maximum value
    const long long MAXIM = 1000000000000;

    // Open input/output files
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    // Read the number of nodes and edges
    fin >> n >> m;

    // Initialize adjacency lists for the graph and its reversed version
    vector<vector<pair<int, int> > > adj(n + 1);
    vector<vector<pair<int, int> > > adjRev(n + 1);

    // Read the edges and build the adjency lists
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adjRev[b].push_back(make_pair(a, c));
    }

    // Read nodes x, y, z
    int x, y, z;
    fin >> x >> y >> z;

    // Init distance vectors with MAXIM
    vector<long long> dFromX(n + 1, MAXIM);
    vector<long long> dFromY(n + 1, MAXIM);
    vector<long long> dToZ(n + 1, MAXIM);

    // Call Dijkstra's algorithm from x, y, and z
    dijkstra(x, dFromX, adj);
    dijkstra(y, dFromY, adj);
    dijkstra(z, dToZ, adjRev);

    // Calculate the minimum path cost
    long long shortestPath = MAXIM;
    for (int i = 1; i <= n; i++) {
        if (dFromX[i] != MAXIM && dFromY[i] != MAXIM && dToZ[i] != MAXIM) {
            shortestPath = min(shortestPath, dFromX[i] + dFromY[i] + dToZ[i]);
        }
    }

    fout << shortestPath;

    fin.close();
    fout.close();

    return 0;
}
