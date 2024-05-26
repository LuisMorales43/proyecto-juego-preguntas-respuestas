# Objetivo predeterminado: compilar y ejecutar el programa
all: juego_preguntas_debug.bin

# Compilar el programa final enlazando los archivos objeto de C y ASM
juego_preguntas_debug.bin: main.o comparar_respuesta.o
	gcc -g -o juego_preguntas_debug.bin main.o comparar_respuesta.o -no-pie

# Compilar el archivo fuente de C en un archivo objeto
main.o: main.c
	gcc -c main.c -o main.o

# Compilar el archivo fuente de ASM en un archivo objeto
comparar_respuesta.o: comparar_respuesta.asm
	nasm -f elf64 -o comparar_respuesta.o comparar_respuesta.asm

# Limpiar los archivos compilados y el ejecutable
clean:
	rm -f *.o juego_preguntas_debug.bin
