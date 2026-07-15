#include <stdio.h>

#define MAX 100

int main()
{
    int A[20][20], B[20][20];
    int tupleA[MAX][3], tupleB[MAX][3], tupleC[MAX][3], tupleT[MAX][3];
    int r, c;
    int i, j, k;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    // Read First Matrix
    printf("\nEnter First Matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&A[i][j]);

    // Read Second Matrix
    printf("\nEnter Second Matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&B[i][j]);

    // Convert First Matrix to Tuple
    k=1;
    tupleA[0][0]=r;
    tupleA[0][1]=c;
    tupleA[0][2]=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(A[i][j]!=0)
            {
                tupleA[k][0]=i;
                tupleA[k][1]=j;
                tupleA[k][2]=A[i][j];
                k++;
                tupleA[0][2]++;
            }
        }
    }

    // Convert Second Matrix to Tuple
    k=1;
    tupleB[0][0]=r;
    tupleB[0][1]=c;
    tupleB[0][2]=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(B[i][j]!=0)
            {
                tupleB[k][0]=i;
                tupleB[k][1]=j;
                tupleB[k][2]=B[i][j];
                k++;
                tupleB[0][2]++;
            }
        }
    }

    // Display First Tuple
    printf("\nFirst Sparse Matrix (Tuple)\n");
    printf("Row\tCol\tValue\n");
    for(i=0;i<=tupleA[0][2];i++)
        printf("%d\t%d\t%d\n",tupleA[i][0],tupleA[i][1],tupleA[i][2]);

    // Display Second Tuple
    printf("\nSecond Sparse Matrix (Tuple)\n");
    printf("Row\tCol\tValue\n");
    for(i=0;i<=tupleB[0][2];i++)
        printf("%d\t%d\t%d\n",tupleB[i][0],tupleB[i][1],tupleB[i][2]);

    // Addition of Tuples
    i=1;
    j=1;
    k=1;

    tupleC[0][0]=r;
    tupleC[0][1]=c;

    while(i<=tupleA[0][2] && j<=tupleB[0][2])
    {
        if(tupleA[i][0]==tupleB[j][0] && tupleA[i][1]==tupleB[j][1])
        {
            tupleC[k][0]=tupleA[i][0];
            tupleC[k][1]=tupleA[i][1];
            tupleC[k][2]=tupleA[i][2]+tupleB[j][2];
            i++;
            j++;
            k++;
        }
        else if(tupleA[i][0]<tupleB[j][0] ||
               (tupleA[i][0]==tupleB[j][0] && tupleA[i][1]<tupleB[j][1]))
        {
            tupleC[k][0]=tupleA[i][0];
            tupleC[k][1]=tupleA[i][1];
            tupleC[k][2]=tupleA[i][2];
            i++;
            k++;
        }
        else
        {
            tupleC[k][0]=tupleB[j][0];
            tupleC[k][1]=tupleB[j][1];
            tupleC[k][2]=tupleB[j][2];
            j++;
            k++;
        }
    }

    while(i<=tupleA[0][2])
    {
        tupleC[k][0]=tupleA[i][0];
        tupleC[k][1]=tupleA[i][1];
        tupleC[k][2]=tupleA[i][2];
        i++;
        k++;
    }

    while(j<=tupleB[0][2])
    {
        tupleC[k][0]=tupleB[j][0];
        tupleC[k][1]=tupleB[j][1];
        tupleC[k][2]=tupleB[j][2];
        j++;
        k++;
    }

    tupleC[0][2]=k-1;

    // Display Result Tuple
    printf("\nResultant Sparse Matrix (Tuple)\n");
    printf("Row\tCol\tValue\n");
    for(i=0;i<=tupleC[0][2];i++)
        printf("%d\t%d\t%d\n",tupleC[i][0],tupleC[i][1],tupleC[i][2]);

    // Transpose Tuple
    tupleT[0][0]=tupleC[0][1];
    tupleT[0][1]=tupleC[0][0];
    tupleT[0][2]=tupleC[0][2];

    k=1;

    for(int col=0;col<c;col++)
    {
        for(i=1;i<=tupleC[0][2];i++)
        {
            if(tupleC[i][1]==col)
            {
                tupleT[k][0]=tupleC[i][1];
                tupleT[k][1]=tupleC[i][0];
                tupleT[k][2]=tupleC[i][2];
                k++;
            }
        }
    }

    // Display Transpose Tuple
    printf("\nTranspose of Resultant Tuple\n");
    printf("Row\tCol\tValue\n");
    for(i=0;i<=tupleT[0][2];i++)
        printf("%d\t%d\t%d\n",tupleT[i][0],tupleT[i][1],tupleT[i][2]);

    return 0;
}
