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
*	[공통 함수 종류(1)]
* 생성			_객체()
* 설정			set_객체()
* 변환			변환할객체_to_변환될객체()
* 
*	(다음은 문자열로 생성, 설정하는 함수임)
* 문자열로 생성	_s객체()
* 문자열로 설정	set_s객체()
* 
* [공통 함수 종류(2)] - 내부적으로 malloc 함수가 사용되는 경우
* (다음은 객체를 동적 생성, 동적 해제하는 함수임)
* 동적 생성(new) 
* 동적 해제(free) 
* 
* (다음은 new, free 함수가 있는 객체이거나, 객체를 포함할때 정의되는 함수임)
* 초기화(init) 
* 마무리(finalize)
* 깊은 복사(deepcopy)
* 
* 
* < !주의 >
* 공통 함수 이외에, 각 객체에 특화된 manage 함수가 존재할 수 있음
*
* 
* 
* [공통 함수 설명(1)]
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
* [객체 문자열로 생성(_s) 함수]
* 객체를 알맞은 형식의 문자열로 생성
* 
* 이름				: _s객체()
* 매개변수			: 알맞은 형식의 문자열
* 반환값				: 생성된 객체 반환
*
* 
* [객체 문자열로 설정(set_s) 함수]
* 객체 설정 계열 함수는 객체를 주어진 인자로 설정하는 역할을 담당함
* '동적 할당이 필요한 멤버'가 있는 객체는 반드시 객체 사용 후 delete 함수를 호출해야 함
*
* 이름				: set_s객체()
* 첫 매개변수		: 설정할 객체의 주소값
* 그 외 매개변수		: 알맞은 형식의 문자열
* 반환값				: void
*
*
* [객체 변환(_to_) 함수]
* 객체 변환 계열 함수는 변환할객체를 변환될객체로 변환하는 역할을 담당함
* 이때 객체 복사가 수행되며 복사된 객체가 리턴됨
*
* 이름			: 변환할객체_to_변환된객체()
* 매개변수		: 변환할객체의 주소값
* 반환값			: 지역변수 형태의 변환된객체
*
* 
* 
* [공통 함수 설명(2)] - 내부적으로 malloc 함수가 사용되는 경우
* [동적 생성(new) 함수]
* 객체를 동적 생성한 뒤 객체의 주소값을 반환하는 역할을 담당함
* 이때 인자로 전달된 객체가 동적 할당 객체로 얕은 복사 수행되며
* 이 함수로 만들어진 동적 객체는 추후 반드시 free 함수의 인자로 전달되야 함
* 
* 이름			: new_객체()
* 매개변수		: 동적 할당된 객체를 설정할 정적 객체
* 반환값			: 동적 할당된 객체의 주소값 (얕은 복사됨)
* 
* 
* [동적 해제(free) 함수]
* new로 동적 생성된 객체를 해제하는 역할을 담당함
* 
* 이름			: free_객체()
* 매개변수		: 해제할 동적 할당된 객체
* 반환값			: 정상 해제되면 1, 그렇지 않으면 0 반환
* 
* 
* [초기화(init) 함수]
* new나 free 함수가 있는 객체가 포함된 객체를 초기화하는 함수
* 이 함수가 있는 객체는 반드시 초기화 함수(init)를 통해 초기화해야 하며,
* 객체의 동적 생성을 하지 않아야 함
* 그리고 객체를 사용하지 않을 때 finalize 함수의 인자로 전달해야 함
* 
* 이름			: init_객체()
* 첫 매개변수	: 초기화할 정적 선언 객체의 주소값
* 그 외 매개변수	: 객체마다 다름
* 반환값			: 정상 초기화되면 1, 그렇지 않으면 0 반환
* 
* 
* [마무리(finalize) 함수]
* init 함수로 초기화된 객체를 초기화 해제하는 함수
* 
* 이름		: finalize_객체()
* 매개변수	: 초기화 해제할 정적 선언 객체의 주소값
* 반환값		: 정상적으로 마무리되면 1, 그렇지 않으면 0 반환
* 
* 
* [깊은 복사(deepcopy) 함수]
* new 함수가 있는 객체거나 그 객체를 포함하는 객체를 깊은 복사하는 함수
* 
* 이름			: deepcopy_객체()
* 첫 매개변수	: 깊은 복사될 객체를 저장할 객체의 주소값
* 그 외 매개변수	: 깊은 복사를 할 객체의 주소값
* 반환값			: 정상적으로 깊은 복사되면 1, 그렇지 않으면 0 반환
* 
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
* TODO:	Done
*					OmokCoord management
* 생성(_) 설정(set)
* 문자열로 생성(_s) 문자열로 설정(set_s)
******************************************************************/

/**
* @fn OmokCoord _OmokCoord(char row, short col);
* @brief OmokCoord 생성
* @param char row		: 생성할 객체의 행 정보, 범위: 'A' ~ 'Z', 인자가 잘못되면 '\\0'으로 초기화
* @param short col		: 생성할 객체의 열 정보, 범위: 1 ~ 19, 인자가 잘못되면 0으로 초기화
* @return OmokCoord		: 생성된 객체
*
* @author daol
* @date 2020-11-27 02:27
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
* @author daol
* @date 2020-11-27 02:27
* @version 0.0.1
*/
void set_OmokCoord(OmokCoord* obj, char row, short col);

/**
* @fn OmokCoord _sOmokCoord(const char* str);
* @brief 문자열로 OmokCoord 생성
* @param const char* str	: 형식은 "a19" 또는 "A19"이어야 하며, 인자가 잘못되면 row는 '\\0', col은 0으로 초기화
* @return OmokCoord			: 생성된 객체 반환
*
* @author daol
* @date 2020-11-27 02:27
* @version 0.0.1
*/
OmokCoord _sOmokCoord(const char* str);

/**
* @fn OmokCoord Str_to_OmokCoord(const char* str);
* @brief 문자열로 OmokCoord 설정
* @param OmokCoord* obj		: 설정할 OmokCoord 객체
* @param const char* set	: 형식은 "a19" 또는 "A19"이어야 하며, 인자가 잘못되면 row는 '\\0', col은 0으로 초기화
* @return					: void
*
* @author lja3723
* @date 2020-11-27 20:10
* @version 0.0.1
*/
void set_sOmokCoord(OmokCoord* obj, const char* set);



/*******************************************************************
* TODO: Done
*					StoneType management
* 문자열로 생성(_s)
********************************************************************/

/**
* @fn StoneType _StoneType(const char* str);
* @brief 문자열로 StoneType 생성
* @param const char* str	: 생성할 StoneType에 해당하는 문자열("w", "W", "white", "White", "b", "B", "black", "Black")
* @return StoneType			: Black 또는 White 반환, 변환 오류시 ERR_ST 반환
*
* @author daol
* @date 2020-11-27 02:27
* @version 0.0.1
*/
StoneType _sStoneType(const char* str);



/*******************************************************************
* TODO:	Done
*					OmokCursor management
* 생성(_) 설정(set) 
* 문자열로 생성(_s) 문자열로 설정(set_s)
변환(Stone|_to_)
********************************************************************/

/**
* @fn OmokCursor _OmokCursor(OmokCoord locate, StoneType type);
* @brief OmokCursor 객체 생성
* @param OmokCoord locate	: 생성되는 커서의 좌표
* @param StoneType type		: 생성되는 커서의 오목알 타입
* @return OmokCursor		: 생성된 객체
*
* @author daol 
* @date 2020-11-27 02:27
* @version 0.0.1 
*/
OmokCursor _OmokCursor(OmokCoord locate, StoneType type);

/**
* @fn int set_OmokCursor(OmokCursor *obj, OmokCoord locate, StoneType type);
* @brief OmokCursor 설정
* @param OmokCursor *obj	: 설정할 객체의 주소값
* @param OmokCoord locate	: 좌표 설정값
* @param StoneType type		: 오목알 타입 설정값
* @return void
*
* @author daol
* @date 2020-11-27 02:28
* @version 0.0.1
*/
void set_OmokCursor(OmokCursor* obj, OmokCoord locate, StoneType type);

/**
* @fn OmokCursor _sOmokCursor(const char* locate, const char* type);
* @brief 문자열으로 OmokCursor 객체 생성
* @param const char* locate	: 문자열 형식의 좌표("a19", "A19")
* @param const char* type	: 문자열 형식의 오목알 타입("W", "black" 등)
* @return OmokCursor		: 생성된 객체
*
* @author lja3723
* @date 2020-11-27 20:30
* @version 0.0.1
*/
OmokCursor _sOmokCursor(const char* locate, const char* type);

/**
* @fn void set_sOmokCursor(OmokCursor* obj, const char* locate, const char* type);
* @brief 문자열으로 OmokCursor 설정
* @param OmokCursor *obj	: 설정할 객체의 주소값
* @param OmokCoord locate	: 문자열 형식의 좌표 설정값("a19", "A19")
* @param StoneType type		: 문자열 형식의 오목알 타입 설정값("W", "black" 등)
* @return void
*
* @author lja3723
* @date 2020-11-27 20:30
* @version 0.0.1
*/
void set_sOmokCursor(OmokCursor* obj, const char* locate, const char* type);

/** 
* @fn OmokCursor Stone_to_OmokCursor(Stone *obj);
* @brief Stone 객체를 OmokCursor로 변환
* @param Stone *obj	: 변환할 Stone 객체의 주소값
* @return			: 변환된 Cursor 객체
*
* @author daol
* @date 2020-11-27 02:27
* @version 0.0.1
*/
OmokCursor Stone_to_OmokCursor(Stone *obj);



/*******************************************************************
* TODO:	Done
*					Stone management
* 생성(_) 설정(set) 
* 문자열로 생성(_s) 문자열로 설정(set_s) 
* 변환(OmokCursor|_to_)
********************************************************************/

/**
* @fn _Stone(OmokCoord locate, StoneType type);
* @brief Stone 객체 생성
* @param OmokCoord locate	: 생성될 오목알의 좌표
* @param StoneType type		: 생성될 오목알 종류
* @return Stone				: 생성된 객체
*
* @author daol
* @date 2020-11-27 02:30
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
* @author daol
* @date 2020-11-27 02:30
* @version 0.0.1
*/
void set_Stone(Stone* obj, OmokCoord locate, StoneType type);

/**
* @fn Stone _sStone(const char* locate, const char* type);
* @brief 문자열으로 Stone 객체 생성
* @param const char* locate	: 문자열로 표현된 오목알 객체("a19" 또는 "A19")
* @param const char* type	: 문자열로 표현된 오목알 종류("w", "white", "Black" 등)
* @return Stone				: 변환된 Stone 객체
*
* @author lja3723
* @date 2020-11-27 19:05
* @version 0.0.1
*/
Stone _sStone(const char* locate, const char* type);

/**
* @fn set_Stone(Stone* obj, OmokCoord locate, StoneType type);
* @brief 문자열로 Stone 객체 설정
* @param const char* locate	: 문자열로 표현된 오목알 객체 설정값("a19" 또는 "A19")
* @param const char* type	: 문자열로 표현된 오목알 종류 설정값("w", "white", "Black" 등)
* @return void
*
* @author lja3723
* @date 2020-11-27 10:35
* @version 0.0.1
*/
void set_sStone(Stone* obj, const char* locate, const char* type);

/** 
* @fn Stone OmokCursor_to_Stone(OmokCursor* obj);
* @brief OmokCursor 객체를 Stone 객체로 변환
* @param OmokCursor* obj	: 변환할 OmokCursor의 주소값
* @return Stone				: 변환된 Stone 객체
*
* @author lja3723
* @date 2020-11-27 20:40
* @version 0.0.1
*/
Stone OmokCursor_to_Stone(OmokCursor* obj);



/*******************************************************************
* TODO:	Done
*					StoneNode management
* 생성(_) 설정(set)
* 동적 생성(new) 동적 해제(free) 
* 
* next 노드 분리(detach_nextStoneNode)
* next 노드 연결(attach_nextStoneNode)
* 깊은 복사(deepcopy)
********************************************************************/

/**
* @fn StoneNode _StoneNode(Stone stone, StoneNode* next);
* @brief StoneNode 객체 생성(동적 할당 없음)
* @param Stone stone		: 생성될 객체의 Stone 정보
* @param StoneNode* next	: 생성될 객체의 next 정보
* @return StoneNode			: 생성된 StoneNode 객체
*
* @author lja3723
* @date 2020-11-27 18:50
* @version 0.0.1
*/
StoneNode _StoneNode(Stone stone, StoneNode* next);

/**
* @fn void set_StoneNode(StoneNode* obj, Stone stone, StoneNode* next);
* @brief StoneNode 객체 설정
* @param StoneNode* obj		: 설정할 객체의 주소값
* @param Stone stone		: 설정할 stone 정보
* @param StoneNode* next	: 설정할 next 정보
* @return void
*
* @author lja3723
* @date 2020-11-27 18:50
* @version 0.0.1
*/
void set_StoneNode(StoneNode* obj, Stone stone, StoneNode* next);

/**
* @fn StoneNode* new_StoneNode(StoneNode obj);
* @brief obj 정보로 초기화한 동적 할당된 객체 주소값을 반환(단 동적할당 실패시 NULL 반환).
*		이 함수로 받은 주소값은 메모리 누수를 방지하기 위해 반드시
*		사용 후 free_StoneNode의 인자로 전달해야함.
*		<!주의> 반환된 객체는 얕은 복사된 상태임
* @param StoneNode obj		: 동적 생성될 객체 정보(정적 변수 권장)
* @return StoneNode*		: 동적 생성된 객체의 주소값, 동적 할당 실패시 NULL 반환
*
* @author lja3723
* @date 2020-11-27 18:50
* @version 0.0.1
*/
StoneNode* new_StoneNode(StoneNode obj);

/**
* @fn int free_StoneNode(StoneNode* obj);
* @brief 동적 할당된 StoneNode 객체를 해제하는 역할을 함.
*		<!주의> NextNode에 동적 할당 객체가 연결되어 있으면 재귀적으로 해제되며, 
		obj을 가리키는 또 다른 StoneNode 객체가 없어야 함
* 
* @param StoneNode* obj	: 동적 해제하려는 StoneNode 객체의 주소값
* @return int			: 정상 해제되었으면 1, 그렇지 않으면 0을 반환
*
* @author lja3723
* @date 2020-11-27 18:50
* @version 0.0.1
*/
int free_StoneNode(StoneNode* obj);

/**
* @fn StoneNode* detach_nextStoneNode(StoneNode* obj);
* @brief 인자로 전달된 객체의 nextNode를 분리 후, 분리된 nextNode의 주소값 반환.
*		분리후 obj의 nextNode는 NULL임
* @param StoneNode* obj	: nextNode를 분리하려는 객체의 주소값
* @return StoneNode*	: 분리된 nextNode의 주소값
*
* @author lja3723
* @date 2020-11-27 21:40
* @version 0.0.1
*/
StoneNode* detach_nextStoneNode(StoneNode* obj);

/**
* @fn int attach_nextStoneNode(StoneNode* obj, StoneNode* target);
* @brief 인자로 전달된 obj 객체의 next에 target 객체를 연결함.
*		<!주의> obj의 next는 반드시 NULL이거나 free가 되지 않은 동적 객체어야 하고, 
				target은 반드시 동적 할당된 객체여야 함.
* @param StoneNode* obj		: target을 가리키고자 하는 StoneNode 객체
* @param StoneNode* target	: obj의 nextNode에 연결될 목표 객체
* @return int				: 연결이 성공하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-27 22:15
* @version 0.0.1
*/
int attach_nextStoneNode(StoneNode* obj, StoneNode* target);

/**
* @fn StoneNode copy_StoneNode(StoneNode* obj);
* @brief 동적 할당된 obj 깊은 복사함. 이때
		obj의 nextNode가 동적 할당 객체라면 재귀적으로 깊은 복사함
* @param StoneNode* obj	: 깊은 복사할 동적 할당된 StoneNode 객체
* @return StoneNode		: 깊은 복사 성공지 깊은 복사된 객체 반환, 
		깊은 복사 실패하거나 obj가 동적 할당된 객체가 아니면 NULL 반환
*
* @author lja3723
* @date 2020-11-27 23:30
* @version 0.0.1
*/
StoneNode* deepcopy_StoneNode(StoneNode* obj);



/*******************************************************************
* TODO:	선언 및 빈 정의 완료. 함수 내용 작성해야 함
*					StoneList management
* 생성(_) 동적 생성(new) 동적 해제(free)
* 
* 노드추가(addNode_to)
* 노드제거(deleteNode_from)
* 모든 노드 클리어(clearallNode_from)
* 깊은 복사(deepcopy)
********************************************************************/

/**
* @fn StoneList _StoneList(int size, StoneNode* header);
* @brief StoneList 객체 생성(동적 할당 없음)
* @param int size			: 생성될 객체의 size 정보
* @param StoneNode* header	: 생성될 객체의 header 정보
* @return StoneList			: 생성된 StoneList 객체
*
* @author lja3723
* @date 2020-11-28 15:50
* @version 0.0.1
*/
StoneList _StoneList(int size, StoneNode* header);

/**
* @fn StoneList* new_StoneList(StoneList obj);
* @brief obj 정보로 초기화한 동적 할당된 객체 주소값을 반환(단 동적할당 실패시 NULL 반환).
*		이 함수로 받은 주소값은 메모리 누수를 방지하기 위해 반드시
*		사용 후 free_StoneList의 인자로 전달해야함.
*		<!주의> 반환된 객체는 얕은 복사된 상태임
* @param StoneList obj		: 동적 생성될 객체 정보(정적 변수 권장)
* @return StoneList*		: 동적 생성된 객체의 주소값, 동적 할당 실패시 NULL 반환
*
* @author lja3723
* @date 2020-11-28 16:00
* @version 0.0.1
*/
StoneList* new_StoneList(StoneList obj);

/**
* @fn int free_StoneList(StoneList* obj);
* @brief 동적 할당된 StoneList 객체를 해제하는 역할을 함.
*		<!주의> NextList의 header에 동적 할당 객체가 연결되어 있으면 재귀적으로 해제됨
*
* @param StoneList* obj	: 동적 해제하려는 StoneList 객체의 주소값
* @return int			: 정상 해제되었으면 1, 그렇지 않으면 0을 반환
*
* @author lja3723
* @date 2020-11-28 16:00
* @version 0.0.1
*/
int free_StoneList(StoneList* obj);

/**
* @fn int addNode_to(StoneList* list, StoneNode node);
* @brief list에 node를 추가하는 함수
* @param StoneList* list	: node를 추가하고자 하는 StoneList 객체의 주소값
* @param StoneNode node		: 추가하려는 StoneNode 객체(정적 변수 권장)
* @return int				: 잘 추가되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 16:10
* @version 0.0.1
*/
int addNode_to(StoneList* list, StoneNode node);

/**
* @fn int deleteNode_from(StoneList* list, StoneNode node);
* @brief list의 node를 제거하는 함수
* @param StoneList* list	: node를 제거하고자 하는 StoneList 객체의 주소값
* @param StoneNode node		: 제거하려는 StoneNode 객체 정보(정적 변수 권장)
* @return int				: 잘 제거되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 16:10
* @version 0.0.1
*/
int deleteNode_from(StoneList* list, StoneNode node);

/**
* @fn int clearallNode_from(StoneList* list);
* @brief list의 모든 node를 제거하는 함수
* @param StoneList* list	: 모든 node를 제거하고자 하는 StoneList 객체의 주소값
* @return int				: 작업이 잘 수행되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 16:10
* @version 0.0.1
*/
int clearallNode_from(StoneList* list);

/**
* @fn int deepcopy_StoneList(StoneList* obj, StoneList* target);
* @brief 초기화된 정적 StoneList 객체(target)를 obj에 깊은 복사하는 함수
* @param StoneList* obj		: 깊은 복사된 StoneList 객체를 저장할 주소값, 초기화되지 않은 객체여야 함
* @param StoneList* target	: 깊은 복사할 목표 객체의 주소값, 초기화된 객체여야 함
* @return int				: 깊은 복사가 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 13:50
* @version 0.0.1
*/
int deepcopy_StoneList(StoneList* obj, StoneList* target);



/*******************************************************************
* TODO:	Done
*					OmokPanelType management
* 문자열로 생성(_s)
********************************************************************/

/**
* @fn OmokPanelType _sOmokPanelType(const char *str);
* @brief 문자열로 OmokPanelType을 생성
* @param const char *str	: 양식에 맞는 문자열("regular", "r", "jumbo", "J" 등)
* @return OmokPanelType		: 생성된 OmokPanelType 객체
*
* @author lja3723
* @date 2020-11-28 00:10
* @version 0.0.1
*/
OmokPanelType _sOmokPanelType(const char *str);



/*******************************************************************
* TODO:	선언 및 빈 정의 완료. 함수 내용 작성해야 함
*					OmokPanel management
* 초기화(init) 마무리(finalize)
* 깊은 복사(deepcopy)
* 
* 타입 수정(modify_type)
* 오목알 추가(addStone_to)
* 오목알 찾기(lookupStone_from)		//omokobj_judge.h로 이동 요망
* 오목알 삭제(deleteStone_from)
* 오목알 모두 삭제(clearallStone_from)
* 
* 좌표에 있는 Node 포인터 얻기(get_StoneNodeptr_from)
********************************************************************/

/**
* @fn int init_OmokPanel(OmokPanel* obj, OmokPanelType type);
* @brief OmokPanel 객체(정적 변수)를 type에 맞게 초기화함.
*		초기화한 객체는 사용 후 메모리 누수를 방지하기 위해 반드시 마무리 함수(finalize)의 인자로 전달해야 함
* @param OmokPanel* obj		: 초기화할 정적 OmokPanel 객체의 주소값
* @param OmokPanelType type	: 초기화될 객체의 오목판 크기
* @return int				: 잘 초기화되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 15:10
* @version 0.0.1
*/
int init_OmokPanel(OmokPanel* obj, OmokPanelType type);

/**
* @fn int finalize_OmokPanel(OmokPanel* obj);
* @brief 초기화된 OmokPanel 객체(정적 변수)를 초기화 해제(마무리)하는 함수
* @param OmokPanel* obj		: 초기화 해제할 정적 OmokPanel 객체의 주소값
* @return int				: 잘 마무리되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 15:10
* @version 0.0.1
*/
int finalize_OmokPanel(OmokPanel* obj);

/**
* @fn int deepcopy_OmokPanel(OmokPanel* obj, OmokPanel* target);
* @brief 초기화된 정적 OmokPanel 객체(target)를 obj에 깊은 복사하는 함수
* @param OmokPanel* obj		: 깊은 복사된 OmokPanel 객체를 저장할 주소값, 초기화되지 않은 객체여야 함
* @param OmokPanel* target	: 깊은 복사할 목표 객체의 주소값, 초기화된 객체여야 함
* @return int				: 깊은 복사가 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 15:10
* @version 0.0.1
*/
int deepcopy_OmokPanel(OmokPanel* obj, OmokPanel* target);

/**
* @fn int modify_type_OmokPanel(OmokPanel* obj, OmokPanelType type);
* @brief obj의 type을 수정하는 함수. obj은 초기화된 객체여야 함.
		변경할 type이 기존 type보다 작다면 정보가 손실될 수 있음
* @param OmokPanel* obj			: type을 수정할 초기화된 OmokPanel 객체의 주소값
* @param OmokPanelType* type	: obj에 새로 적용할 오목판 종류 정보
* @return int					: 수정이 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 15:10
* @version 0.0.1
*/
int modify_type_OmokPanel(OmokPanel* obj, OmokPanelType type);

/**
* @fn int addStone_to(OmokPanel* panel, Stone stone);
* @brief OmokPanel에 오목알을 추가함
* @param OmokPanel* panel	: 오목알을 추가할 OmokPanel 객체의 주소값(초기화된 상태여야 함)
* @param Stone stone		: 추가할 오목알 정보
* @return int				: 잘 추가되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 17:05
* @version 0.0.1
*/
int addStone_to(OmokPanel* panel, Stone stone);

//omokobj_judge.h로 이동 요망
/**
* @fn StoneType lookupStone_from(OmokPanel* panel, OmokCoord locate);
* @brief panel에서 locate에 있는 오목알의 종류를 알려줌 (검사된 오목알은 제거되지 않음)
* @param OmokPanel* panel	: 오목알을 찾을 OmokPanel 객체의 주소값(초기화된 상태여야 함)
* @param OmokCoord locate	: 찾을 오목알의 좌표
* @return StoneType			: locate에 오목알이 있으면 오목알 종류(W, B)가,
		없거나 panel이 초기화되지 않았으면 ERR_ST이 반환됨
*
* @author lja3723
* @date 2020-11-28 17:10
* @version 0.0.1
*/
StoneType lookupStone_from(OmokPanel* panel, OmokCoord locate);

/**
* @fn StoneType deleteStone_from(OmokPanel* panel, OmokCoord locate);
* @brief panel에서 locate에 있는 오목알을 제거함
* @param OmokPanel* panel	: 오목알을 제거할 OmokPanel 객체의 주소값(초기화된 상태여야 함)
* @param OmokCoord locate	: 제거할 오목알의 위치
* @return StoneType			: 잘 제거되었으면 제거된 오목알의 형식이, 그렇지 않으면 ERR_ST 반환
*
* @author lja3723
* @date 2020-11-28 17:15
* @version 0.0.1
*/
StoneType deleteStone_from(OmokPanel* panel, OmokCoord locate);

/**
* @fn int clearallStone_from(StoneList* obj);
* @brief obj에 저장된 모든 오목알을 제거하는 함수
* @param OmokPanel* obj	: 오목알을 모두 제거할 OmokPanel 객체의 주소값(초기화된 상태여야 함)
* @return int			: 잘 제거되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 14:48
* @version 0.0.1
*/
int clearallStone_from(OmokPanel* obj);

/**
* @fn StoneNode* get_StoneNodeptr_from(OmokPanel* obj, OmokCoord locate);
* @brief panel의 locate 위치에 있는 StoneNode에 대한 포인터를 반환
* @param OmokPanel* panel	: StoneNode를 찾을 panel
* @param OmokCoord locate	: StoneNode를 찾을 locate
* @return StoneNode*		: locate에 StoneNode가 있으면 포인터, 아니면 NULL 반환
*
* @author lja3723
* @date 2020-11-28 22:30
* @version 0.0.1
*/
StoneNode* get_StoneNodeptr_from(OmokPanel* panel, OmokCoord locate);



/*******************************************************************
* TODO:	함수 선언 및 빈 정의 완료, 실제 정의해야 함
*					OmokStatus management
* 초기화(init) 마무리(finalize)
* 깊은 복사(deepcopy)
* 착수 횟수 초기화(clear)
* 
* 착수 횟수 증가(turns_up)
* 착수 횟수 감소(turns_down)
* 착수 순서 배열 크기 증가(ordersize_up)
* 착수 순서 배열 크기 감소(ordersize_down)
* 
* 착수 횟수 얻기(get_turns)
* 착수 순서 배열 크기 얻기(get_ordersize)
* N번째에 착수된 바둑알 정보 얻기(get_StoneInfo_from)
* 
********************************************************************/

/**
* @fn int init_OmokStatus(OmokStatus* obj);
* @brief 정적 OmokStatus 객체인 obj를 초기화함
* @param OmokStatus* obj	: 초기화할 객체의 주소값
* @return int				: 작업이 성공하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int init_OmokStatus(OmokStatus* obj);

/**
* @fn int finalize_OmokStatus(OmokStatus* obj);
* @brief 초기화된 정적 OmokStatus 객체 obj을 초기화 해제하는 함수
* @param OmokStatus* obj	: 초기화 해제할 객체의 주소값
* @return int				: 작업이 성공하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int finalize_OmokStatus(OmokStatus* obj);

/**
* @fn int deepcopy_OmokStatus(OmokStatus* obj, OmokStatus* target);
* @brief 초기화된 정적 OmokStatus 객체 target을 초기화되지 않은 정적 변수 obj에 깊은 복사하는 함수
* @param OmokStatus* obj	: 깊은 복사된 OmokStatus 객체를 저장할 주소값, 초기화되지 않은 객체여야 함
* @param OmokStatus* target	: 깊은 복사할 목표 객체의 주소값, 초기화된 객체여야 함
* @return int				: 작업이 성공하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int deepcopy_OmokStatus(OmokStatus* obj, OmokStatus* target);

/**
* @fn int clear_OmokStatus(OmokStatus* obj);
* @brief 정적 OmokStatus 객체 obj를 처음 초기화된 상태로 클리어하는 함수
* @param OmokStatus* obj	: 처음 초기화된 상태로 클리어할 객체
* @return int				: 작업이 성공하면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int clear_OmokStatus(OmokStatus* obj);

/**
* @fn int turns_up(OmokStatus* obj, StoneNode* released);
* @brief obj의 착수 횟수를 1 증가시키는 함수. 기존의 착수 횟수가 N일 때
*		함수를 실행하면 착수 횟수는 N + 1이 되고,released는 오목판 위에 
*		N+1번째로 추가된 StoneNode의 주소값이어야 함
* @param OmokStatus* obj		: 착수 횟수를 1 증가시킬 OmokStatus 객체(초기화된 상태여야 함)
* @param StoneNode* released	: 오목판에 가장 최근에 추가된 StoneNode 객체의 주소값
* @return int					: 잘 증가되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int turns_up(OmokStatus* obj, StoneNode* released);

/**
* @fn StoneNode* turns_down(OmokStatus* obj);
* @brief obj의 착수 횟수를 1 감소시키는 함수. 기존의 착수 횟수가 N일 때
*		함수를 실행하면 착수 횟수는 N - 1이 되고, N번째 착수된 StoneNode 객체의
*		주소값이 반호나됨
* @param OmokStatus* obj	: 착수 횟수를 1 감소시킬 OmokStatus 객체(초기화된 상태여야 함)
* @return StoneNode*		: 착수 횟수가 잘 감소되었으면 마지막으로 착수되었던 StoneNode 객체의 주소값이,
*		그렇지 않으면 NULL을 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
StoneNode* turns_down(OmokStatus* obj);

/**
* @fn int ordersize_up(OmokStatus* obj);
* @brief OmokStatus 객체의 착수 순서 저장 배열의 크기를 증가시키는 함수
*		배열의 크기는 buff만큼 증가됨
* @param OmokStatus* obj	: 착수순서 저장배열의 크기를 증가시킬 OmokStatus 객체의 주소값(정적변수가 전제됨)
* @return int				: 착수순서 저장배열의 크기가 증가되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int ordersize_up(OmokStatus* obj);

/**
* @fn int ordersize_down(OmokStatus* obj);
* @brief 객체의 착수 순서 저장 배열의 크기를 감소시키는 함수. 
*		배열의 크기는 buff만큼 감소됨
		<!주의> 경우에 따라 착수 순서 정보가 손실될 수 있음
* @param OmokStatus* obj	: 착수순서 저장배열의 크기를 감소시킬 OmokStatus 객체의 주소값(정적변수가 전제됨)
* @return int				: 착수순서 저장배열의 크기가 감소되었으면 1, 그렇지 않으면 0
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int ordersize_down(OmokStatus* obj);

/** 
* @fn int get_turns(OmokStatus* obj);
* @brief OmokStatus의 착수 횟수를 반환
* @param OmokStatus* obj	: 착수 횟수를 알고 싶은 OmokStatus 객체
* @return int				: 착수 횟수
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int get_turns(OmokStatus* obj);

/**
* @fn int get_ordersize(OmokStatus* obj);
* @brief OmokStatus의 착수순서 저장배열의 크기를 반환
* @param OmokStatus* obj	: 착수순서 저장배열의 크기를 알고 싶은 OmokStatus 객체
* @return int				: 착수순서 저장배열의 크기
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
int get_ordersize(OmokStatus* obj);

/**
* @fn Stone get_StoneInfo_from(OmokStatus* obj, int turns);
* @brief obj에서 turns번째에 착수된 오목알 정보를 구하는 함수
* @param OmokStatus* obj	: turns번째에 착수된 오목알 정보를 구하고자 하는 OmokStatus 객체
* @param int turns			: 착수 횟수 정보
* @return Stone				: turns번째에 착수된 오목알이 있으면 그에 대한 정보가, 
		그렇지 않으면 StoneType이 ERR_ST인 Stone 객체가 반환됨
*
* @author lja3723
* @date 2020-11-29 00:15
* @version 0.0.1
*/
Stone get_StoneInfo_from(OmokStatus* obj, int turns);



/*******************************************************************
* TODO:	
*					Omok management
* 초기화(init) 마무리(finalize)
* 깊은 복사(deepcopy)
********************************************************************/

/**
* @fn int init_Omok(Omok* obj, OmokPanelType type);
* @brief Omok 객체(정적 변수)를 오목판의 type에 맞게 초기화함.
*		초기화한 객체는 사용 후 메모리 누수를 방지하기 위해 반드시 마무리 함수(finalize)의 인자로 전달해야 함
* @param Omok* obj			: 초기화할 정적 Omok 객체의 주소값(정적 변수 권장)
* @param OmokPanelType type	: 초기화될 객체의 오목판 크기
* @return int				: 잘 초기화되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:20
* @version 0.0.1
*/
int init_Omok(Omok* obj, OmokPanelType type);

/**
* @fn int finalize_Omok(Omok* obj);
* @brief 초기화된 Omok 객체(정적 변수)를 초기화 해제(마무리)하는 함수
* @param Omok* obj	: 초기화 해제할 정적 Omok 객체의 주소값
* @return int		: 잘 마무리되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:20
* @version 0.0.1
*/
int finalize_Omok(Omok* obj);

/**
* @fn int deepcopy_Omok(Omok* obj, Omok* target);
* @brief 초기화된 정적 Omok 객체(target)를 obj에 깊은 복사하는 함수
* @param Omok* obj		: 깊은 복사된 Omok 객체를 저장할 주소값, 초기화되지 않은 객체여야 함
* @param Omok* target	: 깊은 복사할 목표 객체의 주소값, 초기화된 객체여야 함
* @return int			: 깊은 복사가 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-29 00:20
* @version 0.0.1
*/
int deepcopy_Omok(Omok* obj, Omok* target);



/********************************* /본문 *************************************/
#endif