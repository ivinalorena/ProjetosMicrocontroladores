
#include <16f628a.h>
#use delay(clock=400000)
#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR,XT

void main () {

   output_high(pin_b0); //acende o led vermelho
 output_low(pin_b1); //apaga o led amarelo
 output_low(pin_b2); //apaga o led verde
  delay_ms(6000); //espera 6s
  
 output_low(pin_b0); //apaga o led vermelho
 output_high(pin_b2); //acente o led verde
  delay_ms(4000); //espera 4s

 output_low(pin_b2); //apaga o led verde
 output_high(pin_b1); //acente o led amarelo
  delay_ms(3000); //espera 3
  
 output_low(pin_b1);
  output_high(pin_b0);
   
  //SEGUNDO SEMAFORO b0 = b3// b1 = b4 //e o b2=b5
 
  output_high(pin_b5); //acende o led verde
 output_low(pin_b4); //apaga o led amarelo
 output_low(pin_b3); //apaga o led vermelho
  delay_ms(6000); //espera 6s
  
 output_low(pin_b5); //apaga o led verde
 output_high(pin_b3); //acente o led vermelho
  delay_ms(4000); //espera 4s

 output_low(pin_b3); //apaga o led vermelho
 output_high(pin_b4); //acente o led amarelo
  delay_ms(3000); //espera 3
  
 output_low(pin_b4);
  output_high(pin_b5);
  
}

