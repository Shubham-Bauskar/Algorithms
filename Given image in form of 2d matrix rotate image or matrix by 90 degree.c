#include<stdio.h>
int main()
{
    printf("Enter the Size of Matrix:-\n");
    int n;
    scanf("%d",&n);
    char a[n][n],i,j;
    printf("Enter the elements of Matrix:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf(" %c",&a[i][j]);
    char b[n][n];
    for(i=0;i<n;i++) // First Transpose the matrix
        for(j=0;j<n;j++)
          b[i][j]=a[j][i];
    printf("Transpose of Matrix (or) Rotation by 90` ANTICLOCKWISE:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
    for(i=0;i<n;i++) // Swapping the matrix
    {
        int f=0,l=n-1;
        while(f<l)
        {
            char t=b[i][f];
            b[i][f]=b[i][l];
            b[i][l]=t;
            f++;
            l--;
        }
    }
    printf("ROTATION BY 90` CLOCKWISE:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c",b[i][j]);
        printf("\n");
    }
	getch();
    return 0;
}
