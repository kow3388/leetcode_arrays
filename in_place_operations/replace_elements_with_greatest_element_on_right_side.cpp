#include <bits/stdc++.h>

using namespace std;

vector<int> replaceElements1(vector<int> &arr)
{
    const int n = arr.size();
    for(int i = 1; i < n; i++)
        arr[i-1] = *max_element(arr.begin()+i, arr.end());

    arr[n-1] = -1;

    return arr;
}

//其他人的做法
//只需要掃過一次即可
vector<int> replaceElements(vector<int> &arr)
{
    const int n = arr.size();
    int mx = -1;

    //exchange(a, b) => 把b assign到a，再把a舊值回傳
    for(int i = n-1; i >= 0; i--)
        //紀錄(從右邊開始看)目前最大
        mx = max(mx, exchange(arr[i], mx));
    
    return arr;
}

int main()
{
    vector<int> arr = {17,18,5,4,6,1};
    vector<int> ans = replaceElements(arr);

    for(int num : ans)
        cout << num << endl;

    return 0;
}