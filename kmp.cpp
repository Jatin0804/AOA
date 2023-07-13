#include<stdio.h>
#include<iostream>
using namespace std;
#include<string.h>

// Fills lps[] for given texttern text[0..M-1]
void computeLPSArray(char *text, int M)
{
    int pref[M];
    // length of the previous longest prefix suffix
    int len = 0;

    pref[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (text[i] == text[len])
        {
            len++;
            pref[i] = len;
            i++;
        }
        else // (text[i] != text[len])
        {
            if (len != 0)
            {
                len = pref[len - 1];

                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                pref[i] = 0;
                i++;
            }
        }
    }
    printf("Prefix array : ");
    for(int i=0;i<M;i++)
    {
        printf(" %d\t",pref[i]);
    }
}

int main(void)
{
    char text[]="abacababcab";
    int M=strlen(text);
    computeLPSArray(text,M);
}