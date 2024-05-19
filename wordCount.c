#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void count_characters(const char *filename);
void count_words(const char *filename);

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] input.txt\n", argv[0]);
        return 1;
    }

    // Get the parameter and filename from the arguments
    char *parameter = argv[1];
    char *filename = argv[2];

    // Check the parameter and call the appropriate function
    if (strcmp(parameter, "-c") == 0) {
        count_characters(filename);
    } else if (strcmp(parameter, "-w") == 0) {
        count_words(filename);
    } else {
        fprintf(stderr, "Invalid parameter. Use -c for character count or -w for word count.\n");
        return 1;
    }

    return 0;
}

// Function to count characters in a file
void count_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int char_count = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        char_count++;
    }

    fclose(file);
    printf("×Ö·ûÊý£º%d\n", char_count);
}

// Function to count words in a file
void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    int ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == ',') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        word_count++;
    }

    fclose(file);
    printf("µ¥´ÊÊý£º%d\n", word_count);
}

