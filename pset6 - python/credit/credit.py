import cs50
import math


def main():
    # Example card number: 4003600000000014
    card = 0
    flag = 0

    card = cs50.get_int("Card n*: ")

    if (card < 100000000000):
        print("INVALID\n")
        return 0

    # Auxilian variables
    tempCard = card
    odd = 0
    oddTotal = 0
    even = 0
    evenTotal = 0
    while (tempCard > 0):
        # Even numbers
        even = int(tempCard % 100 / 10) * 2
        if (even > 9):
            # Sum values more than 9 with using the card logic
            n1 = int(even % 10)
            n2 = int(even / 10)
            evenTotal = evenTotal + n1 + n2
        else:
            evenTotal = evenTotal + even

        # Odd numbers
        odd = int(tempCard % 10)
        oddTotal = oddTotal + odd

        # Reduce the card
        tempCard /= 100

        if (tempCard < 100 and tempCard > 10):
            flag = tempCard
        elif (tempCard < 1000 and tempCard > 10):
            flag = tempCard / 10

    # Kind of card
    if (int(oddTotal + evenTotal) % 10 == 0):
        flag = int(flag)
        if (56 > flag and flag > 50):
            print("MASTERCARD\n")
        elif (flag == 34 or flag == 37):
            print("AMEX\n")
        elif (int(flag / 10) == 4):
            print("VISA\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()
