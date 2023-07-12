#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

double h=0.0001;
double xo=0;
double xf=3.14*10;
double yi=0;
double ui=1;




using namespace std;

double g(double x, double y, double z){

	double df=-y*x;
	
	//double df=1;
	
	return df;
	
}


double f(double x, double y, double z){

	double df=z;
	
	//double df=1;
	
	return df;
	
}


vector <double> xaxis(){

	vector <double> x;

	for(double u=xo; u<xf+h; u=u+h){
	
		//cout<<u<<endl;
		x.push_back(u);
	
	}

	return x;
}

vector <double> yn(double yo, double zo){

	vector <double> x=xaxis();
	vector <double> y={yo};
	vector <double> z={zo};
	
	ofstream file;
	file.open("results.txt");	
	
	for(int i=0; i<size(x); i++){

		double k0=h*f(x[i],y[i],z[i]);
		double l0=h*g(x[i],y[i],z[i]);
		double k1=h*f(x[i]+(1/2)*h,y[i]+(1/2)*k0,z[i]+(1/2)*l0);
		double l1=h*g(x[i]+(1/2)*h,y[i]+(1/2)*k0,z[i]+(1/2)*l0);
		double k2=h*f(x[i]+(1/2)*h,y[i]+(1/2)*k1,z[i]+(1/2)*l1);
		double l2=h*g(x[i]+(1/2)*h,y[i]+(1/2)*k1,z[i]+(1/2)*l1);
		double k3=h*f(x[i]+h,y[i]+k2,z[i]+l2);
		double l3=h*g(x[i]+h,y[i]+k2,z[i]+l2);
		double yf=y[i]+(k0+2*k1+2*k2+k3)/6;
		double zf=z[i]+(l0+2*l1+2*l2+l3)/6;
		
		z.push_back(zf);
		y.push_back(yf);
		
		cout<<y[i]<<endl;
		file<<y[i]<<endl;

	}
	
	file.close();
	
	return y;

}

	
int main(){

	yn(yi, ui);

}
