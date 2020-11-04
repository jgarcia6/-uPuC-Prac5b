#define BYTE unsigned char
#define WORD unsigned int
#define PA 0x40
#define PB 0x41
#define PC 0x42
#define RCtr 0x43
#define PTOs_all_out 0x80

// To be define in ASM file
extern void outportb(WORD port, BYTE data);
extern BYTE inportb(WORD port);

// Prototypes
void SetBitPort(WORD Puerto, BYTE num_bit);
void ClrBitPort(WORD Puerto, BYTE num_bit);
void NotBitPort(WORD Puerto, BYTE num_bit);
BYTE TstBitPort(WORD Puerto, BYTE num_bit);
void ReverseBitsPort(WORD Puerto);

char dato;

void main( void )
{
    puts(“Practica 5b\n\r”); /* imprimir mensaje */
    outportb(RCtr, PTOs_all_out); /* inicializar 8255 */
    outportb(PA,0x55); /* presentar 55h en el Pto A */
    while(1)
    {
        dato = getch(); /* leer tecla */
        outportb(PB,dato); /* presentar tecla en PB */
        printBin(dato);
        puts(“\n\r”);
    }
}

/* función para lectura de puertos usando ensamblador in-line */
void outportb( WORD port, BYTE dato)
{
    asm mov dx, port
    asm mov al, dato
    asm out dx, al
}

/* función simple para desplegar un byte en formato binario */
void printBin( BYTE dato )
{
    BYTE msk=0x80;
    do{
        putchar( (dato & msk) ? '1' : '0' );
        msk>>=1;
    }while( msk );
}