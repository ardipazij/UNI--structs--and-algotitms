#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void buble_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++ ){
            comparisons++;
            if(items[j] > items[j+1]){
                assigments+= 3;
                int n = items[j];
                items[j] = items[j+1];
                items[j+1] = n;
            }
        }
    }
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
    }
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}