#ifndef __OMOK_H__
#define __OMOK_H__

#include <stdio.h>
#include "omok_algorithm.h"
#include "omok_err.h"
#include "omokobj.h"
#include "omokobj_manage.h"
#include "omokobj_conio.h"

/**
* @file omok.h
*/

/*
*	[파일 개요]
* 
*	1. 게임 시작
*	2. 게임 관련 객체 초기화
*	3. 게임 그래픽 출력
*	4. 게임 인터페이스 제공
*	5. 유저 입력에 따른 반응 서술
*	6. 게임 규칙 및 종료 판별
* 
*/

/*************************** 본문 ******************************/



/*************************
*	 1. 게임 시작     
**************************/

/**
* @fn void omok_start();
* @brief	오목 게임 시작
*
* @param	void
* @return	void
*
* @author	lja3723
* @date		2020-11-24 16:00
* @version	0.0.1
*
*/
void omok_start();





/********************************
*	 2. 게임 관련 객체 초기화
*********************************/

/**
* @fn void UI_initial_set();
* @brief	본게임 시작 전 게임 초기값을 설정
*
* @param	void
* @return	void
*
*/
void UI_initial_set();

/**
* @fn void obj_initialize();
* @brief 오목 게임의 객체를 초기화
* 
* @param	void
* @return	void
* 
*/
void obj_initialize();







/*************************** /본문 *******************************/
#endif