/*
===============================
 Problem 1: Thief in Town
===============================
A thief is robbing n streets, where each street has some number of houses.
He robs at a constant rate of K houses per hour. Robbing one street with
`a[i]` houses takes ceil(a[i]/K) hours.

You are given:
- n : number of streets
- a[i] : number of houses in each street
- H : total hours available

Task:
Find the minimum integer K such that the thief can finish robbing all houses
within H hours.

--------------------------------
Input:
n H
a1 a2 a3 ... an

Output:
Minimum rate K

--------------------------------
Example:
Input:
5 6
30 11 23 4 20

Output:
23
--------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

long long requiredHours(const vector<int>& a, long long k) {
    long long hours = 0;
    for (int x : a) {
        hours += (x + k - 1) / k; // ceil division
    }
    return hours;
}

int minRate(vector<int>& a, long long H) {
    int lo = 1, hi = *max_element(a.begin(), a.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (requiredHours(a, mid) <= H) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    int n; long long H;
    cin >> n >> H;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << minRate(a, H) << "\n";
    return 0;
}
