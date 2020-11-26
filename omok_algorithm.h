#ifndef __OMOK_ALGORITHM_H__
#define __OMOK_ALGORITHM_H__

/**
* @file omok_algorithm.h
*/

#include "omokobj.h"
#include "omokobj_manage.h"
#include "omokobj_conio.h"

/**
* @fn int check_win_row(OmokCoord* l, OmokPanel* o);
* @brief 가로로 5개의 돌이 놓여있는지 확인하는 함수
*
* @param OmokPanel* panel	: 돌이 놓여있는 오목판
* @param OmokCoord* coord	: 확인할 오목판의 좌표
* @return int				: 가로로 5개의 돌이 놓여있으면 1, 아니면 0 반환
*
* @author	lja3723
* @date		2020-11-26 17:00
* @version	0.0.1
*
*/
int check_win_row(OmokPanel* panel, OmokCoord* coord);

#endif