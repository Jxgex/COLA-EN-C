#include<stdio.h>
#include<stdlib.h>
 
////////////////////
typedef struct Carro{
	char	Placa[7];
	struct Carro *sig;	
}Carro;
///////////////////////////////////
/////// Prototipos de función ////
struct Carro* agregar(Carro *Cola, char valor[]);
struct Carro* siguiente(Carro **cola);
////////////////////////////////
///////////////////////////////
main(){
	char placa[7] = "ABCDEF";
	char placa2[7] = "XCVWERF";
	
	
	char placa3[7] = "1234567";
	char placa4[7] = "0987654";
	
	// Declaración de la cola//
	Carro *Cola = NULL;
	Carro *Uno =  NULL;
	// Declaración de la cola//
	Carro *ColaDos = NULL;
	Carro *DatoDos = NULL;
	
	Cola = agregar(Cola, placa);
	Cola = agregar(Cola,placa2);
	
	Uno = siguiente(&Cola);
	printf(Uno->Placa);
	printf("\n");
	
	
	ColaDos = agregar(ColaDos,Uno->Placa);	

	
	
	DatoDos = siguiente(&ColaDos);
	printf(DatoDos->Placa);
	
	/*
	Uno = siguiente(&Cola);
	printf(Uno->Placa);
	printf("\n");
	
	Uno = siguiente(&Cola);
	printf(Uno->Placa);
	printf("\n");*/
	
}
struct Carro* agregar(Carro *Cola, char valor[]){
	Carro *temporal = calloc(sizeof(Carro),1);
	Carro *Inicio;
	strcpy(temporal->Placa,valor);
	if(Cola!=NULL){
		Inicio = Cola;
		while(Inicio->sig!=NULL){
			Inicio = Inicio->sig;
		}
		Inicio->sig = temporal;
		return Cola;
	}
	else{
		return temporal;
	}
}
struct Carro* siguiente(Carro **cola){
	Carro *auxiliar = cola[0];
	Carro *temporal;
	if(auxiliar == NULL){
		printf("Vacio");
		return NULL;
	}
	else{
		temporal = auxiliar;
		cola[0] = auxiliar->sig;
		auxiliar->sig = NULL;
		return temporal;
	}
}

