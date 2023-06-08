#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void linear_probe(int nums[SIZE], int key){
    
    int i, temp;
    i = key%SIZE;
    if (nums [i]==0){
        nums [i] = key;
    }
    else{
        temp=i;
        while (nums[temp]!=0){
            temp = (temp+1)%SIZE;
            if (temp==i) break;
        }
        if (nums [temp]==0){
            nums [temp] = key;
        }
        else{
            printf ("Too many collisions for %d\n", key);
        }
    } 
}

void quad_probe(int nums[SIZE], int key){
    
    int i, temp;
    i = key%SIZE;
    if (nums [i]==0){
        nums [i] = key;
    }
    else{
        temp=i;
        for(int j=0; j<SIZE; j++){
            temp = (temp+(j*j))%SIZE;
            if (temp==i) break;
            if (nums[temp]==0) break;
        }
        if (nums [temp]==0){
            nums [temp] = key;
        }
        else{
            printf ("Too many collisions for %d . Therefore replacing old element with new element.\n", key);
        }
        nums[i]=key;
    } 
}

void double_hash (int nums[SIZE], int key){
    int i, temp;
    i = key%SIZE;
    if (nums [i]==0){
        nums [i] = key;
    }
    else{
        temp=i;
        for(int j=0; j<SIZE; j++){
            temp = (i+j*i)%SIZE;
            if (temp==i) break;
            if (nums[temp]==0) break;
        }
        if (nums [temp]==0){
            nums [temp] = key;
        }
        else{
            printf ("Too many collisions for %d . Therefore replacing old element with new element.\n", key);
        }
        nums[i]=key;
    } 
}

int main(){
    
    int arr[SIZE];
    for (int i=0; i<SIZE; i++){
        arr[i]=0;
    }
    linear_probe(arr, 1);
    linear_probe(arr, 11);
    linear_probe(arr, 7);
    linear_probe(arr, 17);
    quad_probe (arr, 6);
    quad_probe (arr, 16);
    double_hash (arr, 9);
    double_hash (arr, 19);
    linear_probe(arr, 21);

    for (int i=0; i<SIZE; i++){
        printf ("%d  ", arr[i]);
    }
}