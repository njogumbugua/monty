#include "main.h"
void printFileContent(const char *filename) {
    FILE *fd = fopen(filename, "r"); // Open file in read mode
    check_file_status(fd, filename);

    if (fd == NULL) {
        perror("Error opening file");
        return;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, fd) != -1) {
        // Tokenize the line
        char *token = strtok(line, " \t\n"); // You can add more delimiters if needed

        while (token != NULL) {
            printf("%s\n", token); // Print each token to the console
            token = strtok(NULL, " \t\n"); // Get the next token
        }
    }

    free(line); // Free the allocated memory for getline
    fclose(fd); // Close the file
}
