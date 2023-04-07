// ANALISADOR LÉXICO - ETAPA 2 -----------------------------------------------

// Inclusões------------------------------------------------------------------
#include <stdio.h>

// Definições ---------------------------------------------------------------
#define _ACEITA_ 1
#define _REJEITA_ 0

// Protótipo das funções ---------------------------------------------------
int scanner(char palavra[]);


// Implementação ------------------------------------------------------------
int scanner(char palavra[])
{
   char c;
   int i = -1;
   q0:
    i++;
    c = palavra[i];
    if (c == 'a') goto q1;
    else if (c == 'b') goto q0;
    else if (c == '\0') return (_REJEITA_);
    else goto poco;
   q1:
    i++;
    c = palavra[i];
    if (c == 'a') goto q1;
    else if (c == 'b') goto q0;
    else if (c == '\0') return (_ACEITA_);
    else goto poco;
   poco:
    return (_REJEITA_);
}


// main -----------------------------------------------------------------------
int main(int argc, char * argv[])
{
    char str[] = "bbababababaabba";
    int out = scanner(str);
    FILE * token_output_ptr = fopen("token.txt", "w");
    fprintf(token_output_ptr, "%d", out);
    fclose(token_output_ptr);
    return 0;
}

