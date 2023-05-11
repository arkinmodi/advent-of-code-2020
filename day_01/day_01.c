#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int day1PartA(char filename[], int numOfExpenses) {
    FILE* inputFile;
    inputFile = fopen(filename, "r");
    if(inputFile == NULL) {
        perror("Failed to open file: ");
        return 1;
    }

    int expenses[numOfExpenses];

    int i = 0;
    char buffer[6];
    while(fgets(buffer, sizeof(buffer) + 1, inputFile) && i < numOfExpenses) {
        expenses[i++] = strtol(buffer, NULL, 10);
    }

    if(fclose(inputFile)) {
        perror("Failed to close file: ");
        return 1;
    }

    for(i = 0; i < numOfExpenses; i++) {
        for(int j = i + 1; j < numOfExpenses; j++) {
            if(expenses[i] + expenses[j] == 2020) {
                printf("Day 1 Part A (%s):\t%d\n", filename, expenses[i] * expenses[j]);
                return 0;
            }
        }
    }
    return 0;
}

int day1PartB(char filename[], int numOfExpenses) {
    FILE* inputFile;
    inputFile = fopen(filename, "r");
    if(inputFile == NULL) {
        perror("Failed to open file: ");
        return 1;
    }

    int expenses[numOfExpenses];

    int i = 0;
    char buffer[6];
    while(fgets(buffer, sizeof(buffer) + 1, inputFile) && i < numOfExpenses) {
        expenses[i++] = strtol(buffer, NULL, 10);
    }

    if(fclose(inputFile)) {
        perror("Failed to close file: ");
        return 1;
    }

    for(i = 0; i < numOfExpenses; i++) {
        for(int j = i + 1; j < numOfExpenses; j++) {
            for(int k = j + 1; k < numOfExpenses; k++) {
                if(expenses[i] + expenses[j] + expenses[k] == 2020) {
                    printf("Day 1 Part B (%s):\t%d\n", filename, expenses[i] * expenses[j] * expenses[k]);
                    return 0;
                }
            }
        }
    }
    return 0;
}

int main() {
    day1PartA("example.txt", 6); // 514579
    day1PartA("input.txt", 200); // 703131

    day1PartB("example.txt", 6); // 241861950
    day1PartB("input.txt", 200); // 272423970

    return 0;
}
