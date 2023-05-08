Quem puder checa direito se o que eu fiz tá batendo depois por favor, eu fiz com muito sono + dor de cabeça forte.
Não tentei fazer 18)

* !! Os símbolos terminais correspondentes aos tokens estão `destacados`.
* Não tirei os "<"">" pra legibilidade disso ficar melhor, mas se alguém quiser passar pra outro jeito tá ok
* Quem for mexer no código (e se não tirar as setinhas), coloca um "\\" antes do "<" ou então o markdown vai bugar

# Sintaxe

1) \<programa> → \<declaração de funções> `semic` \<identificador> \<bloco> | `semic` \<identificador> \<bloco>
2) \<bloco> → `{` \<parte declarações de variáveis> \<comando composto> `}` | `{` \<comando composto> `}`

# Declarações
  
3) \<parte declarações de variáveis> → \<declaração de variáveis> \<declaração de variáveis> \<parte declaração de variáveis> | \<declaração de variáveis>
4) \<declaração de variáveis> → `int` \<lista de identificadores> `;` | `bool` \<lista de identificadores> `;`
5) \<lista de identificadores> → \<identificador> `,` \<lista de identificadores> | \<identificador>
6) \<declarações de funções> → \<declara função> \<declarações de funções> | ε
7) \<declara função> → `void` \<identificador> `(` \<parâmetro formal> `)` \<bloco> | `void` \<identificador> `(` `)` \<bloco>
8) \<parâmetro formal> → `int` \<identificador> | `bool` \<identificador>
  
# Comandos
  
9) \<comando composto> → \<comando> `;` \<comando> `;` \<comando composto> | \<comando> `;`
10) \<comando> → \<atribuição> | \<chamada de procedimento> | \<comando condicional> | \<comando repetitivo> | `print` `(` \<identificador> `)`
11) \<atribuição> → \<variável> `=` \<expressão>
12) \<chamada de procedimento> → `proc` \<identificador> `(` \<parâmetro> `)` | `proc` \<identificador> `(` `)` 
13) \<parâmetro> → \<identificador> | \<número> | \<bool> | ε
14) \<comando condicional> → `if` `(` \<expressão> `)` `{` \<comando composto> `}` `else` `{` \<comando composto> `}` | `if` `(` \<expressão> `)` `{` \<comando composto> `}`
15) \<comando repetitivo> → `do` `{` \<comando composto> `}` `while` `(` \<expressão> `)`

# Expressões
  
16) \<expressão> → \<expressão simples> \<relação> \<expressão simples> | \<expressão simples>
17) \<relação> → `==` | `<>` | `<` | `<=` | `>=` | `>`
18) \<expressão simples> →
19) \<termo> → \<fator> `*` \<fator> \<termo> | \<fator> `/` \<fator> \<termo> | \<fator>
20) \<fator> → \<variavel> | \<número> | \<bool> | `(` \<expressão simples> `)`
21) \<variável> → \<identificador>

# Números e Identificadores
  
22) \<bool> → `true` | `false`
23) \<número> → `num` ////(token obtido pelo analisador léxico)
24) \<identificador> → `id` ////(token obtido pelo analisador léxico)
