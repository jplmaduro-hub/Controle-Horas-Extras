#include <stdio.h>
#include "funcoes.h"

// Programa Principal
int main() {
    Funcionario funcionarios[MAX_FUNC];
    int quantidade = 0;
    int opcao;

    do {
        exibirMenu();

        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarFuncionario(funcionarios, &quantidade);
                break;
            case 2:
                registrarHoras(funcionarios, quantidade);
                break;
            case 3:
                aprovarHoras(funcionarios, quantidade);
                break;
            case 4:
                mostrarRelatorio(funcionarios, quantidade);
                break;
            case 0:
                printf("\nEncerrando o sistema... Até mais!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
