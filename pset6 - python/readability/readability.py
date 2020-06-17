import cs50
import math


# Main Function
def main():
    # Variables
    text = cs50.get_string("Text: ").strip()
    letter, word, sentence = 0, 0, 0

    for i in range(len(text)):
        if (text[i].isalpha()):
            letter += 1

        if ((i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text[i + 1] != ' ')):
            word += 1

        if (text[i] == '.' or text[i] == '?' or text[i] == '!'):
            sentence += 1

    # Get the result
    l = (letter / word) * 100
    s = (sentence / word) * 100
    grade = round(0.0588 * l - 0.296 * s - 15.8)
    if (grade > 1 and grade < 16):
        print(f"Grade {grade}")
    elif (grade >= 16):
        print("Grade 16+")
    else:
        print("Before Grade 1")


if __name__ == "__main__":
    main()