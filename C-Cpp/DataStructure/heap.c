// the following is the code for Heap (with the first index being the maximum)
#include "stdio.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct heaps{
    int *arr;   // this is the array
    int size;
} Heap;

void init(Heap *h){
    h->size = 0;
    printf("What is the Size of Heap:- ");
    scanf("%d", &h->size);
    h->size += 1;

    h->arr = (int*)malloc(sizeof(int) * h->size);  // Allocate memory before using arr
    h->arr[0] = 0;  // Initialize the 0th element (dummy)

    printf("Initialized");
    printf("\nENTER THE NUMBERS BELOW:- ");

    for(int i = 1; i < h->size; i++){
        scanf("%d", &h->arr[i]);
    }
}

void swap(Heap* h, int idx1, int idx2){
    int temp = h->arr[idx1];
    h->arr[idx1] = h->arr[idx2];
    h->arr[idx2] = temp;
}

void heapify(Heap* h, int i){           // i refers to the maximal at the index
    int largest = i;                    // here we have to go from the top, to the bottom region
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < h->size && h->arr[left] > h->arr[largest]){
        largest = left;
    }
    
    if (right < h->size && h->arr[right] > h->arr[largest]){
        largest = right;
    }

    if (largest != i){
        swap(h, i, largest);
        heapify(h, largest);    // USING RECURSION
    }
}

void heapBuild(Heap* h){
    int startingPoint = (h->size - 1) / 2;

    for (int i = startingPoint; i >= 1; i--) {
        heapify(h, i);  // Call heapify for all non-leaf nodes
    }
}

void display(Heap* h){
    int len = h->size;
    printf("HEAPIFIED HEAP IS: ");
    for (int i = 1; i < len; i++){
        printf("%d | ", h->arr[i]);
    }
    printf("\n");
}

void deleteNodes(Heap* h){
    if(h->size<=1){
        printf("EMPTY HEAP!");
        return;
    }

    printf("REMOVED NODE %d", h->arr[1]);       // I wrote arr[1] because we are using a 1st index array
    h->arr[1]=h->arr[h->size-1];
    h->size--; // the size needs to be decreased so that we do not enter the root removal again while re-heapifying
    h->arr[h->size]=0;

    heapify(h, 1);
    printf("\n");
    display(h);
}

void kthElement(Heap* h, int k){
    k=k-1;      // as we pop k-1 times, and then, the present at the max will be the kth element
    Heap* copy=h;
    if(k > copy->size){
        printf("\nINDEX OUT OF BOUNDS");
        return;
    }
    for(int i=0; i<k; i++){
        deleteNodes(copy);
        heapify(copy,1);
    }

    printf("\nKth Element in the Heap is:- %d", copy->arr[1]);
}

void heapSort(Heap* h){
    int s=h->size;
    for(int i=s-1; i>1; i--){
        swap(h, 1, i);
        h->size--;
        heapify(h,1);
    }

    h->size=s;      // restoring the size back
    printf("HEAP SORT DONE\n");
    display(h);
}

int main(){
    Heap h;
    init(&h);
    heapBuild(&h);
    display(&h);

    int reply=0;

    printf("\nDo You Wish to Poll the Heap ( Enter 1 or O ):- ");
    scanf("%d", &reply);

    if(reply==1){
        deleteNodes(&h);
    }

    // earlier, I put the kth below heap sort
    // the problem was that, since it was heap as a data structure, the heap was getting sorted
    // thus, using the kth was giving a logically wrong answer

    int k=0;
    printf("\nDo You Wish to Get the Kth Element ( Enter 1 or O ):- ");
    scanf("%d", &reply);
    if(reply==1){
        printf("Enter the value of k:- ");
        scanf("%d", &k);
        kthElement(&h, k);
    }

    printf("\nDo You Wish to Perform Heap Sort ( Enter 1 or O ):- ");
    scanf("%d", &reply);

    if(reply==1){
        heapSort(&h);
    }

    printf("\n\nRE-RUN THE CODE ( Enter 1 or O ):- ");
    scanf("%d", &reply);

    if(reply==1){
        main();
    }

    printf("\n\nEXITING THE CODE!\nThank You For Trying out the Code");
    return 0;
}
