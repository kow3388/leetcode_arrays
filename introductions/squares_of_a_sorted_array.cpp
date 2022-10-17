#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares1(vector<int> &nums)
{
    const int n = nums.size();

    for(int i = 0; i < n; i++)
        nums[i] *= nums[i];

    sort(nums.begin(), nums.end());

    return nums;
}

//因為題目有說一開始的array是sorted in non-decreasing order
//所以可以簡化為one phase(但不會比較快)
vector<int> sortedSquares(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> ans;
    int head = 0, tail = n-1;

    while(head <= tail)
        if(nums[head]*nums[head] > nums[tail]*nums[tail])
        {
            ans.insert(ans.begin(), nums[head]*nums[head]);
            head++;
        }
        else
        {
            ans.insert(ans.begin(), nums[tail]*nums[tail]);
            tail--;
        }
    
    return ans;
}

int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = sortedSquares(nums);

    for(int num : ans)
        cout << num << endl;

    return 0;
}