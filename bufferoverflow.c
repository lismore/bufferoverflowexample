/*
*  Buffer Overflow, Segmentation Fault Example
*
*  Description
*  Simple C example to demonstrate a buffer overflow and cause a segmentation fault 
*
*  To compile this program on Linux use the following command (Kali 2.0 used)
*  gcc -ggdb -fno-stack-protector -o bufferoverflow bufferoverflow.c
*
*  *** Note the flag -fno-stack-protector , used to allow this simple example to be demonstrated
*
*  To execute 
* ./bufferoverflow 
*
* Author	: Patrick Lismore
* Date		: 19th Dec 2015  
* Twitter	: @patricklismore
*/

//includes
#include <stdio.h>
#include <string.h>

//main routine 
main(){

//declare a char variable to hold 20

	char buffer[20];

//copy 40 char into it to cause a segmentation fault

	strcpy(buffer, "1234567899876543210012345678998765432100");

//print string buffer

printf("%s\n", buffer);

}