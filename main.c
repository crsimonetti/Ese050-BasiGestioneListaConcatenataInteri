#include <stdio.h>
#include <stdlib.h>

void VuotaLista(elemento *primo);

struct s_elemento{
    int value;
    struct s_elemento* next;
};
typedef struct s_elemento elemento;


int main(int argc, char** argv) {
    
    elemento *primo=NULL;
    elemento *nuovoElemento;
    elemento *scorri;
    
    char risposta;
    
    while(risposta=='s') {
        nuovoElemento=(elemento*)malloc(sizeof(elemento));
        if (nuovoElemento==NULL){
            fprintf(stderr, "Errore nell'allocazione di mememoria.");
            exit(1);
        }
        printf("Inserisci un numero: ");
        scanf("%d", &(nuovoElemento->value));
        nuovoElemento->next=primo;
        primo=nuovoElemento;
        
        printf("Vuoi Inserire un altro numero? (s/n): ");
        scanf("\n%c", &risposta);
    }
    
    printf("In ordine inverso, i numeri inseriti sono:\n");
    scorri=primo;
    while(scorri!=NULL){
        printf("%d\n", scorri->value);
        scorri=scorri->next;
    }
    VuotaLista(primo);
    return (EXIT_SUCCESS);
}

void VuotaLista(elemento *primo){
    elemento *temporanea;
    while(primo!=NULL){
        temporanea=primo->next;
        free(primo);
        primo=temporanea;
    }
}
