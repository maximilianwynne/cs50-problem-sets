#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // check number of command line arguments
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }

    string key = argv[1];

    // check key length
    if (strlen(key) != 26)
    {
        printf("Error");
        return 1;
    }

    // check for non-letters in key.
    for (int i = 0; i < strlen(key); ++i)
    {
        if (!(islower(key[i]) || isupper(key[i])))
			return 1;
    }

    char c;

    int n = strlen(key);

    // check for duplicate letters in key
    for (int i = 0; i < n; ++i)
    {
        c = key[i];

    	for(int j = i + 1; j < n; ++j)
    	{
    		if (c == key[j])
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
			code[i] = key[pos];
			if (isupper(code[i]))
				code[i] += 32;
        }
        else if (isupper(code[i]))
        {
            int pos = code[i] - 'A';
            code[i] = key[pos];
			if (islower(code[i]))
				code[i] -= 32;
        }

    }
    printf("ciphertext: %s\n", code);
    return 0;
}
