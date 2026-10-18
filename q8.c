
#include <stdio.h>

int main() {
    int stock[3][4][5];
    int totalStock, fullestShelf = 0;
    int fullestBuilding = 0, maxStock = -1;
    int shelfTotal;

    // Input stock
    for (int b = 0; b < 3; b++) {
        printf("\nBuilding %d\n", b + 1);

        for (int s = 0; s < 4; s++) {
            for (int sl = 0; sl < 5; sl++) {
                printf("Shelf %d, Slot %d: ",
                       s + 1, sl + 1);
                scanf("%d", &stock[b][s][sl]);
            }
        }
    }

    // Total stock per building
    printf("\n--- Total Stock Per Building ---\n");

    for (int b = 0; b < 3; b++) {
        totalStock = 0;

        for (int s = 0; s < 4; s++) {
            for (int sl = 0; sl < 5; sl++) {
                totalStock += stock[b][s][sl];
            }
        }

        printf("Building %d: %d items\n",
               b + 1, totalStock);
    }

    // Find the fullest shelf
    for (int b = 0; b < 3; b++) {
        for (int s = 0; s < 4; s++) {
            shelfTotal = 0;

            for (int sl = 0; sl < 5; sl++) {
                shelfTotal += stock[b][s][sl];
            }

            if (shelfTotal > maxStock) {
                maxStock = shelfTotal;
                fullestBuilding = b;
                fullestShelf = s;
            }
        }
    }

    printf("\nFullest shelf: Building %d, Shelf %d\n",
           fullestBuilding + 1, fullestShelf + 1);
    printf("Total items: %d\n", maxStock);

    // Find slots needing restock
    printf("\n--- Slots Needing Restock ---\n");

    for (int b = 0; b < 3; b++) {
        for (int s = 0; s < 4; s++) {
            for (int sl = 0; sl < 5; sl++) {
                if (stock[b][s][sl] < 5) {
                    printf("Building %d, Shelf %d, Slot %d"
                           " [ %d ][ %d ][ %d ]: needs restock\n",
                           b + 1, s + 1, sl + 1,
                           b, s, sl);
                }
            }
        }
    }

    return 0;
}
