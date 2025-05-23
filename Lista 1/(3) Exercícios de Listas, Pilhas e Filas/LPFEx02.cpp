/*
    Exercícios sobre Listas (4 exercícios)

    Exercício 2 - Contagem de Elementos na Lista

    Modifique o código do exercício 1 e implemente uma função para contar
    quantos elementos existem na lista.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct No {
    int dado;
    No* prox;
} No;

No* inserirInicio(No* head, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->dado = valor;
    novoNo->prox = head;

    return novoNo;
}

No* inserirFinal(No* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->dado = valor;
    novoNo->prox = NULL;

    if (!lista) return novoNo;

    No* temp = lista;

    while (temp->prox) {
        temp = temp->prox;
    }

    temp->prox = novoNo;

    return lista;
}

No* remover(No* lista, int valor) {
    if (lista->dado == valor) {
        No* temp = lista;
        lista = lista->prox;

        free(temp);
        return lista;
    }

    No* temp = lista;

    while (temp->prox) {
        if (temp->prox->dado == valor) {
            No* toDelete = temp->prox;
            temp->prox = temp->prox->prox;  // Remove o nó
            free(toDelete);  // Libera o nó removido
            return lista;
        }
        temp = temp->prox;
    }

    return lista;
}

void printLista(No* lista) {
    No* temp = lista;

    cout << endl;

    while (temp) {
        cout << temp->dado << " -> ";
        temp = temp->prox;
    }

    cout << "NULL" << endl;
}

int qtdElementos(No* lista) {
    No* temp = lista;
    int contador=0;

    while (temp) {
        contador++;
        temp = temp->prox;
    }

    return contador;
}

int main() {
    int qtd;
    No* lista = NULL;

    // exemplos

    lista = inserirInicio(lista, 40);
    lista = inserirInicio(lista, 50);
    lista = inserirInicio(lista, 70);

    lista = remover(lista, 50);

    printLista(lista);

    qtd = qtdElementos(lista);

    cout << "A lista tem "<< qtd << " elementos";

    return 0;
}