/*******************************
 * motorDriverHelper.h
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

#ifndef __MOTORDRIVERHELPER_H__
#define __MOTORDRIVERHELPER_H__

//#include "L298N_driver.h"
#include "DRV8833_driver.h"

#define SPEED 100
#define DELTA 225
#define ANTIDELTA 70

#define SPEED_FAST 200
#define SPEED_TURN 200
#define SPEED_MEDI 120
#define SPEED_SLOW 90

#define DELAY 80

enum class enDirection {
	FORWARD,
	REVERSE,
	RIGHT,
	LEFT,
  FORWARD_RIGHT,
  FORWARD_LEFT,
  REVERSE_RIGHT,
  REVERSE_LEFT,
	STOP,
	UNKNOWN
};

class motorDriverHelper
{
private:
//L298N* objl298n;
DRV8833* objdrv8833;
public:
	//motorDriverHelper(uint8_t ena, uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4, uint8_t enb);
  motorDriverHelper( uint8_t ain1, uint8_t ain2, uint8_t bin1, uint8_t bin2 );
	~motorDriverHelper();
	void initDriver(void);
	void directionSpeed( enDirection __enDirection, int speed );
};

#endif //__MOTORDRIVERHELPER_H__
