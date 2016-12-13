#include <stdio.h>
#include <errno.h>
#include <string.h>

void print_spaces(int spaces)
{
    while (spaces-- > 0)
        putchar(' ');
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: format <file>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        int _errno = errno;
        printf("Could not open file %s: %s", argv[1], strerror(_errno));
        return 1;
    }

    char c;
    int spaces = 0;
    while ((c = getc(f)) != EOF) {
        //if (c == ' ') {
            /* main handler stuff */
            // putchar(c); // yeah, nothing yet
        //} else {
            putchar(c);
            if (c == '{')
                spaces += 4;
            else if (c == '}')
                spaces -= 4;
            else if (c == '\n') {
                print_spaces(spaces);
                while ((c = getc(f)) == ' ');
                putchar(c);
            } else if (c == '"') {
                while ((c = getc(f)) != '"')
                    putchar(c);
                putchar(c);
            }
        //}
    }

    fclose(f);
    return 0;
}
