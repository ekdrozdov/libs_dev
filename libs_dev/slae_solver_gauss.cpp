/**
* slae_solver_gauss.h
* Purpose: solve the system of the linear algebraic equations
* that looks like Ax = b using the Gauss method.
*
* @author Edward Drozdov
* @version 1.0 09/11/17
*/

#include "slae_solver_gauss.h"


int SLAESolverGauss::copmuteRequiredMemorySize() {
	exceptionGenerator.checkIsError();
	exceptionGenerator.generateError(dimension < 0,
		"copmuteRequiredMemorySize: dimension less than 0");

	int memoryForMatrix = dimension * dimension;
	int memoryForVectorX = dimension;
	int memoryForVectorB = dimension;
	return memoryForMatrix + memoryForVectorX + memoryForVectorB;
};


void SLAESolverGauss::
loadMatrix(char* infoName, char* matrixName) {
	exceptionGenerator.checkIsError();
	exceptionGenerator.generateError(infoName == NULL,
		"solve: info file name is NULL");
	exceptionGenerator.generateError(matrixName == NULL,
		"solve: di file name is NULL");

	memoryController->loadInfo(infoName, &dimension);
	memoryController->initilizeMemory(copmuteRequiredMemorySize());
	Ad = memoryController->loadFile(matrixName, dimension, dimension);
};


void SLAESolverGauss::putSystemIntoUpperTriangularForm() {
	for (int i = 0; i < dimension; i++) {
		// Pick a leading element.
		DATA_TYPE maxElement = Ad[i * dimension + i];
		int maxElementStringNumber = i;
		for (int k = i + 1; k < dimension; k++) {
			if (Ad[k * dimension + i] > maxElement) {
				maxElement = Ad[k * dimension + k];
				maxElementStringNumber = k;
			}
		}
		// Swap strings if the leading element don't belong to current string.
		if (maxElementStringNumber != i) {
			DATA_TYPE swapBuffer = 0;
			for (int j = 0; j < dimension; j++) {
				swapBuffer = Ad[i * dimension + j];
				Ad[i * dimension + j] = Ad[maxElementStringNumber * dimension + j];
				Ad[maxElementStringNumber * dimension + j] = swapBuffer;
			}
			swapBuffer = b[i];
			b[i] = b[maxElementStringNumber];
			b[maxElementStringNumber] = swapBuffer;
		}
		// Nullify all other strings under current one.
		for (int j = i + 1; j < dimension; j++) {
			DATA_TYPE coefficient = Ad[j * dimension + i] / Ad[i * dimension + i];
			Ad[j * dimension + i] = 0.0;
			for (int k = i + 1; k < dimension; k++) {
				Ad[j * dimension + k] -= Ad[i * dimension + k] * coefficient;
			}
			b[j] -= b[i] * coefficient;
		}
	}
};


void SLAESolverGauss::solve(char* bName) {
	exceptionGenerator.checkIsError();
	exceptionGenerator.generateError(bName == NULL,
		"solve: b file name is NULL");

	b = memoryController->loadFile(bName, dimension, 1);
	x = memoryController->holdMemory(dimension, 0);
	memoryController->finalize();

	putSystemIntoUpperTriangularForm();

	reverseRun();
};


void SLAESolverGauss::printSLAE() {
	memoryController->printMemoryContent(Ad, dimension * dimension, dimension, "matrix");
	memoryController->printMemoryContent(b, dimension, dimension, "b");
	memoryController->printMemoryContent(x, dimension, dimension, "x");
};


void SLAESolverGauss::reverseRun() {
	exceptionGenerator.checkIsError();
	exceptionGenerator.generateError(Ad == NULL,
		"reverseRun: matrix diagonal pointer is NULL");
	exceptionGenerator.generateError(x == NULL,
		"reverseRun: variable vector pointer is NULL");

	int n = dimension;

	for (int i = dimension - 1; i >= 0; i--) {
		DATA_TYPE sum = 0;
		for (int j = i + 1; j < dimension; j++) {
			sum += Ad[i * dimension + j] * x[j];
		}
		x[i] = (b[i] - sum) / Ad[i * dimension + i];
	}
}