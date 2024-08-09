#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    vector<int> ct(n,0);
    vector<pair<int,pair<int,int>>> arr(n);
    vector<int> at(n),bt(n);
    for(i=0;i<n;i++)
    {
        cin>>at[i];
        cin>>bt[i];
    }
    for(i=0;i<n;i++)
       {
           arr[i].first=at[i];
           arr[i].second.first=bt[i];
           arr[i].second.second=i;
       }

    sort(arr.begin(),arr.end());
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    int counter=arr[0].first;
    i=0;
    while(i<n||!pq.empty())
    {
        while(i<n&&counter>=arr[i].first)
        {
            pq.push({arr[i].second.first,{arr[i].first,arr[i].second.second}});
            i++;
        }
        if(!pq.empty())
        {
            counter+=pq.top().first;
            ct[pq.top().second.second]=counter;
            pq.pop();
        }
        else if(i<n)
        {
            counter++;
        }
    }
      for(i=0;i<n;i++)
        {
            cout<<ct[i]<<endl;
        }
}
