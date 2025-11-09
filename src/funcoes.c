#include <stdio.h>
#include <string.h>
#include "funcoes.h"

// Menu
void exibirMenu() {
    printf("\n========== SISTEMA DE HORAS EXTRAS ==========\n");
    printf("1 - Cadastrar funcionário\n");
    printf("2 - Registrar horas extras\n");
    printf("3 - Aprovar horas (gestor)\n");
    printf("4 - Exibir relatório\n");
    printf("0 - Sair\n");
    printf("=============================================\n");
}

// Cadastro
void adicionarFuncionario(Funcionario lista[], int *qtd) {
    if (*qtd >= MAX_FUNC) {
        printf("Limite máximo de funcionários atingido.\n");
        return;
    }

    printf("Nome do funcionário: ");
    fgets(lista[*qtd].nome, 50, stdin);
    lista[*qtd].nome[strcspn(lista[*qtd].nome, "\n")] = 0;

    lista[*qtd].id = *qtd + 1;
    lista[*qtd].horasExtras = 0;
    lista[*qtd].totalPagar = 0;
    lista[*qtd].aprovado = 0;

    printf("Funcionário '%s' cadastrado com ID %d.\n", lista[*qtd].nome, lista[*qtd].id);
    (*qtd)++;
}

// Registro
void registrarHoras(Funcionario lista[], int qtd) {
    int id;
    float horas;

    printf("Digite o ID do funcionário: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) {
        printf("ID inválido!\n");
        return;
    }

    printf("Horas extras realizadas: ");
    scanf("%f", &horas);

    if (horas > LIMITE_DIARIO) {
        printf("⚠️  Limite diário de %.1f horas excedido!\n", LIMITE_DIARIO);
        return;
    }

    lista[id - 1].horasExtras += horas;
    calcularPagamento(&lista[id - 1]);
    printf("Horas extras registradas com sucesso!\n");
}

// Cálculo
void calcularPagamento(Funcionario *f) {
    f->totalPagar = f->horasExtras * VALOR_HORA_EXTRA;
}

// Aprovação
void aprovarHoras(Funcionario lista[], int qtd) {
    int id;
    printf("Informe o ID do funcionário para aprovação: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) {
        printf("ID inválido!\n");
        return;
    }

    lista[id - 1].aprovado = 1;
    printf("Horas extras de '%s' foram aprovadas!\n", lista[id - 1].nome);
}

// Relatório
void mostrarRelatorio(Funcionario lista[], int qtd) {
    printf("\n--------- RELATÓRIO DE HORAS EXTRAS ---------\n");
    printf("ID | Nome                | Horas | Valor (R$) | Status\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < qtd; i++) {
        printf("%-2d | %-20s | %5.1f | %10.2f | %s\n",
               lista[i].id, lista[i].nome,
               lista[i].horasExtras, lista[i].totalPagar,
               lista[i].aprovado ? "Aprovado" : "Pendente");
    }

    printf("-------------------------------------------------------\n");
}
