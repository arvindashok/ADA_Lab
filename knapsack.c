#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int w, int n, int p[], int weights[]) {
    int v[n+1][w+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (weights[i - 1] > j) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weights[i - 1]] + p[i - 1]);
            }
        }
    }

    return v[n][w];
}

int main() {
    int weights[6], profit[6], n, i;
    int capacity = 5;

    printf ("Enter the number of items:\n");
    scanf ("%d", &n);

    printf ("Enter the weights and profit:\n");
    for (i=0; i<n; i++){
        scanf ("%d %d", &weights[i], &profit[i]);
    }

    int maxProfit = knapsack(capacity, n, profit, weights);

    printf("Maximum Profit: %d\n", maxProfit);

    return 0;
}
