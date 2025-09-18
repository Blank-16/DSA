#include <iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end)
{
    if (start > end)
        return true;

    if (str[start] != str[end])
        return false;
    else
    {
        return checkPalindrome(str, start + 1, end - 1);
    }
}

int main()
{
    string str;
    cout << "Give a string :";
    cin >> str;
    cout << "Palindrome check : " << (checkPalindrome(str, 0, str.length() - 1) ? "It is a palindrome" : "It isn't palindrome");

    return 0;
}