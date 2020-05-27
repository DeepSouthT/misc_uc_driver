/*******************************
* irDirectionHelper.cpp
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

#include "irDirectionHelper.h"

// default constructor
irDirectionHelper::irDirectionHelper()
{
}

enCurrentDirection irDirectionHelper::currentDirection(uint8_t RB, uint8_t RR, uint8_t LL, uint8_t LB)
{
	bool isInputValid = false;
	enCurrentDirection ret = enCurrentDirection::UNKNOWN;
	
	isInputValid = irDirectionHelper::validInput(RB, RR, LL, LB);
	
	if (isInputValid == false)
	{
		ret = enCurrentDirection::UNKNOWN;
	}
	else
	{
			 if((RB == 1)&&(RR == 0)&&(LL == 0)&&(LB == 0))
		{ ret = enCurrentDirection::ON_RIGHT_BORDER; }
		else if((RB == 1)&&(RR == 1)&&(LL == 0)&&(LB == 0))
		{ ret = enCurrentDirection::FROM_RIGHT_TO_LEFT;	}
		else if((RB == 0)&&(RR == 0)&&(LL == 0)&&(LB == 1))
		{ ret = enCurrentDirection::ON_LEFT_BORDER;	}
		else if((RB == 0)&&(RR == 0)&&(LL == 1)&&(LB == 1))
		{ ret = enCurrentDirection::FROM_LEFT_TO_RIGHT;	}
		else if((RB == 0)&&(RR == 1)&&(LL == 0)&&(LB == 0))
		{ ret = enCurrentDirection::IN_CENTER; }
		else if((RB == 0)&&(RR == 0)&&(LL == 1)&&(LB == 0))
		{ ret = enCurrentDirection::IN_CENTER; }
		else if((RB == 0)&&(RR == 1)&&(LL == 1)&&(LB == 0))
		{ ret = enCurrentDirection::IN_CENTER; }
	}
	
	return ret;
}

bool irDirectionHelper::validInput(uint8_t LB, uint8_t LL, uint8_t RR, uint8_t RB)
{
	bool ret = false;
	
		 if((RB == 1)&&(RR == 1)&&(LL == 1)&&(LB == 1))
	{ ret = false; }
	else if((RB == 1)&&(RR == 1)&&(LL == 1)&&(LB == 0))
	{ ret = false; }
	else if((RB == 0)&&(RR == 1)&&(LL == 1)&&(LB == 1))
	{ ret = false; }
	else if((RB == 1)&&(RR == 1)&&(LL == 0)&&(LB == 1))
	{ ret = false; }
	else if((RB == 1)&&(RR == 0)&&(LL == 1)&&(LB == 1))
	{ ret = false; }
	else if((RB == 1)&&(RR == 0)&&(LL == 0)&&(LB == 1))
	{ ret = false; }
	else if((RB == 1)&&(RR == 0)&&(LL == 1)&&(LB == 0))
	{ ret = false; }
	else if((RB == 0)&&(RR == 1)&&(LL == 0)&&(LB == 1))
	{ ret = false; }
	else if((RB == 0)&&(RR == 1)&&(LL == 1)&&(LB == 1))
	{ ret = false; }
	else { ret = true; }
	
	return ret;
}

// default destructor
irDirectionHelper::~irDirectionHelper()
{
}
