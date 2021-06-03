def get_value():
    a = 0
    while a < 1 or a > 8:
        a = int(input("Height: "))
    return a


def draw(height):
    for row in range(height):
        num_spaces = height - row - 1
        num_hashes = row + 1
        print(" " * num_spaces + "#" * num_hashes + "  " + "#" * num_hashes)


height = get_value()
draw(height)
