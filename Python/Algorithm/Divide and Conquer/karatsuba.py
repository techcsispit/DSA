def product(n1: str, n2: str) -> int:
    """
    Karatsuba signed big integer multiplication algorithm.

    This function multiplies two potentially large integers (provided as strings) using 
    the Karatsuba algorithm, which is more efficient than the standard long multiplication
    method for large numbers.

    Parameters:
        n1 (str): The first large integer as a string (can be negative).
        n2 (str): The second large integer as a string (can be negative).
    
    Returns:
        int: The product of the two integers.
    
    Input Format:
        - Both n1 and n2 are strings representing large integers. They may be negative, and 
          the number of digits in each number should not exceed 4000.

    Output Format:
        - The function returns the product of the two integers as a signed integer.

    Example:
        Input: 
            n1 = "1234"
            n2 = "5678"
        Output:
            7006652
    
    Karatsuba Multiplication Explanation:
        1. **Sign Handling**: The signs of both numbers are determined first:
           - If both numbers have the same sign, the result is positive.
           - If they have different signs, the result is negative.
           The sign is calculated as `sign1 * sign2`, where each sign is either 1 (positive) or -1 (negative).
        2. The input numbers are divided into two halves (a, b for n1; c, d for n2).
        3. Recursive calls are made for the products of the halves:
           - `ac = product(a, c)`
           - `bd = product(b, d)`
        4. Additional recursive calls are made to calculate intermediate terms:
           - `p = a + b`, `q = c + d`, and `pq = product(p, q)`
        5. The result is assembled from these sub-results using:
           - `result = 10^(2 * half_size) * ac + 10^(half_size) * (pq - ac - bd) + bd`
        6. The final result is multiplied by the sign (`final_sign`) calculated in step 1 to ensure the correct sign.

    Time Complexity:
        Since each iteration the integer into two integers of half length and the two halves are used to calculate three products recursively, that is ac, bd and pq and the final combining step is just O(n) time because of addition.
        
        Therefore, T(n) = 3T(n/2) + O(n)
        By master theorem, we can see that the time complexity comes out to O(n^1.585) which is better than the conventional long multipliation method which takes O(n^2)
    """
    
    # Determine the signs of both numbers (1 for positive, -1 for negative)
    sign1 = -1 if n1[0] == '-' else 1
    sign2 = -1 if n2[0] == '-' else 1

    # Remove the negative sign from the string for easier processing
    n1 = n1.lstrip('-')
    n2 = n2.lstrip('-')

    # The final sign of the product is determined by the product of the individual signs
    final_sign = sign1 * sign2

    # Ensure both numbers have the same length by padding with leading zeros
    n = max(len(n1), len(n2))
    n1 = n1.zfill(n)
    n2 = n2.zfill(n)

    # Base case for recursion: if numbers are of length 1, multiply them directly
    if n <= 1:
        return final_sign * (int(n1) * int(n2))

    # Divide the numbers into two halves
    mid = n // 2
    a, b = n1[:mid], n1[mid:]
    c, d = n2[:mid], n2[mid:]

    # Recursively compute the products of the parts
    ac = product(a, c)
    bd = product(b, d)
    p = str(int(a) + int(b))
    q = str(int(c) + int(d))
    pq = product(p, q)

    # Compute the intermediate term (ad + bc)
    adbc = pq - ac - bd

    # Return the final result based on Karatsuba formula, adjusted for sign
    return final_sign * (10**((n-mid)*2) * ac + 10**(n-mid) * adbc + bd)


if __name__ == '__main__':
    n1, n2 = input("Number 1: "), input("Number 2: ")
    
    # Ensure valid input by checking if the numbers are integers
    if len(n1) == 0 or len(n2) == 0:
        print('Please enter a number')
        exit()
    
    if len(n1) > 4000 or len(n2) > 4000:
        print('Number should not exceed 4000 digits')
        exit()

    try:
        int(n1)
        int(n2)
    except ValueError:
        print('Number has to be integer')
        exit()

    # Output the result of the multiplication
    print(product(n1, n2))
