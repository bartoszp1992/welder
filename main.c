/*
 * main.c
 *
 *  Created on: 28 mar 2018
 *      Author: bartosz
 *
 *      welder software v0.1 alpha
 */

#include <avr/io.h>
#include <util/delay.h>

volatile int f;
 void mydelay(uint16_t delay) {

 for (f = 0; f<delay; f++)
 _delay_ms(1);
 }


 _delay_ms_var(uint16_t a)
 {
   while(a--)
   {
     _delay_ms(1);
   }
 }

 int a;

int main(void){

	//indicator
	DDRC |= (1<< PC1);
	DDRC |= (1<< PC2);
	DDRC |= (1<< PC3);
	DDRC |= (1<< PC4);
	DDRC |= (1<< PC5);

	PORTC = 0x00;

	//trigger
	DDRB &= ~(1<PB0);
	PORTB |= (1<<PB0);

	//adjust
	DDRB &= ~(1<<PB1);
	PORTB |= (1<<PB1);

	DDRB &= ~(1<<PB2);
	PORTB |= (1<<PB2);

	//out(optotriac)
	DDRD |= (1<<PD0);
	PORTD &= ~(1<<PD0);

	//warming LED
	DDRD |= (1<<PD1);
	PORTD &= ~(1<<PD1);

	//buzzer
	DDRD |= (1<<PD2);
	PORTD &= ~(1<<PD0);

	//zmienne
	int times[30] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150,160, 170, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290};
	int set = 1;
	int time;

	PORTD |= (1<<PD1);
	PORTC = (0<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (1<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTC = (0<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
	_delay_ms(100);
	PORTD &= ~(1<<PD1);





	while(1){


		if(!(PINB & (1<<PB0))){



			PORTD |= (1<<PD2);//buzzer
			PORTD |= (1<<PD1);//LED
			PORTD |= (1<<PD0);//opto

			_delay_ms_var(times[set]);

			PORTD &= ~(1<<PD0);//opto
			_delay_ms(100);
			PORTD &= ~(PD2);//buzzer
			_delay_ms(300);
			PORTD &= ~(PD1);//LED
			_delay_ms(500);

		}


		if(!(PINB & (1<<PB1)) && set < 28){
			set++;
			_delay_ms(200);

		}

		if(!(PINB & (1<<PB2)) && set > 1){
			set--;
			_delay_ms(200);
		}


		if(set == 1){
		PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[1];
		}

		if(set == 2){
		PORTC = (0<<PC1) | (1<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[2];
		}

		if(set == 3){
		PORTC = (1<<PC1) | (1<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[3];
		}

		if(set == 4){
		PORTC = (0<<PC1) | (0<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[4];
		}

		if(set == 5){
		PORTC = (1<<PC1) | (0<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[5];
		}

		if(set == 6){
		PORTC = (0<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[6];
		}

		if(set == 7){
		PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (0<<PC5);
		time = times[7];
		}

		if(set == 8){
		PORTC = (0<<PC1) | (0<<PC2) | (0<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[8];
		}

		if(set == 9){
		PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[9];
		}

		if(set == 10){
		PORTC = (0<<PC1) | (1<<PC2) | (0<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[10];
		}

		if(set == 11){
		PORTC = (1<<PC1) | (1<<PC2) | (0<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[11];
		}

		if(set == 12){
		PORTC = (0<<PC1) | (0<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[12];
		}

		if(set == 13){
		PORTC = (1<<PC1) | (0<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[13];
		}

		if(set == 14){
		PORTC = (0<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[14];
		}

		if(set == 15){
		PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4) | (0<<PC5);
		time = times[15];
		}

		if(set == 16){
		PORTC = (0<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[16];
		}

		if(set == 17){
		PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[17];
		}

		if(set == 18){
		PORTC = (0<<PC1) | (1<<PC2) | (0<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[18];
		}

		if(set == 19){
		PORTC = (1<<PC1) | (1<<PC2) | (	0<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[19];
		}

		if(set == 20){
		PORTC = (0<<PC1) | (0<<PC2) | (1<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[20];
		}

		if(set == 21){
		PORTC = (1<<PC1) | (0<<PC2) | (1<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[21];
		}

		if(set == 22){
		PORTC = (0<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[22];
		}

		if(set == 23){
		PORTC = (1<<PC1) | (1<<PC2) | (1<<PC3) | (0<<PC4) | (1<<PC5);
		time = times[23];
		}

		if(set == 24){
		PORTC = (0<<PC1) | (0<<PC2) | (0<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[24];
		}

		if(set == 25){
		PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[25];
		}

		if(set == 26){
		PORTC = (0<<PC1) | (1<<PC2) | (0<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[26];
		}

		if(set == 27){
		PORTC = (1<<PC1) | (1<<PC2) | (0<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[27];
		}

		if(set == 28){
		PORTC = (0<<PC1) | (0<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[28];
		}

		if(set == 29){
		PORTC = (1<<PC1) | (0<<PC2) | (1<<PC3) | (1<<PC4) | (1<<PC5);
		time = times[29];
		}

																									if(set == 1){
																												PORTC = (1<<PC1) | (0<<PC2) | (0<<PC3) | (0<<PC4) | (0<<PC5);
																												}




	}
}
