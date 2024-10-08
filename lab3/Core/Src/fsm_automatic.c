/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

void automatic_run (void)
{
	switch (status)
	{
	case INIT:
		if (1) // ko dieu kien
		break;
	case GREEN_RED:
		if (isTimerExpired(0) == 1)
		{
			status = AMBER_RED;
			setTimer(0, 2000);
		}
		if (isButtonPress)
		{
			// chuan bi tai nguyen cho trang thai tiep theo
			setTimer(0, 10000);
		}
	}
}
