#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void swap(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void bsort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[j]>A[j+1])
            swap(A[j],A[j+1]);
        }
    }
}

void bsearch(int A[],int n,int t,long tim)
{
    time -t,tim;
    long time1;
    int low,mid,high;
    low=0;
    high=n;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(t=A[mid])
        {
            cout<<"\n Search Complete and element found.";
            break;
        }
        else if(t<A[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    if(low>high)
    cout<<"\n Search unsuccessful.";
    tim=time(NULL);
    time1=tim;
    cout<<"\nTime taken : "<<time1-tim<<" nanoseconds.";
}

int main(void)
{
    int A[10000],n,s,ran,t;
    long tim;
    time -t,t;
    cout<<"Enter number of elemenst in arrray :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ran=rand()%1000+1;
        A[i]=ran;
    }
    cout << "Input array is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<A[i];
    }
    bsort(A,n);
    t=time(NULL);
    tim=t;
    cout<<"\n Enter element to search : ";
    cin>>s;
    cout << "\n Output array is :";
    for (int i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
    bsearch(A,n,s,tim);
    return 0;
}