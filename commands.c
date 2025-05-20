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


