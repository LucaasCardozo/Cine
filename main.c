#include <stdio.h>
#include <stdlib.h>
#include "cine.h"
#include "sala.h"
#include "persona.h"
#include "lista.h"

int main()
{

    /// 1- Crear el cine: Cinemark Avellaneda, Guemes 897

    CinePtr cine = crearCine("Cinemark Avellaneda", "Guemes 897");

    ///2- Enlistar 3 salas:
    //1, Sala 2D, 5, 10. Es decir matriz de 5 x 10 en esa sala
    //2, Sala 3D, 10,15
    //3, Sala 4D XD, 15, 10
    SalaPtr sala1 = crearSala(1, "Sala 2D", 5, 10);
    SalaPtr sala2 = crearSala(2, "Sala 3D", 10,15);
    SalaPtr sala3 = crearSala(3, "Sala 4D XD", 15, 10);

    insertarSala(cine, sala1);
    insertarSala(cine, sala2);
    insertarSala(cine, sala3);

    ///3- Mostrar el Cine con sus salas y butacas

    mostrarCine(cine);

    ///4-  Enlistar a las siguientes personas en las salas
    //11111,1,2,3. La persona 11111, en la sala 1, butaca [2][3]
    //22222,1,3,4
    //33333,1,4,9
    //44444,1,3,4. Esta persona debería tirar error porque ese asiento estaba ocupado.
    //55555,2,1,1
    PersonaPtr persona1 = crearPersona(11111, 1, 2, 3);
    PersonaPtr persona2 = crearPersona(22222, 1, 3, 4);
    PersonaPtr persona3 = crearPersona(33333, 1, 4, 9);
    PersonaPtr persona4 = crearPersona(44444, 1, 3, 4);
    PersonaPtr persona5 = crearPersona(55555, 2, 1, 1);

    insertarPersona(sala1, persona1);
    insertarPersona(sala1, persona2);
    insertarPersona(sala1, persona3);
    insertarPersona(sala1, persona4);
    insertarPersona(sala2, persona5);

    ///5- Mostrar el Cine con sus salas y butacas
    printf("\n\n");
    mostrarCine(cine);

    liberarCine(cine);

    return 0;
}
