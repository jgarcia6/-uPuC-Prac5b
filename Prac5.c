#include "Timer.h"

#define BYTE unsigned char

void UpdateClock( void );
void DisplayClock( void );
void PrintDec2d( BYTE );
void Delay( BYTE );

BYTE seg=0; /* para el manejo de los segundos */

void main()
{
    Timer_Ini(); /* inicialzaTimer de 1 segundo */
    while(1)
    {
        /* Verificación para actualizar el reloj */
        if(TimerSecFlag() )
        { /* Ha pasado un segundo? */
            UpdateClock(); /* actualiza y muestra el reloj */
            DisplayClock(); /* desplegar reloj en 0,0 */
            /* indicar en puerto */
        }
        /* otras cosas por hacer */
        Delay(100);
        putchar('.'); /* Imprime */
    }
}

void UpdateClock( void )
{
    seg=(++seg%60);
    /*falta minutos , horas etc. etc. */
} 

void DisplayClock( void )
{
    /* imprimir reloj en formato "hh:mm:ss" */;
    PrintDec2d(seg); /* solo se esta desplegando segundos */
} 

void Delay( BYTE i)
{
    while(--i);
} 

void PrintDec2d( BYTE dato)
{
    putchar( dato/10 +'0'); /* Imprime decenas */
    putchar( dato%10 +'0'); /* Imprime unidades */
}