#include <stdio.h>
#include <cs50.h>
#include <string.h>

void vigenere(char *a1, char *p);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            while (argv[1][i] < 'A' || argv[1][i] > 'z' || (argv[1][i] > 'Z' && argv[1][i] < 'a'))
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }
        
        printf("plaintext: ");
        char *p_text = get_string();
        
        vigenere(argv[1], p_text);
        
        printf("ciphertext: %s\n", p_text);
    }
}

void vigenere(char *a1, char *p)
{
    char *key = malloc((strlen(p) + 1) * sizeof(char)); //宣告一組記憶體空間,長度和p字串一樣長,並讓key指向空間中第一個bit的位址
    char *c_text = malloc((strlen(p) + 1) * sizeof(char)); ////宣告一組記憶體空間,長度和p字串一樣長,用來存被加密過的p
    int str_count = 0;
    
    for (int i = 0; i < (strlen(p) + 1); i++) //讓key字串照著p字串的格式,依序填入a1字串的字元
    {
        if ((*(p + i) >= 'A' && *(p + i) <='Z') || (*(p + i) >= 'a' && *(p + i) <='z'))
        {
            if (*(a1 + str_count) == '\0') //如果a1到盡頭了,重新把pointer指回a1的第一個bit
            {
                str_count = 0;
            }
            *(key + i) = *(a1 + str_count);
            str_count++;
        }
        else if (*(p + i) == '\0')
        {
            *(key + i) = '\0';
        }
        else
        {
            *(key + i) = ' ';
        }
    }
    
    for (int i = 0; i < (strlen(p) + 1); i++)
    {
        if (*(p + i) >= 'A' && *(p + i) <='Z') //若p的第i個字是大寫的話
        {
            if (*(key + i) >= 'A' && *(key + i) <= 'Z' && (*(p + i) + (*(key + i) - 65)) > 'Z') //若key的第i個字是大寫,且p的第i個字加上k的第i個字會超過Z時
            {
                *(c_text + i) = 'A' + (*(p + i) + (*(key + i) - 65)) - 'Z' - 1;
            }
            else if (*(key +i) >= 'A' && *(key + i) <= 'Z') //若key的第i個字是大寫,且p的第i個字加上k的第i個字不會超過Z時
            {
                *(c_text + i) = *(p + i) + *(key + i) - 65;
            }
            else if (*(key + i) >= 'a' && *(key + i) <= 'z' && (*(p + i) + (*(key + i) - 97)) > 'Z') //若key的第i個字是小寫,且p的第i個字加上k的第i個字超過Z時
            {
                *(c_text + i) = 'A' + (*(p + i) + (*(key + i) - 97)) - 'Z' - 1;
            }
            else
            {
                *(c_text + i) = *(p + i) + *(key + i) - 97;
            }
        }
        
        else if (*(p + i) >= 'a' && *(p + i) <='z') //若p的第i個字是小寫的話
        {
            if (*(key + i) >= 'A' && *(key + i) <= 'Z' && (*(p + i) + (*(key + i) - 65)) > 'z') //若key的第i個字是大寫,且p的第i個字加上k的第i個字會超過z時
            {
                *(c_text + i) = 'a' + (*(p + i) + (*(key + i) - 65)) - 'z' - 1;
            }
            else if (*(key + i) >= 'A' && *(key + i) <= 'Z') //若key的第i個字是大寫,且p的第i個字加上k的第i個字不會超過z時
            {
                *(c_text + i) = *(p + i) + *(key + i) - 65;
            }
            else if (*(key + i) >= 'a' && *(key + i) <= 'z' && (*(p + i) + (*(key + i) - 97)) > 'z') //若key的第i個字是小寫,且p的第i個字加上k的第i個字超過z時
            {
                *(c_text + i) = 'a' + (*(p + i) + (*(key + i) - 97)) - 'z' - 1;
            }
            else
            {
                *(c_text + i) = *(p + i) + *(key + i) - 97;
            }
        }
        
        else if (*(p + i) == '\0')
        {
            *(c_text + i) = '\0';
        }
        
        else
        {
            *(c_text + i) = *(p + i);
        }
    }

    strcpy(p, c_text);
    free(key);
    free(c_text);
}