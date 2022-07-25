#include <iostream>
#include <vector>
#include<tuple>
using namespace std;

bool checkFunc(tuple<int, int, int> t, vector<int> f){
    for(int i=0; i<f.size(); i++){
        if((get<0>(t) ^ i) + (get<1>(t) ^ i) + (get<2>(t) ^ i) != f[i]){
            return false;
        }
    }
    return true;
}

int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test>0){
	    int a, b, c;
	    int N;
	    cin>>N;
	    vector<int> f;
	    for(int i=0; i<N+1; i++){
	        int d;
	        cin>>d;
	        f.push_back(d);
	    }
	    bool flag = true;
        tuple<int, int, int> t;
	    // for(int l=0; l<f.size() && flag; l++){
	    for(int i=0; i<=N && flag; i++){
	        for(int j=0; j<=N && flag; j++){
	            for(int k=0; k<=N && flag; k++){
	                if((i^0) + (j^0) + (k^0) == f[0]){
	                    // a = i; b = j; c = k;
                        t = make_tuple(i,j,k);
                        if(checkFunc(t, f)){
                            flag = false;
                            break;
                        }
	                }
	            }
	        }
	    }
	// }
        // cout<<a<<" "<<b<<" "<<c<<endl;
        cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
        test--;
	}
	return 0;
}
