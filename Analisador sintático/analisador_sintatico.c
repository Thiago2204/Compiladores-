/* 
    Analisador Sintático
    *** Feito por *** (quem for abrindo o código, põe o nome e TIA):
    Amanda Laís Xavier Fontes - 31949436
    Ryan Marco Andrade dos Santos - 42080223
*/

//  Bibliotecas  ====================================================
#include <stdio.h>
#include <stdlib.h>


//  Protótipos das Funções e Declarações ============================
int    lookahead;
int     match(int t, int palavra[], int *pos);
void    erro (void);

/* ##DO CÓDIGO DO BOB##
int lookahead;   /* Excepcionalmente variavel global
##o Bob chama a lookahead na main, sendo "lookahead= palavra[pos];" ##

int  match(int t, char palavra[], int *pos){
	if (lookahead == t){
		lookahead= palavra[++(*pos)];
		return(1);
	}
	return(0);  
}

void trataErro(){
	printf("\n\nERRO DE SINTAXE\n\n");
	/* IMPORTANTE:  Faca um tratamento melhor !!!
}
*/

//  Protótipos Regras da Gramática ==================================
int programa(int palavra[], int *pos);
int bloco (int palavra[], int *pos);

//  Declarações
int d_variavel_i(int palavra[], int *pos);
int d_variavel  (int palavra[], int *pos);
int lista_id    (int palavra[], int *pos);
int decl_funcoes(int palavra[], int *pos);
int declara_func(int palavra[], int *pos);
int para_formal (int palavra[], int *pos);

//  Comandos
int comando_comp(int palavra[], int *pos);
int comando     (int palavra[], int *pos);
int atribuicao  (int palavra[], int *pos);
int chamada_proc(int palavra[], int *pos);
int parametro   (int palavra[], int *pos);
int comando_cond(int palavra[], int *pos);
int comando_repe(int palavra[], int *pos);

//  Expressões
int expressao   (int palavra[], int *pos);
int relacao     (int palavra[], int *pos);
int expre_sim   (int palavra[], int *pos);
int termo       (int palavra[], int *pos);
int fator       (int palavra[], int *pos);
int variavel    (int palavra[], int *pos);

//  Numeros e Identificadores
int bool    (int palavra[], int *pos);
int num     (int palavra[], int *pos);
int ident   (int palavra[], int *pos);

//  Implementação das Funções =======================================
// <programa>::= { <declarações de funções> } 'semic' <identificador> <bloco>
int programa(int palavra[], int *pos) 
{
    if ()
    return (0);
}

// <bloco>::= '{' [<parte declarações de variáveis] <comando composto> '}'
int bloco(int palavra[], int *pos)
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
int d_variavel_i(int palavra[], int *pos)
{
    if((match(4, palavra, pos) || match(3, palavra, pos)) &&
        lista_id(palavra, pos) && match(16, palavra, pos))
        return (1);
    return (0);
}

// <lista de id> ::= <id>{','<identificador>}
int lista_id(int palavra[], int *pos) 
{
    if( ident(palavra, pos)     &&
        match(15, palavra, pos) &&
        ident(palavra, pos))
        return (1);
    return (0);
}

// <decl funcoes> ::= {<declara função>}
int decl_funcoes(int palavra[], int *pos)
{
    return (0);
}

// <decl funcao> ::= 'void'<identificador> '('[<parâmetro formal>]')' <bloco>
// TÁ ERRADO ISSO AQ
int declara_func(int palavra[], int *pos)
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
    int palavra[] = "";
    int pos = 0;

    lookahead = palavra[pos];
    
    return 0;
}
