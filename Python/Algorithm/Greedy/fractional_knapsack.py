import csv
import os

def knapsack(items, W):
    """
    The knapsack function selects items to maximize the total value while
    staying within the weight capacity W. It implements the fractional knapsack
    approach, taking whole items when possible and a fraction of an item when needed.

    Parameters:
        items (list): A list of items where each item is represented as a list:
                      [No., Capacity (weight), Life, Value, Efficiency (Value/Life/Capacity)].
        W (int): The maximum weight capacity of the knapsack.

    Output:
        The function prints:
        - A list of items (whole or fraction) added to the knapsack.
        - The total value of all items selected, formatted to two decimal places.

    Explanation:
        1. **Problem**:
           - Given a list of items, each with a weight (Capacity), value, and some additional information (e.g., life).
           - The goal is to fill the knapsack with items to maximize the total value without exceeding a given weight limit W.
           - We are allowed to take whole items or fractions of items (fractional knapsack approach).

        2. **Approach**:
           - Items are sorted based on their efficiency, which is determined by a metric such as value per weight or value/life/weight.
           - The algorithm then iterates through the sorted items, adding as many whole items as possible.
           - When a whole item no longer fits, the algorithm takes a fraction of the item, enough to completely fill the remaining capacity in the knapsack.
        
        3. **Steps**:
           - **Step 1**: Iterate over the list of sorted items.
           - **Step 2**: For each item, check if it can fit entirely into the remaining knapsack capacity.
               - If it can, add the whole item and subtract its weight from the remaining capacity.
               - If it cannot, calculate the fraction of the item that can fit, add the fractional value, and stop.
           - **Step 3**: After the iteration, the selected items and the total value are printed.
        
        4. **Fractional Knapsack**:
           - This approach allows taking a fraction of an item, unlike the 0/1 knapsack problem where you must take or leave an item entirely.
           - In cases where the knapsack's remaining capacity is smaller than the weight of an item, the algorithm calculates how much of the item can fit and adds a proportional amount of its value.

    Example:
        Input:
            items = [[1, 10, 5, 60, 1.2], [2, 20, 8, 100, 0.75], [3, 30, 10, 120, 0.4]]
            W = 50
        Output:
            Whole item 1
            Whole item 2
            33.33% of item 3
            Total Value of all items = $173.33
    """
    
    soln = []
    total = 0

    # Iterate through the sorted list of items and decide whether to take whole or part of the item
    for item in items:
        if item[1] <= W:
            # If the whole item can fit, add it to the solution and subtract its weight from the capacity
            soln.append(f"Whole item {item[0]}")
            total += item[3]
            W -= item[1]
        else:
            # If only part of the item can fit, take the fraction of the item that fits
            soln.append(f"{'{:.2f}'.format(W * 100 / item[1])}% of item {item[0]}")
            total += W * item[3] / item[1]
            break

    # Print the solution and the total value
    print("\n".join(soln))
    print(f'Total Value of all items = $' + "{:.2f}".format(total))


def process_csv(file_path):
    """
    The process_csv function processes a CSV file containing information about items,
    extracts relevant data, sorts the items by their efficiency (value-to-weight-life ratio),
    and applies the knapsack algorithm.

    CSV File Structure:
        - No. (int): The item's number or ID.
        - Capacity (int): The weight of the item.
        - Life (int): The life of the item, indicating how long it lasts before it goes bad.
        - Value (int): The value of the entire item.

    Example CSV format:
        No., Capacity, Life, Value
        1, 10, 5, 500
        2, 20, 10, 1000
        3, 15, 8, 800

    Parameters:
        file_path (str): The path to the CSV file containing the item data.

    Output:
        If the file is valid, the function will call the knapsack function to
        print the optimal selection of items based on the input capacity.
        If the file is invalid, appropriate error messages are printed.
    """
    
    items = []

    # Check if the file has the .csv extension
    if not file_path.lower().endswith('.csv'):
        print(f'Error: File {file_path} is not a CSV file')
        return
    
    # Check if the file exists in the given path
    if not os.path.exists(file_path):
        print(f'Error: File {file_path} does not exist')
        return
    
    # Check if the file is empty
    if os.stat(file_path).st_size == 0:
        print(f'Error: File {file_path} is empty')
        return
    
    # Process the CSV file and extract the required information
    with open(file_path, 'r') as file:
        reader = csv.DictReader(file)
        
        # Read each row, convert the necessary fields, and append to the items list
        for row in reader:
            items.append([
                int(row['No.']),  # Item No.
                int(row['Capacity']),  # Weight or capacity of the item
                int(row['Life']),  # Life of the item
                int(row['Value']),  # Value of the item
                # Efficiency calculated as (Value / Life / Capacity)
                float("{:.5f}".format((int(row['Value']) / int(row['Life'])) / int(row['Capacity'])))
            ])
    
    # Sort items by their efficiency in descending order
    items.sort(key=lambda x: x[4], reverse=True)
    
    # Input maximum capacity from the user
    W = int(input('Enter maximum capacity:'))
    
    # Call the knapsack function to process the sorted items
    knapsack(items, W)


if __name__ == '__main__':
    # Prompt the user to input the file path of the CSV file
    file = input('File:')
    
    # Process the given file
    process_csv(file)
