#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    //Example card number: 4003600000000014
    long card;
    int flag;

    card  = get_long("Card n*: ");

    if (card < 100000000000) 
    {
        printf("INVALID\n");
        return 0;
    }
 
    //Auxilian variables
    long tempCard = card;
    int odd = 0;
    int oddTotal = 0;
    int even = 0;
    int evenTotal = 0;
    while (tempCard > 0) 
    {
        //Even numbers
        even = (tempCard % 100 / 10) * 2;
        if (even > 9) 
        {
            //Sum values more than 9 with using the card logic
            int n1 = even % 10;
            int n2 = even / 10;
            evenTotal = evenTotal + n1 + n2;
        } 
        else 
        {
            evenTotal = evenTotal + even;
        }

        //Odd numbers
        odd = tempCard % 10;
        oddTotal = oddTotal + odd;

        //Reduce the card
        tempCard /= 100;

        if (tempCard < 100 && tempCard > 10) 
        {
            flag = tempCard;
        } 
        else if (tempCard < 1000 && tempCard > 10) 
        {
            flag = tempCard / 10;
        }
    }
    
    //Kind of card
    if ((oddTotal + evenTotal) % 10 == 0) 
    {
        if (56 > flag && flag > 50) 
        {
            printf("MASTERCARD\n");
        }
        else if (flag == 34 || flag == 37) 
        {
            printf("AMEX\n");
        }
        else if (flag / 10 == 4) 
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    } 
    else 
    {
        printf("INVALID\n");
    }
}
