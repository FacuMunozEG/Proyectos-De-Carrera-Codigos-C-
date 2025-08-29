#include "Juego_Prototipos.h"



SDL_Color colores[] =
{
    {141, 141, 141, 255},//[0]  - Gris 1
    {133, 133, 133, 255},//[1]  - Gris 2
    {133, 150, 133, 255},//[2]  - Gris 3
    {35, 30, 24, 255},//[3]  - Negro 1
    {29, 25, 20, 255},//[4]  - Negro 2
    {0, 0, 0, 255},//[5]  - Negro 3
    {23, 83, 168, 255},//[6]  - Azul 1
    {17, 63, 141, 255},//[7]  - Azul 2
    {130, 195, 75, 255},//[8]  - Verde Hoja 1
    {117, 180, 75, 255},//[9]  - Verde Hoja 2
    {112, 169, 66, 255},//[10] - Verde Hoja 3
    {0, 149, 42, 255},//[11] - Verde 1
    {1, 84, 2, 255},//[12] - Verde 2
    {253, 0, 0, 255},//[13] - Rojo 1
    {172, 15, 2, 255},//[14] - Rojo 2
    {113, 2, 1, 255},//[15] - Rojo 3
    {183, 239, 242, 255},//[16] - Celeste 1
    {76, 236, 219, 255},//[17] - Celeste 2
    {255, 255, 255, 255},//[18] - Amarillo 1
    {255, 247, 0, 255},//[19] - Amarillo 2
    {214, 208, 27, 255},//[20] - Amarillo 3
    {170, 0, 10, 255},//[21] - Rojo Oscuro 1
    {150, 69, 75, 255},//[22] - Rojo Oscuro 2
    {57, 32, 32, 255},//[23] - Rojo Oscuro 3
    {255, 255, 255, 255},//[24] - Blanco 1
    {195, 0, 255, 255},//[25] - Violeta 1
    {255, 156, 0, 255},//[26] - Naranja 1
    {147, 116, 67, 255},//[27] - Marrón 1
    {62, 51, 32, 255},//[28] - Marrón 2
    {189, 138, 115,255}, //[29] - Piel
    {144, 94, 68,255},//[30] - LABIOS
    {120, 65, 54,255}, //[31] - NARIZ
    {73, 49, 25,255}, //[32] - PELO2
    {144, 91, 65,255}, //[33] - BARBA1
    {96, 59, 37,255}, //[34] - BARBA2
    {27, 164, 56,255}, //[35] - VERDE CREEPER
    {0,0,0,255}, // [36] - NEGRO ORIGINAL
    {56, 115, 12,255}, // [37] - HOJA1
    {32, 71, 10,255}, //[38] - HOJA2
    {82, 61, 137,255} //[39] - OJOS
};
///--------COMIENZO DISEÑO CARAS DE ESTADO------------------ ///
int caraJugando[8][8]= {{PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL},{PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL},{PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL},
    {PIEL,MARRON2,MARRON2,MARRON2,MARRON2,MARRON2,MARRON2,PIEL},{PIEL,BLANCO1,VERDE1,PIEL,PIEL,VERDE1,BLANCO1,PIEL},{NARIZ,PIEL,PIEL,NARIZ,NARIZ,PIEL,PIEL,NARIZ},
    {NARIZ,PIEL,LABIOS,NARIZ,NARIZ,LABIOS,PIEL,NARIZ},{NARIZ,PIEL,PIEL,NARIZ,NARIZ,PIEL,PIEL,NARIZ}
};

int caraGanador[8][8]= {{PELO2,MARRON2,PELO2,MARRON2,MARRON2,MARRON2,MARRON2,MARRON2},{MARRON2,MARRON2,MARRON2,MARRON2,PELO2,PELO2,MARRON2,MARRON2},
    {MARRON2,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PELO2},{PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL,PIEL},
    {PIEL,BLANCO1,OJOS,PIEL,PIEL,OJOS,BLANCO1,PIEL},{BARBA1,PIEL,PIEL,NARIZ,NARIZ,PIEL,PIEL,BARBA1},
    {BARBA1,BARBA1,PELO2,LABIOS,LABIOS,PELO2,BARBA1,BARBA1},{BARBA2,BARBA2,MARRON2,MARRON2,MARRON2,MARRON2,BARBA2,BARBA2}
};
int caraPerdedor[8][8]= {{CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER},{CREEPER,NEGROPURO,NEGROPURO,CREEPER,CREEPER,NEGROPURO,NEGROPURO,CREEPER},
    {CREEPER,NEGROPURO,NEGROPURO,CREEPER,CREEPER,NEGROPURO,NEGROPURO,CREEPER},{CREEPER,CREEPER,CREEPER,NEGROPURO,NEGROPURO,CREEPER,CREEPER,CREEPER},
    {CREEPER,CREEPER,NEGROPURO,NEGROPURO,NEGROPURO,NEGROPURO,CREEPER,CREEPER},{CREEPER,CREEPER,NEGROPURO,NEGROPURO,NEGROPURO,NEGROPURO,CREEPER,CREEPER},
    {CREEPER,CREEPER,NEGROPURO,CREEPER,CREEPER,NEGROPURO,CREEPER,CREEPER},{CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER,CREEPER}
};
///--------FIN DISEÑO CARAS DE ESTADO------------------ ///

/// -------COMIENZO DISEÑOS DE CELDAS-------------///
int Bandera[7][7]= {{VERDEHOJA2,VERDEHOJA1,VERDEHOJA1,ROJO1,VERDEHOJA2,VERDEHOJA2,VERDEHOJA2},{VERDEHOJA1,VERDEHOJA3,ROJO1,NARANJA1,ROJO1,VERDEHOJA1,VERDEHOJA2},{VERDEHOJA2,VERDEHOJA2,ROJO1,BLANCO1,ROJO1,VERDEHOJA1,VERDEHOJA2},
    {VERDEHOJA2,VERDEHOJA3,VERDEHOJA1,ROJO1,VERDEHOJA2,VERDEHOJA3,VERDEHOJA2},{VERDEHOJA2,VERDEHOJA3,VERDEHOJA2,MARRON1,VERDEHOJA3,VERDEHOJA3,VERDEHOJA2},{VERDEHOJA1,VERDEHOJA1,VERDEHOJA1,MARRON2,VERDEHOJA1,VERDEHOJA3,VERDEHOJA2},
    {VERDEHOJA2,VERDEHOJA1,VERDEHOJA2,MARRON2,VERDEHOJA1,VERDEHOJA2,VERDEHOJA2}
};

int Uno[7][7]= {{GRIS1,GRIS1,GRIS1,NEGRO2,GRIS2,GRIS2,GRIS1},{GRIS2,GRIS2,NEGRO2,NEGRO1,GRIS1,GRIS1,GRIS2},{GRIS2,GRIS1,GRIS1,NEGRO1,GRIS2,GRIS2,GRIS2},
    {GRIS1,GRIS1,GRIS1,NEGRO2,GRIS1,GRIS1,GRIS1},{GRIS2,GRIS2,GRIS2,NEGRO1,GRIS2,GRIS2,GRIS2},{GRIS1,GRIS1,GRIS2,NEGRO1,GRIS1,GRIS1,GRIS2},
    {GRIS1,GRIS2,NEGRO3,NEGRO3,NEGRO3,GRIS2,GRIS1}
};

int Dos[7][7]= {{GRIS1,GRIS1,AZUL2,AZUL2,AZUL1,GRIS2,GRIS1},{GRIS2,AZUL2,AZUL1,GRIS2,AZUL1,AZUL2,GRIS2},{GRIS2,AZUL2,GRIS1,GRIS1,AZUL2,AZUL2,GRIS2},
    {GRIS1,GRIS1,GRIS1,AZUL1,AZUL1,GRIS1,GRIS1},{GRIS2,GRIS2,AZUL2,AZUL1,GRIS2,GRIS2,GRIS2},{GRIS1,AZUL2,AZUL1,GRIS1,GRIS1,GRIS1,GRIS2},
    {GRIS1,AZUL2,AZUL2,AZUL1,AZUL1,AZUL2,GRIS1}
};

int Tres[7][7]= {{GRIS1,GRIS1,VERDE2,VERDE1,VERDE1,GRIS2,GRIS1},{GRIS2,VERDE2,GRIS1,GRIS2,GRIS1,VERDE1,GRIS2},{GRIS2,GRIS1,GRIS1,GRIS1,VERDE1,VERDE2,GRIS2},
    {GRIS1,GRIS1,VERDE2,VERDE1,VERDE1,GRIS1,GRIS1},{GRIS2,GRIS2,GRIS2,GRIS1,VERDE2,VERDE2,GRIS2},{GRIS1,VERDE1,GRIS2,GRIS1,GRIS1,VERDE2,GRIS2},
    {GRIS1,GRIS2,VERDE1,VERDE2,VERDE2,GRIS2,GRIS1}
};

int Cuatro[7][7]= {{GRIS1,GRIS1,GRIS1,ROJO2,ROJO1,GRIS2,GRIS1},{GRIS2,GRIS2,ROJO2,GRIS2,ROJO3,GRIS1,GRIS2},{GRIS2,ROJO2,GRIS1,GRIS1,ROJO1,GRIS2,GRIS2},
    {GRIS1,ROJO1,ROJO3,ROJO1,ROJO1,ROJO2,GRIS1},{GRIS2,GRIS2,GRIS2,GRIS1,ROJO2,GRIS2,GRIS2},{GRIS1,GRIS1,GRIS2,GRIS1,ROJO1,GRIS1,GRIS2},
    {GRIS1,GRIS2,GRIS2,GRIS2,ROJO3,GRIS2,GRIS1}
};

int Cinco[7][7]= {{GRIS1,CELESTE2,CELESTE2,CELESTE2,CELESTE1,CELESTE1,GRIS1},{GRIS2,CELESTE1,CELESTE2,GRIS2,GRIS1,GRIS1,GRIS2},{GRIS2,CELESTE1,CELESTE1,GRIS1,GRIS2,GRIS2,GRIS2},
    {GRIS1,CELESTE2,CELESTE1,CELESTE1,CELESTE2,GRIS1,GRIS1},{GRIS2,GRIS2,GRIS2,GRIS1,CELESTE1,CELESTE2,GRIS2},{GRIS1,CELESTE2,GRIS2,GRIS1,GRIS1,CELESTE1,GRIS2},
    {GRIS1,CELESTE2,CELESTE2,CELESTE2,CELESTE2,CELESTE1,GRIS1}
};

int Seis[7][7]= {{GRIS1,GRIS1,GRIS1,AMARILLO3,AMARILLO3,GRIS2,GRIS1},{GRIS2,GRIS2,AMARILLO2,AMARILLO2,GRIS1,GRIS1,GRIS2},{GRIS2,AMARILLO3,AMARILLO2,GRIS1,GRIS2,GRIS2,GRIS2},
    {GRIS1,AMARILLO3,GRIS1,GRIS2,GRIS1,GRIS1,GRIS1},{GRIS2,AMARILLO3,AMARILLO3,AMARILLO2,AMARILLO1,AMARILLO1,GRIS2},{GRIS1,AMARILLO2,GRIS2,GRIS1,GRIS1,AMARILLO1,GRIS2},
    {GRIS1,AMARILLO2,AMARILLO2,AMARILLO3,AMARILLO3,AMARILLO3,GRIS1}
};

int Siete[7][7]= {{ROJOOSCURO2,BLANCO1,BLANCO1,BLANCO1,BLANCO1,BLANCO1,ROJOOSCURO1},{ROJOOSCURO3,ROJOOSCURO3,ROJOOSCURO2,ROJOOSCURO3,BLANCO1,BLANCO1,ROJOOSCURO3},{ROJOOSCURO3,ROJOOSCURO2,ROJOOSCURO3,ROJOOSCURO2,BLANCO1,BLANCO1,ROJOOSCURO2},
    {ROJOOSCURO2,ROJOOSCURO1,ROJOOSCURO3,BLANCO1,BLANCO1,ROJOOSCURO3,ROJOOSCURO1},{ROJOOSCURO2,ROJOOSCURO3,ROJOOSCURO2,BLANCO1,BLANCO1,ROJOOSCURO2,ROJOOSCURO3},{ROJOOSCURO3,ROJOOSCURO3,BLANCO1,BLANCO1,ROJOOSCURO2,ROJOOSCURO3,ROJOOSCURO2},
    {ROJOOSCURO1,ROJOOSCURO2,BLANCO1,BLANCO1,ROJOOSCURO3,ROJOOSCURO1,ROJOOSCURO3}
};

int Ocho[7][7]= {{BLANCO1,GRIS1,VIOLETA1,VIOLETA1,VIOLETA1,GRIS1,BLANCO1},{GRIS1,VIOLETA1,GRIS1,BLANCO1,BLANCO1,VIOLETA1,BLANCO1},{BLANCO1,VIOLETA1,GRIS1,BLANCO1,GRIS1,VIOLETA1,GRIS1},
    {BLANCO1,BLANCO1,VIOLETA1,VIOLETA1,VIOLETA1,BLANCO1,BLANCO1},{GRIS1,VIOLETA1,BLANCO1,GRIS1,BLANCO1,VIOLETA1,BLANCO1},{BLANCO1,VIOLETA1,GRIS1,BLANCO1,GRIS1,VIOLETA1,GRIS1},
    {GRIS1,BLANCO1,VIOLETA1,VIOLETA1,VIOLETA1,BLANCO1,GRIS1}
};

int MinaReventada[7][7]= {{ROJO1,ROJO3,ROJO1,ROJO3,ROJO1,ROJO3,ROJO1},{ROJO1,ROJO3,ROJO1,ROJO3,ROJO1,ROJO3,ROJO1},{BLANCO1,BLANCO1,GRIS2,GRIS2,BLANCO1,BLANCO1,BLANCO1},
    {GRIS2,NEGRO3,BLANCO1,NEGRO3,BLANCO1,NEGRO3,BLANCO1},{BLANCO1,BLANCO1,BLANCO1,BLANCO1,BLANCO1,GRIS2,GRIS2},{ROJO1,ROJO3,ROJO1,ROJO3,ROJO1,ROJO3,ROJO1},
    {ROJO1,ROJO3,ROJO1,ROJO3,ROJO1,ROJO3,ROJO1}
};

int celdaCubierta[7][7]= {{VERDEHOJA2,VERDEHOJA1,VERDEHOJA1,VERDEHOJA1,VERDEHOJA2,VERDEHOJA2,VERDEHOJA2},{VERDEHOJA1,VERDEHOJA3,VERDEHOJA3,VERDEHOJA1,VERDEHOJA1,VERDEHOJA1,VERDEHOJA2},{VERDEHOJA2,VERDEHOJA2,VERDEHOJA1,VERDEHOJA2,VERDEHOJA2,VERDEHOJA1,VERDEHOJA2},
    {VERDEHOJA2,VERDEHOJA3,VERDEHOJA1,VERDEHOJA2,VERDEHOJA2,VERDEHOJA3,VERDEHOJA2},{VERDEHOJA2,VERDEHOJA3,VERDEHOJA2,VERDEHOJA1,VERDEHOJA3,VERDEHOJA3,VERDEHOJA2},{VERDEHOJA1,VERDEHOJA1,VERDEHOJA1,VERDEHOJA3,VERDEHOJA1,VERDEHOJA3,VERDEHOJA2},
    {VERDEHOJA2,VERDEHOJA1,VERDEHOJA2,VERDEHOJA3,VERDEHOJA1,VERDEHOJA2,VERDEHOJA2}
};

int celdaDescubierta[7][7]= {{GRIS1,GRIS1,GRIS1,GRIS2,GRIS2,GRIS2,GRIS1},{GRIS2,GRIS2,GRIS1,GRIS2,GRIS1,GRIS1,GRIS2},{GRIS2,GRIS1,GRIS1,GRIS1,GRIS2,GRIS2,GRIS2},
    {GRIS1,GRIS1,GRIS1,GRIS2,GRIS1,GRIS1,GRIS1},{GRIS2,GRIS2,GRIS2,GRIS1,GRIS2,GRIS2,GRIS2},{GRIS1,GRIS1,GRIS2,GRIS1,GRIS1,GRIS1,GRIS2},
    {GRIS1,GRIS2,GRIS2,GRIS2,GRIS1,GRIS2,GRIS1}
};
/// -------COMIENZO DISEÑOS DE CELDAS-------------///
///--------DISEÑO DE LA INTERFAZ-------------///
int HojasInterfaz[7][7]= {{HOJA1,HOJA1,HOJA1,HOJA2,NEGRO1,NEGRO1,NEGRO1},{HOJA1,HOJA2,HOJA1,NEGRO1,NEGRO1,HOJA1,HOJA1},{HOJA1,HOJA2,HOJA1,NEGRO1,NEGRO1,HOJA1,HOJA1},
    {HOJA2,HOJA2,NEGRO1,HOJA1,HOJA1,HOJA2,HOJA1},{NEGRO1,HOJA1,HOJA2,HOJA1,HOJA2,NEGRO1,HOJA1},{NEGRO1,HOJA1,HOJA2,NEGRO1,HOJA1,NEGRO1,HOJA2},
    {NEGRO1,HOJA1,HOJA2,HOJA2,HOJA1,NEGRO1,HOJA1}
};

int iniciarMenu(Ventana *menu, MenuUI *ui)
{
    menu->altoVentana =ALTO_MENU*TAM_PIXEL*10;
    menu->anchoVentana =ANCHO_MENU*TAM_PIXEL*10;
    if (ventanaInicializarSDL(menu) != COD_OK)
        return ERR_SDL;
    if(dibujarOpcionesMenu(ui, menu, "BUSCAMINAS") != COD_OK) return ERR_SDL;
    SDL_Texture* fondo=cargar_fondo(menu->renderer);
    if(fondo == NULL) return ERR_SDL;
    ui->fondo = fondo;
    return COD_OK;
}

SDL_Texture* cargar_fondo(SDL_Renderer *renderer)
{
    SDL_Texture* fondo = IMG_LoadTexture(renderer, "img/Fondo_BM.png");
    if (!fondo)
    {
        SDL_Log("No se pudo cargar el fondo: %s", IMG_GetError());
        return NULL;
    }
    return fondo;
}

int dibujarOpcionesMenu(MenuUI* ui, Ventana* menu, const char* textoTitulo)
{
    if(TTF_Init() == -1) return ERR_SDL;
    char *fuenteLink = "fnt/MinecraftTen-VGORe.ttf";
    SDL_Color color = {0, 0, 0, 255};

    //TITULO
    inicializarFuente(&ui->fuente, fuenteLink, 36);
    SDL_Surface* supTitulo = TTF_RenderText_Solid(ui->fuente, textoTitulo, color);
    ui->textoTitulo = SDL_CreateTextureFromSurface(menu->renderer, supTitulo);
    ui->rectTitulo.x = (menu->anchoVentana - supTitulo->w) / 2;
    ui->rectTitulo.y = 20;
    ui->rectTitulo.w = supTitulo->w;
    ui->rectTitulo.h = supTitulo->h;
    SDL_FreeSurface(supTitulo);

    // Botón Nueva Partida
    inicializarFuente(&ui->fuente, fuenteLink, 22);
    SDL_Surface* supNueva = TTF_RenderText_Solid(ui->fuente, "Partida nueva", color);
    ui->botonNueva = SDL_CreateTextureFromSurface(menu->renderer, supNueva);
    ui->rectBotonNueva.w = supNueva->w;
    ui->rectBotonNueva.h = supNueva->h;
    ui->rectBotonNueva.x = (menu->anchoVentana - supNueva->w) / 2;
    ui->rectBotonNueva.y = (menu->altoVentana / 2) - supNueva->h - 10;
    SDL_FreeSurface(supNueva);

    // Botón Continuar
    SDL_Surface* supCont = TTF_RenderText_Solid(ui->fuente, "Continuar partida", color);
    ui->botonContinuar = SDL_CreateTextureFromSurface(menu->renderer, supCont);
    ui->rectBotonContinuar.w = supCont->w;
    ui->rectBotonContinuar.h = supCont->h;
    ui->rectBotonContinuar.x = (menu->anchoVentana - supCont->w) / 2;
    ui->rectBotonContinuar.y = (menu->altoVentana / 2) + 10 + supCont->h;
    SDL_FreeSurface(supCont);

    // Icono engranaje
    ui->iconoEngranaje = IMG_LoadTexture(menu->renderer, "img/engranaje.png");
    if (!ui->iconoEngranaje)
    {
        printf("Error cargando icono engranaje: %s\n", SDL_GetError());
        exit(1);
    }
    ui->rectEngranaje.x = 10;
    ui->rectEngranaje.y = menu->altoVentana - 42;
    ui->rectEngranaje.w = 32;
    ui->rectEngranaje.h = 32;

    return COD_OK;
}

int loop_menu(Ventana** v, MenuUI* ui)
{
    SDL_Event e;
    float bgX = 0;
    float velocidad = 0.5;
    int direccion = 1;

    int ancho_textura, alto_textura;
    SDL_QueryTexture(ui->fondo, NULL, NULL, &ancho_textura, &alto_textura);

    int corriendo = 1;
    while (corriendo)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                corriendo = 0;
                break;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                if (clickPartida(&e, ui->rectBotonContinuar))
                {
                    if(archivoEstaCreado("partida_anterior.dat"))
                    {
                        liberarMenu(ui);
                        return CARGAR;
                    }
                    else
                    {
                        renderizarError(*v, "No hay ninguna partida guardada");
                    }
                }
                if (clickPartida(&e, ui->rectBotonNueva))
                {
                    liberarMenu(ui);
                    return NUEVO;
                }
                if (clickPartida(&e, ui->rectEngranaje))
                {
                    ///aca deberia ir la logica del menu de configuracion
                    liberarMenu(ui);
                    SDL_DestroyTexture(ui->fondo);

                    //SDL_DestroyWindow((*v)->window);  // Cerramos ventana actual
                    cerrarSDL(*v);
                    // --- Abrimos nueva ventana para configuración ---
                    Ventana ventanaConfig;
                    ventanaConfig.anchoVentana = 350;
                    ventanaConfig.altoVentana = 500;

                    ventanaConfig.window = SDL_CreateWindow("Configuración",
                                                            SDL_WINDOWPOS_CENTERED,
                                                            SDL_WINDOWPOS_CENTERED,
                                                            ventanaConfig.anchoVentana,
                                                            ventanaConfig.altoVentana,
                                                            SDL_WINDOW_SHOWN);
                    ventanaConfig.renderer = SDL_CreateRenderer(ventanaConfig.window, -1, SDL_RENDERER_ACCELERATED);
                    ConfigUI cfg;

                    cargarDatos(&cfg);
                    loop_configuracion(&ventanaConfig,&cfg);
                    dibujarMenuConfiguracion(&ventanaConfig,&cfg);


                    TTF_CloseFont(cfg.fuente);
                    SDL_DestroyRenderer(ventanaConfig.renderer);
                    SDL_DestroyWindow(ventanaConfig.window);

                    return MENU;

                }
            }
        }

        bgX += direccion * velocidad;
        if (bgX >= ancho_textura - (*v)->anchoVentana) direccion = -1;
        if (bgX <= 0) direccion = 1;

        dibujar_menu(v, ui->fondo, bgX);
        dibujarFondosBotones(ui, *v);
        dibujarTextos(ui, *v);

        // Dibuja el engranaje
        SDL_RenderCopy((*v)->renderer, ui->iconoEngranaje, NULL, &ui->rectEngranaje);

        SDL_RenderPresent((*v)->renderer);
        SDL_Delay(16);
    }

    liberarMenu(ui);
    return -1;
}

bool clickPartida(SDL_Event * evento,SDL_Rect rect)
{
    return (evento->button.x >= rect.x && evento->button.x <= rect.x + rect.w) &&
           (evento->button.y >= rect.y && evento->button.y <= rect.y + rect.h);
}

void liberarMenu(MenuUI* ui)
{
    SDL_DestroyTexture(ui->textoTitulo);
    SDL_DestroyTexture(ui->botonNueva);
    SDL_DestroyTexture(ui->botonContinuar);
    SDL_DestroyTexture(ui->iconoEngranaje);
    TTF_CloseFont(ui->fuente);
}

void cargarDatos(ConfigUI * cfg)
{
    FILE* archivo = fopen("buscaminas.conf", "rt");
    if (!archivo)
    {
        // Si no existe, valores por defecto
        cfg->minas = 10;
        cfg->orden = 9;
    }
    else
    {
        char linea[64];
        int valor;
        fgets(linea,1,archivo);
        if(sscanf(linea,"tam_tablero=%d",&valor))cfg->orden=valor;
        fgets(linea,1,archivo);
        if(sscanf(linea,"cantidad_minas=%d",&valor))cfg->minas=valor;
    }
    // Convertir los enteros a texto para mostrarlos en pantalla
    snprintf(cfg->minasTexto, sizeof(cfg->minasTexto), "%d", cfg->minas);
    snprintf(cfg->ordenTexto, sizeof(cfg->ordenTexto), "%d", cfg->orden);
}

void loop_configuracion(Ventana * cv,ConfigUI * cfg)
{
    int corriendo=1;
    SDL_Event e;
    SDL_StartTextInput();
    while(corriendo)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type==SDL_QUIT) corriendo=0;
            if(e.type==SDL_MOUSEBUTTONDOWN)
            {
                if(clickPartida(&e,cfg->cajaMinas))
                    cfg->cajaActiva=1;

                if(clickPartida(&e,cfg->cajaOrden))
                    cfg->cajaActiva=2;

                if(clickPartida(&e,cfg->botonGuardar))
                {
                    if(configuracionValida(cfg, cv))
                    {
                        guardarConfiguracion(cfg);
                        return;
                    }
                }

            }

            if(e.type==SDL_TEXTINPUT)
            {
                if (cfg->cajaActiva == 1 && strlen(cfg->minasTexto) < 9 && (isdigit(e.text.text[0]) || e.text.text[0] == '%'))
                    strcat(cfg->minasTexto, e.text.text);
                else if (cfg->cajaActiva == 2 && strlen(cfg->ordenTexto) < 9 && (isdigit(e.text.text[0])))
                    strcat(cfg->ordenTexto, e.text.text);
            }

            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE)
            {
                if (cfg->cajaActiva == 1 && strlen(cfg->minasTexto) > 0)
                {
                    cfg->minasTexto[strlen(cfg->minasTexto) - 1] = '\0';
                }
                else if (cfg->cajaActiva == 2 && strlen(cfg->ordenTexto) > 0)
                {
                    cfg->ordenTexto[strlen(cfg->ordenTexto) - 1] = '\0';
                }
            }
        }
        SDL_SetRenderDrawColor(cv->renderer, 109, 109, 109, 255); // limpiar fondo negro
        SDL_RenderClear(cv->renderer);

        dibujarOpciones(cv, cfg);
        dibujarCuadrosTexto(cv, cfg); // esto incluye el texto dentro de las cajas

        SDL_RenderPresent(cv->renderer);
    }
    SDL_StopTextInput();
}

void dibujarMenuConfiguracion(Ventana * ventanaConfig,ConfigUI * cfg)
{
    dibujarOpciones(ventanaConfig,cfg);
    dibujarCuadrosTexto(ventanaConfig,cfg);
    SDL_RenderPresent(ventanaConfig->renderer);
}

bool configuracionValida(ConfigUI *cfg, Ventana *v)
{
    int minasLeidas, ordenLeido, cantVariablesLeidas;
    char charLeido, error[MAX_ERROR_LEN];

    sscanf(cfg->ordenTexto,"%d",&ordenLeido);
    if(validarOrdenLeido(ordenLeido, error) < 0)
    {
        if(renderizarError(v, error) != COD_OK) return false;
        return false;
    }

    cantVariablesLeidas = sscanf(cfg->minasTexto,"%d%c",&minasLeidas,&charLeido);

    if(validarMinasLeidas(ordenLeido * ordenLeido, cantVariablesLeidas, minasLeidas, charLeido, error) < 0)
    {
        if(renderizarError(v, error) != COD_OK) return false;
        return false;
    }

    return true;
}

int renderizarError(Ventana *v, char *error)
{
    TTF_Init();
    TTF_Font *fuente;
    if(inicializarFuente(&fuente, "fnt/mineTexto.TTF", 10) != COD_OK) return ERR_SDL;
    if(renderizarTexto(MARGEN,v->altoVentana - MARGEN,v->renderer,0,v->anchoVentana,&fuente,error,colores[BLANCO1]) != COD_OK) return ERR_SDL;
    SDL_RenderPresent(v->renderer);
    SDL_Delay(1000);
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
    puts(error);
    TTF_CloseFont(fuente);
    TTF_Quit();
    return COD_OK;
}

void dibujar_menu(Ventana** v, SDL_Texture* fondo, int bgX)
{
    int zoom_ancho = (*v)->anchoVentana * 1.5;
    int zoom_alto = (*v)->altoVentana * 2;
    int offset_y = 100;

    SDL_Rect src = {(int)bgX, offset_y, zoom_ancho, zoom_alto};
    SDL_Rect dest = {0, 0, (*v)->anchoVentana, (*v)->altoVentana};

    SDL_RenderClear((*v)->renderer);
    SDL_RenderCopy((*v)->renderer, fondo, &src, &dest);
}

void dibujarFondosBotones(MenuUI* ui, Ventana* menu)
{
    SDL_Color colorFondo = {100, 100, 100, 255};

    // fondo común para ambos botones
    int fondoW = (ui->rectBotonNueva.w > ui->rectBotonContinuar.w ? ui->rectBotonNueva.w : ui->rectBotonContinuar.w) + 40;
    int fondoH = (ui->rectBotonNueva.h > ui->rectBotonContinuar.h ? ui->rectBotonNueva.h : ui->rectBotonContinuar.h) + 20;

    SDL_Rect fondoNueva =
    {
        (menu->anchoVentana - fondoW) / 2,
        ui->rectBotonNueva.y - 10,
        fondoW,
        fondoH
    };

    SDL_Rect fondoContinuar =
    {
        (menu->anchoVentana - fondoW) / 2,
        ui->rectBotonContinuar.y - 10,
        fondoW,
        fondoH
    };

    SDL_SetRenderDrawColor(menu->renderer, colorFondo.r, colorFondo.g, colorFondo.b, colorFondo.a);
    SDL_RenderFillRect(menu->renderer, &fondoNueva);
    SDL_RenderFillRect(menu->renderer, &fondoContinuar);
}

void dibujarTextos(MenuUI* ui, Ventana* menu)
{
    SDL_RenderCopy(menu->renderer, ui->textoTitulo, NULL, &ui->rectTitulo);
    SDL_RenderCopy(menu->renderer, ui->botonNueva, NULL, &ui->rectBotonNueva);
    SDL_RenderCopy(menu->renderer, ui->botonContinuar, NULL, &ui->rectBotonContinuar);
}

void guardarConfiguracion(ConfigUI * cfg)
{
    FILE * arch=fopen("buscaminas.conf","wt");
    if(!arch)
    {
        puts("Error al intentar abrir archivo de configuracion");
        exit(ERR_ARCH);
    }
    cfg->minas = atoi(cfg->minasTexto);
    cfg->orden = atoi(cfg->ordenTexto);
    fprintf(arch, "tam_tablero=%d\n", cfg->orden);
    fprintf(arch, "cantidad_minas=%d", cfg->minas);
    fclose(arch);
}

void dibujarOpciones(Ventana * ventanaConfig,ConfigUI * cfg)
{
    char *fuenteLink = "fnt/MinecraftTen-VGORe.ttf";
    inicializarFuente(&cfg->fuente, fuenteLink, 36);
    SDL_Color color = {0, 0, 0, 255};  // Negro
    // -------- TEXTO 1: Título --------
    SDL_Surface* superficieTitulo = TTF_RenderText_Solid(cfg->fuente, "CONFIGURACION", color);
    SDL_Texture* texturaTitulo = SDL_CreateTextureFromSurface(ventanaConfig->renderer, superficieTitulo);
    SDL_Rect rectTitulo =
    {
        ventanaConfig->anchoVentana/7,      // ← X: cambiá esta coordenada para mover el título horizontalmente
        15,      // ← Y: cambiá esta coordenada para mover el título verticalmente
        superficieTitulo->w,
        superficieTitulo->h
    };

    // -------- TEXTO 2: Subtítulo --------
    inicializarFuente(&cfg->fuente, fuenteLink, 27);
    SDL_Surface* superficieSub = TTF_RenderText_Solid(cfg->fuente, "Cantidad de minas:", color);
    SDL_Texture* texturaSub = SDL_CreateTextureFromSurface(ventanaConfig->renderer, superficieSub);
    SDL_Rect rectSub =
    {
        ventanaConfig->anchoVentana/12,      // ← X: cambiá esta coordenada para mover el texto horizontalmente
        ventanaConfig->altoVentana/4,     // ← Y: cambiá esta coordenada para mover el texto verticalmente
        superficieSub->w,
        superficieSub->h
    };

    // -------- TEXTO 3: Otro dato --------
    inicializarFuente(&cfg->fuente, fuenteLink, 27);
    SDL_Surface* superficieDato = TTF_RenderText_Solid(cfg->fuente, "Orden del tablero:", color);
    SDL_Texture* texturaDato = SDL_CreateTextureFromSurface(ventanaConfig->renderer, superficieDato);
    SDL_Rect rectDato =
    {
        ventanaConfig->anchoVentana/12,      // ← X: cambiá esta coordenada para mover el texto horizontalmente
        ventanaConfig->altoVentana/2,     // ← Y: cambiá esta coordenada para mover el texto verticalmente
        superficieDato->w,
        superficieDato->h
    };

    color.r=255;
    color.g=0;
    color.b=0;
    color.a=255;
    inicializarFuente(&cfg->fuente, fuenteLink, 24);
    SDL_Surface* superficieGuardar = TTF_RenderText_Solid(cfg->fuente, "GUARDAR", color);
    SDL_Texture* texturaGuardar = SDL_CreateTextureFromSurface(ventanaConfig->renderer, superficieGuardar);

    // --- Rectángulo para centrar el texto dentro del botón ---
    SDL_Rect rectGuardarTexto =
    {
        ventanaConfig->anchoVentana/3+10,
        ventanaConfig->altoVentana-90,
        superficieGuardar->w,
        superficieGuardar->h
    };
    cfg->botonGuardar.x=ventanaConfig->anchoVentana/3+10;
    cfg->botonGuardar.y=ventanaConfig->altoVentana-90;
    cfg->botonGuardar.h=superficieGuardar->h;
    cfg->botonGuardar.w=superficieGuardar->w;
    // --- Dibujar texto GUARDAR ---
    SDL_RenderCopy(ventanaConfig->renderer, texturaGuardar, NULL, &rectGuardarTexto);


    // Dibujo
    SDL_RenderCopy(ventanaConfig->renderer, texturaTitulo, NULL, &rectTitulo);
    SDL_RenderCopy(ventanaConfig->renderer, texturaSub, NULL, &rectSub);
    SDL_RenderCopy(ventanaConfig->renderer, texturaDato, NULL, &rectDato);

    // Limpieza
    SDL_FreeSurface(superficieTitulo);
    SDL_DestroyTexture(texturaTitulo);
    SDL_FreeSurface(superficieSub);
    SDL_DestroyTexture(texturaSub);
    SDL_FreeSurface(superficieDato);
    SDL_DestroyTexture(texturaDato);
}

void dibujarCuadrosTexto(Ventana * vc,ConfigUI * cfg)
{
    SDL_SetRenderDrawColor(vc->renderer, 0, 0, 0, 255); // fondo negro

    SDL_Rect cuadroMinas = {vc->anchoVentana/12, vc->altoVentana/4 + 40, 300, 40};
    SDL_Rect cuadroOrden = {vc->anchoVentana/12, vc->altoVentana/2 + 40, 300, 40};

    SDL_RenderFillRect(vc->renderer, &cuadroMinas);
    SDL_RenderFillRect(vc->renderer, &cuadroOrden);

    cfg->cajaMinas = cuadroMinas;
    cfg->cajaOrden = cuadroOrden;

    // Ahora dibujamos el texto dentro de las cajas
    dibujarTextoCaja(vc->renderer, cfg->fuente, cfg->minasTexto, cfg->cajaMinas);
    dibujarTextoCaja(vc->renderer, cfg->fuente, cfg->ordenTexto, cfg->cajaOrden);
}

void dibujarTextoCaja(SDL_Renderer* renderer, TTF_Font* fuente, const char* texto, SDL_Rect caja)
{
    if (strlen(texto) == 0) return; // Nada que dibujar

    SDL_Color colorTexto = {255, 255, 255, 255}; // blanco
    SDL_Surface* superficie = TTF_RenderText_Solid(fuente, texto, colorTexto);
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

    SDL_Rect destino =
    {
        caja.x + 5,  // margen interno izquierdo
        caja.y + (caja.h - superficie->h) / 2, // centrado vertical
        superficie->w,
        superficie->h
    };

    SDL_RenderCopy(renderer, textura, NULL, &destino);

    SDL_FreeSurface(superficie);
    SDL_DestroyTexture(textura);

}

void cerrar_todo(Ventana* v, MenuUI *ui)
{
    SDL_DestroyTexture(ui->fondo);
    SDL_DestroyRenderer(v->renderer);
    SDL_DestroyWindow(v->window);
    IMG_Quit();
    SDL_Quit();
}

int obtenerNombreJugador(char *str)
{
    Ventana v;
    v.anchoVentana = 500;
    v.altoVentana = 100;

    v.window = SDL_CreateWindow("Ingresar nombre",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                v.anchoVentana,
                                v.altoVentana,
                                SDL_WINDOW_SHOWN);
    if(!v.window)
        return ERR_SDL;

    v.renderer = SDL_CreateRenderer(v.window, -1, SDL_RENDERER_ACCELERATED);
    if(!v.renderer)
    {
        SDL_DestroyWindow(v.window);
        return ERR_SDL;
    }
    SDL_SetRenderDrawColor(v.renderer, 68, 42, 26,255);
    SDL_RenderClear(v.renderer);

    int margenVentana = 3*MARGEN;
    renderizarRectangulo(v.renderer,MARRON1,margenVentana,margenVentana,v.anchoVentana-2*margenVentana,v.altoVentana-2*margenVentana);

    char nombre[11] = "";
    int cantCaracteres = 0;
    bool fin = false;
    SDL_Color color = {255,255,255,255};
    TTF_Font *fuente, *fuenteTitulo, *fuenteFooter;
    if(inicializarFuente(&fuenteTitulo,"fnt/MinecraftTen-VGORe.ttf",25) != COD_OK) return ERR_SDL;
    if(inicializarFuente(&fuente,"fnt/mineTexto.TTF",30) != COD_OK) return ERR_SDL;
    if(inicializarFuente(&fuenteFooter,"fnt/MinecraftTen-VGORe.ttf",10) != COD_OK) return ERR_SDL;

    if(renderizarTexto(margenVentana,margenVentana*0.3,v.renderer, margenVentana, v.anchoVentana-2*margenVentana,&fuenteTitulo,"INGRESA TU NOMBRE",color) != COD_OK)
        return ERR_SDL;
    if(renderizarTexto(margenVentana,v.altoVentana - margenVentana*0.5,v.renderer, margenVentana, v.anchoVentana-2*margenVentana,&fuenteFooter,"Presiona ENTER para continuar...",color) != COD_OK)
        return ERR_SDL;
    SDL_RenderPresent(v.renderer);
    SDL_Event e;
    SDL_StartTextInput();
    while(SDL_WaitEvent(&e) && !fin)
    {
        if(e.type == SDL_QUIT)
            return SALIDA;

        if(e.type == SDL_TEXTINPUT && cantCaracteres<10)
        {
            nombre[cantCaracteres] = e.text.text[0];
            cantCaracteres++;
        }

        if(e.type == SDL_KEYDOWN)
        {
            if(e.key.keysym.sym == SDLK_BACKSPACE && cantCaracteres>0)
            {
                cantCaracteres--;
                nombre[cantCaracteres] = '\0';
            }
            if(e.key.keysym.sym == SDLK_RETURN && cantCaracteres < 10 && cantCaracteres>0)
            {
                nombre[cantCaracteres] = '\0';
                fin = true;
            }
        }
        renderizarRectangulo(v.renderer,MARRON1,margenVentana,margenVentana,v.anchoVentana-2*margenVentana,v.altoVentana-2*margenVentana);
        if(cantCaracteres>0)
        {
            if(renderizarTexto(margenVentana,margenVentana*1.3,v.renderer, margenVentana, v.anchoVentana-2*margenVentana,&fuente,nombre,color) != COD_OK)
                return ERR_SDL;
        }
        SDL_RenderPresent(v.renderer);
    }
    SDL_StopTextInput();


    strcpy(str, nombre);

    TTF_CloseFont(fuenteTitulo);
    TTF_CloseFont(fuente);
    TTF_CloseFont(fuenteFooter);
    SDL_DestroyRenderer(v.renderer);
    SDL_DestroyWindow(v.window);

    return COD_OK;
}

Tablero* tableroCrear(char nombreJugador[11])
{
    // Decicidimos crear el tablero dentro de una funcion para mantener el TDA.
    Tablero* t = malloc(sizeof(Tablero));
    if(!t) return NULL;

    int orden, minas;

    if(leerDatosJuego(&orden, &minas)!= COD_OK)
    {
        free(t);
        return NULL;
    }

    if(tableroInicializar(t,orden,minas, nombreJugador) != COD_OK)
    {
        free(t);
        return NULL;
    }

    return t;
}


int leerDatosJuego(int *orden, int* minas)
{
    //Apertura de archivo
    FILE* archJuego = fopen("buscaminas.conf","rt");
    if(!archJuego)
    {
        *orden = ORDENDEFAULT;
        *minas = MINASDEFAULT;
        return COD_OK;
    }

    //Lectura de archivo
    char lineas[2][150];

    for(int i=0; i<2; i++)
    {
        if(!fgets(lineas[i], sizeof(lineas[i]), archJuego))
        {
            puts("Hubo un error al intentar leer el archivo buscaminas.conf...");

            fclose(archJuego);

            return ERR_ARCH;
        }
    }

    fclose(archJuego);

    int numArchivo, cantVariablesLeidas, minasInterpretadas;

    char charArchivo, error[MAX_ERROR_LEN];
    ;

    //Lectura del tamanio del tablero
    cantVariablesLeidas = sscanf(lineas[0],"tam_tablero=%d",&numArchivo);

    if(cantVariablesLeidas == 0) return ERR_ARCH;

    if(validarOrdenLeido(numArchivo, error) < 0) return ERR_ARCH;

    *orden = numArchivo;

    cantVariablesLeidas = sscanf(lineas[1],"cantidad_minas=%d%c",&numArchivo, &charArchivo);

    minasInterpretadas = validarMinasLeidas((*orden) * (*orden), cantVariablesLeidas, numArchivo, charArchivo, error);

    if(minasInterpretadas < 0) return ERR_ARCH;

    *minas = minasInterpretadas;

    return COD_OK;
}


int validarOrdenLeido(int orden, char *error)
{
    if(orden < MIN_ORDEN || orden > MAX_ORDEN)
    {
        snprintf(error, MAX_ERROR_LEN,
                 "El orden debe estar entre %d y %d", MIN_ORDEN, MAX_ORDEN);
        return ERR_ARCH;
    }
    return COD_OK;
}


int validarMinasLeidas(int cantidadCeldas, int variablesLeidas, int minasLeidas, char caracterLeido, char* error)
{
    int limSuperiorMinas = cantidadCeldas / 3;
    int limInferiorMinas = 1;

    // Validaciones para cantidad_minas=numero (CON porcentaje)
    if(variablesLeidas == 2)
    {
        int minasSegunPorcentaje = cantidadCeldas * minasLeidas / 100;

        /// Casos fracaso
        if(caracterLeido != '%')
        {
            strcpy(error, "Para establecer el porcentaje de minas, escriba '%' seguido del valor.");
            return ERR_ARCH;
        }

        if(!(minasSegunPorcentaje >= limInferiorMinas && minasSegunPorcentaje <= limSuperiorMinas))
        {
            snprintf(error, MAX_ERROR_LEN,
                     "La cantidad de minas debe estar entre %d y %d (tercio del tablero)",
                     limInferiorMinas, limSuperiorMinas);
            return ERR_ARCH;
        }



        return minasSegunPorcentaje;
    }

    // Validaciones para cantidad_minas=numero (SIN porcentaje)
    if (variablesLeidas == 1)
    {
        /// Caso fracaso
        if (minasLeidas < 1 || minasLeidas > limSuperiorMinas)
        {
            snprintf(error, MAX_ERROR_LEN,
                     "La cantidad de minas debe ser entre 0 y %d (tercio del tablero)", limSuperiorMinas);
            return ERR_ARCH;
        }

        /// Caso exito
        return minasLeidas;
    }

    if (variablesLeidas == 0)
    {
        snprintf(error, MAX_ERROR_LEN,
                 "La misma debe indicarse como 'cantidad_minas=numero', con numero estando entre 1 y %d", limSuperiorMinas);
        return ERR_ARCH;
    }

    return COD_OK;
}


int tableroInicializar(Tablero* t, int orden, int minas, char nombreJugador[11])
{
    t->orden = orden;
    t->minas_totales = minas;
    t->celdas_cubiertas = orden * orden;
    t->banderas_puestas = 0;
    t->jugador = jugadorInicializar(nombreJugador);
    Celda** celdasAux = matrizCrear(t->orden);
    if(!celdasAux) return ERR_MEM;
    t->celdas = celdasAux;
    matrizInicializar(t->celdas, t->orden);

    return COD_OK;
}


Celda** matrizCrear(int orden)
{

    Celda** celdas = malloc(orden * sizeof(Celda*));
    if(!celdas) return NULL;

    // Asignacion de memoria
    for (int i = 0; i < orden; i++)
    {
        celdas[i] = malloc(orden * sizeof(Celda));
        if(!celdas[i])
        {
            for(int j = 0; j < i; j ++)
            {
                free(celdas[j]);
            }
            free(celdas);
            return NULL;
        }
    }

    // Retorno de la direccion
    return celdas;
}


void matrizInicializar(Celda **celdas, int orden)
{
    for(int i = 0; i < orden ; i++)
    {
        for (int j = 0; j < orden; j++)
        {
            celdas[i][j].tiene_mina = false;
            celdas[i][j].revelada = false;
            celdas[i][j].bandera = false;
            celdas[i][j].minas_alrededor = INCOGNITA;
            memcpy(celdas[i][j].dibujo_asignado,celdaCubierta,sizeof(celdaCubierta));
        }
    }
}

Jugador jugadorInicializar(char nombreJugador[11])
{
    Jugador jugador;
    jugador.cant_clicks = 0;
    jugador.gano = false;
    jugador.tiempo_juego = 0;
    jugador.inicio_partida = 0;
    strcpy(jugador.nombre, nombreJugador);
    return jugador;
}

Ventana* ventanaCrear(Vector* vector)
{
    /// Asignar memoria
    Tablero *tablero = obtenerTableroActual(vector);
    Ventana* v = malloc(sizeof(Ventana));
    if(!v) return NULL;

    ventanaCalcularDimension(v,tablero);

    if(ventanaInicializarSDL(v) != COD_OK)
    {
        free(v);
        return NULL;
    }

    return v;
}


void ventanaCalcularDimension(Ventana* ventana, const Tablero* tablero)
{
    ventana->altoVentana = 2*ALTO_INTERFAZ + tablero->orden * TAM_CELDA + 4 * MARGEN;

    ventana->anchoVentana = tablero->orden * TAM_CELDA + 2 * MARGEN;
}


int ventanaInicializarSDL(Ventana* ventana)
{

    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_Log("SDL no pudo inicializarse! SDL_Error: %s\n", SDL_GetError());
        return ERR_SDL;
    }

    // Crear la ventana
    ventana->window = SDL_CreateWindow("Buscaminas", // Título
                                       SDL_WINDOWPOS_CENTERED, // Posición X
                                       SDL_WINDOWPOS_CENTERED, // Posición Y
                                       ventana->anchoVentana,                     // Ancho en píxeles
                                       ventana->altoVentana,                     // Alto en píxeles
                                       SDL_WINDOW_SHOWN); // Banderas: visible y redimensionable

    if (ventana->window == NULL)
    {
        SDL_Log("La ventana no pudo crearse! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return ERR_SDL;
    }

    // Crear renderer
    ventana->renderer = SDL_CreateRenderer(ventana->window,
                                           -1,
                                           SDL_RENDERER_ACCELERATED);

    if (ventana->renderer == NULL)
    {
        SDL_Log("El renderer no pudo crearse! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(ventana->window);
        SDL_Quit();
        return ERR_SDL;
    }
    SDL_SetRenderDrawColor(ventana->renderer, 68, 42, 26,255);//CAMBIO EL FONDO
    SDL_RenderClear(ventana->renderer);

    return COD_OK;
}


void tableroDibujar(Vector *vector, Ventana* ventana,Boton * ui, const int estado)
{
    Tablero *tablero = obtenerTableroActual(vector);
    renderizarCeldas(ventana->renderer, tablero);
    renderizarGrilla(ventana->renderer, tablero);
    renderizarInterfaz(ventana, estado, tablero, ui, vector->indice, vector->ce);
    //Aplica cambios sobre el renderer
    SDL_RenderPresent(ventana->renderer);
}


void renderizarCeldas(SDL_Renderer* renderer, const Tablero* tablero)
{
    int orden = tablero->orden;
    int dibujo[7][7];
    for (int fila = 0; fila < orden; fila++)
    {
        for (int col = 0; col < orden; col++)
        {
            int offsetX = MARGEN + col * TAM_CELDA;
            int offsetY = 2*MARGEN + fila * TAM_CELDA + ALTO_INTERFAZ;

            //Se le asigna el dibujo a la celda
            memcpy(dibujo,tablero->celdas[fila][col].dibujo_asignado,sizeof(dibujo));

            //Pinta cada pixel de la celda del tablero
            for (int y = 0; y < PIXELES_X_LADO; y++)
            {
                for (int x = 0; x < PIXELES_X_LADO; x++)
                {
                    int color_id = dibujo[y][x];


                    //Establece el color del "pincel"
                    SDL_SetRenderDrawColor(renderer,
                                           colores[color_id].r,
                                           colores[color_id].g,
                                           colores[color_id].b,
                                           255);

                    //Define en qué parte de la pantalla se va a "pintar"
                    SDL_Rect pixel =
                    {
                        offsetX + x * TAM_PIXEL,
                        offsetY + y * TAM_PIXEL,
                        TAM_PIXEL,
                        TAM_PIXEL
                    };

                    //Pinta, con el color y la ubicacion definidos, el pixel
                    SDL_RenderFillRect(renderer, &pixel);

                }
            }
        }
    }
}


void renderizarGrilla(SDL_Renderer* renderer, const Tablero* tablero)
{
    int orden = tablero->orden;
    SDL_SetRenderDrawColor(renderer,0, 0, 0,255); // Marron o negro? a decidir

    for (int i = 0; i <= orden; i++)
    {
        int y = i * TAM_CELDA + ALTO_INTERFAZ + 2*MARGEN;
        SDL_RenderDrawLine(renderer, MARGEN, y, MARGEN + orden * TAM_CELDA, y);
        SDL_RenderPresent(renderer);

    }
    for (int j = 0; j <= orden; j++)
    {
        int x = MARGEN + j * TAM_CELDA;
        SDL_RenderDrawLine(renderer, x, 2*MARGEN + ALTO_INTERFAZ, x, 2*MARGEN + ALTO_INTERFAZ + orden * TAM_CELDA);
        SDL_RenderPresent(renderer);

    }
}


void renderizarInterfaz(Ventana *ventana,const int estado, const Tablero * tablero, Boton * btn, int indice, int ce)
{
    // Zona Interfaz superior:HOJAS
    int orden=tablero->orden;
    for (int fila = 0; fila < 2; fila++)   // 2 filas fijas porque el alto de la interfaz es igual a 2 celdas del tablero de 28px
    {
        for (int col = 0; col < orden; col++)   // tantas columnas como orden del tablero
        {
            for (int y = 0; y < 7; y++)
            {
                for (int x = 0; x < 7; x++)
                {
                    int color_id = HojasInterfaz[y][x]; //dejo la matriz fija sin guardar en otra matriz ya que es siempre el mismo diseño

                    SDL_SetRenderDrawColor(ventana->renderer,
                                           colores[color_id].r,
                                           colores[color_id].g,
                                           colores[color_id].b,
                                           255);

                    SDL_Rect pixel =
                    {
                        MARGEN + col * 28 + x * 4,
                        MARGEN + fila * 28 + y * 4,
                        TAM_PIXEL, TAM_PIXEL
                    };

                    SDL_RenderFillRect(ventana->renderer, &pixel);
                }
            }
        }
        ///dependiendo el estado cambio la cara:
        ///JUGANDO=ALDEANO
        ///GANANDO=STEVE
        ///PERDIENDO=CREEPER
        switch(estado)
        {
        case -1:
            dibujarCara(ventana->renderer,caraPerdedor,ventana->anchoVentana, btn);
            break;
        case 1:
            dibujarCara(ventana->renderer,caraGanador,ventana->anchoVentana, btn);
            break;
        default:
            dibujarCara(ventana->renderer,caraJugando,ventana->anchoVentana, btn);
            break;
        }
    }
    mostrarContadorMinas(tablero, ventana->renderer);
    if(estado==JUGANDO)
    {
        dibujarBotonGuardado(ventana, btn);
        renderizarUIinferior(ventana, btn, indice, ce);
    }

}


void dibujarCara(SDL_Renderer * renderer,const int dibujo[][8],const int anchoVentana,Boton * btn)
{
    int posInitX=(anchoVentana / 2 - 15)+TAM_PIXEL;
    int posInitY=(MARGEN+ALTO_INTERFAZ/ 2 -15)+TAM_PIXEL;
    SDL_Rect cara= {posInitX,posInitY,PIXELES_X_LADO_CARAS*TAM_PIXEL,PIXELES_X_LADO_CARAS*TAM_PIXEL};
    btn->reiniciar = cara;
    for (int y = 0; y < PIXELES_X_LADO_CARAS; y++)
    {
        for (int x = 0; x < PIXELES_X_LADO_CARAS; x++)
        {
            int color_id = dibujo[y][x];

            SDL_SetRenderDrawColor(renderer,
                                   colores[color_id].r,
                                   colores[color_id].g,
                                   colores[color_id].b,
                                   255);


            SDL_Rect pixel =
            {
                (anchoVentana / 2 - 15) + x * TAM_PIXEL,///SELECCIONO EL CENTRO RELATIVO EN BASE AL ANCHO DE LA INTERFAZ
                (MARGEN+ALTO_INTERFAZ/ 2 -15) + y * TAM_PIXEL,///SELECCIONO EL CENTRO ABSOLUTO EN BASE AL ALTO DE LA INTERFAZ
                TAM_PIXEL,
                TAM_PIXEL
            };

            //Pinta, con el color y la ubicacion definidos, el pixel
            SDL_RenderFillRect(renderer, &pixel);

        }
    }
}


///Funcion con SDL_ttf
void mostrarContadorMinas(const Tablero* tablero,SDL_Renderer *renderer)
{
    if (TTF_Init() == -1)
    {
        printf("Error al iniciar SDL_ttf: %s\n", TTF_GetError());
        return;
    }

    TTF_Font* fuente = TTF_OpenFont("fnt/DS-DIGI.TTF", 48);
    if (!fuente)
    {
        printf("No se pudo cargar la fuente: %s\n", TTF_GetError());
        return;
    }

    SDL_Color colorRojo = {255, 0, 0, 255};

    int contador = tablero->minas_totales - tablero->banderas_puestas;

    char texto[5];

    snprintf(texto, sizeof(texto), "%03d", contador);

    SDL_Surface* superficieTexto = TTF_RenderText_Solid(fuente, texto, colorRojo);
    if (!superficieTexto)
    {
        printf("No se pudo renderizar el texto: %s\n", TTF_GetError());
        TTF_CloseFont(fuente);
        return;
    }

    SDL_Texture* texturaTexto = SDL_CreateTextureFromSurface(renderer, superficieTexto);
    if (!texturaTexto)
    {
        printf("No se pudo crear textura: %s\n", SDL_GetError());
        SDL_FreeSurface(superficieTexto);
        TTF_CloseFont(fuente);
        return;
    }

    SDL_Rect destino = {20, 10, superficieTexto->w, superficieTexto->h};


    SDL_RenderCopy(renderer, texturaTexto, NULL, &destino);

    ///CIERRES
    SDL_DestroyTexture(texturaTexto);
    SDL_FreeSurface(superficieTexto);
    TTF_CloseFont(fuente);
}

int renderizarUIinferior(Ventana *ventana,Boton * btn, int indice, int ce)
{



    if(cargarImagen(&btn->agregar,
                    ventana->anchoVentana/2-10*TAM_PIXEL, ventana->altoVentana-ALTO_INTERFAZ,
                    10*TAM_PIXEL, 10*TAM_PIXEL,
                    ventana->renderer, &btn->texturaAgregar, "img/Filas_Agregar.png")
            != COD_OK) return ERR_SDL;

        ///dibujar un boton y guardarlo en btn

//    if(cargarImagen(&btn->restar,ventana->anchoVentana/2+5*TAM_PIXEL,ventana->altoVentana-ALTO_INTERFAZ,10*TAM_PIXEL,10*TAM_PIXEL,
//                    ventana->renderer,&btn->texturaRestar,"img/Resta_bm.png") != COD_OK)return ERR_SDL;///

    if(indice>0)
    {
        if(cargarImagen(&btn->atras,
                        MARGEN, ventana->altoVentana-ALTO_INTERFAZ,
                        10*TAM_PIXEL, 10*TAM_PIXEL,
                        ventana->renderer, &btn->texturaAtras, "img/undo.png")
                != COD_OK) return ERR_SDL;
    }
    else
    {
        if(cargarImagen(&btn->atras,
                        MARGEN, ventana->altoVentana-ALTO_INTERFAZ,
                        10*TAM_PIXEL, 10*TAM_PIXEL,
                        ventana->renderer, &btn->texturaAtras, "img/undoGriseado.png")
                != COD_OK) return ERR_SDL;
    }
    if(indice < ce-1)
    {
        if(cargarImagen(&btn->adelante,
                        ventana->anchoVentana-MARGEN-10*TAM_PIXEL, ventana->altoVentana-ALTO_INTERFAZ,
                        10*TAM_PIXEL, 10*TAM_PIXEL,
                        ventana->renderer, &btn->texturaAdelante, "img/redo.png")
                != COD_OK) return ERR_SDL;
    }
    else
    {
        if(cargarImagen(&btn->adelante,
                        ventana->anchoVentana-MARGEN-10*TAM_PIXEL, ventana->altoVentana-ALTO_INTERFAZ,
                        10*TAM_PIXEL, 10*TAM_PIXEL,
                        ventana->renderer, &btn->texturaAdelante, "img/redoGriseado.png")
                != COD_OK) return ERR_SDL;
    }



    return COD_OK;
}

int cargarImagen(SDL_Rect *rect, int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture **textura,char *rutaImg)
{
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    SDL_Surface* surface = IMG_Load(rutaImg);
    if (!surface)
    {
        printf("Error al cargar la imagen: %s\n", IMG_GetError());
        return ERR_SDL;
    }
    *textura = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!*textura)
    {
        printf("Error al crear textura: %s\n", SDL_GetError());
        return ERR_SDL;
    }

    SDL_Rect borde =
    {
        rect->x - 2,
        rect->y - 2,
        rect->w + 4,
        rect->h + 4
    };

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Negro
    SDL_RenderFillRect(renderer, &borde);
    SDL_RenderCopy(renderer, *textura, NULL, rect);
    return COD_OK;
}

int buscaminasJugar(Vector *vector, Ventana **ventana, Boton * ui, Click *click, int accion, bool *reinicio, int *ending)
{
    do
    {
        if (procesarAccion(accion, reinicio, vector, ventana, ui, click) != COD_OK)
            return ERR_SDL;
        tableroDibujar(vector,*ventana,ui,JUGANDO);
        if(!GameOver(vector, click, ending, accion))
            accion = clickIngresar(click,*ventana, vector,ui, JUGANDO);
    }
    while(!(*ending));

    if(*ending == COD_DERROTA)
    {
        Tablero *tablero = obtenerTableroActual(vector);
        despejarMinas(tablero);
        tableroDibujar(vector,*ventana,ui,PERDIENDO);
        accion = clickIngresar(click,*ventana, vector,ui, PERDIENDO);
        if(accion == ATRAS)
        {
            *ending = 0;
            if(buscaminasJugar(vector, ventana, ui, click, accion, reinicio, ending) != COD_OK)
                return ERR_SDL;
        }
    }

    return COD_OK;
}

int clickIngresar(Click * click,Ventana * ventana, Vector * vector,Boton * btn, int estado)
{
    Tablero *tablero = obtenerTableroActual(vector);
    SDL_Event evento;

    while(SDL_WaitEvent(&evento))
    {
        if (evento.type == SDL_QUIT) return SALIDA;
        if (evento.type == SDL_MOUSEBUTTONDOWN)
        {
            tablero->jugador.cant_clicks++;
            if(clickEnTablero(&evento, ventana))
            {
                if (evento.button.button == SDL_BUTTON_LEFT)
                {
                    click->columna = (evento.button.x - MARGEN) / TAM_CELDA;
                    click->fila = (evento.button.y - ALTO_INTERFAZ - 2 * MARGEN) / TAM_CELDA;

                    if(evento.button.clicks==2){
                        Celda celdaAux=tablero->celdas[click->fila][click->columna];
                        if(celdaAux.revelada && despejarDobleClick(tablero,click,celdaAux.minas_alrededor))
                            revelarAdyacentes(tablero,click);

                    }

                    return CLICK_IZQUIERDO;
                }

                if (evento.button.button == SDL_BUTTON_RIGHT)
                {
                    click->columna = (evento.button.x - MARGEN) / TAM_CELDA;
                    click->fila = (evento.button.y - ALTO_INTERFAZ - 2 * MARGEN) / TAM_CELDA;
                    return CLICK_DERECHO;
                }
            }
            if(estado==JUGANDO && clickPartida(&evento,btn->reiniciar))
                return REINICIO;

            if(estado == JUGANDO && clickPartida(&evento,btn->guardar))
                return GRABAR;

            if(estado == JUGANDO && clickPartida(&evento,btn->agregar))
            {
                return AGREGAR;
            }

            if(clickPartida(&evento,btn->atras))
                return ATRAS;
            if(clickPartida(&evento,btn->adelante))
                return ADELANTE;

            if(estado == JUGANDO && clickPartida(&evento, btn->restar))
                return RESTAR;

        }
        if(estado == JUGANDO && (evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_c))
            return CHEAT;
        if(estado == JUGANDO && (evento.type == SDL_KEYDOWN && evento.key.keysym.sym == SDLK_g))
            return GRABAR;
    }
    return ERR_SDL; ///CASO RARO
}

bool despejarDobleClick(Tablero * tablero,Click * click, int minas){
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};
    int i,j,banderas=0;

    for(int k =0;k<8;k++){
        i=click->fila+dx[k];
        j=click->columna+dy[k];
        if(i >= 0 && i< tablero->orden && j>= 0 && j< tablero->orden)
        {
            Celda *celda = &tablero->celdas[i][j];
            if(celda->bandera)banderas++;
        }
    }
    if(banderas==minas){
        for(int k =0;k<8;k++){
            i=click->fila+dx[k];
            j=click->columna+dy[k];
            if(i >= 0 && i< tablero->orden && j>= 0 && j< tablero->orden)
            {
                Celda *celda = &tablero->celdas[i][j];
                if(celda->tiene_mina && !celda->bandera){
                    click->fila=i;
                    click->columna=j;
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}


Tablero *leerPartida()
{
    Tablero *tablero;
    /// cargamos la partida, leemos binario
    FILE* arch = fopen("partida_anterior.dat","rb");
    if(!arch)
    {
        fclose(arch);
        return NULL;
    }
    tablero = malloc(sizeof(Tablero));
    if(!tablero)
    {
        fclose(arch);
        return NULL;
    }
    Partida partida;
    fread(&partida, sizeof(Partida),1,arch);
    tablero->banderas_puestas = partida.banderas_puestas;
    tablero->celdas_cubiertas = partida.celdas_cubiertas;
    tablero->minas_totales = partida.minas_totales;
    tablero->orden = partida.orden;
    tablero->jugador = partida.jugador;
    tablero->jugador.inicio_partida = time(NULL);

    Celda** matriz = matrizCrear(tablero->orden);
    if(!matriz)
    {
        fclose(arch);
        return NULL;
    }

    for (int i = 0; i < tablero->orden; i++)
    {
        for(int j = 0; j < tablero->orden; j++)
        {
            fread(*(matriz + i)+j,sizeof(Celda),1,arch);
        }
    }

    tablero->celdas = matriz;
    fclose(arch);
    return tablero;
}

int procesarAccion(int accion, bool *reinicio, Vector *vector,Ventana **ventana,Boton * ui, Click *click)
{
    Tablero *tablero = obtenerTableroActual(vector);
    if(accion == SALIDA) return FIN_EJECUCION;

    if((accion == CLICK_DERECHO || accion == CLICK_IZQUIERDO || accion == REINICIO || accion==RESTAR) && !tablero->celdas[click->fila][click->columna].revelada)
    {
        if(vector->indice < vector->ce - 1)
            vector->ce = vector->indice+1;

        if(vector->ce > vector->cap * FACT_CAP_MIN)
        {
            if(vectorRedimensionar(vector, vector->cap * (1+FACT_CAP_INCR)) != COD_OK)
                return ERR_MEM;
        }
        Tablero *copia = tableroCopiar(tablero);
        if(!copia) return ERR_MEM;
        memcpy(vector->vec + vector->ce * vector->tamElem, copia, sizeof(Tablero));
        free(copia);
        vector->ce++;
        vector->indice++;
        tablero = obtenerTableroActual(vector);
    }

    if(*reinicio==true)
    {
        while(accion != CLICK_IZQUIERDO)
        {
            if(accion == SALIDA) return FIN_EJECUCION;
            if(accion == CLICK_DERECHO)
            {
                celdaAsignarDibujo(tablero, click);
                tableroDibujar(vector,*ventana,ui,JUGANDO);
            }
            accion = clickIngresar(click,*ventana, vector,ui, PRIMERINGRESO);
        }

        tableroColocarMinas(tablero, click);
        celdaRevelar(tablero, click);
        celdaAsignarDibujo(tablero, click);
        guardarLog("Inicio de juego", "Izquierdo", click);
        *reinicio=false;
    }

    if(accion == GRABAR)
        if (partidaGrabar(tablero) != COD_OK)
            return ERR_ARCH;

    if(accion == CLICK_DERECHO)
    {
        if(!tablero->celdas[click->fila][click->columna].revelada)
        {
            if (!tablero->celdas[click->fila][click->columna].bandera)
                // Si NO tenía bandera, la estamos poniendo
                tablero->banderas_puestas++;
            else
                // Si ya tenía bandera, la estamos quitando
                tablero->banderas_puestas--;

            tablero->celdas[click->fila][click->columna].bandera = !tablero->celdas[click->fila][click->columna].bandera;
        }
        guardarLog("Click","Derecho", click);
        celdaAsignarDibujo(tablero, click);
    }

    if(accion == CLICK_IZQUIERDO)
    {
        guardarLog("Click","Izquierdo", click);
        celdaRevelar(tablero, click);
        celdaAsignarDibujo(tablero, click);
    }

    if(accion==REINICIO)
    {
        char nombreJugador[11];
        int i = vector->indice;
        strcpy(nombreJugador,tablero->jugador.nombre);
        memcpy(vector->vec + i * vector->tamElem, tableroReiniciar(tablero), sizeof(Tablero));
        if((vector->vec + i * vector->tamElem) == NULL)return ERR_MEM;
        ((Tablero*)(vector->vec + i * vector->tamElem))->jugador.inicio_partida = time(NULL);
        tableroDibujar(vector,*ventana,ui,JUGANDO);
        *reinicio=true;
    }

    if(accion==CHEAT)
    {
        despejarMinas(tablero);
        tableroDibujar(vector,*ventana,ui,JUGANDO);
        SDL_Delay(1000);
        SDL_PumpEvents();
        SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
        taparMinas(tablero);
        tableroDibujar(vector,*ventana,ui,JUGANDO);
    }

    if(accion==ATRAS && vector->indice > 0)
    {
        Tablero *tableroAnterior = obtenerTableroActual(vector);
        int ordenAnterior = tableroAnterior->orden;

        vectorDecrementarIndice(vector);
        Tablero *tableroNuevo = obtenerTableroActual(vector);
        int ordenNuevo = tableroNuevo->orden;

        if(ordenAnterior != ordenNuevo)
        {
            ventanaDestruir(*ventana, ui);
            *ventana = ventanaCrear(vector);
        }

        tableroDibujar(vector, *ventana, ui, JUGANDO);
    }

    if(accion==ADELANTE && vector->indice < vector->ce -1)
    {
        Tablero *tableroAnterior = obtenerTableroActual(vector);
        int ordenAnterior = tableroAnterior->orden;

        vectorIncrementarIndice(vector);
        Tablero *tableroNuevo = obtenerTableroActual(vector);
        int ordenNuevo = tableroNuevo->orden;

        if(ordenAnterior != ordenNuevo)
        {
            ventanaDestruir(*ventana, ui);
            *ventana = ventanaCrear(vector);
        }

        tableroDibujar(vector, *ventana, ui, JUGANDO);
    }

    if(accion==AGREGAR && tablero->orden < 31)
    {
        if(agregarTablero(tablero,*ventana)!= COD_OK) return ERR_MEM;
        ventanaDestruir(*ventana,ui);
        *ventana=ventanaCrear(vector);
        tableroDibujar(vector,*ventana,ui,JUGANDO);
    }

    if(accion == RESTAR && tablero->orden > 8)
    {
        if(reducirTablero(&vector, ventana,ui) != COD_OK) return ERR_MEM;

        ventanaDestruir(*ventana, ui);
        *ventana = ventanaCrear(vector);      /* mismo refresh de ventana */
        tableroDibujar(vector, *ventana, ui, JUGANDO);
    }

    return COD_OK;
}

int partidaGrabar(Tablero *tablero)
{
    FILE* arch = fopen("partida_anterior.dat","wb");
    if(!arch)
    {
        fclose(arch);
        return ERR_ARCH;
    }
    tablero->jugador.tiempo_juego = time(NULL) - tablero->jugador.inicio_partida;
    Partida partida;
    partida.banderas_puestas = tablero->banderas_puestas;
    partida.celdas_cubiertas = tablero->celdas_cubiertas;
    partida.minas_totales = tablero->minas_totales;
    partida.orden = tablero->orden;
    partida.jugador = tablero->jugador;
    /// Traspaso de contenido, dejando fuera el puntero a Celda.
    fwrite(&partida,sizeof(Partida),1,arch);
    for(int i = 0; i < tablero->orden; i++)
        fwrite(tablero->celdas[i], sizeof(Celda), tablero->orden, arch);

    fclose(arch);

    return COD_OK;
}

int clickEnTablero(SDL_Event * evento, Ventana * ventana)
{
    return ((evento->button.x >= MARGEN && evento->button.x < ventana->anchoVentana - MARGEN) &&
            (evento->button.y < ventana->altoVentana - 2*MARGEN-ALTO_INTERFAZ && evento->button.y >= 2*MARGEN + ALTO_INTERFAZ));
}


void tableroColocarMinas(Tablero* tablero, Click *click)
{
    srand(time(NULL)); // Semilla para random
    int f;
    int c;

    for(int minasColocadas = 0;  minasColocadas < tablero->minas_totales; minasColocadas++)
    {
        do
        {
            f = rand() % tablero->orden;
            c = rand() % tablero->orden;
        }
        while(esPosicionInvalida(tablero,click,f,c));

        tablero->celdas[f][c].tiene_mina = true;
    }
}

Tablero *tableroReiniciar(Tablero *tablero)
{
    Tablero *tableroAux = malloc(sizeof(Tablero));
    tableroInicializar(tableroAux, tablero->orden, tablero->minas_totales, tablero->jugador.nombre);
    return tableroAux;
}

bool esPosicionInvalida(const Tablero* tablero, const Click* click, int f, int c)
{
    return (click->fila >= f - 1 && click->fila <= f + 1 && click->columna >= c - 1 && click->columna <= c + 1)|| tablero->celdas[f][c].tiene_mina;
}


void celdaRevelar(Tablero* tablero, Click *click)
{
    Celda *celda = &tablero->celdas[click->fila][click->columna];
    if(!celda->revelada && !celda->bandera && !celda->tiene_mina)  // La segunda condición debería evaluarse luego de ingresar un click
    {
        tablero->celdas_cubiertas --;
        celda->minas_alrededor = calcularMinasAdyacentes(tablero,click);
        celda->revelada = true;
        if(celda->minas_alrededor == 0)
        {
            revelarAdyacentes(tablero, click);
        }
    }
}

void revelarAdyacentes(Tablero* tablero, Click *click)
{
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};
    Click clickCorrelativo;

    for (int k = 0; k < 8; k++)
    {
        clickCorrelativo.fila = click->fila + dx[k];
        clickCorrelativo.columna = click->columna + dy[k];

        // Verificar que las coordenadas estén dentro del tablero
        if(clickCorrelativo.fila >= 0 && clickCorrelativo.fila < tablero->orden
                && clickCorrelativo.columna >= 0 && clickCorrelativo.columna < tablero->orden)
        {
            Celda *celda = &tablero->celdas[clickCorrelativo.fila][clickCorrelativo.columna];

            // Revelar solo si no está revelada y no tiene bandera
            if(!celda->revelada && !celda->bandera)
            {
                celdaRevelar(tablero, &clickCorrelativo);
                celdaAsignarDibujo(tablero, &clickCorrelativo);
            }
        }
    }
}

int calcularMinasAdyacentes(const Tablero* tablero, Click* click)
{

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};

    int contador = 0;

    Celda* celda;
    Click clickCorrelativo;

    for(int i = 0; i < 8; i++)
    {

        clickCorrelativo.fila = click->fila + dx[i];
        clickCorrelativo.columna = click->columna + dy[i];

        if(clickCorrelativo.fila >= 0 && clickCorrelativo.fila < tablero->orden
                && clickCorrelativo.columna >= 0 && clickCorrelativo.columna < tablero->orden)
        {

            celda = &tablero->celdas[clickCorrelativo.fila][clickCorrelativo.columna];

            if(!celda->revelada && celda->tiene_mina) contador ++;
        }
    }

    return contador;
}


void celdaAsignarDibujo(Tablero* tablero, Click *click)
{
    Celda *celda = &tablero->celdas[click->fila][click->columna];
    switch(celda->minas_alrededor)
    {
    case 0:
        memcpy(celda->dibujo_asignado,celdaDescubierta,sizeof(celda->dibujo_asignado));
        break;
    case 1:
        memcpy(celda->dibujo_asignado,Uno,sizeof(celda->dibujo_asignado));
        break;
    case 2:
        memcpy(celda->dibujo_asignado,Dos,sizeof(celda->dibujo_asignado));
        break;
    case 3:
        memcpy(celda->dibujo_asignado,Tres,sizeof(celda->dibujo_asignado));
        break;
    case 4:
        memcpy(celda->dibujo_asignado,Cuatro,sizeof(celda->dibujo_asignado));
        break;
    case 5:
        memcpy(celda->dibujo_asignado,Cinco,sizeof(celda->dibujo_asignado));
        break;
    case 6:
        memcpy(celda->dibujo_asignado,Seis,sizeof(celda->dibujo_asignado));
        break;
    case 7:
        memcpy(celda->dibujo_asignado,Siete,sizeof(celda->dibujo_asignado));
        break;
    case 8:
        memcpy(celda->dibujo_asignado,Ocho,sizeof(celda->dibujo_asignado));
        break;
    default:
        if(celda->revelada && celda->tiene_mina)
        {
            memcpy(celda->dibujo_asignado,MinaReventada,sizeof(celda->dibujo_asignado));
            break;
        }
        if(celda->bandera)
        {
            memcpy(celda->dibujo_asignado,Bandera,sizeof(celda->dibujo_asignado));
        }
        else
        {
            memcpy(celda->dibujo_asignado,celdaCubierta,sizeof(celda->dibujo_asignado));
        }
        break;
    }
}


void guardarLog(char *tipoLog, char *tipoClick, Click *click)
{
    time_t ahora;
    struct tm* punteroAhora;
    time(&ahora);
    punteroAhora = localtime (&ahora);
    printf("%-2d/%-2d/%-4d\t%2d:%2d:%2d  --- [%s] Click %-9s en posicion (%d;%d)\n",punteroAhora->tm_mday, punteroAhora->tm_mon + 1, punteroAhora->tm_year + 1900, punteroAhora->tm_hour, punteroAhora->tm_min, punteroAhora->tm_sec,tipoLog, tipoClick, click->fila+1, click->columna+1);

}


bool GameOver(Vector* vector, const Click *click, int* ending, int accion)
{
    Tablero *tablero = obtenerTableroActual(vector);
    if(accion!=CLICK_IZQUIERDO)
    {
        return false;
    }
    Celda* celda = &tablero->celdas[click->fila][click->columna];
    if((celda->tiene_mina || tablero->celdas_cubiertas == tablero->minas_totales)&& celda->bandera == false)
    {
        if(celda->tiene_mina == true)
        {
            *ending = COD_DERROTA;
        }
        else
        {
            *ending = COD_VICTORIA;
        }

        return true;
    }

    return false;
}

void procesarDerrota(Vector *vector, Ventana *ventana,Boton * ui)
{
    Tablero *tablero = obtenerTableroActual(vector);
    tablero->jugador.gano = false;
    tablero->jugador.tiempo_juego += time(NULL) - tablero->jugador.inicio_partida;
    despejarMinas(tablero);
    tableroDibujar(vector,ventana,ui,PERDIENDO);
}

void procesarVictoria(Vector *vector, Ventana *ventana,Boton * ui)
{
    Tablero *tablero = obtenerTableroActual(vector);
    tableroDibujar(vector,ventana,ui,GANANDO);
    SDL_Delay(500);
    tablero->jugador.gano = true;
    tablero->jugador.tiempo_juego += time(NULL) - tablero->jugador.inicio_partida;
}

int escribirEstadisticas(Vector *vector, Ventana *ventana)
{
    Tablero *tablero = obtenerTableroActual(vector);
    Jugador jugador = tablero->jugador;
    FILE *p;

    if(archivoEstaCreado(NOMBRE_ARCHIVO_ESTADISTICAS))
    {
        Jugador jugadores[10];
        p = fopen(NOMBRE_ARCHIVO_ESTADISTICAS, "r+t");
        if(p==NULL) return ERR_ARCH;
        int cantJugadores = cargarVectorJugadores(p, jugadores);
        jugadores[0] = jugador;
        rewind(p);
        escribirVectorJugadores(p, jugadores, cantJugadores);
        if(renderizarEstadisticas(ventana, tablero, jugadores, cantJugadores) != COD_OK) return ERR_SDL;
    }
    else
    {
        Jugador jugadores[1];
        jugadores[0] = jugador;
        p = fopen(NOMBRE_ARCHIVO_ESTADISTICAS, "wt");
        if(p==NULL) return ERR_ARCH;
        fprintf(p,"%s|%s|%d|%d", jugador.nombre, conversionBooleanoAResultado(jugador.gano),jugador.tiempo_juego, jugador.cant_clicks);
        if(renderizarEstadisticas(ventana, tablero, jugadores, 1) != COD_OK) return ERR_SDL;

    }
    fclose(p);

    return COD_OK;
}

bool archivoEstaCreado(char *nombreArch)
{
    FILE *p = fopen(nombreArch, "r");
    if(!p)
        return false;
    fclose(p);
    return true;
}

int cargarVectorJugadores(FILE *p, Jugador jugadores[10])
{
    char linea[101];
    char resultado[3];
    int i = 1;
    Jugador jugador;
    do
    {
        fgets(linea, sizeof(linea), p);
        sscanf(linea,"%[^|]|%[^|]|%d|%d", jugador.nombre, resultado,&jugador.tiempo_juego, &jugador.cant_clicks);
        jugador.gano = conversionResultadoABooleano(resultado);
        jugadores[i] = jugador;
        i++;
    }
    while(!feof(p) && i < 10);
    return i;
}

void escribirVectorJugadores(FILE *p, Jugador jugadores[10], int cantJugadores)
{
    fprintf(p,"%s|%s|%d|%d", jugadores[0].nombre, conversionBooleanoAResultado(jugadores[0].gano),jugadores[0].tiempo_juego, jugadores[0].cant_clicks);
    for(int i = 1; i < cantJugadores; i++)
        fprintf(p,"\n%s|%s|%d|%d", jugadores[i].nombre, conversionBooleanoAResultado(jugadores[i].gano),jugadores[i].tiempo_juego, jugadores[i].cant_clicks);

}

char *conversionBooleanoAResultado(bool gano)
{
    if(gano)
        return "SI";
    return "NO";
}

bool conversionResultadoABooleano(char* resultado)
{
    if(strcmp(resultado, "SI") == 0)
        return true;
    return false;
}

int renderizarEstadisticas(Ventana* ventana, Tablero *tablero, Jugador *jugadores, int cantJugadores)
{

    TTF_Font *fuenteTexto;
    int anchoTablero = ventana->anchoVentana - 2*MARGEN;
    int tamFuente = anchoTablero * (0.05);
    SDL_Color colorFuente = {255, 255, 255, 255};
    int anchoNombre = anchoTablero * 0.3;
    int anchoNumeros = anchoTablero * 0.22;
    int anchoResultado = anchoTablero * 0.26;

    renderizarRectangulo(ventana->renderer, MARRON1, MARGEN, 2*MARGEN + ALTO_INTERFAZ, ventana->anchoVentana-2*MARGEN,ventana->altoVentana-3*MARGEN-ALTO_INTERFAZ);

    if (TTF_Init() == -1)
    {
        printf("Error al iniciar SDL_ttf: %s\n", TTF_GetError());
        return ERR_SDL;
    }

    if (inicializarFuente(&fuenteTexto, "fnt/mineTexto.TTF", tamFuente) != COD_OK) return ERR_SDL;

    if(renderizarEncabezadoEstadistica(ventana->renderer, &fuenteTexto, colorFuente, tamFuente, anchoNombre,anchoNumeros,anchoResultado) != COD_OK) return ERR_SDL;
    for(int i = 0; i < cantJugadores; i++)
    {
        //NOMBRE
        if(renderizarTexto
                (MARGEN,
                 2*MARGEN+ALTO_INTERFAZ + (i + 1)*tamFuente + tamFuente,
                 ventana->renderer,
                 MARGEN,
                 anchoNombre,
                 &fuenteTexto,
                 jugadores[i].nombre,
                 colorFuente
                ) != COD_OK) return ERR_SDL;

        //RESULTADO
        if(renderizarTexto
                (MARGEN,
                 2*MARGEN+ALTO_INTERFAZ + (i + 1)*tamFuente + tamFuente,
                 ventana->renderer,
                 MARGEN + anchoNombre,
                 anchoResultado,
                 &fuenteTexto,
                 conversionBooleanoAResultado(jugadores[i].gano),
                 colorFuente
                ) != COD_OK) return ERR_SDL;

        char tiempo_juego[10];
        enteroAString(jugadores[i].tiempo_juego, tiempo_juego, sizeof(tiempo_juego));
        //TIEMPO DE JUEGO
        if(renderizarTexto
                (MARGEN,
                 2*MARGEN+ALTO_INTERFAZ + (i + 1)*tamFuente + tamFuente,
                 ventana->renderer,
                 MARGEN + anchoNombre + anchoResultado,
                 anchoNumeros,
                 &fuenteTexto,
                 tiempo_juego,
                 colorFuente
                ) != COD_OK) return ERR_SDL;

        char cant_clicks[10];
        enteroAString(jugadores[i].cant_clicks, cant_clicks, sizeof(cant_clicks));
        //CANTIDAD DE CLICKS
        if(renderizarTexto
                (MARGEN,
                 2*MARGEN+ALTO_INTERFAZ + (i + 1)*tamFuente + tamFuente,
                 ventana->renderer,
                 MARGEN + anchoNombre + anchoResultado + anchoNumeros,
                 anchoNumeros,
                 &fuenteTexto,
                 cant_clicks,
                 colorFuente
                ) != COD_OK) return ERR_SDL;

    }

    TTF_CloseFont(fuenteTexto);
    SDL_RenderPresent(ventana->renderer);
    TTF_Quit();
    return COD_OK;
}

void renderizarRectangulo(SDL_Renderer *renderer, int idColor, int x, int y, int w, int h)
{
    SDL_SetRenderDrawColor( renderer,
                            colores[idColor].r,
                            colores[idColor].g,
                            colores[idColor].b,
                            255);
    SDL_Rect rectangulo =
    {
        x,
        y,
        w,
        h
    };
    SDL_RenderFillRect(renderer, &rectangulo);
}

int inicializarFuente(TTF_Font **fuente, char *rutaFuente, int tamFuente)
{
    *fuente = TTF_OpenFont(rutaFuente, tamFuente);
    if (!(*fuente))
    {
        printf("No se pudo cargar la fuente: %s\n", TTF_GetError());
        return ERR_SDL;
    }
    return COD_OK;
}

int renderizarTexto(int x, int y, SDL_Renderer *renderer, int margenIzquierdo, int anchoContenedor, TTF_Font **fuente, char *texto, SDL_Color color)
{
    SDL_Surface* superficieTexto = TTF_RenderText_Solid(*fuente, texto, color);
    if (!superficieTexto)
    {
        printf("No se pudo renderizar el texto: %s\n", TTF_GetError());
        TTF_CloseFont(*fuente);
        return ERR_SDL;
    }

    SDL_Texture* texturaTexto = SDL_CreateTextureFromSurface(renderer, superficieTexto);
    if (!texturaTexto)
    {
        printf("No se pudo crear textura: %s\n", SDL_GetError());
        SDL_FreeSurface(superficieTexto);
        TTF_CloseFont(*fuente);
        return ERR_SDL;
    }
    SDL_Rect destino = { margenIzquierdo + (anchoContenedor - superficieTexto->w)/2, y, superficieTexto->w, superficieTexto->h};
    SDL_RenderCopy(renderer, texturaTexto, NULL, &destino);
    SDL_DestroyTexture(texturaTexto);
    SDL_FreeSurface(superficieTexto);
    return COD_OK;
}

void enteroAString(int num, char *texto, int tamTexto)
{
    snprintf(texto, tamTexto, "%d", num);
}

int renderizarEncabezadoEstadistica(SDL_Renderer *renderer,TTF_Font **fuente, SDL_Color colorFuente, int tamFuente,int anchoNombre,int anchoNumeros,int anchoResultado)
{
    //NOMBRE
    if(renderizarTexto
            (MARGEN,
             2*MARGEN+ALTO_INTERFAZ + tamFuente,
             renderer,
             MARGEN,
             anchoNombre,
             fuente,
             "NOMBRE",
             colorFuente
            ) != COD_OK) return ERR_SDL;

    //RESULTADO
    if(renderizarTexto
            (MARGEN,
             2*MARGEN+ALTO_INTERFAZ + tamFuente,
             renderer,
             MARGEN + anchoNombre,
             anchoResultado,
             fuente,
             "GANO",
             colorFuente
            ) != COD_OK) return ERR_SDL;

    //TIEMPO DE JUEGO
    if(renderizarTexto
            (MARGEN,
             2*MARGEN+ALTO_INTERFAZ + tamFuente,
             renderer,
             MARGEN + anchoNombre + anchoResultado,
             anchoNumeros,
             fuente,
             "TIEMPO",
             colorFuente
            ) != COD_OK) return ERR_SDL;

    //CANTIDAD DE CLICKS
    if(renderizarTexto
            (MARGEN,
             2*MARGEN+ALTO_INTERFAZ + tamFuente,
             renderer,
             MARGEN + anchoNombre + anchoResultado + anchoNumeros,
             anchoNumeros,
             fuente,
             "CLICKS",
             colorFuente
            ) != COD_OK) return ERR_SDL;

    return COD_OK;
}

void despejarMinas(Tablero * tablero)
{
    Click click;
    for(int i = 0; i<tablero->orden; i++)
    {
        for(int j = 0; j<tablero->orden; j++)
        {
            if(tablero->celdas[i][j].tiene_mina)
            {
                click.fila = i;
                click.columna = j;
                tablero->celdas_cubiertas --;
                tablero->celdas[i][j].revelada = true;
                celdaAsignarDibujo(tablero,&click);
            }
        }
    }
}

void taparMinas(Tablero *tablero)
{
    Click click;
    for(int i = 0; i<tablero->orden; i++)
    {
        for(int j = 0; j<tablero->orden; j++)
        {
            if( tablero->celdas[i][j].tiene_mina)
            {
                click.fila = i;
                click.columna = j;
                tablero->celdas_cubiertas ++;
                tablero->celdas[i][j].revelada = false;
                celdaAsignarDibujo(tablero,&click);
            }
        }
    }

}

void tableroDestruir(Tablero* tablero)
{
    // Libera matriz
    for (int i = 0; i < tablero->orden; i++)
    {
        free(tablero->celdas[i]);
    }
}


void ventanaDestruir(Ventana* ventana,Boton * ui)
{
    SDL_DestroyTexture(ui->texturaAgregar);
    SDL_DestroyTexture(ui->texturaAtras);
    SDL_DestroyTexture(ui->texturaAdelante);
    cerrarSDL(ventana);
    free(ventana);
}


void cerrarSDL(Ventana* ventana)
{
    SDL_DestroyRenderer(ventana->renderer);
    SDL_DestroyWindow(ventana->window);
    SDL_Quit();
}
void dibujarBotonGuardado(Ventana *ventana, Boton *btn)
{
    SDL_Rect rect = {ventana->anchoVentana-MARGEN-50, ALTO_INTERFAZ/2-MARGEN, 40, 40};
    btn->guardar = rect;
    SDL_SetRenderDrawColor(ventana->renderer, 69, 75, 166, 255);

    SDL_RenderFillRect(ventana->renderer, &rect);

    TTF_Font *fuente;
    if (TTF_Init() == -1)
    {
        printf("Error al iniciar SDL_ttf: %s\n", TTF_GetError());
        return;
    }

    inicializarFuente(&fuente,"fnt/mineTexto.TTF",40);
    renderizarTexto(ventana->anchoVentana-MARGEN-50,(ALTO_INTERFAZ/2-MARGEN)*1.3,ventana->renderer,ventana->anchoVentana-MARGEN-50,40,&fuente,"G",colores[BLANCO1]);

    TTF_CloseFont(fuente);
    TTF_Quit();
}

void iniciarJuego(Vector *vector, Click *click)
{
    Tablero *tablero = obtenerTableroActual(vector);
    tablero->jugador.inicio_partida = time(NULL);
    tableroColocarMinas(tablero, click);
    celdaRevelar(tablero, click);
    celdaAsignarDibujo(tablero, click);
    guardarLog("Inicio de juego", "Izquierdo", click);
}

int agregarTablero(Tablero * tablero,Ventana * ventana)
{
    int ordenViejo=tablero->orden;
    float porcentaje_minas = (float)tablero->minas_totales / (ordenViejo * ordenViejo);
    tablero->orden+=2;
    int nuevoOrden=tablero->orden;
    tablero->celdas_cubiertas+= (nuevoOrden * nuevoOrden) - (ordenViejo * ordenViejo);
    int minasNuevas=(tablero->orden*tablero->orden)*porcentaje_minas;
    int minasAgregar=minasNuevas-tablero->minas_totales;
    tablero->minas_totales=minasNuevas;
    Celda** nuevasCeldas = realloc(tablero->celdas, nuevoOrden * sizeof(Celda*));
    if (!nuevasCeldas) return ERR_MEM; // error de memoria

    tablero->celdas= nuevasCeldas;

    //Redimensionar cada fila existente para agregar columna nueva
    for (int i = 0; i < ordenViejo; i++)
    {
        Celda* nuevaFila = realloc(tablero->celdas[i], nuevoOrden * sizeof(Celda));
        if (!nuevaFila) return ERR_MEM; // error de memoria
        tablero->celdas[i] = nuevaFila;
    }
    //Reservar memoria para las nuevas filas completas
    for(int i = ordenViejo; i < nuevoOrden; i++)
    {
        tablero->celdas[i] = malloc(nuevoOrden * sizeof(Celda));
        if (!tablero->celdas[i]) return ERR_MEM;
    }

    inicializarAgregados(tablero->celdas,ordenViejo, nuevoOrden);
    cargarMinasNuevas(tablero,minasAgregar);
    actualizarAdyacencia(tablero,3);
    return COD_OK;
}

void actualizarAdyacencia(Tablero * tablero,int desplazamiento)
{
    Click click;

    int contador,orden=tablero->orden;

    for(int i = 0; i < orden; i++)
    {
        if(tablero->celdas[i][orden-desplazamiento].revelada)
        {
            click.columna=orden-desplazamiento;
            click.fila=i;
            contador=calcularMinasAdyacentes(tablero,&click);
            tablero->celdas[i][orden-desplazamiento].minas_alrededor = contador;
            if(contador == 0)
                revelarAdyacentes(tablero,&click);
            celdaAsignarDibujo(tablero,&click);
        }
    }

    for(int i = 0; i < orden; i++)
    {
        if(tablero->celdas[orden-desplazamiento][i].revelada)
        {
            click.columna=i;
            click.fila=orden-desplazamiento;
            contador=calcularMinasAdyacentes(tablero,&click);
            tablero->celdas[orden-desplazamiento][i].minas_alrededor = contador;
            celdaAsignarDibujo(tablero,&click);
        }
    }
}

void inicializarAgregados(Celda ** c,int ordenViejo, int nuevoOrden)
{
    for(int i = 0; i < ordenViejo; i++)
    {
        for (int j = ordenViejo; j < nuevoOrden; j++)
        {
            c[i][j].bandera=false;
            c[i][j].revelada=false;
            c[i][j].tiene_mina=false;
            c[i][j].minas_alrededor=INCOGNITA;
            memcpy(c[i][j].dibujo_asignado,celdaCubierta,sizeof(celdaCubierta));
        }
    }
    for(int i = ordenViejo; i < nuevoOrden; i++)
    {
        for (int j = 0; j < nuevoOrden; j++)
        {
            c[i][j].bandera=false;
            c[i][j].revelada=false;
            c[i][j].tiene_mina=false;
            c[i][j].minas_alrededor=INCOGNITA;
            memcpy(c[i][j].dibujo_asignado,celdaCubierta,sizeof(celdaCubierta));
        }
    }
}

void cargarMinasNuevas(Tablero * tablero,int minasFaltantes)
{
    srand(time(NULL)); // Semilla para random
    int f;
    int c;

    for(int minasColocadas = 0;  minasColocadas < minasFaltantes; minasColocadas++)
    {

        do
        {
            if(rand()%2)
            {
                f = tablero->orden - 1 - rand() % 2;
                c = rand() % tablero->orden;
            }
            else
            {
                f = rand() % tablero->orden;
                c = tablero->orden - 1 - rand() % 2;
            }

        }
        while(tablero->celdas[f][c].tiene_mina == true);//(f!=tablero->orden-1 && c!=tablero->orden-1);

        tablero->celdas[f][c].tiene_mina = true;
    }
}



int vectorCrear(Vector *vec, size_t tamElem)
{
    vec->vec = malloc(tamElem * CAP_INI);
    if(vec->vec == NULL) return ERR_MEM;

    vec->indice = 0;
    vec->tamElem = tamElem;
    vec->cap = CAP_INI;
    vec->ce = 0;

    return COD_OK;
}

int vectorAgregarElemento(Vector *vec, void *elem)
{
    if(vec->ce * FACT_CAP_MIN > vec->cap)
        if(vectorRedimensionar(vec, vec->cap * FACT_CAP_INCR) != COD_OK)
            return ERR_MEM;


    memmove(vec->vec + vec->tamElem,vec->vec,vec->tamElem * vec->ce);
    memcpy(vec->vec, elem, vec->tamElem);
    vec->ce++;
    return COD_OK;
}

int vectorRedimensionar(Vector *vec, size_t nuevaCap)
{
    void *nuevoVec = realloc(vec->vec, nuevaCap * vec->tamElem);
    if(nuevoVec == NULL) return ERR_MEM;

    vec->vec = nuevoVec;
    vec->cap = nuevaCap;

    return COD_OK;
}

void vectorIncrementarIndice(Vector *vec)
{
    vec->indice++;
}

void vectorDecrementarIndice(Vector *vec)
{
    vec->indice--;
}

void vectorTableroDestruir(Vector *vec)
{
    for(int i=0; i < vec->ce; i++)
        tableroDestruir(vec->vec + i * vec->tamElem);
}

Tablero *obtenerTableroActual(Vector *vec)
{
    Tablero *tablero = (Tablero*)(vec->vec + vec->indice * vec->tamElem);
    return tablero;
}

Tablero* tableroCopiar(Tablero *original)
{
    Tablero *copia = malloc(sizeof(Tablero));
    if(!copia) return NULL;

    memcpy(copia, original, sizeof(Tablero));

    copia->celdas = malloc(copia->orden * sizeof(Celda*));
    if(!copia->celdas)
    {
        free(copia);
        return NULL;
    }

    for(int i = 0; i < copia->orden; i++)
    {
        copia->celdas[i] = malloc(copia->orden * sizeof(Celda));
        if(!copia->celdas[i])
        {
            for(int j = 0; j < i; j++)
                free(copia->celdas[j]);
            free(copia->celdas);
            free(copia);
            return NULL;
        }
        memcpy(copia->celdas[i], original->celdas[i], copia->orden * sizeof(Celda));
    }

    return copia;
}


int reducirTablero(Vector ** vec, Ventana **v,Boton * ui)
{

    Tablero * t=obtenerTableroActual(*vec);
    if(validarReduccion(t) != COD_OK) return ERR_ARG;

    int ordenViejo  = t->orden;
    int nuevoOrden  = ordenViejo - 2;
    float porcentajeMin=t->minas_totales*100/(ordenViejo*ordenViejo);
    int minasNuevas=(int)((nuevoOrden*nuevoOrden)*porcentajeMin/100);
    int minasBorde, banderasBorde;
    contarEntidadesBorde(t, &minasBorde, &banderasBorde);
    int minasQuitar=t->minas_totales - minasNuevas - minasBorde;

    int celdasQuitadas = ordenViejo*ordenViejo - nuevoOrden*nuevoOrden;


    for(int i = 0; i < nuevoOrden; i++)
        t->celdas[i] = realloc(t->celdas[i], nuevoOrden * sizeof(Celda));

    for(int i = nuevoOrden; i < ordenViejo; i++)
        free(t->celdas[i]);


    t->celdas = realloc(t->celdas, nuevoOrden * sizeof(Celda*));
    if(!t->celdas) return ERR_MEM;


    t->orden = nuevoOrden;
    t->banderas_puestas-= banderasBorde;
    t->celdas_cubiertas-= celdasQuitadas;

    if(minasQuitar>0){
        desactivarMinasAleatorias(t,minasQuitar);
        t->minas_totales =minasNuevas;
    }else{
        t->minas_totales-=minasBorde;
    }



    actualizarAdyacencia(t,1);

    return COD_OK;
}



int validarReduccion(const Tablero *t)
{
    return (t->orden <= 8) ? ERR_ARG : COD_OK;
}

void contarEntidadesBorde(const Tablero *t, int *minas, int *banderas)
{
    *minas =0;
    *banderas = 0;
    int n = t->orden;

    for(int i=n-2;i<n;i++){
        for(int j=0;j<n;j++){
            const Celda c=t->celdas[i][j];
            if (c.tiene_mina)(*minas)++;
            if (c.bandera)(*banderas)++;
        }
    }
    for(int i=n-2;i<n;i++){
        for(int j=0;j<n-2;j++){
            const Celda c=t->celdas[j][i];
            if (c.tiene_mina)(*minas)++;
            if (c.bandera)(*banderas)++;
        }
    }
}

void desactivarMinasAleatorias(Tablero *t, int aQuitar)
{
    srand(time(NULL));
    while(aQuitar)
    {
        int f = rand() % t->orden;
        int c = rand() % t->orden;
        Celda *cel = &t->celdas[f][c];
        if (cel->tiene_mina && !cel->revelada)
        {
            cel->tiene_mina = false;
            aQuitar--;
            t->minas_totales--;
        }
    }
}

