
#include <stdio.h>

int main() {
    char titles[5][50];
    int copies[5];
    int vowels, maxCopies, maxIndex = 0;
    char letter;
    int found;

    // Input book details
    for (int i = 0; i < 5; i++) {
        printf("Enter title of book %d: ", i + 1);
        scanf(" %[^\n]", titles[i]);

        printf("Enter number of copies: ");
        scanf("%d", &copies[i]);
    }

    // Display catalog
    printf("\n--- Library Catalog ---\n");
    printf("%-30s %s\n", "Title", "Copies");

    for (int i = 0; i < 5; i++) {
        printf("%-30s %d\n", titles[i], copies[i]);
    }

    // Count vowels in each title
    printf("\n--- Vowel Count ---\n");

    for (int i = 0; i < 5; i++) {
        vowels = 0;

        for (int j = 0; titles[i][j] != '\0'; j++) {
            if (titles[i][j] == 'a' || titles[i][j] == 'e' ||
                titles[i][j] == 'i' || titles[i][j] == 'o' ||
                titles[i][j] == 'u' || titles[i][j] == 'A' ||
                titles[i][j] == 'E' || titles[i][j] == 'I' ||
                titles[i][j] == 'O' || titles[i][j] == 'U') {
                vowels++;
            }
        }

        printf("%s: %d vowels\n", titles[i], vowels);
    }

    // Search titles by starting letter
    printf("\nEnter a letter to search titles: ");
    scanf(" %c", &letter);

    found = 0;

    for (int i = 0; i < 5; i++) {
        if (titles[i][0] == letter ||
            titles[i][0] == letter - 'a' + 'A' ||
            titles[i][0] == letter - 'A' + 'a') {
            printf("%s\n", titles[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No titles start with that letter.\n");
    }

    // Find title with the most copies
    maxCopies = copies[0];

    for (int i = 1; i < 5; i++) {
        if (copies[i] > maxCopies) {
            maxCopies = copies[i];
            maxIndex = i;
        }
    }

    printf("\nBook with the most copies: %s\n", titles[maxIndex]);
    printf("Number of copies: %d\n", maxCopies);

    return 0;
}
