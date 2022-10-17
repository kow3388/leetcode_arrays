#include <bits/stdc++.h>

using namespace std;

bool validMountainArray1(vector<int> &arr)
{
    const int n = arr.size();
    vector<int>::iterator it = max_element(arr.begin(), arr.end());
    int idx = distance(arr.begin(), it);

    if(idx == 0)
        return false;

    int tmp = idx;
    for(int i = idx+1; i < n; i++)
        if(arr[i] == arr[idx])
            tmp = i;
        else
            break;
    
    if(tmp == n - 1)
        return false;
    else
        idx = tmp;

    for(int i = 1; i < n; i++)
        if(i <= idx)
        {
            if(arr[i] <= arr[i-1])
                return false;
        }
        else
        {
            if(arr[i] >= arr[i-1])
                return false;
        }

    return true;
}

//官方解答
bool validMountainArray(vector<int> &arr)
{
    const int n = arr.size();
    int i = 0;

    //walk up
    while(i+1 < n and arr[i] < arr[i+1])
        i++;
    
    //peak cannot be first or last
    if(i == 0 or i == n-1)
        return false;
    
    //walk down
    while(i+1 < n and arr[i] > arr[i+1])
        i++;

    return i == n-1;
}

int main()
{
    vector<int> arr = {1,1,1,1,1,1,1,2,1};
    bool ans = validMountainArray(arr);

    cout << ans << endl;

    return 0;
}