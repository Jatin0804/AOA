#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>
#include <bits\stdc++.h>

int main(void)
{
    int n;
    cout << "Enter max elements of array : ";
    cin >> n;
    int array[n];

    /*cout << "Enter elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }*/

    srand(time(0));
    for(int i=0;i<n;i++)
    {
        array[i]=rand()%100;
    }

    cout<<"Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<"\t";
    }

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 2; j < array[i]; j++)
        {
            if (array[i] % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
            printf("\n%d  is prime number.", array[i]);
    }

    return 0;
}