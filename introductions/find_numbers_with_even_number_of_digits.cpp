#include <bits/stdc++.h>

using namespace std;

int findNumbers(vector<int> &nums)
{
    int cnt = 0;
    for(int num : nums)
        if(to_string(num).length()%2 == 0)
            cnt++;

    return cnt;
}

int main()
{
    vector<int> nums = {12,345,2,6,7896};
    int ans = findNumbers(nums);

    cout << ans << endl;

    return 0;
}