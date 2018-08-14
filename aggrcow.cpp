#include<bits/stdc++.h>
#include<climits>

using namespace std;

int n;
int c;

int F(int x,int a[])
{
    int current=0;
    int tempc=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-a[current]>=x)
        {
            current=i;
            tempc++;
            if(tempc==c){ return 1;}
        }
    }
    return 0;
}

int main()
{
    int t;         // total test case
    cin >> t;

    while(t--)
    {
        cin >> n >> c;
        int a[n];

        for(int i=0;i<n;i++)
        { cin >> a[i];}

        sort(a,a+n);

        int low=1;
        int high=a[n-1]-a[0];  //Minimun seperation between cows very from 1 to (a[n-1]-a[0])

        //why high = a[n-1]-a[0]  ?

        while(low<high)
        {
            int mid=(low+high)/2;
            if(mid==low){ break;}
            F(mid,a)?low=mid:high=mid; //F(mid,a)?low=mid:high=mid;
        }

        cout << low << endl;

    }
    }
