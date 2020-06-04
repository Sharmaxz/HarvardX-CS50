#include <stdio.h>
#include <cs50.h>

//Main function without parameters
int main(void)
{
    //get_string allows user send data to the code 
    string name = get_string("What is your name?\n");
    //printf allows send a text to the terminal
    printf("hello, %s\n", name);
}