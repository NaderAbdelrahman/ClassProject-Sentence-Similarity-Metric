#include "EditDistance.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;



void Feeder(string input_file1, string input_file2)
{
  string tmp;
  float max_ST_= 0, max_TS_= 0;
  ifstream file_1_(input_file1);
  ifstream file_2_(input_file2);
  if(!file_1_.is_open()){cout << "FILE 1 ISSUE" << endl;}
  if(!file_2_.is_open()){cout << "FILE 2 ISSUE" << endl;}
  vector<string> file_1_vector_, file_2_vector_;
  string file_1_sentence_1_, file_2_sentence_1_, file_1_sentence_2_, file_2_sentence_2_, word;
  // vector<string> file_1_sentence_1_vector_, file_1_sentence_2_vector_, file_2_sentence_1_vector_, file_2_sentence_2_vector_;
  // Dump files into vectors
  while(getline(file_1_, tmp))
  {
    file_1_vector_.push_back(tmp);
  }
  while(getline(file_2_, tmp))
  {
    file_2_vector_.push_back(tmp);
  }
  file_1_.close();
  file_2_.close();
  
  for(int x = 0; x < file_1_vector_.size(); ++x)
  {
    file_1_sentence_1_ = file_1_vector_[x];
    file_2_sentence_1_ = file_2_vector_[x];
    for(int k = x + 1; k < file_1_vector_.size(); ++k)
    {
       vector<string> file_1_sentence_1_vector_, file_1_sentence_2_vector_, file_2_sentence_1_vector_, file_2_sentence_2_vector_;
 
      file_1_sentence_2_ = file_1_vector_[k];
      file_2_sentence_2_ = file_2_vector_[k];
   
      istringstream s11(file_1_sentence_1_);
      istringstream s21(file_2_sentence_1_);
      istringstream s12(file_1_sentence_2_);
      istringstream s22(file_2_sentence_2_);
      string word;
      // Tokenize sentences by word, in their own respective vector
      while(getline(s11, word, ' '))
      {
        file_1_sentence_1_vector_.push_back(word);
      }
      while(getline(s21, word, ' '))
      {
        file_2_sentence_1_vector_.push_back(word);
      }
      while(getline(s12, word, ' '))
      {
        file_1_sentence_2_vector_.push_back(word);
      }
      while(getline(s22, word, ' '))
      {
        file_2_sentence_2_vector_.push_back(word);
      }

      float file1ED = 0, file2ED = 0, floatTMP;
      EditDistance EDObj1, EDObj2;
      file1ED = EDObj1.ED(file_1_sentence_1_vector_, file_1_sentence_1_vector_.size(), file_1_sentence_2_vector_, file_1_sentence_2_vector_.size());
	  file2ED = EDObj2.ED(file_2_sentence_1_vector_, file_2_sentence_1_vector_.size(), file_2_sentence_2_vector_, file_2_sentence_2_vector_.size());
      if(file2ED == 0)
      {
        file2ED = 1;
      }
      else if(file1ED == 0)
      {
        file1ED = 1;
      }else{
        floatTMP = (file1ED)/(file2ED);
      }
      if(floatTMP > max_ST_)
      {
        max_ST_ = floatTMP;
      }
      if(floatTMP > max_TS_)
      {
        max_TS_ = floatTMP;
      }
    }
  }
  cout << "Max Worst Stretching Factor: " << (max_TS_) * (max_ST_) << endl;



}

int main(int argc, char **argv){

 if(argc != 3){
  cout << "Incorrect Usage!" << endl << "Sample Usage:" << endl << "./ED file_name.ext file_name2.ext" << endl;
  return 0;
 }
 Feeder(argv[1], argv[2]);


  return 0;
}