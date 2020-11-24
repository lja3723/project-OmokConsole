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
* @brief	struct student 객체 출력
* 
* @param	struct student* p : 출력하고자 하는 객체의 주솟값
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
* @brief	Student 객체 설정
* 
* @param	const int num		: 설정할 학번	
* @param	const char *phone	: 설정할 전화번호
* @param	const char *name	: 설정할 이름
* @param	Student *p			: 설정하고자 하는 객체의 주솟값
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
	set_student(201037, "조홍식", "010-7143-9632", &s1);
	student_print(&s1);


	return 0;
}

