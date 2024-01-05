#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void locale() {
    setlocale(LC_ALL, "Portuguese");

    return;
}

int main() {
    locale();
    int escolha;
    do {
        int nprimeiro = 0;

        printf("\nEscolha uma questão para executar (ou 0 para sair):\n");
        printf("1. Questão 1: N primeiros inteiros positivos\n");
        printf("2. Questão 2: o quadrado de N \n");
        printf("3. Questão 3: N primeiros ímpares\n");
        printf("4. Questão 4: nota de N alunos, maior e menor \n");
        printf("5. Questão 5: soma todos os pares até o número N \n");
        printf("6. Questão 6: Fatorial do N \n");
        printf("7. Questão 7: múltiplos de A e B, apenas até o N \n");
        printf("8. Questão 8: Saber se o número N é triangular ou não \n");
        printf("9. Questão 9: saber se o número N é primo ou não\n");
        printf("10. Questão 10: Quantidade de discos vendidos em 1 mês, o maior número, quantidade total e o menor número. \n");
        printf("0. Sair\n");

        printf("\n DIGITE O NÚMERO DA OPÇÃO DESEJADA...: \n ");
        scanf("%d", &escolha);

        if (escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4 || escolha == 5 || escolha == 6 || escolha == 7 || escolha == 8 || escolha == 9) {
            printf("\n DIGITE SEU NÚMERO N...:");
            scanf("%d", &nprimeiro);
        }

        switch (escolha) {
            case 1:
                Q1(nprimeiro);
                break;
            case 2:
                Q2(nprimeiro);
                break;
            case 3:
                Q3(nprimeiro);
                break;
            case 4:
                Q4(nprimeiro);
                break;
            case 5:
                Q5(nprimeiro);
                break;
            case 6:
                Q6(nprimeiro);
                break;
            case 7:
                Q7(nprimeiro);
                break;
            case 8:
                Q8(nprimeiro);
                break;
            case 9:
                Q9(nprimeiro);
                break;
            case 10:
                Q10();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}

void Q10() {
    int vendas[30];
    int maiorVenda = 0;
    int diaMaiorVenda = 0;
    int menorvenda = 19999999;
    int diamenorvenda = 0;
    int soma = 0;

    for (int i = 0; i < 30; i++) {
        printf("Digite a quantidade de discos vendidos no dia %d: ", i + 1);
        scanf("%d", &vendas[i]);

        soma += vendas[i];

        if (vendas[i] > maiorVenda) {
            maiorVenda = vendas[i];
            diaMaiorVenda = i + 1;
        }
        if (vendas[i] < menorvenda) {
            menorvenda = vendas[i];
            diamenorvenda = i + 1;
        }
    }

    printf("\nO dia com a maior venda foi o dia %d, com %d discos vendidos.\n", diaMaiorVenda, maiorVenda);
    printf("\nO dia com a menor venda foi o dia %d, com %d discos vendidos.\n", diamenorvenda, menorvenda);
    printf("\n O TOTAL DE VENDAS FOI........: %d \n", soma);

    system("pause ");
    system("cls");

    return;
}

void Q9(int n) {
    if (n == 2 || n == 3) {
        printf("\n É um número primo.\n");
    } else if (n % 1 == 0 && n % 2 != 0 && n % 3 != 0) {
        printf("\n É um número primo.\n");
    } else {
        printf("\n Não é um número primo.\n");
    }
    system("pause ");
    system("cls");

    return;
}

void Q8(int n) {
    int i = 1;
    int produto = 1;

    for (i = 1; produto < n; i++) {
        produto = i * (i + 1) * (i + 2);
    }

    if (produto == n) {
        printf("\n  %d  é um número triangular!\n", n);
    } else {
        printf("\n  %d  NÃO é um número triangular!\n", n);
    }
    system("pause ");
    system("cls");

    return;
}

void Q7(int n) {
    int a, b, count;
    count = 0;
    printf("\n QUAL O PRIMEIRO NUMERO?...>");
    scanf("%d", &a);
    printf("\n QUAL O SEGUNDO NUMERO?...>");
    scanf("%d", &b);

    for (int i = 0; count < n; i++) {
        if (a <= 0 || b <= 0 || n <= 0) {
            printf("Por favor, digite números inteiros positivos.\n");
        }
        if (i % a == 0 || i % b == 0) {
            printf("%d, ", i);
            count++;
        }
    }
    system("pause ");
    system("cls");

    return;
}

void Q6(int n) {
    int mut = 1;
    if (n != 0) {
        for (int i = 1; i <= n; i++) {
            mut *= i;
        }
    }

    printf("\n %d \n", mut);
    system("pause ");
    system("cls");

    return;
}

int Q1(int n) {
    for (int i = 0; i < n; i++) {
        printf(" \n %d \n", i + 1);
    }
    system("pause ");
    system("cls");

    return 0;
}

int Q2(int n) {
    int q = 0;

    q = n * n;
    printf("\n %d \n", q);

    system("pause ");
    system("cls");

    return 0;
}

int Q3() {
    int numero;
    printf("\n DIGITE SEU NÚMERO...:");
    scanf("%d", &numero);

    imprimirIMPAR(numero);

    system("pause ");
    system("cls");

    return 0;
}

void imprimirIMPAR(int n) {
    for (int i = 1; n > 0; i += 2) {
        if (i % 2 != 0) {
            printf("\n %d \n", i);
            n--;
        }
    }

    system("pause ");
    system("cls");

    return;
}

void Q4(int n) {
    int maior, menor, nota = 0;
    maior = -1;
    menor = 999;
    for (int i = 0; n > i; i++) {
        printf("\n DIGITE SUA NOTA %d ....:", (i + 1));
        scanf("%d", &nota);
        if (nota > maior) {
            maior = nota;
        }
        if (nota < menor) {
            menor = nota;
        }
    }

    printf("\n  SUA MAIOR NOTA É...: %d \n", maior);
    printf("\n  SUA MENOR NOTA É...: %d \n", menor);
    system("pause ");
    system("cls");
    return 0;
}

void Q5(int n) {
    int soma = 0;
    for (int i = 0; n > 0; i += 2) {
        printf(" \n %d \n", i);
        n--;
        soma += i;
    }

    printf("\n  A SOMA É ...:%d \n", soma);
    system("pause ");
    system("cls");

    return;
}
