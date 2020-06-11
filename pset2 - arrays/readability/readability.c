#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Main Function
int main(void)
{
    //Variables
    string text;
    int letter = 0;
    int word = 0;
    int sentence = 0;

    //Repeat until find a valid value
    do 
    {
        text = get_string("Text: ");
    }
    while (text == NULL);

    for (int i = 0; i < strlen(text); i++)
    {
        //Using ternario operator
        isalpha(text[i]) ? letter++ : 0;

        if ((i == 0 && text[i] != ' ') || 
        (i != strlen(text) - 1 && text[i] == ' ' && text[i + 1] != ' ')) 
        {
            word++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
    }

    //Get the result
    float l = (letter / (float) word) * 100;
    float s = (sentence / (float) word) * 100;
    int grade = round(0.0588 * l - 0.296 * s - 15.8);
    if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
