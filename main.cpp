#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int offset = 0;

bool printlinehex(std::ifstream &file) {
	int i = 0;
	
	
	char buffer[16];
	for (int cntr=1; cntr<=16; cntr++) {
		buffer[cntr] = 0;
	}

	file.read(buffer, sizeof(buffer));
	std:: streamsize bytesRead = file.gcount();
	printf("%08x: ", offset);
	for (i=0; i<16; i++) {
		printf("%02x ",buffer[i]);
	}
	for (i=0; i<16; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{
			printf(".");
		}
	}
	offset+=bytesRead;
	if(bytesRead<16) {
		return false;
	}

	printf("\n");
	return true;
}

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

bool printlinebin(std::ifstream &file) {
	int i = 0;
	
	char buffer[6];
	for (int cntr=1; cntr<=6; cntr++) {
		buffer[cntr] = 0;
	}

	file.read(buffer, sizeof(buffer));
	std:: streamsize bytesRead = file.gcount();
	printf("%08x: ", offset);
	for (i=0; i<6; i++) {
		printbinary(buffer[i]);
		printf(" ");
	}
	for (i=0; i<6; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{
			printf(".");
		}
	}
	offset+=bytesRead;
	if(bytesRead<6) {
		return false;
	}

	printf("\n");
	return true;
}

void printfilehex(std::ifstream &file) {
	for(;;){
		bool cancallagain = printlinehex(file);
		if((!cancallagain)){
			break;
		}
	}
}

void printfilebin(std::ifstream &file) {
	for(;;){
		bool cancallagain = printlinebin(file);
		if((!cancallagain)){
			break;
		}
	}
}

int main() {
	
	std::ifstream file("data/files/main.cpp", std::ios::binary);

	int inp; 
	printf("Type 1 if you want a hex translation, or 2 for binary \n");
	std::cin >> inp; 

	if(inp==1) {
		printfilehex(file);
	} 
	else if(inp==2) {
		printfilebin(file);
	}
	else {
		printf("input not valid \n");
	}

	printf("\n");
	return 0;
}
