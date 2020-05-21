#include<bits/stdc++.h>
using namespace std;

int h,w ,K;
char grid[11][1010];
int tmpg[11][1010];
int main(){
    
    cin>>h>>w>>K;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
        }
    }
   
   int cnt=1<<30,tmp=0,x[11],chk,lst;
   for(int i=(1<<(h-1)); i<(1<<h);i++){
        tmp=0;
        for(int j=0;j<(h-1);j++)
            tmp+=(!!(i&(1<<j)));
        for(int j=0;j<w;j++){
            lst=0;
            for(int k=0;k<h;k++){
                tmpg[k][j]=0;
                if(i&(1<<k)){
                    for(int l=lst;l<=k;l++){
                        tmpg[k][j]+=(grid[l][j]-'0');
                    }
                    if(tmpg[k][j]>K){
                        tmp = 1<<30;
                        break;
                    }
                    lst=k+1;
                }
            }
            if(tmp==(1<<30))
                break;
        }
        if(tmp==(1<<30))
            continue;
        
        for(int k=0;k<h;++k)x[k]=0;

        for(int j=0;j<w;j++){
            for(int k=0;k<h;k++){
                if(i&(1<<k)){
                    x[k]+=tmpg[k][j];
                    if(x[k]>K){
                        tmp++;
                        for(int l=0;l<h;l++)
                            x[l]=tmpg[l][j];
                        break;
                    }
                }
            }
        }
        cnt= min(tmp,cnt);

   }
    cout<<cnt<<endl;
    return 0;
}
