# include <iostream>
# include <Eigen/Dense>
# include "dyn_funcs_test.h"

using namespace Eigen;

//Root Tracking via Newton-Raphson
VectorXd TrackRoot(VectorXd thetai, VectorXd phii){
	VectorXd qval(24), tempphi(18), dphi(18), nvec(18);
	MatrixXd Jmat(18,18);
	int loopcounter=0;
	qval << phii.tail(12), thetai, phii.head(6);
	nvec = etavec(qval);
	loopcounter = 0;
	tempphi = phii;
	while ((nvec.cwiseAbs()).maxCoeff()>=pow(10, -15)) {
		if (loopcounter>=25)
			break;
		loopcounter++;
		Jmat = Jetaqphimat(qval);
		dphi = LinearSolve(Jmat, nvec);
//		dphi = Jmat.inverse()*nvec;
		tempphi = tempphi - dphi;
		qval << tempphi.tail(12), thetai, tempphi.head(6);
		nvec = etavec(qval);
	}
	return tempphi;
}
