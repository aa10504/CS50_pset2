#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>         //為了使用strcmp

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char *salt = "50";
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //第53個是\0
    char *p_text = malloc(5 * sizeof(char));       ////request 5 bytes for 5 char, _ _ _ _ \0
    *(p_text) = '\0', *(p_text + 1) = '\0', *(p_text + 2) = '\0', *(p_text + 3) = '\0', *(p_text + 4) = '\0';
    
    for (int i = 53; i >= 0; i--)
    {
        for(int j = 53; j >= 0; j--)
        {
            for(int k = 53; k >= 0; k--)
            {
                for(int l = 52; l >= 0; l--)
                {
                    if ((k == 53 && j == 53 && i == 53) || (k != 53 && j == 53 && i == 53) || (k != 53 && j != 53 && i == 53) || (k != 53 && j != 53 && i != 53))
                    {
                        *(p_text) = alphabet[l], *(p_text + 1) = alphabet[k], *(p_text + 2) = alphabet[j], *(p_text + 3) = alphabet[i];
                        if (strcmp(crypt(p_text, salt), argv[1]) == 0)
                        {
                            printf("%s\n", p_text);
                            free(p_text);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}