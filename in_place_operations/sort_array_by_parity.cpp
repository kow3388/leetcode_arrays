#include <bits/stdc++.h>

using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    const int n = nums.size();
    for(int i =0, j = 0; i < n; i++)
        if(nums[i]%2 == 0)
            swap(nums[i], nums[j++]);
    
    return nums;
}

int main()
{
    vector<int> nums = {3,1,2,4};
    vector<int> ans = sortArrayByParity(nums);

    for(int num : ans)
        cout << num << endl;

    return 0;
}