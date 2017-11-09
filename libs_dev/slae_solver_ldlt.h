/**
* slae_solver_ldlt.h
* Purpose: solve the system of the linear algebraic equations
* that looks like Ax = b using the LDLt decomposition method.
*
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#pragma once
#include "slae_solver.h"


class SLAESolverLDLT : public SLAESolver {
public:
	SLAESolverLDLT();
	~SLAESolverLDLT();

	void loadMatrix(char* infoName, char* diName, char* aalName);
	void computeLDLTDecomposition();
	void solve(char* bName);
	void printSolveVector();
	void printSLAE();

	inline int getLowBandWidth() { return lowBandWidth; };

private:
	bool isDecompose;

	int copmuteRequiredMemorySize();
	void reverseRun();
	void directRun();
	int lowBandWidth;
};