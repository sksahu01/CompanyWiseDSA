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
Output: (A/W maze grid)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string instr;
    cin >> instr;

    map<pair<int,int>, char> maze;
    int x = 0, y = 0;
    maze[{x,y}] = 'A';

    // Directions: 0=up,1=right,2=down,3=left
    int dir = 1; // start facing right
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    for (char c : instr) {
        if (c == 'R') dir = (dir + 1) % 4;
        else if (c == 'L') dir = (dir + 3) % 4;
        else if (c == 'B') dir = (dir + 2) % 4;
        else if (c == 'F') {
            x += dx[dir];
            y += dy[dir];
            maze[{x,y}] = 'A';
        }
    }

    int minX=INT_MAX,maxX=INT_MIN,minY=INT_MAX,maxY=INT_MIN;
    for (auto &p : maze) {
        minX = min(minX, p.first.first);
        maxX = max(maxX, p.first.first);
        minY = min(minY, p.first.second);
        maxY = max(maxY, p.first.second);
    }

    for (int i=minX-1;i<=maxX+1;i++) {
        for (int j=minY-1;j<=maxY+1;j++) {
            if (maze.count({i,j})) cout << 'A';
            else cout << 'W';
        }
        cout << "\n";
    }
    return 0;
}
