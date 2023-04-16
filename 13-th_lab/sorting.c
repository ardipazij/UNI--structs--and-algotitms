#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void buble_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++ ){
            comparisons++;
            if(temp_array[j] > temp_array[j+1]){
                assigments+= 3;
                int n = temp_array[j];
                temp_array[j] = temp_array[j+1];
                temp_array[j+1] = n;
            }
        }
    }
    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}

void selection_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n"); 

    for(int i = 0; i < n - 1; i++) {
        int position = i;
        for(int j = i + 1; j < n; j++){
            comparisons++;
            if(temp_array[position] > temp_array[j]){
                position=j;
                assigments++;
            }
        }
        comparisons++;
        if(position != i){
            assigments+=3;
            int swap=temp_array[i];
            temp_array[i]=temp_array[position];
            temp_array[position]=swap;
        }
    }
    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}