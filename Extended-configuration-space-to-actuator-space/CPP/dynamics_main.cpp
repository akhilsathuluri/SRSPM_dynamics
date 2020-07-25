//Dynamics is verified with Mathematica data
#include <iostream>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <Eigen/Dense>
#include "helper_funcs.h"
#include <fstream>

using namespace Eigen;

VectorXd doubledots(VectorXd qthss);
VectorXd tempphi(18);

int func (double t, const double y[], double f[], void *params)
{
double vals[] = {y[0], y[1], y[2], y[3], y[4], y[5]};
double dvals[] = {y[6], y[7], y[8], y[9], y[10], y[11]};
VectorXd qss(12), dd(6);
qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], y[11];
// phi values at time t=0
tempphi << 0, 0, 1.1, 0, 0, 0, -0.17618033875594355, -0.2667245792909399, \
0.42390218334416085, 0.42390218334416097, -0.2667245792909397, \
-0.1761803387559433, 0.39064841061634575, 0.33709521577064094, \
-0.05006177387374231, 0.05006177387374231, -0.33709521577064094, \
-0.3906484106163457;
//Calling dd function
// printf("starting double dots");
//std::cout<<"computing doubledots"<<std::endl;

dd = doubledots(qss);
//printf("double dots computed");
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
// printf("Entered main");
    gsl_odeiv2_system sys = {func, NULL, 12, NULL};
    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-7, 1e-6, 0.0);
    int i;
    double t = 0.0, t1 = 0.48;
    double y[12] = {1.2083279353106968,1.2083279353106968,1.2083279353106968,1.2083279353106968,
   1.2083279353106968,1.2083279353106968, 0,0,0,0,0,0};

    for (i = 1; i <= 100; i++)
    {
        double ti = i * t1 / 100.0;
        int status = gsl_odeiv2_driver_apply (d, &t, ti, y);
        if (status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }
/*  
      //Printing the values
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
	VectorXd qe(24), dqvals(18), dqe(24), thvals(6), dthvals(6);
	thvals = qthss.head(6);
	dthvals = qthss.tail(6);
	//Root tracking
	tempphi = TrackRoot(thvals, tempphi);
	qe << tempphi.tail(12), thvals, tempphi.head(6);
	//Compute dqe
	MatrixXd Jetqphival(passive,passive),Jetqthval(passive,active), Jqphiqxval(passive,active), Jqphiqthval(passive,active), Jqethval(coords,active), tempJ(coords,active);
	  Jetqphival = Jetaqphimat(qe);
	  Jetqthval = Jetaqthmat(qe);
	  Jqphiqthval = -((Jetqphival.inverse())*Jetqthval);
	  dqvals = Jqphiqthval*dthvals;
	  dqe << dqvals.tail(12), dthvals, dqvals.head(6);
	  Jqethval << Jqphiqthval, MatrixXd::Identity(active,active);
	  //Computing the coefficient matrices
	  MatrixXd Mval(coords, coords), Cval(coords, coords);
	  VectorXd Gval(coords);
	  Mval = Mmat(qe);
	  Cval = Cmat(qe, dqe);
	  Gval = Gvec(qe);
	  //Computing the Jacobians
	  MatrixXd dJetqphival(passive,passive), dJetqthval(passive,active), dJqethval(coords,active);
	  dJetqphival = dJetaqphimat(qe, dqe);
	  dJetqthval = dJetaqthmat(qe, dqe);
	  //Concatenating these matrices for getting the mapping
	  dJqethval << (Jetqphival.inverse())*(dJetqphival*(Jetqphival.inverse())*Jetqthval-dJetqthval), MatrixXd::Zero(active,active);
	  MatrixXd Mthval(active,active), Cthval(active,active);
	  VectorXd Gthval(active), dd(active);
	  Mthval = (Jqethval.transpose())*Mval*Jqethval;
	  Cthval = (Jqethval.transpose())*(Mval*dJqethval+Cval*Jqethval		 );
	  Gthval = (Jqethval.transpose())*Gval;
	  //Dynamics equations
//	  dd = -(Mthval.inverse())*(Cthval*dthvals+Gthval);
	  dd = -LinearSolve2(Mthval, (Cthval*dthvals+Gthval));
	  
	  //dd = -LinearSolve2(Mthval, (Cthval*dthvals+Gthval));
	  return dd;
}
