#include<bits/stdc++.h>
using namespace std;
int target;
int dis;
int ques_num;

double lev(double a){
	double re=1;
	for(int i=1;i<=a;i++){
		re*=i;
	}
	return re;
}
int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		if(s[i]=='+')
			target++;
		else if(s[i]=='-')
			target--;
	}
	getline(cin,s);
	int tmp=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='+')
			tmp++;
		else if(s[i]=='-')
			tmp--;
		else if(s[i]=='?')
			ques_num++;
	}
	dis=target-tmp;
	if(abs(dis)>ques_num)
		printf("%.12lf",0.0);
	else{
		//	(ques_num!/black!white!)/2^ques_num
		if((ques_num-dis)%2!=0)
			printf("%.12lf",0.0);
		else{
			double black=(ques_num-dis)/2.0;
			double white=dis+(ques_num-dis)/2.0;
			double ans=(lev(ques_num)/(lev(black)*lev(white)))/(double)(1<<ques_num);
			printf("%.12lf\n",ans);
		}
	} 
	
	return 0;
} 
