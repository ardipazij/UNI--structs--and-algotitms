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
int get_max(int array[], int n) {
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
    printf("Before sorting\n");
    print_vector(data, n);
    int max = get_max(data, n);
  for (int place = 1; max / place > 0; place *= 10)
    couting_sort_for_radix(&data, n, place);
   printf("After sorting\n");
    print_vector(data, n);
}

void bucket_sort(int * arr, int n, int command) {
  printf("Before sorting\n");
  print_vector(arr, n);
	if (command == 0) {
		for (int i = 0 ; i < n; i++)
		{
			while (arr[i] != i)
			{
				int temp = arr[arr[i]] ;
				arr[arr[i]] = arr[i];
				arr[i] = temp;
			}
		}
	}
	else if (command == 1) {
		int * b = calloc(n, sizeof(int));
		for (int i = 0 ; i < n; i++) {
			b[arr[i]] = arr[i];	
		}
		arr = b;
	}
  printf("After sorting\n");
  print_vector(arr, n);
}

// void generalized_bucket_sort(int * arr, int narray) {
//   printf("Before sorting\n");
//   print(arr, narray);
//   int i, j;
//   int interval = 10;
//   int nbucket = narray / interval;
//   struct Node **buckets;

//   buckets = (struct Node **)malloc(sizeof(struct Node *) * nbucket);

//   // Initialize empty buckets
//   for (i = 0; i < nbucket; ++i) {
//     buckets[i] = NULL;
//   }

//   for (i = 0; i < narray; ++i) {
//     struct Node *current;
//     int pos = getBucketIndex(arr[i], interval);
//     current = (struct Node *)malloc(sizeof(struct Node));
//     current->data = arr[i];
//     current->next = buckets[pos];
//     buckets[pos] = current;
//   }

//   for (i = 0; i < nbucket; i++) {
//     printf("Bucket[%d]: ", i);
//     printBuckets(buckets[i]);
//     printf("\n");
//   }

//   for (i = 0; i < nbucket; ++i) {
//     buckets[i] = InsertionSort(buckets[i]);
//   }

//   printf("-------------\n");
//   printf("Bucktets after sorting\n");
//   for (i = 0; i < nbucket; i++) {
//     printf("Bucket[%d]: ", i);
//     printBuckets(buckets[i]);
//     printf("\n");
//   }

//   for (j = 0, i = 0; i < nbucket; ++i) {
//     struct Node *node;
//     node = buckets[i];
//     while (node) {
//       arr[j++] = node->data;
//       node = node->next;
//     }
//   }

//   printf("After sorting\n");
//   print(arr, narray);
// }

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value, int interval) {
  return value / interval;
}

void print(int * ar, int narray) {
  int i;
  for (i = 0; i < narray; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}



struct Node *insertionListSort(struct Node *newNode, struct Node *sorted)
{
  if (sorted == NULL  || sorted->data >= newNode->data)
  {
    newNode->next = sorted;
    return newNode;
  }
  else
  { 
    struct Node *current=sorted;

    while (current->next != NULL && current->next->data < newNode->data)
      current = current->next;

    newNode->next = current->next;
    current->next = newNode;
  }

  return sorted;
}

struct Node *sortBucket(struct Node *head)
{
  struct Node *current=head;
  struct Node *sorted=NULL;

  while (current != NULL)
  {
    struct Node* next= current->next ;
    sorted = insertionListSort(current, sorted);
    current = next;
  }

  return sorted;
}

void genericBucketSort(int *numbers, int N)
{
  int numberOfBuckets;
  if (N > 100)
    numberOfBuckets = N/10;
  else
    numberOfBuckets = 10;

  int bucketInterval=(N / numberOfBuckets) + 1;
  struct Node **buckets = malloc (numberOfBuckets*sizeof(struct Node));

  for (int i=0; i < N; i++)
  {
    int position= numbers[i] / bucketInterval ;
    struct Node* current=malloc (sizeof (struct Node));
    current->data = numbers[i];
    current->next = buckets[position];
    buckets[position] = current;
  }

  for (int i=0; i < numberOfBuckets; i++)
    buckets[i] = sortBucket(buckets[i]);
  int j=0;
  for (int i=0; i < numberOfBuckets; ++i)
  {
    struct Node* node= buckets[i];
    while (node)
    {
      numbers[j++] = node->data;
      node = node->next;
    }
  }
  print(numbers, N);
}