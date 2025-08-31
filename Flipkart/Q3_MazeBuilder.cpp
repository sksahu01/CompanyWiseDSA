/*
Question 3: Maze Builder

Problem Statement:
We need to generate a maze from given instructions. 
The instructions are given as a string with moves:
F = move forward
R = turn right
L = turn left
B = turn back

We start entering the maze from the left side and also exit from the left side. 
The maze is represented with:
'A' = Accessible path
'W' = Wall

Given the instruction string, construct the maze programmatically.

Example:
Input: FFRFRBRFBFRBRFLF
Output: 
7 5
WWWWW
AAAWW
WWAWW
WAAAW
WWAWW
WWAWW
WWWWW
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    string moves;
    cin >> moves;

    // Directions: right, down, left, up
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // Track visited positions
    set<pair<int,int>> visited;
    int x = 0, y = 0; // starting point
    int dir = 0; // facing right

    visited.insert({x,y});

    for(char c : moves) {
        if(c == 'F') {
            x += dx[dir];
            y += dy[dir];
            visited.insert({x,y});
        }
        else if(c == 'R') dir = (dir + 1) % 4;
        else if(c == 'L') dir = (dir + 3) % 4;
        else if(c == 'B') dir = (dir + 2) % 4;
    }

    // Find bounds
    int minx=1e9, maxx=-1e9, miny=1e9, maxy=-1e9;
    for(auto [xx,yy] : visited) {
        minx = min(minx, xx);
        maxx = max(maxx, xx);
        miny = min(miny, yy);
        maxy = max(maxy, yy);
    }

    int rows = maxx - minx + 3; // +3 for border
    int cols = maxy - miny + 3;

    vector<vector<char>> maze(rows, vector<char>(cols,'W'));

    // Mark path as 'A'
    for(auto [xx,yy] : visited) {
        int r = xx - minx + 1;
        int c = yy - miny + 1;
        maze[r][c] = 'A';
    }

    cout << rows << " " << cols << "\n";
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) cout << maze[i][j];
        cout << "\n";
    }

    return 0;
}
