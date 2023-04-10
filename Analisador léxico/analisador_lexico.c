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
        case 'e': goto q56;
        case 'p': goto q39;
        case 's': goto q77;
        case 'v': goto q83;
        case 'w': goto q88;
        case 'd': goto q94;

        case '(': goto q31;
        case ')': goto q27;
        case ',': goto q28;
        case ';': goto q29;
        case '{': goto q30;
        case '}': goto q32; 

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

    // else
    q56:
        c == (*palavra)++; if (c == 'l') goto q57; else goto poco;
    q57:
        c == (*palavra)++; if (c == 's') goto q58; else goto poco;
    q58:
        c == (*palavra)++; if (c == 'e') goto q59; else goto poco;
    q59:
        c == (*palavra)++; if (c == ' ') goto q60; else goto poco;
    q60:
        return (_ELSE_);

    // print - proc
    q39:
        c == (*palavra)++; if (c == 'r') goto q40; else goto poco;
    q40:
        c == (*palavra)++; if (c == 'i') goto q41; else if (c == 'o') goto q45; else goto poco;
    q41:
        c == (*palavra)++; if (c == 'n') goto q42; else goto poco;
    q42:
        c == (*palavra)++; if (c == 't') goto q43; else goto poco;
    q43:
        c == (*palavra)++; if (c == ' ') goto q44; else goto poco;
    q44:
        return (_PRINT_);
    q45:
        c == (*palavra)++; if (c == 'c') goto q46; else goto poco;
    q46:
        c == (*palavra)++; if (c == ' ') goto q47; else goto poco;
    q47: 
        return(_PROC_);
    
    // semic
    q77:
        c == (*palavra)++; if (c == 'e') goto q78; else goto poco;
    q78:
        c == (*palavra)++; if (c == 'm') goto q79; else goto poco;
    q79:
        c == (*palavra)++; if (c == 'i') goto q80; else goto poco;
    q80:
        c == (*palavra)++; if (c == 'c') goto q81; else goto poco;
    q81:
        c == (*palavra)++; if (c == ' ') goto q82; else goto poco;
    q82:
        return (_SEMIC_);

    // void
    q83:
        c == (*palavra)++; if (c == 'o') goto q84; else goto poco;
    q84:
        c == (*palavra)++; if (c == 'i') goto q85; else goto poco;
    q85:
        c == (*palavra)++; if (c == 'd') goto q86; else goto poco;
    q86:
        c == (*palavra)++; if (c == ' ') goto q87; else goto poco;
    q87:
        return (_VOID_);

    // while
    q88: 
        c == (*palavra)++; if (c == 'h') goto q89; else goto poco;
    q89:
        c == (*palavra)++; if (c == 'i') goto q90; else goto poco;
    q90:
        c == (*palavra)++; if (c == 'l') goto q91; else goto poco;
    q91:
        c == (*palavra)++; if (c == 'e') goto q92; else goto poco;
    q92:
        c == (*palavra)++; if (c == ' ') goto q93; else goto poco;
    q93:
        return (_WHILE_);

    // do
    q94:
        c == (*palavra)++; if (c == 'o') goto q95; else goto poco;
    q95:
        c == (*palavra)++; if (c == ' ') goto q96; else goto poco;
    q96:
        return (_DO_);

    // Símbolos
    q31:
        c == (*palavra)++; if (c == ' ') goto q33; else goto poco;
    q33:
        return (_PARENTESE1_);
    q27:
        c == (*palavra)++; if (c == ' ') goto q34; else goto poco;
    q34:
        return (_PARENTESE2_);
    q28:
        c == (*palavra)++; if (c == ' ') goto q35; else goto poco;
    q35:
        return (_VIRGULA_);
    q29:
        c == (*palavra)++; if (c == ' ') goto q36; else goto poco;
    q36:
        return (_PVIRGULA_);
    q30:
        c == (*palavra)++; if (c == ' ') goto q37; else goto poco;
    q37:
        return (_CHAVE1_);
    q32:
        c == (*palavra)++; if (c == ' ') goto q38; else goto poco;
    q38:
        return (_CHAVE2_);


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
