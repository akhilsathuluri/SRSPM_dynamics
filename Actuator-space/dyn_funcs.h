#include<iostream>
#include<Eigen/Dense>
#include"Cfuncs.h"

using namespace Eigen;

#define coords 18
#define passive 12
#define active 6

// Mass Matrix
MatrixXd Mmat(VectorXd vals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd Mval1(coords,coords), diagM(coords,coords), Mval(coords,coords);
Mval1 << `Mexpressions1`;
diagM << `Mexpressions2`;
Mval = diagM+Mval1+(Mval1.transpose());
return Mval;
}

// C matrix
MatrixXd Cmat(VectorXd q, VectorXd dq){
double vals[] = {q(0), q(1), q(2), q(3), q(4), q(5), q(6), q(7), q(8), q(9), q(10), \
q(11), q(12), q(13), q(14), q(15), q(16), q(17)};
double dvals[] = {dq(0), dq(1), dq(2), dq(3), dq(4), dq(5), dq(6), dq(7), dq(8), dq(9), \
dq(10), dq(11), dq(12), dq(13), dq(14), dq(15), dq(16), dq(17)};
MatrixXd Cmat(18, 18);
Cmat<< Cmat0101(vals, dvals), Cmat0102(vals, dvals), Cmat0103(vals, dvals), Cmat0104(vals, dvals), Cmat0105(vals, dvals), Cmat0106(vals, dvals), Cmat0107(vals, dvals), Cmat0108(vals, dvals), Cmat0109(vals, dvals), Cmat0110(vals, dvals), Cmat0111(vals, dvals), Cmat0112(vals, dvals), Cmat0113(vals, dvals), Cmat0114(vals, dvals), Cmat0115(vals, dvals), Cmat0116(vals, dvals), Cmat0117(vals, dvals), Cmat0118(vals, dvals), Cmat0201(vals, dvals), Cmat0202(vals, dvals), Cmat0203(vals, dvals), Cmat0204(vals, dvals), Cmat0205(vals, dvals), Cmat0206(vals, dvals), Cmat0207(vals, dvals), Cmat0208(vals, dvals), Cmat0209(vals, dvals), Cmat0210(vals, dvals), Cmat0211(vals, dvals), Cmat0212(vals, dvals), Cmat0213(vals, dvals), Cmat0214(vals, dvals), Cmat0215(vals, dvals), Cmat0216(vals, dvals), Cmat0217(vals, dvals), Cmat0218(vals, dvals), Cmat0301(vals, dvals), Cmat0302(vals, dvals), Cmat0303(vals, dvals), Cmat0304(vals, dvals), Cmat0305(vals, dvals), Cmat0306(vals, dvals), Cmat0307(vals, dvals), Cmat0308(vals, dvals), Cmat0309(vals, dvals), Cmat0310(vals, dvals), Cmat0311(vals, dvals), Cmat0312(vals, dvals), Cmat0313(vals, dvals), Cmat0314(vals, dvals), Cmat0315(vals, dvals), Cmat0316(vals, dvals), Cmat0317(vals, dvals), Cmat0318(vals, dvals), Cmat0401(vals, dvals), Cmat0402(vals, dvals), Cmat0403(vals, dvals), Cmat0404(vals, dvals), Cmat0405(vals, dvals), Cmat0406(vals, dvals), Cmat0407(vals, dvals), Cmat0408(vals, dvals), Cmat0409(vals, dvals), Cmat0410(vals, dvals), Cmat0411(vals, dvals), Cmat0412(vals, dvals), Cmat0413(vals, dvals), Cmat0414(vals, dvals), Cmat0415(vals, dvals), Cmat0416(vals, dvals), Cmat0417(vals, dvals), Cmat0418(vals, dvals), Cmat0501(vals, dvals), Cmat0502(vals, dvals), Cmat0503(vals, dvals), Cmat0504(vals, dvals), Cmat0505(vals, dvals), Cmat0506(vals, dvals), Cmat0507(vals, dvals), Cmat0508(vals, dvals), Cmat0509(vals, dvals), Cmat0510(vals, dvals), Cmat0511(vals, dvals), Cmat0512(vals, dvals), Cmat0513(vals, dvals), Cmat0514(vals, dvals), Cmat0515(vals, dvals), Cmat0516(vals, dvals), Cmat0517(vals, dvals), Cmat0518(vals, dvals), Cmat0601(vals, dvals), Cmat0602(vals, dvals), Cmat0603(vals, dvals), Cmat0604(vals, dvals), Cmat0605(vals, dvals), Cmat0606(vals, dvals), Cmat0607(vals, dvals), Cmat0608(vals, dvals), Cmat0609(vals, dvals), Cmat0610(vals, dvals), Cmat0611(vals, dvals), Cmat0612(vals, dvals), Cmat0613(vals, dvals), Cmat0614(vals, dvals), Cmat0615(vals, dvals), Cmat0616(vals, dvals), Cmat0617(vals, dvals), Cmat0618(vals, dvals), Cmat0701(vals, dvals), Cmat0702(vals, dvals), Cmat0703(vals, dvals), Cmat0704(vals, dvals), Cmat0705(vals, dvals), Cmat0706(vals, dvals), Cmat0707(vals, dvals), Cmat0708(vals, dvals), Cmat0709(vals, dvals), Cmat0710(vals, dvals), Cmat0711(vals, dvals), Cmat0712(vals, dvals), Cmat0713(vals, dvals), Cmat0714(vals, dvals), Cmat0715(vals, dvals), Cmat0716(vals, dvals), Cmat0717(vals, dvals), Cmat0718(vals, dvals), Cmat0801(vals, dvals), Cmat0802(vals, dvals), Cmat0803(vals, dvals), Cmat0804(vals, dvals), Cmat0805(vals, dvals), Cmat0806(vals, dvals), Cmat0807(vals, dvals), Cmat0808(vals, dvals), Cmat0809(vals, dvals), Cmat0810(vals, dvals), Cmat0811(vals, dvals), Cmat0812(vals, dvals), Cmat0813(vals, dvals), Cmat0814(vals, dvals), Cmat0815(vals, dvals), Cmat0816(vals, dvals), Cmat0817(vals, dvals), Cmat0818(vals, dvals), Cmat0901(vals, dvals), Cmat0902(vals, dvals), Cmat0903(vals, dvals), Cmat0904(vals, dvals), Cmat0905(vals, dvals), Cmat0906(vals, dvals), Cmat0907(vals, dvals), Cmat0908(vals, dvals), Cmat0909(vals, dvals), Cmat0910(vals, dvals), Cmat0911(vals, dvals), Cmat0912(vals, dvals), Cmat0913(vals, dvals), Cmat0914(vals, dvals), Cmat0915(vals, dvals), Cmat0916(vals, dvals), Cmat0917(vals, dvals), Cmat0918(vals, dvals), Cmat1001(vals, dvals), Cmat1002(vals, dvals), Cmat1003(vals, dvals), Cmat1004(vals, dvals), Cmat1005(vals, dvals), Cmat1006(vals, dvals), Cmat1007(vals, dvals), Cmat1008(vals, dvals), Cmat1009(vals, dvals), Cmat1010(vals, dvals), Cmat1011(vals, dvals), Cmat1012(vals, dvals), Cmat1013(vals, dvals), Cmat1014(vals, dvals), Cmat1015(vals, dvals), Cmat1016(vals, dvals), Cmat1017(vals, dvals), Cmat1018(vals, dvals), Cmat1101(vals, dvals), Cmat1102(vals, dvals), Cmat1103(vals, dvals), Cmat1104(vals, dvals), Cmat1105(vals, dvals), Cmat1106(vals, dvals), Cmat1107(vals, dvals), Cmat1108(vals, dvals), Cmat1109(vals, dvals), Cmat1110(vals, dvals), Cmat1111(vals, dvals), Cmat1112(vals, dvals), Cmat1113(vals, dvals), Cmat1114(vals, dvals), Cmat1115(vals, dvals), Cmat1116(vals, dvals), Cmat1117(vals, dvals), Cmat1118(vals, dvals), Cmat1201(vals, dvals), Cmat1202(vals, dvals), Cmat1203(vals, dvals), Cmat1204(vals, dvals), Cmat1205(vals, dvals), Cmat1206(vals, dvals), Cmat1207(vals, dvals), Cmat1208(vals, dvals), Cmat1209(vals, dvals), Cmat1210(vals, dvals), Cmat1211(vals, dvals), Cmat1212(vals, dvals), Cmat1213(vals, dvals), Cmat1214(vals, dvals), Cmat1215(vals, dvals), Cmat1216(vals, dvals), Cmat1217(vals, dvals), Cmat1218(vals, dvals), Cmat1301(vals, dvals), Cmat1302(vals, dvals), Cmat1303(vals, dvals), Cmat1304(vals, dvals), Cmat1305(vals, dvals), Cmat1306(vals, dvals), Cmat1307(vals, dvals), Cmat1308(vals, dvals), Cmat1309(vals, dvals), Cmat1310(vals, dvals), Cmat1311(vals, dvals), Cmat1312(vals, dvals), Cmat1313(vals, dvals), Cmat1314(vals, dvals), Cmat1315(vals, dvals), Cmat1316(vals, dvals), Cmat1317(vals, dvals), Cmat1318(vals, dvals), Cmat1401(vals, dvals), Cmat1402(vals, dvals), Cmat1403(vals, dvals), Cmat1404(vals, dvals), Cmat1405(vals, dvals), Cmat1406(vals, dvals), Cmat1407(vals, dvals), Cmat1408(vals, dvals), Cmat1409(vals, dvals), Cmat1410(vals, dvals), Cmat1411(vals, dvals), Cmat1412(vals, dvals), Cmat1413(vals, dvals), Cmat1414(vals, dvals), Cmat1415(vals, dvals), Cmat1416(vals, dvals), Cmat1417(vals, dvals), Cmat1418(vals, dvals), Cmat1501(vals, dvals), Cmat1502(vals, dvals), Cmat1503(vals, dvals), Cmat1504(vals, dvals), Cmat1505(vals, dvals), Cmat1506(vals, dvals), Cmat1507(vals, dvals), Cmat1508(vals, dvals), Cmat1509(vals, dvals), Cmat1510(vals, dvals), Cmat1511(vals, dvals), Cmat1512(vals, dvals), Cmat1513(vals, dvals), Cmat1514(vals, dvals), Cmat1515(vals, dvals), Cmat1516(vals, dvals), Cmat1517(vals, dvals), Cmat1518(vals, dvals), Cmat1601(vals, dvals), Cmat1602(vals, dvals), Cmat1603(vals, dvals), Cmat1604(vals, dvals), Cmat1605(vals, dvals), Cmat1606(vals, dvals), Cmat1607(vals, dvals), Cmat1608(vals, dvals), Cmat1609(vals, dvals), Cmat1610(vals, dvals), Cmat1611(vals, dvals), Cmat1612(vals, dvals), Cmat1613(vals, dvals), Cmat1614(vals, dvals), Cmat1615(vals, dvals), Cmat1616(vals, dvals), Cmat1617(vals, dvals), Cmat1618(vals, dvals), Cmat1701(vals, dvals), Cmat1702(vals, dvals), Cmat1703(vals, dvals), Cmat1704(vals, dvals), Cmat1705(vals, dvals), Cmat1706(vals, dvals), Cmat1707(vals, dvals), Cmat1708(vals, dvals), Cmat1709(vals, dvals), Cmat1710(vals, dvals), Cmat1711(vals, dvals), Cmat1712(vals, dvals), Cmat1713(vals, dvals), Cmat1714(vals, dvals), Cmat1715(vals, dvals), Cmat1716(vals, dvals), Cmat1717(vals, dvals), Cmat1718(vals, dvals), Cmat1801(vals, dvals), Cmat1802(vals, dvals), Cmat1803(vals, dvals), Cmat1804(vals, dvals), Cmat1805(vals, dvals), Cmat1806(vals, dvals), Cmat1807(vals, dvals), Cmat1808(vals, dvals), Cmat1809(vals, dvals), Cmat1810(vals, dvals), Cmat1811(vals, dvals), Cmat1812(vals, dvals), Cmat1813(vals, dvals), Cmat1814(vals, dvals), Cmat1815(vals, dvals), Cmat1816(vals, dvals), Cmat1817(vals, dvals), Cmat1818(vals, dvals);
return Cmat;
}


// Gravity Vector
VectorXd Gvec(VectorXd vals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
VectorXd Gval(coords);
Gval << `Gexpressions1`;
return Gval;
}

// Jetaq matrix
MatrixXd Jetaqmat(VectorXd vals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd Jetaqval(passive, coords);
Jetaqval << `Jetaqexpressions1`;
return Jetaqval;
}

// dJetaq matrix
MatrixXd dJetaqmat(VectorXd vals, VectorXd dvals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17), dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
	ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
	dl6=dvals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd dJetaqval(passive,coords);
dJetaqval << `dJetaqexpressions1`;
return dJetaqval;
}

// Jetath matrix
MatrixXd Jetathmat(VectorXd vals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd Jetathval(passive, active);
Jetathval << `Jetathexpressions1`;
return Jetathval;
}

// Jetaph matrix
MatrixXd Jetaphmat(VectorXd vals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd Jetaphval(passive, passive);
Jetaphval << `Jetaphexpressions1`;
return Jetaphval;
}

// dJetath matrix
MatrixXd dJetathmat(VectorXd vals, VectorXd dvals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17), dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
	ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
	dl6=dvals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd dJetathval(passive,active);
dJetathval << `dJetathexpressions1`;
return dJetathval;
}

// dJetaph matrix
MatrixXd dJetaphmat(VectorXd vals, VectorXd dvals){
	double p1=vals(0), p2=vals(1), p3=vals(2), p4=vals(3), p5=vals(4), p6=vals(5),s1=vals(6), s2=vals(7), s3=vals(8), s4=vals(9), s5=vals(10), \
	s6=vals(11), l1=vals(12), l2=vals(13), l3=vals(14), l4=vals(15), l5=vals(16), \
	l6=vals(17), dp1=dvals(0), dp2=dvals(1), dp3=dvals(2), dp4=dvals(3), dp5=dvals(4), dp6=dvals(5),ds1=dvals(6), ds2=dvals(7), ds3=dvals(8), ds4=dvals(9), ds5=dvals(10), \
	ds6=dvals(11), dl1=dvals(12), dl2=dvals(13), dl3=dvals(14), dl4=dvals(15), dl5=dvals(16), \
	dl6=dvals(17);
	double cs1=cos(s1), cs2=cos(s2), cs3=cos(s3), cs4=cos(s4), cs5=cos(s5), \
cs6=cos(s6), ss1=sin(s1), ss2=sin(s2), ss3=sin(s3), ss4=sin(s4), ss5=sin(s5), \
ss6=sin(s6), sp1=sin(p1), sp2=sin(p2), sp3=sin(p3), sp4=sin(p4), sp5=sin(p5), \
sp6=sin(p6), cp1=cos(p1), cp2=cos(p2), cp3=cos(p3), cp4=cos(p4), cp5=cos(p5), \
cp6=cos(p6);
MatrixXd dJetaphval(passive,passive);
dJetaphval << `dJetaphexpressions1`;
return dJetaphval;
}