#include <bits/stdc++.h>

using namespace std;

//time: O(n), space: O(n)
int findMaxConsecutiveOnes1(vector<int> &nums)
{
    vector<int> index;
    vector<int> len;
    int max_len = INT_MIN;

    for(int i = 0; i < nums.size(); i++)
        if(nums[i] == 0)
            index.push_back(i);
    
    if(index.empty())
        return nums.size();
    
    for(int i = 0; i < index.size(); i++)
        if(i == 0)
            len.push_back(index[0]-0);
        else
            len.push_back(index[i]-index[i-1]-1);
    
    len.push_back(nums.size()-1-index.back());

    for(int i = 1; i < len.size(); i++)
        max_len = max(max_len, len[i]+len[i-1]);

    return max_len + 1;
}

//其他人的寫法紀錄只有1和包含一個0的長度
//time: O(n), space: O(1)
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ones = 0;
    int ones_and_zero = 0;
    int len = 0;

    for(int num : nums)
    {
        if(num == 1)
        {
            ones++;
            ones_and_zero++;
        }
        else
        {
            ones_and_zero = ones + 1;
            ones = 0;
        }
        len = max(len, ones_and_zero);
    }

    return len;
}

int main()
{
    vector<int> nums = {1,0,1,1,0,1};
    int ans = findMaxConsecutiveOnes(nums);

    cout << ans << endl;

    return 0;
}