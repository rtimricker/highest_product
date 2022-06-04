/*
company logo

Given an array of integers, find the highest product you can get from three of the integers.

The input arrayOfInts will always have at least three integers.

*/

#include <stdio.h>
#include <stdlib.h>

// To execute C, please define "int main()"

//int arrayOfInts[] = {-100, -10, -1, 0, 20, 2, 10};
int arrayOfInts[] = {-20, -100, -10, -1, 0, 20, 2, 10};
int prod;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b > *(int*)a );
}


int main() {
  printf ("sizeof: %d\n", (int)sizeof(arrayOfInts));

  qsort(&arrayOfInts[0], sizeof(arrayOfInts) / sizeof(arrayOfInts[0]), sizeof(int), cmpfunc);

  // group in a window of threes and shift window by one to ascending
  printf ("[%d]", (int)arrayOfInts[0]);
  for (int idx = 0; idx < (sizeof(arrayOfInts) / sizeof(int)); idx++) {
    printf ("[%d]", arrayOfInts[idx]);
  }
  printf ("\n");

  int largest = 0xffffffff; // max negative integer number:w:q
  // group of three integer sized number window moving through array 
  int start = 0;
  int end = 3;
  for (; end <= sizeof(arrayOfInts)/sizeof(int); start++, end++) {
    int prod = 1;  // multiply by one at start
    for (int idx = start; idx < end; ++idx) {
      printf ("%d ", arrayOfInts[idx]);
      // multiply
      prod *= (int)arrayOfInts[idx];
    }
    if (prod > largest) {
      largest = prod;
    }
    printf ("[%d ][largest: %d]\n", prod, largest);
  }
  
  printf ("\nprod %d\n", largest);
  return 0;
}
