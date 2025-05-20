#include <stdio.h>
#include <string.h>

char clientes[10][30];
int total = 0;

void adicionar() {
    if (total < 10) {
        printf("Nome do cliente: ");
        scanf("%s", clientes[total]);
        total++;
        printf("Cliente adicionado!\n");
    } else {
        printf("Limite de cliente atingido.\n");
    }
}

void listar() {
    if (total == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("%d - %s\n", i + 1, clientes[i]);
        }
    }
}

void remover() {
    int pos;
    if (total == 0) {
        printf("Nao ha clientes para remover.\n");
    } else {
        printf("Digite o numero do cliente para remover: ");
        scanf("%d", &pos);
        if (pos >= 1 && pos <= total) {
            for (int i = pos - 1; i < total - 1; i++) {
                for (int j = 0; j < 30; j++) {
                    clientes[i][j] = clientes[i + 1][j];
                }
            }
            total--;
            printf("Cliente removido!\n");
        } else {
            printf("Numero invalido.\n");
        }
    }
}

void buscar() {
    char nome[30];
    int encontrado = 0;

    if (total == 0) {
        printf("Nao ha clientes para buscar.\n");
        return;
    }

    printf("Digite o nome do cliente a buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < total; i++) {
        if (strcmp(clientes[i], nome) == 0) {
            printf("Cliente encontrado na posicao %d.\n", i + 1);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Remover cliente\n");
        printf("4 - Sair\n");
        printf("5 - Buscar cliente\n"); // Adição no menu
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionar();
        } else if (opcao == 2) {
            listar();
        } else if (opcao == 3) {
            remover();
        } else if (opcao == 4) {
            printf("Saindo...\n");
        } else if (opcao == 5) {
            buscar(); // Nova função chamada aqui
        } else {
            printf("Opcao invalida \n");
        }

    } while (opcao != 4);

    return 0;
}
