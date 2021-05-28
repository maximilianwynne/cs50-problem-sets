#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt); // defining a function

int main(void) // function to return some value

{
    int number = get_positive_int("Height: "); // asking for a positive number

    for (int height = 0; height < number; height++) // height + number of lines
    {
        for (int spaces = number - height - 2; spaces >= 0; spaces--)
        {
            printf(" ");
        }
        for (int row = 0; row <= height; row++)
        {
            printf("#");
        }
        printf("  ");
        for (int row2 = 0; row2 <= height; row2++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(string prompt) // coding a function

{
    int number;
    do
    {
        number = get_int("%s", prompt); // defining integer value, my BIGGEST value
    }
    while (number < 1 || number > 8);
    return number;
}
