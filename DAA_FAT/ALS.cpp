//Assembly Line Scheduling

#include <iostream>
using namespace std;

int assemblyLineScheduling(int a[][2], int t[][2], int e[], int x[], int n) {
    int dp[2][n];
    
    dp[0][0] = e[0] + a[0][0];
    dp[1][0] = e[1] + a[0][1];
    
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[0][i-1] + a[i][0], dp[1][i-1] + t[i-1][1] + a[i][0]);
        dp[1][i] = min(dp[1][i-1] + a[i][1], dp[0][i-1] + t[i-1][0] + a[i][1]);
    }
    
    return min(dp[0][n-1] + x[0], dp[1][n-1] + x[1]);
}

int main() {
    int a[][2] = {{4, 5}, {2, 10}, {3, 1}, {4, 3}}; 
    int t[][2] = {{3, 7}, {2, 2}, {4, 5}}; 
    int e[] = {2, 4}; 
    int x[] = {3, 6}; 
    int n = 4; 
    
    cout << "Minimum time taken: " << assemblyLineScheduling(a, t, e, x, n) << endl;
    
    return 0;
}
