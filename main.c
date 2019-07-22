#include <stdio.h>
#include <stdlib.h>
 char keywords[18][10] = {"break","case","char","const","continue","do",
                          "else","enum","float","for","goto",
                          "if","int","long","record","return","static","while"};
char operators[7][2] = {"+","-","*","/","++","--",":="};
int isKeyword(char[]);
int isOperator(char[]);
int isBracket(char );
int main()
{
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;

    fp = fopen("kod.psi","r");

    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    else
    {
        while((ch = fgetc(fp)) != EOF)
        {
            if(ispunct(ch))
            {
                if(ch==':')
                {
                    printf("%c is End Of Line",ch);
                }
                else
                {
                    int number=isBracket(ch);
                    switch(number)
                {
                    case 1:
                        printf("%c is LeftPar\n",ch);
                        break;
                    case 2:
                        printf("%c is RightPar\n",ch);
                        break;
                    case 3:
                        printf("%c is LeftSquareBracket\n",ch);
                        break;
                    case 4:
                        printf("%c is RightSquareBracket\n",ch);
                        break;
                    case 5:
                        printf("%c is LeftCurlyBracket\n",ch);
                        break;
                    case 6:
                        printf("%c is RightCurlyBracket\n",ch);
                        break;
                    default:

                        while(ispunct(ch) &&  !isspace(ch) && ch!=':')
                        {
                            buffer[j++] = ch;
                            ch = fgetc(fp);
                        }
                        if(ch==':')
                        {
                            fseek( fp, -1, SEEK_CUR );
                        }
                        buffer[j] = '\0';
                        j = 0;
                        if(isOperator(buffer) == 1)
                        {
                           printf("%s is operator\n", buffer);
                        }
                        break;
                }
                }

            }
            else
            {
                if(isalnum(ch))
                    buffer[j++] = ch;
                else
                {
                        if((ch == ' ' || ch == '\n') && (j != 0))
                        {
                            buffer[j] = '\0';
                            j = 0;
                            if(isKeyword(buffer) == 1)
                                printf("%s is keyword\n", buffer);
                            else{
                                printf("%s is indentifier\n", buffer);
                            }
                            memset(buffer, 0, sizeof(buffer));
                        }
                }


            }
        }
    }
    return 0;
}
int isKeyword(char buffer[])
{
    int i;

    for(i = 0; i < 18; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}
int isOperator(char buffer[])
{
    int i;
    for(i = 0; i < 7; ++i)
    {
        if(strcmp(operators[i], buffer) == 0)
            return 1;
    }
    return 0;
}
int isBracket(char ch)
{
    int i;
    for(i = 0; i < 6; ++i)
    {
        if('('==ch)
            return 1;
        if(')'==ch)
            return 2;
        if('['==ch)
            return 3;
        if(']'==ch)
            return 4;
        if('{'==ch)
            return 5;
        if('}'==ch)
            return 6;
    }
    return 0;
}

