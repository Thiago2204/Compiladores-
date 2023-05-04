/* 
    Analisador Sintático
    *** Feito por *** (quem for abrindo o código, põe o nome e TIA):
    Ryan Marco Andrade dos Santos - 42080223
*/

//  Bibliotecas  ====================================================
#include <stdio.h>
#include <stdlib.h>


//  Protótipos das Funções e Declarações ============================
int    lookahead;
int     match(int t, char palavra[], int *pos);
void    erro (void);

//  Protótipos Regras da Gramática ==================================
int programa(char palavra[], int *pos);
int bloco (char palavra[], int *pos);

//  Declarações
int d_variavel_i(char palavra[], int *pos);
int d_variavel  (char palavra[], int *pos);
int lista_id    (char palavra[], int *pos);
int decl_funcoes(char palavra[], int *pos);
int declara_func(char palavra[], int *pos);
int para_formal (char palavra[], int *pos);

//  Comandos
int comando_comp(char palavra[], int *pos);
int comando     (char palavra[], int *pos);
int atribuicao  (char palavra[], int *pos);
int chamada_proc(char palavra[], int *pos);
int parametro   (char palavra[], int *pos);
int comando_cond(char palavra[], int *pos);
int comando_repe(char palavra[], int *pos);

//  Expressões
int expressao   (char palavra[], int *pos);
int relacao     (char palavra[], int *pos);
int expre_sim   (char palavra[], int *pos);
int termo       (char palavra[], int *pos);
int fator       (char palavra[], int *pos);
int variavel    (char palavra[], int *pos);

//  Numeros e Identificadores
int bool    (char palavra[], int *pos);
int num     (char palavra[], int *pos);
int ident   (char palavra[], int *pos);

//  Implementação das Funções =======================================
// !! PRECISA VERIFICAR COMO REALIZAR A REPETIÇÃO DA CADEIA -> qnd o não-terminal aparece entre chaves {}
// <programa>::= { <declarações de funções> } 'semic' <identificador> <bloco>
int programa(char palavra[], int *pos) 
{
    if( decl_funcoes(palavra, pos)   &&
        match(6, palavra, pos)       &&
        ident(palavra, pos)          &&
        bloco(palavra, pos))
        return (1);
    return (0);
}

// <bloco>::= '{' [<parte declarações de variáveis] <comando composto> '}'
int bloco(char palavra[], int *pos)
{
    if(match(17, palavra, pos))  // {
    {
        if (d_variavel_i(palavra, pos)) // parte declarações de variáveis
        {
            if (comando_comp(palavra, pos) && match(18, palavra, pos))  // comando }
                return (1);
        }
        else if (comando_comp(palavra, pos) && match(18, palavra, pos)) // comando }
            return (1);
    }
    return (0);
}

// <p declarações de variáveis> ::= ('int'|'bool') <lista de identificadores> ';'
int d_variavel_i(char palavra[], int *pos)
{
    if((match(4, palavra, pos) || match(3, palavra, pos)) &&
        lista_id(palavra, pos) && match(16, palavra, pos))
        return (1);
    return (0);
}

// <lista de id> ::= <id>{','<identificador>}
int lista_id(char palavra[], int *pos) 
{
    if( ident(palavra, pos)     &&
        match(15, palavra, pos) &&
        ident(palavra, pos))
        return (1);
    return (0);
}

// <decl funcoes> ::= {<declara função>}
int decl_funcoes(char palavra[], int *pos)
{
    return (0);
}

// <decl funcao> ::= 'void'<identificador> '('[<parâmetro formal>]')' <bloco>
// TÁ ERRADO ISSO AQ
int declara_func(char palavra[], int *pos)
{
    if (match(5, palavra, pos) &&
        ident(palavra, pos)    &&
        match(13, palavra, pos))
        if (para_formal(palavra, pos))
            if (match(14, palavra, pos) && bloco(palavra, pos))
                return (1);
            else return (0);
        if (match(14, palavra, pos) && bloco(palavra, pos))
            return (1);
    return (0);
}

//  Main ============================================================
int main(int argc, char const *argv[])
{
    char palavra[] = "";
    int pos = 0;

    lookahead = palavra[pos];
    
    return 0;
}
