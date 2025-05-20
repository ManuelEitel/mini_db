#include <stdio.h>
#include <string.h>
#include "STRUCTURE_PARAMETERS.h"

int get_max_id(FILE *fp) {
    char line[MAX_LINE_LEN];
    int max_id = 0;
    int id_temp;

    fseek(fp, 0, SEEK_SET);

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%3d", &id_temp) == 1) {  
            if (id_temp > max_id) {
                max_id = id_temp;
            }
        }
    }

    return max_id;
}


int check_existing_entry(FILE *fp, const char *key, const char *value, int *max_id_out) {
    char line[MAX_LINE_LEN];
    char file_key[MAX_KEY_LEN];
    char file_value[MAX_VAL_LEN];
    int id = 0;
    int max_id = 0;

    fseek(fp, 0, SEEK_SET);

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%3d;\"%[^\"]\";\"%[^\"]\"", &id, file_key, file_value) == 3) {

            if (id > max_id) {
                max_id = id;
            }

            if (strcmp(file_key, key) == 0 && strcmp(file_value, value) == 0) {
                printf("Entry already existing: ID: %3d; Key: %s; Value: %s\n", id, file_key, file_value);
                return 1;
            }
        }
    }
    *max_id_out = max_id;
    return 0;
}
   

int write_entry(FILE *fp, int id, const char *key, const char *value);

