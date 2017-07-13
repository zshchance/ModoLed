#ifndef INTERUPT_H
#define INTERUPT_H

ISR(WDT_vect) ;
void EncoderA_ISR();
void EncoderSW_ISR(void);

#endif //INTERUPT_H

