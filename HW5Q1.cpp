#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// primes protoype
void primes(int n);

//top range value for the container size.
const int MAXNUM=1000;

int main(){

// function call- finds all primes from 0 to MAXNUM
  primes(MAXNUM);

  return 0;
}


void primes(int primeNum){
  //creates vector and initializes each value to true (not 0 or 1)
  vector<int> primeList (primeNum+1, true);
    primeList[0] = false;
    primeList[1] = false;

  int root= sqrt(primeNum);

  // loops through each value and makes false each value that is not prime
  for (int i=2; i<=root; i++){
    if(primeList[i]){
      for(int j= i*i; j<=primeNum; j+= i){
        primeList[j] = false;
      }
    }
  }
  //prints the prime list (each true value)
  for (int i=0; i<=primeNum;i++){
    if (primeList[i]) cout<<i<<" ";
      }
  cout<<endl;
    }
