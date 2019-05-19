#include<stdio.h>

void shelf();
int rankify(int subshelf[],int n,int k);

int main(){
	int T,P;
	printf("Enter no of test cases : ");
	scanf("%d",&T);
	
	for(P=1;P<=T;P++){		
		shelf();       
	}
}

void shelf(){
	int N,M,Q,I;
	        printf("Enter no of shelves : ");
	        scanf("%d",&N);
	        int shelf[N];
	        
	        for(M=0;M<N;M++){
		        scanf("%d",&shelf[M]);
           	}
           	printf("Enter no of queires : ");
           	scanf("%d",&Q);
           	
           	for(I=0;I<Q;I++){
           		int n;
           		printf("Enter query : ");
           		scanf("%d",&n);
           		         		
           		int x,y,k;
           		switch(n){
           			case 1:		
           				scanf("%d%d",&x,&k);
           				shelf[x-1]=k;
           				if(shelf[x-1]==k)
           				  printf("Successfully changed\n");
           				break;
           				
           			case 0:
           				scanf("%d%d%d",&x,&y,&k);
           				int s;
           				s=y-x+1;
           				int subshelf[s];
           				int j=0;
           				int i;
           				for(i=x-1;i<y,j<s;i++){
           					subshelf[j]=shelf[i];
           					j++;
						   }
			   		    int l;
                        printf("--------------------------------------------------> Answer is : ");
                        printf("%d\n",rankify(subshelf,s,k));
                        break;
				   }
			   }
}

int rankify(int subshelf[],int n,int k){
	float R[100] = {0};
    int value = -1;
    int i,j;
    for (i = 0; i < n; i++) { 
        int r = 1, s = 1; 
          
        for (j = 0; j < n; j++) { 
            if (j != i && subshelf[j] < subshelf[i]) 
                r += 1; 
                  
            if (j != i && subshelf[j] == subshelf[i]) 
                s += 1;      
        } 
        R[i] = r + (float)(s - 1) / (float) 2; 
    }
    
     for(i=0; i<n; i++){
        int r = (int)R[i];
         if(r==k){
            value = subshelf[i];
            break;
        }
    }
         return value;
    
}

