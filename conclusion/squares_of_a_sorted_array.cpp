#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int> &A)
{
    const int n = A.size();
    vector<int> ans(n, 0);
    int l = 0, r = n-1;

    for(int i = n-1; i >= 0; i--)
    {
        if(abs(A[l]) > abs(A[r]))
            ans[i] = A[l]*A[l++];
        else
            ans[i] = A[r]*A[r--];
    }

    return ans;
}

int main()
{
    vector<int> A = {-4,-1,0,3,10};
    vector<int> ans = sortedSquares(A);

    for(int num : ans)
        cout << num << endl;

    return 0;
}