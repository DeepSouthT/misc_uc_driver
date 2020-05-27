/*******************************
 * DRV8833_driver.cpp
 *
 * Created: 02.02.2020 16:51:00
 * Author : DeepSouthT
 *
 * Used:
 *    DRV8833 Motor driver module
 * 
 * Description:
 *     Helper function implementation for using DRV8833 module in Arduino projects
 *
 * Last modified: 02.02.2020
 *******************************/

#include "DRV8833_driver.h"

DRV8833::DRV8833(void){/*init constructor*/};

/**
 * constructor function 
 * params map arduino pin to pin DRV8833 module
 * 
 * ain1 -> AIN1
 * ain2 -> AIN2
 * bin1 -> BIN1
 * bin2 -> BIN2
 */
DRV8833::DRV8833( uint8_t ain1, uint8_t ain2, uint8_t bin1, uint8_t bin2 )
{
	this->AIN1 = ain1;
	this->AIN2 = ain2;
	this->BIN1 = bin1;
	this->BIN2 = bin2;
}

/**
 * initial arduino pin
 */
void DRV8833::initDRV8833(void)
{
	pinMode(AIN1, OUTPUT);
	digitalWrite(AIN1, LOW);
	pinMode(AIN2, OUTPUT);
	digitalWrite(AIN2, LOW);
	pinMode(BIN1, OUTPUT);
	digitalWrite(BIN1, LOW);
	pinMode(BIN2, OUTPUT);
	digitalWrite(BIN2, LOW);
}
	
/**
 * motor left turn clockwise
 * by specify speed (PWM) 0 - 255
 */
void DRV8833::motorRightForward(uint8_t PWM)
{
	digitalWrite(AIN1, LOW);
	analogWrite(AIN2, PWM);
}

/**
 * motor right turn clockwise
 * by specify speed (PWM) 0 - 255
 */
void DRV8833::motorLeftForward(uint8_t PWM)
{
	digitalWrite(BIN1, LOW);
  analogWrite(BIN2, PWM);
}

/**
 * motor left turn anticlockwise
 * by specify speed (PWM) 0 - 255
 */
void DRV8833::motorRightReverse(uint8_t PWM)
{
	analogWrite(AIN1, PWM);
	digitalWrite(AIN2, LOW);
}

/**
 * motor right turn anticlockwise
 * by specify speed (PWM) 0 - 255
 */
void DRV8833::motorLeftReverse(uint8_t PWM)
{
	analogWrite(BIN1, PWM);
	digitalWrite(BIN2, LOW);
}

/**
 * motor left break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void DRV8833::motorRightbreak(uint8_t PWM)
{
	digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, HIGH);
}

/**
 * motor right break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void DRV8833::motorLeftbreak(uint8_t PWM)
{
	digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, HIGH);
}

/**
 * motor left stop
 */
void DRV8833::motorRightstop()
{
	digitalWrite(AIN1, LOW);
	digitalWrite(AIN2, LOW);
}

/**
 * motor right stop
 */
void DRV8833::motorLeftstop()
{
	digitalWrite(BIN1, LOW);
	digitalWrite(BIN2, LOW);
}
