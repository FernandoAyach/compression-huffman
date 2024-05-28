# :bulb: Algoritmo de Huffman

O algoritmo de huffman é um algoritmo de compactação de arquivos sem perda de informações. No computador, 
os caracteres (ou qualquer outra informação) tem quantidades padrão de bytes. No entanto, dependendo da informação, não precisamos
usar toda a quantidade de bits que o computador reserva para determinado dado. Dessa forma, no algoritmo de huffman, geramos códigos para cada dado, 
seguindo a regra de que os caracteres que mais se repetem possuem códigos menores.

### :mailbox: Para compactar os dados:

1. Contamos a frequência de cada letra.

2. Construimos uma Min Heap (Lista de prioridades) e inserimos as letras com suas frequências.

3. Construimos uma árvore de Huffman a partir da Min Heap.

4. Percorremos a Huffman em percurso Pre-order e colocamos os códigos numa Hashtable.

5. Inserimos num arquivo binário o texto mapeado para os códigos de huffman e um cabeçalho com informações necessárias para a descompactação.

### :mailbox_with_mail: Para descompactar os dados:

1. Lemos o binário com o cabeçalho e o texto compactado

2. Recriamos a arvore de huffman

3. Mapeamos a partir dela os códigos compactados para o dado real

4. Inserimos no arquivo de destino (descompactado)

# Como usar?

O uso é bem simples, por conta do Makefile. Se já tiver o compilador para C++ (g++), faça o clone na sua máquina e digite os seguintes comandos:

## :inbox_tray: Compactar
```
make run ARGS="c nome_do_arquivo_a_ser_compactado.txt nome_do_compactado.huff"
```

## :outbox_tray: Descompactar
```
make run ARGS="d nome_do_compactado.huff nome_do_arquivo_descompactado.txt"
```

## :pushpin: Observações: 
- Você pode compactar/descompactar qualquer arquivo, de qualquer extensão, mas é importante que o compactado seja .huff.
- Se estiver usando Vscode, você pode visualizar o binário gerado com a extensão HexEditor.
