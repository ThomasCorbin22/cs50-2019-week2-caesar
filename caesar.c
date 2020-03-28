#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int COUNT = 1;
int validate(int x, string y);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int sum = 0;
        for (int i = 0, n = strlen(argv[COUNT]); i < n; i++)
        {
            int c = (int) argv[COUNT][i];
            if ((c < 48) || (c > 57))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                sum = sum * 10 + (argv[COUNT][i] - '0');
            }
        }
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char c = plaintext[i];
            if ((c + sum > 90) && (c <= 90))
            {
                printf("%c", (((c - 65) + sum) % 26) + 65);
            }
            else if (((c + sum > 122) && (c <= 122)) && (c >= 97))
            {
                printf("%c", (((c - 97) + sum) % 26) + 97);
            }
            else if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
            {
                printf("%c", c + sum);
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
