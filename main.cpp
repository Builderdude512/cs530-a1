#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


bool printline(std::ifstream &file) {
	int i = 0;
	int offset = 0;
	
	char buffer[16];

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
	if(bytesRead<16) {
		return false;
	}

	printf("\n");
	return true;
}

int main() {
	
	std::ifstream file("data/files/main.cpp", std::ios::binary);
	for(int i = 0; i <=10; i++){
		bool cancallagain = printline(file);
		if((!cancallagain)){
			break;
		}
	}

	printf("\n");
	return 0;
}