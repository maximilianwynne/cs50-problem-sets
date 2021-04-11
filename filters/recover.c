#include <stdio.h>
#include <stdlib.h>

// find first JPEG block and open it
int main(int argc, char* argv[])
{
    char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    char line[1];

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

fread(data, size, number, input);

    if (buffer = 0xff || 0xd88 || 0xff)
    {
        buffer[0] == 0xff
        buffer[1] == 0xd88
        buffer[2] == 0xff
        buffer[3] & 0xf0 == 0xe0
    }

sprintf(filename, "%03i.jpg", 2);
