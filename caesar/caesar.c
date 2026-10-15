#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("Ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Rotate the character if it's a letter
        if (isalpha(plaintext[i]))
        {
            char ciphertext = rotate(plaintext[i], key);
            printf("%c",ciphertext);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");


    return 0;
}


bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char cipher;
    // Formula: Ci = (pi + k) % 26
    if (isupper(c))
    {
        cipher = (c - 'A' + n) % 26;
        return cipher + 'A';
    }
    else if (islower(c))
    {
        cipher = (c - 'a' + n) % 26;
        return cipher + 'a';
    }
    else
    {
        return c;
    }
}
