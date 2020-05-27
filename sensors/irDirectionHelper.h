/*******************************
 * irDirectionHelper.h
 *
 * Created: 11.01.2020 21:07:34
 * Author : DeepSouthT
 *
 * Used:
 *    IR emitter and detector
 * 
 * Description:
 *     Helper function for determining the current direction based on IR
 *
 * Last modified: 01.02.2020
 *******************************/

#ifndef __IRDIRECTIONHELPER_H__
#define __IRDIRECTIONHELPER_H__

#include <stdint.h>

enum class enCurrentDirection {
	IN_CENTER,
	ON_LEFT_BORDER,
	ON_RIGHT_BORDER,
	FROM_LEFT_TO_RIGHT,
	FROM_RIGHT_TO_LEFT,
	UNKNOWN
};

class irDirectionHelper
{
public:
	irDirectionHelper();
	~irDirectionHelper();
	enCurrentDirection currentDirection(uint8_t RB, uint8_t RR, uint8_t LL, uint8_t LB);

private:
	bool validInput(uint8_t RB, uint8_t RR, uint8_t LL, uint8_t LB);
};

#endif //__IRDIRECTIONHELPER_H__
