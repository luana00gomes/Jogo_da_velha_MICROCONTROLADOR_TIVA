# Jogo_da_velha_MICROCONTROLADOR_TIVA
Jogo da velha desenvolvido em C com quite de desenvolvimento TIVA C Series da Texas Instruments. O jogo pode ser jogado através do microcontrolador e com um display NOKIA.

<h1> Como compilar e rodar</h1>

1. Baixe e instale o programa Code Composer Studio <https://software-dl.ti.com/ccs/esd/documents/ccs_downloads.html>
2. Tenha um microcontrolador TIVA C series tm4c123gh6pm
3. Tenha um display NOKIA 5110
4. Conecte seu microcontrolador ao display conforme as instruções abaixo

<h5>
======================== PINS ========================
    Blue Nokia 5110
    -------------------------------------------
    Signal        (Nokia 5110) LaunchPad pin
    -------------------------------------------
    Reset         (RST, pin 1) connected to PA7
    SSI0Fss       (CE,  pin 2) connected to PA3
    Data/Command  (DC,  pin 3) connected to PA6
    SSI0Tx        (Din, pin 4) connected to PA5
    SSI0Clk       (Clk, pin 5) connected to PA2
    3.3V          (Vcc, pin 6) power
    back light    (BL,  pin 7) not connected
    Ground        (Gnd, pin 8) ground
//////////////////////////////////////////////////////
    Red SparkFun Nokia 5110 (LCD-10168)
    --------------------------------------------
    Signal        (Nokia 5110) LaunchPad pin
    --------------------------------------------
    3.3V          (VCC, pin 1) power
    Ground        (GND, pin 2) ground
    SSI0Fss       (SCE, pin 3) connected to PA3
    Reset         (RST, pin 4) connected to PA7
    Data/Command  (D/C, pin 5) connected to PA6
    SSI0Tx        (DN,  pin 6) connected to PA5
    SSI0Clk       (SCLK, pin 7) connected to PA2
    back light    (LED, pin 8) not connected
======================================================
</h5>

5. Tendo baixado o diretório deste código, abra-o no Code Composer
6. No Code Composer, clique em Build para compilar o programa e em Flash para carregá-lo no microcontrolador

<h1> Jogando </h1>
1. Use o Switch 1 do seu microcontrolador para mover entre as casas
2. Use o Switch 2 para marcar sua posição