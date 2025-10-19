Faculdade de Computação (FACOM)- UFMS
 Algoritmos e Programação 2
 Prof. Dr. Anderson Bessa da Costa
 Trabalho Prático 2025-2: Show do Milhão

- 1 Descrição do Trabalho
 Show do milhão é um jogo de perguntas e respostas que ficou bastante popular na década de 90,
 quando as pessoas ainda assistiam um certo canal de televisão chamado CBT (Conglomerado
 Brasileiro de Televisão). Nesse jogo, um participante convidado deve responder perguntas sobre
 os mais diversos assuntos. O nível de dificuldade das perguntas aumenta quanto mais longe o
 participante chega, porém basta apenas uma resposta errada para ser eliminado sem levar nada.
 O objetivo é avançar o jogo com respostas corretas. Ao responder corretamente a pergunta
 final o participante sairá vencedor com o prêmio de 1 milhão de reais (para nós fictício, infeliz
mente).
- 2 Manual do Jogo
 O participante inicia o jogo com o valor fictício de R$ 0,00 (ou seja, nada). As perguntas são
 divididas em 3 blocos compostos por 5 perguntas cada, mais a pergunta final. No primeiro bloco
 são feitas perguntas do nível fácil, no segundo bloco são feitas perguntas do nível médio, e no
 terceiro bloco são feitas perguntas do nível difícil. A pergunta final é do nível super difícil.
 ATabela 1 apresenta o valor ganho por cada pergunta respondida corretamente, segmentada
 por bloco. Também é apresentado o valor que o participante inicia cada bloco. Lembre-se que
 uma única resposta incorreta automaticamente elimina o participante, encerrando o jogo com
 nenhuma premiação.
 Bloco Valor Inicial
 Valor ganho por pergunta
 1
 2
 3
 R$ 0,00
 R$ 10.000,00
 R$ 1.000,00
 R$ 10.000,00
 R$ 100.000,00 R$ 100.000,00
 Tabela 1: Valor inicial e valor ganho por pergunta, segmentado por bloco.
 Desta forma, o participante que iniciar o jogo e acertar as três primeiras perguntas terá uma
 premiação total acumulada de R$ 3.000,00. Outro exemplo, se o participante iniciar o jogo e
 acertar as cinco primeiras perguntas, ele irá avançar para o bloco 2 (perguntas de dificuldade
 média) e terá como premiação total acumulada de R$ 10.000,00.
 Para dar alguma emoção a mais no jogo e também facilitar a vida do participante, existem
 alguns recursos que permitem ajudá-lo. Atenção pois os recursos são limitados:
 Pular pergunta O participante tem o poder de pular uma pergunta. O recurso pode ser
 utilizado 3 vezes;
 Pedir ajuda a plateia O participante pede ajuda à platéia composta por 30 pessoas. Essas
 30 pessoas devem levantar uma placa com a opção que acredita ser a correta. O recurso
 pode ser utilizado 3 vezes;
 1
Pedir ajuda aos universitários O participante pede ajuda a um grupo de 3 universitários.
 Cada universitário opina com uma opção. O recurso pode ser utilizado 3 vezes;
 Pedir ajuda as cartas O participante escolhe uma dentre 4 cartas, que estão escondidas sob
 a mesa (o participante não vê o conteúdo da carta). Ao escolher uma carta, a carta é
 revelada: 0- nenhuma opção é excluída, 1- uma opção incorreta é automaticamente
 excluída, 2- duas opções incorretas são automaticamente excluídas e 3- as três opções
 incorretas são automaticamente excluídas. Logicamente o desejado pelo participante é
 sempre que se saia o número 3, porém é necessário sorte para que isso aconteça. Este
 recurso também está limitado a 3 usos.
- 3 Funcionamento do Jogo
 Um exemplo de pergunta é apresentado abaixo:
 ==-----------
 == Pergunta 1
 == Voce possui um total acumulado de R$ 0.00 ==
 O churrasco e considerado uma comida tipica de qual estado?
 a) Ceara
 b) Rio Grande do Sul
 c) Para
 d) Maranhao-- Ajuda-
[1] Pular pergunta (3x)
 [2] Pedir ajuda a plateia (3x)
 [3] Pedir ajuda aos universitarios (3x)
 [4] Pedir ajuda as cartas (3x)
 [5] Parar
 ~~~~~~~~~~~~~~~
 Entre com a sua opcao:
 Você como um entendedor do assunto deveria responder com a alternativa b). Qualquer
 outra alternativa (a), c) ou d)) estaria incorreta e portanto iria eliminá-lo automaticamente.
 Caso não tivesse convicção para responder, é possível selecionar um dos recursos de ajuda, porém
 é dever do desenvolvedor manter o controle sobre a quantidade disponíveis de cada recurso.
 Para a sua implementação será fornecido um único arquivo chamado perguntas.dat. Esse
 é um arquivo binário que contém as perguntas, as alternativas, a resposta correta e o nível da
 pergunta. Esse arquivo contém um total de 70 perguntas, sendo 20 perguntas do nível fácil, 20
 perguntas do nível médio, 20 perguntas do nível difícil e 10 perguntas do nível super difícil. A
 Tabela 2 apresenta o formato de cada pergunta gravada no arquivo binário.
 1 byte 200 bytes 30 bytes 30 bytes 30 bytes 30 bytes
 nível
 pergunta
 alt. 1
 alt. 2
 1 byte
 alt. 3
 alt. 4
 resposta correta
 Tabela 2: Formato de cada pergunta no arquivo binário.
 Uma descrição detalhada de cada campo é dada a seguir:
 2
nível (1 byte) Um número inteiro representando o nível da pergunta. Pode assumir os valores
 entre 1 e 4 (inclusive), onde 1 é o nível mais fácil e 4 o mais difícil;
 pergunta (200 bytes) Sequência de caracteres contendo a pergunta. A sequência é delimitada
 no final pelo caractere ‘\0’;
 alt. 1 (30 bytes) Sequência de caracteres contendo a alternativa 1. A sequência é delimitada
 no final pelo pelo caractere ‘\0’;
 alt. 2 (30 bytes) Sequência de caracteres contendo a alternativa 2. A sequência é delimitada
 no final pelo pelo caractere ‘\0’;
 alt. 3 (30 bytes) Sequência de caracteres contendo a alternativa 3. A sequência é delimitada
 no final pelo pelo caractere ‘\0’;
 alt. 4 (30 bytes) Sequência de caracteres contendo a alternativa 4. A sequência é delimitada
 no final pelo pelo caractere ‘\0’;
 alt. correta (1 byte) Contém a alternativa correta para a pergunta. Pode armazenar um dos
 seguintes caracteres: ‘a’, ‘b’, ‘c’, ‘d’.
 Para auxiliá-lo, considere o seguinte registro para representar uma pergunta:
 struct pergunta {
 char nivel;
 char descricao[200];
 char alt[4][30];
 char alt_correta;
 };
 Assim, ao se executar o comando fread carregando sizeof(struct pergunta) bytes, uma
 pergunta pode ser lida do arquivo binário fornecido.
 As perguntas apresentadas ao participante devem ser selecionadas de forma aleatória, porém
 dentro do nível correto. Da maneira como está disposta no arquivo, as primeiras 20 perguntas
 são do nível fácil, as próximas 20 perguntas são do nível médio, as próximas 20 perguntas são
 do nível difícil e as 10 últimas perguntas do nível super difícil.
 Estando o participante no primeiro bloco, deve-se apresentar perguntas do nível fácil. Assim
 sendo, deve ser escolhido de forma aleatória uma pergunta entre as 20 deste nível.
 Os recursos de ajuda ao participantes devem seguir a seguinte lógica:
 Pular pergunta Selecionar outra pergunta de forma aleatória, porém dentro do mesmo nível;
 Pedir ajuda a plateia Gerar 30 alternativas aleatoriamente, com probabilidade de 40% para
 selecionar a alternativa correta, e 20% para cada uma das alternativas incorretas;
 Pedir ajuda aos universitários Gerar 3 alternativas aleatoriamente, com probabilidade de
 70% para selecionar a alternativa correta, e 10% para cada uma das alternativas incorretas;
 Pedir ajuda as cartas Aleatoriamente selecionar uma das possíveis cartas: 0, 1, 2 ou 3. Cada
 uma deve ter probabilidade igual de ser selecionada.
 Você como desenvolvedor deve ser capaz de abrir este arquivo e manipulá-lo da melhor forma
 que lhe convêm. Espera-se que seja capaz de carregar as informações corretamente do arquivo.
 Toda a lógica deverá ser implementada do zero, e será avaliado a sua implementação como um
 todo, estando atento a todos os detalhes: nomenclatura de variáveis, organização de código,
 nomenclatura de funções, espaçamento, lógica, desempenho e tudo mais relacionado.

Texto Produzido Por : Anderson Bessa Costa (FACOM/UFMS)
Implementação em Código Produzida Por : Érick Pereira Calauri (FACOM/UFMS)