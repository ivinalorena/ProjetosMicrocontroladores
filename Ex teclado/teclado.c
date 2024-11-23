#include <16f877.h>

#fuses xt, nowdt,noprotect,put,brownout,nolvp,nocpd,nowrt

#use delay(clock=4000000)

//Definicao da Matriz do teclado
#define COL1   pin_c4
#define COL2   pin_c5
#define COL3   pin_c6
#define LIN1   pin_c3
#define LIN2   pin_c2
#define LIN3   pin_c1
#define LIN4   pin_c0

void main()
{
while (true)
{
   int tecla;


   output_high(COL1); //Ativa primeira coluna
   output_low(COL2);
   output_low(COL3);

   if (input(LIN1)) tecla = 1;
   if (input(LIN2)) tecla = 4;
   if (input(LIN3)) tecla = 7;
   if (input(LIN4)) tecla = 10;

   output_low(COL1);
   output_high(COL2);  //Ativa segunda coluna
   output_low(COL3);

   if (input(LIN1)) tecla = 2;
   if (input(LIN2)) tecla = 5;
   if (input(LIN3)) tecla = 8;
   if (input(LIN4)) tecla = 0;

   output_low(COL1);
   output_low(COL2);
   output_high(COL3);   //Ativa terceira coluna

   if (input(LIN1)) tecla = 3;
   if (input(LIN2)) tecla = 6;
   if (input(LIN3)) tecla = 9;
   if (input(LIN4)) tecla = 11;

   output_d(tecla);

   }

}
