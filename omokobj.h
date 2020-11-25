#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__

/**
* @file omokobj.h
*
*	[���� ����]
* ���� ���α׷����� ���Ǵ� ��� ��ü(����ü)�� ������
* 
*	[��ü ����]
*	����					�̸�			  ��� ����
* ��ǥ���� ��ü		: OmokCoord		��� �� ����
* ����� Ÿ�� ������	: StoneType		����� ����
* Ŀ�� ��ü			: OmokCursor	����� ����, ��ǥ����
* ����� ��ü		: Stone			����� ����, ��ǥ����
* ����� ���		: StoneNode		����� ���� ��ü�� ���� ��ü
* ����� ���� ��ü	: StoneStorage	���� ����Ʈ ����� ���� 
* ������ Ÿ�� ������	: OmokPanelType	������ ����
* ������ ��ü		: OmokPanel		������ ũ��, ����� ���� ��ü
* ���� ���� ��Ȳ ��ü	: OmokStatus	���� ����, ���� ȸ��, ���� ��ǥ����
* ���� ��ü			: Omok			Ŀ��, ������, ���� ���� ��Ȳ ��ü
*/



/*************************** ���� ******************************/



/**
* @brief	��ǥ���� ��ü
* @details	������ �� ��ǥ: ��� �� ������ ǥ��
* 
* @author	lja3723
* @date		2020-11-24	18:00
* @version	0.0.1 
*/
typedef struct _OMOKCOORD {
	char row;	/* �� ���� */
	short col;	/* �� ���� */
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
	Black = 0,		/* ��� ����� */
	White = 1,		/* ��� ����� */
	ERR_ST = -1		/* ���� �߻� */
} StoneType;



/**
* @brief	Ŀ�� ��ü
* @details	Ŀ���� ��ġ(OmokCoord)�� ����� ����(StoneType)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _OMOKCURSOR {
	OmokCoord locate;	/* Ŀ���� ��ġ */
	StoneType type;		/* Ŀ���� ǥ���ϴ� ����� Ÿ��(Black, White) */
} OmokCursor;



/**
* @brief	����� ��ü
* @details	������� ��ġ(OmokCoord)�� ����� ����(StoneType)�� ǥ��
*
* @author	lja3723
* @date		2020-11-24	18:10
* @version	0.0.1
*/
typedef struct _STONE {
	OmokCoord locate;	/* ������� ��ġ */
	StoneType type;		/* ����� Ÿ��(Black, White) */
} Stone;



/**
* @brief	����� ���
* @details	����� ��ü�� �����ϴ� ��� ����
*
* @author	lja3723
* @date		2020-11-24	21:40
* @version	0.0.1
*/
typedef struct _STONENODE {
	Stone stone;				/* ����� ���� */
	struct _STONENODE* next;	/* ���� ����� ��带 ����Ű�� ������ */
} StoneNode;



/**
* @brief	����� ���� ��ü
* @details	������� �����ϴ� �ڷᱸ���� �����ϴ� ��ü
*			���� ����Ʈ�� ����
*
* @author	lja3723
* @date		2020-11-24	21:40
* @version	0.0.1
*/
typedef struct _STONESTORAGE {
	StoneNode** header;	/* �����Ҵ����� ������ StoneNode ������ �迭: �� ǥ�� */
	int size;			/* ������ �迭�� ũ�� */
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
	regular	= 15,	/* ���ַ�(15*15) ������ */
	jumbo	= 19,	/* ����(19*19) ������ */
	ERR_OPT	= -1	/* ���� �߻� */
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
	OmokPanelType type;		/* ������ Ÿ��(regular, jumbo) */
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
	StoneType who_is_turn;		/* ���� ����(Black, White) */
	int	turns;					/* ���� Ƚ�� */
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
	OmokCursor cursor;	/* ������ Ŀ�� */
	OmokPanel panel;	/* ������ */
	OmokStatus status;	/* ���� ���� ��Ȳ */
} Omok;



/*************************** /���� ******************************/
#endif