/**
 * sample code from http://monoinfinito.wordpress.com/series/introduction-to-c-template-metaprogramming/
 */

#include <iostream>

template <int n, int d> struct Frak {
  static const long Num = n;
  static const long Den = d;
};

//template <int N, typename X> struct ScalarMultiplication {
//  static const long Num = N * X::Num;
//  static const long Den = N * X::Den;
//};

template <int N, typename F> struct ScalarMultiplication {
  typedef Frak < N * F::Num, N * F::Den> result;
};

int main() {
  typedef Frak <2, 3> Two_Thirds;
  typedef ScalarMultiplication <2, Two_Thirds>::result Four_Sixths;
  std::cout << Four_Sixths::Num << "/" << Four_Sixths::Den << "/n";
}
