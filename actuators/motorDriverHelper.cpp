/*******************************
 * motorDriverHelper.cpp
 *
 * Created: 05.01.2020 22:20:26
 * Author : DeepSouthT
 *
 * Used:
 *    L298N/DRV8833 Motor driver module
 * 
 * Description:
 *     Helper function implementation for using L298N/DRV8833 module in Arduino projects
 *
 * Last modified: 11.01.2020
 *******************************/

#include "motorDriverHelper.h"

// default constructor
/*
motorDriverHelper::motorDriverHelper(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb)
{
	objl298n = new L298N( ena, in1, in2, in3, in4, enb);
}
*/

motorDriverHelper::motorDriverHelper( uint8_t ain1, uint8_t ain2, uint8_t bin1, uint8_t bin2 )
{
  objdrv8833 = new DRV8833( ain1, ain2, bin1, bin2 );
}

// default destructor
motorDriverHelper::~motorDriverHelper()
{
}

/***************************
  Drive the motor driver IC
  " direction "
  0 Forward
  1 Backward
  2 Right
  3 Left
  4 Stop
  " speed "
  8 bit PWM value
***************************/
int speedR = 0; //Speed of the right motor
int speedL = 0; //Speed of the left motor
int offsetR = 0; //Offset speed for Motor R
int offsetL = 0; //Offset speed for Motor L
enDirection __enDirectionOld = enDirection::UNKNOWN; //Previous direction of the motor driver

void motorDriverHelper::directionSpeed( enDirection __enDirection, int speed ) {

  //Left & Right speed set to equal
  speedR = speed + offsetR;
  speedL = speed + offsetL;

  //8-bit PWM, MAX 255. To avoid exceeding the limit
  if ( speedR > 255) { speedR = 255; }
  if ( speedL > 255) { speedL = 255; }
  
  switch ( __enDirection ) {
    case enDirection::FORWARD:
      objdrv8833->motorLeftForward(speedL);
      objdrv8833->motorRightForward(speedR);
      break;
    case enDirection::REVERSE:
      objdrv8833->motorLeftReverse(speedL);
      objdrv8833->motorRightReverse(speedR);
      break;
    case enDirection::RIGHT:
      objdrv8833->motorRightForward(0);
      objdrv8833->motorLeftForward(speedL);
      break;
    case enDirection::LEFT:
      objdrv8833->motorRightForward(speedR);
      objdrv8833->motorLeftForward(0);
      break;
    case enDirection::FORWARD_RIGHT:
      objdrv8833->motorLeftForward(speedL);
      objdrv8833->motorRightForward(ANTIDELTA);
      break ;
    case enDirection::FORWARD_LEFT:
      objdrv8833->motorLeftForward(ANTIDELTA);
      objdrv8833->motorRightForward(speedR);
      break ;
    case enDirection::REVERSE_RIGHT:
      objdrv8833->motorLeftReverse(speedL);
      objdrv8833->motorRightReverse(ANTIDELTA);
      break ;
    case enDirection::REVERSE_LEFT:
      objdrv8833->motorLeftReverse(ANTIDELTA);
      objdrv8833->motorRightReverse(speedR);
      break ;
    case enDirection::STOP:
      objdrv8833->motorLeftbreak(speedL);
      objdrv8833->motorRightbreak(speedR);
      break ;
  }
  __enDirectionOld = __enDirection;
  __enDirection = enDirection::UNKNOWN; //Clear the variable
}

void motorDriverHelper::initDriver(void) {
  objdrv8833->initDRV8833();
}
