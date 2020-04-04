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

// dJetaqx matrix
MatrixXd dJetaqxmat(VectorXd vals, VectorXd dvals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23) , dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
dl6=dvals(17), dx=dvals(18), dy=dvals(19), dz=dvals(20), dc1=dvals(21), dc2=dvals(22), \
dc3=dvals(23);
MatrixXd dJetaqxval(passive,active);
dJetaqxval<< `dJetaqxexpressions1`;
return dJetaqxval;
}

// Jetaqx matrix
MatrixXd Jetaqxmat(VectorXd vals){
double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
l6=vals(17), x=vals(18), y=vals(19), z=vals(20), c1=vals(21), c2=vals(22), \
c3=vals(23);
MatrixXd Jetaqxmat(passive, active);
Jetaqxmat << `Jetaqxexpressions1`;
return Jetaqxmat;
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

// iksolver
VectorXd iksolver(VectorXd ts){
  double x=ts(0), y=ts(1), z=ts(2), c1=ts(3), c2=ts(4), c3=ts(5);
  VectorXd li(6), phi(6), psi(6), fullq(18);
  li << `lexpressions1`;

double l1 = li(1);  
double l2 = li(2);  
double l3 = li(3);  
double l4 = li(4);  
double l5 = li(5);  
double l6 = li(6);

  psi << `psiexpressions1`;

double s1 = psi(1);  
double s2 = psi(2);  
double s3 = psi(3);  
double s4 = psi(4);  
double s5 = psi(5);  
double s6 = psi(6);  

  phi << `phiexpressions1`;

  fullq << phi, psi, li;
  return fullq;
}

// double dots
VectorXd doubledots(VectorXd qxss){
  //Extracting the position and veelocity
  VectorXd xvals(active), dxvals(active);
  xvals = qxss.head(active);
  dxvals = qxss.tail(active);
  //Computing ik
  VectorXd qvals(passive), qe(coords), dqvals(passive), dqe(coords);
  qvals = iksolver(xvals);
  qe << qvals, xvals;
  //Compute dqe
  MatrixXd Jetqphival(passive,passive),Jetqxval(passive,active), Jqphiqxval(passive,active), Jqphitest(passive,active), Jqphixval(coords,active), tempJ(coords,active);
  Jetqphival = Jetaqphimat(qe);
  Jetqxval = Jetaqxmat(qe);
  Jqphiqxval = -((Jetqphival.inverse())*Jetqxval);
  dqvals = Jqphiqxval*dxvals;
  dqe << dqvals, dxvals;
  Jqphixval << MatrixXd::Identity(active,active), Jqphiqxval;
  //Computing the coefficient matrices
  MatrixXd Mval(coords, coords), Cval(coords, coords);
  VectorXd Gval(coords);
  Mval = Mmat(qe);
  Cval = Cmat(qe, dqe);
  Gval = Gvec(qe);
  //Computing the Jacobians
  MatrixXd dJetqphival(passive,passive), dJetqxval(passive,active), dJqphixval(coords,active);
  dJetqphival = dJetaqphimat(qe, dqe);
  dJetqxval = dJetaqxmat(qe, dqe);
  //Concatenating these matrices for getting the mapping
  dJqphixval << MatrixXd::Zero(active,active), (Jetqphival.inverse())*(dJetqphival*(Jetqphival.inverse())*Jetqxval-dJetqxval);
  MatrixXd Mxval(active,active), Cxval(active,active);
  VectorXd Gxval(active), dd(active);
  Mxval = (Jqphixval.transpose())*Mval*Jqphixval;
  Cxval = (Jqphixval.transpose())*(Mval*dJqphixval+Cval*Jqphixval);
  Gxval = (Jqphixval.transpose())*Gval;
  //Dynamics equations
  dd = -(Mxval.inverse())*(Cxval*dxvals+Gxval);
  return dd;
}
