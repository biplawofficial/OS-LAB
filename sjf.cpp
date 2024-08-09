#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    vector<int> ct(n,0);
    multimap<int,int> mts;
    vector<int> at(n),bt(n);
    for(i=0;i<n;i++)
    {
        cin>>at[i];
        cin>>bt[i];
    }
    for(i=0;i<n;i++)
    {
        mts.insert({at[i],bt[i]});
    }
    vector<pair<int,int>> arr(mts.begin(),mts.end());
    vector<pair<int,pair<int,int>>> arr2;
    for(int i=0;i<n;i++)
    {
        arr2.push_back({arr[i].first,{arr[i].second,i}});
    }
    vector<pair<int,pair<int,int>>> temp;
    int counter=arr2[0].first;
    i=0;
    while(i!=n)
    {
        int tobedel;
        for(int j=0;j<n-i;j++)
        {
            if(arr2[j].first<=counter)
            {
                temp.push_back({arr2[j].second.first,{arr2[j].first,arr2[j].second.second}});
            }
        }
        if(temp.size()>0)
        {
        sort(temp.begin(),temp.end());
        tobedel=temp[0].second.second;
        counter+=temp[0].first;
        ct[tobedel]=counter;
        for(int k=0;k<n-i;k++)
        {
            if(arr2[k].second.second==tobedel)
            {
                arr2.erase(arr2.begin()+k);
                i++;
                break;
            }
        }
        }
        else
        counter++;
        temp.clear();
    }  
    for(int i=0;i<n;i++)
    {
        cout<<"ct="<<ct[i]<<" "<<endl;
    }
}