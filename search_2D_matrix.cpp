// https://leetcode.com/problems/search-a-2d-matrix/

/*
Logic:
    - Approach: Using binary search on the index
    - Initialize two variables n and m for rows and columns
    - Initial a low value to 0 and high to last index
    - Find a mid value by taking average of high and low
    - Find the element at mid value index by using this formula: matrix[mid / column][mid % column]
    - If the element is < target then low = mid + 1, else high = mid - 1  
*/

#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0)
        return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        if (matrix[mid / m][mid % m] == target)
            return true;
        else if (matrix[mid / m][mid % m] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    searchMatrix(matrix, target) ? cout << "true" << endl : cout << "false" << endl;    
    return 0;
}