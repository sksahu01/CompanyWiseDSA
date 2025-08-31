/*
==========================================
 Problem 3: Pirates and the Mystery Islands
==========================================
There are N islands. Each island i has some amount of treasure.
There are M directed routes between islands, where each route u->v
has a travel cost w.

Pirates start at an island s and must reach island e.
- When they visit an island, they collect its treasure.
- When they travel on a route, they must pay its cost.

Task:
Find a path from s to e that maximizes the profit
(treasure collected - travel cost).
Output the total treasure, total cost, and the actual path.

--------------------------------
Input:
N M K
t1 t2 t3 ... tN
u1 v1 w1
u2 v2 w2
...
uM vM wM
s1 e1
s2 e2
...
sK eK

Output:
For each query:
<total_treasure> <total_cost>
<path_of_islands>

If no path exists: "No Path"

--------------------------------
Example:
Input:
5 6 1
10 20 30 40 50
1 2 5
1 3 10
2 4 10
3 4 5
4 5 1
2 5 2
1 5

Output:
130 16
1->3->4->5
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> treasure(N+1);
    for (int i = 1; i <= N; i++) cin >> treasure[i];

    vector<vector<Edge>> adj(N+1);
    vector<int> indeg(N+1, 0);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        indeg[v]++;
    }

    // Topological sort (assume DAG)
    queue<int> q;
    for (int i = 1; i <= N; i++) if (indeg[i]==0) q.push(i);

    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto &edge: adj[u]){
            indeg[edge.v]--;
            if(indeg[edge.v]==0) q.push(edge.v);
        }
    }

    while (K--) {
        int s, e;
        cin >> s >> e;

        vector<long long> bestTreasure(N+1, LLONG_MIN);
        vector<long long> totalTreasure(N+1, 0);
        vector<long long> totalCost(N+1, 0);
        vector<int> parent(N+1, -1);

        bestTreasure[s] = treasure[s];
        totalTreasure[s] = treasure[s];
        totalCost[s] = 0;

        for (int u : topo) {
            if (bestTreasure[u] == LLONG_MIN) continue;
            for (auto &edge : adj[u]) {
                long long candidate = bestTreasure[u] + treasure[edge.v] - edge.w;
                if (candidate > bestTreasure[edge.v]) {
                    bestTreasure[edge.v] = candidate;
                    totalTreasure[edge.v] = totalTreasure[u] + treasure[edge.v];
                    totalCost[edge.v] = totalCost[u] + edge.w;
                    parent[edge.v] = u;
                }
            }
        }

        if (bestTreasure[e] == LLONG_MIN) {
            cout << "No Path\n";
        } else {
            cout << totalTreasure[e] << " " << totalCost[e] << "\n";
            vector<int> path;
            for (int v = e; v != -1; v = parent[v]) path.push_back(v);
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                cout << path[i];
                if (i + 1 < path.size()) cout << "->";
            }
            cout << "\n";
        }
    }
}
