"""
Algorithm:
QUICKSORT(A,p,r)
//Input: A is the input array which we have to sort
         p is the index of the first element of the array
         r is the index of the last element of the array
         Initial call will be of form QUICKSORT(A,0,A.length()-1)
//Output: Sorts the array inputted

if p < r:
    q = PARTITION(A,p,r) // Partitions array into 2 halves such that elements to the left of q are all less than it and elements to the right of it are more than it
    QUICKSORT(A,p,q-1) //Sorting Left of Partition
    QUICKSORT(A,q+1,r) //Sorting Right of Partition

    
PARTITION(A,p,r)
//Input: Same as QUICKSORT
//Output: Returns index of element that the array has been partitioned by

x = A[r]//Let element we partition by be the last element
i = p-1
for(j = p to r-1)
    if(A[j]<=x)://If element is less than x swap it to the start
        i++
        swap(A[i],A[j])
swap(A[i+1],A[j])//Swap element to the place such that left elements are less than it and right elements are more
return i+1
"""

def partition(array: list, start: int, end: int) -> int:
    """Helper function for Quick Sort."""
    if not array: 
        return 0
    pivot = array[end]
    index = start - 1
    for j in range(start, end):
        if array[j] <= pivot:
            index += 1
            array[index], array[j] = array[j], array[index]
    array[index+1], array[end] = array[end], array[index+1]
    return index+1

def quicksort(array, start, end):
    """Returns a list of sorted array elements using Quick Sort."""
    if start < end:
        partition_index = partition(array, start, end)
        quicksort(array, start, partition_index-1)
        quicksort(array, partition_index+1, end)

if __name__ == "__main__":
    array = [6,4,2,7,1]
    n = len(array) - 1
    quicksort(array, 0, n)
    print(array)
