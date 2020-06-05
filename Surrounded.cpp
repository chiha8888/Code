#include<bits/stdc++.h>
using namespace std;


int main(){
	double x1,y1,r1;
	double x2,y2,r2;
	double dis;
	double answer;
	cin>>x1>>y1>>r1;		
	cin>>x2>>y2>>r2;
	dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(dis<r1-r2)
		printf("%.15lf\n",(r1-dis-r2)/2.0);
	else if(dis<r2-r1)
		printf("%.15lf\n",(r2-dis-r1)/2.0);
	else if(dis>r1+r2)
		printf("%.15lf\n",(dis-r1-r2)/2.0);
	else 
		printf("%.15lf\n",0.0);
	return 0;
} 
