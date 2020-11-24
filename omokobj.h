#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/**
* @file omokobj.h
*/

/*
*	[���� ����]
* 
* ���� ���α׷����� ���Ǵ� ��� ��ü(����ü)�� ����
* 
* 
*	[��ü ����]
* 
* -��ǥ���� ��ü(��� �� ����)
* Coord
* 
* -����� ���� ������(����� ����)
* StoneInfo
* 
* -Ŀ�� ��ü(����� ����, ��ǥ����)
* Cursor
* 
* -����� ��ü(����� ����, ��ǥ����)
* Stone
* 
* -����� ���� �ڷᱸ�� ��ü(���� ����Ʈ, �迭 ��)
* StoneStorage
* 
* -������ ��ü(������ ũ��, ����� ���� �ڷᱸ��)
* OmokPanel
* 
* -���� ���� ��Ȳ ��ü(���� ����(����� ���� ��ü), ���� ȸ��, ���� ��ǥ����)
* OmokStatus
* 
* -���� ��ü(Ŀ��, ������, ���� ���� ��Ȳ ��ü)	
* Omok
*/



/**
* @brief	��ǥ���� ��ü
* @details	�������� ��� �� ������ ǥ��
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct _COORD {
	char row;	/* ������ �� ���� */
	short col;	/* ������ �� ���� */
} Coord;



/**
* @brief	����� ���� ������
* @details	����� ����(Black, White)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:05
* @version	0.0.1
*/
typedef enum _STONEINFO {
	Black = 0,	/* ��� ����� */
	White = 1	/* ��� ����� */
} StoneInfo;



/**
* @brief	Ŀ�� ��ü
* @details	Ŀ���� ��ġ(Coord)�� ����� ����(StoneInfo)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _CURSOR {
	Coord loc;		/* Ŀ���� ��ġ */
	StoneInfo type;	/* Ŀ���� ǥ���ϴ� ����� Ÿ�� */
} Cursor;



/**
* @brief	����� ��ü
* @details	������� ��ġ(Coord)�� ����� ����(StoneInfo)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _STONE {
	Coord loc;		/* ������� ��ġ */
	StoneInfo type;	/* ����� Ÿ�� */
} Stone;






typedef struct _OMOK_PANEL
{
	int size;
} OmokPanel;

#endif