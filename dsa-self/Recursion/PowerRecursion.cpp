#include <iostream>
using namespace std;

long long int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long int ans = power(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cout << "Give a and b :";
    cin >> a >> b;
    cout << "***************"<< endl << "POWER OF A^B: " << power(a, b) << endl << "***************";
}