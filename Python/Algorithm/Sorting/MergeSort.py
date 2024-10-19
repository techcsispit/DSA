"""
Merge Sort Algorithm

Merge Sort is a divide-and-conquer algorithm that works by recursively dividing the array into two halves, 
sorting each half, and then merging the two sorted halves. The process can be broken down into the following steps:

1. Divide: Recursively split the array into two halves until each subarray contains only one element.
2. Conquer: Merge each pair of subarrays by comparing their elements and sorting them during the merge process.
3. Combine: As the recursion unwinds, the two halves are merged together in sorted order.

Key Properties:
- Time Complexity: O(n log n), where 'n' is the number of elements in the array.
  This is because the array is divided into two halves in each recursive call (log n divisions),
  and merging two sorted halves takes O(n) time.
- Space Complexity: O(n) due to the extra space required for temporary arrays during merging.

This algorithm is stable and works well for larger datasets, but it uses extra space for the merging process.

Reference: CLRS
"""

def merge_sort(arr, p, r):
    """
    Sorts an array using the Merge Sort algorithm.

    :param arr: List of elements to be sorted
    :param p: Starting index of the subarray
    :param r: Ending index of the subarray
    """
    if p < r:
        # Step 1: Find the middle point to divide the array into two halves
        q = (p + r) // 2

        # Step 2: Recursively sort the two halves
        merge_sort(arr, p, q)
        merge_sort(arr, q + 1, r)

        # Step 3: Merge the sorted halves
        merge(arr, p, q, r)


def merge(arr, p, q, r):
    """
    Merges two sorted subarrays into a single sorted subarray.
    
    :param arr: List of elements
    :param p: Starting index of the left subarray
    :param q: Middle index, separating left and right subarrays
    :param r: Ending index of the right subarray
    """
    # Step 1: Create temporary arrays for left and right halves
    n1 = q - p + 1  # Length of left half
    n2 = r - q      # Length of right half

    # Initialize the left and right subarrays
    L = [0] * n1
    R = [0] * n2

    # Step 2: Copy data to temporary arrays
    for i in range(n1):
        L[i] = arr[p + i]

    for j in range(n2):
        R[j] = arr[q + 1 + j]

    # Step 3: Merge the two sorted subarrays into the original array
    i = j = 0  # Initial indexes for L and R
    k = p      # Initial index for merged subarray

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Step 4: Copy remaining elements of L[], if any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Step 5: Copy remaining elements of R[], if any
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


if __name__ == "__main__":
    arr = [38, 27, 43, 3, 9, 82, 10]
    print("Original array:", arr)
    merge_sort(arr, 0, len(arr) - 1)
    print("Sorted array:", arr)
