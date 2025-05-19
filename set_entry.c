#include <string.h>
#include <stdio.h>

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

int set_entry(const char *key, const char *value) {
    
    if (*key == '\0' || *value == '\0') {
        return -1;
    }

    FILE *fp = fopen(DB_FILE, "a+");
    if (!fp) fp = fopen(DB_FILE, "a+"); 
    
    int max_id = get_max_id(fp) + 1;


    // ToDo: Methode bauen, die bereits eingefügte Einträge prüft
    
    fprintf(fp, "%03d;\"%s\";\"%s\"\n", max_id, key, value);
    fclose(fp);
    return 1;
}


