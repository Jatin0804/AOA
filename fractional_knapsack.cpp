#include<bits/stdc++.h>
using namespace std;

struct item
{
    int value,weight;

    item(int value,int weight)
    {
        this->value=value;
        this->weight=weight;
    }
};

bool cmp(struct item a,struct item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}

double fractional(int w,struct item arr[],int N)
{
    sort(arr,arr+N,cmp);

    double finalvalue=0.0;
    
}