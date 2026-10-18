#include <stdio.h>

int main() {
    int seats[5][8];
    int rowCount, totalCount = 0;

    // Input booking status
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            printf("Enter 0 for empty or 1 for booked, Row %d Seat %d: ",
                   i + 1, j + 1);
            scanf("%d", &seats[i][j]);
        }
    }

    // Display seating map
    printf("\n--- Seating Map ---\n");

    for (int i = 0; i < 5; i++) {
        rowCount = 0;

        for (int j = 0; j < 8; j++) {
            if (seats[i][j] == 0) {
                printf(". ");
                rowCount++;
            } else {
                printf("X ");
            }
        }

        printf("\nFree seats in row %d: %d\n", i + 1, rowCount);
        totalCount += rowCount;
    }

    printf("\nTotal free seats: %d\n", totalCount);

    return 0;
}
