#include<stdio.h>

void quicksort(int array[],int first,int last)
{
    int low=first,high=last,pivot,temp;
    pivot=array[high];

    do
    {
        while(array[low]<pivot)
        low++;
        while(array[high]>pivot)
        high--;

        if(low<=high)
        {
            temp=array[low];
            array[low]=array[high];
            array[high]=temp;
            low++;
            high--;
        }
    } while (low<=high);
    
    if(first<high)
    quicksort(array,first,high);

    if(low<last)
    quicksort(array,low,last);
}

int main()
{
    int n;
    printf("Enter maximum elements : ");
    scanf("%d",&n);
    int array[n];

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
    array[i] = rand() % 100;
    }

    printf("The given array is : ");
    for(int i=0;i<n;i++)
    printf("\t%d",array[i]);

    quicksort(array,0,n-1);

    printf("\nThe sorted array is : ");
    for(int i=0;i<n;i++)
    printf("\t%d",array[i]);

    return 0;
}