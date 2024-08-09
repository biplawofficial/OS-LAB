#include <bits/stdc++.h>
using namespace std;
#define timequantum 2
#define ll long long
#define vi vector<int>
#define mp map<int, int>
void RR(vi at, vi bt)
{
    cout << "b1-entered function" << endl;
    multimap<int, int> mmap;
    queue<pair<int, pair<int, int>>> qt;
    int i, n = at.size();
    vi ct(n), tat(n), wt(n);
    for (i = 0; i < n; i++)
        mmap.insert({at[i], bt[i]});
    int j = 0;
    for (auto it = mmap.begin(); it != mmap.end(); it++)
    {
        qt.push({j++, {it->first, it->second}});
    }
    int timer = qt.front().second.first;
    cout << "b2-dsa part over logic code starts here" << endl;
    // int a=5;
    // while(a--)
    // {
    //     cout<<qt.front().first<<" "<<qt.front().second.first<<" "<<qt.front().second.second<<endl;
    //     qt.pop();
    // }
    while (!qt.empty())
    {
        if (timer >= qt.front().second.first)
        {
            if (qt.front().second.second - timequantum <= 0)
            {
                timer += qt.front().second.second;
                qt.front().second.second = 0;
                ct[qt.front().first] = timer;
                qt.pop();
            }
            else
            {
                timer += timequantum;
                qt.front().second.second -= timequantum;
                qt.push({qt.front().first, {qt.front().second.first, qt.front().second.second}});
                qt.pop();
            }
        }
        else  
        {
            timer += 1;
             qt.push({qt.front().first, {qt.front().second.first, qt.front().second.second}});
             qt.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ct[i] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vi at(n), bt(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i];
    }

    int k;
    reinput: // goto label for defualt case
    cin >> k;
    switch (k)
    {
    case 1:
    {
        RR(at, bt);
        break;
    }
    default:
        goto reinput;
    }
}