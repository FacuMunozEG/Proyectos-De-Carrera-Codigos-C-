/*
Apellido: Muñoz Gimenez, Facundo Ezequiel
DNI: 46346378
*/

#include "Juego_Prototipos.h"

int WinMain()
{
    Boton uiinf;
    MenuUI ui;
    Vector vector;
    Ventana *menu = malloc(sizeof(Ventana));
    if(iniciarMenu(menu, &ui) != COD_OK)
    {
        free(menu);
        return ERR_SDL;
    }

    int cargarPartida=loop_menu(&menu,&ui);
    while(cargarPartida==MENU)
    {
        iniciarMenu(menu, &ui);
        cargarPartida=loop_menu(&menu,&ui);
    }
    vectorCrear(&vector, sizeof(Tablero));
    //Tablero *tablero;
    if(cargarPartida == CARGAR)
    {
        cerrar_todo(menu, &ui);
        if (vectorAgregarElemento(&vector,leerPartida())) return ERR_MEM;
        //tablero = leerPartida();
        //if(!tablero) return ERR_ARCH;
    }
    else if(cargarPartida==NUEVO)
    {
        cerrar_todo(menu, &ui);
        char nombreJugador[11];
        if(obtenerNombreJugador(nombreJugador) != COD_OK)
        {
            free(menu);
            vectorTableroDestruir(&vector);
            return ERR_SDL;
        }
        if (vectorAgregarElemento(&vector,tableroCrear(nombreJugador)))
        {
            free(menu);
            return ERR_MEM;
        }
        //tablero = tableroCrear(nombreJugador);
        //if (!tablero) return ERR_ARCH;
    }
    else
        return ERR_SDL;

    free(menu);

    //Temas sdl
    Ventana *ventana = ventanaCrear(&vector);
    if (!ventana)
    {
        vectorTableroDestruir(&vector);
        return ERR_SDL;
    }


    Click click;
    int ending = 0, accion;
    bool reinicio=false;

    //Bucle hasta recibir el primer click
    if(cargarPartida == NUEVO)
    {
        tableroDibujar(&vector,ventana,&uiinf,PRIMERINGRESO);
        accion = clickIngresar(&click, ventana, &vector,&uiinf, PRIMERINGRESO);
        while(accion != CLICK_IZQUIERDO)
        {
            if (procesarAccion(accion, &reinicio, &vector, &ventana, &uiinf, &click) != COD_OK)
                return ERR_ARCH;
            tableroDibujar(&vector,ventana,&uiinf,PRIMERINGRESO);
            accion = clickIngresar(&click, ventana, &vector,&uiinf, PRIMERINGRESO);
        }
        iniciarJuego(&vector, &click);
    }
    else
    {
        tableroDibujar(&vector,ventana,&uiinf,JUGANDO);
        accion = clickIngresar(&click,ventana, &vector,&uiinf, JUGANDO);
    }

    //Bucle principal del juego
    if(buscaminasJugar(&vector, &ventana, &uiinf, &click, accion, &reinicio, &ending) != COD_OK)
        return ERR_SDL;


    guardarLog("Fin del juego", "Izquierdo", &click);
    if(ending == COD_DERROTA)
        procesarDerrota(&vector, ventana,&uiinf);
    else
        procesarVictoria(&vector, ventana,&uiinf);

    escribirEstadisticas(&vector, ventana);
    clickIngresar(&click,ventana, &vector,&uiinf, PARTIDAFINALIZADA);
    vectorTableroDestruir(&vector);
    ventanaDestruir(ventana, &uiinf);
    return COD_OK;
}
