def sieve_of_eratosthenes(n):
    """
    Args:
        n (int): An integer representing the upper limit.

    Returns:
        list: A list of prime numbers up to n.

    Algorithm:
        - Initialize an array of size n.
        - The first element of the array is set to False, indicating that 1 is not a prime number.
        - The loop starts from the second element and for each element, if it is not marked as False, it is a prime number.
        - The loop iterates through the remaining numbers and marks multiples of the current prime number as False.
        - The loop continues until all the numbers are processed.
        - The elements which are not marked as False are the prime numbers.
    """
    # Initialize an array of size n+1 and set all values to True
    prime_numbers = [True] * (n + 1)

    # Set the first element to False as 1 is not a prime number
    prime_numbers[0] = prime_numbers[1] = False

    # Loop through the array
    for p in range(2, int(n**0.5) + 1):
        if prime_numbers[p]:
            # Mark all multiples of p as False
            for i in range(p * p, n + 1, p):
                prime_numbers[i] = False

    # Return the list of prime numbers
    return [p for p in range(2, n + 1) if prime_numbers[p]]


# Test the function
limit = 500000
print(f"Prime numbers up to {limit}: {sieve_of_eratosthenes(limit)}")
print(f"Total prime numbers up to {limit}: {len(sieve_of_eratosthenes(limit))}")