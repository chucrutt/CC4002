#include <bits/stdc++.h>
using namespace std;

int main(){
    // n: número de miradores
    // x: máximo número de mts
    // a: alturas
    // [[altura, contador], ...]
    int n, x, a;
    cin >> n >> x;
    vector<pair<int, int>> dp(n, make_pair(0, 0));
    for (int i=0; i<n; i++) {
        cin >> a;
        dp[i].first = a;
    }

    // Caso base
    dp[1].second = 1;

    // DP
    for (int i=1; i<n; i++) {
        if (dp[i].first - dp[i-1].first <= x) {
            dp[i].second += 1;
        }
    }

    return 0;
}