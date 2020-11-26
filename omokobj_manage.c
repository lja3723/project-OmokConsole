#include "omokobj_manage.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/**
* @file omokobj_manage.c
*/

OmokCoord _OmokCoord(char row, short col)
{
	OmokCoord obj;
	if (isalpha(row))
		obj.row = toupper(row);
	else
		obj.row = 0;
	if (1 <= col && col <= 19)
		obj.col = col;
	else
		obj.col = 0;
	return obj;
}

void set_OmokCoord(OmokCoord* obj, char row, short col)
{
	if (isalpha(row))
		obj->row = toupper(row);
	else
		obj->row = 0;
	if (1 <= col && col <= 19)
		obj->col = col;
	else
		obj->col = 0;

}

OmokCoord Str_to_OmokCoord(const char* str)
{
	OmokCoord obj;
	if (isalpha(str[0]))
		obj.row = toupper(str[0]);
	else
		obj.row = 0;
	
	if (isdigit(str[1]))
	{
		if (strlen(str) == 2)
			obj.col = atoi(str + 1);
		else if (strlen(str) == 3 && isdigit(str[2]))
			obj.col = atoi(str + 1);
		else
			obj.col = 0;
	}
	else
		obj.col = 0;
	return obj;
	
}
