//Dynamics is verified with Mathematica data
#include <iostream>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <Eigen/Dense>
#include "dyn_funcs_test.h"
#include <fstream>

using namespace Eigen;

VectorXd doubledots(VectorXd qss);

int func (double t, const double y[], double f[], void *params)
{
VectorXd qss(36), dd(18);
qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], \
y[11], y[12], y[13], y[14], y[15], y[16], y[17], y[18], y[19], y[20], y[21], y[22], y[23], y[24], y[25], y[26], y[27], \
y[28], y[29], y[30], y[31], y[32], y[33], y[34], y[35];
//Calling dd function
dd = doubledots(qss);
//Declaring the statespace
f[0] = y[18];
f[1] = y[19];
f[2] = y[20];
f[3] = y[21];
f[4] = y[22];
f[5] = y[23];
f[6] = y[24];
f[7] = y[25];
f[8] = y[26];
f[9] = y[27];
f[10] = y[28];
f[11] = y[29];
f[12] = y[30];
f[13] = y[31];
f[14] = y[32];
f[15] = y[33];
f[16] = y[34];
f[17] = y[35];
f[18] = dd(0);
f[19] = dd(1);
f[20] = dd(2);
f[21] = dd(3);
f[22] = dd(4);
f[23] = dd(5);
f[24] = dd(6);
f[25] = dd(7);
f[26] = dd(8);
f[27] = dd(9);
f[28] = dd(10);
f[29] = dd(11);
f[30] = dd(12);
f[31] = dd(13);
f[32] = dd(14);
f[33] = dd(15);
f[34] = dd(16);
f[35] = dd(17);
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
  VectorXd qss(36), dd(18);
    gsl_odeiv2_system sys = {func, NULL, 36, NULL};

    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rkf45, 1e-6, 1e-6, 0.0);
    int i;
    double t = 0.0, t1 = 1, chops = 100.0;
    double y[36] = {-0.17618033875594355,-0.2667245792909399,0.42390218334416085,0.42390218334416097,
     -0.2667245792909397,-0.1761803387559433,0.39064841061634575,0.33709521577064094,
     -0.05006177387374231,0.05006177387374231,-0.33709521577064094,-0.3906484106163457,
     1.2083279353106968,1.2083279353106968,1.2083279353106968,1.2083279353106968,
     1.2083279353106968,1.2083279353106968, 0.06624059529735819,0.08303839919975613,0.07035174383427205,0.008916220242014095,
      -0.0037704351234699287,0.03025924388757712,0.1083516789955628,0.08633350197948997,
      0.050290758373406255,0.05029075837340627,0.08633350197949005,0.1424329143422793,0.1,0,0,0,0,
      0};

	for (i = 1; i <= chops; i++)
    {
        double ti = i * t1 / chops;
        int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

        if (status != GSL_SUCCESS)
        {
            printf ("error, return value=%d\n", status);
            break;
        }
        //Printing the values
       //printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[0],y[1],y[2],y[3],y[4],y[5], y[6], y[7], y[8], y[9], y[10], \
       //y[11], y[12], y[13], y[14], y[15], y[16], y[17]);
       //printf ("%.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e %.5e\n ", t, y[18], y[19], y[20], y[21], y[22], y[23], y[24], y[25], y[26], y[27], \
       //y[28], y[29], y[30], y[31], y[32], y[33], y[34], y[35]);
       //writing a code to dump this data into a csv file


       file <<t<<" "<<y[0]<<" "<<y[1]<<" "<<y[2]<<" "<<y[3]<<" "<<y[4]<<" "<<y[5]<<" "<<y[6]<<" "<<y[7]<<" "<<y[8]<<" "<<y[9]<<" "<<y[10]<<" "\
       <<y[11]<<" "<<y[12]<<" "<<y[13]<<" "<<y[14]<<" "<<y[15]<<" "<<y[16]<<" "<<y[17]<<" "<<std::endl;
       dfile <<t<<" "<<y[18]<<" "<< y[19]<<" "<< y[20]<<" "<< y[21]<<" "<< y[22]<<" "<< y[23]<<" "<< y[24]<<" "<<y[25]<<" "<< y[26]<<" "<< y[27]\
       <<" "<<y[28]<<" "<<y[29]<<" "<<y[30]<<" "<<y[31]<<" "<<y[32]<<" "<<y[33]<<" "<<y[34]<<" "<<y[35]<<std::endl;
       qss << y[0], y[1], y[2], y[3], y[4], y[5], y[6], y[7], y[8], y[9], y[10], \
       y[11], y[12], y[13], y[14], y[15], y[16], y[17], y[18], y[19], y[20], y[21], y[22], y[23], y[24], y[25], y[26], y[27], \
       y[28], y[29], y[30], y[31], y[32], y[33], y[34], y[35];
       dd = doubledots(qss);
       ddfile <<t<<" "<<dd(0)<<" "<<dd(1)<<" "<<dd(2)<<" "<<dd(3)<<" "<<dd(4)<<" "<<dd(5)<<" "<<dd(6)<<" "<<dd(7)<<" "<<dd(8)<<" "<<dd(9)<<" "\
       <<dd(10)<<" "<<dd(11)<<" "<<dd(12)<<" "<<dd(13)<<" "<<dd(14)<<" "<<dd(15)<<" "<<dd(16)<<" "<<dd(17)<<std::endl;



    }

    gsl_odeiv2_driver_free (d);
    return 0;
}


//doubledots
VectorXd doubledots(VectorXd qss){
	MatrixXd Minv(18,18), Mval(18,18), Cval(18,18), Jetaqval(12,18), dJetaqval(12,18), lambda(18,12);
	VectorXd Gval(18), Qvec(18), dd(18), qvals(18), dqvals(18);
  qvals = qss.head(18);
  dqvals = qss.tail(18);

	Mval = Mmat(qvals);
	Cval = Cmat(qvals, dqvals);
	Gval = Gvec(qvals);
	Jetaqval = Jetaqmat(qvals);
	dJetaqval = dJetaqmat(qvals, dqvals);
	Minv = Mval.inverse();
	//Constraint
	// lambda = (-(Jetaqval*Minv*Jetaqval.transpose()).inverse())*(Jetaqval*Minv*(-Cval*dq-Gval));
	lambda = (-(Jetaqval*Minv*Jetaqval.transpose()).inverse())*(dJetaqval*dqvals+Jetaqval*Minv*(-Cval*dqvals-Gval));
	Qvec=(Jetaqval.transpose())*lambda;
	//Configuration space dynamics
	dd = -(Mval.inverse())*(Cval*dqvals+Gval-Qvec);
	return dd;
}
