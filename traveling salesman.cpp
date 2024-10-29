#include <iostream>
#include <vector>
#include <cstring> 
#include <limits.h>
using namespace std;

const int MAX = 20;
const int INF = INT_MAX;

int n;
int dist[MAX][MAX];
int dp[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the distance matrix (use 0 for no path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] == 0) dist[i][j] = INF;
        }
    }

    memset(dp, -1, sizeof(dp));
    int minCost = tsp(1, 0); 
    cout << "Minimum cost of traveling salesman problem: " << minCost << endl;

    return 0;
}
b0 
