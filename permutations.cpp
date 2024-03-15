// https://leetcode.com/problems/permutations/

/*
Logic:
    - Approach: Using backtracking and swapping
    - Take an index pointer which is initially 0
    - Swap that index number with each value in nums.size and increase the index pointer
    - When the pointer reaches out of bond, push the vector to ans vector
    - Swap back both values in order to backtrack to original state
    - Recursively call this function by increasing value of index pointer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recurPermute(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            recurPermute(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.permute(nums);
    return 0;
}