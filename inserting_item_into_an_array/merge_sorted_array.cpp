#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int put = m + n - 1;
    int t1 = m - 1, t2 = n - 1;

    while(t2 >= 0)
        nums1[put--] = (t1 >= 0 and nums1[t1] > nums2[t2])? nums1[t1--] : nums2[t2--];
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for(int num : nums1)
        cout << num << endl;

    return 0;
}