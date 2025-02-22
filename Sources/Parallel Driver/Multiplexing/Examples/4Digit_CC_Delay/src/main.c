#include "aKaReZa.h"

uint32_t Counter = 0;

int main(void)
{
  Seg7_init();
  while(1)
  {
    //Counter++;
    //Seg7_Puti((uint16_t) (Counter/1000));
    Seg7_Puti(1234);
    delay_ms(1);
  };
};