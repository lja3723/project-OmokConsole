#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/**
* @file omokobj.h
*/

/*
*	[파일 개요]
* 
* 오목 프로그램에서 사용되는 모든 객체(구조체)를 정의
* 
* 
*	[객체 종류]
* 
* -좌표정보 객체(행과 열 정보)
* Coord
* 
* -오목알 정보 열거형(오목알 종류)
* StoneInfo
* 
* -커서 객체(오목알 정보, 좌표정보)
* Cursor
* 
* -오목알 객체(오목알 정보, 좌표정보)
* Stone
* 
* -오목알 저장 자료구조 객체(연결 리스트, 배열 등)
* StoneStorage
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
* @details	오목판의 행과 열 정보를 표현
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct _COORD {
	char row;	/* 오목판 행 정보 */
	short col;	/* 오목판 열 정보 */
} Coord;



/**
* @brief	오목알 정보 열거형
* @details	오목알 정보(Black, White)를 표현
*
* @author	lja3723
* @date		2020-11-24	18:05
* @version	0.0.1
*/
typedef enum _STONEINFO {
	Black = 0,	/* 흑색 오목알 */
	White = 1	/* 백색 오목알 */
} StoneInfo;



/**
* @brief	커서 객체
* @details	커서의 위치(Coord)와 오목알 정보(StoneInfo)를 표현
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _CURSOR {
	Coord loc;		/* 커서의 위치 */
	StoneInfo type;	/* 커서가 표현하는 오목알 타입 */
} Cursor;



/**
* @brief	오목알 객체
* @details	오목알의 위치(Coord)와 오목알 정보(StoneInfo)를 표현
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _STONE {
	Coord loc;		/* 오목알의 위치 */
	StoneInfo type;	/* 오목알 타입 */
} Stone;






typedef struct _OMOK_PANEL
{
	int size;
} OmokPanel;

#endif