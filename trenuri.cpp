#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Function for topological sorting of the graph
void topologicalSort(string node, unordered_map<string, bool> & visited,
unordered_map<string, vector<string> > & adj, stack<string> & myStack) {
    visited[node] = true;  // Mark the current node as visited

    // Iterate over all adjacent nodes
    for (int i = 0; i < adj[node].size(); i++) {
        string neigh = adj[node][i];

        // If adjacent node is not visited, call topologicalSort recursively
        if (!visited[neigh]) {
            topologicalSort(neigh, visited, adj, myStack);
        }
    }
    // Push current node to the stack after visiting all adjacent nodes
    myStack.push(node);
}

int main() {
    int n;  // Number of edges

    // Start and end nodes
    string startNode, endNode;

    // Adjacency list of the graph
    unordered_map<string, vector<string> > adj;

    // Dp table for storing the longest path
    unordered_map<string, int> dp;

    unordered_map<string, bool> visited;  // Map for visited nodes
    stack<string> myStack;      // Stack for topologically sorted nodes
    vector<string> cities;      // Vector for all cities(nodes)

    // Open input/ output file
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");

    fin >> startNode >> endNode;  // Read start and end nodes
    fin >> n;                     // Read number of edges

    for (int i = 0; i < n; i++) {
        string u, v;
        fin >> u >> v;        // Read edge (u, v)
        adj[u].push_back(v);  // Add connection to adj list

        // Add nodes to cities list
        cities.push_back(u);
        cities.push_back(v);
    }

    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        // init dp with -1, nodes are not visited yet
        dp[city] = -1;
        if (!visited[city]) {
            // Perform topological sort if the city is not visited
            topologicalSort(city, visited, adj, myStack);
        }
    }

    dp[startNode] = 0;  // Initialize the start node in DP table

    // Process nodes in topological order
    while (!myStack.empty()) {
        string node = myStack.top();
        myStack.pop();

        // If the node has already a value(it was visited)
        if (dp[node] != -1) {
            for (int i = 0; i < adj[node].size(); i++) {
                string neigh = adj[node][i];

                // Update the longest path to the neighbor node
                dp[neigh] = max(dp[neigh], dp[node] + 1);
            }
        }
    }
    // Increment the result for the end node
    dp[endNode]++;

    fout << dp[endNode];

    fin.close();
    fout.close();

    return 0;
}
