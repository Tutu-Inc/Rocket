#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "./lib/BMP280/bmp280.h"
//#include "./lib/MPU6050/mpu6050.h"
#include "pico/binary_info.h"
#include "./src/bus_init.cpp"


int main() {
    stdio_init_all();

    i2cInit();

    BMP280 bmp280;
    
    bmp280.init();

    while(1){
        bmp280.get_data();
        printf("Pressure = %.3f kPa\n", bmp280.pressure / 1000.f);
        printf("Temp. = %.2f C\n", bmp280.temperature / 100.f);
    }

}


//#include <stdio.h>
//#include <iostream>
//#include "pico/stdlib.h"

/*
States: IDLE, Tracking, STOP
IDLE: wait for Start Tracking-Command from Host
Tracking: read all Data from BMP280&MPU6050
STOP: write Data to SD-Card when Stop Tracking-Command is received


//Sensor Read Rate = 400Hz

//enum state {IDLE, Tracking, STOP};
*/

//using namespace std;


    
    /*
    sensor_data = bmp_data & mpu_data

    IDLE
        rf_send(sensor_data)
        if(rf_receive = "Tracking"){
            state = Tracking
        }

    Tracking
        rf_send(sensor_data)
        flash_write(sensor_data)
        if(rf_receive = "STOP"){
            state = STOP
        }
    
    STOP
        data = flash_data()
        sd_write(data)
        rf_send("Tracking stopped")
    

    */
