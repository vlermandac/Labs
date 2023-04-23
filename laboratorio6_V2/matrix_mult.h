#include <iostream>
#include <vector>

using namespace std;


void read_matrix(vector<vector<int> > &M){
  for(auto &row : M)
    for(auto &element : row) cin>>element;
}

void print_matrix(const vector<vector<int> > &M){
  for(int i = 0; i < M.size(); i++){
    for(int j = 0; j < M[i].size(); j++)
      cout<<M[i][j]<<" ";
    cout<<endl;
  }
}

vector<vector<int> > standard_mm(const vector<vector<int> > &A, const vector<vector<int> > &B) {
  int n = A.size();
  int m = A[0].size();
  int k = B[0].size();

  vector<vector<int> > C(n, vector<int>(k, 0));

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < k; j++)
      for(int k = 0; k < m; k++)
        C[i][j] += A[i][k] * B[k][j];

  return C;
}

vector<vector<int> > transpose_mm(const vector<vector<int> > &A, const vector<vector<int> > &B) {
  int n = A.size();
  int m = A[0].size();
  int k = B[0].size();

  vector<vector<int> > Bt(k, vector<int>(m, 0));

  for(int i = 0; i < k; i++) 
    for(int j = 0; j < m; j++) 
      Bt[i][j] = B[j][i];

  vector<vector<int> > C(n, vector<int>(k, 0));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++){
      int dotProduct = 0;
      for(int k = 0; k < m; k++)
        dotProduct += A[i][k] * Bt[j][k];
      C[i][j] = dotProduct;
    }

  return C;
}          

vector<vector<int> > matrix_multiplication(const vector<vector<int> > &A, const vector<vector<int> > &B, string alg){
  if(alg == "transpose_mm") return transpose_mm(A, B);
  return standard_mm(A, B);
}

long long execution_time_ms(const vector<vector<int> > &A, const vector<vector<int> > &B, string alg) {
  auto start_time = std::chrono::high_resolution_clock::now();
  matrix_multiplication(A, B, alg);
  auto end_time = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

}


