#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_logs(FILE *file, const char *keyword) {
    char line[512];
    int line_number = 1;
    int alert_count = 0;

    printf("\n=== Security Log Analysis Report ===\n");
    printf("Target Keyword: [%s]\n", keyword);
    printf("--------------------------------------------------\n");
    printf("%-12s | %s\n", "Line Number", "Suspicious Log Content");
    printf("--------------------------------------------------\n");

    // Read the file line by line to avoid high memory consumption
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove trailing newline characters (\r or \n) for clean output
        line[strcspn(line, "\r\n")] = 0;

        // Search for the keyword using strstr
        if (strstr(line, keyword) != NULL) {
            alert_count++;
            printf("[Line %-6d] | %s\n", line_number, line);
        }
        line_number++;
    }

    printf("--------------------------------------------------\n");
    printf("[+] Analysis Summary:\n");
    printf("    - Total lines scanned: %d lines\n", line_number - 1);
    printf("    - Total suspicious alerts found: %d alerts\n", alert_count);
    printf("==================================================\n");
}

int main(int argc, char *argv[]) {
    // Validate command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <log_file> <keyword>\n", argv[0]);
        fprintf(stderr, "Example: %s auth.log FAILED\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *keyword = argv[2];

    // Open target log file in text read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error: Could not open the specified log file");
        return 1;
    }

    // Execute log parsing
    parse_logs(file, keyword);

    // Close the file safely to free resources
    fclose(file);
    return 0;
}