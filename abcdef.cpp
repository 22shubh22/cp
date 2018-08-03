//binary search

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    int res=0;   //stores result

    long long s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&s[i]);
    }

    vector<long long> s1;
    vector<long long> s2;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                s1.push_back(s[i]*s[j] + s[k]);
                if(s[k]!=0)
                {
                    s2.push_back((s[i]+s[j]) * s[k]);
                }
            }
        }
    }

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    int low=0,up=0;

    for(int i=0;i<s1.size();i++)
    {

        low = lower_bound(s2.begin(),s2.end(),s1[i]) - s2.begin();
        up = upper_bound(s2.begin(),s2.end(),s1[i]) - s2.begin();
        res+=(up-low);

    }
    printf("%d",res);


}

