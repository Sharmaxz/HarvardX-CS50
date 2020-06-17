height = 0

# Loop to get the correct value
while (1 >= height or height > 9):
    height = int(input("Height: ")) + 1

# Logic to make the pyramid
for i in range(1, height):
    for j in range(1, height - i):
        print(" ",  end='')

    for j in range((height - i), height):
        print("#",  end='')

    print("")
