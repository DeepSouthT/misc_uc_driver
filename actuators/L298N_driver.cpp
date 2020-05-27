/*******************************
 * L298N_helper.h
 *
 * Created: 31.12.2019 13:39:17
 * Author : DeepSouthT
 *
 * Used:
 *    L298N Motor driver module
 * 
 * Description:
 *     Helper function implementation for using L298N module in Arduino projects
 *
 * Last modified: 04.01.2020
 *******************************/

#include "L298N_driver.h"

L298N::L298N(void){/*init constructor*/};

/**
 * constructor function 
 * params map arduino pin to pin L298N module
 * 
 * ena -> ENA  or PWM pin motor left
 * in1 -> IN1
 * in2 -> IN2
 * in3 -> IN3
 * in4 -> IN4
 * enb -> ENB or PWM pin right
 */
L298N::L298N(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb)
{
	this->ENA = ena;
	this->ENB = enb;
	this->IN1 = in1;
	this->IN2 = in2;
	this->IN3 = in3;
	this->IN4 = in4;
}

/**
 * initial arduino pin
 */
void L298N::initL298N(void)
{
	pinMode(ENA, OUTPUT);
	analogWrite(ENA, MIN_SPEED_PWM);
	pinMode(ENB, OUTPUT);
	analogWrite(ENB, MIN_SPEED_PWM);
	pinMode(IN1, OUTPUT);
	digitalWrite(IN1, LOW);
	pinMode(IN2, OUTPUT);
	digitalWrite(IN2, LOW);
	pinMode(IN3, OUTPUT);
	digitalWrite(IN3, LOW);
	pinMode(IN4, OUTPUT);
	digitalWrite(IN4, LOW);
}
	
/**
 * motor left turn clockwise
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorRightForward(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
}

/**
 * motor right turn clockwise
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorLeftForward(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}

/**
 * motor left turn anticlockwise
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorRightReverse(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
}

/**
 * motor right turn anticlockwise
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorLeftReverse(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
}

/**
 * motor left break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void L298N::motorRightbreak(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, HIGH);
}

/**
 * motor right break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void L298N::motorLeftbreak(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, HIGH);
}

/**
 * motor left stop
 */
void L298N::motorRightstop()
{
	analogWrite(ENA, MIN_SPEED_PWM);
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}

/**
 * motor right stop
 */
void L298N::motorLeftstop()
{
	analogWrite(ENB, MIN_SPEED_PWM);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
