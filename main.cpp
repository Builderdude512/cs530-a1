/*
Connor Shands-Sparks
cssc4022
CS 530-05, Spring2024
Program Assignment #1
main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int offset = 0;

// print one line of hex similar to the following
// 00000000: 2369 6e63 6c75 6465 203c 696f 7374 7265  #include <iostre
bool printlinehex(std::ifstream &file) {
	int i = 0;
	
	//clear buffer to prevent the previous data from carrying over
	char buffer[16];
	for (int cntr=1; cntr<=16; cntr++) {
		buffer[cntr] = 0;
	}

	file.read(buffer, sizeof(buffer));
	std:: streamsize bytesRead = file.gcount();

	// print offset at beggining of line
	printf("%08x: ", offset);
	
	// print as hex
	for (i=0; i<bytesRead; i++) {
		printf("%02x",buffer[i]);
		if(i%2 != 0){
			printf(" ");
		}
	}

	// for short lines, add spaces
	for (; i<16; i++) {
		printf("  ");
		if(i%2 != 0){
			printf(" ");
		}
	}
	printf(" ");

	// print as ascii
	for (i=0; i<bytesRead; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{

			//non printable
			printf(".");
		}
	}

	// add spaces
	for (; i < 16; i++) {
		printf(" ");
	}

	// keep track of total bytes read
	offset+=bytesRead;

	// no more data to read
	if(bytesRead<16) {
		return false;
	}

	printf("\n");
	return true;
}


// manual translation from hex to binary
void printbinary(unsigned char bin) 
{
	unsigned char mask = 0x80;
	for (int i = 0; i<8; i++) {
		if (bin & mask){
			printf("1");
		}
		else {
			printf("0");
		}
		mask >>=1;
	}
}

// print one line of hex similar to the following: 
// 00000000: 00100011 01101001 01101110 01100011 01101100 01110101 #inclu
bool printlinebin(std::ifstream &file) {
	int i = 0;
	
	//clear buffer to prevent the previous data from carrying over
	char buffer[6];
	for (int cntr=1; cntr<=6; cntr++) {
		buffer[cntr] = 0;
	}

	file.read(buffer, sizeof(buffer));
	std:: streamsize bytesRead = file.gcount();
	if(bytesRead==0) {
		return false;
	}

	// print offset at beggining of line
	printf("%08x: ", offset);

	// print as boolean using the printbinary() function
	for (i=0; i<bytesRead; i++) {
		printbinary(buffer[i]);
		printf(" ");
	}

	// spacing for short lines
	for (; i<6; i++) {
		printf("         ");
	}

	// printing ascii
	for (i=0; i<bytesRead; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{
			printf(".");
		}
	}

	// add spaces
	for (; i<6; i++) {
		printf(" ");
	}

	//keep track of bytes read
	offset+=bytesRead;

	// no more data to read
	if(bytesRead<6) {
		return false;
	}

	printf("\n");
	return true;
}

// printfilehex will print the file in hex format 16 bytes at a time.
void printfilehex(std::ifstream &file) {
	for(;;){
		bool cancallagain = printlinehex(file);
		if((!cancallagain)){
			break;
		}
	}
}

// printfilebin will print the file in binary format 6 bytes at a time.
void printfilebin(std::ifstream &file) {
	for(;;){
		bool cancallagain = printlinebin(file);
		if((!cancallagain)){
			break;
		}
	}
}

int main(int argc, char const * argv[]) {

	// did user enter file name
	if (argc < 2) {
		std::cout << "Enter file name" << std::endl;
		return 1;
	}

	// hex mode
	if(argc==2) {
		std::ifstream file(argv[1], std::ios::binary);
		printfilehex(file);
	} 
	// binary mode
	else if(argc==3) {
		std::ifstream file(argv[2], std::ios::binary);
		printfilebin(file);
	}
	else {
		printf("input not valid \n");
	}

	printf("\n");
	return 0;
}
