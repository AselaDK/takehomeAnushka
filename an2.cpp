#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int rankify(int* A , int n, int k) { 
  
    // Rank Vector 
    float R[n] = {0};
    int value = -1;
      
    // Sweep through all elements in A for each 
    // element count the number of less than and 
    // equal elements separately in r and s. 
    for (int i = 0; i < n; i++) { 
        int r = 1, s = 1; 
          
        for (int j = 0; j < n; j++) { 
            if (j != i && A[j] < A[i]) 
                r += 1; 
                  
            if (j != i && A[j] == A[i]) 
                s += 1;      
        } 
          
        // Use formula to obtain rank 
        R[i] = r + (float)(s - 1) / (float) 2; 
      
    }

    for(int i=0; i<n; i++){
        int r = (int)R[i];
        //cout<<"\nr = "<<r;
        //cout<<"\nk = "<<k;
        
        if(r==k){
            value = A[i];
            //cout<<"\nmatched\n";
            break;
        }
    }

    return value;
  
} 

void shelfProb(){
    int N;
    int shelf[100];
    cout<<"enter no of shelves = ";
    cin>>N;
    cout<<"enter shelves' book counts =>  ";
    for(int i= 0; i<N; i++){
        int n;
        cin>>n;
        shelf[i] = n;  
    }
    
    int q;
    cout<<"enter no of queriess = ";
    cin>>q;
    
    for(int i= 0; i<q; i++){
        int n;

        cout<<"enter query = ";
        cin>>n;
        
        switch(n){
            case 1:{
                int x, k;
                cin>>x>>k;
                shelf[k-1] = x;

                //cout<<"x = ";
                if(shelf[k-1] == x){
                    cout<<"\nsuccessfully changed\n";
                }
                //cout<<"\n";
            }break;
            case 0:{
                int x, y, k;
                cin>>x>>y>>k;
                //cout<<"DRGD";
                int s = y-x+1;
                //cout<<"\n s = "<<s;
                int subshelf[s];
                int j=0;
                for(int i=x-1; i<y, j<s; i++){
                    //cout<<shelf[i]<<"001";
                    subshelf[j] = shelf[i];
                    j++;
                }

                for(int l=0; l<s; l++){
                    cout<<subshelf[l]<<"002";
                }
                
                cout<<"value with kth rank = ";
                cout<<rankify(subshelf, s, k);
                cout<<"\n";
            }break;
            default:cout<<"Invalid";
        }
    }
}


int main()
{
    int T;
    cout<<"enter T = ";
    cin>>T;
    
   for(int i = 0; i<T; i++){
       shelfProb();
   }
}
