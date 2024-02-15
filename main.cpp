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
	for (i=0; i<bytesRead; i++) {
		printf("%02x",buffer[i]);
		if(i%2 != 0){
			printf(" ");
		}
	}
	for (; i<16; i++) {
		printf("  ");
		if(i%2 != 0){
			printf(" ");
		}
	}
	printf(" ");
	for (i=0; i<bytesRead; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{
			printf(".");
		}
	}
	for (; i < 16; i++) {
		printf(" ");
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
	if(bytesRead==0) {
		return false;
	}
	printf("%08x: ", offset);
	for (i=0; i<bytesRead; i++) {
		printbinary(buffer[i]);
		printf(" ");
	}
	for (; i<6; i++) {
		printf("         ");
	}
	for (i=0; i<bytesRead; i++) {
		if(isprint(buffer[i])){
			printf("%c", buffer[i]);
		}
		else{
			printf(".");
		}
	}
	for (; i<6; i++) {
		printf(" ");
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

int main(int argc, char const * argv[]) {

	// if (argc < 2) {
	// 	std::cout << "Enter file name" << std::endl;
	// 	return 1;
	// }

	if(/*argc==2*/ false) {
		// std::ifstream file(argv[1], std::ios::binary);
		std::ifstream file("data/files/main.cpp", std::ios::binary);
		printfilehex(file);
	} 
	else if(/*argc==3*/ true) {
		std::ifstream file("data/files/main.cpp", std::ios::binary);
		printfilebin(file);
	}
	else {
		printf("input not valid \n");
	}

	printf("\n");
	return 0;
}
