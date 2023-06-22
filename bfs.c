#include<stdio.h>
#include<stdlib.h>

int a[10][20], q[10], visited[10], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for(i = 0; i < n; i++){
        if(a[v][i] && visited[i]==0){
            q[++r] = i;
        }
    }
    if(f <= r){
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

int main() {
    int v;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    
    for(i=1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    
    printf("\nEnter graph data in matrix form:\n");
    for(i=0; i<n; i++) {
        for(j=0;j<n;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter the starting vertex:");
    scanf("%d", &v);
    bfs(v);
    printf("\nThe node which are reachable are:\n");
    
    for(i=0; i < n; i++) {
        if(visited[i])
            printf("%d\t", i);
        else {
            printf("\nBfs is not possible. Not all nodes are reachable");
            break;
        }
    }
    return 0;
}