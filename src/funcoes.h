#ifndef FUNCOES_H
#define FUNCOES_H

// Constantes
#define MAX_FUNC 100
#define VALOR_HORA_EXTRA 80.0
#define LIMITE_DIARIO 2.0

// Estrutura
typedef struct {
    int id;
    char nome[50];
    float horasExtras;
    float totalPagar;
    int aprovado;
} Funcionario;

// Funções
void exibirMenu();
void adicionarFuncionario(Funcionario lista[], int *qtd);
void registrarHoras(Funcionario lista[], int qtd);
void aprovarHoras(Funcionario lista[], int qtd);
void mostrarRelatorio(Funcionario lista[], int qtd);
void calcularPagamento(Funcionario *f);

#endif
