#include<18f4550.h>
#fuses HS,NOMCLR,NOWDT
#use delay(clock=20MHZ)

#include<lcd.c>

void main () {

    lcd_init();
    
    printf(LCD_PUTC,"UNILAB");
    delay_ms(1000);
    printf(LCD_PUTC,"\nENGENHARIA ");
    
}
