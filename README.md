# micromachines

## Librerias / programas necesarios

### Se instalan con apt install en ubuntu
cmake

libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-image-dev

lua5.3 liblua5.3-dev

libavutil-dev libavformat-dev libavcodec-dev libswscale-dev libswresample-dev

## Compilacion
Clonar el repositorio.
Ubicarse en el directorio raíz
En una consola
  mkdir build
  cd build
  make install (se recomienda -jN con N el número de núcleos)
  
## Ejecucion
Los ejecutables y assets necesarios se instalan en /home/user/NombreUsuario/micromachines

En una terminal en dicho directorio:
  ./Servidor
  
En otra terminal, mismo directorio:
  ./Cliente
  
  
Hacer click en cualquier parte de la pantalla, y presionar la tecla C.
Para conducir, se acelera con la tecla A, se retrocede/frena con la Z.

### Para dos o mas jugadores
Ejecutar el servidor
Ejecutar un cliente
Ejecutar otro cliente
Hacer click en la pantalla en el primer cliente
Hacer click en la pantalla en el segundo cliente
En uno solo de los clientes, presionar la tecla C.

###### The smallest heading
