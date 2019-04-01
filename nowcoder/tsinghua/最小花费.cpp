//
// Created by guozhuoqiang on 2019-03-12.
//
#include <iostream>

using namespace std;
const int maxCL = 1000000000;
const int maxN = 100000000;
const int INF = 1<<30;

int L[4];
int C[4];
int A;
int B;
int N;
int S[maxN+1];
int dp[maxN+1];

int getCost(int dis){
    if (dis <= L[1]) return C[1];
    if (dis <= L[2]) return C[2];
    if (dis <= L[3]) return C[3];
    cerr << "error" <<endl;
    exit(-1);
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> L[1] >> L[2] >> L[3] >> C[1] >> C[2] >> C[3] >> A >> B >> N) {
        S[0] = S[1] = 0;
        for (int i = 2; i <= N; ++i) {
            cin >> S[i];
        }
        dp[A] = 0;
        for(int i = A+1;i<=B;i++){
            dp[i] = INF;
            for(int j = i - 1;j>=A && S[i] - S[j] <= L[3] ;j--){
                dp[i] = min(dp[i],dp[j] + getCost(S[i] - S[j]));
            }
        }
        cout << dp[B] <<endl;
    }
    return 0;
}

