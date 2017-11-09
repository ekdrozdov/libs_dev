/**
* slae_solver_gauss.h
* Purpose: solve the system of the linear algebraic equations
* that looks like Ax = b using the Gauss method.
*
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#pragma once
#include "slae_solver.h"

class SLAESolverGauss : public SLAESolver {
public:
	void loadMatrix(char* infoName, char* matrixName);
	void solve(char* bName);
	void printSLAE();

private:
	void reverseRun();
	void putSystemIntoUpperTriangularForm();
	int copmuteRequiredMemorySize();
};