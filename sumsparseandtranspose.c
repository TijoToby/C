#include <stdio.h>

int main() {
    int r, len = 0, c;

    printf("Enter number of rows of matrix A: ");
    scanf("%d", &r);

    printf("Enter number of columns of matrix A: ");
    scanf("%d", &c);

    int a[10][10];
    printf("Enter elements of the matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix A is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    int r2, c2;
    printf("Enter number of rows of matrix B: ");
    scanf("%d", &r2);

    printf("Enter number of columns of matrix B: ");
    scanf("%d", &c2);

    int b[10][10];
    printf("Enter elements of the matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatrix B is:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    int f[10][10] = {0};  

    if (r == r2 && c == c2) {
        printf("Sum of the matrices is:\n");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                f[i][j] = a[i][j] + b[i][j];
                printf("%d\t", f[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("We can't add these two matrices\n");
        return 1; 
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (f[i][j] != 0) {
                len = len + 1;
            }
        }
    }

    printf("\nMatrix S:\n");

    int d[len + 1][3];
    d[0][0] = r;
    d[0][1] = c;
    d[0][2] = len;

    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (f[i][j] != 0) {
                d[k][0] = i;
                d[k][1] = j;
                d[k][2] = f[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose of Sparse Matrix:\n");

    int e[len + 1][3];
    e[0][0] = c;
    e[0][1] = r;
    e[0][2] = len;

    k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (f[i][j] != 0) {
                e[k][0] = j;
                e[k][1] = i;
                e[k][2] = f[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", e[i][j]);
        }
        printf("\n");
    }

    return 0;
}