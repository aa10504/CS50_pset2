#include <stdio.h>
#include <cs50.h>
#include <string.h>

void cipher(int a, char *p);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    else
    {
        int a = atoi(argv[1]); //創一個a把command-lined argument的第二個字串存成int
        printf("plaintext: ");
        char *p_text = get_string();
        
        cipher(a, p_text);
        
        printf("ciphertext: %s\n", p_text);
        return 0;
    }
}

void cipher(int a, char *p)
{
    int b = a % 26; //創一個b來存a除以26的餘數
    char *tmp = malloc((strlen(p) + 1) * sizeof(char)); //要求電腦給出p字串大小的記憶體,並把這組記憶體的位址存在tmp,+1是為了最後的/0
    tmp[strlen(p) + 1] = '\0';
    
    for (int i = 0; i < strlen(p); i++) //把p字串裡的每一個字都後移b個單位,存在tmp裡
    {
        if (p[i] >= 'A' && p[i] <= 'Z' && (p[i] + b) > 'Z')
        {
            tmp[i] = 'A' + (p[i] + b - 'Z' - 1);
        }
        else if (p[i] >= 'a' && p[i] <= 'z' && (p[i] + b) > 'z')
        {
            tmp[i] = 'a' + (p[i] + b - 'z' - 1);
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            tmp[i] = p[i] + b;
        }
        else if (p[i] >= 'a' && p[i] <= 'z')
        {
            tmp[i] = p[i] + b;
        }
        else
        {
            tmp[i] = p[i];
        }
    }
    
    strcpy(p, tmp); //把存在tmp地址裡的資料存到位址裡
    
    free(tmp); //把tmp這組記憶體解放掉,避免永遠消耗掉heap memory
}