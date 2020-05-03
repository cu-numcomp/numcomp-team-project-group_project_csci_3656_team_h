#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
  feng::matrix<double> a;

  // bug: this will break if matrix has dtype 'int'
  a.load_npy("/program_io/input.npy");

  auto const [r, c] = a.shape();

  auto begin = chrono::high_resolution_clock::now();
  auto const& svd = feng::singular_value_decomposition(a);
  auto elapsed = chrono::high_resolution_clock::now() - begin;

  //Extracting u,s,v and A prime from svd
  auto const& [u, s, v] = *svd;

  auto b = chrono::high_resolution_clock::now();
  auto const& a_prime = u * s * v.transpose();
  auto a_elapsed = chrono::high_resolution_clock::now() - b;

  u.save_as_bmp("/program_io/U.bmp", "gray");
  s.save_as_bmp("/program_io/S.bmp", "gray");
  v.save_as_bmp("/program_io/V.bmp", "gray");
  a_prime.save_as_bmp("/program_io/A_prime.bmp", "gray");

  // make sure this is at the very end
  cout << "!!BEGIN-STATS!!" << endl;

  cout << "matrix-rows := " << r << endl;
  cout << "matrix-cols := " << c << endl;
  // cout << "some-num := 1234567890" << endl;

  long long microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();

  long long aprimemicro = chrono::duration_cast<chrono::microseconds>(a_elapsed).count();

  cout << "performance-svd-us := " << fixed << setprecision(4) << microseconds << endl;
  cout << "performance-aprime := " << fixed << setprecision(4) << aprimemicro << endl;

  return 0;
}
