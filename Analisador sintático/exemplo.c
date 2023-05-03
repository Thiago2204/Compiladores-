#include <stdio.h>
#include <stdlib.h>
/*
Linguagem:
E -> T R
R -> + T R
R -> - T R
R -> §
T -> 0 | 1 | 2 | .. | 8 | 9
*/

char lookahead;

int match (char t, char palavra[], int *pos)
{
    if (lookahead == t)
    {
        lookahead = palavra[++(*pos)];
        return(1);
    }
    return(0);
}

void erro(void);

int E(char palavra[], int *pos);
int R(char palavra[], int *pos);
int T(char palavra[], int *pos);

int E(char palavra[], int *pos)
{
    if ( T(palavra, pos) && R(palavra, pos))
        return (1);
    return (0);
}

int R(char palavra[], int *pos)
{
    switch(lookahead)
    {
        case '+':
            if( match('+', palavra, pos) &&
                T(palavra, pos)          &&
                R(palavra, pos) 
            )   return (1);
            return (0);
        case '-':
            if( match('-', palavra, pos) &&
                T(palavra, pos)          &&
                R(palavra, pos)
            )   return (1);
            return (0);
        case 'e':
            return(1); 
    }
}

int T(char palavra[], int *pos)
{
    if(match(lookahead, palavra, pos)) return (1);
    else return (0);
}

void erro(void) { printf("Se ferrou, irmão.\n"); }

int main()
{
    char palavra[] = "0+1e";
    int pos=0;

    lookahead = palavra[pos];
    if(E(palavra, &pos))
        printf("\n Deu bom irmão, fé\n\n");
    else
        erro();
    system("PAUSE");
    return(0);
}