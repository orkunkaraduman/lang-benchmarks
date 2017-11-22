#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	FILE *fp = fopen("lipsum.txt", "r");
	int i;
	for (i = 0; i < 100000; i++) {
//		char **fields = NULL;
		char *fields[10240];
		size_t fields_len = 0;
		char line[1024];
		fseek(fp, 0, 0);
		while (fgets(line, 1024, fp)) {
//			fields = (char **)realloc(fields, 0);
			fields_len = 0;
			char *field = strtok(line, " ");
			while (field) {
				fields_len++;
//				fields = (char **)realloc(fields, sizeof(char *)*fields_len);
				fields[fields_len-1] = field;
				field = strtok(NULL, " ");
			}
		}
		if (i % 1000 == 0) {
			printf("%d %s\n", i, fields[i % fields_len]);
		}
//		free(fields);
	}
	fclose(fp);
}
