#include <bits/stdc++.h>

using namespace std;

void duplicateZeros1(vector<int> &arr)
{
    const int n = arr.size();
    vector<int> idx;

    for(int i = 0; i < n; i++)
        if(arr[i] == 0 and i != n-1)
            idx.push_back(i);
    
    for(int i = 0; i < idx.size(); i++)
        arr.insert(arr.begin()+i+idx[i], 0);

    while(arr.size() != n)
        arr.pop_back();
}

void duplicateZeros2(vector<int> &arr)
{
    const int n = arr.size();

    for(int i = 0; i < n; i++)
        if(arr[i] == 0)
        {
            arr.insert(arr.begin()+i, 0);
            i++;
        }
    
    while(arr.size() != n)
        arr.pop_back();
}

//其他人的寫法(這個寫法很屌)
void duplicateZeros(vector<int> &arr)
{
    const int n = arr.size();
    int j = n + count(arr.begin(), arr.end(), 0);

    //當arr[i] = 0的時候, j會-2
    //當arr[i] != 0的時候, j會-1 (因為在第2個if時, arr[i] == 0就不符合條件)
    //所以--j不會執行
    for(int i = n-1; i >= 0; i--)
    {
        //當j在arr.size()內，把arr往前推移
        if(--j < n)
            arr[j] = arr[i];
        //當arr[i] == 0時, 因為要插0, 所以j要在多推移一格
        if(arr[i] == 0 and --j < n)
            arr[j] = 0;
    }
}

int main()
{
    vector<int> arr = {1,0,2,3,0,4,5,0};
    duplicateZeros(arr);

    for(int a : arr)
        cout << a << endl;

    return 0;
}