#include <iostream>
#include "solver_square_equation.h"
#include "test_solver_square_equation.h"

int main()
{
	//модульное тестирование
	TestSolverSquareEquation testSolverEquation;
	testSolverEquation.runTest();
	std::cout<<"------------------"<<std::endl;

	//приемочное тестирование
	SolverSquareEquation solver_square_equation;
	solver_square_equation.rootSquareEquation(1, -5, 6);
	std::cout<<std::endl;
	solver_square_equation.rootSquareEquation(1, -10, 25);
	std::cout<<std::endl;
	solver_square_equation.rootSquareEquation(1, -5, 7);
	std::cout<<std::endl;
	solver_square_equation.rootSquareEquation(0, -5, 7);
	system("pause");
	return 0;
}

