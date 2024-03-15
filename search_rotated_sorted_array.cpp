// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/*
Logic:
    - Linearly search array and return the element index
*/

// Linear Search
#include <bits/stdc++.h>
using namespace std;

class LinearSolution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    LinearSolution ls;
    cout << ls.search(nums,6) << endl;
}

/*
Logic:
    - Approach: Apply binary search
    - If mid is the target element, return it
    - else check which side of array is sorted by comparing mid with low or high
    - if right side is sorted check if the target resides under that half and eliminate other half
    - else vice versa
*/

// Binary Search (Optimal)
#include <bits/stdc++.h>
using namespace std;
class BinarySolution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (nums[mid] == target)
                return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    };
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    BinarySolution bs;
    cout << bs.search(nums, target) << endl;
}