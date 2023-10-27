#include <stdio.h>
#include <stdlib.h>

struct pilhas
{
    int dado;
    struct pilhas *prox;
};

typedef struct pilhas Pilha;
typedef Pilha *PilhaPtr;

void menu();
void push(PilhaPtr *, int);
int pop(PilhaPtr *);

int main()
{
    PilhaPtr topo = NULL;
    int op;
    char operacao[100];

    while (1)
    {
        menu();
        scanf("%d", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            printf("Digite a operacao: ");
            fgets(operacao, 100, stdin);
            break;
        case 2:
            printf("\nSaindo...\n");
            return 0;
        default:
            printf("Opcao invalida.\n\n");
            system("pause");
            break;
        }

        for (int i = 0; i < sizeof(operacao); i++)
        {
            if (operacao[i] == '\0')
            {
                break;
            }
            if (operacao[i] == '(' || operacao[i] == '[' || operacao[i] == '{')
            {
                push(&topo, operacao[i]);
            }
            else if (operacao[i] == ')' || operacao[i] == ']' || operacao[i] == '}')
            {
                if (topo == NULL)
                {
                    break;
                }
                else
                {
                    if (operacao[i] == ')' && topo->dado == '(')
                    {
                        pop(&topo);
                    }
                    else if (operacao[i] == ']' && topo->dado == '[')
                    {
                        pop(&topo);
                    }
                    else if (operacao[i] == '}' && topo->dado == '{')
                    {
                        pop(&topo);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        if (op == 1)
        {
            if (topo == NULL)
            {
                printf("\nOperação correta!\n\n");
                system("pause");
            }
            else
            {
                printf("\nOperação incorreta!\n\n");
                system("pause");
            }
        }
    }
    return 0;
}

void menu()
{
    system("cls");
    printf("Escolha a opcao:\n");
    printf("1 - Digitar operacao.\n");
    printf("2 - Sair.\n");
    printf("Escolha uma opcao: ");
}

void push(PilhaPtr *topo, int info)
{
    PilhaPtr novo = (PilhaPtr)malloc(sizeof(Pilha));

    if (novo != NULL)
    {
        novo->dado = info;
        novo->prox = *topo;
        *topo = novo;
    }
    else
    {
        printf("%d Nao Inserido. Sem memoria disponivel.\n", info);
    }
}

int pop(PilhaPtr *topo)
{
    PilhaPtr aux = *topo;
    int valor = (*topo)->dado;
    *topo = (*topo)->prox;
    free(aux);
    return valor;
}
