#include "omok.h"


/**
* @file main.c
*/
#include<stdio.h>
#include<string.h>
typedef struct student
{
	int	number;
	char name[30];
	char phone[14];
} Student;

/**
* @brief	struct student ��ü ���
* 
* @param	struct student* p : ����ϰ��� �ϴ� ��ü�� �ּڰ�
* @return	void 
* 
* @author	chongsik
* @date		2020-11-24 17:04
* @version	0.0.1
*/
void student_print(Student* p)
{
	printf("%d %s %s", p->number, (*p).name, (*p).phone);
}

/**
* @brief	Student ��ü ����
* 
* @param	const int num		: ������ �й�	
* @param	const char *phone	: ������ ��ȭ��ȣ
* @param	const char *name	: ������ �̸�
* @param	Student *p			: �����ϰ��� �ϴ� ��ü�� �ּڰ�
* 
* @return	void
* 
* @author	chongsik
* @date		2020-11-24 17:25
* @version	0.0.1
*/
void set_student(const int num, const char *name, const char *phone, Student *p)
{
	p->number = num;
	strcpy(p->phone, phone);
	strcpy((*p).name, name);
}

int main(void)
{
	omok_start();
	Student s1;
	set_student(201037, "��ȫ��", "010-7143-9632", &s1);
	student_print(&s1);


	return 0;
}

