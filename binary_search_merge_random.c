#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>

void merge(int arr[], int first, int last, int mid)
{
    int i, j, k;
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int temp1[n1], temp2[n2];

    for (i = 0; i < n1; i++)
        temp1[i] = arr[first + i];
    for (j = 0; j < n1; j++)
        temp2[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = first;

    while ((i < n1) && (j < n2))
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k] = temp1[i++];
        }
        else
        {
            arr[k] = temp2[j++];
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = temp1[i++];
    }
    while (j < n2)
    {
        arr[k++] = temp2[j++];
    }
}

void merge_sort(int arr[], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, last, mid);
    }
}

int bin_search(int array[], int first, int last, int j)
{
    int mid;
    while (first <= last)
    {

        mid = (first + last) / 2;
        if (array[mid] == j)
        {
            return mid;
        }
        else if (j > array[mid])
            first = mid + 1;
        else if (j < array[mid])
            last = mid - 1;
    }
    return -1;
}

int main(void)
{
    //time_t begin = time(NULL);
    int num, j;
    printf("Enter maximum numbers of elements in array : ");
    scanf("%d", &num);
    int array[num], first, last, ran;
    /*printf("Enter elements of array: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }*/

    srand(time(0));
    for(int i=0;i<num;i++)
    {
        ran=rand()%1000;
        array[i]=ran;
    }

    printf("\nEntered array is : \t");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);
    first = 0;
    last = num - 1;

    merge_sort(array, first, last);

    printf("\nEnter element to be searched : ");
    scanf("%d", &j);

    printf("\nOutput array is : \t");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);

    int result = bin_search(array, first, last, j);

    if (result == -1)
        printf("\n\nElement not found !!!!");
    else
        printf("\n\nElement found at index %d", result);

    // time_t end = time(NULL);
    // printf("\nElapsed time : %d seconds",(end-begin));

    return 0;
}
