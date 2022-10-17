#include <bits/stdc++.h>

using namespace std;

int removeDuplicates1(vector<int> &nums)
{
    const int n = nums.size();
    int j = 1, tmp = nums[0];

    for(int i = 0; i < n; i++)
    {
        if(nums[i] == tmp)
            continue;
        else
        {
            tmp = nums[i];
            swap(nums[i], nums[j++]);
        }
    }

    return j;
}

//有一個想法跟我一樣，但更簡潔的寫法
int removeDuplicates(vector<int> &nums)
{
    int j = 1;
    for(int i = 1; i < nums.size(); i++)
        if(nums[i] != nums[i-1])
            nums[j++] = nums[i];

    return j;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(nums);

    cout << ans << endl;

    return 0;
}