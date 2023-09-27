#include <bits/stdc++.h>
using namespace std;

int main(){
    // Tamaño del laberinto
    int n;
    cin >> n;
    // Inicializar el laberinto
    vector<vector<pair<int,bool>>> dp(n, vector<pair<int,bool>> (n, make_pair(0, false)));
    // vector<vector<int>> dp(n, vector<int>(n, 0));
    string s;
    for (int i=0; i<n-1; i++) {
        cin >> s;
        for (int j=0; j<n-1; j++) {
            if (s[j] == '*') {
                dp[i][j] = make_pair(0, true);
            }
        }
    }
    return 0;
}