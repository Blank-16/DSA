
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int s = matrix.size();
        int s1 = matrix[0].size();

        for(int i = 0; i < s; i++){
            for(int j = i + 1; j < s1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < s; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Test case 1 - Original matrix:" << endl;
    for (const auto &row : matrix1)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    solution.rotate(matrix1);
    cout << endl;
    cout << "Test case 1 - Rotated matrix:" << endl;
    for (const auto &row : matrix1)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
