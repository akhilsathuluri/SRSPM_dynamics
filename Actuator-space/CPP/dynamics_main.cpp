//Dynamics is verified with Mathematica data
#include <iostream>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <Eigen/Dense>
#include "Cfuncs.h"
#include "helper_funcs.h"
#include <fstream>
//#include "dyn_funcs_test.h"

using namespace Eigen;

VectorXd doubledots(VectorXd qthss);
VectorXd tempphi(12);

int func (double t, const double y[], double f[], void *params)
{
double vals[] = {y[0], y[1], y[2], y[3], y[4], y[5]};
double dvals[] = {y[6], y[7], y[8], y[9], y[10], y[11]};
VectorXd qss(12), dd(6);
qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], y[11];
// phi values at time t=0
tempphi << -0.17618033875594355,-0.2667245792909399,0.42390218334416085,0.42390218334416097,
   -0.2667245792909397,-0.1761803387559433,0.39064841061634575,0.33709521577064094,
   -0.05006177387374231,0.05006177387374231,-0.33709521577064094,-0.3906484106163457;
//Calling dd function
dd = doubledots(qss);
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
/*
  std::ofstream ddfile;
  ddfile.open("dddata.dat");
  std::ofstream file;
  std::ofstream dfile;
  file.open("qxdata.dat");
  dfile.open("dqxdata.dat");
*/
  VectorXd qss(12), dd(6);
    gsl_odeiv2_system sys = {func, NULL, 12, NULL};

    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-7, 1e-6, 0.0);
    int i;
    double t = 0.0, t1 = 0.48;
    double y[12] = {1.2083279353106968,1.2083279353106968,1.2083279353106968,1.2083279353106968, 1.2083279353106968,1.2083279353106968, 0,0,0,0,0,0};
//    double y[12] = {1.16276,1.16276,1.16276,1.16276,1.16276,1.16276,0, 0,0,0,0,0};
//    double y[12] = {1.2083,1.2083,1.2083,1.2083,1.2083,1.2083, 0, 0,0, 0, 0, 0};

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
/*
      printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[0],y[1],y[2],y[3],y[4],y[5]);
      printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[6], y[7], y[8], y[9], y[10], y[11]);
*/
/*
    file <<t<<" "<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<" "<<y[4]<<" "<<y[5]<<std::endl;
       dfile <<t<<" "<<y[6]<<" "<<y[7]<<" "<<y[8]<<" "<<y[9]<<" "<<y[10]<<" "<<y[11]<<std::endl;
       qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], \
       y[11];
       dd = doubledots(qss);
       ddfile <<t<<" "<<dd(0)<<" "<<dd(1)<<" "<<dd(2)<<" "<<dd(3)<<" "<<dd(4)<<" "<<dd(5)<<std::endl;
*/
    }

    gsl_odeiv2_driver_free (d);
    return 0;
}

//doubledots
VectorXd doubledots(VectorXd qthss){
	//Root Tracker
	VectorXd qvals(18), dqvals(18), thetai(6), dthetai(6);
	thetai = qthss.head(6);
	dthetai = qthss.tail(6);
	tempphi = TrackRoot(thetai, tempphi);
	qvals << tempphi, thetai;
	//Computing dq
	MatrixXd Mval(18,18), Cval(18,18), Jetathval(12,6), Jetaphval(12,12), dJetathval(12,6), dJetaphval(12,12), Mthval(6,6), Cthval(6,6)\
	, Jqthval(18,6), dJphthval(12,6), dJqthval(18,6), Jphthval(12,6);
	VectorXd Gval(18), dd(6), Gthval(6);
	//Jacobians for embedded formulation
	Jetathval = Jetathmat(qvals);
	Jetaphval = Jetaphmat(qvals);
	Jphthval = -(Jetaphval.inverse())*Jetathval;
	dqvals << Jphthval*dthetai, dthetai;
	Jqthval <<  Jphthval, MatrixXd::Identity(6,6);
	//Now getting the velocity of the passive variables
	dJetathval = dJetathmat(qvals, dqvals);
	dJetaphval = dJetaphmat(qvals, dqvals);
	dJqthval << (Jetaphval.inverse())*(-dJetathval+dJetaphval*(Jetaphval.inverse())*Jetathval), MatrixXd::Zero(6,6);
	//Constructing the matrices
	Mval = Mmat(qvals);
	Cval = Cmat(qvals, dqvals);
	Gval = Gvec(qvals);
	//Mapping the matrices
	Mthval = (Jqthval.transpose())*Mval*Jqthval;
	Cthval = (Jqthval.transpose())*(Mval*dJqthval+Cval*Jqthval);
	Gthval = (Jqthval.transpose())*Gval;
	//So the dd will be
	dd = -(Mthval.inverse())*(Cthval*dthetai+Gthval);
	return dd;
}
