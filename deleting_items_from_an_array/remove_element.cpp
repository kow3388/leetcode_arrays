#include <bits/stdc++.h>

using namespace std;

int removeElement1(vector<int> &nums, int val)
{
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] == val)
        {
            nums.erase(nums.begin()+i);
            i--;
        }
    
    return nums.size();
}

//其他人的寫法
//因為他只要回傳移除後的剩餘個數k
//所以實際上並不用真的移除
int removeElement(vector<int> &nums, int val)
{
    const int n = nums.size();
    int j = 0;

    //j一開始指向nums的頭
    //如果nums[i]不是val，則放到j(把不是val的往前放)
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