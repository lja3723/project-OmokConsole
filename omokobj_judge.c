#include <stdio.h>
#include "omokobj_judge.h"

/**
* @file omokobj_judge.c
*/

int valid_OmokCoord(OmokCoord* obj)
{
    return 0;
}

int is_StoneNode_dynamic(StoneNode* obj)
{
    if (obj != NULL && obj->is_dynamic)
        return 1;
    else
        return 0;
}
