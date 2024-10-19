"""
Insertion Sort Algorithm

Insertion Sort works similarly to sorting playing cards in your hands. The array is divided into two parts: 
a sorted part and an unsorted part. We pick elements from the unsorted part and insert them into their correct 
position in the sorted part.

Algorithm Steps:
1. Start from the second element (since the first element is trivially sorted).
2. Compare the current element with elements in the sorted part.
3. Shift elements in the sorted part if they are greater than the current element, to make room for it.
4. Insert the current element at the correct position.

Key Properties:
- Time Complexity: O(n^2) in the worst and average cases, where 'n' is the number of elements.
  Best-case time complexity is O(n) when the array is already sorted.
- Space Complexity: O(1) as it only requires constant extra space.

This implementation uses a loop to insert elements in their proper position by shifting other elements to the right.

Reference: CLRS
"""

def insertion_sort(arr):
    """
    Sorts an array using the Insertion Sort algorithm.

    :param arr: List of elements to be sorted
    """
    # Traverse through the array starting from the second element (index 1)
    for j in range(1, len(arr)):
        key = arr[j]  # The current element to be inserted into the sorted part
        i = j - 1     # The last element of the sorted part

        # Step 1: Move elements of arr[0..i], that are greater than 'key', to one position ahead
        # of their current position to make space for the key.
        while i >= 0 and arr[i] > key:
            arr[i + 1] = arr[i]
            i -= 1
        
        # Step 2: Insert the 'key' at the correct position
        arr[i + 1] = key


if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6]
    print("Original array:", arr)
    insertion_sort(arr)
    print("Sorted array:", arr)
