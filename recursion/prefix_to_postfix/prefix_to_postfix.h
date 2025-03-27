#ifndef PREFIX_TO_POSTFIX_H
#define PREFIX_TO_POSTFIX_H

#include <stdlib.h>

#define MAX_LENGTH 100
#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

void convert(char* prefix, char* postfix);
size_t find(char* prefix);

#endif //PREFIX_TO_POSTFIX_H
