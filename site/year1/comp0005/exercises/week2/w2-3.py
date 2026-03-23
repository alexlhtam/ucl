'''
An array is bitonic if it is comprised of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Write a program that, given a bitonic array of n distinct integer values, determines whether a given integer is in the array.
Use  O(lg n) compares in the worst case.

For example, the array [2,4,6,8,10,12,11,9,7,5,3] is bitonic, while the following are not: [1,2,3], [1,2,3,2,3],[5].

Hint
First, find the maximum integer using lg n compares—this divides the array into the increasing and decreasing pieces.
'''

def find_max_index(arr):
    n = len(arr)

    if n == 0:
        return -1

    low = 0
    high = n - 1

    while low <= high:
        mid = (low + high) // 2

        # Case 1: mid is the peak (not at boundaries)
        if mid > 0 and mid < n - 1 and arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]:
            return mid

        # Case 2: mid is on the increasing slope OR at the beginning
        # Check if mid has a right neighbour and is less than it
        elif mid < n - 1 and arr[mid] < arr[mid+1]:
            low = mid + 1

        # Case 3: mid is on the decreasing slope OR is the last element
        # This covers: mid > n - 1 (arr[mid] > arr[mid+1]) or mid = n - 1
        else: 
            high = mid - 1

    if n == 1:
        return 0

    return -1 # Should not be reached for a valid bitonic array

def check_incr_arr(arr, low, high, target):
    while low <= high:
        mid = (low + high) // 2 

        if arr[mid] == target:
            return True
        elif target > arr[mid]:
            low = mid + 1
        else:
            high = mid - 1

    return False

def check_decr_arr(arr, low, high, target):
    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return True
        elif target < arr[mid]:
            low = mid + 1
        else:
            high = mid - 1

    return False

def is_in_bitonic_array(arr, k):
    n = len(arr)

    if n == 0:
        return False
    
    max_index = find_max_index(arr)

    if arr[max_index] == k:
        return True
    
    if k > arr[max_index]:
        return False
    
    found = check_incr_arr(arr, 0, max_index - 1, k)
    if found:
        return True
    
    return check_decr_arr(arr, max_index + 1, n - 1, k)