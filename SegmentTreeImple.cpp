/*
*  Segment Tree Impletation using prefixArray and Queue.
*/

#include<bits/stdc++.h>

using namespace std;

vector<int> seg;  //segmentTree Array
int preArr[6];   //Prefix Sum Array

queue < pair<int,int> > temp;

void util(int l, int h)
{

    //when only single elment
    if(l==h)
    {
        if(l==0)
        {
            seg.push_back(preArr[l]);
            return;
        }
        seg.push_back(preArr[l] - preArr[l-1]);
        return;
    }

    //when l!=h
    if(l==0)
    {
        seg.push_back(preArr[h]);
        return;
    }
    seg.push_back(preArr[h]- preArr[l-1]);
    return;

}

void makeSegTree(int l, int h)
{
    //push first element
    temp.push(make_pair(l,h));


    while(!temp.empty())
    {

        int a,b;
        a = temp.front().first;
        b = temp.front().second;

        util(a,b);

        if(a <  b)
        {
            int mid = (a + b)/2;
            temp.push(make_pair(a,mid));
            temp.push(make_pair(mid+1,b));
        }

        temp.pop();

    }



}

int main()
{
    int arr[]={1,3,5,7,9,11};

    preArr[0]=arr[0];
    for(int i=1;i<6;i++)
    {
        preArr[i] = preArr[i-1] + arr[i];
    }

    makeSegTree(0,5);

    //Output Segment Tree Array.
    for(int i=0;i<seg.size();i++)
    {
        cout << seg[i] <<  " ";
    }

