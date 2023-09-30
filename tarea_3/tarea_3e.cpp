#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    const int MIN = -1e9;
    cin >> n >> a >> b >> c;
    vector<int> l = {a, b, c};
    vector<int> dp(n + 1, MIN);
    // Caso Base
    dp[0] = 0;
    // DP
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - l[j] >= 0) {
                dp[i] = max(dp[i], dp[i - l[j]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}