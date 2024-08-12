#ifndef TEST_SOLVER_SQUARE_EQUATION
#define TEST_SOLVER_SQUARE_EQUATION
#include <vector>
#include <iostream>

class TestCase
{
protected:
	template<typename T>
	void assertEquals(T expectValue, T actualValue){
		if (expectValue == actualValue)
			std::cout << "TEST OK\n";
		else
			std::cout << "TEST FAIL\n";//: "<<expectValue << " not equal " << actualValue << std::endl;
	}

	void assertTrue(bool actualValue){
		if (actualValue)
			std::cout << "TEST OK\n";
		else
			std::cout << "TEST FAIL\n";
	}

	void assertFalse(bool actualValue){
		if (!actualValue)
			std::cout << "TEST OK\n";
		else
			std::cout << "TEST FAIL\n";
	}
};

class TestSolverSquareEquation: public TestCase, SolverSquareEquation
{
public:
	void runTest(){
		testDiscriminant();
		testSolverEquation();
	}
private:
	void testDiscriminant(){
		std::cout<<"---Test Discriminant---"<<std::endl;

		std::cout<<"Test 1: ";
		assertEquals(discriminant(3, -5, 2), 1.0);

		std::cout<<"Test 2: ";
		assertEquals(discriminant(4, 4, 1), 0.);

		std::cout<<"Test 3: ";
		assertEquals(discriminant(3.0, -5, 5), -35.0);
	}

	void testSolverEquation(){
		std::cout<<"---Test SolverEquation---"<<std::endl;
		std::vector<double> resVec; 
		resVec.push_back(3); resVec.push_back(2); 
		
		std::cout<<"Test 1: ";
		//2 roots
		assertEquals(resVec,rootSquareEquation(1, -5, 6)); resVec.clear();

		std::cout<<"Test 2: ";
		//1 roots
		resVec.push_back(5);
		assertEquals(resVec,rootSquareEquation(1, -10, 25)); resVec.clear();

		std::cout<<"Test 3: ";
		//0 roots
		assertEquals(resVec,rootSquareEquation(1, -5, 7));

		std::cout<<"Test 4: ";
		//boundary values
		assertEquals(resVec,rootSquareEquation(0, -5, 7));
	}
};
#endif//TEST_SOLVER_SQUARE_EQUATION
