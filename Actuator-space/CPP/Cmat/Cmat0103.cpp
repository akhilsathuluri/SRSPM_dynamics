#include <iostream>
#include <cmath>

double Cmat0103(double* gen_coords, double* dgen_coords)
{
	//Variables
	double p1 = gen_coords[0];
	double p2 = gen_coords[1];
	double p3 = gen_coords[2];
	double p4 = gen_coords[3];
	double p5 = gen_coords[4];
	double p6 = gen_coords[5];

	double s1 = gen_coords[6];
	double s2 = gen_coords[7];
	double s3 = gen_coords[8];
	double s4 = gen_coords[9];
	double s5 = gen_coords[10];
	double s6 = gen_coords[11];

	double l1 = gen_coords[12];
	double l2 = gen_coords[13];
	double l3 = gen_coords[14];
	double l4 = gen_coords[15];
	double l5 = gen_coords[16];
	double l6 = gen_coords[17];

	double dp1 = dgen_coords[0];
	double dp2 = dgen_coords[1];
	double dp3 = dgen_coords[2];
	double dp4 = dgen_coords[3];
	double dp5 = dgen_coords[4];
	double dp6 = dgen_coords[5];

	double ds1 = dgen_coords[6];
	double ds2 = dgen_coords[7];
	double ds3 = dgen_coords[8];
	double ds4 = dgen_coords[9];
	double ds5 = dgen_coords[10];
	double ds6 = dgen_coords[11];

	double dl1 = dgen_coords[12];
	double dl2 = dgen_coords[13];
	double dl3 = dgen_coords[14];
	double dl4 = dgen_coords[15];
	double dl5 = dgen_coords[16];
	double dl6 = dgen_coords[17];

	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);


	double Cmat0103 = 0. + 0.20339*dp3*((cp3*cs1*cs3*l1*l3*sp1)/36. - (cp1*cs1*cs3*l1*l3*sp3)/36.) + 0.20339*dl3*((cp1*cp3*cs1*cs3*l1)/36. + (cs1*cs3*l1*sp1*sp3)/36.) + 0.20339*ds3*(-(cp1*cp3*cs1*l1*l3*ss3)/36. - (cs1*l1*l3*sp1*sp3*ss3)/36.);

	return(Cmat0103);
}