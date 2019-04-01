//
// Created by guozhuoqiang on 2019-03-10.
//
#include <cstdio>
#include <cmath>

using namespace std;

double a[3];
double b[3];
double x[3];

double pi = acos(-1);

double r,r2,r3,v;
int main(){
    while (scanf("%lf %lf %lf %lf %lf %lf",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]) != EOF){
        x[0] = b[0]-a[0];
        x[1] = b[1]-a[1];
        x[2] = b[2]-a[2];
        r2 = x[0]*x[0]+x[1]*x[1]+x[2]*x[2];
        r = sqrt(r2);
        r3 = r*r2;
        v = 4*pi*r3/3;
        printf("%.3lf %.3lf\n",r,v);
    }

    return 0;
}
