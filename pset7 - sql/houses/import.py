from sys import argv
from cs50 import SQL
import csv


# Main function
def main():

    db = SQL("sqlite:///students.db")
    with open(argv[1]) as file:
        reader = list(csv.reader(file))[1:]
        for row in reader[0:]:
            # Split the name
            name = row[0].split()

            # Doing the query
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       name[0], name[1] if len(name) == 3 else None, name[2] if len(name) == 3 else name[1],
                       row[1], row[2])


# Call the main function
if __name__ == "__main__":
    main()
