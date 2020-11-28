#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/** OmokStatus의 버퍼 크기 (기본값 8) */
#define __OMOKOBJ_OMOKSTATUS_BUFF__ 8

/**
* @file omokobj.h
*
*	[파일 개요]
* 오목 프로그램에서 사용되는 모든 객체(구조체)를 정의함
* 
*	[객체 종류]
*	설명					이름			  멤버 설명
* 좌표정보 객체		: OmokCoord		행과 열 정보
* 오목알 타입 열거형	: StoneType		오목알 종류
* 커서 객체			: OmokCursor	오목알 정보, 좌표정보
* 오목알 객체		: Stone			오목알 정보, 좌표정보
* 오목알 노드		: StoneNode		오목알 리스트의 구성 객체
* 오목알 리스트		: StoneList		연결 리스트 사용한 구현 
* 오목판 타입 열거형	: OmokPanelType	오목판 종류
* 오목판 객체		: OmokPanel		오목판 크기, 오목알 리스트
* 게임 진행 현황 객체	: OmokStatus	착수 차례, 착수 회수, 착수 좌표정보
* 통합 객체			: Omok			커서, 오목판, 게임 진행 현황 객체
*/



/*************************** 본문 ******************************/



/**
* @struct	OmokCoord
* @brief	좌표정보 객체
* @details	오목판 내 좌표: 행과 열 정보를 표현
* 
* @var char row		: 행 정보
* @var shart col	: 열 정보
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct {
	char row;	/* 행 정보 */
	short col;	/* 열 정보 */
} OmokCoord;



/**
* @enum		StoneType
* @brief	오목알 타입 열거형
* @details	오목알 타입(Black, White)을 표현
* 
* @var Black	: 흑색 오목알
* @var White	: 백색 오목알
* @var ERR_ST	: 에러 발생
*
* @author	lja3723
* @date		2020-11-24	18:05
* @version	0.0.1
*/
typedef enum {
	Black = 0,		/* 흑색 오목알 */
	White = 1,		/* 백색 오목알 */
	ERR_ST = -1		/* 에러 발생 */
} StoneType;



/**
* @struct	OmokCursor
* @brief	커서 객체
* @details	커서의 위치(OmokCoord)와 오목알 정보(StoneType)를 표현
* 
* @var OmokCoord locate		: 커서의 위치
* @var StoneType type		: 커서가 표현하는 오목알 타입(Black, White)
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct {
	OmokCoord locate;	/* 커서의 위치 */
	StoneType type;		/* 커서가 표현하는 오목알 타입(Black, White) */
} OmokCursor;



/**
* @struct	Stone
* @brief	오목알 객체
* @details	오목알의 위치(OmokCoord)와 오목알 정보(StoneType)를 표현
*
* @var OmokCoord locate	: 오목알의 위치
* @var StoneType type	: 오목알 타입(Black, White)
* 
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct {
	OmokCoord locate;	/* 오목알의 위치 */
	StoneType type;		/* 오목알 타입(Black, White) */
} Stone;



/**
* @struct	StoneNode
* @brief	오목알 노드
* @details	오목알 객체를 저장하는 노드 구현
* 
* @var Stone stone				오목알 정보
* @var int is_dynamic			동적 할당된 객체인지 표현(1: 동적 할당, 0: 정적 할당)
* @var struct _STONENODE* next	다음 오목알 노드를 가리키는 포인터 
*
* @author	lja3723
* @date		2020-11-24	21:40
* @version	0.0.1
*/
typedef struct _STONENODE{
	int is_dynamic;				/* 동적 할당된 객체인지 표현(1: 동적 할당, 0: 정적 할당) */
	Stone stone;				/* 오목알 정보 */
	struct _STONENODE* next;	/* 다음 오목알 노드를 가리키는 포인터 */
} StoneNode;



/**
* @struct	StoneList
* @brief	오목알 리스트
* @details	오목알을 저장하는 자료구조를 구현한 객체
* 
* @var int size				: 리스트의 크기
* @var StoneNode* header	: StoneNode 연결 리스트를 가리키는 헤더
*
* @author	lja3723
* @date		2020-11-28	15:40
* @version	0.0.1
*/
typedef struct {
	int is_dynamic;		/* 동적 할당된 객체인지 표현(1: 동적 할당, 0: 정적 할당) */
	int size;			/* 리스트의 크기 */
	StoneNode* header;	/* 동적할당으로 구현된 StoneNode 포인터 배열: 행 표현 */
} StoneList;



/**
* @enum		OmokPanelType
* @brief	오목판 타입 열거형
* @details	오목판 타입(regular, jumbo)을 표현
* 
* @var regular	: 레귤러(15*15) 오목판
* @var jumbo	: 점보(19*19) 오목판
* @var ERR_OPT	: 에러 발생
* 
* @author	lja3723
* @date		2020-11-24	20:20
* @version	0.0.1
*/
typedef enum {
	regular	= 15,	/* 레귤러(15*15) 오목판 */
	jumbo	= 19,	/* 점보(19*19) 오목판 */
	ERR_OPT	= -1	/* 에러 발생 */
} OmokPanelType;



/**
* @struct	OmokPanel
* @brief	오목판 객체
* @details	오목판 타입과 오목알 리스트 동적 배열로 오목알 저장 storage 구현
* 
* @var OmokPanelType type	: 오목판 타입(regular, jumbo)
* @var StoneList* storage	: 오목알 리스트 동적 배열
*
* @author	lja3723
* @date		2020-11-24	20:10
* @version	0.0.1
*/
typedef struct {
	OmokPanelType type;		/* 오목판 타입(regular, jumbo) */
	StoneList* storage;	    /* 오목알 저장, StoneList 동적 배열임 */
} OmokPanel;



/**
* @struct	OmokStatus
* @brief	게임 진행 현황 객체
* @details	착수 횟수와 착수 순서를 표현한다. 착수 순서는 StoneNode 포인터의 동적 배열로, 각 원소는
*		오목판의 Node를 가리키며 동적 배열의 인덱스는 해당 Node가 오목판에 몇번째로 생성되었는지 나타낸다.
*		buff크기는 __OMOKOBJ_OMOKSTATUS_BUFF__로 초기화된다.
*		착수 순서 배열은 처음에 크기가 buff이고, 착수 횟수가 size를 초과할 때마다 size는 buff만큼 증가한다.
*		배수만큼 증가한다.
* 
* @var int turns				: 착수 횟수
* @var StoneNode** stone_order	: 착수 순서를 저장하는 동적 배열
* @var int ordersize			: stone_order의 크기
* @var int buff					: 버퍼
* 
* @author	lja3723
* @date		2020-11-28 20:25
* @version	0.0.2
*/
typedef struct {
	int	turns;					/* 착수 횟수 */
	StoneNode** stone_order;	/* 착수 순서를 저장하는 동적 배열 */
	int ordersize;				/* stone_order 크기 */
	int buff;					/* 착수 순서 버퍼(define으로 정의됨) */
} OmokStatus;



/**
* @struct	Omok
* @brief	통합 오목 객체
* @details	커서, 오목판, 게임 진행 현황 객체 등을 종합함
* 
* @var OmokCursor cursor	: 오목판 커서
* @var OmokPanel panel		: 오목판
* @var OmokStatus status	: 게임 진행 블록
* 
* @author	lja3723
* @date		2020-11-24	20:40
* @version	0.0.1
*/
typedef struct {
	OmokCursor cursor;	/* 오목판 커서 */
	OmokPanel panel;	/* 오목판 */
	OmokStatus status;	/* 게임 진행 현황 */
} Omok;



/*************************** /본문 ******************************/
#endif