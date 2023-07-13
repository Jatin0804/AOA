#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>

void compute_prefix(char *text)
{
    int m=strlen(text);
    int pi[m];
    pi[1]=0;
    //pi[0]=0;
    int k=0;

    for(int q=2 ;q<m;q++)
    {
        while(k>0 && text[k+1]!=text[q])
        {
            k=pi[k];
        }
        if(text[k+1]==text[q])
        {
            k++;
        }
        pi[q]=k;
    }
    printf("Prefix values are :\t");
    for(int i=1;i<m;i++)
    cout<<pi[i]<<"\t";
}

int main(void)
{
    char text[10];
    text[0]='0';
    cout<<"Enter string :";
    for(int i=1;i<10;i++)
    cin>>text[i];
    cout<<"String is : "<<text<<endl;
    compute_prefix(text);

    return 0;
}