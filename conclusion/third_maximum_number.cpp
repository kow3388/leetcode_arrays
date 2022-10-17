#include <bits/stdc++.h>

using namespace std;

int thirdMax1(vector<int> &nums)
{   
    long long int m1 = LLONG_MIN, m2 = LLONG_MIN, m3 = LLONG_MIN;

    for(int num : nums)
        if(num > m1)
        {
            m3 = m2;
            m2 = m1;
            m1 = num;
        }
        else if(num > m2 and num < m1)
        {
            m3 = m2;
            m2 = num;
        }
        else if(num > m3 and num < m2)
            m3 = num;

    return m3 == LLONG_MIN? m1 : m3;
}

//官方解答, using min heap
int thirdMax(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> taken;

    for(int i = 0; i < nums.size(); i++)
    {
        //If current number was already taken, skip it.
        if(taken.count(nums[i]))
            continue;
        
        //If min heap already has three numbers in it.
        //Pop the smallest if current number is bigger than it.
        if(minHeap.size() == 3)
        {
            if(minHeap.top() < nums[i])
            {
                taken.erase(minHeap.top());
                minHeap.pop();
                minHeap.push(nums[i]);
                taken.insert(nums[i]);
            }
        }
        //If min heap does not have three number we can push it.
        else
        {
            minHeap.push(nums[i]);
            taken.insert(nums[i]);
        }
    }

    if(minHeap.size() == 1)
        return minHeap.top();
    else if(minHeap.size() == 2)
    {
        minHeap.pop();
        return minHeap.top();
    }

    return minHeap.top();
}

int main()
{
    vector<int> nums = {2,2,3,1};
    int ans = thirdMax(nums);

    cout << ans << endl;

    return 0;
}