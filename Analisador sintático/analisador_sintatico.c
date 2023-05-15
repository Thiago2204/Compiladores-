#include <stdio.h>
#include <stdlib.h>

//  Protótipos das Funções e Declarações ============================
int    lookahead;
int    match(int t, int palavra[], int linha[], int* pos);
void   erro (void);

//  Protótipos Regras da Gramática ==================================
int programa(int palavra[], int linha[], int* pos); //(1)
int bloco (int palavra[], int linha[], int* pos); //(2)

//  Declarações
int d_variaveis  (int palavra[], int linha[], int* pos); //(3)
int decl_variavel(int palavra[], int linha[], int* pos); //(4)
int lista_id    (int palavra[], int linha[], int* pos); //(5)
int decl_funcoes(int palavra[], int linha[], int* pos); //(6) x
int declara_func(int palavra[], int linha[], int* pos); //(7)
int para_formal (int palavra[], int linha[], int* pos); //(8)

//  Comandos
int comando_comp(int palavra[], int linha[], int* pos); //(9)
int comando     (int palavra[], int linha[], int* pos); //(10)
int atribuicao  (int palavra[], int linha[], int* pos); //(11)
int chamada_proc(int palavra[], int linha[], int* pos); //(12)
int parametro   (int palavra[], int linha[], int* pos); //(13) x
int comando_cond(int palavra[], int linha[], int* pos); //(14)
int comando_repe(int palavra[], int linha[], int* pos); //(15)

//  Expressões
int expressao   (int palavra[], int linha[], int* pos); //(16)
int relacao     (int palavra[], int linha[], int* pos); //(17)
int expre_sim   (int palavra[], int linha[], int* pos); //(18)
int termo       (int palavra[], int linha[], int* pos); //(19)
int fator       (int palavra[], int linha[], int* pos); //(20)
int variavel    (int palavra[], int linha[], int* pos); //(21)

//  Numeros e Identificadores
int booleano(int palavra[], int linha[], int* pos); //(22)
int num     (int palavra[], int linha[], int* pos); //(23)
int ident   (int palavra[], int linha[], int* pos); //(24)

//  Implementação das Funções =======================================
//  == SINTAXE ==
// (1) <programa>::= { <declarações de funções> } 'semic' <identificador> <bloco>
int programa(int palavra[], int linha[], int* pos)
{
    if (decl_funcoes(palavra, linha, pos) && match(6, palavra, linha, pos) && ident(palavra, linha, pos) && bloco(palavra, linha, pos))
        return (1);
    else if (match(6, palavra, linha, pos) && ident(palavra, linha, pos))
        return (1);
    return (0);
}

// (2) <bloco>::= '{' [<parte declarações de variáveis] <comando composto> '}'
int bloco(int palavra[], int linha[], int* pos)
{
    if (match(17, palavra, linha, pos))
    {
        if (d_variaveis(palavra, linha, pos) && comando_comp(palavra, linha, pos) && match(18, palavra, linha, pos))
            return (1);
        else if (comando_comp(palavra, linha, pos) && match(18, palavra, linha, pos))
            return (1);
    }
    
    return (0);
}

//  == DECLARAÇÕES ==
// (3) <parte declarações de variáveis> ::= <declaração de variável> {<declaração de variável>}
int d_variaveis(int palavra[], int linha[], int* pos)
{
    if (decl_variavel(palavra, linha, pos)  &&
        d_variaveis(palavra, linha, pos))
        return (1);
    else if (decl_variavel(palavra, linha, pos))
        return (1);
    else return (0);
}

// (4) <declaração de variável> ::= ('int'|'booleano') <lista de identificadores> ';'
int decl_variavel(int palavra[], int linha[], int* pos)
{
    if (match(4, palavra, linha, pos)  &&  //int
        lista_id(palavra, linha, pos)  &&
        match(16, palavra, linha, pos)     //;
        ) return (1);
    else
    if (match(3, palavra, linha, pos)  &&  // booleano
        lista_id(palavra, linha, pos)  &&
        match(16, palavra, linha, pos)     //;
        ) return (1);
    return (0);
}

// (5) <lista de id> ::= <id>{','<identificador>}
int lista_id(int palavra[], int linha[], int* pos)
{
    if( ident(palavra, linha, pos)     &&
        match(15, palavra, linha, pos) &&
        lista_id(palavra, linha, pos))
        return (1);
    else if (ident(palavra, linha, pos)) return (1);
    return (0);
}

// (6) <decl funcoes> ::= {<declara função>}
int decl_funcoes(int palavra[], int linha[], int* pos)
{
    if (lookahead == 5)
        if( declara_func(palavra, linha, pos)   &&
            decl_funcoes(palavra, linha, pos))
            return (1);
        else return (0);
    return(1);
}

// (7) <decl funcao> ::= 'void'<identificador> '('[<parâmetro formal>]')' <bloco>
int declara_func(int palavra[], int linha[], int* pos)
{
    if (match(5, palavra, linha, pos)  &&
        ident(palavra, linha, pos)     &&
        match(13, palavra, linha, pos) &&
        para_formal(palavra, linha, pos)&&
        match(14, palavra, linha, pos) &&
        bloco(palavra, linha, pos))
        return (1);
    if (match(5, palavra, linha, pos)  &&
        ident(palavra, linha, pos)     &&
        match(13, palavra, linha, pos) &&
        match(14, palavra, linha, pos) &&
        bloco(palavra, linha, pos))
        return(1);
    return (0);
}

// (8) <parâmetro formal> ::= (int | booleano) <indentificador>
int para_formal(int palavra[], int linha[], int* pos)
{
    if (match(4, palavra, linha, pos) && ident(palavra, linha, pos)) return (1);
    else if (match(5, palavra, linha, pos) && ident(palavra, linha, pos)) return (1);
    else return (0);
}

//  == COMANDOS ==
// (9) <comando composto> ::= <comando>';' {<comando> ;}
int comando_comp(int palavra[], int linha[], int* pos)
{
    if (comando(palavra, linha, pos) && match(16, palavra, linha, pos)) return (1);
    else if (comando_comp(palavra, linha, pos)) return (1);
    return (0);
}

// (10) <comando> ::= atribuição
//                  | chamada de procedimento
//                  | comando condicional
//                  | comando repetitivo
//                  | print ( identificador )
int comando(int palavra[], int linha[], int* pos)
{
    if (atribuicao(palavra, linha, pos)    ||
        chamada_proc(palavra, linha, pos)  ||
        comando_cond(palavra, linha, pos)  ||
        comando_repe(palavra, linha, pos)  ||
        (match(7, palavra, linha, pos) && match(13, palavra, linha, pos) && ident(palavra, linha, pos) && match(14, palavra, linha, pos)))
        return(1);
    printf("Estou na comando! -> P: %d", palavra[*pos]); return(0);
}

// (11) <atribuicao> ::= <variavel> = <expressao>
int atribuicao(int palavra[], int linha[], int* pos)
{
    if (variavel(palavra, linha, pos)  &&
        match(24, palavra, linha, pos) &&
        expressao(palavra, linha, pos))
        return (1);
    return (0);
}

// (12) <chamada de procedimento> ::= 'proc' <identificador> '{'[<parametro>]'}'
int chamada_proc(int palavra[], int linha[], int* pos)
{
  if(match(8, palavra, linha, pos) &&
     ident(palavra, linha, pos) &&
     match(13, palavra, linha, pos))
        if (parametro(palavra, linha, pos) && match(14, palavra, linha, pos))
            return (1);
        else if (ident(palavra, linha, pos) && match(14, palavra, linha, pos))
            return (1);
  return (0);
}

// (13) <parâmetro> ::= [ ( <identificador> | <número> | <booleano> ) ]
int parametro(int palavra[], int linha[], int* pos)
{
    if (lookahead == 30 || lookahead == 31 || lookahead == 1 || lookahead == 0)
    {
        if       (ident(palavra, linha, pos))    return (1);
        else if  (num(palavra, linha, pos))      return (1);
        else if  (booleano(palavra, linha, pos)) return (1);
        else return (0);
    }
    else return(0);
}

// (14) <comando_cond> ::= 'if' '('<expressão>')''{'<comando_comp>'}'['else' '{'<comando_comp>'}']
int comando_cond(int palavra[], int linha[], int* pos)
{
  if (  match(9, palavra, linha, pos) &&
        match(13, palavra, linha, pos) &&
        expressao(palavra, linha, pos) &&
        match(14, palavra, linha, pos) &&
        match(17, palavra, linha, pos) &&
        comando_comp(palavra, linha, pos))
        if (match(18, palavra, linha, pos) &&
        match(10, palavra, linha, pos) &&
        match(17, palavra, linha, pos) &&
        comando_comp(palavra, linha, pos) &&
        match(18, palavra, linha, pos))
        return (1);
        else if (match(18, palavra, linha, pos))
        return (1);
    else return (0);
}

// (15)
int comando_repe(int palavra[], int linha[], int* pos)
{
    if (match(12, palavra, linha, pos) &&
       match(17, palavra, linha, pos) &&
       comando_comp(palavra, linha, pos) &&
       match(18, palavra, linha, pos) &&
       match(11, palavra, linha, pos) &&
       match(13, palavra, linha, pos) &&
       expressao(palavra, linha, pos) &&
       match(14, palavra, linha, pos))
       return (1);
    return (0);
}

// == EXPRESSÕES ==

// 16
int expressao(int palavra[], int linha[], int* pos)
{
  if (expre_sim(palavra, linha, pos) &&
      relacao(palavra, linha, pos) &&
      expre_sim(palavra, linha, pos))
      return (1);
  else if (expre_sim(palavra, linha, pos)) return (1);
  return (0);
}

// (17)
int relacao(int palavra[], int linha[], int* pos)
{
    if (match(24, palavra, linha, pos) &&
       match(24, palavra, linha, pos))
       return (1);
    else if(match(28, palavra, linha, pos) &&
       match(26, palavra, linha, pos))
       return (1);
    else if(match(28, palavra, linha, pos) &&
       match(24, palavra, linha, pos))
       return (1);
    else if(match(26, palavra, linha, pos) &&
       match(24, palavra, linha, pos))
       return(1);
    else if(match(24, palavra, linha, pos)) return (1);
    else if(match(26, palavra, linha, pos)) return (1);
    return (0);
}

// (18)
int expre_sim(int palavra[], int linha[], int* pos)
{
    if (match(20, palavra, linha, pos) && termo(palavra, linha, pos))
        return (1);
    else if (match(21, palavra, linha, pos) && termo(palavra, linha, pos))
        return(1);
    else if (expre_sim(palavra, linha, pos))
        return (1);
    else if (termo(palavra, linha, pos))
        return (1);
    return (0);
}

// (19)
int termo(int palavra[], int linha[], int* pos)
{
    if (fator(palavra, linha, pos) &&
       match(22, palavra, linha, pos) &&
       fator(palavra, linha, pos) &&
       termo(palavra, linha, pos))
       return (1);
    else if(fator(palavra, linha, pos) &&
       match(23, palavra, linha, pos) &&
       fator(palavra, linha, pos) &&
       termo(palavra, linha, pos))
       return (1);
    else if(fator(palavra, linha, pos)) return (1);
    return (0);
}

// (20)
int fator(int palavra[], int linha[], int* pos)
{
    if (variavel(palavra, linha, pos) ||
        num(palavra, linha, pos) ||
        booleano(palavra, linha, pos) ||
        (match(13, palavra, linha, pos) &&
        expre_sim(palavra, linha, pos) &&
        match(14, palavra, linha, pos)))
        return (1);
  return (0);
}

// (21)
int variavel(int palavra[], int linha[], int* pos)
{
    if (ident(palavra, linha, pos)) return (1);
    return (0);
}

// == NÚMEROS E IDENTIFICADORES ==
// (22)
int booleano(int palavra[], int linha[], int* pos)
{
    if ((match(1, palavra, linha, pos)) || (match(0, palavra, linha, pos))) return (1);
    return(0);
}

// (23)
int num(int palavra[], int linha[], int* pos)
{
    if (match(31, palavra, linha, pos)) return (1);
    return (0);
}

// (24)
int ident(int palavra[], int linha[], int* pos)
{
    if (match(30, palavra, linha, pos)) return (1);
    return (0);
}

//  MATCH ===========================================================
int match(int t, int palavra[], int linha[], int* pos)
{
    if (lookahead == t)
    {
        printf("Lookahead: %d\nPalavra na posição %d: %d\n", lookahead, *pos, palavra[*pos]);
        lookahead = palavra[++(*pos)];
        return (1);
    }
    return (0);
}

//  TRATAMENTO DE ERRO =============================================
void trataErro(){
    printf("\n\nERRO DE SINTAXE\n\n");
  // pega linha do arquivo aberto em que deu erro e printa que erro encontrado na linha X
  // em certos casos mostrar um [expected algo] ou outra sugestoes
  // void erro(int linha)
// {
//     printf("Erro na linha %d: sintaxe inválida \n", linha);
// }

	/* IMPORTANTE:  Faca um tratamento melhor !!! */
}

void get_tokens(FILE* input, int* tokens, int* linha)
{
    int size = 1;
    char line[100];
    while(!feof(input))
    {
        fgets(line, sizeof(line), input);
        tokens = (int*) realloc (tokens, sizeof(int) * size);
        linha  = (int*) realloc (linha , sizeof(int) * size);
        sscanf(line, "%d,%d", &tokens[size-1], &linha[size-1]);
        size++;
    }
}

//  Main ============================================================
int main(int argc, char const *argv[])
{
    //  Inicialização de variáveis
    FILE* input = fopen("tokens.txt", "r");
    int* tokens = (int*) malloc (sizeof(int));
    int* linha  = (int*) malloc (sizeof(int));
    get_tokens(input, tokens, linha);
    int pos = 0;
    lookahead = tokens[pos];

    if(programa(tokens,linha,&pos))
        printf("shbow de bola");
    else
        printf("deu ruim :C");

    fclose(input);
    system("PAUSE");
    return 0;
}
