/*
Question 1: Islands, Safe Zone & Heal Power

Problem:
A player is deployed on a map represented by an N x M grid. There are C islands numbered 1...C. 
Each island has Qi cells. Water cells are represented by 0. 
There is a safe zone that touches some islands. 
The player starts at a source coordinate (p, q) with initial heal power Z.

Every time he moves to a new cell, he loses heal power as:
If entering i-th cell, he loses i/2 (integer division).

If his heal power reaches 0 before reaching the safe zone, he dies.
If he can’t reach the safe zone, output how much more heal power he needs.

Input:
N M → size of map
C → number of islands
For each island: Qi followed by Qi (x, y) coordinates
S → size of safe zone
Next S lines → cells of safe zone
(p, q) → source cell
Z → initial heal power

Output:
If he survives, print remaining heal power.
If he dies, print: "Died <extra_power_needed>".
*/

#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y, cost;
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
    int N, M; cin >> N >> M;
    int C; cin >> C;

    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i=1;i<=C;i++) {
        int Qi; cin >> Qi;
        while(Qi--) {
            int x,y; cin >> x >> y;
            grid[x][y] = i; // mark island
        }
    }

    int S; cin >> S;
    vector<pair<int,int>> safe(S);
    for (int i=0;i<S;i++) cin >> safe[i].first >> safe[i].second;

    int sx, sy; cin >> sx >> sy;
    int Z; cin >> Z;

    queue<Cell> q;
    vector<vector<int>> dist(N, vector<int>(M, -1));
    q.push({sx, sy, 0});
    dist[sx][sy] = 0;

    while(!q.empty()){
        auto [x,y,c] = q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k], ny=y+dy[k];
            if(nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]!=0 && dist[nx][ny]==-1){
                dist[nx][ny]=c+1;
                q.push({nx,ny,c+1});
            }
        }
    }

    int ans=INT_MAX;
    for(auto [x,y]:safe){
        if(dist[x][y]!=-1) ans=min(ans, dist[x][y]);
    }

    if(ans==INT_MAX) {
        cout << "Died " << 0 << "\n"; 
        return 0;
    }

    int powerLost = 0;
    for(int i=1;i<=ans;i++) powerLost += i/2;

    if(Z > powerLost) cout << Z - powerLost << "\n";
    else cout << "Died " << powerLost - Z + 1 << "\n";

    return 0;
}
