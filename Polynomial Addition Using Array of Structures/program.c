#include <stdio.h>

struct polynomial
{
    int coeff;
    int expo;
};

int main()
{
    struct polynomial x1[50], x2[50], x3[100];
    int m, n;
    int i = 0, j = 0, k = 0;

    // Read first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &m);

    printf("Enter coefficient and exponent in descending order of exponents:\n");
    for (i = 0; i < m; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &x1[i].coeff, &x1[i].expo);
    }

    // Read second polynomial
    printf("\nEnter the number of terms in the second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent in descending order of exponents:\n");
    for (i = 0; i < n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &x2[i].coeff, &x2[i].expo);
    }

    // Initialize indices
    i = 0;
    j = 0;
    k = 0;

    // Polynomial addition
    while (i < m && j < n)
    {
        if (x1[i].expo == x2[j].expo)
        {
            x3[k].coeff = x1[i].coeff + x2[j].coeff;
            x3[k].expo = x1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (x1[i].expo > x2[j].expo)
        {
            x3[k] = x1[i];
            i++;
            k++;
        }
        else
        {
            x3[k] = x2[j];
            j++;
            k++;
        }
    }

    // Copy remaining terms of first polynomial
    while (i < m)
    {
        x3[k] = x1[i];
        i++;
        k++;
    }

    // Copy remaining terms of second polynomial
    while (j < n)
    {
        x3[k] = x2[j];
        j++;
        k++;
    }

    // Display first polynomial
    printf("\nFirst Polynomial:\n");
    for (i = 0; i < m; i++)
    {
        printf("%dx^%d", x1[i].coeff, x1[i].expo);
        if (i != m - 1)
            printf(" + ");
    }

    // Display second polynomial
    printf("\n\nSecond Polynomial:\n");
    for (i = 0; i < n; i++)
    {
        printf("%dx^%d", x2[i].coeff, x2[i].expo);
        if (i != n - 1)
            printf(" + ");
    }

    // Display resultant polynomial
    printf("\n\nResultant Polynomial:\n");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d", x3[i].coeff, x3[i].expo);
        if (i != k - 1)
            printf(" + ");
    }

    printf("\n");

    return 0;
}
