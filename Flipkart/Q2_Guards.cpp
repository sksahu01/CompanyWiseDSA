/*
Question 2: Guards, Bikes & Thief

Problem:
Apama owns a farm where a thief tries to steal medicinal plants.
The performance is calculated as:
performance = skill * bike_power

Thief has skill TS and bike power TP.
There are N guards and N bikes.
Each guard has skill array S[i].
Each bike has efficiency array P[i].

Apama needs to distribute bikes to guards such that all guards have performance > thief’s performance.

Input:
TS TP
N
N integers → guards’ skills
N integers → bikes’ powers

Output:
Number of possible distributions modulo 1000000007.
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long solve(int TS, int TP, int N, vector<int>& S, vector<int>& P) {
    long long thiefPerf = 1LL * TS * TP;
    long long ways = 0;

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    do {
        bool ok = true;
        for(int i=0;i<N;i++){
            long long perf = 1LL*S[i]*P[idx[i]];
            if(perf <= thiefPerf) { ok = false; break; }
        }
        if(ok) ways = (ways+1)%MOD;
    } while(next_permutation(idx.begin(), idx.end()));

    return ways;
}

int main(){
    int TS,TP; cin>>TS>>TP;
    int N; cin>>N;
    vector<int> S(N), P(N);
    for(int i=0;i<N;i++) cin>>S[i];
    for(int i=0;i<N;i++) cin>>P[i];
    cout << solve(TS,TP,N,S,P) << "\n";
}
