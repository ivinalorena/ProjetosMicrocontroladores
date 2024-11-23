#include <16f628a.h>
#use delay(clock=4000000)
#fuses INTRC_IO,NOWDT,PUT,BROWNOUT,NOLVP,NOMCLR

#define SEMAPHORE1_LED_RED PIN_B0
#define SEMAPHORE1_LED_YELLOW PIN_B1
#define SEMAPHORE1_LED_GREEN PIN_B2

#define SEMAPHORE2_LED_RED PIN_B3
#define SEMAPHORE2_LED_YELLOW PIN_B4
#define SEMAPHORE2_LED_GREEN PIN_B5

#define BUTTON_PIN PIN_B6

void main() {
    //setup_adc_ports(NO_ANALOGS);  // Configura todos os pinos como digitais
    //setup_adc(ADC_OFF);            // Desliga o módulo ADC
    setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8); // Configura timer 0
    set_timer0(0);                 // Zera o timer 0
    
    output_low(SEMAPHORE1_LED_RED);
    output_low(SEMAPHORE1_LED_YELLOW);
    output_low(SEMAPHORE1_LED_GREEN);
    
    output_low(SEMAPHORE2_LED_RED);
    output_low(SEMAPHORE2_LED_YELLOW);
    output_low(SEMAPHORE2_LED_GREEN);
    
    output_high(BUTTON_PIN); // Habilita pull-up interno
    
    while(TRUE) {
        // Verifica se o botão foi pressionado
        if(input(BUTTON_PIN) == 0) {
            // Botão pressionado, ativa o semáforo 1
            output_high(SEMAPHORE1_LED_GREEN);
            delay_ms(1000); // Aguarda 6 segundos
            
            output_low(SEMAPHORE1_LED_GREEN);
            output_high(SEMAPHORE1_LED_YELLOW);
            delay_ms(2000); // Aguarda 3 segundos
            
            output_low(SEMAPHORE1_LED_YELLOW);
            output_high(SEMAPHORE1_LED_RED);
            delay_ms(1000); // Aguarda 6 segundos
            
            output_low(SEMAPHORE1_LED_RED);
            
            // Ativa o semáforo 2
            output_high(SEMAPHORE2_LED_GREEN);
            delay_ms(1000); // Aguarda 6 segundos
            
            output_low(SEMAPHORE2_LED_GREEN);
            output_high(SEMAPHORE2_LED_YELLOW);
            delay_ms(1000); // Aguarda 3 segundos
            
            output_low(SEMAPHORE2_LED_YELLOW);
            output_high(SEMAPHORE2_LED_RED);
            delay_ms(1000); // Aguarda 6 segundos
            
            output_low(SEMAPHORE2_LED_RED);
        }
    }
}

