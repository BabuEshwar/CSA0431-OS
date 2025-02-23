#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
void grep(const char *pattern, FILE *file);
int main(int argc, char *argv[]) {
 const char *pattern;
 FILE *file;
 
 if (argc < 2) {
 fprintf(stderr, "Usage: %s pattern [file...]\n", argv[0]);
 exit(EXIT_FAILURE);
 }
 
 pattern = argv[1];

 if (argc >= 3) {
 for (int i = 2; i < argc; i++) {
 file = fopen(argv[i], "r");
 if (file == NULL) {
 perror(argv[i]);
 continue;
 }
 grep(pattern, file);
 fclose(file);
 }
 } else { 
 grep(pattern, stdin);
 }
 return 0;
}
void grep(const char *pattern, FILE *file) {
 char line[MAX_LINE_LENGTH];

 while (fgets(line, sizeof(line), file) != NULL) {

 if (strstr(line, pattern) != NULL) {

 printf("%s", line);
 }
 }
}
