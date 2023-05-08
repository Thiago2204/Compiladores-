/*
    Analisador Sintático
    *** Feito por *** (quem for abrindo o código, põe o nome e TIA):
    Amanda Laís Xavier Fontes - 31949436
    Ryan Marco Andrade dos Santos - 42080223
*/
// !! ENCONTRAR UMA FORMA DE REPRESENTAR O VAZIO
//  Bibliotecas  ====================================================
#include <stdio.h>
#include <stdlib.h>


//  Protótipos das Funções e Declarações ============================
int    lookahead;
int    match(int t, int palavra[], int *pos);
void   erro (void);

//  Protótipos Regras da Gramática ==================================
int programa(int palavra[], int *pos); //(1)
int bloco (int palavra[], int *pos); //(2)

//  Declarações
int d_variaveis  (int palavra[], int *pos); //(3)
int decl_variavel(int palavra[], int *pos); //(4)
int lista_id    (int palavra[], int *pos); //(5)
int decl_funcoes(int palavra[], int *pos); //(6)
int declara_func(int palavra[], int *pos); //(7)
int para_formal (int palavra[], int *pos); //(8)

//  Comandos
int comando_comp(int palavra[], int *pos); //(9)
int comando     (int palavra[], int *pos); //(10)
int atribuicao  (int palavra[], int *pos); //(11)
int chamada_proc(int palavra[], int *pos); //(12)
int parametro   (int palavra[], int *pos); //(13)
int comando_cond(int palavra[], int *pos); //(14)
int comando_repe(int palavra[], int *pos); //(15)

//  Expressões
int expressao   (int palavra[], int *pos); //(16)
int relacao     (int palavra[], int *pos); //(17)
int expre_sim   (int palavra[], int *pos); //(18)
int termo       (int palavra[], int *pos); //(19)
int fator       (int palavra[], int *pos); //(20)
int variavel    (int palavra[], int *pos); //(21)

//  Numeros e Identificadores
int booleano(int palavra[], int *pos); //(22)
int num     (int palavra[], int *pos); //(23)
int ident   (int palavra[], int *pos); //(24)

//  Implementação das Funções =======================================
//  == SINTAXE ==
// (1) <programa>::= { <declarações de funções> } 'semic' <identificador> <bloco>
int programa(int palavra[], int *pos)
{
    if (decl_funcoes(palavra, pos) && match(6, palavra, pos) && ident(palavra, pos) && bloco(palavra, pos))
        return (1);
    else if (match(6, palavra, pos) && ident(palavra, pos))
        return (1);
    return (0);
}

// (2) <bloco>::= '{' [<parte declarações de variáveis] <comando composto> '}'
int bloco(int palavra[], int *pos)
{
    if (match(17, palavra, pos) && d_variaveis(palavra, pos) && comando_comp(palavra, pos) && match(18, palavra, pos))
        return (1);
    else if (match(17, palavra, pos) && comando_comp(palavra, pos) && match(18, palavra, pos))
        return (1);
    return (0);
}

//  == DECLARAÇÕES ==
// (3) <parte declarações de variáveis> ::= <declaração de variável> {<declaração de variável>}
int d_variaveis(int palavra[], int *pos)
{
    if (decl_variavel(palavra, pos)  &&
        d_variaveis(palavra, pos))
        return (1);
    else if (decl_variavel(palavra, pos))
        return (1);
    else return (0);
}

// (4) <declaração de variável> ::= ('int'|'booleano') <lista de identificadores> ';'
int decl_variavel(int palavra[], int *pos)
{
    if (match(4, palavra, pos)  &&  //int
        lista_id(palavra, pos)  &&
        match(16, palavra, pos)     //;
        ) return (1);
    else 
    if (match(3, palavra, pos)  &&  // booleano
        lista_id(palavra, pos)  &&
        match(16, palavra, pos)     //;
        ) return (1);
    return (0);
}

// (5) <lista de id> ::= <id>{','<identificador>}
int lista_id(int palavra[], int *pos)
{
    if( ident(palavra, pos)     &&
        match(15, palavra, pos) &&
        lista_id(palavra, pos))
        return (1);
    else if (ident(palavra, pos)) return (1);
    return (0);
}

// (6) <decl funcoes> ::= {<declara função>}
int decl_funcoes(int palavra[], int *pos)
{
    if( declara_func(palavra, pos)   &&
        decl_funcoes(palavra, pos))
        return (1);
    return(1);
}

// (7) <decl funcao> ::= 'void'<identificador> '('[<parâmetro formal>]')' <bloco>
int declara_func(int palavra[], int *pos)
{
    if (match(5, palavra, pos)  &&
        ident(palavra, pos)     &&
        match(13, palavra, pos) &&
        para_formal(palavra, pos)&&
        match(14, palavra, pos) &&
        bloco(palavra, pos))
        return (1);
    if (match(5, palavra, pos)  &&
        ident(palavra, pos)     &&
        match(13, palavra, pos) && 
        match(14, palavra, pos) &&
        bloco(palavra, pos))
        return(1);
    return (0);
}

// (8) <parâmetro formal> ::= (int | booleano) <indentificador>
int para_formal(int palavra[], int *pos)
{
    if (match(4, palavra, pos) && ident(palavra, pos)) return (1);
    else if (match(5, palavra, pos) && ident(palavra, pos)) return (1);
    else return (0);
}

//  == COMANDOS ==
// (9) <comando composto> ::= <comando>';' {<comando> ;}
int comando_comp(int palavra[], int *pos)
{
    if (comando(palavra, pos) && match(16, palavra, pos)) return (1);
    else if (comando_comp(palavra, pos)) return (1);
    return (0);
}

// (10) <comando> ::= atribuição
//                  | chamada de procedimento
//                  | comando condicional
//                  | comando repetitivo
//                  | print ( identificador )
int comando(int palavra[], int *pos)
{
    if (atribuicao(palavra, pos)    ||
        chamada_proc(palavra, pos)  ||
        comando_cond(palavra, pos)  ||
        comando_repe(palavra, pos)  ||
        (match(7, palavra, pos) && match(13, palavra, pos) && ident(palavra, pos) && match(14, palavra, pos)))
        return(1);
    printf("Estou na comando! -> P: %d", palavra[*pos]); return(0);
}

// (11) <atribuicao> ::= <variavel> = <expressao>
int atribuicao(int palavra[], int *pos)
{
    if (variavel(palavra, pos)  &&
        match(24, palavra, pos) &&
        expressao(palavra, pos))
        return (1);
    return (0);
}

// (12) <chamada de procedimento> ::= 'proc' <identificador> '{'[<parametro>]'}'
int chamada_proc(int palavra[], int *pos)
{
  if(match(8, palavra, pos) &&
     ident(palavra, pos) &&
     match(13, palavra, pos))
        if (parametro(palavra, pos) && match(14, palavra, pos))
            return (1);
        else if (ident(palavra, pos) && match(14, palavra, pos))
            return (1);
  return (0);
}

// (13) <parâmetro> ::= [ ( <identificador> | <número> | <booleano> ) ]
int parametro(int palavra[], int *pos)
{
    if       (ident(palavra, pos))    return (1);
    else if  (num(palavra, pos))      return (1);
    else if  (booleano(palavra, pos)) return (1);
    else return (1);
}

// (14) <comando_cond> ::= 'if' '('<expressão>')''{'<comando_comp>'}'['else' '{'<comando_comp>'}']
int comando_cond(int palavra[], int *pos)
{
  if (  match(9, palavra, pos) &&
        match(13, palavra, pos) &&
        expressao(palavra, pos) &&
        match(14, palavra, pos) &&
        match(17, palavra, pos) &&
        comando_comp(palavra, pos))
        if (match(18, palavra, pos) &&
        match(10, palavra, pos) &&
        match(17, palavra, pos) &&
        comando_comp(palavra, pos) &&
        match(18, palavra, pos))
        return (1);
        else if (match(18, palavra, pos))
        return (1);
    else return (0);
}

// (15)
int comando_repe(int palavra[], int *pos)
{
    if (match(12, palavra, pos) &&
       match(17, palavra, pos) &&
       comando_comp(palavra, pos) &&
       match(18, palavra, pos) &&
       match(11, palavra, pos) &&
       match(13, palavra, pos) &&
       expressao(palavra, pos) &&
       match(14, palavra, pos))
       return (1);
    return (0);
}

// == EXPRESSÕES ==

// 16
int expressao(int palavra[], int *pos)
{
  if (expre_sim(palavra, pos) &&
      relacao(palavra, pos) &&
      expre_sim(palavra, pos))
      return (1);
  else if (expre_sim(palavra, pos)) return (1);
  return (0);
}

// (17)
int relacao(int palavra[], int *pos)
{
    if (match(24, palavra, pos) &&
       match(24, palavra, pos))
       return (1);
    else if(match(28, palavra, pos) &&
       match(26, palavra, pos))
       return (1);
    else if(match(28, palavra, pos) &&
       match(24, palavra, pos))
       return (1);
    else if(match(26, palavra, pos) &&
       match(24, palavra, pos))
       return(1);
    else if(match(24, palavra, pos)) return (1);
    else if(match(26, palavra, pos)) return (1);
    return (0);
}

// (18)
int expre_sim(int palavra[], int *pos)
{
    if (match(20, palavra, pos) && termo(palavra, pos))
        return (1);
    else if (match(21, palavra, pos) && termo(palavra, pos))
        return(1);
    else if (expre_sim(palavra, pos))
        return (1);
    else if (termo(palavra, pos))
        return (1);    
    return (0);
}

// (19)
int termo(int palavra[], int *pos)
{
    if (fator(palavra, pos) &&
       match(22, palavra, pos) &&
       fator(palavra, pos) &&
       termo(palavra, pos))
       return (1);
    else if(fator(palavra, pos) &&
       match(23, palavra, pos) &&
       fator(palavra, pos) &&
       termo(palavra, pos))
       return (1);
    else if(fator(palavra, pos)) return (1);
    return (0);
}

// (20)
int fator(int palavra[], int *pos)
{
    if (variavel(palavra, pos) ||
        num(palavra, pos) ||
        booleano(palavra, pos) ||
        (match(13, palavra, pos) &&
        expre_sim(palavra, pos) &&
        match(14, palavra, pos)))
        return (1);
  return (0);
}

// (21)
int variavel(int palavra[], int *pos)
{
    if (ident(palavra, pos)) return (1);
    return (0);
}

// == NÚMEROS E IDENTIFICADORES ==
// (22)
int booleano(int palavra[], int *pos)
{
    if ((match(1, palavra, pos)) || (match(0, palavra, pos))) return (1);
    return(0);
}

// (23)
int num(int palavra[], int *pos)
{
    if (match(31, palavra, pos)) return (1);
    return (0);
}

// (24) 
int ident(int palavra[], int *pos)
{
    if (match(30, palavra, pos)) return (1);
    return (0);
}

//  MATCH ===========================================================
int match(int t, int palavra[], int* pos)
{
    if (lookahead == t)
    {
        printf("Lookahead: %d\nPalavra na posição %d: %d\n", lookahead, *pos, palavra[*pos]);
        lookahead = palavra[++(*pos)];
        return (1);
    }
    return (0);
}

//  Main ============================================================
int main(int argc, char const *argv[])
{
    int palavra[] = {6, 30, 17, 7, 13, 30, 14, 16, 18};
    int pos = 0;

    lookahead = palavra[pos];
    if(programa(palavra, &pos))
        printf("shbow de bola");
    else
        printf("deu ruim :C");
    system("PAUSE");
    return 0;
}
 