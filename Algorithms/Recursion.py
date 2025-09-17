"""

Recursion: A function calling itself to solve problems by breaking them into smaller parts.

Essential Components:
- Base Case: Stops the recursion
- Recursive Case: Function calls itself with modified parameters

"""

from functools import lru_cache
from typing import List, Optional


def factorial(n: int) -> int:
    """
    Calculate factorial using recursion.
    
    Args: n - Non-negative integer
    Returns: n! (factorial of n)
    Example: factorial(5) = 120
    """
    if n < 0:
        raise ValueError("Negative numbers not allowed")
    if n <= 1:  # Base case
        return 1
    return n * factorial(n - 1)  # Recursive case


def fibonacci(n: int) -> int:
    """
    Calculate nth Fibonacci number (basic recursion - slow for large n).
    
    Args: n - Position in sequence
    Returns: nth Fibonacci number
    Example: fibonacci(6) = 8
    """
    if n <= 1:  # Base case
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)  # Recursive case


@lru_cache(maxsize=None)
def fibonacci_fast(n: int) -> int:
    """
    Fast Fibonacci using memoization (caching results).
    
    Args: n - Position in sequence
    Returns: nth Fibonacci number
    Example: fibonacci_fast(50) = 12586269025
    """
    if n <= 1:
        return n
    return fibonacci_fast(n - 1) + fibonacci_fast(n - 2)


def power(base: float, exp: int) -> float:
    """
    Calculate base^exp using divide-and-conquer recursion.
    
    Args: base, exp - base and exponent
    Returns: base raised to power exp
    Example: power(2, 10) = 1024
    """
    if exp == 0:  # Base case
        return 1
    if exp < 0:
        return 1 / power(base, -exp)
    
    if exp % 2 == 0:  # Even exponent - optimize
        half = power(base, exp // 2)
        return half * half
    return base * power(base, exp - 1)


def gcd(a: int, b: int) -> int:
    """
    Greatest Common Divisor using Euclidean algorithm.
    
    Args: a, b - two integers
    Returns: GCD of a and b
    Example: gcd(48, 18) = 6
    """
    if b == 0:  # Base case
        return abs(a)
    return gcd(b, a % b)  # Recursive case


def binary_search(arr: List[int], target: int, left: int = 0, right: int = -1) -> int:
    """
    Search sorted array using recursive binary search.
    
    Args: arr - sorted list, target - value to find
    Returns: index of target or -1 if not found
    Example: binary_search([1,3,5,7,9], 5) = 2
    """
    if right is None:
        right = len(arr) - 1
    
    if left > right:  # Base case - not found
        return -1
    
    mid = (left + right) // 2
    if arr[mid] == target:  # Base case - found
        return mid
    elif arr[mid] > target:
        return binary_search(arr, target, left, mid - 1)
    else:
        return binary_search(arr, target, mid + 1, right)


class TreeNode:
    """Simple tree node for traversal examples."""
    def __init__(self, val: int = 0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def tree_traversal(root: Optional[TreeNode]) -> List[int]:
    """
    In-order tree traversal: Left → Root → Right
    
    Args: root - tree root node
    Returns: list of values in order
    Example: For tree with root=2, left=1, right=3 → [1, 2, 3]
    """
    if not root:  # Base case
        return []
    
    result = []
    result.extend(tree_traversal(root.left))   # Left subtree
    result.append(root.val)                    # Current node
    result.extend(tree_traversal(root.right))  # Right subtree
    return result


def countdown(n: int) -> None:
    """
    Simple countdown demonstrating direct recursion.
    
    Args: n - starting number
    Example: countdown(3) prints "3 2 1 Blast off!"
    """
    if n <= 0:  # Base case
        print("Blast off!")
    else:
        print(n)
        countdown(n - 1)  # Recursive case


def reverse_string(s: str) -> str:
    """
    Reverse string using recursion.
    
    Args: s - input string
    Returns: reversed string
    Example: reverse_string("hello") = "olleh"
    """
    if len(s) <= 1:  # Base case
        return s
    return s[-1] + reverse_string(s[:-1])  # Last char + reverse of rest


def sum_list(lst: List[int]) -> int:
    """
    Sum all elements in list using recursion.
    
    Args: lst - list of integers
    Returns: sum of all elements
    Example: sum_list([1, 2, 3, 4]) = 10
    """
    if not lst:  # Base case - empty list
        return 0
    return lst[0] + sum_list(lst[1:])  # First element + sum of rest


def is_palindrome(s: str) -> bool:
    """
    Check if string is palindrome using recursion.
    
    Args: s - input string
    Returns: True if palindrome, False otherwise
    Example: is_palindrome("racecar") = True
    """
    s = s.lower().replace(" ", "")  # Normalize
    
    if len(s) <= 1:  # Base case
        return True
    
    if s[0] != s[-1]:  # First != last
        return False
    
    return is_palindrome(s[1:-1])  # Check middle part


def quicksort(arr: List[int]) -> List[int]:
    """
    Sort array using recursive quicksort algorithm.
    
    Args: arr - list to sort
    Returns: sorted list
    Example: quicksort([3, 1, 4, 1, 5]) = [1, 1, 3, 4, 5]
    """
    if len(arr) <= 1:  # Base case
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quicksort(left) + middle + quicksort(right)


def flatten_list(lst: List) -> List:
    """
    Flatten nested list using recursion.
    
    Args: lst - nested list
    Returns: flattened list
    Example: flatten_list([1, [2, 3], [4, [5, 6]]]) = [1, 2, 3, 4, 5, 6]
    """
    result = []
    for item in lst:
        if isinstance(item, list):
            result.extend(flatten_list(item))  # Recursive case
        else:
            result.append(item)  # Base case
    return result


# Performance Comparison Example
def compare_fibonacci():
    """
    Demonstrate performance difference between basic and optimized recursion.
    """
    import time
    
    n = 35
    
    # Basic recursion (slow)
    start = time.time()
    result1 = fibonacci(n)
    time1 = time.time() - start
    
    # Optimized with memoization (fast)
    start = time.time()
    result2 = fibonacci_fast(n)
    time2 = time.time() - start
    
    print(f"fibonacci({n}) = {result1}, Time: {time1:.3f}s")
    print(f"fibonacci_fast({n}) = {result2}, Time: {time2:.6f}s")
    print(f"Speedup: {time1/time2:.0f}x faster")


if __name__ == "__main__":
    # Example usage
    print("=== Recursion Examples ===")
    
    print(f"factorial(5) = {factorial(5)}")
    print(f"fibonacci(10) = {fibonacci(10)}")
    print(f"power(2, 8) = {power(2, 8)}")
    print(f"gcd(48, 18) = {gcd(48, 18)}")
    
    arr = [1, 3, 5, 7, 9, 11]
    print(f"binary_search({arr}, 7) = {binary_search(arr, 7)}")
    
    print(f"reverse_string('hello') = {reverse_string('hello')}")
    print(f"sum_list([1,2,3,4,5]) = {sum_list([1,2,3,4,5])}")
    print(f"is_palindrome('racecar') = {is_palindrome('racecar')}")
    
    nested = [1, [2, 3], [4, [5, 6]]]
    print(f"flatten_list({nested}) = {flatten_list(nested)}")
    
    unsorted = [3, 1, 4, 1, 5, 9, 2, 6]
    print(f"quicksort({unsorted}) = {quicksort(unsorted)}")
    
    print("\n=== Performance Comparison ===")
    compare_fibonacci()
    
    print("\n=== Key Points ===")
    print("• Always define a base case to prevent infinite recursion")
    print("• Use memoization (@lru_cache) for overlapping subproblems")
    print("• Consider iterative solutions for deep recursion")
    print("• Python recursion limit: ~1000 (can be changed with sys.setrecursionlimit)")