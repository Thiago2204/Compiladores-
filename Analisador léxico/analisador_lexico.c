// ANALISADOR LÉXICO - ETAPA 2 ================================================

// Inclusões ==================================================================
#include <stdio.h>
#include <stdlib.h>

// Definições =================================================================
// Palavras reservadas --------------------------------------------------------
#define _FALSE_ 0
#define _TRUE_  1
#define _BOOL_  3
#define _INT_   4
#define _VOID_  5
#define _SEMIC_ 6
#define _PRINT_ 7
#define _PROC_  8
#define _IF_    9
#define _ELSE_  10
#define _WHILE_ 11
#define _DO_    12

// Símbolos -------------------------------------------------------------------
#define _PARENTESE1_    13
#define _PARENTESE2_    14
#define _VIRGULA_       15
#define _PVIRGULA_      16
#define _CHAVE1_        17
#define _CHAVE2_        18

// Operadores -----------------------------------------------------------------
#define _ATRIBUICAO_    19
#define _SOMA_          20
#define _SUBTRACAO_     21
#define _MULTIPLICAO_   22
#define _DIVISAO_       23

// Operadores Relacionais ----------------------------------------------------- 
#define _IGUALDADE_     24
#define _DIFERENCA_     25
#define _MAIOR_         26
#define _MAIORIGUAL_    27
#define _MENOR_         28
#define _MENORIGUAL_    29

// Outros ---------------------------------------------------------------------
#define _ID_  30
#define _NUM_ 31 
#define _COM_ 32

// Globais ====================================================================
int     QNTDE_TOKENS = 1;

// Protótipo das funções ======================================================
int*    append_token(int* arr_ptr, int new_token);
int     scanner(char palavra[]);
void    token_output(char file_name[], int token[]);

// Implementação ==============================================================
int scanner(char palavra[])
{
   return (-1);
}

int* append_token(int* arr_ptr, int new_token) { QNTDE_TOKENS++; int* new_ptr = (int*) realloc(arr_ptr, QNTDE_TOKENS * sizeof(int)) ; new_ptr[QNTDE_TOKENS - 1] = new_token; return new_ptr; }

void token_output(char file_name[], int tokens[])
{
    FILE * token_output_ptr = fopen(file_name, "w");
    for (int i = 0; i < QNTDE_TOKENS; i++)
        fprintf(token_output_ptr, "%d\n", tokens[i]);
    fclose(token_output_ptr); 
}

// main =======================================================================
int main(int argc, char * argv[])
{
    int *tokens = (int*) malloc(QNTDE_TOKENS * sizeof(int));
    char *str = "lksajdklajdaslkj";
    // é preciso definir um ponteiro para controlar o índice da string, pois a cada espaço um token será retornado !!!
    // a logica aq está quase feita.
    tokens = append_token(tokens, scanner(str));
    token_output("tokens.txt", tokens);

    return 0;
}
