#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n = 14;

int min (int dist[n], int flag[n]){
    int min = INT_MAX/2, index;
    for (int i=0; i<n; i++){
        if (flag[i]==0 && dist[i]<min){
            min=i;
        }
    }
    return min;
}

void dijkstra (int graph[n][n], int src, int dest){

    int dist[n], flag[n], i;

    for (i=0; i<n; i++){
        dist[i]=INT_MAX/2;
        flag[i]=0;
    }
    dist[src]=0;

    for (i=0; i<n; i++){
        int u = min (dist, flag);

        flag[i]=1;
        for (int v=0; v<n; v++){
            if (flag[v]==0 && graph[u][v] && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u]+graph[u][v];
        }
    }
    for (i=0; i<n; i++){
        if (dist[i]==INT_MAX/2){
            dist[i]=2;
        }
    }
    printf ("Vertex  Distance\n");
    for (i=0; i<n; i++){
        // if (i==dest)
            printf ("%d \t %d\n", i, dist[i]);
    }
}

int main(){

    int src, dest;
    int graph[14][14] = {{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
                        {1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
                        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
                        {1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                    };
    
    printf("0: Ahmedabad\n1: Amritsar\n2: Bengaluru\n3: Chandigarh\n4: Chennai\n5: Delhi\n6: Hyderabad\n7: Jaipur\n8: Kochi\n9: Kolkata\n10: Mumbai\n11: Nagpur\n12: Pune\n13: Srinagar\n");
    printf ("\nEnter Departure:\n");
    scanf ("%d", &src);
    printf ("0: Ahmedabad\n1: Amritsar\n2: Bengaluru\n3: Chandigarh\n4: Chennai\n5: Delhi\n6: Hyderabad\n7: Jaipur\n8: Kochi\n9: Kolkata\n10: Mumbai\n11: Nagpur\n12: Pune\n13: Srinagar\n");
    printf ("\nEnter Arrival:\n");
    scanf ("%d", &dest);
    dijkstra (graph, src, dest);

    return 0;
}