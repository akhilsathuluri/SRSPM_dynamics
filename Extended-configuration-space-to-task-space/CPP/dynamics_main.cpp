//Dynamics is verified with Mathematica data
//Using -Ofast executes 0.5 seconds of dynamics in 0.042s
#include <iostream>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <Eigen/Dense>
#include "dyn_funcs_test.h"
#include <fstream>

using namespace Eigen;

int func (double t, const double y[], double f[], void *params)
{
double vals[] = {y[0],y[1],y[2],y[3],y[4],y[5]};
double dvals[] = {y[6],y[7],y[8],y[9],y[10],y[11]};
VectorXd qxss(12), dd(6);
qxss << y[0],y[1],y[2],y[3],y[4],y[5],y[6],y[7],y[8],y[9],y[10],y[11];
//Calling dd function
dd = doubledots(qxss);
//Declaring the statespace
f[0] = y[6];
f[1] = y[7];
f[2] = y[8];
f[3] = y[9];
f[4] = y[10];
f[5] = y[11];
f[6] = dd(0);
f[7] = dd(1);
f[8] = dd(2);
f[9] = dd(3);
f[10] = dd(4);
f[11] = dd(5);
return GSL_SUCCESS;
}

int * jac;

int main ()
{
  std::ofstream ddfile;
  ddfile.open("dddata.dat");
  std::ofstream file;
  std::ofstream dfile;
  file.open("qxdata.dat");
  dfile.open("dqxdata.dat");
  VectorXd qss(12), dd(6);

    gsl_odeiv2_system sys = {func, NULL, 12, NULL};

    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-6, 1e-6, 0.0);
    int i;
    double t = 0.0, t1 = 1;
    double y[12] = {0, 0, 1.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0, 0};

    for (i = 1; i <= 100; i++)
    {
        double ti = i * t1 / 100.0;
        int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

        if (status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }
        //Printing the values
//       printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[0],y[1],y[2],y[3],y[4],y[5]);
 //      printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[6],y[7],y[8],y[9],y[10],y[11]);
     file <<t<<" "<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<" "<<y[4]<<" "<<y[5]<<std::endl;
       dfile <<t<<" "<<y[6]<<" "<<y[7]<<" "<<y[8]<<" "<<y[9]<<" "<<y[10]<<" "<<y[11]<<std::endl;
       qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], \
       y[11];
       dd = doubledots(qss);
       ddfile <<t<<" "<<dd(0)<<" "<<dd(1)<<" "<<dd(2)<<" "<<dd(3)<<" "<<dd(4)<<" "<<dd(5)<<std::endl;

    }

    gsl_odeiv2_driver_free (d);
    return 0;
}
