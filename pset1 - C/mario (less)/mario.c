#include <stdio.h>
#include <cs50.h>

//Main function without parameters
int main(void)
{
    //Variable
    int height = 0;

    //Loop to get the correct value
    while (height <= 1 || height > 9)
    {
        height = get_int("Height: ") + 1;
    }


    //logic to make the pyramid
    for (int i = 1; i < height; i++)
    {

        for (int j = 1; j < (height - i); j++)
        {
            printf(" ");
        }

        for (int j = (height - i); j < height; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}