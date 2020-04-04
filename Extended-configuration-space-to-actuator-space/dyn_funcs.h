#include<iostream>
#include<Eigen/Dense>

using namespace Eigen;

#define coords 24
#define passive 18
#define active 6

// Mass Matrix
MatrixXd Mmat(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
double cs21=cos(2*s1), cs22=cos(2*s2), cs23=cos(2*s3), cs24=cos(2*s4), cs25=cos(2*s5), \
cs26=cos(2*s6);
MatrixXd Mval(coords, coords);
Mval << `Mexpressions1`;
return Mval;
}

// C matrix
MatrixXd Cmat(VectorXd q, VectorXd dq){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23), dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
dl6=dvals(17), dx=dvals(18), dy=dvals(19), dz=dvals(20), dc1=dvals(21), dc2=dvals(22), \
dc3=dvals(23);
double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6);
MatrixXd Cval(coords, coords);
Cval << `Cexpressions1`;
return Cval;
}

// Gravity Vector
VectorXd Gvec(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
VectorXd Gval(coords);
Gval << `Gexpressions1`;
return Gval;
}

// dJetaqphi matrix
MatrixXd dJetaqphimat(VectorXd vals, VectorXd dvals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23) , dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
dl6=dvals(17), dx=dvals(18), dy=dvals(19), dz=dvals(20), dc1=dvals(21), dc2=dvals(22), \
dc3=dvals(23);
double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd dJetaqphival(passive,passive);
dJetaqphival << `dJetaqphiexpressions1`;
return dJetaqphival;
}

// dJetaqth matrix
MatrixXd dJetaqthmat(VectorXd vals, VectorXd dvals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23) , dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
dl6=dvals(17), dx=dvals(18), dy=dvals(19), dz=dvals(20), dc1=dvals(21), dc2=dvals(22), \
dc3=dvals(23);
MatrixXd dJetaqthval(passive,active);
dJetaqthval<< `dJetaqthexpressions1`;
return dJetaqthval;
}

// Jetaqth matrix
MatrixXd Jetaqthmat(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
MatrixXd Jetaqthmat(passive, active);
Jetaqthmat << `Jetaqthexpressions1`;
return Jetaqthmat;
}

// Jetaqphi matrix
MatrixXd Jetaqphimat(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd Jetaqphimat(passive, passive);
Jetaqphimat << `Jetaqphiexpressions1`;
return Jetaqphimat;
}

// Loop-closure equations
VectorXd etavec(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
VectorXd etaval(coords);
etaval << `etaexpressions1`;
return etaval;
}