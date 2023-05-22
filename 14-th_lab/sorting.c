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
      //  assigments++;
        for(int j = i + 1; j < n - 1; j++){
            comparisons++;
            if(temp_array[position] > temp_array[j]){
                position=j;
               // assigments++;
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

void insert_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n"); 

    int element, j; 
    for (int i = 1; i < n; i++) { 
        assigments++;
        element = temp_array[i];
        j = i - 1;
        comparisons++;
        while (j >= 0 && temp_array[j] > element) { 
            temp_array[j + 1] = temp_array[j];
            j = j - 1;
            comparisons++;
            assigments++;
        }
        comparisons++;
        if(temp_array[j+1] != element){
           temp_array[j + 1] = element; 
            assigments++;
        }
    } 

    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void heapify(int * items, int n, int i, long long int * comparions, long long int * assigments){
    int largest = i;
    int left = 2* i + 1;
    int right = 2 * i + 2;
    (*comparions)++;
    if(left < n && items[left] > items[largest]){
        largest = left;
    }
    (*comparions)++;
    if(right < n && items[right] > items[largest]){
        largest = right;
    }
   // (*comparions)++;
    if(largest != i){
        swap(&items[i], &items[largest]);
        (*assigments)+=3;
        heapify(items, n, largest, comparions, assigments);
    }
}
void heap_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n"); 

    for(int i = n - 1; i >= 0; --i){
        heapify(temp_array, n, i, &comparisons, &assigments);
    }
    for(int i = n - 1; i>= 0; --i){
        swap(&temp_array[0], &temp_array[i]);
        assigments+=3;
        heapify(temp_array, i, 0, &comparisons, &assigments);
    }
    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}

void quick_sort(int * array, int left, int right, long long int * comparisons, long long int * assigments){
    int  i = left;
    int j = right;
    int temp;
    int pivot = array[(left + right) / 2];
    while( i <= j){
        while(array[i] < pivot){
            i++;
            (*comparisons)++;
        }
        while(array[j] > pivot){
            j--;
            (*comparisons)++;
        }
        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            (*assigments)+=3;
            i++;
            j--;
        }
    }
    if(left < j){
        quick_sort(array, left, j, comparisons, assigments);
    }
    if (i < right){
        quick_sort(array, i, right, comparisons, assigments);
    }
}
// int partition(int * array, int low, int high, long long int * compariosns, long long int * assigments) {
//   int pivot = array[high];
//   int i = (low - 1);
//   for (int j = low; j < high; j++) {
//     (*compariosns)++;
//     if (array[j] <= pivot) {
//       i++;
//       swap(&array[i], &array[j]);
//       (*assigments)+=3;
//     }
//   }
//   swap(&array[i + 1], &array[high]);
//   (*assigments)+=3;
//   return (i + 1);
// }

// void quick_sort(int * array, int low, int high, long long int * comparisons, long long int * assigments) {
//     if (low < high) {
//         int pi = partition(array, low, high, comparisons, assigments);
//         quick_sort(array, low, pi - 1, comparisons, assigments);
//         quick_sort(array, pi + 1, high, comparisons, assigments);
//   }
// }

void shell_sort(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n"); 
    for(int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++) { 
            assigments++;
            int element = temp_array[i];
            int j;
        comparisons++;
       for(j = i; j >= gap && temp_array[j - gap] > element; j -= gap) { 
            temp_array[j] = temp_array[j - gap];
            comparisons++;
            assigments++;
        }
        // comparisons++;
        // if(temp_array[j] != element){
        //     temp_array[j] = element;
        //     assigments++;
        // }

        temp_array[j] = element;
        assigments++;
        
        }
    }

    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}

void shell_sort_mod(int * items, int n){
    long long int comparisons = 0;
    long long int assigments = 0;
    int * temp_array = calloc(n, sizeof(int));
    for(int k = 0; k < n; k++){
        printf("%d ", items[k]);
        temp_array[k] = items[k];
    }
    printf("\n"); 
    for (int i = n / 2; i > 0; i /= 2) {
        for (int k = i; k < n; ++k) {
            comparisons++;
            for (int j = k - i; j >= 0  && (temp_array[j] > temp_array[j + i]); j -= i) {
                comparisons++;
                swap(&temp_array[j], &temp_array[j + i]);
                assigments+=3;
            }
        }
    }

    for(int k = 0; k < n; k++){
        printf("%d ", temp_array[k]);
    }
    free(temp_array);
    printf("\n %lld -- число сравнений \n %lld -- число перестановок\n", comparisons, assigments);
}