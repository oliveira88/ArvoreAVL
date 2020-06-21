#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreavl.h"

int DEBUG = 0;

int main(int argc, char **argv){
    Tarvore *arv = CriaArvore();
    Tarvore * aux;
    FILE *arquivo;
    int opcao, elem, ret;
    if(argc == 2){
        arquivo = fopen(argv[1], "r");
        while(fscanf(arquivo, "%d", &elem)!=EOF){
            InsereArvore(&arv, elem);
        }
        ImprimeArvore(&arv);
    }
    
    //Loop infinito
    while(1){
        //if(DEBUG) printf("  ****    Modo DEBUG ativo   ****  \n");
        printf("  *****************************  \n");
        printf("  ****    Menu da Arvore   ****  \n");
        printf("  *****************************  \n");
        printf("  *****************************  \n");
        printf("  *  Digite a opcao desejada  *  \n");
        printf("  *****************************  \n");
        printf("  *  1 - Inserir elemento     *  \n");
        printf("  *  2 - Remover elemento     *  \n");
        printf("  *  3 - Buscar por elemento  *  \n");
        printf("  *  4 - Profundidade arvore  *  \n");
        printf("  *  5 - Imprimir a arvore    *  \n");
        printf("  *  6 - Sair do programa     *  \n");
        printf("  *****************************  \n");
        printf(" : ");
        scanf("%d",&opcao);
        
        switch(opcao){
        case 1:
            printf("Digite o elemento a ser inserido.\n");
            scanf("%d", &elem);
            if(InsereArvore(&arv, elem)==NaoFez) printf("Elemento não inserido. Elemento já existia na árvore\n");
            else printf("Elemento inserido.\n");
        case 5:
            ImprimeArvore(&arv);
            break;
        case 2:
            printf("Digite o elemento a ser removido.\n");
            scanf("%d", &elem);
            
            if(RemoveArvore(&arv, elem)==NaoFez) printf("Elemento nao encontrado.\n");
            else printf("Elemento removido. Elem = %d\n", elem);
            ImprimeArvore(&arv);
            break;
        case 3:
            printf("Digite o elemento a ser buscado.\n");
            scanf("%d", &elem);
            aux = BuscaArvore(&arv, elem);
            if(aux == NULL) printf("Elemento nao encontrado.\n");
            else printf("Elemento encontrado. Elem = %d\n", aux->chave);
            break;
        case 4:
            printf("A arvore tem menor profundudade = %d e maior profundidade = %d.\n", MenorProfArvore(&arv), MaiorProfArvore(&arv));
            break;
        case 6:
            return 1;
        }
    }
}
