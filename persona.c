#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

struct PersonaE{

    int dni;
    int numSala;
    int fila;
    int columna;

};

PersonaPtr crearPersona(int dni, int num, int fil, int column){

    PersonaPtr nuevaPersona = (PersonaPtr)malloc(sizeof(struct PersonaE));

    nuevaPersona->dni = dni;
    nuevaPersona->numSala = num;
    nuevaPersona->fila = fil;
    nuevaPersona->columna = column;

    return nuevaPersona;

};

int getDni(PersonaPtr persona){

    return persona->dni;

};

int getNumSala(PersonaPtr persona){

    return persona->numSala;

};

int getFila(PersonaPtr persona){

    return persona->fila;

};

int getColumna(PersonaPtr persona){

    return persona->columna;

};

void liberarPersona(PersonaPtr persona){

    free(persona);

};
