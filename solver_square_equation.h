#ifndef SOLVER_SQUARE_EQUATION_H
#define SOLVER_SQUARE_EQUATION_H
#include <cmath>
#include <vector>

class SolverSquareEquation{
public:
	std::vector<double> rootSquareEquation(double a,double b, double c){
		std::vector<double> vRoots;
		if (a==0) {
			errorLine = "a == 0";
			return vRoots;
		}
		double D = discriminant(a, b, c);
		if (D > 0){ 
			vRoots.push_back((-b + std::sqrt(D)) / (2 * a));
			vRoots.push_back((-b - std::sqrt(D)) / (2 * a));
		}
		if (D == 0){
			vRoots.push_back(-b/(2*a));
		}
		if (D < 0){
			errorLine = "D < 0";
		}
		printResult(vRoots);
		return vRoots;
	}
	std::string errorMessage(){
		return errorLine;
	}
protected:
	double discriminant(double a, double b, double c){
		return std::pow(b,2) - 4*a*c;
	}
	void printResult(const std::vector<double> &vroots){
		if (vroots.empty()) 
			std::cout<<"Not roots! Because: "<<errorLine.c_str()<<std::endl;
		for(size_t i = 0; i < vroots.size(); ++i){
			char chr[255] = {'\0'};
			sprintf(chr,"x%d = %f", i, vroots[i]);
			std::cout<<chr<<std::endl;
		}

	}

	
private:
	std::string errorLine;
};

#endif //SOLVER_SQUARE_EQUATION_H
