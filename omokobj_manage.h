#ifndef __OMOKOBJ_MANAGE_H__
#define __OMOKOBJ_MANAGE_H__

#include "omokobj.h"

/**
* @file omokobj_manage.h
* 
* 
* @details
*	[파일 개요]
* 오목 프로그램 객체를 관리(설정, 생성, 변환, 제거 등)하는 함수를 선언함
* 
* 
*	[함수 종류]
* 생성		_객체()
* 설정		set_객체()
* 변환		변환할객체_to_변환될객체()
*	(아래는 '동적 할당이 필요한 멤버'가 있는 객체인 경우)
* 동적 생성	new_객체()
* 복사		copy_객체()
* 제거		delete_객체()
*
* 
* [객체 생성(_) 함수]
* 객체 생성 계열 함수는 객체 멤버 변수와 일대일 대응 되는 주어진 인자를 통해 객체를 생성해 반환하는 역할을 담당함
* '동적 할당이 필요한 멤버'가 있는 객체는 반드시 객체 사용 후 해당 객체의 delete 함수를 호출해야 함
*
* 이름				: _객체()
* 매개변수			: 설정값(멤버 변수와 일대일 대응)
* 반환값				: 생성된 객체 반환
*
*
* [객체 설정(set) 함수]
* 객체 설정 계열 함수는 객체를 주어진 인자로 설정하는 역할을 담당함
* '동적 할당이 필요한 멤버'가 있는 객체는 반드시 객체 사용 후 delete 함수를 호출해야 함
* 
* 이름				: set_객체()
* 첫 매개변수		: 설정할 객체의 주소값
* 그 외 매개변수		: 설정값(멤버 변수와 일대일 대응)
* 반환값				: void
*
*
* [객체 변환(_to_) 함수]
* 객체 변환 계열 함수는 변환할객체를 변환될객체로 변환하는 역할을 담당함
* 이때 객체 복사가 수행되며 복사된 객체가 리턴됨
*
* 이름				: 변환할객체_to_변환된객체()
* 첫 매개변수		: 변환할객체의 주소값
* 그 외 매개변수		: 없음
* 반환값				: 지역변수 형태의 변환된객체(변환될객체가 '동적 할당이 필요한 멤버'가 있을 경우 깊은 복사 수행됨)
*
* 
* [객체 동적 생성(new) 함수]
* 객체 동적 생성 계열 함수는 객체를 주어진 인자로 동적 생성하는 역할을 담당함
* 동적 할당된 객체의 주소가 리턴됨
*
* 이름				: 변환할객체_to_변환된객체()
* 매개변수			: 설정값(멤버 변수와 일대일 대응)
* 반환값				: 설정값으로 초기화된 동적 할당된 객체의 주소값
*
* 
* [객체 복사(copy) 함수]
* 객체 복사 계열 함수는 '동적 할당이 필요한 멤버'가 필요한 객체에서 정의되며
* 객체의 내용을 같은 타입의 객체에 '깊은 복사(deep copy)'하는 역할을 담당함
*
* 이름				: copy_객체()
* 첫 매개변수		: 복사할 객체의 주소값
* 그 외 매개변수		: 없음
* 반환값				: 지역 변수 형태의 복사된 객체
*
* 
* [객체 제거(delete) 함수]
* 객체 제거 계열 함수는 '동적 할당이 필요한 멤버'가 있는 객체에서 정의되며
* 객체가 '객체 생성 또는 설정 함수'를 통해 동적 할당 된 후 더 이상 코드에서 사용하지 않을 때 
* 동적 할당된 메모리를 해제하는 역할을 담당함
* 
* 이름				: delete_객체()
* 첫 매개변수		: 제거할 객체의 주소값
* 그 외 매개변수		: 없음
* 반환값				: 객체 제거가 성공하면 1, 실패하거나 객체 내부 동적 할당 메모리 포인터가 NULL인 경우 0을 반환
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
*					OmokCoord management
* 생성(_) 설정(set) 변환(Str|_to_)
******************************************************************/

/**
* @fn OmokCoord _OmokCoord(char row, short col);
* @brief OmokCoord 생성
* @param char row		: 생성할 객체의 행 정보, 범위: 'A' ~ 'Z', 인자가 잘못되면 '\\0'으로 초기화
* @param short col		: 생성할 객체의 열 정보, 범위: 1 ~ 19, 인자가 잘못되면 0으로 초기화
* @return OmokCoord		: 생성된 객체
*
* @author lja3723
* @date 2020-11-25 12:10
* @version 0.0.1
*/
OmokCoord _OmokCoord(char row, short col);

/**
* @fn void set_OmokCoord(OmokCoord* obj, char row, short col);
* @brief OmokCoord 설정
* @param OmokCoord* obj	: 설정할 객체의 주소값
* @param char row		: 설정할 행 정보, 범위: 'A' ~ 'Z', 인자가 잘못되면 '\\0'으로 초기화
* @param short col		: 설정할 열 정보, 범위: 1 ~ 19, 인자가 잘못되면 0으로 초기화
*
* @author lja3723
* @date 2020-11-25 01:10
* @version 0.0.1
*/
void set_OmokCoord(OmokCoord* obj, char row, short col);

/**
* @fn OmokCoord Str_to_OmokCoord(const char* str);
* @brief 문자열을 OmokCoord로 변환
* @param const char* str	: 형식은 "a19" 또는 "A19"이어야 하며, 인자가 잘못되면 row는 '\\0', col은 0으로 초기화
* @return OmokCoord			: 생성된 객체 반환
*
* @author lja3723
* @date 2020-11-25 12:20
* @version 0.0.1
*/
OmokCoord Str_to_OmokCoord(const char* str);



/*******************************************************************
*					StoneType management
* 생성(_)
********************************************************************/

/**
* @fn StoneType _StoneType(const char* str);
* @brief 문자열로 StoneType 생성
* @param const char* str	: 생성할 StoneType에 해당하는 문자열("w", "W", "white", "White", "b", "B", "black", "Black")
* @return StoneType			: Black 또는 White 반환, 변환 오류시 ERR_ST 반환
*
* @author lja3723
* @date 2020-11-25 01:25
* @version 0.0.1
*/
StoneType _StoneType(const char* str);



/*******************************************************************
*					OmokCursor management
* 생성(_) 설정(set) 변환(Stone|_to_)
********************************************************************/

/**
* @fn OmokCursor _OmokCursor(OmokCoord locate, StoneType type);
* @brief OmokCursor 객체 생성
* @param OmokCoord locate	: 생성되는 커서의 좌표
* @param StoneType type		: 생성되는 커서의 오목알 타입
* @return OmokCursor		: 생성된 객체
*
* @author 
* @date 
* @version 
*/
OmokCursor _OmokCursor(OmokCoord locate, StoneType type);

/** 
* @fn OmokCursor Stone_to_OmokCursor(Stone *obj);
* @brief Stone 객체를 OmokCursor로 변환
* @param Stone *obj	: 변환할 Stone 객체의 주소값
* @return			: 변환된 Cursor 객체
*
* @author
* @date
* @version
*/
OmokCursor Stone_to_OmokCursor(Stone *obj);

/**
* @fn int set_OmokCursor(OmokCursor *obj, OmokCoord locate, StoneType type);
* @brief OmokCursor 설정
* @param OmokCursor *obj	: 설정할 객체의 주소값
* @param OmokCoord locate	: 좌표 설정값
* @param StoneType type		: 오목알 타입 설정값
* @return void
*
* @author
* @date
* @version
*/
int set_OmokCursor(OmokCursor *obj, OmokCoord locate, StoneType type);



/*******************************************************************
*					Stone management
*  생성(_) 설정(set) 변환(OmokCursor|_to_)
********************************************************************/

/**
* @fn _Stone(OmokCoord locate, StoneType type);
* @brief Stone 객체 생성
* @param OmokCoord locate	: 생성될 오목알의 좌표
* @param StoneType type		: 생성될 오목알 종류
* @return Stone				: 생성된 객체
*
* @author lja3723
* @date 2020-11-27 00:20
* @version 0.0.1
*/
Stone _Stone(OmokCoord locate, StoneType type);

/**
* @fn set_Stone(Stone* obj, OmokCoord locate, StoneType type);
* @brief Stone 객체 생성
* @param Stone* obj			: 설정할 객체
* @param OmokCoord locate	: 설정할 오목알의 좌표
* @param StoneType type		: 설정할 오목알 종류
* @return void
*
* @author lja3723
* @date 2020-11-27 00:20
* @version 0.0.1
*/
int set_Stone(Stone* obj, OmokCoord locate, StoneType type);

/** 
* @fn Stone OmokCursor_to_Stone(OmokCursor* obj);
* @brief OmokCursor 객체를 Stone 객체로 변환
* @param OmokCursor* obj	: 변환할 OmokCursor의 주소값
* @return Stone				: 변환된 Stone 객체
*
* @author
* @date
* @version
*/
Stone OmokCursor_to_Stone(OmokCursor* obj);



/*******************************************************************
*					StoneNode management
* 생성(_) 설정(set)
* 동적 생성(new)
* 복사(copy) 제거(delete)
********************************************************************/

/**
* @fn StoneNode _StoneNode(Stone stone, struct _STONENODE* next);
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/
StoneNode _StoneNode(Stone stone, struct _STONENODE* next);

/**
* @fn int Set_StoneNode(Stone* obj, Stone stone, struct _STONENODE* next);
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/
int Set_StoneNode(Stone* obj, Stone stone, struct _STONENODE* next);

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
//StoneNote* 




/*******************************************************************
*					StoneStorage management
* 생성(_) 설정(set)
* 복사(copy) 제거(delete)
********************************************************************/






/*******************************************************************
*					OmokPanelType management
* 생성(_)
********************************************************************/

/**
* @fn OmokPanelType _OmokPanelType(const char *str);
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/
OmokPanelType _OmokPanelType(const char *str);




/*******************************************************************
*					OmokPanel management
* 생성(_) 설정(set)
* 복사(copy) 제거(delete)
********************************************************************/






/*******************************************************************
*					OmokStatus management
* 생성(_) 설정(set)
********************************************************************/

/**
* @fn OmokStatus _OmokStatus(StoneType whose_turn, int turns, OmokCoord prev_put_locate);
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/
OmokStatus _OmokStatus(StoneType whose_turn, int turns, OmokCoord prev_put_locate);

/**
* @fn int set_OmokStatus(OmokStatus* obj, StoneType whose_turn, int turns, OmokCoord prev_put_locate);
* @brief
* @param
* @return
*
* @author
* @date
* @version
*/
int set_OmokStatus(OmokStatus* obj, StoneType whose_turn, int turns, OmokCoord prev_put_locate);



/*******************************************************************
*					Omok management
* 생성(_) 설정(set)
* 복사(copy) 제거(delete)
********************************************************************/






/********************************* /본문 *************************************/
#endif