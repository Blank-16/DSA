    
def PrimeNumberFinding():
    def is_prime(num):
        if num <= 1:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True

    def find_primes_in_range(start, end):
        primes = []
        for num in range(start, end + 1):
            if is_prime(num):
                primes.append(num)
        return primes

    # Example usage
    start = 1000
    end = 10000
    primes = find_primes_in_range(start, end)
    print(f"Prime numbers between {start} and {end}: {primes}")


def FibonacciSeries():
    def fibonacci(n):
        if n <= 0:
            return []
        elif n == 1:
            return [0]
        elif n == 2:
            return [0, 1]
        else:
            fib = [0, 1]
            for i in range(2, n):
                fib.append(fib[-1] + fib[-2])
            return fib

    n = 10
    fib = fibonacci(n)
    print(f"Fibonacci series of length {n}: {fib}")