#ifndef __OMOK_ALGORITHM_H__
#define __OMOK_ALGORITHM_H__

/**
* @file omok_algorithm.h
*/

#include "omokobj.h"
#include "omokobj_manage.h"
#include "omokobj_conio.h"

// check_win_row : 가로로 5개의 돌이 놓여있는지 확인하는 함수
int check_win_row(Location* l, OmokPanel* o);

#endif