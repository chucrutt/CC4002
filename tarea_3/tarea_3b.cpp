#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    const long long MOD = 1000000007;
    cin >> n;
    vector<vector<pair<long long,bool>>> dp(n, vector<pair<long long,bool>> (n, make_pair(0, false)));
    string s;

    // Marcas Bomba
    for (long long i=0; i<n; i++) {
        cin >> s;
        for (long long j=0; j<n; j++) {
            if (s[j] == '*') {
                dp[i][j].second = true;
            }
        }
    }

    // Caso Base
    if (dp[0][0].second == false) {
        dp[0][0].first = 1;
    }
    for (long long i=1; i<n; i++) {
        if (dp[i][0].second == false){
            dp[i][0].first += dp[i-1][0].first;;
        }
    }
    for (long long j=1; j<n; j++) {
        if (dp[0][j].second == false){
            dp[0][j].first += dp[0][j-1].first;
        }
    }

    // DP
    for (long long i=1; i<n; i++) {
        for (long long j=1; j<n; j++) {
            if (dp[i][j].second == false){
                dp[i][j].first = (dp[i-1][j].first + dp[i][j-1].first) % MOD;
            }
        }
    }

    // ! Peor Caso dp[n-1][n-1] == 2874513998398909184
    cout << dp[n-1][n-1].first % MOD << endl;

    return 0;
}