#include <iostream>
#include <algorithm>
#include <regex> 

using namespace std;

double sumar(double x, double y){return x + y;}

double resta(double x, double y){return x-y;}

double producto(double x, double y){return x*y;}

double division (double x, double y){return y!= 0 ? x/y : 0;}

bool esEntero(const std::string& input) {
    return !input.empty() && all_of(input.begin(), input.end(), ::isdigit);
}


