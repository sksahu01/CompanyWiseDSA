/*
===============================
 Problem 2: Game with Levels
===============================
You are given n levels in a game. Each level i gives some points a[i].
The rule is that you cannot play two consecutive levels.

Task:
Find the maximum points you can collect.

--------------------------------
Input:
n
a1 a2 a3 ... an

Output:
Maximum points

--------------------------------
Example:
Input:
5
3 2 5 10 7

Output:
15
Explanation:
Pick levels 1,3,5 = 3+5+7 = 15
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& levels) {
    int n = levels.size();
    if (n == 0) return 0;
    if (n == 1) return levels[0];

    int prev2 = levels[0];                    // dp[0]
    int prev1 = max(levels[0], levels[1]);    // dp[1]

    for (int i = 2; i < n; i++) {
        int curr = max(prev1, levels[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;
    vector<int> levels(n);
    for (int i = 0; i < n; i++) cin >> levels[i];

    cout << maxPoints(levels) << "\n";
    return 0;
}

//OR
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& levels) {
    int n = levels.size();
    if (n == 0) return 0;
    if (n == 1) return levels[0];

    vector<int> dp(n, 0);
    dp[0] = levels[0];
    dp[1] = max(levels[0], levels[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], levels[i] + dp[i-2]);
    }

    return dp[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> levels(n);
    for (int i = 0; i < n; i++) cin >> levels[i];

    cout << maxPoints(levels) << "\n";
    return 0;
}
