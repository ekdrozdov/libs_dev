/**
* runtipme.cpp
* Purpose: emulate extern program that use developing classes.
*
* @author Edward Drozdov
* @version 1.0d 09/11/17
*/

#pragma once
#include <stdio.h>
#include <iostream>

#include "arguments_parser.h"
#include "slae_solver.h"
#include "pseudo_dynamic_memory_controller.h"
#include "exception_generator.h"
#include "file_handler.h"


void shutdown() {
	// Activate when debugging.
	std::cout << "Press any key to continue...";
	getchar();
}


int main(int argc, char* argv[]) {
	shutdown();
	return 0;
}