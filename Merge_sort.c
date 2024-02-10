#include<stdio.h>
void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j]=arr[mid + 1 + j];
    i=0;
    j=0;
    k=low;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int low, int high) {
    if (low<high) {
        int mid=(low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void printarray(int A[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}
int main() {
    int arr[] = {15,1,10,20,24,3,8,4,12};
    int n=9;
    mergesort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}
