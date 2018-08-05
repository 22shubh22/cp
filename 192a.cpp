//binary search

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld",&n);

    vector < long long > a;
    //i can only take value till 10^5

    //push no. in array a, then search for acomp using binary_search

    for(long long int i=1;i<=100000;i++)
    {
        a.push_back((i*(i+1))/2);
    }

    int flag=0;

    for(long long int i=1;i<=100000;i++)
    {
        long long acomp = n - ((i*(i+1))/2);
        if(binary_search(a.begin(),a.end(),acomp))
        {
            flag=1;
            break;
        }

    }
    if(flag==1)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }


}
