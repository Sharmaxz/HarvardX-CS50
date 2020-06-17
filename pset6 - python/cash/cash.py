dollares = 0
coins = 0
cents = 0.00

# Loop to get the correct value
while (cents <= 0.00):
    try:
        cents = float(input("Change owed: "))
    except:
        cents = 0.00

dollares = round(cents * 100)

# Reduce the value
while (dollares >= 25):
    dollares = dollares - 25
    coins = coins + 1

# Reduce the value
while (dollares >= 10):
    dollares = dollares - 10
    coins = coins + 1

# Reduce the value
while (dollares >= 5):
    dollares = dollares - 5
    coins = coins + 1

# Reduce the value
while (dollares >= 1):
    dollares = dollares - 1
    coins = coins + 1

print(f"{coins}")