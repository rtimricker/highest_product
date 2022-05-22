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

//int cmpfunc (const void * a, const void * b) {
//   return ( *(int*)b > *(int*)a );
//}

int cmpfunc (const void * a, const void * b) {
   int arg1 = abs(*(int*)a);
   int arg2 = abs(*(int*)b);
   printf ("a: %d, b: %d\n", arg1, arg2);
   return (arg1 > arg2);
   //return ( *(int*)a < *(int*)b );
   //printf ("a: %d, b: %d\n", abs(*(int*)a), abs(*(int*)b));
   //return ( abs(*(int*)a) < (*(int*)b) );
}


int main() {
  printf ("sizeof: %d\n", (int)sizeof(arrayOfInts));

  qsort(&arrayOfInts[0], sizeof(arrayOfInts) / sizeof(arrayOfInts[0]), sizeof(int), cmpfunc);

  // group in a window of threes and shift window by one to ascending
  printf ("[%d]", arrayOfInts[0]);
  for (int idx = 0; idx < (sizeof(arrayOfInts) / sizeof(int)); idx++) {
    printf ("[%d]", arrayOfInts[idx]);
  }
  printf ("\n");
  
  prod = arrayOfInts[0];
  for (int idx = 1; idx < 3; idx++) {
    printf ("[%d]", arrayOfInts[idx]);

    prod *= arrayOfInts[idx];

    //if (prod * arrayOfInts[idx] > 0) {  /* check for two negatives */
    //} else {
    //}
  }

  printf ("\nprod %d\n", prod);
  /* printf ("hello"); */
  return 0;
}
