/**
 * Copyright (C), 2024-07-16
 * @author LinXun
 * @date 24-7-16 下午4:20
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;

int er[100];
bool ck(int cnt, vector<int> num, int D)
{
    if (cnt==0)
        return 1;
    vector<int> v;
    for (int i=0; i<=20; i++)
    {
        if (D%2)
            v.push_back(i);
        D/=2;
    }

    bool f=1;
    for (int i=20; i>=0 && cnt>0 && v.size(); i--)
    {
        if (i != v.back())
        {
            cnt -= num[i];
            num[i] = 0;
            continue;
        }
        int need = cnt * er[i];
        for (int j=i; j>=0 && need>0; j--)
        {
            int used = (need + er[j]-1) / er[j];
            used = min(used, num[j]);
            num[j] -= used;
            need -= used * er[j];
        }
        v.pop_back();
        cnt -= num[i];
        if (need > 0)
        {
            f = 0;
            break;
        }
    }
    return f;
}

signed main()
{
    cin>>n;
    er[0] = 1;
    for (int i=1; i<=25; i++)
        er[i] = er[i-1]*2;
    vector<int> num(25);
    for (int i=0; i<=n; i++)
        cin>>num[i];
    int D;
    cin>>D;
    int l=0, r=3e12;
    int ans=l;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (ck(mid, num, D))
        {
            ans = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
