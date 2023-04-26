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

// Protótipo das funções ======================================================
int     scanner(char* palavra, char** atributo);
void    token_output(char file_name[], int token[]);

// Implementação ==============================================================
int scanner(char* palavra, char** atributo)
{
    char c;
    int attr_buffer = 1;
    char* attr = (char*) malloc (sizeof(char) * attr_buffer);

    q0: // somente neste estado haverá um switch case devido as diversas possibilidades
        c = *palavra;
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

		case '/': goto q1;
		case '+': goto q7;
        case '-': goto q9;
        case '*': goto q11;
        case '<': goto q13;
        case '>': goto q19;
		case '=': goto q23;

        case '0': goto q97;
        case '1': goto q97;
        case '2': goto q97;
        case '3': goto q97;
        case '4': goto q97;
        case '5': goto q97;
        case '6': goto q97;
        case '7': goto q97;
        case '8': goto q97;
        case '9': goto q97;

        case '_': goto q48;

        default:
            goto poco;
        }
        
    // false
    q71:
        *(palavra++); c = *palavra; 
        if (c == 'a') goto q72; else goto poco;
    q72:
        *(palavra++); c = *palavra; 
        if (c == 'l') goto q73; else goto poco;
    q73:
        *(palavra++); c = *palavra; 
        if (c == 's') goto q74; else goto poco;
    q74:
        *(palavra++); c = *palavra; 
        if (c == 'e') goto q75; else goto poco;
    q75:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q76; else goto poco;
    q76:
        return (_FALSE_);
    
    // true
    q66:
        *(palavra++); c = *palavra; 
        if (c == 'r') goto q67; else goto poco;
    q67:
        *(palavra++); c = *palavra; 
        if (c == 'u') goto q68; else goto poco;
    q68:
        *(palavra++); c = *palavra; 
        if (c == 'e') goto q69; else goto poco;
    q69:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q70; else goto poco;
    q70:
        return (_TRUE_);
    
    // bool
    q61:
        *(palavra++); c = *palavra; 
        if (c == 'o') goto q62; else goto poco;
    q62:
        *(palavra++); c = *palavra; 
        if (c == 'o') goto q63; else goto poco;
    q63:
        *(palavra++); c = *palavra; 
        if (c == 'l') goto q64; else goto poco;
    q64:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q65; else goto poco;
    q65:
        return (_BOOL_);

    // int - if
    q50:
        *(palavra++); c = *palavra; 
        if (c == 'n') goto q51; else if (c == 'f') goto q54; else goto poco;
    q51:
        *(palavra++); c = *palavra; 
        if (c == 't') goto q52; else goto poco;
    q52:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q53; else goto poco;
    q53:
        return (_INT_);
    q54:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q55; else goto poco;
    q55:
        return (_IF_);

    // else
    q56:
        *(palavra++); c = *palavra; 
        if (c == 'l') goto q57; else goto poco;
    q57:
        *(palavra++); c = *palavra; 
        if (c == 's') goto q58; else goto poco;
    q58:
        *(palavra++); c = *palavra; 
        if (c == 'e') goto q59; else goto poco;
    q59:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q60; else goto poco;
    q60:
        return (_ELSE_);

    // print - proc
    q39:
        *(palavra++); c = *palavra; 
        if (c == 'r') goto q40; else goto poco;
    q40:
        *(palavra++); c = *palavra; 
        if (c == 'i') goto q41; else if (c == 'o') goto q45; else goto poco;
    q41:
        *(palavra++); c = *palavra; 
        if (c == 'n') goto q42; else goto poco;
    q42:
        *(palavra++); c = *palavra; 
        if (c == 't') goto q43; else goto poco;
    q43:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q44; else goto poco;
    q44:
        return (_PRINT_);
    q45:
        *(palavra++); c = *palavra; 
        if (c == 'c') goto q46; else goto poco;
    q46:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q47; else goto poco;
    q47: 
        return(_PROC_);
    
    // semic
    q77:
        *(palavra++); c = *palavra; 
        if (c == 'e') goto q78; else goto poco;
    q78:
        *(palavra++); c = *palavra; 
        if (c == 'm') goto q79; else goto poco;
    q79:
        *(palavra++); c = *palavra; 
        if (c == 'i') goto q80; else goto poco;
    q80:
        *(palavra++); c = *palavra; 
        if (c == 'c') goto q81; else goto poco;
    q81:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q82; else goto poco;
    q82:
        return (_SEMIC_);

    // void
    q83:
        *(palavra++); c = *palavra; 
        if (c == 'o') goto q84; else goto poco;
    q84:
        *(palavra++); c = *palavra; 
        if (c == 'i') goto q85; else goto poco;
    q85:
        *(palavra++); c = *palavra; 
        if (c == 'd') goto q86; else goto poco;
    q86:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q87; else goto poco;
    q87:
        return (_VOID_);

    // while
    q88: 
        *(palavra++); c = *palavra; 
        if (c == 'h') goto q89; else goto poco;
    q89:
        *(palavra++); c = *palavra; 
        if (c == 'i') goto q90; else goto poco;
    q90:
        *(palavra++); c = *palavra; 
        if (c == 'l') goto q91; else goto poco;
    q91:
        *(palavra++); c = *palavra; 
        if (c == 'e') goto q92; else goto poco;
    q92:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q93; else goto poco;
    q93:
        return (_WHILE_);

    // do
    q94:
        *(palavra++); c = *palavra; 
        if (c == 'o') goto q95; else goto poco;
    q95:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q96; else goto poco;
    q96:
        return (_DO_);

    // Símbolos
    q31:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q33; else goto poco;
    q33:
        return (_PARENTESE1_);
    q27:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q34; else goto poco;
    q34:
        return (_PARENTESE2_);
    q28:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q35; else goto poco;
    q35:
        return (_VIRGULA_);
    q29:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q36; else goto poco;
    q36:
        return (_PVIRGULA_);
    q30:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q37; else goto poco;
    q37:
        return (_CHAVE1_);
    q32:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q38; else goto poco;
    q38:
        return (_CHAVE2_);

	// Operadores
	q1:
		*(palavra++); c = *palavra; 
        if (c == ' ') goto q6; else if (c == '*') goto q2; else goto poco;
	q6:
		return (_DIVISAO_);
    q7:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q8; else goto poco;
    q8:
		return (_SOMA_);
    q9:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q10; else goto poco;
    q10:
		return (_SUBTRACAO_);
    q11:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q12; else goto poco;
    q12:
		return (_MULTIPLICAO_);
    q13:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q14; else if (c == '>') goto q15; else if (c == '=') goto q17; else goto poco;
    q14:
		return (_MENOR_);
    q15:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q16; else goto poco;
    q16:
		return (_DIFERENCA_);
    q17:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q18; else goto poco;
    q18:
		return (_MENORIGUAL_);
    q19:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q20; else if (c == '=') goto q21; else goto poco;
    q20:
		return (_MAIOR_);
    q21:
        *(palavra++); c = *palavra; 
        if (c == ' ') goto q22; else goto poco;
    q22:
		return (_MAIORIGUAL_);
	q23:
		*(palavra++); c = *palavra; 
        if (c == ' ') goto q24; else if (c == '=') goto q25; else goto poco;
	q24:
		return (_ATRIBUICAO_);
	q25:
		*(palavra++); c = *palavra; 
        if (c == ' ') goto q26; else goto poco;
	q26:
		return (_IGUALDADE_);

    // Comentario
	q2:
		*(palavra++); c = *palavra; 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_') || (c == '}') || (c == '{') || (c == ';') || (c == ',') || (c == '(') || (c == ')') || (c == '=') || (c == '>') || (c == '<') || (c == '-') || (c == '+') || (c == '/') || (c == ' ')) goto q2; else if (c == '*') goto q3; else goto poco;
	q3:
		*(palavra++); c = *palavra; 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_') || (c == '}') || (c == '{') || (c == ';') || (c == ',') || (c == '(') || (c == ')') || (c == '=') || (c == '>') || (c == '<') || (c == '-') || (c == '+') || (c == '*') || (c == ' ')) goto q3; else if (c == '/') goto q4; else goto poco;
	q4:
		*(palavra++); c = *palavra; 
        if (c == ' ') goto q5; else goto poco;
	q5:
		return (_COM_);

    // Numero
    q97:
        *(palavra++); c = *palavra; 
        if (c >= '0' && c <= '9')
        {
            attr[attr_buffer-1] = c;
            attr = (char*) realloc (attr, sizeof(char) * (attr_buffer++));
            goto q97;
        }  
        else if (c == ' ') goto q98; else goto poco;

    q98:
        *atributo = attr;
		return (_NUM_);

    // Identificador
    q48:
        *(palavra++); c = *palavra; 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        { 
            attr[attr_buffer] = c;
            attr = (char*) realloc (attr, sizeof(char) * (attr_buffer++));
            goto q48;
        }
        else if (c == ' ') goto q49; else goto poco;
    q49:
        *atributo = attr;
        return (_ID_);

    // Poco
    poco:
        return (_ERROR_);
}

void token_output(char file_name[], int token[])
{
    FILE * token_output_ptr = fopen(file_name, "a");
    fprintf(token_output_ptr, "%d,%d", token[0], token[1]);
    fclose(token_output_ptr); 
}

// main =======================================================================
int main(int argc, char * argv[])
{
    char *str = "/* ** _x int */ ";
    int token;
    char* attr;
    
    // Apaga o conteúdo anterior do arquivo de saída
    FILE* output = fopen(argv[1], "wa");  // O argumento é o nome do arquivo de saída

    /* isso vai dentro do laço */
    token = scanner(str, attr);
    fprintf(output, "<%d, %s>", token, attr);
    /* ----------------------- */


    close(output);
    return 0;
}
