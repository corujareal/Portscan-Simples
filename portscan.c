#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <IP>\n", argv[0]);
        return 1;
    }

    int sock;
    int conecta;
    int porta;
    int inicio = 1;
    int final = 1024;
    char *destino = argv[1];
    struct sockaddr_in alvo;

    // Converte o endereço IP uma única vez (fora do loop)
    alvo.sin_family = AF_INET;
    alvo.sin_addr.s_addr = inet_addr(destino);
    if (alvo.sin_addr.s_addr == INADDR_NONE) {
        printf("Erro: IP inválido: %s\n", destino);
        return 1;
    }

    for (porta = inicio; porta <= final; porta++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            continue;
        }

        alvo.sin_port = htons(porta);

        conecta = connect(sock, (struct sockaddr *)&alvo, sizeof(alvo));
        if (conecta == 0) {
            printf("Porta aberta: %d\n", porta);
        }

        close(sock);   // corrigido: era pclose()
    }

    return 0;
}
