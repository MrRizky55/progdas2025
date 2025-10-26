#include <iostream>
#include <cmath>
using namespace std;

const float pi = 3.1416;

float distance(float,float,float,float);
float radius(float,float,float,float);
float circumference(float);
float area(float);

int main(){
float x1,x2,y1,y2,r;

cin >> x1 >> y1;
cin >> x2 >> y2;

cout << "Jarak kedua titik adalah: " << distance(x1,y1,x2,y2) << endl;
r = radius(x1,y1,x2,y2);
cout << "Radius lingkaran yang terbentuk dari kedua titik adalah: " << r << endl;
cout << "Keliling lingkaran tersebut adalah: " << circumference(r) << endl;
cout << "Luas lingkaran tersebut adalah: " << area(r) << endl;

return 0;
}

float distance(float x1,float y1,float x2,float y2){
    float d = sqrt((pow((x2-x1),2)+pow((y2-y1),2)));
    return d;
};

float radius(float xc,float yc,float xp,float yp){
    float r = distance(xc,yc,xp,yp);
    return r;
}

float circumference(float r){
    float c = 2*pi*r;
    return c;
}

float area(float r){
    float a = pi*pow(r,2);
    return a;
}