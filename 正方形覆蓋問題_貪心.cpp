#include<bits/stdc++.h>
using namespace std;
int T;
//first
int n;
int x[100005];
int y[100005];
int lrud1[2][2];	//[1,1]:l,[1,2]:r,[2,1]:u,[2,2]:d
//second
int m;
int xx[100005];
int yy[100005];
int lrud2[2][2];
//third
int g;
int xxx[100005];
int yyy[100005];
int lrud3[2][2];
int INF=1000000000;

bool check(int r){
	lrud1[1][1]=INF;//��	
	lrud1[1][2]=-INF;//�k
	lrud1[2][1]=-INF;//�W
	lrud1[2][2]=INF;//�U
	 
	for(int i=1;i<=n;i++){	//�W�U���k��� 
		lrud1[1][1]=min(lrud1[1][1],x[i]);
		lrud1[1][2]=max(lrud1[1][2],x[i]);
		lrud1[2][1]=max(lrud1[2][1],y[i]);
		lrud1[2][2]=min(lrud1[2][2],y[i]);
	}
	//4*(n+4*n)
	//first
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){	
			m=0; 
			for(int k=1;k<=n;k++){	//�˵��d�s�� 
				if(abs(x[k]-lrud1[1][i])>r||abs(y[k]-lrud1[2][j])>r){	//�٦s�b m ���I 
					xx[++m]=x[k];
					yy[m]=y[k];
				} 
			}
			
			if(m==0)
				return true;
			
			lrud2[1][1]=INF;//��	
			lrud2[1][2]=-INF;//�k
			lrud2[2][1]=-INF;//�W
			lrud2[2][2]=INF;//�U
			for(int k=1;k<=m;k++){	//�W�U���k��� 
				lrud2[1][1]=min(lrud2[1][1],xx[k]);
				lrud2[1][2]=max(lrud2[1][2],xx[k]);
				lrud2[2][1]=max(lrud2[2][1],yy[k]);
				lrud2[2][2]=min(lrud2[2][2],yy[k]);
			}
			//second
			for(int ii=1;ii<=2;ii++){
				for(int jj=1;jj<=2;jj++){
					g=0;
					for(int kk=1;kk<=m;kk++){	//�٦s�� ���I 
						if(abs(xx[kk]-lrud2[1][ii])>r||abs(yy[kk]-lrud2[2][jj])>r){
							xxx[++g]=xx[kk];
							yyy[g]=yy[kk];
						}
					}
					
					if(g==0)
						return true;
						
					lrud3[1][1]=INF;//��	
					lrud3[1][2]=-INF;//�k
					lrud3[2][1]=-INF;//�W
					lrud3[2][2]=INF;//�U
					for(int kk=1;kk<=g;kk++){	//�W�U���k��� 
						lrud3[1][1]=min(lrud3[1][1],xxx[kk]);
						lrud3[1][2]=max(lrud3[1][2],xxx[kk]);
						lrud3[2][1]=max(lrud3[2][1],yyy[kk]);
						lrud3[2][2]=min(lrud3[2][2],yyy[kk]);
					}
					
					if(abs(lrud3[1][1]-lrud3[1][2])<=r&&abs(lrud3[2][1]-lrud3[2][2])<=r)
						return true; 	
				}
			}
			
			
		}
		
	}
	
	return false;
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x[i],&y[i]);
		}		
		int r=2000000000;	// (  ]
		int l=-1;
		int middle;
		while(r>l+1){
			middle=(r-l)/2+l;
			if(check(middle))
				r=middle;
			else
				l=middle;
		}
		cout<<r<<endl;	
	}	
	
	return 0;
} 
