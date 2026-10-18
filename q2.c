
#include <stdio.h>

int main() {
    int marks[6][4];
    int total;
    float average, subjectTotal, classAverage;
    float bestAverage = -1;
    int bestSubject = 0;

    // Input marks
    for (int student = 0; student < 6; student++) {
        for (int subject = 0; subject < 4; subject++) {
            printf("Enter marks for student %d, subject %d: ",
                   student + 1, subject + 1);
            scanf("%d", &marks[student][subject]);
        }
    }

    // Total and average for each student
    printf("\n--- Student Results ---\n");

    for (int student = 0; student < 6; student++) {
        total = 0;

        for (int subject = 0; subject < 4; subject++) {
            total += marks[student][subject];
        }

        average = total / 4.0;

        printf("Student %d: Total = %d, Average = %.2f\n",
               student + 1, total, average);
    }

    // Class average for each subject
    printf("\n--- Subject Class Averages ---\n");

    for (int subject = 0; subject < 4; subject++) {
        subjectTotal = 0;

        for (int student = 0; student < 6; student++) {
            subjectTotal += marks[student][subject];
        }

        classAverage = subjectTotal / 6.0;

        printf("Subject %d average: %.2f\n",
               subject + 1, classAverage);

        if (classAverage > bestAverage) {
            bestAverage = classAverage;
            bestSubject = subject;
        }
    }

    printf("\nBest-performing subject: %d\n", bestSubject + 1);
    printf("Class average: %.2f\n", bestAverage);

    return 0;
}
