// You are using GCC
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long int factorial(int num);
void printing(int num);
int power(int num);
int binarySearch(int arr[], int size, int target);
int summation(int n);
int main()
{
    int num;
    scanf("%d ", &num);
    long long int result = factorial(num);
    printf("The result is %lld", result);
    printf("\n%d", summation(8));
    return 0;
}

long long int factorial(int num)
{
    if (num == 0)
        return 1;
    return (num * factorial(num - 1));
}

void printing(int num)
{
    if (num == 0)
        return;
    printf("%d\n", num);
    printing(num - 1);
}

int summation(int n)
{
    if (n == 1)
        return 1;
    n = n + summation(n - 1);
    return n;
}

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}   