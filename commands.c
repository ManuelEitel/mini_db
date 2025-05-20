#include <string.h>
#include <stdio.h>
#include "entry_io.h"
#include "STRUCTURE_PARAMETERS.h"

int set_entry(const char *key, const char *value) {
    
    if (*key == '\0' || *value == '\0') {
        printf("Command \"set\" needs key and value. Nothing is done.\n");
        return -1;
    }

    FILE *fp = fopen(DB_FILE, "a+");
    if (!fp) fp = fopen(DB_FILE, "a+"); 
    
    int max_id = 0;

    if (check_existing_entry(fp, key, value, &max_id)){
            fclose(fp);
            return -1;
    }

    int new_id = max_id + 1;
           
    fprintf(fp, "%03d;\"%s\";\"%s\"\n", new_id, key, value);
    fclose(fp);
    return 1;
}

int get_entry(const char *key) {
    FILE *fp = fopen(DB_FILE, "r");
    if (!fp) {
        printf("No db file.\n");
        return -1;
    }

    char line[MAX_LINE_LEN];
    int id;
    char file_key[MAX_KEY_LEN];
    char file_value[MAX_VAL_LEN];
    int found = 0;
    
    int format_used = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%3d;\"%[^\"]\";\"%[^\"]\"", &id, file_key, file_value) == 3) {
            if (strcmp(file_key, key) == 0) {
                if (!format_used) {
                    printf("+-----+----------------+\n");
                    printf("| ID  | VALUE          |\n");
                    printf("+-----+----------------+\n");
                    format_used = 1;
                }

                printf("| %03d | %-14s\n", id, file_value);
                found = 1;
            }
        }
    }

    if (format_used) {
        printf("+-----+----------------+\n");
    }

    fclose(fp);

    if (!found) {
        printf("No entries found for key: %s\n", key);
    }
    return found ? 1 : 0;
}

