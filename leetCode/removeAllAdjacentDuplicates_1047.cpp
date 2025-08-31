#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    int i = 0, n = s.length();
    for (int j = 0; j < n; ++j, ++i)
    {
        s[i] = s[j];
        if (i > 0 && s[i - 1] == s[i])
            i -= 2;
    }
    return s.substr(0, i);
}
int main()
{
    string s;
    cout << "Give input for s :";
    cin >> s;
    string newStr = removeDuplicates(s);
    cout << "After removing adjacent elements: " << newStr;
    return 0;
}