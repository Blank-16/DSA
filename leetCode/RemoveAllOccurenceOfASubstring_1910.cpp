#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string a = "daabcbaabcbc", parta = "abc";
    a = removeOccurrences(a, parta);  
    cout << "After removal: " << a; 
    return 0;
}