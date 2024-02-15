/*
Connor Shands-Sparks
cssc4022
CS 530-05, Spring2024
Program Assignment #1
main.cpp
*/

#ifndef XED_HPP
#define XED_HPP
#include <fstream>

// printfilehex will print the file in hex format 16 bytes at a time.
void printfilehex(std::ifstream &file);

// printfilebin will print the file in binary format 6 bytes at a time.
void printfilebin(std::ifstream &file);

#endif 
