/*
  Author:
  cite:
  pledge
 */
#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a, int b) {
 if (b == 0);
    return (b, a % b);
}
bool isPrime(int a){
     bool prime = true;
    for (int i=2;i<a;i++){
        if (a % i == 0){
            prime = false;
            break;
        }
    }
    return prime;

}
int countPrimes(int a, int b){
    int count = 0;
    for (int i = a; i <=b; i++){
        if(isPrime(i)==true){
          count=count + 1;
        }
    }
    return count;
}
void collatz(int a){
while ( a != 1) {
  if ( a % 2 == 0) {
     a = a/2;
  }else {
   a = a * 3 + 1;
}
 cout<<a<<" ";
}

}

double mean(double x[], int n){
    double sum = x[0];
    for(int i = 1; i < n; i++){
        sum = sum + x[i];
    }
    return sum/n;

}
int prod(int x[], int n){
    int product = x[0];
    for (int i =1; i < n; i++){
        product = product * x[i];
    }
    return product;
}
void demean(double x[], int n){
    double closest = x[0];
  double setmean = mean(x,n);
   for (int i = 1; i < n; i++){
       if(abs(x[i]-setmean) < abs(closest-setmean)){
           closest = x[i];
       }
   }
   for (int j = 0; j < n; j++){
       x[j]= x[j]-closest;
   }
}
void range_reverse(int x[], int n, int a, int b) {
        while (a < b){
            int j = x[a];
            x[a] = x[b];
            x[b] = j;
            a = a+1;
            b = b-1;
        }
}
double hypot(double a, double b) {
    double c = sqrt((a * a) + (b * b));
    return c;
}
double mean(double a, double b) {
        double c = (a + b)/2;
        return c;
}
bool pythagTriple(double a, double b) {
         double c = sqrt((a * a) + (b * b));
        long long int num = c;

if (c == num) {
  return true;
} else {
return false;
}

}
double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
   double l1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
   double l2 = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
    double l3 = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));

    double s = (l1 + l2 + l3)/2;
    double area = sqrt(s * (s - l1) * (s - l2) * (s - l3));
    return area;
}



int main() {

    
    cout << "gcd(12, 18)=" << gcd(12, 18) << '\n';
    cout << "gcd(1025, 3025)=" << gcd(1025, 3025) << '\n';
    cout << "isPrime(5)=" << isPrime(5) << '\n';
    cout << "isPrime(9)=" << isPrime(9) << '\n';
    cout << "isPrime(1001)=" << isPrime(1001) << '\n';
    cout << "isPrime(2601)=" << isPrime(2601) << '\n';
    cout << "isPrime(1013)=" << isPrime(1013) << '\n';

    cout << "countPrimes(1,100): " << countPrimes(1, 100) << '\n';
    cout << "countPrimes(1,10000): " << countPrimes(1, 10000) << '\n';

    collatz(5); // should print out 5 16 8 4 2 1
    collatz(40); // should print out 40 20 10 5 16 8 4 2 1
    collatz(17);

    double x[] = {10, 20, 30, 40, 50, 60};
    constexpr int n = sizeof(x)/sizeof(double);
    cout << endl;
    cout << mean(x, n) << '\n'; // should print 35

    double y[] = {1.0, 2.0, 3.0, 4.0};
    cout << mean(y, sizeof(y)/sizeof(double)) << '\n'; // should print 2.5

    int a[] = {3, 4, 1, 2, -2};
    cout << prod(a, sizeof(a)/sizeof(int)) << '\n';

    int b[] = {2, 4, 8, -2, -4};
    cout << prod(b, sizeof(b)/sizeof(int)) << '\n';

    demean(x, n); // should subtract the mean from each element
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << '\n';

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    range_reverse(c, 9, 2, 4);

    //you should print out the array c
    for (int i = 0; i < sizeof(c)/sizeof(int); i++)
        cout << c[i] << ' '; // should print 1 2 5 4 3 6 7 8 9
    cout << '\n';

    cout << "hypot(3,4)=" << hypot(3, 4) << '\n'; // should print 5
    cout << "hypot(4,5)=" << hypot(4, 5) << '\n';
    cout << "mean(3.0,sqrt(8.0)) = " << mean(3.0,sqrt(8.0)) << '\n';

    cout << "mean(1,4)=" << mean(1, 4) << '\n';

    cout << "if sqrt(3**2 +4**2) is a whole number?: " << pythagTriple(3, 4)
       << endl;
    cout << "if sqrt(2**2 +3**2) is a whole number?: " << pythagTriple(2, 3)
       << endl;

    cout << areaOfTriangle(0,0, 10,0, 10,5) << '\n'; // should be approx 25
    cout << areaOfTriangle(0,0, 5,3, 2,6) << '\n';

    return 0;
}
