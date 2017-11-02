#include <stdio.h>
#include <stdlib.h>
void merge(int [], int, int [], int, int []);

int main() {
  int a[100], b[100], m, n, c, sorted[200];

  printf("Input 18 elements in first array, one by one: \n");
  for (c = 0; c < 18; c++) {
    scanf("%d", &a[c]);
  }

  printf("Input 5 elements in second array, one by one: \n");
  for (c = 0; c < 5; c++) {
    scanf("%d", &b[c]);
  }

  merge(a, m=18, b, n=5, sorted);

  printf("Sorted array:\n");

  for (c = 0; c < m + n; c++)
    {
    printf("%d\n", sorted[c]);
  }

  return 0;
}

void merge(int a[], int m, int b[], int n, int sorted[]) {
  int i, j, k;

  j = k = 0;

  for (i = 0; i < m + n;) {
    if (j < m && k < n) {
      if (a[j] < b[k]) {
        sorted[i] = a[j];
        j++;
      }
      else {
        sorted[i] = b[k];
        k++;
      }
      i++;
    }
    else if (j == m) {
      for (; i < m + n;) {
        sorted[i] = b[k];
        k++;
        i++;
      }
    }
    else {
      for (; i < m + n;) {
        sorted[i] = a[j];
        j++;
        i++;
      }
    }
  }
}

/*(1) Define one array of size 18 for A and the other array of size 5 for B.
(2) Initialize A by inputting 13 integers in the ascending order, and Initialize B by inputting 5 integers in
the ascending order. (Note: don’t hard code the integers of the arrays.)
(3) Merge B with A in a way all values are sorted.
(4) Print out the updated array A, after merging with B.
For example:
If your input for A is
1, 3, 11, 15, 20, 25, 34, 54, 56, 59, 66, 69, 71
and your input for B is
2, 4, 5, 22, 40
Finally, after merging A and B, A becomes
1, 2, 3, 4, 5, 11, 15, 20, 22, 25, 34, 40, 54, 56, 59, 66, 69, 71
*/
