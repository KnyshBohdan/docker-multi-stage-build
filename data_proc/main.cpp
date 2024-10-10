#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

vector<vector<double>> load_csv(const string& filename) {
  vector<vector<double>> data;
  ifstream file(filename);
  string line;

  while (getline(file, line)) {
    stringstream lineStream(line);
    string cell;
    vector<double> row;
    while (getline(lineStream, cell, ',')) {
      row.push_back(stod(cell));
    }
    data.push_back(row);
  }

  return data;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <csv_file>" << endl;
    return 1;
  }

  string filename = argv[1];
  vector<vector<double>> data = load_csv(filename);

  MatrixXd dataMatrix = Map<Matrix<double, Dynamic, Dynamic, RowMajor>>(data[0].data(), data.size(), data[0].size());

  VectorXd colMeans = dataMatrix.colwise().mean();

  cout << "Column means:\n" << colMeans << endl;

  return 0;
}
