#include <stdio.h>
#include <conio.h>
#include <windows.h>

void main()
{
    long inicio, final;

    inicio = GetTickCount();
    printf("Presiona una tecla...");   
    getch();
    final = GetTickCount();   
    printf("Has tardado %ld milisegundos...", final-inicio);
}
