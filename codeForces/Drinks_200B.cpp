#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        sum += x;
    }

    cout << fixed << setprecision(12) << sum / n << endl;

    return 0;
}
