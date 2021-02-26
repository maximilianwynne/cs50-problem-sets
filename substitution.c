#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Error");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        if (!(islower(argv[1][i]) || isupper(argv[1][i])))
			return 1;
    }
    char c;

    int n = strlen(argv);

    for (int i = 0; i < n; ++i)
    {
        c = argv[i];

    	for(int j = 0; j < n; ++j)
    	{
    		if (c == argv[j])
    		{
    			return 1;
    		}
    	}
    }

    string code = get_string("plaintext: ");

    for (int i = 0, n = strlen(code); i < n; i++)
    {
        if (islower(code[i]))
        {
            int pos = code[i] - 'a';
			code[i] = argv[1][pos];
			if (isupper(code[i]))
				code[i] += 32;
        }
        else if (isupper(code[i]))
        {
            int pos = code[i] - 'A';
            code[i] = argv[1][pos];
			if (islower(code[i]))
				code[i] -= 32;
        }

    }
    printf("ciphertext: %s\n", code);
    return 0;
}
