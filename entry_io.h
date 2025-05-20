#ifndef ENTRY_IO_H
#define ENTRY_IO_H

#include <stdio.h>

int get_max_id(FILE *fp);
int check_existing_entry(FILE *fp, const char *key, const char *value, int *max_id_out);
int write_entry(FILE *fp, int id, const char *key, const char *value);




#endif
