#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/**
* @file omokobj.h
*/

/*
*	[파일 개요]
* 오목 프로그램에서 사용되는 모든 객체(구조체)를 정의
* 
*	[객체 종류]
* -좌표정보 객체(행과 열 정보)
* OmokCoord
* 
* -오목알 타입 열거형(오목알 종류)
* StoneType
* 
* -커서 객체(오목알 정보, 좌표정보)
* OmokCursor
* 
* -오목알 객체(오목알 정보, 좌표정보)
* Stone
* 
* -오목알 저장 객체(연결 리스트, 배열, 비트 연산 등 다양한 자료구조 이용)
* StoneStorage
* 
* -오목판 타입 열거형(오목판 종류)
* OmokPanelType
* 
* -오목판 객체(오목판 크기, 오목알 저장 자료구조)
* OmokPanel
* 
* -게임 진행 현황 객체(착수 차례(오목알 정보 객체), 착수 회수, 착수 좌표정보)
* OmokStatus
* 
* -통합 객체(커서, 오목판, 게임 진행 현황 객체)	
* Omok
*/



/**
* @brief	좌표정보 객체
* @details	오목판 내 좌표: 행과 열 정보를 표현
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct _OMOKCOORD {
	char row;	/* 오목판 행 정보 */
	short col;	/* 오목판 열 정보 */
} OmokCoord;



/**
* @brief	오목알 타입 열거형
* @details	오목알 타입(Black, White)을 표현
*
* @author	lja3723
* @date		2020-11-24	18:05
* @version	0.0.1
*/
typedef enum _STONETYPE {
	Black = 0,	/* 흑색 오목알 */
	White = 1	/* 백색 오목알 */
} StoneType;



/**
* @brief	커서 객체
* @details	커서의 위치(Coord)와 오목알 정보(StoneInfo)를 표현
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _OMOKCURSOR {
	OmokCoord loc;		/* 커서의 위치 */
	StoneType type;	/* 커서가 표현하는 오목알 타입 */
} OmokCursor;



/**
* @brief	오목알 객체
* @details	오목알의 위치(Coord)와 오목알 정보(StoneInfo)를 표현
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _STONE {
	OmokCoord loc;		/* 오목알의 위치 */
	StoneType type;	/* 오목알 타입 */
} Stone;



/**
* @brief	오목알 저장 객체
* @details	오목알을 저장하는 자료구조를 정의하는 객체
*			세부 구현은 연결 리스트, 배열, 비트 연산 등 다양한 방법을 이용
*
* @author	lja3723
* @date		2020-11-24	20:25
* @version	0.0.1
*/
typedef struct _STONESTORAGE{
	int tmp;	/* (임시) */
} StoneStorage;



/**
* @brief	오목판 타입 열거형
* @details	오목판 타입(regular, jumbo)을 표현
*
* @author	lja3723
* @date		2020-11-24	20:20
* @version	0.0.1
*/
typedef enum _OMOKPANELTYPE {
	regular = 0,	/* 레귤러 오목판 */
	jumbo = 1		/* 점보 오목판 */
} OmokPanelType;



/**
* @brief	오목판 객체
* @details	오목판 타입, 오목알 저장 객체를 표현
*
* @author	lja3723
* @date		2020-11-24	20:10
* @version	0.0.1
*/
typedef struct _OMOKPANEL {
	OmokPanelType type;		/* 오목판 타입 */
	StoneStorage storage;	/* 오목알 저장 객체 */
} OmokPanel;



/**
* @brief	게임 진행 현황 객체
* @details	착수 차례(오목알 정보 객체), 착수 횟수, 착수 좌표정보를 표현
*
* @author	lja3723
* @date		2020-11-24	20:30
* @version	0.0.1
*/
typedef struct _OMOKSTATUS {
	StoneType who_is_turn;	/* 착수 차례(Black, White) */
	int	turns;				/* 착수 횟수 */
	OmokCoord prev_put_locate;	/* 바로 전 착수한 좌표 정보 */
} OmokStatus;



/**
* @brief	통합 오목 객체
* @details	커서, 오목판, 게임 진행 현황 객체 등을 종합함
*
* @author	lja3723
* @date		2020-11-24	20:40
* @version	0.0.1
*/
typedef struct _OMOK {
	OmokCursor cursor;
	OmokPanel panel;
	OmokStatus status;
} Omok;

#endif