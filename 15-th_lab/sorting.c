#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print_vector(int * data, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}
// int get_number_of_digits (int number){
//     int i = 1;
//     while(number >= pow(10, i))
//     {
//         i = i+1;
//     }
//     return i;
// }

// int get_digit (int number, int i){
//    // return number % ((pow(10, i+1))/pow(10, i));
// }

// int max_number_of_digits(int * data, int n){
//     int number_of_digits = 1;
//     for(int i = 0; i < n; i ++){
//         int current = get_number_of_digits(data[i]);
//         if(current > number_of_digits){
//             number_of_digits = current;
//         }
//     }
//     return number_of_digits;
// }
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void couting_sort_for_radix(int ** numbers, int size, int digit){
    int output[size + 1];
    int max = (*numbers[0] / digit) % 10;

  for (int i = 1; i < size; i++) {
   // printf("%d\n", (*numbers)[i]);
    if ((((*numbers)[i] / digit) % 10) > max)
      max = (*numbers)[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[((*numbers)[i] / digit) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[((*numbers)[i] / digit) % 10] - 1] = (*numbers)[i];
    count[((*numbers)[i] / digit) % 10]--;
  }

  for (int i = 0; i < size; i++)
    (*numbers)[i] = output[i];
}
void radix_sort(int * data, int n){
    printf("Befort sorting\n");
    print_vector(data, n);
    int max = getMax(data, n);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    couting_sort_for_radix(&data, n, place);
//    int number_of_digits = max_number_of_digits(data, n);
//    for(int i = 1; i <= number_of_digits; i++){
//     coutintg_sort_for_radix(&data, n, i);
//    }
   printf("After sorting\n");
    print_vector(data, n);
}