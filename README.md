# Jogo_da_velha_MICROCONTROLADOR_TIVA
Jogo da velha desenvolvido em C com quite de desenvolvimento TIVA C Series da Texas Instruments. O jogo pode ser jogado através do microcontrolador e com um display NOKIA.

<h2> Como compilar e rodar</h2>

1. Baixe e instale o programa Code Composer Studio <https://software-dl.ti.com/ccs/esd/documents/ccs_downloads.html>
2. Tenha um microcontrolador TIVA C series tm4c123gh6pm
3. Tenha um display NOKIA 5110
4. Conecte seu microcontrolador ao display conforme as instruções abaixo

<h5>
===================== PINS ====================  <br>
    Blue Nokia 5110 					<br>
    ------------------------------------------- 	<br>
    Signal        (Nokia 5110) LaunchPad pin 		<br>
    -------------------------------------------		<br>
    Reset         (RST, pin 1) connected to PA7 	<br>
    SSI0Fss       (CE,  pin 2) connected to PA3 	<br>
    Data/Command  (DC,  pin 3) connected to PA6 	<br>
    SSI0Tx        (Din, pin 4) connected to PA5 	<br>
    SSI0Clk       (Clk, pin 5) connected to PA2		<br>
    3.3V          (Vcc, pin 6) power 			<br>
    back light    (BL,  pin 7) not connected 		<br>
    Ground        (Gnd, pin 8) ground 			<br>
///////////////////////////////////////////////		<br>
    Red SparkFun Nokia 5110 (LCD-10168)			<br>
    --------------------------------------------	<br>
    Signal        (Nokia 5110) LaunchPad pin		<br>
    --------------------------------------------	<br>
    3.3V          (VCC, pin 1) power			<br>
    Ground        (GND, pin 2) ground			<br>
    SSI0Fss       (SCE, pin 3) connected to PA3		<br>
    Reset         (RST, pin 4) connected to PA7		<br>
    Data/Command  (D/C, pin 5) connected to PA6		<br>
    SSI0Tx        (DN,  pin 6) connected to PA5		<br>
    SSI0Clk       (SCLK, pin 7) connected to PA2	<br>
    back light    (LED, pin 8) not connected		<br>
================================================	<br>
</h5>

5. Tendo baixado o diretório deste código, abra-o no Code Composer
6. No Code Composer, clique em Build para compilar o programa e em Flash para carregá-lo no microcontrolador

<h2> Jogando </h2>

1. Use o Switch 1 do seu microcontrolador para mover entre as casas
2. Use o Switch 2 para marcar sua posição
