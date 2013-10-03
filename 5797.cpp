#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
map<string,int> mapa;
int main(){
	string vec1[]={".*","*.","*.","**","**","*.","**","**","*.",".*"};
	string vec2[]={"**","..","*.","..",".*",".*","*.","**","**","*."};
	string vec3[]={"..","..","..","..","..","..","..","..","..",".."};
	string vec4[10];
	for (int i = 0; i < 10; i++){
		vec4[i]="";
		vec4[i]+=vec1[i];
		vec4[i]+=vec2[i];
		vec4[i]+=vec3[i];
	}
	int n,k;
	char s;
	string cade;
	//freopen("5797.in","r",stdin);
	while(scanf("%d",&n)and n!=0){
		getchar();
		s=getchar();
		getchar();
		getline(cin,cade);
		if(s=='S'){
			cout<<vec1[cade[0]-'0'];
			for(int i=1;i<cade.size();i++){
				cout<<" "<<vec1[cade[i]-'0'];
			}
			cout<<endl;
			cout<<vec2[cade[0]-'0'];
			for(int i=1;i<cade.size();i++){
				cout<<" "<<vec2[cade[i]-'0'];
			}
			cout<<endl;
			cout<<vec3[cade[0]-'0'];
			for(int i=1;i<cade.size();i++){
				cout<<" "<<vec3[cade[i]-'0'];
			}
		}else{
			string cade2,cade3;
			getline(cin,cade2);
			getline(cin,cade3);
			string d="";
			for(int i=0;i<cade.size();i+=3){
				d=cade[i];
				d+=cade[i+1];
				d+=cade2[i];
				d+=cade2[i+1];
				d+=cade3[i];
				d+=cade3[i+1];
				for(int j=0;j<10;j++){
					if(d.compare(vec4[j])==0){
						cout<<j;
						break;
					}
				}
			}
		}
		cout<<endl;
	}
}