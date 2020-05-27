/*******************************
 * L298N_helper.h
 *
 * Created: 31.12.2019 13:27:10
 * Author : DeepSouthT
 *
 * Used:
 *    L298N Motor driver module
 * 
 * Description:
 *     Helper functions for using L298N module in Arduino projects
 *
 * Last modified: 31.12.2019
 *******************************/
 
#ifndef __L298NDRIVER_H__
#define __L298NDRIVER_H__

#include <stdint.h>
#include <Arduino.h>
 
#define MAX_SPEED_PWM 255
#define MIN_SPEED_PWM 0
 
class L298N
{

public:
	L298N();
	L298N(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb);
	void initL298N();
	void motorLeftForward(uint8_t PWM);
	void motorLeftReverse(uint8_t PWM);
	void motorRightForward(uint8_t PWM);
	void motorRightReverse(uint8_t PWM);
	void motorLeftstop();
	void motorRightstop();
	void motorLeftbreak(uint8_t PWM);
	void motorRightbreak(uint8_t PWM);

private:
	uint8_t ENA;
	uint8_t IN1;
	uint8_t IN2;
	uint8_t IN3;
	uint8_t IN4;
	uint8_t ENB;
};

#endif //__L298NDRIVER_H__
