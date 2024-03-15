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

// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

/*
Logic:
    - If both rows and columns are sorted
    - Place the pointer at last column of first row
    - If the element at the pointer is less than target increase the row value else decrease the column value
*/

#include <bits/stdc++.h>
using namespace std;
int searchSortedMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int j = matrix[0].size() - 1;
    if (n == 0)
        return -1;
    int i = 0;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            cout << "Found " << target << " at " << i << "," << j << endl;
            return 1;
        }
        if (matrix[i][j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {27, 29, 37, 48},
                                  {32, 33, 39, 50}};
    int target = 25;
    searchSortedMatrix(matrix, target);
    return 0;
}
