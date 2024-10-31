#include <stdio.h>

void merge(int arr[], int s, int mid, int e) {
    int s1=s;
    int s2=mid+1;
    while(s1<=mid&&s2<=e){
        if (arr[s1] <= arr[s2]) {
            s1++;
        } else {
            int value = arr[s2];
            int index = s2;
            while (index != s1) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[s1] = value;
            s1++;
            mid++;
            s2++;
        }
    }
}

void mergeSort(int arr[], int s, int e) {
    if (s<e) {
        int mid =s+(e-s)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}

int main() {
    int a[] = {5, 4, 3, 2, 1};
    mergeSort(a, 0, 4);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
