#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura que representa um produto da pilha
struct tp_produto{
	int codigo;              // Código do produto
	char nome[100];          // Nome do produto
	struct tp_produto *prox; // Ponteiro para o próximo produto
};

// Cria o tipo Produto
typedef struct tp_produto Produto;

// Ponteiro que representa o topo da pilha
Produto *topo = NULL;


// -----------------------------
// FUNÇÃO PARA LIMPAR A TELA
// -----------------------------
void limparTela(){
	system("cls || clear"); // funciona no Windows (cls) e Linux/Mac (clear)
}


// -----------------------------
// FUNÇÃO EMPILHAR
// -----------------------------
void Empilhar(){
	limparTela();

	// Aloca memória para um novo produto
	Produto *produto = (Produto*) malloc(sizeof(Produto));

	printf("=========== EMPILHAR PRODUTO ===========\n");

	printf("Digite o codigo: ");
	scanf("%i", &produto->codigo);

	printf("Digite o nome: ");
	fflush(stdin); // limpa o buffer do teclado
	gets(produto->nome); // lê o nome digitado

	// Novo produto aponta para o topo atual
	produto->prox = topo;

	// Atualiza o topo
	topo = produto;

	printf("\nProduto empilhado com sucesso!\n");
}


// -----------------------------
// FUNÇÃO LISTAR
// -----------------------------
void Listar(){
	limparTela();
	
	// Ponteiro auxiliar começa no topo da pilha
	Produto *aux = topo;

	printf("========== PRODUTOS NA PILHA ==========\n\n");

	while(aux != NULL){

		printf("Codigo: %i\n", aux->codigo);
		printf("Nome: %s\n", aux->nome);

		if(aux->prox == NULL){
			printf("Prox: NULL\n");
		}else{
			printf("Prox: %i\n", aux->prox->codigo);
		}

		printf("---------------------------------------\n");

		// avança para o próximo elemento
		aux = aux->prox;
	}

	printf("\n=========== FIM DA LISTA ===========\n");
}


// -----------------------------
// FUNÇÃO REMOVER
// -----------------------------
void remover(){
	limparTela();

	if(topo == NULL){
		printf("Pilha vazia!\n");
		return;
	}
	
	// Ponteiro auxiliar guarda o topo atual
	Produto *aux = topo;

	// topo passa a ser o próximo
	topo = topo->prox;

	printf("Produto removido do topo:\n");
	printf("Codigo: %i\n", aux->codigo);
	printf("Nome: %s\n", aux->nome);

	// libera memória
	free(aux);
}


// -----------------------------
// MENU
// -----------------------------
void menu(){

	printf("\n=====================================\n");
	printf("        PILHA DE PRODUTOS\n");
	printf("=====================================\n");
	printf("1 - Empilhar produto\n");
	printf("2 - Listar produtos\n");
	printf("3 - Remover produto do topo\n");
	printf("0 - Sair\n");
	printf("=====================================\n");
	printf("Escolha uma opcao: ");
}


// -----------------------------
// FUNÇÃO PRINCIPAL
// -----------------------------
int main(){

	setlocale(LC_ALL, "Portuguese");

	int opcao;

	do{
		limparTela();
		menu();
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
				Empilhar();
				break;

			case 2:
				if(topo == NULL){
					printf("\nPilha vazia!\n");
				}else{
					Listar();
				}
				break;

			case 3:
				remover();
				break;

			case 0:
				printf("\nEncerrando programa...\n");
				break;

			default:
				printf("\nOpcao invalida!\n");
		}

		printf("\nPressione ENTER para continuar...");
		fflush(stdin);
		getchar();

	}while(opcao != 0);

	return 0;
}
