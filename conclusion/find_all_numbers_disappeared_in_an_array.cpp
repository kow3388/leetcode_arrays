#include <bits/stdc++.h>

using namespace std;

vector<int> findDisappearedNumbers1(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> ans;
    vector<int> check(n, 0);

    for(int num : nums)
        check[num]++;
    
    for(int i = 0; i < check.size(); i++)
        if(check[i] == 0)
            ans.push_back(i+1);

    return ans;
}

//官方的解法是用絕對值判斷
//time: O(n), space: O(1)
//先掃過一遍，把nums[nums[i]]設為負值
//再掃過一遍，如果是正值表示沒出現過
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> ans;

    for(int i = 0; i < n; i++)
        nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);

    for(int i = 0; i < n; i++)
        if(nums[i] > 0)
            ans.push_back(i+1);

    return ans;
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearedNumbers(nums);

    for(int a : ans)
        cout << a << endl;

    return 0;
}