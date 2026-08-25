#include <stdio.h>
#include <string.h>
#include <ctype.h>

void changeLastNum(char *txt)
{
    int len = strlen(txt);
    txt[len - 1] = '6';
    return;
}

char* getNewStr(char *org_txt, char *new_txt)
{
    strncpy(new_txt, &org_txt[13], 10);
    return new_txt;
};

void myToLower(char *txt)
{
    for(int i = 0; i < strlen(txt); i++)
    {
        txt[i] = tolower(txt[i]);
    }
    return;
}

int getVocals(char *txt)
{
    int c = 0, i = 0;
    char v[5] = {'a','e','i','o','u'};
    myToLower(txt);
    while(txt[i] != '\0')
    {
        for(int j = 0; j < 10; j++)
        {
            if(txt[i] == v[j])
            {
                c++;
            }
        }
        i++;
    }
    return c;
};

void getUpperStr(char *txt)
{
    for(int i = 0; i < strlen(txt); i++)
    {
        txt[i] = toupper(txt[i]);
    }
    printf("%s\n", txt);
    return;
};

void getBackwards(char *txt, char *b_txt)
{
    for(int i = 0; i < strlen(txt); i++)
    {
        b_txt[i] = txt[strlen(txt) - 1 - i];
    }
    printf("%s\n", b_txt);
    return;
};

int main()
{
    char txt[50];
    char new_txt[20];
    char back_txt[50];
    printf("Ingrese texto: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0';
    changeLastNum(txt);
    printf("Nuevo texto: %s\n",getNewStr(txt, new_txt));
    printf("Cantidad de vocales: %d\n", getVocals(txt));
    getUpperStr(txt);
    getBackwards(txt, back_txt);
    return 0;
};

    






