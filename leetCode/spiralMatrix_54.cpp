#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int rows = matrix.size(), cols = matrix[0].size();
    int count = 0, total = rows * cols;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (count < total)
    {
        // Traverse top row
        for (int col = left; count < total && col <= right; col++)
        {
            ans.push_back(matrix[top][col]);
            count++;
        }
        top++;

        // Traverse right column
        for (int row = top; count < total && row <= bottom; row++)
        {
            ans.push_back(matrix[row][right]);
            count++;
        }
        right--;

        // Traverse bottom row
        for (int col = right; count < total && col >= left; col--)
        {
            ans.push_back(matrix[bottom][col]);
            count++;
        }
        bottom--;

        // Traverse left column
        for (int row = bottom; count < total && row >= top; row--)
        {
            ans.push_back(matrix[row][left]);
            count++;
        }
        left++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ansMatrix = spiralOrder(matrix);
    for (auto n : ansMatrix)
    {
        cout << n << " ";
    }
    return 0;
}
