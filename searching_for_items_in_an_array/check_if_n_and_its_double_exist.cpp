#include <bits/stdc++.h>

using namespace std;

bool checkIfExist(vector<int> &arr)
{
    vector<int>::iterator it;
    for(int i = 0; i < arr.size(); i++)
    {
        it = find(arr.begin(), arr.end(), arr[i]*2);
        int idx = distance(arr.begin(), it);
        if(it != arr.end() and idx != i)
            return true;
    }
    
    return false;
}

int main()
{
    vector<int> arr = {-2,0,10,-19,4,6,-8};
    bool ans = checkIfExist(arr);

    //cout << ans << endl;

    return 0;
}