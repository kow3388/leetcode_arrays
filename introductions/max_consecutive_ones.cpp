#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max_len = 0, len = 0;

    for(int i = 0; i < nums.size(); i++)
        if(nums[i] == 1)
            max_len = max(max_len, ++len);
        else
            len = 0;
    
    return max_len;
}

int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    int ans = findMaxConsecutiveOnes(nums);

    cout << ans << endl;

    return 0;
}