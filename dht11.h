#ifndef dht_h
#define dht_h

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class dht
{
	public: 
		int read_dht11(unsigned char pin);
		double humidity;
		double temperature;
	private:
		uint8_t bits[5];
		int read(unsigned char pin);
};

#endif
