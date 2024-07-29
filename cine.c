#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cine.h"

struct CineE{

    char nombre[20];
    char direccion[20];

    ListaPtr salas;

};

CinePtr crearCine(char nombre[20], char direccion[20]){

    CinePtr nuevoCine = (CinePtr) malloc(sizeof(struct CineE));

    strcpy(nuevoCine->nombre, nombre);
    strcpy(nuevoCine->direccion, direccion);

    nuevoCine->salas = crearLista();

    return nuevoCine;

};

void mostrarCine(CinePtr cine){

    printf(" ----------------------- CINE -----------------------\n" );
    printf(" NOMBRE: %s -- DIRECCION: %s\n", cine->nombre, cine->direccion);

    NodoPtr actual = getPrimero(cine->salas);

    while(actual != NULL){

        SalaPtr sala = (SalaPtr)getDato(actual);
        mostrarSala(sala);
        actual = getSiguiente(actual);

    }

};

void insertarSala(CinePtr cine, SalaPtr sala){

    insertarUltimo(cine->salas, sala);

};

char* getNombreCine(CinePtr cine){

    return cine->nombre;

};

char* getDireccionCine(CinePtr cine){

    return cine->direccion;

};

ListaPtr getSalasCine(CinePtr cine){

    return cine->salas;

};

void setNombreCine(CinePtr cine, char nuevoNombre[20]){

    strcpy(cine->nombre, nuevoNombre);

};

void setDireccionCine(CinePtr cine, char nuevaDireccion[20]){

    strcpy(cine->direccion, nuevaDireccion);

};

void setSalasCine(CinePtr cine, ListaPtr nuevasSalas){

    cine->salas = nuevasSalas;

};

void liberarCine(CinePtr cine){

    NodoPtr actual = getPrimero(cine->salas);

    while(actual != NULL){

        SalaPtr sala = (SalaPtr)getDato(actual);
        liberarSala(sala);
        actual = getSiguiente(actual);

    }

    liberarLista(cine->salas);

    free(cine);

};
