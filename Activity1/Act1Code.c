// ACTIVITY 1
// Problem Statement: When the person is sitting on the seat and turns on the heater then the LED should glow.
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
DDRB|=(1<<PB0);//setting B0=1 when led will glow
DDRB&=~(1<<PB0);//clearing the bit
PORTB|=(1<<PB6);//set the bit
DDRB&=~(1<<PB7);//clear bit
PORTB|=(1<<PB7);//set the bit

    while(1)
        {
            if(!(PINB&(1<<PB7)))
            {
                if(!(PINB&(1<<PB6)))
                   {

                       PORTB|=(1<<PB0);//Indication that seat and heater both on
                       _delay_ms(10);

                   }
                   else
                    {
            PORTB&=~(1<<PB0);
            _delay_ms(10);
        }
            }

        }

return 0;
}
