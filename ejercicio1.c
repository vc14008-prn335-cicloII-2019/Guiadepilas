

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};

//variable globla que apunta al primer nodo de la lista

struct nodo *raiz=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    }
else{
    nuevo->sig=raiz;
    raiz=nuevo;
}
}
void imprimir(){
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    while(reco!=NULL){
        printf("%i",reco->info);
        reco=reco->sig;
       
    }
    printf("\n");
}
int extraer(){
    if(raiz !=NULL){
        int informacion = raiz-> info;
        struct nodo *bor=raiz;
        raiz=raiz->sig;
        free(bor);
        return informacion;
    }
    else{
        return -1;
    }
}int cantidad(){
	struct nodo *reco=raiz;
	int cant=0;
	while(reco != NULL){
		cant++;
		reco=reco->sig;
			
	}
	return cant;
	
}

void liberar(){
    struct nodo *reco=raiz;
    struct nodo *bor;
    while(reco !=NULL){
        bor=reco;
        reco=reco->sig;
        free(bor);
    }
}
int vacia(){
	if(raiz==NULL)
		return 1;
		else
		return 0;
		
	
}


int main() {
    insertar(10);
    insertar(40);
     insertar(3);
      printf("Cantidad:%i\n",  cantidad());
     printf("Extraemos de la pila:%i\n",extraer());
     imprimir();
 
     
     liberar();
     if(vacia()==1){
         printf("la lista esta vacia\n");
     }else{
         printf("la lista no esta vacia\n");
     }
    
     
    
    

    return 0;
}

