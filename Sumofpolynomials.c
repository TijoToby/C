#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

struct poly1[100], poly2[100], poly3[100];

void sum(struct poly arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i>0&&arr[i].coeff > 0) {
            printf("+");
        }
        printf("%d(x^%d)", arr[i].coeff, arr[i].exp);
}
    printf("\n");
}

int main() {
    int i = 0, j = 0, k = 0, n1, n2;

    printf("Enter the number of terms of Poly1:\t");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the Coefficient Part: ");
        scanf("%d", &poly1[i].coeff);
        printf("Enter the Exponent Part: ");
        scanf("%d", &poly1[i].exp);
    }

    printf("Enter the number of terms of Poly2:\t");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the Coefficient Part: ");
        scanf("%d", &poly2[i].coeff);
        printf("Enter the Exponent Part: ");
        scanf("%d", &poly2[i].exp);
    }

    i = j = k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k].exp = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            poly3[k].coeff = poly1[i].coeff;
            poly3[k].exp = poly1[i].exp;
            i++;
            k++;
        } else {
            poly3[k].coeff = poly2[j].coeff;
            poly3[k].exp = poly2[j].exp;
            j++;
            k++;
        }
    }

    while (i < n1) {
        poly3[k].coeff = poly1[i].coeff;
        poly3[k].exp = poly1[i].exp;
        i++;
        k++;
    }

    while (j < n2) {
        poly3[k].coeff = poly2[j].coeff;
        poly3[k].exp = poly2[j].exp;
        j++;
        k++;
    }

    printf("\nSUM IS:\n");
    sum(poly1, n1);
    sum(poly2, n2);
printf("\n___________\n");
    printf("Sum: ");
    sum(poly3, k);

    return 0;
}
