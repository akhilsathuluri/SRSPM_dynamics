# include <iostream>
# include <Eigen/Dense>
# include "dyn_funcs_test.h"

using namespace Eigen;

//Root Tracking via Newton-Raphson
VectorXd TrackRoot(VectorXd thetai, VectorXd phii){
	VectorXd qval(18), tempphi(12), dphi(12), nvec(12);
	MatrixXd Jmat(12,12);
	int loopcounter=0;
	qval << phii, thetai;
	nvec = etavec(qval);
	loopcounter = 0;
	tempphi = phii;
	while ((nvec.cwiseAbs()).maxCoeff()>=pow(10, -15)) {
		if (loopcounter>=100)
			break;
		loopcounter++;
		// qval << tempphi, thetai;
		Jmat = Jetaphmat(qval);
		dphi = LinearSolve(Jmat, nvec);
		tempphi = tempphi - dphi;
		qval << tempphi, thetai;
		nvec = etavec(qval);
	}
	return tempphi;
}
