#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

#include "lista.h"
#include "persona.h"

struct SalaE;

typedef struct SalaE * SalaPtr;

SalaPtr crearSala(int numero, char tipo[20], int fil, int column);

void mostrarSala(SalaPtr sala);

void insertarPersona(SalaPtr sala, PersonaPtr persona);

void liberarSala(SalaPtr sala);

#endif // SALA_H_INCLUDED
