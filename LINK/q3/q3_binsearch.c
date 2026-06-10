/* ===================================================================
 * Q3: binary-search helper  (run by q3_fork.c)
 * -------------------------------------------------------------------
 * HOW TO RUN  (copy-paste each line into the terminal):
 *
 *     gcc -o binsearch q3_binsearch.c   # name it 'binsearch' for q3_fork.c
 *     
 *     # (to test it on its own:)
 *     gcc q3_binsearch.c
 *     ./a.out
 * ===================================================================
 */

#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)  return 1;
        if (arr[mid] > x)   return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void swap(int *xp, int *yp) { int t = *xp; *xp = *yp; *yp = t; }

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
}

int main() {
    int n, key, arr[10];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, n);
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) printf("Element is not present in array\n");
    else              printf("Element is present\n");
    return 0;
}
