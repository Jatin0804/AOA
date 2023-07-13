#include <stdio.h>
#include <conio.h>
//#define min(a,b,c) ((a<b) ? (a<c?a:c) : (b<c?b:c))
#define min(a,b) ((a<b)?a:b)

int main()
{
    /*printf("Matrix chain multiplication.\n\n");
    int n;
    printf("Number of Matrices : ");
    scanf("%d",&n);
    int row[n], col[n], i = 0;
    printf("Enter Values of 1st matrix.\n");
    printf("Enter Number of Rows :");
    scanf("%d", &row[i]);
    printf("Enter Number of Columns :");
    scanf("%d", &col[i]);
    i++;
    printf("Enter Values of 2nd matrix.\n");
    printf("Enter Number of Rows :");
    scanf("%d", &row[i]);
    printf("Enter Number of Columns :");
    scanf("%d", &col[i]);
    for(i;i<n-1;i)
    {
        if (col[i - 1] != row[i])
        {
            printf("\nSORRY!!, But the multiplication is not possible.");
            break;
        }
        else
        {
            i++;
            printf("Enter Values of matrix %d.\n", i+1);
            printf("Enter Number of Rows :");
            scanf("%d", &row[i]);
            printf("Enter Number of Columns :");
            scanf("%d", &col[i]);
        }
    }
    if (col[i-1] != row[i])
        printf("\nTry Entering same value of Column of matrix %d and row of matrix %d.\n",i,i+1);
    else
    {
        printf("\nThe matrix sizes are : \n");
        for (i = 0; i < n; i++)
        {
            printf("Matrix %d is : %d*%d\n", i + 1, row[i], col[i]);
        }
    }

    int mat[n][n],k[n][n],Pi[n],ki=0,result=10000,mij=0;
    Pi[0]=row[0];
    //Pi[1]=col[0];
    for(int i=1;i<=n;i++)
        Pi[i]=col[i-1];
    for(int i=0;i<=n;i++)
        printf("\n Pi[%d] is : %d",i,Pi[i]);
    */

    int mat[4][4],k[4][4],Pi[4],ki=0,result=10000,mij=0;
    Pi[0]=5;
    Pi[1]=4;
    Pi[2]=1;
    Pi[3]=2;
    Pi[4]=3;

    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            mat[i][j]=0;
            k[i][j]=0;
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(i<j)
            {
                ki=i+1;
                printf("i=%d\t\t"
                       "j=%d\t\t"
                       "i,ki=%d\t\t"
                       "ki+1,j=%d\t\t"
                       "pi[i]=%d\t\t"
                       "pi[ki]=%d\t\t"
                       "pi[j]=%d\n\n",i+1,j+1,mat[i][ki],mat[ki+1][j],Pi[i],Pi[ki],Pi[j+1]);
                mij=(mat[i][ki]+mat[ki+1][j]+(Pi[i]*Pi[ki]*Pi[j+1]));
                result=min(mij,result);
                mat[i][j]=result;
                printf("result  :  %d\n\n",result);
            }
        }
    }

    /*printf("\n\nThe matrix for min scalar products is : \n");
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
*/
    return 0;
}
