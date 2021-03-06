/**
* slae_solver.h
* Purpose: solve the system of the linear algebraic equations
* that looks like Ax = b.
*
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#pragma once
#include <string>
#include <fstream>
#include "pseudo_dynamic_memory_controller.h"
#include <iostream>
#include <fstream>

#define SCALE double


using namespace std;

class SLAESolver {
public:
	SLAESolver();
	~SLAESolver();

	virtual void solve(char* bName) = 0;
	virtual void printSLAE() = 0;
	void saveResult(char* resultName);

	void setAlertLevel(int newAlertLevel);

	inline DATA_TYPE* getAl() { return Al; };
	inline DATA_TYPE* getAd() { return Ad; };
	inline DATA_TYPE* getB() { return b; };
	inline DATA_TYPE* getX() { return x; };
	inline int getDimension() { return dimension; };

protected:
	int dimension;
	PseudoDynamicMemoryController<DATA_TYPE>* memoryController;
	ExceptionGenerator exceptionGenerator;
	DATA_TYPE* Au;
	DATA_TYPE* Ad;
	DATA_TYPE* Al;
	DATA_TYPE* x;
	DATA_TYPE* b;
};