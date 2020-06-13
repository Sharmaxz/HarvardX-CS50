#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;


bool check_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    //Check if argc is different of two
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Get the filename
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int index = 0;

    char filename[8];
    FILE *outfile = NULL;

    while (true)
    {
        //Read the card image
        size_t reader = fread(buffer, sizeof(BYTE), BLOCK_SIZE, infile);

        if (!reader && feof(infile))
        {
            break;
        }

        //Check if it is a jpeg
        bool is_jpeg = check_jpeg(buffer);

        //Close the previous file
        if (is_jpeg && outfile)
        {
            fclose(outfile);
        }

        //Open the file
        if (is_jpeg)
        {
            sprintf(filename, "%03i.jpg", index++);
            outfile = fopen(filename, "w");
        }

        //Write in the file
        if (outfile)
        {
            fwrite(buffer, sizeof(BYTE), reader, outfile);
        }
    }

    //Close file
    fclose(infile);

    //Close the last file
    fclose(outfile);

    return 0;
}
