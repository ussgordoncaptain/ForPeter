// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std; 

class finalValueContainer {
public:
    double functionReturn;
    double var1;
    double var2;
    double var3;
    double var4;
    double var5;
    double var6;
    double var7;
    finalValueContainer(double mainReturn, double a, double b, double c, double d, double e, double f, double g) {
        functionReturn = mainReturn;
        var1 = a;
        var2 = b;
        var3 = c;
        var4 = d;
        var5 = e;
        var6 = f;
        var7 = g;
    }
   bool operator < (finalValueContainer tester) {
       return this->functionReturn < tester.functionReturn;
   }
   bool operator < (double beatThis) {
       return this->functionReturn < beatThis;
   }
   ~finalValueContainer() {}
};

double arbitaryBlackBoxTest(double var1, double var2, double var3, double var4, double var5, double var6, double var7) {
    return (var1*var4 + var2 * var3+var6 * var7  + var5/5+var4*var5);
}

shared_ptr <finalValueContainer> blackBoxTester( int max_step_size) {
   int num_variables = 7; //in lisp you could dynamically increase the number of for loops please don't ask how to do this 
  shared_ptr <finalValueContainer> output = make_shared<finalValueContainer>(0, 0, 0, 0, 0, 0, 0, 0);
    for (int step_size = 1; step_size <= max_step_size; step_size *= 2) {
        double step_divisor = step_size * num_variables;
        int step_quantity = step_size * num_variables;
        for (int ii = 0; ii <= step_quantity; ii++) {
            int step_quantity2 = step_quantity - ii;
            //keeping track of sets of step quantities because just subtracting from 1 main Q will give errors later
            double var1 = static_cast<double>(ii) / step_divisor;
            for (int jj = 0; jj <= step_quantity2; jj++) {
                int step_quantity3 = step_quantity2 - jj;
                double var2 = static_cast<double>(jj) / step_divisor;
                for (int kk = 0; kk <= step_quantity3; kk++) {
                    int step_quantity4 = step_quantity3 - kk;
                    double var3 = static_cast<double>(kk) / step_divisor;
                    for (int ll = 0; ll <= step_quantity4; ll++) {
                        int step_quantity5 = step_quantity4 - ll;
                        double var4 = static_cast<double>(ll) / step_divisor;
                        for (int mm = 0; mm <= step_quantity5; mm++) {
                            int step_quantity6 = step_quantity5 - mm;
                            double var5 = static_cast<double>(mm) / step_divisor;
                            for (int nn = 0; nn <= step_quantity6; nn++) {
                                int step_quantity7 = step_quantity6 - nn;
                                double var6 = static_cast<double>(nn) / step_divisor;
                                double var7 = static_cast<double>(step_quantity7) / step_divisor;
                                assert((var1 + var2 + var3 + var4 + var5 + var6 + var7) < 1.000001);
                                assert(var1 + var2 + var3 + var4 + var5 + var6 + var7 > 0.999999999);
                                double blackBoxTest= arbitaryBlackBoxTest(var1, var2, var3, var4, var5, var6, var7);
                                if (*output<blackBoxTest) {
                                    //hopefully there is no memory leak, if someone remembers how to delete zombie children other than a shared_PTR remind me
                                    output->functionReturn = blackBoxTest;
                                    output->var1 = var1;
                                    output->var2 = var2;
                                    output->var3 = var3;
                                    output->var4 = var4;
                                    output->var5 = var5;
                                    output->var6 = var6;
                                    output->var7 = var7;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return output;
}




int main()
{
     shared_ptr <finalValueContainer> a = blackBoxTester(2);
    cout << a->functionReturn << endl;
    
    
    //writing tests RN
    
    //okvalues of the test up until 33 are fine, then at that point you get to the part where it will hang for an unreasoably long time. (so you get 7*16=112 parts)
    // you could change this to accept the top 50 or so values then write a different funciton that takes the top 50 scores and looks "around" those numbers for the best from there
    
}
