#include <iostream>
#include <limits>

using namespace std;

#define MAX_INT 2147483646


int factors[256];

int* factor(int number){
  int c=0;
  int i=2;
  while(number>=2){
    if(number % i == 0){
      factors[c] = i;
      c++;
      number /= i;
      i = 2;
      continue;
    }
    i++;
  }
  return factors;
}

void print_array(int* arr){
  int j=0;
  while(arr[j] > 0){
    cout << arr[j];
    if(arr[++j] > 0) cout << ", ";
  }
  cout << endl;
  return;
}

int main(){
  int n;
  cout << "Enter a number between 2 and 2^31 to prime factorize:\n";
  do{
	cin.clear();
	cin >> n;		
	if(cin.fail()){
		cout << "Please enter a number.\n";
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
	}
  }while(n > MAX_INT || n < 2);
  cout << "The prime factors of " << n << " are:\n";
  print_array(factor(n));
  return 0;
}

