/**
 * @file Activity4.c
 * @author Daman (damanpreet@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

/**
 * @brief Initialize UART
 * 
 * @param ubrr_value 
 */
void init_uart(uint16_t ubrr_value)
{
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}
/**
 * @brief Read values from sensor
 * 
 * @return char 
 */
char USARTReadChar()
{
    while(!(UCSR0A & (1<<RXC0)))
    {
      //do nothing
    }
    return UDR0;
}

/**
 * @brief Give Output in degree celsius read from sensor
 * 
 * @param temp_value 
 */
void USARTWriteChar(uint16_t temp_value)
{

    if(temp_value>=0&&temp_value<=200)
    {
        unsigned char output01[]="Temp. is 20 degree C \n";
        int i = 0;
        while (output01[i]!=0)
        {
        while(!(UCSR0A&(1<<UDRE0)));
        UDR0=output01[i];
        i++;
        }
    }

    if(temp_value>=210&&temp_value<=500)
    {
        unsigned char output02[]="Temperature is 25 degree C \n";
        int i = 0;
        while (output02[i]!=0)
        {
        while(!(UCSR0A&(1<<UDRE0)));
        UDR0=output02[i];
        i++;
        }
    }

    if(temp_value>=510&&temp_value<=700)
    {
        unsigned char output03[]="Temperature is 29 degree C \n";
        int i = 0;
        while (output03[i]!=0)
        {
        while(!(UCSR0A&(1<<UDRE0)));
        UDR0=output03[i];
        i++;
        }
    }


    if(temp_value>=710&&temp_value<=1024)
    {
        unsigned char output04[]="Temperature is 33 degree C \n";
        int i = 0;
        while (output04[i]!=0)
        {
        while(!(UCSR0A&(1<<UDRE0)));
        UDR0=output04[i];
        i++;
        }
    }

}