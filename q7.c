
#include <stdio.h>

int main() {
    int marks[3][4][5];
    float studentAverage, departmentTotal;
    float departmentAverage[3];
    float highestAverage;
    int topperIndex, highestDepartment = 0;
    int fail;

    // Input marks
    for (int d = 0; d < 3; d++) {
        printf("\nDepartment %d\n", d + 1);

        for (int s = 0; s < 4; s++) {
            printf("Student %d:\n", s + 1);

            for (int sub = 0; sub < 5; sub++) {
                printf("Subject %d marks: ", sub + 1);
                scanf("%d", &marks[d][s][sub]);
            }
        }
    }

    // Student averages and department toppers
    for (int d = 0; d < 3; d++) {
        departmentTotal = 0;
        highestAverage = -1;
        topperIndex = 0;

        printf("\n--- Department %d ---\n", d + 1);

        for (int s = 0; s < 4; s++) {
            studentAverage = 0;
            fail = 0;

            for (int sub = 0; sub < 5; sub++) {
                studentAverage += marks[d][s][sub];

                if (marks[d][s][sub] < 40) {
                    fail = 1;
                }
            }

            studentAverage /= 5;
            departmentTotal += studentAverage;

            printf("Student %d average: %.2f",
                   s + 1, studentAverage);

            if (fail == 1) {
                printf(" FAIL");
            }

            printf("\n");

            if (studentAverage > highestAverage) {
                highestAverage = studentAverage;
                topperIndex = s;
            }
        }

        departmentAverage[d] = departmentTotal / 4;

        printf("Department topper: Student %d\n",
               topperIndex + 1);
        printf("Topper average: %.2f\n", highestAverage);
        printf("Department average: %.2f\n",
               departmentAverage[d]);
    }

    // Find department with highest average
    highestAverage = departmentAverage[0];

    for (int d = 1; d < 3; d++) {
        if (departmentAverage[d] > highestAverage) {
            highestAverage = departmentAverage[d];
            highestDepartment = d;
        }
    }

    printf("\nDepartment with highest average: %d\n",
           highestDepartment + 1);
    printf("Overall average: %.2f\n", highestAverage);

    return 0;
}
