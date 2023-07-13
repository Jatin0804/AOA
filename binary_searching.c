#include <stdio.h>

int main()
{
    int n, i, j, bs[10], mid, first, last, tag = 0;

    printf("Enter total elements : ");
    scanf("%d", &n);

    printf("Enter Values in array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &bs[i]);

    printf("Enter element to be searched : ");
    scanf("%d", &j);
    first = 0;
    last = n - 1;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (bs[mid] == j)
        {
            tag = 1;
            break;
        }
        else if (j > bs[mid])
            first = mid + 1;
        else if (j < bs[mid])
            last = mid - 1;
    }

    if (tag == 1)
        printf("Element found.");
    else
        printf("Element Not found.");

    return 0;
}
