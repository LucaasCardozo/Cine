#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct PersonaE;

typedef struct PersonaE * PersonaPtr;

PersonaPtr crearPersona(int dni, int num, int fil, int column);

int getDni(PersonaPtr persona);
int getNumSala(PersonaPtr persona);
int getFila(PersonaPtr persona);
int getColumna(PersonaPtr persona);

void liberarPersona(PersonaPtr persona);

#endif // PERSONA_H_INCLUDED
