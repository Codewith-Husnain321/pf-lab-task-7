
#include <stdio.h>

int main() {
    float sales[3][5];
    float totalSales, branchTotal[3];
    float productTotal, lowestSales;
    int bestBranch = 0, lowestProduct = 0;

    // Input sales
    for (int branch = 0; branch < 3; branch++) {
        for (int product = 0; product < 5; product++) {
            printf("Enter sales for branch %d, product %d: ",
                   branch + 1, product + 1);
            scanf("%f", &sales[branch][product]);
        }
    }

    // Total sales per branch
    printf("\n--- Total Sales Per Branch ---\n");

    for (int branch = 0; branch < 3; branch++) {
        totalSales = 0;

        for (int product = 0; product < 5; product++) {
            totalSales += sales[branch][product];
        }

        branchTotal[branch] = totalSales;

        printf("Branch %d: %.2f\n", branch + 1, totalSales);
    }

    // Find best-selling branch
    float highestSales = branchTotal[0];

    for (int branch = 1; branch < 3; branch++) {
        if (branchTotal[branch] > highestSales) {
            highestSales = branchTotal[branch];
            bestBranch = branch;
        }
    }

    printf("\nBest-selling branch: %d\n", bestBranch + 1);
    printf("Total sales: %.2f\n", highestSales);

    // Total sales per product
    printf("\n--- Total Sales Per Product ---\n");

    lowestSales = sales[0][0] + sales[1][0] + sales[2][0];

    for (int product = 0; product < 5; product++) {
        productTotal = 0;

        for (int branch = 0; branch < 3; branch++) {
            productTotal += sales[branch][product];
        }

        printf("Product %d: %.2f\n", product + 1, productTotal);

        if (productTotal < lowestSales) {
            lowestSales = productTotal;
            lowestProduct = product;
        }
    }

    printf("\nLowest-selling product: %d\n", lowestProduct + 1);
    printf("Total sales: %.2f\n", lowestSales);

    return 0;
}
