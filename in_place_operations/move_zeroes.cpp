#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    const int n = nums.size();
    for(int i = 0, j = 0; i < n; i++)
        if(nums[i] != 0)
            swap(nums[i], nums[j++]);
}

int main()
{
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    for(int num : nums)
        cout << num << endl;

    return 0;
}