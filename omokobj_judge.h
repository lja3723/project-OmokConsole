#ifndef __OMOKOBJ_JUDGE_H__
#define __OMOKOBJ_JUDGE_H__

#include "omokobj.h"

/**
* @file omokobj_judge.h
* 
* 
* @details
*	[파일 개요]
* 오목 프로그램 객체가 특정 조건을 만족하는지 판단하는 함수를 선언함
* 
* 
*	[함수 종류(공통)]
* 유효성		valid_객체()
* 반유효성	invalid_객체()
* 
*
* [객체 유효성(valid) 함수]
* 객체 유효성 검사 계열 함수는 객체가 유효한 값으로 초기화됐는지
* 검사하거나 '동적 할당이 필요한 멤버'가 있는 객체가
* 유효한 동적 할당이 되어 있는지 판단하는 역할을 담당함
*
* 이름				: valid_객체()
* 매개변수			: 유효성 검사할 객체의 주소값
* 반환값				: 객체가 유효하면 1, 그렇지 않으면(NULL 등) 0 반환
*
* 
* [객체 반유효성(invalid) 함수]
* 객체 반유효성 검사 계열 함수는 valid 함수의 반환값을 반대로 바꾼 함수임
*
* 이름				: invalid_객체()
* 매개변수			: 유효성 검사할 객체의 주소값
* 반환값				: !valid_객체() - 객체가 유효하지 않으면(NULL 등) 1, 유효하면 0 반환
*/

//양식
/**
* @fn
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/


/********************************* 본문 *************************************/



/*****************************************************************
*						OmokCoord judgment
* 유효성(valid) 반유효성(invalid)
******************************************************************/

/**
* @fn int valid_OmokCoord(OmokCoord* obj);
* @brief OmokCoord 유효성 검사:
*		객체의 row가 'A'~'Z'이고 객체의 col이 1~19면 유효함
* @param OmokCoord* obj	: 유효성 검사할 객체의 주소값
* @return int			: 유효하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-25 12:10
* @version 0.0.1
*/
int valid_OmokCoord(OmokCoord* obj);

/**
* @fn int invalid_OmokCoord(OmokCoord* obj);
* @brief OmokCoord 반유효성 검사:
*		객체의 row가 'A'~'Z'이고 객체의 col이 1~19면 유효함
* @param OmokCoord* obj	: 반유효성 검사할 객체의 주소값
* @return OmokCoord		: 유효하지 않으면 1, 유효하면 0 반환
*
* @author lja3723
* @date 2020-11-25 17:50
* @version 0.0.1
*/
int invalid_OmokCoord(OmokCoord* obj);




/*******************************************************************
*						StoneType judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/

/**
* @fn int valid_StoneType(StoneType* obj);
* @brief StoneType 유효성 검사:
*		객체가 ERR_ST가 아니면 유효함
* @param StoneType* obj		: 유효성 검사할 객체의 주소값
* @return int				: 유효하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-25 12:15
* @version 0.0.1
*/
int valid_StoneType(StoneType* obj);

/**
* @fn int invalid_StoneType(StoneType* obj);
* @brief StoneType 반유효성 검사:
*		객체가 ERR_ST가 아니면 유효함
* @param StoneType* obj		: 유효성 검사할 객체의 주소값
* @return int				: 유효하지 않으면 1, 유효하면 0 반환
*
* @author lja3723
* @date 2020-11-25 17:50
* @version 0.0.1
*/
int invalid_StoneType(StoneType* obj);



/*******************************************************************
*						OmokCursor judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/






/*******************************************************************
*						Stone judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/






/*******************************************************************
*						StoneNode judgment
* 유효성(valid) 반유효성(invalid)
* 동적 할당 객체 여부 검사(is_StoneNode_dynamic)
********************************************************************/

/**
* @fn int is_StoneNode_dynamic(StoneNode* obj);
* @brief obj이 동적 할당된 StoneNode인지 검사
* @param StoneNode* obj	: 검사할 StoneNode 객체의 주소값
* @return int			: 동적 할당된 StoneNode이면 1, 아니면 0 반환
*
* @author lja3723
* @date 2020-11-27 21:50
* @version 0.0.1
*/
int is_StoneNode_dynamic(StoneNode* obj);




/*******************************************************************
*						StoneStorage judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/






/*******************************************************************
*						OmokPanelType judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/






/*******************************************************************
*						OmokPanel judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/






/*******************************************************************
*						OmokStatus judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/







/*******************************************************************
*						Omok judgment
* 유효성(valid) 반유효성(invalid)
********************************************************************/







/********************************* /본문 *************************************/
#endif
