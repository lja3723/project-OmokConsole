#ifndef __OMOKOBJ_H__
#define __OMOKOBJ_H__


//ÁÂÇ¥Á¤º¸ °´Ã¼
typedef struct _LOCATE
{
	//	[x ÁÂÇ¥]
	//ÁÂÇ¥ÀÇ x°ªÀ» Ç¥Çö
	int x;

	/*	[y ÁÂÇ¥]
	ÁÂÇ¥ÀÇ y°ªÀ» Ç¥Çö */
	int y;	

} Location;

typedef struct _OMOK_PANEL
{
	int size;
} OmokPanel;

#endif