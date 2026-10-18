
#include <stdio.h>

int main() {
    float temp[7][4];
    float hottest, coldest, noonTotal = 0, noonAverage;

    int hottestDay = 0, coldestDay = 0;
    int hottestTime = 0, coldestTime = 0;

    char *timeName[4] = {"Morning", "Noon", "Evening", "Night"};

    // Input temperatures
    for (int days = 0; days < 7; days++) {
        printf("\nEnter temperatures for Day %d:\n", days + 1);

        for (int time = 0; time < 4; time++) {
            printf("%s: ", timeName[time]);
            scanf("%f", &temp[days][time]);
        }
    }

    // Initialize hottest and coldest temperatures
    hottest = temp[0][0];
    coldest = temp[0][0];

    // Find hottest, coldest and total noon temperature
    for (int days = 0; days < 7; days++) {
        for (int time = 0; time < 4; time++) {

            if (temp[days][time] > hottest) {
                hottest = temp[days][time];
                hottestDay = days;
                hottestTime = time;
            }

            if (temp[days][time] < coldest) {
                coldest = temp[days][time];
                coldestDay = days;
                coldestTime = time;
            }
        }

        noonTotal += temp[days][1];
    }

    // Calculate weekly average noon temperature
    noonAverage = noonTotal / 7;

    // Display results
    printf("\nHottest temperature: %.2f", hottest);
    printf("\nRecorded on Day %d (%s)",
           hottestDay + 1, timeName[hottestTime]);

    printf("\n\nColdest temperature: %.2f", coldest);
    printf("\nRecorded on Day %d (%s)",
           coldestDay + 1, timeName[coldestTime]);

    printf("\n\nWeekly average noon temperature: %.2f\n",
           noonAverage);

    // Display days with noon temperature above average
    printf("\nDays with noon temperature above average:\n");

    for (int days = 0; days < 7; days++) {
        if (temp[days][1] > noonAverage) {
            printf("Day %d: %.2f\n",
                   days + 1, temp[days][1]);
        }
    }

    return 0;
}
