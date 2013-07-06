
#include <vector>
#include <iostream>


template< typename T >
class Less_than {
public:

   Less_than(const T & v ) : val { v } {};

   bool operator()(const T & x ) {
      return x < val;
   }

private:
   T val;
};


template < typename Container, typename P >
int count( const Container & c, P p ) {


   int cnt = 0;
   for( auto x : c ) {
     if( p(x) ) {
       ++cnt;
       }
    }
   return cnt;
}


int main() {

  std::vector<double> v { 1,2,3,4,5,6,7,8,9 };

  const double th = 5;

  Less_than<double> lt(th);

  int k1 = count(v, lt );

  std::cout << "There are " << k1 << " elements";
  std::cout << " that are less than " << th << std::endl;

  int k2 = count(v, [&](double a) { return a < th; } );

  std::cout << "There are " << k2 << " elements";
  std::cout << " that are less than " << th << std::endl;

  return 0;
}