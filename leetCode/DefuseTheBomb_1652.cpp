class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if (k == 0) return res;

        int start, end, windowSum = 0;

        if (k > 0) {
            start = 1;
            end = k;
        } else {
            k = -k;
            start = n - k;
            end = n - 1;
        }

        // Initial window sum
        for (int i = start; i <= end; i++)
            windowSum += code[i % n];

        // Sliding window
        for (int i = 0; i < n; i++) {
            res[i] = windowSum;

            windowSum -= code[start % n];
            start++;
            end++;

            windowSum += code[end % n];
        }

        return res;
    }
};


class Solution {
    public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0) {
            return res;
        } else if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int curr = i + 1;
                int count = 0;
                while (count < k) {
                    if (curr == n) {
                        curr = 0;
                    }
                    sum += code[curr];
                    curr++;
                    count++;
                }
                res[i] = sum;
            }
            return res;
        } else {
            k = abs(k);
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int curr = i - 1;
                int count = 0;
                while (count < k) {
                    if (curr == -1) {
                        curr = n - 1;
                    }
                    sum += code[curr];
                    curr--;
                    count++;
                }
                res[i] = sum;
            }
            return res;
        }
    }
};
