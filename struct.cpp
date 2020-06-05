#include<iostream>
using namespace std;

struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){
	}
};

point operator + (const point& a,const point& b){
	return point(a.x+b.x,a.y+b.y);
}

ostream& operator << (ostream& out,const point& p){
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}

int main(){
	point p1(1,2);
	point p2=5;
	cout<<p1+p2<<endl;
	
	return 0;
} 
