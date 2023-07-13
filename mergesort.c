#include <stdio.h>
#include <stdlib.h>

int res[10], n;
void SortedMerge(int arr[], int l, int m, int h) {
    int i=l, j=m+1, k=0;

    while (i<=m && j<=h){
        if (arr[i]<arr[j]){
            res[k]=arr[i];
            i++;
        }
        else{
            res[k]=arr[j];
            j++;
        }
        k++;
    }
    while (i<=m){
        res[k++]=arr[i++];
    }
    while (j<=h){
        res[k]=arr[j];
        k++;
        j++;
    }
    for (int i=0; i<(h-l)+1; i++) {
        arr[l+i]=res[i];
    }
}
void Merge(int arr[], int l, int h){
    if (l<h){
        int m = (l+h)/2;
        Merge(arr, l, m);
        Merge(arr, m+1, h);
        SortedMerge(arr, l, m , h);   
    }
}

int main(){
    int a[10],i;
    printf ("Enter size of array:\n");
    scanf("%d",&n);
    printf ("Enter elements:\n");
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    Merge(a,0,n-1);

    for (i=0; i<n; i++){
        printf ("%d  ",a[i]);
    }
    return 0;
}