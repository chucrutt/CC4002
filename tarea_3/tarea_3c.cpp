#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a, c, max;
    cin >> n >> x;
    vector<int> dp(n, 0);
    for (int i = 0; i <n; i++) {
        cin >> a;
        dp[i] = a;
    }

    // Caso Base
    if (dp.empty()) {
        c = 0;
    } else {
        c = 1;
    }
    max = 0;
    
    // DP
    for (int i = 1; i < n; i++) {


        if (dp[i] - dp[i - 1] <= x) {
            c++;
        } else {
            c = 1;
        }

        if (c > max) {
            max = c;
        }
    }

    if (c > max) {
        max = c;
    }

    cout << max << endl;
    return 0;
}