# Aprendiendo del Shell

El Shell es un programa que toma comandos desde el teclado
y los pasa al Sistema Operativo para realizar alguna operación.

Casi todos las distribuciones Linux,proporcionan un shell, desde el
proyecto GNU, llamado [`bash`](https://www.gnu.org/software/bash/), que 
reemplaza al original shell de Unix, llamado `sh`.

## Emuladores de terminal

Cuando estamos usando una interfaz de usuario gráfica, necesitamos otro programa 
llamado `emulador de terminal (terminal emulador)` o simplemente  **terminal** para interactuar con el shell.

Por ejemplo para interfaces como KDE Gnome

- KDE  			**konsole**.
- GNOME 		**gnome-terminal.**

## Primeros pasos

Normalmente podemos lanzar el terminal escribiendo `alt + F2`

``` bash
[nombre-usuario@linux~]$
```

Eso es llamado un `prompt de Shell` y aparece siempre que el shell, está listo para
recibir entradas. Esto puede variar de la distribución y usualmente incluye
`nombre-usuario@nombre-maquina`, seguido por el actual directorio de trabajo y un signo de dolar.

Algunas veces en lugar del signo dolar, aparece el signo `#`, esto significa que el terminal tiene `previlegios de super usuario`. Eso significa que tu estas logeado como el `usuario root` o has seleccionado un terminal con permisos de `superusuario`.


Si presionas la tecla arriba (up-arrow) para recordar el comando  anterior. Esto es llamado `historia de comandos (command history)`. Presiona la tecla abajo (down-arrow) y el previo comando desaparece.


## Algunos comandos simples

- `date`: Comando que  muestra la fecha y la hora

```bash
[nombre-usuario@linux~]$date
sáb sep 26 19:45:11 PET 2015
```
- `cal`: Muestra un calendario del mes actual.

```bash
[nombre-usuario@linux~]$cal
 Septiembre 2015
dom lu ma mi ju vi sá
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30
```

- `df` Comando que sirve para ver la cantidad de espacio libre de tus particiones

```bash
[nombre-usuario@linux~]$df
S.ficheros     blocks de 1K    Usados Disponibles Uso% Montado en
/dev/sda1         472869112 127166280   321659364  29% /
none                      4         0           4   0% /sys/fs/cgroup
udev                3857540         4     3857536   1% /dev
tmpfs                773432      1272      772160   1% /run
none                   5120         0        5120   0% /run/lock
none                3867148     16260     3850888   1% /run/shm
none                 102400        24      102376   1% /run/user
```

- `free` Muestra la cantidad de memoria libre.

```bash
[nombre-usuario@linux~]$free
            total       usado       libre     compart.    búffers     almac.
Mem:       7734300    2049148    5685152      36132      71676     698268
-/+ buffers/cache:    1279204    6455096
Intercambio:    7841788          0    7841788
```
Para finalizar la sesión en el terminal, cerrando la ventana del terminal o escribiendo `exit` en el prompt  del terminal.

```bash
[nombre-usuario@linux~]$exit.
```

## Navegando en el sistema de archivos


Como en Windows, Linux organiza sus archivos de manera jerarquica ` hierarchical directory structure`. Esto significa que ellos están organizados como un diseño de árboles de directorios, los cuales contienen directorios y archivos. El primer directorio en el sistema es llamado `directorio raiz(root directory)` que contiene directorios y archivos, los cuales a su vez contienen más directorios y archivos. Por ejemplo estos directorios son los que contiene un directorio raiz típico.


``` bash
bin    dev   initrd.img      lost+found  opt   run   sys  var
boot   etc   initrd.img.old  media       proc  sbin  tmp  vmlinuz
cdrom  home  lib             mnt         root  srv   usr  vmlinuz.old
```
Los sistemas Linux, siempre tienen un único sistema de archivos independiente de como sus dispositivos de almacenamiento están  unidos al computador. Los dispositivos de almacenamiento son ** montados **  a varios puntos del árbol, dependiendo de lo que se deba hacer con ellos y del administrador del sistema.

### El actual directorio de trabajo

- Para mostrar el actual `directorio de trabajo (working directory)` usamos el comando `pwd(print working directory)`.


```bash
[nombre-usuario@linux~]$pwd
/home/cesarlara-avila
```

Cuando iniciamos o nos logeamos en nuestro sistema (o empezar el terminal), nuestro actual directorio de trabajo es nuestro directorio `home`. Cada cuenta de usuario tiene su propio directorio `home` y es el lugar donde normalmente se escriben los archivos.

- Para listar todos los archivos y directorios del actual directorio de trabajo, usamos el comando `ls`.

```bash
[nombre-usuario@linux~]$ls
.....
silabus-cm274.md
simplex1.R
Simul-CC.c
Soluciones-Introductorio.md
Soluciones-Introductorio.pdf
stadistic.R
tabla-Z.R
temp.rda
temp.txt
thuesen.txt
TLC.R
TutorialCLI.md
VariablesAleatorias.Rnw
Vectores-Matrices-Arrays.ipynb
.....
```

Para cambiar el  actual directorio de trabajo, usamos el comando `cd`. Para hacer esto, escribimos `cd` seguido por la `ruta de nombres(pathname)` del directorio al que queremos ir. Un `pathname` es una ruta que tomamos a lo largo de las ramas del árbol de directorios para conseguir el directorio que queremos. Las `rutas de nombres` pueden ser especificados de dos maneras distintas: rutas de nombres absolutas y relativas.

Las ** rutas de nombres absoluta** inician con el directorio raiz y siguen por las ramas, hasta completar la ruta al directorio o archivo deseado.

```bash
[nombre-usuario@linux~]$cd /usr/bin
[nombre-usuario@linux bin]$pwd
/usr/bin
[nombre-usuario@linux bin]$ls
...........
lspci                            xxd
lspgpot                          xz
lss16toppm                       xzcat
lsusb                            xzcmp
ltrace                           xzdiff
ltxfileinfo                      xzegrep
lua2dox_filter                   xzfgrep
lualatex                         xzgrep
luaotfload-tool                  xzless
luatex                           xzmore
lubuntu-logout                   yes
lubuntu-software-center          zdump
luit                             zenity
lupdate                          zip
lwp-download                     zipcloak
lwp-dump                         zipdetails
lwp-mirror                       zipgrep
lwp-request                      zipinfo
lxappearance                     zipnote
.............
```


Una ruta de nombres absoluta empieza desde el directorio raíz y recorre  la rama del árbol del sistema de archivos hasta llegar a su destino, un ruta de nombres relativa en cambio empieza desde el directorio de trabajo. Para ello, utiliza un par de símbolos para representar  posiciones relativas en el árbol del sistema de archivos. Estos símbolos especiales son `"." (punto) y ".." (punto punto)`.

Los "." símbolo se refiere al directorio de trabajo y el ".." símbolo se refiere a la directorio padre (un directorio un nivel por encima del directorio actual) del directorio de trabajo. Así es como funciona:

```bash
[nombre-usuario@linux~]$cd /usr/bin
[nombre-usuario@linux bin]$pwd
/usr/bin
```

Ahora queremos cambiar el directorio actual al directorio padre de `/usr/bin`, el cual es `/usr`. Podemos hacer esto de dos maneras diferentes

```bash
[nombre-usuario@linux bin]$cd /usr
[nombre-usuario@linux usr]$pwd
/usr
```

o con una ruta de nombres relativa

```bash
[nombre-usuario@linux bin]$cd ..
[nombre-usuario@linux usr]$pwd
/usr
```

De igual manera podemos cambiar el directorio `/usr` a `/usr/bin` de dos maneras distintas

```bash
[nombre-usuario@linux usr]$cd /usr/bin
[nombre-usuario@linux bin]$pwd
/usr/bin
```

o con rutas de nombres relativas

```bash
[nombre-usuario@linux usr]$cd ./bin
[nombre-usuario@linux bin]$pwd
/usr/bin
```

En casi todos los casos, se puede omitir el `./`. Esto implica que si tu no especificas una ruta de nombres, el directorio actual de trabajo es asumido.


```bash
[nombre-usuario@linux usr]$cd bin
```

### Útiles atajos para cd

```
Atajo                        Resultado
cd                 Cambia tu directorio de trabajo a tu directorio home
cd -               Cambia tu directorio de trabajo al previo directorio de trabajo
cd ~nombre_usuario Cambia el directorio de trabajo al directorio home nombre_usuario
```



### Observaciones importantes

- Los archivos que empiezan con un punto, son archivos ocultos. Esto significa que `ls` no puede listarlos, para ello se utiliza `ls -a`, esto es debido a que  cuando se creó tu cuenta, varios archivos ocultos se colocaron en tu directorio personal para configurar  cosas por ti mismo, además de que  algunas aplicaciones colocan sus archivos de configuración y ajustes en tu directorio personal como archivos ocultos.
 ```bash
[nombre-usuario@linux ~ $ls -a 
.............
.Xauthority
.xchm
.xscreensaver
.xsession-errors
.xsession-errors.old
.zcompdump
.zcompdump-c-lara-5.0.2
.zsh_history
.zshrc
..............
```

- Los nombres de archivos y comandos en Linux son `case sensitive`. Los nombres de archivos `ARCHIVO1` y `archivo1` se refieren a diferentes archivos.
- Linux no tiene un concepto de una `"extensión"` como otros sistemas operativos. Los contenidos y/o función de un archivo se determina por otros medios. Aunque Linux no utiliza las extensiones de archivo para determinar el contenido/ propósito de un archivo, algunas aplicaciones lo hacen.
- Aunque Linux soporta nombres de archivo  que pueden contener espacios incrustados y caracteres de puntuación, debes limitar los caracteres de puntuación en los nombres de archivos y lo más importante, no incrustar espacios en los nombres de archivo. Si desea representar espacios entre las palabras en un nombre de archivo, utilice caracteres de subrayado.


## Explorando el sistema

`ls` es el comando más usado, y con justa razón. Con este comando podemos ver el contenido de directorios y determinar una variedad de archivos importantes y atributos de directorios.

```bash
[nombre-usuario@linux ~ $ls
.......

Laboratorio2.Rnw
Lista1-Ejercicios-concordance.tex
Lista1-Ejercicios.log
Lista1-Ejercicios.pdf
Lista1-Ejercicios.Rnw
Lista1-Ejercicios.synctex.gz
Lista1-Ejercicios.tex
Lista2-Ejercicios.Rnw
Lista3-Ejercicios-concordance.tex
Lista3-Ejercicios.log
Lista3-Ejercicios.pdf
Lista3-Ejercicios.Rnw

......
```

Podemos especificar el directorio a listar
```bash
[nombre-usuario@linux ~ $ls /boot
abi-3.13.0-24-generic         initrd.img-3.13.0-62-generic
abi-3.13.0-57-generic         initrd.img-3.13.0-63-generic
abi-3.13.0-58-generic         memtest86+.bin
abi-3.13.0-59-generic         memtest86+.elf
abi-3.13.0-61-generic         memtest86+_multiboot.bin
abi-3.13.0-62-generic         System.map-3.13.0-24-generic
abi-3.13.0-63-generic         System.map-3.13.0-57-generic
config-3.13.0-24-generic      System.map-3.13.0-58-generic
config-3.13.0-57-generic      System.map-3.13.0-59-generic
config-3.13.0-58-generic      System.map-3.13.0-61-generic
config-3.13.0-59-generic      System.map-3.13.0-62-generic
config-3.13.0-61-generic      System.map-3.13.0-63-generic
config-3.13.0-62-generic      vmlinuz-3.13.0-24-generic
config-3.13.0-63-generic      vmlinuz-3.13.0-57-generic
grub                          vmlinuz-3.13.0-58-generic
initrd.img-3.13.0-24-generic  vmlinuz-3.13.0-59-generic
initrd.img-3.13.0-57-generic  vmlinuz-3.13.0-61-generic
initrd.img-3.13.0-58-generic  vmlinuz-3.13.0-62-generic
initrd.img-3.13.0-59-generic  vmlinuz-3.13.0-63-generic
initrd.img-3.13.0-61-generic
```

Listamos varios directorios: En este caso el directorio de trabajo y el directorio `usr`.

```bash
[nombre-usuario@linux ~ $ls ~/usr
```

Podemos cambiar el formato de salida para revelar más detalles.
```bash
[nombre-usuario@linux ~ $ls -ls
.....
drwx------  3 cesarlara-avila cesarlara-avila 4096 jul  6 23:03 .macromedia
-rw-rw-r--  1 cesarlara-avila cesarlara-avila  9043 sep 14 14:14 make.md
-rw-rw-r--  1 cesarlara-avila cesarlara-avila 753 sep 20 23:31 Mbiseccion.R
-rw-rw-r--  1 cesarlara-avila cesarlara-avila  806 sep 22 10:55 MCd-Mcm.c
-rw-r--r--  1 root            root             79 sep 16 01:17 miData.Rdata
-rw-rw-r--  1 cesarlara-avila cesarlara-avila  27 sep 22 10:02 mili.txt
drwx------  4 cesarlara-avila cesarlara-avila  4096 jul  6 22:52 .mozilla
.....
```


### Opciones y argumentos

Los  comandos suelen ir acompañados de una o más opciones que modifican su comportamiento y además, por uno o más argumentos, sobre los que los comandos actuan. Así  la mayoría de los comandos se ven más o menos así:

```
comandos -opciones argumentos
```

La mayoría de los comandos utilizan opciones consisten  de un sólo carácter precedido por un guión, por ejemplo, `"-l"`, pero muchos comandos, incluidos los del proyecto GNU, también admiten opciones largas, que consisten en una palabra precedida de dos guiones. Además, muchos comandos permiten múltiples opciones cortas que se encadenan juntas.

En este ejemplo, el comando `ls` tiene dos opciones, la opción "l" para producir la salida de formato largo, y la opción "t" para ordenar el resultado por fecha de modificación del archivo.

```bash
[nombre-usuario@linux ~ $ls -lt
```

Podemos agregar una opción larga `--reverse` para revertir el orden de búsqueda.

```bash
[nombre-usuario@linux ~ $ls -lt --reverse
```

### Viendo la salida de formato largo

Expliquemos que es cada campo en la salida de uno de los archivos, dado por `ls -l`:

```bash
-rw-rw-r-- 1 cesarlara-avila cesarlara-avila 12143 sep 27 00:09 TutorialCLI.md
drwx------ 2 cesarlara-avila cesarlara-avila  4096 sep 16 01:47 RCode
```

- `-rw-rw-r--` o `drwx------`: Derechos de acceso al archivo. El primer carácter indica el tipo de archivo. Entre los diferentes tipos, un guión  significa un archivo normal, mientras que una "d" indica un directorio.
Los siguientes tres caracteres son los derechos de acceso para el propietario del archivo, los siguientes tres son para los miembros del grupo con acceso al archivo, y la final tres son los permisos para el resto .
- `1 o 2`: Número de `enlaces fuertes (hard links).`
-  `cesarlara-avila` : El usuario propietario del archivo.
-  `cesarlara-avila` : El nombre del grupo que posee el archivo.
-  `12143 o 4096`    : Tamaño del archivo en bytes.
-  `sep 27 00:09 o  sep 16 01:47`: Fecha y hora de la última modificación del archivo.
-  `TutorialCLI.md o RCode`: Nombre de los archivos.


### Otros comandos importantes

- `file` Comando para determinar el tipo de archivo.

```bash
[nombre-usuario@linux ~ $file EjerciciosR-1.Rnw 
EjerciciosR-1.Rnw: LaTeX 2e document, ASCII text, with very long lines
```
- `less` Este comando es un programa para ver archivos de texto y es muy útil  debido a que muchos de los archivos (**scripts **) que contienen las configuraciones del sistema (llamados archivos de configuración) se almacenan en este formato, y ser capaz de leerlos nos da una idea de cómo funciona el sistema.

```c
[nombre-usuario@linux ~ $less getchar-putchar.c
/*
** Este programa copia la entrada estandar a la salida estandar y
* calcula un "suma" de caractere. La suma es mostrada despues de la entrada.
*/
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
int c;
char sum =-1;

// Lee los caracteres uno a uno y los agrega a sum.

while( (c = getchar()) != EOF ){
  putchar( c );
  sum += c;
    }
      printf( "%d\n", sum );
      return EXIT_SUCCESS;
}
getchar-putchar.c (END)
```


Una vez que `less` empieza puede mostrarnos el contenido del archivo.

#### ¿ Qué se entiende por texto? [The Linux Command Line](http://linuxcommand.org/).

Hay muchas formas de representar la información en un ordenador. Todos los métodos implican la definición de una relación entre la información y algunos números que se utilizarán para representarla. Las computadoras después de todo, sólo entienden números y todos los datos son convertidos  en representación numérica.

Algunos de estos sistemas de representación son muy complejos  mientras que otros son muy  simples. Uno de los primeros y más simples es llamado  `ASCII` que es la abreviatura de `American Standard Code for Information Interchange`. Este es un esquema de codificación simple que fue utilizado  para mapear los caracteres del teclado a números. El texto es un simple mapeo uno a uno de caracteres a  números. Es muy compacto. Cincuenta caracteres de texto se traducen en  cincuenta bytes de datos. Es importante entender que sólo el texto contiene un mapeo de caracteres a números. No es lo mismo que un documento de procesador de textos, como el creado por OpenOffice.org o Microsoft Word. Esos archivos, en contraste con ASCII  contienen muchos elementos no son de texto que se utilizan para describir su estructura y formato. Archivos de texto plano ASCII contienen  algunos códigos de control adicionales   como saltos de línea, tabulador, etc. A través de un sistema Linux, muchos archivos se almacenan en formato de texto y hay muchas herramientas de Linux que trabajan con archivos de texto.

Es importante conocer los archivos de texto, por que muchos archivos llamados de `configuración` son almacenados en este formato y siendo capaz de leer estos nos da una visión de como el sistema trabaja, además de que muchos programas que el sistema  usa llamados `scripts` utilizan este formato.

El comando `less` es usada como es esto

```
less nombre-archivo
```

Una vez iniciado, el programa `less` le permite desplazarse hacia adelante y hacia atrás mediante un archivo de texto. Como el siguiente ejemplo

```bash
[cesarlara-avila@c-lara~]$less /etc/vim/vimrc
```

La siguiente tabla muestra los comandos de teclado más comunes utilizadas por `less`


```
     Comando					Acción
   Page Up or b            Desplazarse hacia atrás una página
   Page Down or space      Desplazarse a la página siguiente
   Up Arrow                Desplazarse una línea hacia arriba
   Down Arrow              Desplazarse una línea hacia abajo
      G                    Desplazarse al final del archivo de texto
   1G or g               Ir al principio del archivo de texto
 /caracter            Busca la próxima ocurrencia de caracter
     n                  Busca la siguiente aparición de la búsqueda anterior
     h                      Visualiza la pantalla de ayuda
     q                         Quitamos less
```

El programa `less` fue diseñado como una mejora de un programa anterior llamada `more`. El nombre `"less"` es un juego en la frase `"less is more"`.

`less` cae en la clase de programas llamados `pagers` que permiten la fácil visualización de documentos de texto grandes  página por página hacia adelante y hacia atrás junto con otras características, como indica el cuadro anterior.

Podemos ver la documentación de  `less`  escribiendo `man less`.

## Directorios Importantes

El diseño del sistema de archivos en los sistemas Linux es muy similar al de  otros sistemas Unix. El diseño es en realidad especificado en un estándar llamado  `Linux Filesystem Hierarchy Standard `y mucho de los más interesantes archivos están  en archivo de texto.

Veamos una lista de los directorios más importantes del sistema de archivos de Linux

- `/`: Directorio raiz. Donde todo empieza.
- `/bin`:  Contiene programas (binarios) que deben estar presente en el sistema para que arranque y corra.
- `/boot`: Contiene el Kernel de Linux, disco de imagen RAM inicial y el gestor de arranque. Un archivo importante 	es `/boot/vmlinuz` que es el Kernel Linux.
- `/dev`: Este es un directorio especial que contiene nodos de dispositivos. "Todo es un archivo" también se aplica a los dispositivos. Aquí es donde el kernel mantiene una lista de todos los dispositivos que entiende.
- `/etc`: Es un directorio contiene todos los archivos de configuración de todo el sistema. También contiene una colección de scripts del shell que  inician cada uno de los servicios del sistema en el arranque. Todo en este directorio debe ser  texto legible. Archivos importantes:
  - `/etc/crontab`: Un archivo que define cuando un proceso automático deberá ejecutarse.
  - `/etc/fstab`:  Es una tabla de dispositivos de almacenamiento y sus puntos de montajes asociados.
  - `/etc/passwd`: Contiene una lista  de las cuentas de usuario.
- `/home`: Directorio del usuario.
- `/lib`: Contiene librerias compartidas usadas por los programas centrales del sistema. Son similares a las DLL en windows.
- `/lost + found`: Cada partición formateada o dispositivo usando el sistema de archivos  **ext3** tiene este directorio. Es usado en el caso de una recuperación parcial de un evento de sistemas dañados.
- `/media`: Es el directorio, que contiene los puntos de montaje de dispositivos removibles como los USB, CD-ROMs, etc, que son montados automáticamante en la insercción.
- `/mnt`: Contiene los puntos de montaje de dispositivos removibles que han sidos montados manualmente.
- `/opt`: Es un directorio usado para instalar *opcional* software.
- `/proc`: Es un sistema de archivo virtual mantenido por el Kernel. Los "archivos" que contiene son rendijas en el propio Kernel. Los archivos se pueden leer y le dará una idea de cómo el Kernel ve su computadora.
- `/root`: Este es el directorio de la cuenta del usuario `root`.
- `/sbin`: Contiene *sistemas binarios*, que son programas que llevan tareas vitales que son reservadas al usuario root.
- `/tmp`: El directorio `/tmp` está destinado para el almacenamiento de archivos temporales, creados por diversos programas. Algunas configuraciones causan que este directorio deba ser vaciado cada vez que se reinicia el sistema.
- `/usr`: El árbol de directorios `/usr` probablemente es el más grande en un sistema Linux. Contiene todos los archivos de los programas y de soporte utilizados por los usuarios regulares.

  - `/usr/bin`: Contiene ejecutables instalados en tu distribución.
  - `/usr/lib`: Librerias compartidas por los programas en `/usr/bin`
  - `/usr/local`: Es el directorio donde se encuentran los programas que no son incluidos con la distribución, pero que están destinados para el uso de todo el sistema. Programas compilados desde el código fuente normalmente se instalan en `/usr/local/bin`.
  - `/usr/sbin`: Contiene muchos programas de administración del sistema.
  - `/usr/share`: Es un directorio que contiene toda los datos, usados por los programas en `/usr/bin`. Esto incluye cosas como archivos de configuración, íconos, archivos de sonido, fondos de pantalla, etc.
  - `/usr/share/doc`: Documentación de programas del sistema.
- `/var`: El árbol de directorios `/var` es donde se almacenan los datos que  probablemente  cambien. Varias bases de datos,  correo de usuario, etc., se encuentran aquí.
  - `/var/log`: Contiene los archivos de registro, registros de diversas actividades del sistema. Estos son muy importantes y deben ser vigilados de vez en cuando. El archivo más útil es `/var/log/messages`. Ten en cuenta que por razones de seguridad en algunos sistemas, debe ser superusuario quien pueda ver los archivos de registro.


##  Enlaces símbolicos

Al mirar en nuestro sistema de archivos, es probable que veamos un directorio con una entrada como esta:
```
lrwxrwxrwx  1 root root  19 oct 15  2013 libsidplay.so.1 -> libsidplay.so.1.0.3

```

Observa cómo la primera letra de la lista es "l" y la entrada parece tener dos nombres de archivo? Este es un tipo especial de un archivo llamado un `enlace simbólico`.  En sistemas Unix  es posible tener un archivo referenciado por varios nombres. Mientras que el valor de este puede no ser obvio, es realmente una característica útil.

Imagina este escenario: Un programa requiere el uso de un recurso compartido de algún tipo contenido en un archivo llamado `"Mily"`, pero `"Mily"` tiene cambios de versión frecuentes. Sería bueno incluir el número de versión en el nombre del archivo para que el administrador u otra parte interesada pueda ver qué versión de `"Mily"` está instalada. Esto presenta un problema. Si cambiamos el nombre del recurso compartido, tenemos que localizar  cada programa que lo utiliza y modificarlo para buscar un nuevo nombre de recurso cada vez que se instala una nueva versión. Eso no suena divertido en absoluto.

Aquí es donde los enlaces simbólicos interviene. Digamos que instalamos la versión 2.6 de `"Mily"`, que tiene el nombre de archivo `"Mily-2.6"` y luego creamos un enlace simbólico llamado simplemente `"Mily"` que apunta a `"Mily-2.6"`. Esto significa que cuando un programa se abre el archivo `"Mily"`, en realidad está abriendo el archivo `"Mily-2.6"`. Ahora todo el mundo es feliz. Los programas que dependen de `"foo"` pueden encontrarlo y podemos ver qué versión actual está instalada. Cuando es el momento de actualizar a `"Mily-2.7"` solo  agregamos el archivo a nuestro sistema, eliminamos  el vínculo simbólico `"Mily"` y crear uno nuevo que apunta a la nueva versión. Esto no sólo resuelve el problema de la actualización de la versiones, sino que también nos permite mantener ambas versiones en nuestra máquina. Imagínese que `"Mily-2.7"` tiene un error,  tenemos que volver a la versión antigua necesariamente.

Una vez más, solo  eliminamos el vínculo simbólico que apunta a la nueva versión y creamos un nuevo enlace simbólico que apunta a la versión anterior.


# Manipulando Archivos y Directorios

## Wildcards (comodines)

Desde que el shell utiliza nombres de archivo demasiadas veces, proporciona caracteres especiales para ayudar a especificar rápidamente grupos de nombres de archivos. Estos caracteres especiales son llamados `comodines`(http://www.linfo.org/wildcard.html).

Los comodines nos permiten seleccionar los nombres de archivo basado en patrones de caracteres. La siguiente tabla muestra una lista de comodines y que es lo que seleccionan

```
Comodin					 Significado
*					Enlaza uno o más caracteres
?					Enlaza un único caracter
[caracteres] 		Enlaza algún caracter que es miembro de *caracteres*
[!caracter] 		Enlaza algún caracter que no es miembro de *caracteres*
[[:clase:]] 		Enlaza algún caracter que es miembro de una determinada clase

```

Las clases comunmente usadas son

```
Clase de caracteres 		Significado
[:alnum:]          Enlaza algún caracter alfa numérico
[:alpha:]          Enlaza algúb caracter alfabético
[:digit:]          Enlaza algún numeral
[:lower:]          Enlaza alguna letra minúscula
[:upper:]          Enlaza alguna letra mayúscula
```

## Ejemplos
- Muestra la información de cada objeto en el directorio actual.
``` bash 
[cesarlara-avila@c-lara~]$file *
...
EjerciciosR-2.tex:                      LaTeX 2e document, UTF-8 Unicode text, with very long lines
Ejer-R.Rnw:                             LaTeX 2e document, ASCII text
Ejer-R.tex:                             LaTeX 2e document, ASCII text
Entrada-SalidaR.ipynb:                  HTML document, UTF-8 Unicode text, with very long lines
Escritorio:                            directory
Estructuras-Programacion-R.ipynb:      UTF-8 Unicode text, with very long lines
Evaluacion-no-StandardR.pdf:           PDF document, version 1.4
Examen.txt:                            ASCII text
fglxr:                                 directory
file1:                                 ASCII text, with no line terminators
Funcion-Ejemplo10.R:                    ASCII text
.......
```
- Le decimos al comando `ls` que proporciones todos los nombres de los archivos en el actual directorio que tiene una extensión `.md`, `.R`, `.c`

```bash
[cesarlara-avila@c-lara~]$ls  *.md *.R *.c

acceptance-rejection.R   curvaC.R                   Funcion-Ejemplo1.R     funcion_numerica.c       Mbiseccion.R          rango_numerico.c  Soluciones Introductorio.md
Animation.R             Curva-koch.R                 Funcion-Ejemplo2.R     funcion_sierpinski.c  Mcd-Mcm.c           README copy.md    stadistic.R
args.c                  d-beta.R                     Funcion-Ejemplo3.R     gamma.c               method-dispatch.md  README.md         tabla-Z.R
bookDBrooks.c           d-geometrica.R               Funcion-Ejemplo4.R     getchar-putchar1.c    newton1.c           RNG.c             TLC.R
cadena.c                Ejemplo_llamadaReferencia.c  Funcion-Ejemplo5.R     getchar-putchar2.c    newton.c            roman.c           trapecio.c
camino-aleatorio1D.R    Ejemplo_llamadaValor.c       Funcion-Ejemplo6.R     getchar-putchar3.c    Notas-C.md          Roman-Numero.c    TutorialCLI.md
camino-aleatorio2D.R    Ejemplo-pandoc.md            Funcion-Ejemplo7.R     getchar-putchar.c     N-recycling.R       silabus-cm274.md
camino-aleatorio.R      Ejemplo.R                    Funcion-Ejemplo8.R     helecho.R             operaciones2.c      simplex1.R
combinatoria.c          Funcion-Ejemplo10.R          Funcion-Ejemplo9.R     juego-morra.R         potenciacion.c      simulacion.c
conversiones.c          Funcion-Ejemplo11.R          funcion_estadistica.c  make.md               Proceso-Poisson.R   Simul-CC.c

```

- Proporciona información acerca de todos los objetos que empiezan con la letra *a* y tiene 6 caracteres de longitud

```bash
[cesarlara-avila@c-lara~]$file a?????
args.c: C source, ASCII text
```
- Retorna una lista de archivos en el actual directorio de trabajo que tienen dos caracteres los archivos de extensión.

```bash
[cesarlara-avila@c-lara~]$ls *.??
Desigualdades-Probabilidad.synctex.gz  EjerciciosR-2.synctex.gz      Lista3-Ejercicios.synctex.gz  Notas-C.md               README.md                    TutorialCLI.md
Ejemplo-pandoc.md                      get-pip.py                    make.md                       Probabilidad.synctex.gz  silabus-cm274.md
Ejercicios-FuncionesC102.synctex.gz    Lista1-Ejercicios.synctex.gz  method-dispatch.md            README copy.md           Soluciones-Introductorio.md
```




## Creando directorios

El comando `mkdir` es usado para crear directorios. Y se usa de la siguiente manera, (los tres puntos, significan que el argumento puede ser repetido)

```
mkdir directorio...
```

Asi podemos crear un solo directorio o varios directorios

```
mkdir dir1
```

o

```
mkdir dir1 dir2 dir3
```


### Copiando archivos y directorios

El comando `cp` copia archivos o directorios. Puede ser usado de dos formas

```
cp item1 item2
```

para copiar el archivo  o directorio `item1` al archivo o directorio `item2` y

```
cp item ...directorio
```

para copiar múltiples ítems (archivo o directorios) en un directorio.

### Algunas opciones y ejemplos

Aquí algunas opciones para `cp`

```
   Opciones                     Significado
-a, --archive      Copia los archivos y directorios y todo sus atributos.
-i, --interactive  Antes de sobreescribir un archivo, se pide una confirmacion.
-r, --recursive   Recursivamente copia directorios y sus contenidos.
-u, --update      Al copiar archivos de un directorio a otro, solamente copia los archivos que, o bien no existen, o son más recientes que los existentes  en el directorio destino.
-v, --verbose     Muestra mensajes informativos, como que la copia se ha llevado a cabo.
```


## Ejemplo

### Creando Directorios

```bash
[cesarlara-avila@c-lara~]$cd
[cesarlara-avila@c-lara~]mkdir codigos
[cesarlara-avila@c-lara~]cd codigos
[cesarlara-avila@c-lara codigos]mkdir Python R  C Java
```

### Copiando Archivos

```bash
[cesarlara-avila@c-lara codigos]$ cp /home/cesarlara-avila/Documentos/Ejemplo.R .
[cesarlara-avila@c-lara codigos]$ cp /home/cesarlara-avila/Documentos/Ejemplo.Java .
[cesarlara-avila@c-lara codigos]$ cp /home/cesarlara-avila/Documentos/Ejemplo.c .
[cesarlara-avila@c-lara codigos]$ cp /home/cesarlara-avila/Documentos/Ejemplo.py .
[cesarlara-avila@c-lara codigos]$ ls -l
total 36
drwxrwxr-x 2 cesarlara-avila cesarlara-avila 4096 sep 30 22:06 C
drwxrwxr-x 2 cesarlara-avila cesarlara-avila 4096 sep 30 22:06 C++
-rw-rw-r-- 1 cesarlara-avila cesarlara-avila  820 sep 30 22:30 Ejemplo.c
-rw-rw-r-- 1 cesarlara-avila cesarlara-avila  135 sep 30 22:30 Ejemplo.Java
-rw-rw-r-- 1 cesarlara-avila cesarlara-avila  198 sep 30 22:30 Ejemplo.py
-rw-rw-r-- 1 cesarlara-avila cesarlara-avila  233 sep 30 22:28 Ejemplo.R
drwxrwxr-x 2 cesarlara-avila cesarlara-avila 4096 sep 30 22:06 Java
drwxrwxr-x 2 cesarlara-avila cesarlara-avila 4096 sep 30 22:06 Python
drwxrwxr-x 2 cesarlara-avila cesarlara-avila 4096 sep 30 22:06 R

# Ahora veamos una revisión de otros argumentos

[cesarlara-avila@c-lara codigos]$ cp -v /home/cesarlara-avila/Documentos/Ejemplo.py .
«/home/cesarlara-avila/Documentos/Ejemplo.py» -> «./Ejemplo.py»
[cesarlara-avila@c-lara codigos]$cp -i /home/cesarlara-avila/Documentos/Ejemplo.Java .
cp: ¿sobreescribir «./Ejemplo.Java»? (s/n) s
```

### Moviendo y Renombrando archivos

```bash
[cesarlara-avila@c-lara codigos]$ls
C  C++  Ejemplo.c  Ejemplo.Java  Ejemplo.py  Ejemplo.R  Java  Python  R
[cesarlara-avila@c-lara codigos]$mv Ejemplo.c C
[cesarlara-avila@c-lara codigos]$mv Ejemplo.py Python
[cesarlara-avila@c-lara codigos]$mv Ejemplo.R R
[cesarlara-avila@c-lara codigos]$mv Ejemplo.Java Java
[cesarlara-avila@c-lara codigos]$ls
C  C++  Java  Python  R
```



# Trabajando con Comandos

Los comandos pueden ser cualquiera de estos tipos

- `Un programa ejecutable` como los de `/usr/bin`. Dentro de esta categoria, los programas pueden ser `compilados binarios` tales como los programas en C y C++ o programas escritos en `lenguajes interpretados`` como perl, Python o Ruby.
-  `Un comando dentro del shell`. `bash` soporta un número de comandos internamente llamados `shell builtins`. El comando `cd` por ejemplo es un `shell builtins`.
-  Una `función del Shell` que son scripts de shell incorporados al `entorno (environment)`.
-  Un `alias` que son comandos que podemos definir, desde otros comandos propios del shell de Linux.


## Identificando comandos

### type- Mostrando un tipo de comando

El comando `type` muestra el tipo de comando que el shell ejecuta, dando un particular nombre.

```
type comando
```

donde `comando` es el nombre del comando que tu quieres analizar.

```bash
[cesarlara-avila@c-lara~]$type ls
ls is an alias for ls --color=tty
```

```bash
[cesarlara-avila@c-lara~]$type top
top is /usr/bin/top
```

```bash
[cesarlara-avila@c-lara~]$type cd 
cd is a shell builtin
```

### which - Muestra la localización de los programas ejecutables

`which` es un comando que muestra la localización de los archivos ejecutables, si se intenta otro tipo de comando se genera un error


```bash
[cesarlara-avila@c-lara~]$which cd
/bin/ls
```

### Documentación de Comandos

###  Consiguiendo ayuda para los shell builtins(ordenes internas)

Bash tiene un `help` para cada `shell builtins`. Para usar esto escribimos `help` seguido por el nombre de la orden interna del shell. Muchos programas ejecutables soportan la opción `--help` que muestra la descripción del comando y opciones


```
[cesarlara-avila@c-lara~]$grep --help
Uso: grep [OPCIÓN]... PATRÓN [ARCHIVO]...
Busca PATRÓN en cada FICHERO o en la entrada estándar.
PATRÓN es, por omisión, una expresión regular básica (BRE).
Ejemplo: grep -i 'hello world' menu.h main.c

Selección e interpretación de Expreg:
  -E, --extended-regexp     PATRÓN es una expresión regular extendida (ERE)
  -F, --fixed-strings       PATRÓN es un conjunto de cadenas separadas por
                            caracteres de nueva línea
  -G, --basic-regexp        PATRÓN es una expresión regular básica (BRE)
  -P, --perl-regexp         PATRÓN es una expresión regular en Perl
  -e, --regexp=PATRÓN       utiliza PATRÓN como expresión regular
  -f, --file=FICHERO        obtiene PATRÓN de FICHERO
  -i, --ignore-case         considera iguales mayúsculas y minúsculas
  -w, --word-regexp         obliga a que PATRÓN coincida solamente
                            con palabras completas
  -x, --line-regexp         obliga a que PATRÓN coincida solamente
                            con líneas completas
  -z, --null-data           una línea de datos termina en un byte 0, no
                            en un carácter de nueva línea

Variadas:
  -s, --no-messages         suprime los mensajes de error
  -v, --invert-match        selecciona las líneas que no coinciden
  -V, --version             muestra la versión y finaliza
      --help                muestra esta ayuda y finaliza
      --mmap                no hace nada y está obsoleta; da un aviso

Control del resultado:
  -m, --max-count=NÚM       se detiene después de NÚM coincidencias
  -b, --byte-offset         muestra el desplazamiento en bytes junto
                            con las líneas de salida
  -n, --line-number         muestra el número de línea junto con
                            las líneas de salida
      --line-buffered       descarga el resultado para cada línea
  -H, --with-filename       muestra el nombre del fichero para cada
                            coincidencia
  -h, --no-filename         suprime los nombres de los ficheros como prefijo
                            en el resultado
      --label=ETIQUETA      utiliza ETIQUETA como nombre de fichero prefijo
                            para la entrada estándar
  -o, --only-matching       muestra solamente la parte de una línea que
                            encaja con PATRÓN
  -q, --quiet, --silent     suprime todo el resultado normal
      --binary-files=TIPO   supone que los ficheros binarios son TIPO
                            TIPO es 'binary', 'text', o 'without-match'
  -a, --text                equivalente a --binary-files=text
  -I                        equivalente a --binary-files=without-match
  -d, --directories=ACCIÓN  especifica cómo manejar los directorios
                            ACCIÓN es 'read', 'recurse', o 'skip'
  -D, --devices=ACCIÓN      especifica cómo manejar dispositivos, FIFOs y
                            `sockets', puede ser 'read' o 'skip'
  -r, --recursive           equivalente a --directories=recurse
  -R, --dereference-recursive  similar, pero sigue todos los enlaces simbólicos
      --include=PATRÓN      examina los ficheros que encajan con PATRÓN
      --exclude=PATRÓN      se salta los ficheros que encajan con PATRÓN
      --exclude-from=FICHERO se salta los ficheros que encajan con los patrones
                             de FICHERO
      --exclude-dir=PATRÓN  se salta los directorios que encajan con PATRÓN
  -L, --files-without-match muestra solamente los nombres de FICHEROs
                            que no contienen ninguna coincidencia
  -l, --files-with-matches  muestra solamente los nombres de FICHEROs
                            que contienen alguna coincidencia
  -c, --count               muestra solamente el total de líneas que coinciden
                            por cada FICHERO
  -Z, --null                imprime un byte 0 después del nombre del FICHERO

Control del contexto:
  -B, --before-context=NÚM  muestra NÚM líneas de contexto anterior
  -A, --after-context=NÚM   muestra NÚM líneas de contexto posterior
  -C, --context=NÚM         muestra NÚM líneas de contexto
  -NÚM                      lo mismo que --context=NÚM
      --color[=CUÁNDO],
      --colour[=CUÁNDO]     distingue con marcadores la cadena que encaja
                            CUÁNDO puede ser 'always', 'never' o 'auto'.
  -U, --binary              no elimina los caracteres de retorno de carro
                            finales de línea (MSDOS/Windows)
  -u, --unix-byte-offsets   cuenta los desplazamientos como si no hubiera
                            retornos de carro (MSDOS/Windows)

'egrep' significa 'grep -E'.  'fgrep' significa 'grep -F'.
La invocación directa como 'egrep' o 'fgrep' está obsoleta.
Cuando FICHERO es -, lee la entrada estándar.  Si no se especifica
ningún FICHERO, lee . si se especifica -r en la línea de órdenes, o -
en caso contrario.  Si se dan menos de dos FICHEROs, se supone -h. El
estado de salida es 0 si hay coincidencias, 1 si no las hay; si ocurre
algún error y no se especificó -q, el estado de salida es 2.

Comunicar errores en el programa a: bug-grep@gnu.org
Página inicial de GNU grep: <http://www.gnu.org/software/grep/>
Ayuda general sobre el uso de software de GNU: <http://www.gnu.org/gethelp/>
```
### man -Muestra la página del Manual de los programas

Muchos programas  ejecutables usan línea de comandos para mostrar  documentación, llamada `manual` o `man page`. Para este fin, se usa un programa llamado `man` y que se puede utilizar de la siguiente manera:

```
man programa
```
```bash
[cesarlara-avila@c-lara~]$man less
```

El manual que `man` muestra es dividido en secciones y no solo cubre comandos de usuarios sino también comandos de sistemas de administración, archivos de formato, etc. La organización de la página mostrada por `man` es

```
Sección               Contenido
   1             Comandos de usuario
   2             Llamadas de interfaces de programación del kernel
   3             Programación de interfaces para la biblioteca C
   4             Archivos especiales tales como nodos y controladores de  dispositivos
   5             Formatos de archivos
   6             Juegos y entretenimientos tales como protectores de pantalla
   7             Miscélanea
   8             Comandos de administración de sistema
```

Un ejemplo de esto es el siguiente que muestra los formatos del archivo `/etc/passwd`.

```bash
[cesarlara-avila@c-lara~]$man 5 passwd
```

### apropos-Muestra los comandos apropiados

También es posible buscar en la lista de páginas de `man` para posibles coincidencias de un término que estamos buscando.He aquí un ejemplo de una búsqueda en las páginas de `man` utilizando el término de búsqueda `gcc`.

```bash
[cesarlara-avila@c-lara~]$apropos gcc
c89-gcc (1)          - ANSI (1989) C compiler
c99-gcc (1)          - ANSI (1999) C compiler
gcc (1)              - GNU project C and C++ compiler
gcc-4.8 (1)          - GNU project C and C++ compiler
i686-linux-gnu-gcc-ar-4.8 (1) - a wrapper around ar adding the - plugin option
gcc-ar-4.8 (1)       - a wrapper around ar adding the - plugin option
i686-linux-gnu-gcc-nm-4.8 (1) - a wrapper around nm adding the - plugin option
gcc-nm-4.8 (1)       - a wrapper around nm adding the - plugin option
i686-linux-gnu-gcc-ranlib-4.8 (1) - a wrapper around ranlib adding the - plugin option
gcc-ranlib-4.8 (1)   - a wrapper around ranlib adding the - plugin option
i686-linux-gnu-gcc (1) - GNU project C and C++ compiler
i686-linux-gnu-gcc-4.8 (1) - GNU project C and C++ compiler
```

El  primer campo en la línea de salida es el nombre de la página de `man`, el segundo campo muestra la sección. `man` con la opción `k` lleva a cabo la misma función que `apropos`.

### whatis - Muestra una breve descripción de un comando.

`whatis` muestra el nombre y una línea de descripción de la página de  `man` del término buscado

```bash
[cesarlara-avila@c-lara~]$whatis make
make (1)             - GNU make utility to maintain groups of programs
```

### README y otros archivos de documentación de programas

Muchos paquetes de software instalados en el sistema tienen archivos de documentación que residen en el directorio `/usr/share/doc`. La mayoría de éstos se almacenan en formato de texto plano y puede ser visto con `less`. Algunos de los archivos están en formato HTML y se puede ver con un navegador web. 
Podemos encontrar algunos archivos que terminan con la extensión `".gz"`, esto indica que se han comprimido con el programa de compresión `gzip`. El paquete gzip incluye una versión especial de `less` llamado `zless` que muestra el contenido del archivo comprimido `gzip`.

## Usando `alias`

Es posible colocar más de un comando en una sóla línea separando los comandos por un punto y coma:

```
comando1; comando2; comando3...
```

Un ejemplo de esto es el siguiente

```bash
[cesarlara-avila@c-lara~]$cd /usr; ls; cd -
bin  games  include  lib  local  sbin  share  src
~
```

La primera cosa que debemos hacer para usar `alias`  es inventar un nombre, para ello usamos el comando `type`

```bash
[cesarlara-avila@c-lara~]$type mili
mili not found
```
 Tomamos `mili` para crear nuestro alias:

```bash
[cesarlara-avila@c-lara~]$alias mili='cd /usr; ls; cd -'
```
Notemos la estructura del comando

```
alias  nombre ='cadena'
```

Probemos lo que hemos hecho en el terminal

```bash
[cesarlara-avila@c-lara~]$mili
bin  games  include  lib  local  sbin  share  src
~
```

Podemos usar el comando `type` otra vez nuestro alias

```bash
[cesarlara-avila@c-lara~]$mili
mili is an alias for cd /usr; ls; cd -
```

Para remove un alias, usamos el comando `unalias`, de la siguiente forma

```bash
[cesarlara-avila@c-lara~]$unalias mili
[cesarlara-avila@c-lara~]$type mili
mili not found
```

A menudo un comando conocido es  usado como un alias para agregar una opción común de ese comando, por ejemplo  `ls` es un alias del comando con una opción de  soporte de color

```bash
[cesarlara-avila@c-lara~]$type ls
ls is an alias for ls --color=tty
```

Para ver todos los alias definidos en el `entorno`, utilice el comando alias, sin argumentos. Un buen ejercicio es ver lo que ellos hacen.

```bash
[cesarlara-avila@c-lara~]$alias
...=../..
....=../../..
.....=../../../..
......=../../../../..
1='cd -'
2='cd -2'
3='cd -3'
4='cd -4'
5='cd -5'
6='cd -6'
7='cd -7'
8='cd -8'
9='cd -9'
_=sudo
afind='ack-grep -il'
d='dirs -v | head -10'
g=git
ga='git add'
gaa='git add --all'
gapa='git add --patch'
gb='git branch'
gba='git branch -a'
gbda='git branch --merged | command grep -vE "^(\*|\s*master\s*$)" | command xargs -n 1 git branch -d'
gbl='git blame -b -w'
gbnm='git branch --no-merged'
gbr='git branch --remote'
gbs='git bisect'
gbsb='git bisect bad'
gbsg='git bisect good'
gbsr='git bisect reset'
gbss='git bisect start'
gc='git commit -v'
'gc!'='git commit -v --amend'
gca='git commit -v -a'
'gca!'='git commit -v -a --amend'
gcam='git commit -a -m'
'gcan!'='git commit -v -a -s --no-edit --amend'
gcb='git checkout -b'
gcf='git config --list'
gcl='git clone --recursive'
gclean='git clean -fd'
gcm='git checkout master'
gcmsg='git commit -m'
gco='git checkout'
gcount='git shortlog -sn'
gcp='git cherry-pick'
gcs='git commit -S'
gd='git diff'
gdca='git diff --cached'
gdt='git diff-tree --no-commit-id --name-only -r'
gdw='git diff --word-diff'
gf='git fetch'
gfa='git fetch --all --prune'
gfo='git fetch origin'
gg='git gui citool'
gga='git gui citool --amend'
ggpull='git pull origin $(current_branch)'
ggpur=ggu
ggpush='git push origin $(current_branch)'
ggsup='git branch --set-upstream-to=origin/$(current_branch)'
gignore='git update-index --assume-unchanged'
gignored='git ls-files -v | grep "^[[:lower:]]"'
git-svn-dcommit-push='git svn dcommit && git push github master:svntrunk'
gk='\gitk --all --branches'
gke='\gitk --all $(git log -g --pretty=format:%h)'
gl='git pull'
glg='git log --stat --color'
glgg='git log --graph --color'
glgga='git log --graph --decorate --all'
glgm='git log --graph --max-count=10'
glgp='git log --stat --color -p'
glo='git log --oneline --decorate --color'
globurl='noglob urlglobber '
glog='git log --oneline --decorate --color --graph'
glol='git log --graph --pretty=format:'\''%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset'\'' --abbrev-commit'
glola='git log --graph --pretty=format:'\''%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset'\'' --abbrev-commit --all'
glp=_git_log_prettily
gm='git merge'
gmom='git merge origin/master'
gmt='git mergetool --no-prompt'
gmtvim='git mergetool --no-prompt --tool=vimdiff'
gmum='git merge upstream/master'
gp='git push'
gpd='git push --dry-run'
gpoat='git push origin --all && git push origin --tags'
gpristine='git reset --hard && git clean -dfx'
gpu='git push upstream'
gpv='git push -v'
gr='git remote'
gra='git remote add'
grb='git rebase'
grba='git rebase --abort'
grbc='git rebase --continue'
grbi='git rebase -i'
grbm='git rebase master'
grbs='git rebase --skip'
grep='grep  --color=auto --exclude-dir={.bzr,.cvs,.git,.hg,.svn}'
grh='git reset HEAD'
grhh='git reset HEAD --hard'
grmv='git remote rename'
grrm='git remote remove'
grset='git remote set-url'
grt='cd $(git rev-parse --show-toplevel || echo ".")'
gru='git reset --'
grup='git remote update'
grv='git remote -v'
gsb='git status -sb'
gsd='git svn dcommit'
gsi='git submodule init'
gsps='git show --pretty=short --show-signature'
gsr='git svn rebase'
gss='git status -s'
gst='git status'
gsta='git stash'
gstaa='git stash apply'
gstd='git stash drop'
gstl='git stash list'
gstp='git stash pop'
gsts='git stash show --text'
gsu='git submodule update'
gts='git tag -s'
gunignore='git update-index --no-assume-unchanged'
gunwip='git log -n 1 | grep -q -c "\-\-wip\-\-" && git reset HEAD~1'
gup='git pull --rebase'
gupv='git pull --rebase -v'
gvt='git verify-tag'
gwch='git whatchanged -p --abbrev-commit --pretty=medium'
gwip='git add -A; git rm $(git ls-files --deleted) 2> /dev/null; git commit -m "--wip--"'
history='fc -l 1'
l='ls -lah'
la='ls -lAh'
ll='ls -lh'
ls='ls --color=tty'
lsa='ls -lah'
md='mkdir -p'
please=sudo
po=popd
pu=pushd
rd=rmdir
which-command=whence

```

Hay un pequeño problema con la definición de alias en la línea de comandos. Ellos desaparecen cuando finalizas una sesión en el shell.

