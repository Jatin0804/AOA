#include<bits\stdc++.h>
using namespace std;
#define d 99 

void robin_Search(char *pat,char *txt,int q)
{
    int m=strlen(pat);
    int n=strlen(txt);
    int i,j,p=0,t=0;
    int h=1;

    //value of h
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    //values of hash value of pattern and text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    //slide the pattern over text
    for (i = 0; i <= n - m; i++)
    {
        cout<<p<<"\t"<<t<<endl;
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if(j==m)
            {
                cout<<"Pattern found at index : "<<i<<endl;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main(void)
{
    char txt[]="ABCDABCABC";
    char pat[]="CDAB";

    int q=INT_MAX;

    robin_Search(pat,txt,q);

    return 0;
}