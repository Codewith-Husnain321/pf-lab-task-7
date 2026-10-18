
#include <stdio.h>

int main() {
    int rooms[4][6];
    int vacantCount, maxVacancies = 0;
    int floorIndex = 0;
    int consecutive = 0, found = 0;

    // Input room occupancy
    for (int floor = 0; floor < 4; floor++) {
        printf("\nEnter occupancy for Floor %d (1 = Occupied, 0 = Vacant):\n",
               floor + 1);

        for (int room = 0; room < 6; room++) {
            printf("Room %d: ", room + 1);
            scanf("%d", &rooms[floor][room]);
        }
    }

    // Find the floor with the most vacant rooms
    for (int floor = 0; floor < 4; floor++) {
        vacantCount = 0;

        for (int room = 0; room < 6; room++) {
            if (rooms[floor][room] == 0) {
                vacantCount++;
            }
        }

        printf("Floor %d has %d vacant rooms.\n",
               floor + 1, vacantCount);

        if (vacantCount > maxVacancies) {
            maxVacancies = vacantCount;
            floorIndex = floor;
        }
    }

    printf("\nFloor with most vacancies: %d\n", floorIndex + 1);
    printf("Number of vacant rooms: %d\n", maxVacancies);

    // Find 3 or more consecutive vacant rooms
    printf("\n--- Consecutive Vacant Rooms ---\n");

    for (int floor = 0; floor < 4; floor++) {
        consecutive = 0;

        for (int room = 0; room < 6; room++) {
            if (rooms[floor][room] == 0) {
                consecutive++;

                if (consecutive >= 3 && consecutive == 3) {
                    printf("Floor %d: Starting room %d\n",
                           floor + 1, room - 1);
                    found = 1;
                }
            } else {
                consecutive = 0;
            }
        }
    }

    if (found == 0) {
        printf("No floor has 3 or more consecutive vacant rooms.\n");
    }

    return 0;
}
