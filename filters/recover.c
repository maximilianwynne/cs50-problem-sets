#include <stdio.h>
#include <stdlib.h>

FILE * image = NULL

// find first JPEG block and open it on the memory card
int main(int argc, char* argv[])
{
    // open the file
    FILE* in_p = fopen("card.raw", "r");

    // check if file exists and can be opened
    char const* const fileName = argv[1];
    FILE* f = fopen(filename, "r");
    char line[1];

    while(fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    else
    {
    while (fscanf(f, "%s", &etc) != EOF)
        {
            f = fgetc( fp );
            if( feof(fp) )
            break ;
            printf( "%c", c);
        }
    }
}

// declare the buffer where the block of 512 bytes will be stored
unsigned buffer storage[512];

// read from the file until it ends
while (fread fileName)
{
    if (buffer = 0xff || 0xd88 || 0xff)
    {
        buffer[0] == 0xff
        buffer[1] == 0xd8
        buffer[2] == 0xff
        (buffer[3] & 0xf0) == 0xe0

        sprintf(int argc, char* argv[1]; i++)
        printf(fileName);
    }
}

// read from the file until it ends
while (fread(&buffer, sizeof(buffer), 1, in_p))
{
    //const char mark_1[4] =
    if (buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] == 0xe0 || buffer[3] == 0xe1))


    {
    // if the new jpeg sequence is found, write into new JPEG until a new JPEG sequence is found
    printf("found \n ");
    break;
    // FILE* out_p = fopen("title", "a");
    // fwrite(&buffer, sizeof(buffer), 1, out_p);



    //fclose(out_p);
    }

    else
    {
        printf("not found \n");
    }

// Write the block to JPEG file (or append)
unsigned char buffer[3];
FILE *ptr;
{
    ptr = fopen("card.raw", "rb");
    fread(buffer,sizeof(buffer),1,ptr);

    for(int i = 0; i < 10; i++)
}
    {
        printf("%u ", buffer[i]);
    }
}

FILE *write_ptr;
{
    write_ptr = fopen("card.raw", "wb");
    fwrite(buffer, sizeof(buffer), 1, write_ptr);
    {
        // close the JPEG file
        fclose(in_p);
    }
}
