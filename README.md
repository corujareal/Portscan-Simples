# Como o port scanner funciona

O programa implementa um port scanner TCP básico que verifica quais portas estão abertas em um determinado host.
Funcionamento passo a passo:

    Entrada do usuário – O programa recebe um endereço IP como argumento na linha de comando.

    Loop de portas – Ele percorre as portas de 1 a 1024 (portas mais comuns, para execução rápida).

    Criação do socket – Para cada porta, cria um socket TCP (SOCK_STREAM).

    Tentativa de conexão – Tenta se conectar ao IP informado na porta atual usando a função connect().

    Avaliação do resultado – Se connect() retorna sucesso (código 0), a porta está aceitando conexões – ou seja, está aberta. O programa imprime essa informação.

    Limpeza – O socket é fechado antes de partir para a próxima porta.

# Principais elementos técnicos (sem complexidade excessiva):

    socket(AF_INET, SOCK_STREAM, 0) – cria um socket IPv4 para comunicação TCP.

    struct sockaddr_in – estrutura que guarda o endereço e a porta do alvo.

    htons(porta) – converte o número da porta para o formato de rede.

    inet_addr(destino) – converte o IP em texto para o formato binário usado pelo socket.

    connect() – tenta estabelecer a conexão TCP; o tempo de resposta indica se a porta está acessível.

# Limitação conhecida

O scanner é sequencial e não otimizado – testa uma porta por vez. Por isso é mais lento em varreduras com muitas portas. Ele também só funciona com endereços IP (não com nomes de domínio diretos, a menos que resolvidos previamente).
# Instalação(linux)
     git clone https://github.com/corujareal/Portscan-Simples
     cd Portscan-Simples
     gcc portscan.c -o portscan
     ./portscan
# Avisos
Este repositório tem foco em fins curriculares.
