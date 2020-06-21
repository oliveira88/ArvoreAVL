#include <arvore.h>
#include <stdio.h>

void rotacionaEsq(Arvore **arv) {  //RR
    Arvore *aux1, *aux2;
    aux1 = (*arv);
    aux2 = aux1->right;
    (*arv) = aux2;
    aux1->right = aux2->left;
    aux2->left = aux1;
}
void rotacionaDir(Arvore **arv) {  //LL
    Arvore *q, *temp;

    q = (*arv)->left;
    temp = q->right;
    q->right = temp;
    (*arv)->left = temp;
    (*arv) = q;
}
void rotacionaEsqDir(Arvore **arv) {  //RL
}
void rotacionaDirEsq(Arvore **arv) {  //LR
}
int inserirNaArvore(Arvore **arv, int valor) {
    Arvore *nova, *left, *right;
    if ((*arv) == NULL) {
        nova = (Arvore *)malloc(sizeof(Arvore));
        nova->valor = valor;
        nova->left = NULL;
        nova->right = NULL;
        nova->bal = 0;
        (*arv) = nova;
        return Alterou;
    }
    if (valor < (*arv)->valor) {
        int retorno = inserirNaArvore((&(*arv)->left), valor);
        if (retorno == NaoAlterou || retorno == NaoExecutou) return retorno;
        if (retorno == Alterou) {
            (*arv)->bal += 1;
            if ((*arv)->bal == 2) {
                left = (*arv)->left;

                if (left->bal == 1) {  //LL = [Uma rotaçao para a direita]
                    rotacionaDir(&(*arv));
                    return NaoAlterou;
                }
                if (left->bal == -1) {  //LR = [RR + LL] = [Uma rotaçao p/ a esquerda + Uma rotação p/ Direita]
                    rotacionaEsqDir(&(*arv));
                    return NaoAlterou;
                }
            }
            if ((*arv)->bal == 1) return Alterou;
            if ((*arv)->bal == 0) return NaoAlterou;
        }
    }
    if (valor > (*arv)->valor) {
        int retorno = inserirNaArvore((&(*arv)->right), valor);
        if (retorno == NaoAlterou || NaoExecutou) return retorno;
        if (retorno == Alterou) {
            (*arv)->bal -= 1;
            if ((*arv)->bal == -2) {
                right = (*arv)->right;

                if (right->bal == -1) {  // RR = [Uma rotação para esquerda]
                    rotacionaEsq(&(*arv));
                    return NaoAlterou;
                }
                if (right->bal == 1) {  // RL = [LL + RR] = [Uma rotação p/ direita + Uma rotação p/ esquerda]
                    rotacionaDirEsq(&(*arv));
                    return NaoAlterou;
                }
            }
            if ((*arv)->bal == -1) return Alterou;
            if ((*arv)->bal == 0) return NaoAlterou;
        }
    }
    if (valor == (*arv)->valor) return NaoExecutou;
}
void removerDaArvore(Arvore **arv, int valor) {}
Arvore *buscarNaArvore(Arvore **arv, int valor) {
    if ((*arv) == NULL) return NULL;
    if ((valor) < (*arv)->valor) return buscarNaArvore(&(*arv)->left, valor);
    if ((valor) > (*arv)->valor) return buscarNaArvore(&(*arv)->right, valor);
    if ((valor) == (*arv)->valor) return (*arv);
}