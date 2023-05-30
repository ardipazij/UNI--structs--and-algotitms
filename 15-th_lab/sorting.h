#ifndef SORTING_H
#define SORTING_H
struct Node
{
  int data;
  struct Node *next;
};
void generalized_bucket_sort(int * arr, int n);
void print(int * arr, int narray);
int getBucketIndex(int value, int interval);
void genericBucketSort(int *numbers, int N);
void radix_sort(int * data, int n);
void bucket_sort(int * arr, int n, int command);
#endif