#include<bits/stdc++.h>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void func(double* p, const int N, const double dx, const double xmin){
  double x;
  for(int i=0; i<N; i++){
    x = i*dx + xmin;
    p[i] = exp(-x*x);
  }
    
}

void deriv(double* p, const int N, const double dx){
 double a;
 double b=0;
  for(int i=0; i<N-1;i++){
    a=p[i];
    p[i] = (p[i+1]- b)/(2*dx);
    b=a;
  }
  p[N-1] = (0 - b)/(2*dx);
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  func(p,N,dx,xmin);  // call to function which fills array p here
  
  
  deriv(p,N,dx); // call to function which calculates the derivative
  
  
  print(p,N,dx,xmin);

  return 0;
}
