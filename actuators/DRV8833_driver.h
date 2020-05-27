/*******************************
 * DRV8833_driver.h
 *
 * Created: 02.02.2020 16:51:00
 * Author : DeepSouthT
 *
 * Used:
 *    DRV8833 Motor driver module
 * 
 * Description:
 *     Helper functions for using DRV8833 module in Arduino projects
 *
 * Last modified: 02.02.2020
 *******************************/
 
#ifndef __DRV8833DRIVER_H__
#define __DRV8833DRIVER_H__

#include <stdint.h>
#include <Arduino.h>
 
#define MAX_SPEED_PWM 255
#define MIN_SPEED_PWM 0
 
class DRV8833
{

public:
	DRV8833();
	DRV8833( uint8_t ain1, uint8_t ain2, uint8_t bin1, uint8_t bin2 );
	void initDRV8833();
	void motorLeftForward(uint8_t PWM);
	void motorLeftReverse(uint8_t PWM);
	void motorRightForward(uint8_t PWM);
	void motorRightReverse(uint8_t PWM);
	void motorLeftstop();
	void motorRightstop();
	void motorLeftbreak(uint8_t PWM);
	void motorRightbreak(uint8_t PWM);

private:
	uint8_t AIN1;
	uint8_t AIN2;
	uint8_t BIN1;
	uint8_t BIN2;
};

#endif //__DRV8833DRIVER_H__
