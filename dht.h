#ifndef DHT_H
#define DHT_H

#include "dht_global.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class DHTSHARED_EXPORT dht
{

public:
        int read_dht11(unsigned char pin);
        double humidity;
        double temperature;
private:
        uint8_t bits[5];
        int read(unsigned char pin);
};

#endif // DHT_H
