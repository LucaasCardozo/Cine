#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sala.h"

struct SalaE{

    int numeroDeSala;
    char tipo[20];
    int filas;
    int columnas;
    int **asientos;

    ListaPtr reservas;

};

SalaPtr crearSala(int numero, char tipo[20], int fil, int column){

    SalaPtr nuevaSala = (SalaPtr) malloc(sizeof(struct SalaE));

    nuevaSala->numeroDeSala = numero;
    strcpy(nuevaSala->tipo, tipo);
    nuevaSala->filas = fil;
    nuevaSala->columnas = column;
    nuevaSala->asientos = (int**)malloc(fil * sizeof(int*));
    for(int i=0; i<fil; i++){

        nuevaSala->asientos[i] = (int*)malloc(column * sizeof(int));

        for(int j=0; j<column; j++){

            nuevaSala->asientos[i][j] = 0;

        }

    }

    nuevaSala->reservas = crearLista();

    return nuevaSala;

};

void mostrarSala(SalaPtr sala){

    printf("\n --------------- SALA %d ---------------\n", sala->numeroDeSala);
    printf(" TIPO: %s -- FILAS: %d -- COLUMNAS: %d\n\n", sala->tipo, sala->filas, sala->columnas);
    for(int i=0; i<sala->filas; i++){

        for(int j=0; j<sala->columnas; j++){

            printf(" %d", sala->asientos[i][j]);

        }

        printf("\n");

    }

};

void insertarPersona(SalaPtr sala, PersonaPtr persona){

    if((getFila(persona) < sala->filas) && (getColumna(persona) < sala->columnas) && (sala->asientos[getFila(persona)][getColumna(persona)] == 0)){
        insertarUltimo(sala->reservas, persona);

        sala->asientos[getFila(persona)][getColumna(persona)] = getDni(persona);

    }else{

        printf("\nERROR!! EL ASIENTO UBICADO EN LA FILA '%d' Y COLUMNA '%d' ESTA OCUPADO O ESTA FUERA DE RANGO!!\n", getFila(persona), getColumna(persona));

    }


};

void liberarSala(SalaPtr sala){

    NodoPtr actual = getPrimero(sala->reservas);

    while(actual != NULL){

        PersonaPtr persona = (PersonaPtr)getDato(actual);
        liberarPersona(persona);
        actual = getSiguiente(actual);

    }

    liberarLista(sala->reservas);

    free(sala);

};

