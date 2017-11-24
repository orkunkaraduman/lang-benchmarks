#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PAGE_SIZE 4096

void main()
{
	FILE *fp = fopen("lipsum.txt", "r");

	int i;
	for (i = 0; i < 1000000; i++) {
		char **fields = NULL;
//		char *fields[10240];
		size_t fields_len = 0;
		char line[1024];
		fseek(fp, 0, 0);
		while (fgets(line, 1024, fp)) {
			fields = (char **)realloc(fields, PAGE_SIZE);
			fields_len = 0;
			char *field = strtok(line, " ");
			while (field) {
				fields_len++;
				size_t k = sizeof(char *)*fields_len;
				if (k/PAGE_SIZE != (k-sizeof(char *))/PAGE_SIZE) {
					fields = (char **)realloc(fields, (k/PAGE_SIZE+1)*PAGE_SIZE);
				}
				fields[fields_len-1] = field;
				field = strtok(NULL, " ");
			}
		}
		if (i % 1000 == 0) {
			printf("%d %s\n", i, fields[i % fields_len]);
		}
		free(fields);
	}

	fclose(fp);
}
