/* 
    Analisador Sintático
    *** Feito por *** (quem for abrindo o código, põe o nome e TIA):
    Ryan Marco Andrade dos Santos - 42080223
*/

//  Bibliotecas  ====================================================
#include <stdio.h>
#include <stdlib.h>


//  Protótipos das Funções e Declarações ============================
char    lookahead;
int     match(char t, char palavra[], int *pos);
void    erro (void);

//  Protótipos Regras da Gramática ==================================
int programa(char palavra[], int *pos);
int bloco (char palavra[], int *pos);

//  Declarações
int d_variavel_i(char palavra[], int *pos);
int d_variavel(char palavra[], int *pos);
int lista_id(char palavra[], int *pos);
int decl_funcoes(char palavra[], int *pos);
int declara_funcao(char palavra[], int *pos);
int para_formal(char palavra[], int *pos);

//  Comandos
int comando_comp(char palavra[], int *pos);
int comando(char palavra[], int *pos);
int atribuicao(char palavra[], int *pos);
int chamada_proc(char palavra[], int *pos);
int parametro(char palavra[], int *pos);
int comando_cond(char palavra[], int *pos);
int comando_repe(char palavra[], int *pos);

//  Expressões
int expressao(char palavra[], int *pos);
int relacao(char palavra[], int *pos);
int expre_sim(char palavra[], int *pos);
int termo(char palavra[], int *pos);
int fator(char palavra[], int *pos);
int variavel(char palavra[], int *pos);

//  Numeros e Identificadores
int bool(char palavra[], int *pos);
int num(char palavra[], int *pos);
int ident(char palavra[], int *pos);

//  Implementação das Funções =======================================


//  Main ============================================================
int main(int argc, char const *argv[])
{
    char palavra[] = "";
    int pos = 0;

    lookahead = palavra[pos];
    
    return 0;
}
