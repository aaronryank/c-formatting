#include <stdio.h>
#include <errno.h>
#include <string.h>

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
    while ((c = getc(f)) != EOF) {
        if (c == '"')
            while (getc(f) != '"');
    }
}
