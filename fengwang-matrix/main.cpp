#include "matrix.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string read_input_data() {
  std::ifstream f;
  f.open("/input.txt");
  std::stringstream ss;
  ss << f.rdbuf();
  return ss.str();
}

//void deserialize(const string& input, double& rows, double& cols, double *data) {

//}

int main() {
  cout << "SVD Image Program\n";

  cout << "indata := " << read_input_data() << endl;

  cout << "test-var := hello\n";
  cout << "some-num := 1234567890\n";

  feng::matrix<double> m{ 12, 34 };

  // adding noise
  auto const[r, c] = m.shape();
  m += feng::rand<double>( r, c );

  // record noisy matrix
  m.save_as_bmp( "./matrix/images/0001_singular_value_decomposition.bmp", "gray" );

  // execute svd
  auto const& svd = feng::singular_value_decomposition( m );

  // extracted svd result matrices, u, v w
  auto const& [u, v, w] = (*svd);
  // try to reconstruct matrix using  u * v * w'
  auto const& m_ = u * v * (w.transpose());
  // record reconstructed matrix
  m_.save_as_bmp( "./images/0002_singular_value_decomposition.bmp", "gray" );
}
