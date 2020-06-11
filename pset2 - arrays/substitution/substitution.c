#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Check if the argument is valid!
bool check_argv(string argv)
{
    if (strlen(argv) != 26)
    {
        return false;
    }


    int frequence[26] = { };
    for (int i = 0; i < strlen(argv); i++)
    {

        if (argv[i] == ' ')
        {
            return false;
        }



        int index = toupper(argv[i]) - 'A';
        if (frequence[index] > 0)
        {
            return false;
        }

        frequence[index]++;
    }

    return true;
}

//Main Function
int main(int argc, string argv[])
{
    //Verification with usage warning
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Verification of the size
    if (!check_argv(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Variables
    int key = atoi(argv[1]);
    string diff = argv[1];
    string text = get_string("plaintext: ");

    for (int i = 'A'; i <= 'Z'; i++)
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i;
    }

    //Convert all the text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        //Convert the keys to the new "alphabet".
        if (isalpha(text[i]))
        {
            text[i] = text[i] + diff[text[i] - (isupper(text[i]) ? 'A' : 'a')];
        }

        printf("%c", text[i]);
    }

    printf("\n");
    return 0;
}
