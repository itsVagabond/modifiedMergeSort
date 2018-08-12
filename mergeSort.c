/*
    Merge Sort for N no. of numbers (Divide and Conquer)
*/

#include <stdio.h>
#include <stdlib.h>
#define UINT_MAX 0xFFFFU/0xFFFFFFFFUL

void input_array(int *arr, int num){
    int i;

    for(i = 0; i < num; i++){
        printf("Enter Number[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void divide(int *arr, int num, int *left, int *right){
    int i, j, k;

    for(i = 0, j = 0, k = 0; i < num; i++){
        if(i < num/2){
            left[j++] = arr[i];
        }else{
            right[k++] = arr[i];
        }
    }

    left[j] = right[k] = UINT_MAX;
}

void insertion_sort(int *arr, int size){
    int i, j, k, key, pos;

    for(i = 1; i < size; ++i){
        key = arr[i];           //Pick

        for(j = i-1; j > -1 && arr[i] < arr[j]; --j);
        pos = j+1;              //Search Position

        for(k = i; k > pos; --k){
            arr[k] = arr[k-1];   //Shift
        }

        arr[pos] = key;         //Insert
    }
}

void combine(int *arr, int i, int num, int *rem, int counter){
    for(; i < num;){
        arr[i] = rem[counter];
    }
}

void conquer(int *arr, int num, int *left, int *right){
    int i, j, k;

    for(i = 0, j = 0, k = 0; left[j] != UINT_MAX && right[k] != UINT_MAX;){
        if(left[j] > right[k]){
            arr[i++] = right[k++];
        }else{
            arr[i++] = left[j++];
        }
    }

    if(j == 4){
        combine(arr, i, num, right, k);
    }else{
        combine(arr, i, num, left, j);
    }
}

void merge_sort(int *arr, int num){
    int size = (num/2) + 1;
    int left[size], right[size];

    divide(arr, num, left, right);

    insertion_sort(left, size-1);
    insertion_sort(right, size-1);

    conquer(arr, num, left, right);
}

void output_array(int *arr, int num){
    int i;

    printf("\nSorted : \n");

    for(i = 0; i < num; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void main(){
    int *arr, num;

    printf("\nEnter No. Of Nos. To be Sorted : ");
    scanf("%d", &num);

    arr = (int *) malloc(num * sizeof(int));

    input_array(arr, num);

    merge_sort(arr, num);

    output_array(arr, num);

    free(arr);
}