#include <bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traverse s2 string in window of size s1 length and compare the two
    int i = 0;
    int winSize = s1.length();
    int count2[26] = {0};
    while (i < winSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
    {
        return 1;
    }
    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - winSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;
        if (checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

bool checkInclusionPart2(string s1, string s2) {
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    
    int winSize = s1.length();
    int count2[26] = {0};
    
    // Single loop combining both initialization and sliding
    for (int i = 0; i < s2.length(); i++) {
        // Add current character to window
        int index = s2[i] - 'a';
        count2[index]++;
        
        // If window size exceeds winSize, remove the leftmost character
        if (i >= winSize) {
            int oldIndex = s2[i - winSize] - 'a';
            count2[oldIndex]--;
        }
        
        // Check for match only when we have a complete window
        if (i >= winSize - 1 && checkEqual(count1, count2)) {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";
    cout << "Inclusion: " << (checkInclusionPart2(s1, s2) ? "True" : "False");
    return 0;
}