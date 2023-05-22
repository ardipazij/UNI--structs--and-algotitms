#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int get_number_of_digits (int number){
    int i = 1;
    while(number >= pow(10, i))
    {
        i = i+1;
    }
    return i;
}

int get_digit (int number, int i){
    return number % ((pow(10, i+1))/pow(10, i));
}

int max_number_of_digits(int * data, int n){
    int number_of_digits = 1;
    for(int i = 0; i < n; i ++){
        int current = get_number_of_digits(data[i]);
        if(current > number_of_digits){
            number_of_digits = current;
        }
    }
    return number_of_digits;
}

void radix_sort(int * data, int n){
   int number_of_digits = max_number_of_digits(data, n);
}