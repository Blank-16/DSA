#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0, ansIndex = 0, n = chars.size();
    while (i < n)
    {
        int j = i + 1;
        while(j < n && chars[i] == chars[j])
        {
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j - i;
        if(count > 1)
        {
            string cnt = to_string(count);
            for(char ch: cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> s = {'a', 'a', 'b', 'b', 'b', 'c'};

    int ans = compress(s);
    cout << "RETURNED NUMBER: " << ans << endl;
    for (auto n : s)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
