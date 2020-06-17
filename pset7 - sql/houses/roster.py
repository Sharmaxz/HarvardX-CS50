from sys import argv
from cs50 import SQL
import csv


# Main function
def main():
    db = SQL("sqlite:///students.db")

    # Do the query and get the response
    response = db.execute("SELECT first, middle, last, house, birth FROM students \
        WHERE house = ? ORDER BY last,first ", argv[1])

    for row in response:
        print(row['first'], end=" ")
        if row['middle'] != None:
            print(f"{row['middle']}", end=" ")
        print(row['last'], end=", ")
        print("born", row['birth'])


# Call the main function
if __name__ == "__main__":
    main()
