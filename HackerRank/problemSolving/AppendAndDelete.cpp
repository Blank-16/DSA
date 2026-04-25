#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int common = 0;
    
    // longest common prefix
    while (common < s.length() && common < t.length() && s[common] == t[common]) {
        common++;
    }
    
    int deletions = s.length() - common;
    int additions = t.length() - common;
    int min_ops = deletions + additions;
    
    // Exact operations match
    if (k == min_ops) return "Yes";
    
    // Enough operations to delete everything and rebuild
    if (k >= s.length() + t.length()) return "Yes";
    
    // Extra operations can be wasted in pairs
    if (k > min_ops && (k - min_ops) % 2 == 0) return "Yes";
    
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
