#include <stdio.h>
#include <stdlib.h>
///Using dynamic memory allocation where is the case, solve the following:
///1. Multiply 2 matrices of integers.

void citire(int **mat, int l, int c)
{
    int i, j;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++)
    {
        printf("mat[%d][%d]=", i, j);
        scanf("%d", &mat[i][j]);
    }

}


int main()
{
    int n1, m1,i,j,k,n2,m2,suma;
    printf("Dati nr. de linii: ");
    scanf("%d", &n1);
    printf("Dati nr. de coloane: ");
    scanf("%d", &m1);
    int ** mat1=(int**)malloc(n1*sizeof(int*));
    for(i=0;i<n1;i++)
        mat1[i]=(int*)malloc(m1*sizeof(int));
    citire(mat1, n1, m1);
    printf("Dati nr. de linii: ");
    scanf("%d", &n2);
    printf("Dati nr. de coloane: ");
    scanf("%d", &m2);
    int** mat2=(int**)malloc(n2*sizeof(int*));
    for(i=0;i<n2;i++)
        mat2[i]=(int*)malloc(m2*sizeof(int));
    citire(mat2, n2, m2);
    if(m1!=n2) printf("Nu se poate face inmultirea celor 2 matrici!");
        else {
        ///mat3 este matricea rezultata
            int ** mat3=(int**)malloc(n1*sizeof(int*));
             for(i=0;i<n1;i++)
                 mat3[i]=(int*)malloc(m2*sizeof(int));
        ///se inmultesc matricile
        for(i=0;i<n1;i++)
        {
            for(k=0;k<m2;k++)
            {
                suma=0;
                for(j=0;j<m1;j++)
                    suma+=mat1[i][j]*mat2[j][k];
                mat3[i][k]=suma;
            }
        }
        printf("Produsul este:\n");
        for(i=0;i<n1;i++)
        {
            for(j=0;j<m2;j++)
                printf("%d ", mat3[i][j]);
            printf("\n");
        }
        for(i=0;i<n1;i++)
            free(mat3[i]);
        free(mat3);//delocam memoria
        }
     for(i=0;i<n1;i++)
            free(mat1[i]);
        free(mat1);
    for(i=0;i<n2;i++)
            free(mat2[i]);
        free(mat2);
    return 0;
}
