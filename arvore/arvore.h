typedef struct Arvore {
    int bal;
    int valor;
    struct Arvore *left;
    struct Arvore *right;
} Arvore;
#define Alterou 1
#define NaoAlterou 0
#define NaoExecutou -1
void rotacionaEsq(Arvore **arv);     //RR
void rotacionaDir(Arvore **arv);     //LL
void rotacionaEsqDir(Arvore **arv);  //RL
void rotacionaDirEsq(Arvore **arv);  //LR
int inserirNaArvore(Arvore **arv, int valor);
void removerDaArvore(Arvore **arv, int valor);
Arvore *buscarNaArvore(Arvore **arv, int valor);