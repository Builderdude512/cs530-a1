#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


int main() {
	int i = 0;
	int offset = 0;
	
	std::ifstream file("data/files/main.cpp", std::ios::binary);
	char buffer[16];

	file.read(buffer, sizeof(buffer));
	std:: streamsize bytesRead = file.gcount();
	printf("%08x: ", offset);
	for (i=0; i<16; i++) {
		printf("%02x ",buffer[i]);
	}
	for (i=0; i<16; i++) {
		printf("%c", buffer[i]);
	}

	// std::cout << "Bytes read: " << bytesRead << std::endl;

	printf("\n");
	return 0;
}

