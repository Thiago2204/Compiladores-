// ANALISADOR LÉXICO - ETAPA 2 ================================================

// Inclusões ==================================================================
#include <stdio.h>
#include <stdlib.h>

// Definições =================================================================
// Palavras reservadas --------------------------------------------------------
#define _FALSE_ 0
#define _TRUE_  1
#define _ERROR_ 2 
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
char**  PTR_PALAVRA;

// Protótipo das funções ======================================================
int*    append_token(int* arr_ptr, int new_token);
int     scanner(char** palavra);
void    token_output(char file_name[], int token[]);

// Implementação ==============================================================
int scanner(char** palavra)
{
    char c;

    q0: // somente neste estado haverá um switch case devido as diversas possibilidades
        c == **palavra;
        switch (c)
        {
        case 'f': goto q71;
        case 't': goto q66;
        case 'b': goto q61;
        case 'i': goto q50;
            
        default:
            goto poco;
        }
        
    // false
    q71:
        c == (*palavra)++; if (c == 'a') goto q72; else goto poco;
    q72:
        c == (*palavra)++; if (c == 'l') goto q73; else goto poco;
    q73:
        c == (*palavra)++; if (c == 's') goto q74; else goto poco;
    q74:
        c == (*palavra)++; if (c == 'e') goto q75; else goto poco;
    q75:
        c == (*palavra)++; if (c == ' ') goto q76; else goto poco;
    q76:
        return (_FALSE_);
    
    // true
    q66:
        c == (*palavra)++; if (c == 'r') goto q67; else goto poco;
    q67:
        c == (*palavra)++; if (c == 'u') goto q68; else goto poco;
    q68:
        c == (*palavra)++; if (c == 'e') goto q69; else goto poco;
    q69:
        c == (*palavra)++; if (c == ' ') goto q70; else goto poco;
    q70:
        return (_TRUE_);
    
    // bool
    q61:
        c == (*palavra)++; if (c == 'o') goto q62; else goto poco;
    q62:
        c == (*palavra)++; if (c == 'o') goto q63; else goto poco;
    q63:
        c == (*palavra)++; if (c == 'l') goto q64; else goto poco;
    q64:
        c == (*palavra)++; if (c == ' ') goto q65; else goto poco;
    q65:
        return (_BOOL_);

    // int - if
    q50:
        c == (*palavra)++; if (c == 'n') goto q51; else if (c == 'f') goto q54; else goto poco;
    q51:
        c == (*palavra)++; if (c == 't') goto q52; else goto poco;
    q52:
        c == (*palavra)++; if (c == ' ') goto q53; else goto poco;
    q53:
        return (_INT_);
    q54:
        c == (*palavra)++; if (c == ' ') goto q55; else goto poco;
    q55:
        return (_IF_);

    poco:
        return (_ERROR_);
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
    char *str = "isso aq será a string de todo o código fonte yeeeey";
    
    tokens = append_token(tokens, scanner(str));
    token_output("tokens.txt", tokens);

    return 0;
}
