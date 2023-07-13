#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>

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
    int num, j;
    printf("Enter maximum numbers of elements in array : ");
    scanf("%d", &num);
    int array[num], first, last, ran;

    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        ran = rand() % 100;
        array[i] = array[i-1]+ran;
    }

    first = 0;
    last = num - 1;

    // printf("\nEnter element to be searched : ");
    // scanf("%d", &j);

    printf("\nOutput array is : \t");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);

    printf("\nEnter element to be searched : ");
    scanf("%d", &j);

    int result = bin_search(array, first, last, j);

    if (result == -1)
        printf("\n\nElement not found !!!!");
    else
        printf("\n\nElement found at index %d", result);

    return 0;
}