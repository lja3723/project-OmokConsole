#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/**
* @file omokobj.h
*/

/*
*	[���� ����]
* ���� ���α׷����� ���Ǵ� ��� ��ü(����ü)�� ����
* 
*	[��ü ����]
* -��ǥ���� ��ü(��� �� ����)
* OmokCoord
* 
* -����� Ÿ�� ������(����� ����)
* StoneType
* 
* -Ŀ�� ��ü(����� ����, ��ǥ����)
* OmokCursor
* 
* -����� ��ü(����� ����, ��ǥ����)
* Stone
* 
* -����� ���� ��ü(���� ����Ʈ, �迭, ��Ʈ ���� �� �پ��� �ڷᱸ�� �̿�)
* StoneStorage
* 
* -������ Ÿ�� ������(������ ����)
* OmokPanelType
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
* @details	������ �� ��ǥ: ��� �� ������ ǥ��
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct _OMOKCOORD {
	char row;	/* ������ �� ���� */
	short col;	/* ������ �� ���� */
} OmokCoord;



/**
* @brief	����� Ÿ�� ������
* @details	����� Ÿ��(Black, White)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:05
* @version	0.0.1
*/
typedef enum _STONETYPE {
	Black = 0,	/* ��� ����� */
	White = 1	/* ��� ����� */
} StoneType;



/**
* @brief	Ŀ�� ��ü
* @details	Ŀ���� ��ġ(Coord)�� ����� ����(StoneInfo)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _OMOKCURSOR {
	OmokCoord loc;		/* Ŀ���� ��ġ */
	StoneType type;	/* Ŀ���� ǥ���ϴ� ����� Ÿ�� */
} OmokCursor;



/**
* @brief	����� ��ü
* @details	������� ��ġ(Coord)�� ����� ����(StoneInfo)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _STONE {
	OmokCoord loc;		/* ������� ��ġ */
	StoneType type;	/* ����� Ÿ�� */
} Stone;



/**
* @brief	����� ���� ��ü
* @details	������� �����ϴ� �ڷᱸ���� �����ϴ� ��ü
*			���� ������ ���� ����Ʈ, �迭, ��Ʈ ���� �� �پ��� ����� �̿�
*
* @author	lja3723
* @date		2020-11-24	20:25
* @version	0.0.1
*/
typedef struct _STONESTORAGE{
	int tmp;	/* (�ӽ�) */
} StoneStorage;



/**
* @brief	������ Ÿ�� ������
* @details	������ Ÿ��(regular, jumbo)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	20:20
* @version	0.0.1
*/
typedef enum _OMOKPANELTYPE {
	regular = 0,	/* ���ַ� ������ */
	jumbo = 1		/* ���� ������ */
} OmokPanelType;



/**
* @brief	������ ��ü
* @details	������ Ÿ��, ����� ���� ��ü�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	20:10
* @version	0.0.1
*/
typedef struct _OMOKPANEL {
	OmokPanelType type;		/* ������ Ÿ�� */
	StoneStorage storage;	/* ����� ���� ��ü */
} OmokPanel;



/**
* @brief	���� ���� ��Ȳ ��ü
* @details	���� ����(����� ���� ��ü), ���� Ƚ��, ���� ��ǥ������ ǥ��
*
* @author	lja3723
* @date		2020-11-24	20:30
* @version	0.0.1
*/
typedef struct _OMOKSTATUS {
	StoneType who_is_turn;	/* ���� ����(Black, White) */
	int	turns;				/* ���� Ƚ�� */
	OmokCoord prev_put_locate;	/* �ٷ� �� ������ ��ǥ ���� */
} OmokStatus;



/**
* @brief	���� ���� ��ü
* @details	Ŀ��, ������, ���� ���� ��Ȳ ��ü ���� ������
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