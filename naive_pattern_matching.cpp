#include<bits\stdc++.h>
using namespace std;

void naive(char *pat,char *text)
{
    int m=strlen(pat);
    int n=strlen(text);
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pat[j])
            break;
        }
        if(j==m)
        {
            cout<<"Pattern matched at index : "<<i<<endl;
            continue;
        }
    }
}

int main(void)
{
    char text[]="ABCDCABCDC";
    char pat[]="CDC";
    naive(pat,text);

    return 0;
}