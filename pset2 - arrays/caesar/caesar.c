#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_argv(string argv) 
{
    for (int i = 0; i < strlen(argv); i++) 
    {
        if (!isdigit(argv[i]))
        {
            return false;
        }
    }
    return true;
}

//Main Function
int main(int argc, string argv[])
{
    if (argc != 2 || !check_argv(argv[1])) 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Variables
    int key = atoi(argv[1]);
    string text;

    //Repeat until find a valid value
    do 
    {
        text = get_string("plaintext: ");
    }
    while (text == NULL);

    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            //Logic of get the right key
            char letterCase = islower(c) ? 'a' : 'A';
            printf("%c", (c - letterCase + key) % 26 + letterCase);
        } 
        else 
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
