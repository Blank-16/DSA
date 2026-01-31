class Solution {
public:
    string countAndSay(int n) {
        string current = "1"; // Base case, first term in the sequence

        // Generate terms until we reach the nth term
        for (int i = 1; i < n; i++) {
            string nextTerm = "";
            int count = 1;

            // Traverse the current string to describe the next term
            for (int j = 1; j < current.size(); j++) {
                if (current[j] == current[j - 1]) {
                    count++; // Increment count if the current char is same as
                             // the previous one
                } else {
                    // Append the count and the digit to the next term
                    nextTerm += to_string(count) + current[j - 1];
                    count = 1; // Reset count for the new character
                }
            }

            // Don't forget to append the last counted group
            nextTerm += to_string(count) + current.back();

            // Move to the next term
            current = nextTerm;
        }

        return current;
    }
};