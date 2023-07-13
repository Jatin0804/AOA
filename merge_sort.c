#include<stdio.h>

void merge(int arr[],int first,int last, int mid)
{
    int i,j,k;
    int n1=mid-first+1;
    int n2=last-mid;
    int temp1[n1],temp2[n2];

    for(i=0;i<n1;i++)
    temp1[i] = arr[first + i];
    for (j = 0; j < n1; j++)
    temp2[j] = arr[mid + 1 + j];

    i=0,j=0,k=first;

    while((i<n1) && (j<n2))
    {
        if(temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i++];
        }
        else
        {
            arr[k]=temp2[j++];
        }
        k++;
    }
    while(i<n1)
    {
        arr[k++]=temp1[i++];
    }
    while(j<n2)
    {
        arr[k++]=temp2[j++];
    }
}

void merge_sort(int arr[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        merge_sort(arr,first,mid);
        merge_sort(arr,mid+1,last);
        merge(arr,first,last,mid);
    }
}

int main(void)
{
    int n;
    printf("Enter maximum number of array to be sorted : ");
    scanf("%d",&n);
    int arr[n];
    // printf("Enter the elements of array : ");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&arr[i]);

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("\nThe input array is : ");
    for(int i=0;i<n;i++)
        printf("\t%d",arr[i]);
        
    merge_sort(arr,0,n-1);

    printf("\nThe Output array is :");
    for (int i = 0; i < n; i++)
        printf("\t%d", arr[i]);

    return 0;
}