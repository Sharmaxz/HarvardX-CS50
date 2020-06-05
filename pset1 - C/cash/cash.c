#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    int dollares;
    int coins = 0;
    float cents;
    
    do 
    {
        cents = get_float("Change owed: ");
    }
    while (cents < 0.00);

    //Round the cents
    dollares = round(cents * 100);

    //Reduce the value
    while (dollares >= 25) 
    {
        dollares = dollares - 25;
        coins = coins + 1;
    }

    while (dollares >= 10) 
    {
        dollares = dollares - 10;
        coins = coins + 1;
    }

    while (dollares >= 5) 
    {
        dollares = dollares - 5;
        coins = coins + 1;
    }

    while (dollares >= 1)
    {
        dollares = dollares - 1;
        coins = coins + 1;
    }

    printf("%i \n", coins);
}
