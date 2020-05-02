#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  feng::matrix<double> a;

  // bug: this will break if matrix has dtype 'int'
  a.load_npy("/program_io/input.npy");

  auto const [r, c] = a.shape();

  auto const& svd = feng::singular_value_decomposition(a);
  auto const& [u, s, v] = *svd;
  auto const& a_prime = u * s * v.transpose();

  u.save_as_bmp("/program_io/U.bmp", "gray");
  s.save_as_bmp("/program_io/S.bmp", "gray");
  v.save_as_bmp("/program_io/V.bmp", "gray");
  a_prime.save_as_bmp("/program_io/A_prime.bmp", "gray");

  // make sure this is at the very end
  cout << "!!BEGIN-STATS!!" << endl;

  cout << "matrix-rows := " << r << endl;
  cout << "matrix-cols := " << c << endl;
  cout << "some-num := 1234567890" << endl;

  return 0;
}
