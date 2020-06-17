from sys import argv
import csv


def main():
    # Dictionary to store the sequences
    sequences = {}

    # Check if argv is valid
    if len(argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Extract the sequence
    with open(argv[1]) as file:
        reader = next(csv.reader(file))
        reader.pop(0)

        # Copy list to dict
        for i in reader:
            sequences[i] = 1

    # Extract the DNA
    with open(argv[2]) as file:
        reader = csv.reader(file)
        dna = next(reader)[0]

    for seq in sequences:
        size = len(seq)
        max, temp = 0, 0
        for i in range(len(dna)):
            while temp > 0:
                temp -= 1
                continue

            if dna[i: i + size] == seq:
                while dna[i - size: i] == dna[i: i + size]:
                    temp += 1
                    i += size

                if temp > max:
                    max = temp

        sequences[seq] += max

    with open(argv[1], newline='') as file:
        reader = csv.DictReader(file)
        for row in reader:
            match = 0
            # Compares the sequence
            for dna in sequences:
                if sequences[dna] == int(row[dna]):
                    match += 1
            if match == len(sequences):
                print(row['name'])
                exit()

        print("No match")


# Call the main function
if __name__ == "__main__":
    main()
