#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./recover IMAGE\n");
        return 1;
    }
    //open file - Reading mode

    FILE *in_file = fopen(argv[1], "r");

    if (in_file == NULL)
    {
        printf("Could not find file\n");
        return 2;
    }

    //store blocks of 512bytes
    unsigned char buffer[512];

    int count_image = 0;

    FILE *out_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, in_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //write the JPEG filename
            sprintf(filename, "%03i.jpg", count_image);

            //open out_file for writing
            out_file = fopen(filename, "w");

            //count number of found images
            count_image++;
        }
        //check if out_file has been used
        if (out_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, out_file);
        }
    }

    free(filename);
    fclose(out_file);
    fclose(in_file);

    return 0;
}



