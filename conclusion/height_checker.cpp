#include <bits/stdc++.h>

using namespace std;

int heightChecker1(vector<int> &heights)
{
    vector<int> sort_h;
    sort_h.assign(heights.begin(), heights.end());
    sort(sort_h.begin(), sort_h.end());

    int cnt = 0;
    for(int i = 0; i < heights.size(); i++)
        cnt += (sort_h[i] != heights[i]);

    return cnt;
}

//其他人的作法是用counting sort
int heightChecker(vector<int> &heights)
{
    int cnt = 0;
    vector<int> counting(101);
    for(int h : heights)
        counting[h]++;

    int i = 1, j = 0;
    while(i < 101)
    {
        if(counting[i] == 0)
            i++;
        else
        {
            if(i != heights[j])
                cnt++;
            j++;
            counting[i]--;
        }
    }

    return cnt;
}

int main()
{
    vector<int> h = {1,1,4,2,1,3};
    int ans = heightChecker(h);

    cout << ans << endl;

    return 0;
}