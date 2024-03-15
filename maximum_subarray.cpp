// https://leetcode.com/problems/maximum-subarray/description/

/*
Logic:
    - Create two variable to keep track of carrying sum and maximum int
    - Don't carry any < 0 value to sum, if value is <0 make the sum 0
    - Keep adding elements to sum
    - If our sum > maximum int, then maximum int = sum
    - Finally return maximum int
*/

#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxSubArray(nums) << endl;
}