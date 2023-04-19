//uva11624
#include<bits/stdc++.h>
using namespace std;
char mmap[1001][1001];
int re[1001][1001];
int re_2[1001][1001];
int gor[4]={0,1,0,-1};
int goc[4]={1,0,-1,0};
struct Point{
	int r;
	int c;
	int dis;
};
deque<Point>myq;
bool bound(int row,int col,int nr,int nc){
	if((row>0)&&(row<=nr)&&(col>0)&&(col<=nc))return 1;
	else return 0;
}
int main(){
	bool ans;
	int r,c,sr,sc,tmpr,tmpc,num,t;
	Point myp,nextp,myp_2,nextp_2;
	cin>>t;
	while(t--){
		num=100000000;
		ans=false;
		memset(re,0,sizeof(re));
		memset(re_2,0,sizeof(re_2));
		myq.clear();
		cin>>r>>c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>mmap[i][j];
				if(mmap[i][j]=='F'){
					sr=i;
					sc=j;
				}
				if(mmap[i][j]=='J'){
					tmpr=i;
					tmpc=j;
				}
			}
		}
		myp.r=sr;
		myp.c=sc;
		myp.dis=1;
		re[myp.r][myp.c]=1;
		myq.push_back(myp);
		while(myq.size()>0){
			nextp=myq.front();
			myq.pop_front();
			for(int i=0;i<4;i++){
				if(bound(nextp.r+gor[i],nextp.c+goc[i],r,c)&&
				(mmap[nextp.r+gor[i]][nextp.c+goc[i]]=='.')&&
				(re[nextp.r+gor[i]][nextp.c+goc[i]]==0)){
					re[nextp.r+gor[i]][nextp.c+goc[i]]=nextp.dis+1;
					myp.r=nextp.r+gor[i];
					myp.c=nextp.c+goc[i];
					myp.dis=nextp.dis+1;
					myq.push_back(myp);
				}
			}
		}
		/*for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cout<<re[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";*/
		sr=tmpr;
		sc=tmpc;
		myp_2.r=sr;
		myp_2.c=sc;
		myp_2.dis=1;
		re_2[myp_2.r][myp_2.c]=1;
		myq.push_back(myp_2);
		while(myq.size()>0){
			nextp_2=myq.front();
			myq.pop_front();
			for(int i=0;i<4;i++){
				if(bound(nextp_2.r+gor[i],nextp_2.c+goc[i],r,c)&&
				(mmap[nextp_2.r+gor[i]][nextp_2.c+goc[i]]!='#')&&
				(re_2[nextp_2.r+gor[i]][nextp_2.c+goc[i]]==0)&&
				((nextp_2.dis+1)<re[nextp_2.r+gor[i]][nextp_2.c+goc[i]] || re[nextp_2.r+gor[i]][nextp_2.c+goc[i]]==0)){
					re_2[nextp_2.r+gor[i]][nextp_2.c+goc[i]]=nextp_2.dis+1;
					myp_2.r=nextp_2.r+gor[i];
					myp_2.c=nextp_2.c+goc[i];
					myp_2.dis=nextp_2.dis+1;
					myq.push_back(myp_2);
					//cout<<"test"<<re[nextp_2.r+gor[i]][nextp_2.c+goc[i]]<<"\n";
				}
			}
		}
		/*for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cout<<re_2[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		//11~1c
		for(int i=1;i<=c;i++){
			if(re_2[1][i]!=0 && re_2[1][i]<num){
				ans=true;
				num=re_2[1][i];
			}
		}
		//r1~rc
		for(int i=1;i<=c;i++){
			if(re_2[r][i]!=0 && re_2[r][i]<num){
				ans=true;
				num=re_2[r][i];
			}
		}
		//11~r1
		for(int i=1;i<=r;i++){
			if(re_2[i][1]!=0 && re_2[i][1]<num){
				ans=true;
				num=re_2[i][1];
			}
		}
		//1c~rc
		for(int i=1;i<=r;i++){
			if(re_2[i][c]!=0 && re_2[i][c]<num){
				ans=true;
				num=re_2[i][c];
			}
		}
		//cout<<ans<<"\n";
		if(num!=100000000)ans=true;
		if(ans){
			cout<<num<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
}
