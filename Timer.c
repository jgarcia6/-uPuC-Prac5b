#define INTR 8 /* Utilizar el vector adecuado */

volatile static unsigned char SecFlag; /*Bandera para indicar el Seg. */

/* Manejador de Interrupcion: ocurre 20 veces por segundo */
void interrupt ManejadorISR( void ){
    static unsigned char Cont = 0;
    Cont++; /* Conteo de Ticks */
    if(Cont == 20)
    {
        SecFlag=1;
        Cont = 0;
    }
} 

unsigned char TimerSecFlag( void )
{
    if( SecFlag == 1 )
    {
        SegFlag = 0;
        return 1;
    }
    else
    {
        return 0;
    }
} 

void Timer_Ini( void ){
    SecFlag=0;
    /* Inicializarvector --faltapokeW(WORD segment, WORD offset, WORD value) -- */
    pokeW(0x0,INTR*4,offset de la ISR); /* Determinar offset */
    pokeW(0x0,INTR*4+2,_CS);
}