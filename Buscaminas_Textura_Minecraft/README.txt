En esta carpeta se encuentra un .zip con los .c y .h que los acompaña mas carpetas con las librerias y archivos necesarios para su correcta ejecucion.

EL SIGUIENTE TUTORIAL FUE DISEÑADO PARA CONFIGURAR EL IDE CODE::BLOCKS. SI TRATASE PROBAR EL PROYECTO EN OTRO IDE LA CONFIGURACION DEBE CONSTAR CON LOS MISMOS LINKEOS.

Pasos para incluir la librería ttf en el buscaminas:
1) Incluir la librería SDL2_ttf.dll, que está dentro de la carpeta lib, en la carpeta bin/debug, junto con el .exe del proyecto y el SDL2.dll
2) Para evitar linkear nuevos includes, dentro de Codeblocks, en Project/BuildOptions/Search Directories/Compiler, incluir el archivo SDL_ttf.h en la siguiente ubicación: SDL2-2.0.22\x86_64-w64-mingw32\include
3) Para evitar linkear librerías nuevas en Project/Build Options/Search Directories/Linker, incluir el archivo libSDL2_ttf.a en la siguiente ubicación: SDL2-2.0.22\x86_64-w64-mingw32\lib

Linkeos (ttf):
1) En Project/Build Options/Linker Settings, junto con "-Imingw32 -ISDL2main -ISDL2" en Other linker options,agregar lo siguiente:
-lSDL2_ttf
-lgdi32
-luser32
-ladvapi32
-lusp10
-lrpcrt4

*ACLARACIÓN: En Link Libraries no es necesario tener nada más que "SDL2".

De esta manera podremos hacer los includes correspondientes para SDL_ttf siendo este "#include <SDL2/SDL_ttf.h>"

Tutorial para usar SDL2_Image:
1)pegar ,de la carpeta lib, el archivo SDL2_image.dll en la carpeta bin/debug junto con el .exe del proyecto.
2)pegar,de la carpeta lib, el archivo libSDL2_image.a en la carpeta lib del SDL2.Direccion:SDL2-2.0.22\x86_64-w64-mingw32\lib.
3)pegar el archivo SDL_image.h en la carpeta include del SDL2.Direccion:SDL2-2.0.22\x86_64-w64-mingw32\include\SDL2.
4)finalmente en Project/Build Options/Linker Settings en Other Linker Options agregar el siguiente linkeo: -lSDL2_image.

Tutorial para usar SDL2:
1) Descomprimir la carpeta SDL2-2.0.22.
2) Incluir dicha carpeta descomprimida en la carpeta donde estará nuestro proyecto, junto con el main,los .c y .h existentes.
3) En la dirección SDL2-2.0.22\x86_64-w64-mingw32\bin, copiar (NO CORTAR Y PEGAR), el archivo SDL2.dll e incluirlo en la carpeta bin/debug de nuestro proyecto junto con el .exe correspondiente.

Linkeos (SDL2):
1) En Project/Build Options/Linker Settings/Link libraries, incluir (copiar y pegar): "SDL2"
2) En Project/Build Options/Linker Settings/Other Linker Options, incluir (copiar y pegar): "-Imingw32 -ISDL2main -ISDL2 ".
3) En Project/Build Options/Search Directories/Compiler agregar el siguiente link: “SDL2-2.0.22\x86_64-w64-mingw32\include”.
4) En Project/Build Options/Search Directories/Linker agregar el siguiente link: “SDL2-2.0.22\x86_64-w64-mingw32\lib”.

5) Una vez hecho todo esto en los archivos que queramos usar SDL2 debemos hacer el siguiente include : #include <SDL2/SDL.h>
