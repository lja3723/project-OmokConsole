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
*	[공통 함수 종류]
* 생성			_객체()
* 설정			set_객체()
* 변환			변환할객체_to_변환될객체()
* 
*	(다음은 문자열로 생성, 설정하는 함수임)
* 문자열로 생성	_s객체()
* 문자열로 설정	set_s객체()
* 
* < !주의 >
* 공통 함수 이외에, 각 객체에 특화된 manage 함수가 존재할 수 있음
*
* 
* 
* [공통 함수 설명]
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
* 이름				: 변환할객체_to_변환된객체()
* 첫 매개변수		: 변환할객체의 주소값
* 그 외 매개변수		: 없음
* 반환값				: 지역변수 형태의 변환된객체(변환될객체가 '동적 할당이 필요한 멤버'가 있을 경우 깊은 복사 수행됨)
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
* next 노드 분리(detach_nextStoneNode)
* next 노드 연결(attach_nextStoneNode)
* 깊은 복사(deepcopy)
********************************************************************/

/**
* @fn StoneNode _StoneNode(Stone stone, StoneNode* next);
* @brief StoneNode 객체 생성(동적 할당 없음)
* @param Stone stone				: 생성될 객체의 Stone 정보
* @param struct _STONENODE* next	: 생성될 객체의 next 정보
* @return StoneNode					: 생성된 StoneNode 객체
*
* @author lja3723
* @date 2020-11-27 18:50
* @version 0.0.1
*/
StoneNode _StoneNode(Stone stone, StoneNode* next);

/**
* @fn void set_StoneNode(StoneNode* obj, Stone stone, StoneNode* next);
* @brief StoneNode 객체 설정
* @param Stone* obj			: 설정할 객체의 주소값
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
* @param Stone stone		: 동적 생성될 객체의 Stone 정보
* @param StoneNode* next	: 동적 생성될 객체의 next 정보
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
* @fn StoneNode* connect_nextStoneNode(StoneNode* obj, StoneNode* target);
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
* 초기화(init) 마무리(finalize)
* 깊은 복사(deepcopy)
* 타입 수정(modify_type)
* 오목알 저장(save_Stone_to)
* 오목알 보기(view_Stone_from)
* 오목알 삭제(delete_Stone_from)
* 오목알 모두 삭제(clear_all_Stone_from)
* 
********************************************************************/

/**
* @fn int init_StoneList(StoneList* obj, OmokPanelType type);
* @brief StoneList 객체(정적 변수)를 type에 맞게 초기화함.
*		초기화한 객체는 사용 후 메모리 누수를 방지하기 위해 반드시 마무리 함수(finalize)의 인자로 전달해야 함
* @param StoneList* obj	: 초기화할 정적 StoneList 객체의 주소값
* @param OmokPanelType type	: 초기화될 객체의 오목판 크기
* @return int				: 잘 초기화되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 13:42
* @version 0.0.1
*/
int init_StoneList(StoneList* obj, OmokPanelType type);

/**
* @fn int finalize_StoneList(StoneList* obj);
* @brief 초기화된 StoneList 객체(정적 변수)를 초기화 해제(마무리)하는 함수
* @param StoneList* obj	: 초기화 해제할 정적 StoneList 객체의 주소값
* @return int				: 잘 마무리되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 13:49
* @version 0.0.1
*/
int finalize_StoneList(StoneList* obj);

/**
* @fn int deepcopy_StoneList(StoneList* obj, StoneList* target);
* @brief 초기화된 정적 StoneList 객체(target)를 obj에 깊은 복사하는 함수
* @param StoneList* obj		: 깊은 복사된 StoneList 객체를 저장할 주소값, 초기화되지 않은 객체여야 함
* @param StoneList* target	: 깊은 복사할 목표 객체의 주소값, 초기화된 객체여야 함
* @return int					: 깊은 복사가 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 13:50
* @version 0.0.1
*/
int deepcopy_StoneList(StoneList* obj, StoneList* target);

/**
* @fn int modify_type_StoneList(StoneList* obj, OmokPanelType* type);
* @brief obj의 type을 수정하는 함수. obj은 초기화된 객체여야 함. 
		변경할 type이 기존 type보다 작다면 정보가 손실될 수 있음
* @param StoneList* obj		: type을 수정할 초기화된 StoneList 객체의 주소값
* @param OmokPanelType* type	: obj에 새로 적용할 오목판 종류 정보
* @return int					: 수정이 잘 되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 13:50
* @version 0.0.1
*/
int modify_type_StoneList(StoneList* obj, OmokPanelType* type);

/**
* @fn int save_Stone_to(StoneList* obj, Stone stone);
* @brief StoneList에 바둑알을 저장함
* @param StoneList* obj		: 바둑알을 저장할 StoneList 객체의 주소값(초기화된 상태여야 함)
* @param Stone stone			: 저장할 바둑알 정보
* @return int					: 잘 저장되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 14:30
* @version 0.0.1
*/
int save_Stone_to(StoneList* obj, Stone stone);

/**
* @fn Stone view_Stone_from(StoneList* obj, OmokCoord locate);
* @brief obj에서 locate에 있는 바둑알을 보여주는 함수(바둑알은 제거되지 않음)
* @param StoneList* obj	: 바둑알을 볼 객체의 주소값(초기화된 상태여야 함)
* @param OmokCoord locate	: 바둑알을 볼 좌표
* @return int				: locate에 바둑알이 있으면 바둑알 객체가, 
		없으면 바둑알 종류가 ERR_ST인 바둑알 객체가 반환됨
*
* @author lja3723
* @date 2020-11-28 14:35
* @version 0.0.1
*/
Stone view_Stone_from(StoneList* obj, OmokCoord locate);

/**
* @fn int delete_Stone_from(StoneList* obj, OmokCoord locate);
* @brief StoneList 객체의 locate에 있는 바둑알을 제거함
* @param StoneList* obj	: 바둑알을 제거할 StoneList 객체의 주소값(초기화된 상태여야 함)
* @param OmokCoord locate	: 제거할 바둑알의 좌표
* @return int				: 제거되었으면 1, 좌표에 바둑알이 없거나 제거가 안됐으면 0 반환
*
* @author lja3723
* @date 2020-11-28 14:35
* @version 0.0.1
*/
int delete_Stone_from(StoneList* obj, OmokCoord locate);

/**
* @fn int clear_all_Stone_from(StoneList* obj);
* @brief obj에 저장된 모든 바둑알을 제거하는 함수
* @param StoneList* obj	: 바둑알을 모두 제거할 StoneList 객체의 주소값(초기화된 상태여야 함)
* @return int				: 잘 제거되었으면 1, 그렇지 않으면 0 반환
*
* @author lja3723
* @date 2020-11-28 14:48
* @version 0.0.1
*/
int clear_all_Stone_from(StoneList* obj);

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
* 타입 수정(modify_type)
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



/*******************************************************************
* TODO:	
*					OmokStatus management
* 
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
void set_OmokStatus(OmokStatus* obj, StoneType whose_turn, int turns, OmokCoord prev_put_locate);



/*******************************************************************
* TODO:	
*					Omok management
* 생성(_) 설정(set)
* 복사(copy) 제거(delete)
********************************************************************/






/********************************* /본문 *************************************/
#endif