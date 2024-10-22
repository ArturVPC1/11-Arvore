#include <iostream>
using namespace std;

// definicao de tipo
struct NO
{
	int valor;
	NO *esq;
	NO *dir;
};

NO *raiz = NULL;

// headers
// estrutura principal
void menu()
{
	int op = 0;
	while (op != 6)
	{
		system("cls"); // somente no windows
		cout << "Menu Arvore";
		cout << endl
			 << endl;
		cout << "1 - Inicializar Arvore \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Inserir elemento \n";
		cout << "4 - Exibir elementos \n";
		cout << "5 - Buscar elemento \n";
		cout << "6 - Sair \n";
		cout << "7 - Exibir em ordem\n"; // nova opção

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1:
			inicializar();
			break;
		case 2:
			exibirQuantidade();
			break;
		case 3:
			inserir();
			break;
		case 4:
			exibir();
			break;
		case 5:
			buscar();
			break;
		case 7: // case para exibir em ordem
			cout << "Elementos da árvore em ordem: ";
			exibirEmOrdem(raiz);
			cout << endl;
			break;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// provis�rio porque n�o libera a memoria usada pela arvore
	NO *raiz = NULL;

	cout << "Arvore inicializada \n";
}

void inserir()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (raiz == NULL)
	{
		raiz = criaNO(valor);
	}
	else
	{
		insereArvore(raiz, valor);
	}
}

void exibirQuantidade()
{
	cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;
}

void exibir()
{
	exibirElementosArvore(raiz);
}

void buscar()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	buscarElementoArvore(raiz, valor);
}

NO *criaNO(int valor)
{
	NO *novo = (NO *)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

NO *insereArvore(NO *no, int valor)
{
	if (no->valor > valor && no->esq == NULL)
	{
		no->esq = criaNO(valor);
		return no->esq;
	}
	else if (no->valor < valor && no->dir == NULL)
	{
		no->dir = criaNO(valor);
		return no->dir;
	}
	else if (no->valor > valor)
	{
		return insereArvore(no->esq, valor);
	}
	else if (no->valor < valor)
	{
		return insereArvore(no->dir, valor);
	}
	else
	{
		return NULL;
	}
}

int elementosArvore(NO *no)
{
	if (no == NULL)
	{
		return 0;
	}

	return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO *no)
{
	if (no == NULL)
	{
		return;
	}

	cout << no->valor << endl;
	exibirElementosArvore(no->esq);
	exibirElementosArvore(no->dir);
}

void buscarElementoArvore(NO *no, int valor)
{
	if (no == NULL)
	{
		cout << "Elemento " << valor << " não encontrado na árvore." << endl;
		return;
	}

	if (no->valor == valor)
	{
		cout << "Elemento " << valor << " encontrado na árvore." << endl;
		return;
	}

	if (valor < no->valor)
	{
		buscarElementoArvore(no->esq, valor);
	}
	else
	{
		buscarElementoArvore(no->dir, valor);
	}
}

void exibirEmOrdem(NO *no)
{
	if (no == NULL)
	{
		return;
	}

	// Visita o filho esquerdo
	exibirEmOrdem(no->esq);

	// Exibe o valor do nó atual
	cout << no->valor << " ";

	// Visita o filho direito
	exibirEmOrdem(no->dir);
}
