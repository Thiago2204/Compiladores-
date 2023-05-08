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
int    match(int t, int palavra[], int *pos);
void   erro (void);

//  Protótipos Regras da Gramática ==================================
int programa(int palavra[], int *pos); //(1)
int bloco (int palavra[], int *pos); //(2)

//  Declarações
int d_variavel  (int palavra[], int *pos); //(3)
int d_variavel_i(int palavra[], int *pos); //(4)
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
int bool    (int palavra[], int *pos); //(22)
int num     (int palavra[], int *pos); //(23)
int ident   (int palavra[], int *pos); //(24)

//  Implementação das Funções =======================================
//  == SINTAXE ==
// (1) <programa>::= { <declarações de funções> } 'semic' <identificador> <bloco>
int programa(int palavra[], int *pos)
{
    if ()
    return (0);
}

// (2) <bloco>::= '{' [<parte declarações de variáveis] <comando composto> '}'
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

//  == DECLARAÇÕES ==
// (3)
int d_variavel(int palavra[], int *pos)
{
  if (d_variavel_i(palavra, pos) &&
      d_variavel_i(palavra, pos) &&
      d_variavel(palavra, pos))
      return (1);
  else if (d_variavel_i(palavra, pos)) return (1);
  return (0);
}

// (4) <p declarações de variáveis> ::= ('int'|'bool') <lista de identificadores> ';'
int d_variavel_i(int palavra[], int *pos)
{
    if((match(4, palavra, pos) || match(3, palavra, pos)) &&
        lista_id(palavra, pos) && match(16, palavra, pos))
        return (1);
    return (0);
}

// (5) <lista de id> ::= <id>{','<identificador>}
int lista_id(int palavra[], int *pos)
{
    if( ident(palavra, pos)     &&
        match(15, palavra, pos) &&
        ident(palavra, pos))
        return (1);
    return (0);
}

// (6) <decl funcoes> ::= {<declara função>}
int decl_funcoes(int palavra[], int *pos)
{
    return (0);
}

// (7) <decl funcao> ::= 'void'<identificador> '('[<parâmetro formal>]')' <bloco>
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

// (8)
int para_formal(int palavra[], int *pos)
{
  if ((match(4, palavra, pos) ||
     (match(3, palavra, pos))) &&
     ident(palavra, pos))
     return (1);
  return (0);
}

//  == COMANDOS ==
// (9)
int comando_comp(int palavra[], int *pos)
{
  if (comando(palavra, pos) &&
     match(16, palavra, pos) &&
     comando(palavra, pos) &&
     match(16, palavra, pos) &&
     comando_comp(palavra, pos))
     return (1);
  else if (comando(palavra, pos) &&
     match(16, palavra, pos))
     return (1);
  return (0);
}

// (10)
int comando(int palavra[], int *pos)
{
  if (atribuicao(palavra, pos) ||
     chamada_proc(palavra, pos) ||
     comando_cond(palavra, pos) ||
     comando_repe(palavra, pos) ||
     (match(7, palavra, pos) &&
     match(14, palavra, pos) &&
     ident(palavra, pos) &&
     match(15, palavra, pos)))
     return (1);
  return (0);
}

// (11)
int atribuicao(int palavra[], int *pos)
{
  if (variavel(palavra, pos) &&
     match(24, palavra, pos) &&
     expressao(palavra, pos))
     return (1);
  return (0);
}

// (12)
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

// (13)
int parametro(int palavra[], int *pos)
{
  if (ident(palavra, pos) ||
     num(palavra, pos) ||
     bool(palavra, pos) ||
     //VAZIO(palavra, pos)
     )
     return (1);
  return (0);
}

// (14)
int comando_cond(int palavra[], int *pos)
{
  if (match(9, palavra, pos) &&
     match(13, palavra, pos) &&
     expressao(palavra, pos) &&
     match(14, palavra, pos) &&
     match(17, palavra, pos) &&
     comando_comp(palvra, pos))
     if (match(18, palavra, pos) &&
        match(10, palavra, pos) &&
        match(17, palavra, pos) &&
        comando_comp(palavra, pos) &&
        match(18, palavra, pos))
        return (1);
     else if (match(18, palavra, pos))
        return (1);
     else
        return (0);
  return (0);
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
  else if expre_sim(palavra, pos) return (1);
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
     bool(palavra, pos) ||
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
int bool(int palavra[], int *pos)
{
  if ((match(1, palavra, pos)) || (match(0, palavra, pos))) return (1);
  return(0);
}

// (23)
int num(int palavra[], int *pos)
{
  return (0);
}

// (24) 
int ident(int palavra[], int *pos)
{
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
