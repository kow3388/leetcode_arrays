#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    const int n = nums.size();
    int j = 0;

    for(int i = 0; i < n; i++)
        if(nums[i] != val)
            nums[j++] = nums[i];
    
    return j;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = removeElement(nums, val);

    cout << ans << endl;

    return 0;
}