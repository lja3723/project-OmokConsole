#ifndef __OMOK_H__
#define __OMOK_H__

#include <stdio.h>
#include "omok_algorithm.h"
#include "omok_err.h"
#include "omokobj.h"
#include "omokobj_manage.h"
#include "omokobj_print.h"


//omok_start: 오목 게임을 시작하는 함수
void omok_start();

//initial_set: 본게임 시작 전 게임 초기값을 설정하는 유저 인터페이스 함수
void UI_initial_set();

//init: 오목 게임의 객체를 초기화하는 함수
void obj_initialize();




#endif