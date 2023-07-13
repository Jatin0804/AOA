//#define min(a,b,c) ((a<b) ? (a<c?a:c) : (b<c?b:c))
#include<stdio.h>
#include<stdarg.h>

int min(int cnt,...)
{
    va_list ap;
    int i, current, minimum;
    va_start(ap, cnt);
    minimum = 99999;
    for (i=0;i<cnt;i++){
        current = va_arg(ap, int);
        if (current < minimum)
            minimum = current;
    }
    va_end(ap);
    return minimum;
}

int main()
{
    int f=100,j=200,k=30;
    //int result=min(f,j,k);
    int arr[10];
    arr[0]=15;
    arr[1]=2;
    arr[2]=14;
    arr[3]=11;
    arr[4]=12;
    arr[5]=10;
    arr[6]=17;
    arr[7]=13;
    arr[8]=100;
    arr[9]=12;
    arr[10]=5;
    int res1=min(10,(for(int i=0;i<10;i++)arr[i];));
    printf("%d",res1);
}

/*
#include <stdio.h>
#include <stdarg.h>
int sum (int cnt,...) {
    va_list ap;
    int i, n;
    va_start(ap, cnt);
    n = 0;
    for (i=0;i<cnt;i++){
        n += va_arg(ap, int);
     }
    va_end(ap);
    return n;
}
int min(int cnt,...) {
    va_list ap;
    int i, current, minimum;
    va_start(ap, cnt);
    minimum = 99999;
    for (i=0;i<cnt;i++){
        current = va_arg(ap, int);
        if (current < minimum)
            minimum = current;
    }
    va_end(ap);
    return minimum;
}
int max(int cnt,...) {
    va_list ap;
    int i, current, maximum;
    va_start(ap, cnt);
    maximum = 0;
    for (i=0;i<cnt;i++){
        current = va_arg(ap, int);
        if (current > maximum)
            maximum = current;
    }
    va_end(ap);
    return maximum;
}
int main(){
    printf("%d",sum(5, 5, 2, 8, 9, 3));
    printf("%d",max(3, 5, 9, 2));
    printf("%d",min(6, 8, 5, 2, 6, 7, 9));
}*/
