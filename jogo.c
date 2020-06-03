#include "jogo.h"
#include <time.h>
#include <stdlib.h>
#include "bitmap.h"

void inicia(void)
{
    volatile uint32_t ui32Loop; //O qualificador volatile impede que a variável sofra otimização, obrigando o programa a reler o valor da variável em véz de usar valores armazanados de registradores
                                //Útil para evitar que mudanças feitas fora do escopo da função sejam perdidas

    Nokia5110_Init();
    Nokia5110_Clear();
    Nokia5110_DrawFullImage(bem_vindo);

    for (ui32Loop = 0; ui32Loop < 2000000; ui32Loop++)
    { //delay de +- 2s
    }

    Nokia5110_Clear();
    Nokia5110_DrawFullImage(jogo_velha);
    for (ui32Loop = 0; ui32Loop < 2050000; ui32Loop++)
    { //delay de +- 2s
    }

    Nokia5110_Clear();
    Nokia5110_DrawFullImage(select);

    for (ui32Loop = 0; ui32Loop < 2050000; ui32Loop++)
    { //delay de +- 2s
    }
}

void partida(void)
{
    int ocupado[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //Posições ocupadas na matriz
    char M[9]; //
    int j = 0;

    SysCtlClockSet(
            SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //Habilita o portal F
    //desbloquear SW2(pin 0) e interrupcao botao
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;
    //define como input
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0,
                     GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4 | GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

    int variavel = 0;
    srand(time(NULL));
    while (1)
    {

        if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) != GPIO_PIN_4)
                && variavel == 20)
        { //SW1 1 APERTADO: SELECIONA X
            Nokia5110_Clear();
            Nokia5110_DrawFullImage(tabuleiro);
            Nokia5110_SetCursor(2, 10);
            Nokia5110_OutString("L,C");
            Nokia5110_SetCursor(2, 15);
            Nokia5110_OutString("1,1");

            while (j < 5)
            {
                //MOVIMENTO PLAYER
                int aux = 1;
                int position = 0;
                int v = 0;
                while (aux)
                {
                    if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) != GPIO_PIN_4)
                            && v == 200)
                    {
                        position++;

                        switch ((position % 9))
                        {
                        case (0):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("1,1");

                            break;
                        case (1):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("1,2");
                            break;
                        case (2):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("1,3");
                            break;
                        case (3):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("2,1");
                            break;
                        case (4):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("2,2");
                            break;
                        case (5):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("2,3");
                            break;
                        case (6):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("3,1");
                            break;
                        case (7):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("3,2");
                            break;
                        case (8):
                            Nokia5110_SetCursor(2, 15);
                            Nokia5110_OutString("3,3");
                            break;

                        }

                    }
                    if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) != GPIO_PIN_0)
                            && v == 200)
                    {
                        int x = (position % 9);

                        switch (x)
                        {
                        case (0):
                            Nokia5110_SetCursor(30, 10);
                            break;
                        case (1):
                            Nokia5110_SetCursor(45, 10);
                            break;
                        case (2):
                            Nokia5110_SetCursor(65, 10);
                            break;
                        case (3):
                            Nokia5110_SetCursor(30, 20);
                            break;
                        case (4):
                            Nokia5110_SetCursor(45, 20);
                            break;
                        case (5):
                            Nokia5110_SetCursor(65, 20);
                            break;
                        case (6):
                            Nokia5110_SetCursor(30, 25);
                            break;
                        case (7):
                            Nokia5110_SetCursor(45, 25);
                            break;
                        case (8):
                            Nokia5110_SetCursor(65, 25);
                            break;

                        }
                        ocupado[x] = 1;
                        Nokia5110_OutString("X");
                        aux = 0;
                        j++;
                        position = 0;
                        M[x] = 'X';
                    }
                    if (v > 200)
                    {
                        v = 0;
                    }
                    v++;
                    SysCtlDelay(20000);

                }
                win(M, 'X');

                //MOVIMENTO COMPUTADOR

                int x = rand() % 9;
                setaPosicao(ocupado, x);
                Nokia5110_OutString("O");

                ocupado[x] = 1;
                M[x] = 'O';
                win(M, 'X');
            }
            //  char x ="X";
            //win(M, "X");
            Nokia5110_Clear();
            Nokia5110_OutString("Empate!");

        }
        if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) != GPIO_PIN_0)
                && variavel == 20)
        { //SW1 2 APERTADO: SELECIONA O
            Nokia5110_Clear();
            Nokia5110_DrawFullImage(tabuleiro);
            while (j < 5)
            {
                playerMov(ocupado, 'O');
                machineMov(ocupado, 'X');
            }
        }
        if (variavel > 20)
        {
            variavel = 0;
        }
        variavel++;
        SysCtlDelay(20000);
    }
}

void run(void)
{
    inicia();
    partida();
}

void playerMov(int *ocupado, char peca)
{
    /*
     int aux=1;
     int position=0;

     Nokia5110_Clear();
     Nokia5110_DrawFullImage(tabuleiro);
     int variavel = 0;

     while(aux){

     if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) != GPIO_PIN_4) && variavel == 20){
     position++;
     Nokia5110_OutChar("A");
     }
     if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) != GPIO_PIN_0) && variavel == 20){
     int x = (position%9);

     switch (x){
     case (0):
     Nokia5110_SetCursor(30, 10);
     case (1):
     Nokia5110_SetCursor(45, 10);
     case (2):
     Nokia5110_SetCursor(65, 10);
     case (3):
     Nokia5110_SetCursor(30, 20);
     case (4):
     Nokia5110_SetCursor(45, 20);
     case (5):
     Nokia5110_SetCursor(65, 20);
     case (6):
     Nokia5110_SetCursor(30, 25);
     case (7):
     Nokia5110_SetCursor(45, 25);
     case (8):
     Nokia5110_SetCursor(65, 25);

     }
     ocupado[x]=1;
     Nokia5110_OutChar(peca);
     aux=0;
     }
     if(variavel>20){variavel = 0;}
     variavel++;
     SysCtlDelay(1000);

     }
     */
}

void machineMov(int *ocupado, char peca)
{/*
 int x= rand() % 9;
 setaPosicao(ocupado, x);
 Nokia5110_OutChar(peca);

 ocupado[x]=1;
 */
}

void setaPosicao(int *ocupado, int x)
{
    x = x % 9;
    if (ocupado[x] == 0)
    {
        switch (x)
        {
        case (0):
            Nokia5110_SetCursor(30, 10);
            break;
        case (1):
            Nokia5110_SetCursor(45, 10);
            break;
        case (2):
            Nokia5110_SetCursor(65, 10);
            break;
        case (3):
            Nokia5110_SetCursor(30, 20);
            break;
        case (4):
            Nokia5110_SetCursor(45, 20);
            break;
        case (5):
            Nokia5110_SetCursor(65, 20);
            break;
        case (6):
            Nokia5110_SetCursor(30, 25);
            break;
        case (7):
            Nokia5110_SetCursor(45, 25);
            break;
        case (8):
            Nokia5110_SetCursor(65, 25);
            break;

        }
    }
    else
    {
        setaPosicao(ocupado, x + 1);
    }
}

void botao1()
{
    int variavel = 0;

    while (1)
    {
        if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) != GPIO_PIN_0)
                && variavel == 20)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xFF);
        }
        if (variavel > 20)
        {
            variavel = 0;
        }
        variavel++;
        SysCtlDelay(1000);
    }
}

void botao2()
{
    int variavel = 0;

    while (1)
    {
        if ((GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0) != GPIO_PIN_0)
                && variavel == 20)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xFF);
        }
        if (variavel > 20)
        {
            variavel = 0;
        }
        variavel++;
        SysCtlDelay(1000);
    }
}

void win(char M[9], char x)
{
    int i = 0;
    int j = 0;
    char v[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            v[i][j] = M[i * 3 + j];
        }
    }

    //ler todas as posições da matriz
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                //caso em que a vitória ocorre nas colunas.
                if ((v[i][j] == v[i + 1][j]) && (v[i + 1][j] == v[i + 2][j]))
                {
                    if (x == v[i][j])
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce ganhou!");
                    }
                    else
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce perdeu!");
                    }
                    break;
                }
            }
            else
            {
                if (j == 0)
                {
                    //caso em que a vitória ocorre nas linhas.
                    if ((v[i][j] == v[i][j + 1])
                            && (v[i][j + 1] == v[i][j + 2]))
                    {
                        if (x == v[i][j])
                        {
                            Nokia5110_Clear();
                            Nokia5110_OutString("Voce ganhou!");
                        }
                        else
                        {
                            Nokia5110_Clear();
                            Nokia5110_OutString("Voce perdeu!");
                        }
                        break;
                    }

                }
            }

            if (i == j)
            {
                //caso em que a vitória ocorre na diagonal principal.
                if ((v[i][j] == v[i + 1][j + 1])
                        && (v[i + 1][j + 1] == v[i + 2][j + 2]))
                {
                    if (x == v[i][j])
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce ganhou!");
                    }
                    else
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce perdeu!");
                    }
                    break;
                }

            }
            if (i == j && j == 1)
            {
                //caso em que a vitória ocorre na diagonal secundária
                if ((v[i - 1][j + 1] == v[i, j])
                        && (v[i][j] == v[i + 1][j - 1]))
                {
                    if (x == v[i][j])
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce ganhou!");
                    }
                    else
                    {
                        Nokia5110_Clear();
                        Nokia5110_OutString("Voce perdeu!");
                    }
                    break;
                }
            }
        }
    }

}
