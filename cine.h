#ifndef CINE_H_INCLUDED
#define CINE_H_INCLUDED

#include "lista.h"
#include "sala.h"

struct CineE;

typedef struct CineE * CinePtr;

CinePtr crearCine(char nombre[20], char direccion[20]);

void mostrarCine(CinePtr cine);

void insertarSala(CinePtr cine, SalaPtr sala);

char* getNombreCine(CinePtr cine);
char* getDireccionCine(CinePtr cine);
ListaPtr getSalasCine(CinePtr cine);

void setNombreCine(CinePtr cine, char nuevoNombre[20]);
void setDireccionCine(CinePtr cine, char nuevaDireccion[20]);
void setSalasCine(CinePtr cine, ListaPtr nuevasSalas);

void liberarCine(CinePtr cine);

#endif // CINE_H_INCLUDED
