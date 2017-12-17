#ifndef EDIT_DISTANCE_H_
#define EDIT_DISTANCE_H_

#include <vector>
#include <string>

using namespace std;

class EditDistance{

public:
  int min(int x, int y, int z);
  int ED(vector <string> str1, int m, vector <string> str2, int n);
private:
  

};

#endif // EDIT_DISTANCE_H_