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
*
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



// 잠깐! 아래의 주석은 함수를 설명해 주는 주석임
/**
*
* @brief	: 함수에 대한 간단한 설명
* @details	: 함수에 대한 자세한 설명
* @param	: 함수의 매개 변수 설명
* @param	: 이렇게 함수 매개변수 수에 따라 @param을 여러 개 적을 수 있다
* @return	: 함수의 리턴값 설명
*
* @author	: 저작권자(함수 작성한 사람)
* @date		: 함수 작성 날짜 (예: 2020-11-30 오후 08:20)
* @version	: 함수 버전 (예: 0.0.1)
*
*/
//이런 형식을 doxygen 주석이라 하며, 자세한 정보는 다음 사이트를 참고바람
//https://onecellboy.tistory.com/342

//doxygen 주석 양식(아래를 복사해 사용)
/**
*
* @brief
* @details
*
* @param
* @return
*
* @author
* @date
* @version
*
*/



/*************************** 본문 ******************************/



/*************************
*	 1. 게임 시작     
**************************/

/**
*
* @brief	오목 게임을 시작함
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
*
* @brief	본게임 시작 전 게임 초기값을 설정하는 유저 인터페이스 함수
*
* @param	void
* @return	void
*
*/
void UI_initial_set();

/**
* 
* @brief 오목 게임의 객체를 초기화하는 함수
* 
* @param	void
* @return	void
* 
*/
void obj_initialize();







/*************************** /본문 *******************************/
#endif