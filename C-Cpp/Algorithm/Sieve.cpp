#include <bits/stdc++.h>
using namespace std;

// Initialization
#define N 5000001
vector<int> hpf(N,1);         //stores the highest prime factor of i, i.e. hpf[i] = highest prime factor of i 
vector<int> lpf(N,1);         //stores the lowest prime factor of i, i.e. lpf[i] = lowest prime factor of i 
vector<bool> prime(N,true);   // stores true at index i if i is a prime number else false
vector<int> prime_nos;        // stores all prime numbers in inceasing order, e.g. 2,3,5,7,11,13,....... and so on

void sieve(){

    // since 0 and 1 are not prime
    prime[0]=false;
    prime[1]=false;

        for(int i=2;i<N;i++){
            if(prime[i]){
                // If prime[i] is true means there is no integer less than i which divides i,therefore it is a prime number.
                prime_nos.push_back(i); // since i is a prime number.
                hpf[i]=i; // highest prime factor of prime numbers is number itself.

                // Loop on all multiples of i and mark them as false since it is divisible by i.
                for(int j=2*i;j<N;j+=i){
                    prime[j]=false;
                
                    // hpf will be updated every time it is divisible by any i, since we want hightest factor but in case of lpf the first number which divides j will be its lowest prime factor.
                    hpf[j]=i;
                    if(lpf[j]==1) lpf[j]=i;
                }
            }
        }
}


int main()
{
    sieve();

    //To get first m prime numbers.
    int m=20;
    cout<<"First "<<m<<" prime numbers: ";
    for(int i=0;i<m;i++) cout<<prime_nos[i]<<" ";
    cout<<endl;

    // To check whether a number is prime or not
    int n=23; 
    if(prime[n]==true){
         cout<<n<<" is a prime number."<<endl;
    }
    else {
        cout<<n<<" is not a prime number."<<endl;
    }

    //To find hpf and lpf of any number.
    int x=92;
    cout<<"Highest prime factor of "<<x<<" is "<<hpf[x]<<endl;
    cout<<"Lowest prime factor of "<<x<<" is "<<lpf[x]<<endl; 

    return 0;
}