/**
* slae_solver.cpp
* Purpose: solve the system of the linear algebraic equations
* that looks like Ax = b.
*
* @author Edward Drozdov
* @version 1.0 18/10/17
*/

#include "slae_solver.h"


SLAESolver::SLAESolver() {
	dimension = 0;
	Au = NULL;
	Ad = NULL;
	Al = NULL;
	x = NULL;
	b = NULL;
	memoryController = new PseudoDynamicMemoryController<DATA_TYPE>;
};


SLAESolver::~SLAESolver() {
	dimension = 0;
	if (memoryController != NULL) {
		memoryController->~PseudoDynamicMemoryController();
		memoryController = NULL;
	}
	Au = NULL;
	Ad = NULL;
	Al = NULL;
	x = NULL;
	b = NULL;
};


void SLAESolver::saveResult(char* resultName) {
	exceptionGenerator.checkIsError();
	exceptionGenerator.generateError(Al == NULL,
		"saveResult: low matrix pointer is NULL");

	memoryController->saveInFile(resultName, x, dimension, dimension);
};


void SLAESolver::setAlertLevel(int newAlertLevel) {
	exceptionGenerator.setExceptionAlertLevel(newAlertLevel);
	memoryController->setAlertLevel(newAlertLevel);
};