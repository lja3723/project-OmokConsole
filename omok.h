#ifndef __OMOK_H__
#define __OMOK_H__

#include <stdio.h>
#include "omok_algorithm.h"
#include "omok_err.h"
#include "omokobj.h"
#include "omokobj_manage.h"
#include "omokobj_conio.h"

/**
* @file omok.h
*
*	[���� ����]
* 
*	1. ���� ����
*	2. ���� ���� ��ü �ʱ�ȭ
*	3. ���� �׷��� ���
*	4. ���� �������̽� ����
*	5. ���� �Է¿� ���� ���� ����
*	6. ���� ��Ģ �� ���� �Ǻ�
* 
*/

/*************************** ���� ******************************/



/*************************
*	 1. ���� ����     
**************************/

/**
*
* @brief	���� ������ ������
*
* @param	void
* @return	void
*
* @author	lja3723
* @date		2020-11-24 16:00
* @version	0.0.1
*
*/
void omok_start();





/********************************
*	 2. ���� ���� ��ü �ʱ�ȭ
*********************************/

/**
*
* @brief	������ ���� �� ���� �ʱⰪ�� �����ϴ� ���� �������̽� �Լ�
*
* @param	void
* @return	void
*
*/
void UI_initial_set();

/**
* 
* @brief ���� ������ ��ü�� �ʱ�ȭ�ϴ� �Լ�
* 
* @param	void
* @return	void
* 
*/
void obj_initialize();







/*************************** /���� *******************************/
#endif