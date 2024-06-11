#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

#define MOD 1000000007

using namespace std;

int main() {
    // Declare variables to store number of nodes and edges
    int n, m;

    // Open input/output file
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    // Read the number of nodes and edges from the input file
    fin >> n >> m;

    // Initialize DP array to store the number of paths to each node
    vector<int> dp(n + 1, 0);

    // Initialize adjacency list for the first & second graph
    vector<vector<int>> adj1(n + 1);
    vector<unordered_set<int>> adj2(n + 1);

    // Initialize common graph adjacency list
    vector<vector<int>> commonGraph(n + 1);

    // Read edges for the first graph and build the adjacency list
    for (int i = 0; i < m; i++) {
        // Declare variables to store the edge
        int x1, y1;
        fin >> x1 >> y1;
        // Add the edge to the adjacency list of the first graph
        adj1[x1].push_back(y1);
    }

    // Read edges for the second graph and build the adjacency set
    for (int i = 0; i < m; i++) {
        // Declare variables to store the edge
        int x2, y2;
        fin >> x2 >> y2;
        // Add the edge to the adjacency set of the second graph
        adj2[x2].insert(y2);
    }

    // Construct the common graph by finding common edges in both graphs
    for (int i = 1; i <= n; i++) {
        // Iterate over neighbors of node i in the first graph
        for (int neighbor : adj1[i]) {
            // Check if the neighbor exists in the second graph
            if (adj2[i].find(neighbor) != adj2[i].end()) {
                // Add the neighbor to the common graph
                commonGraph[i].push_back(neighbor);
            }
        }
    }

    // Initialize the dp for start point with 1
    dp[1] = 1;

    // Compute the number of paths for each node in topological order
    for (int node = 1; node <= n; node++) {
        // Iterate over neighbors of the current node in the common graph
        for (int neighbor : commonGraph[node]) {
            // Update the number of paths to the neighbor node
            dp[neighbor] = (dp[neighbor] + dp[node]) % MOD;
        }
    }

    // Output the common number of chains
    fout << dp[n];

    // Close the input/output file
    fin.close();
    fout.close();

    return 0;
}
