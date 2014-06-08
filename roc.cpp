// Copyright (c) 2014 vassilis@entropiece.com
// www.entropiece.com

// cppROC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "roc.hpp"

ROC::ROC(std::string filename){
  float score;
  int label;
  std::ifstream inFile(filename.c_str());

  if(!inFile) {
    std::cerr << "File "<< filename << " not found.";
  }

  // read the data from the file
  while(!inFile.eof()) {
    inFile  >>  score >> label;
    if (!inFile) break;
    this->data.push_back(std::make_pair(score,label));
  }
  getROCFromData(this->data);
}

ROC::~ROC() {
}

void ROC::writeToFile(std::string filename){
  std::ofstream outfile(filename.c_str());
  for (int i = 0; i < this->TP.size(); i++) {
    outfile  <<  FP[i] << "\t" << TP[i] << std::endl;
  }
  std::cout <<  "ROC curve points saved to file " << filename << std::endl;
}

float ROC::get95ErrorRate(){
  // TODO - Implement this
  return 1.0;
}

float ROC::getAreaUnderCurve(){
  // TODO - Implement this
  return 1.0;
}

bool compare(const std::pair<float,int>&i, const std::pair<float,int>&j){
  return i.first > j.first;
}

// Main ROC algorithm from the paper
// ROC Graphs: Notes and Practical Considerations for
// Researchers - Tom Fawcett (Algorithm 2)
// @TECHREPORT{Fawcett04rocgraphs:,
//     author = {Tom Fawcett},
//     title = {ROC Graphs: Notes and Practical Considerations for Researchers},
//     year = {2004}
// }
void ROC::getROCFromData(std::vector<std::pair<float,int> > data){
  //sort the data by classification score
  sort(data.begin(),data.end(),compare);
  int L = data.size();
  int P = 0;
  int N = 0;

  // count positive and negative class occurences
  for (int j = 0; j < data.size(); j++) {
    if (data[j].second==1)
      {
	P++;
      }
    else 
      {
	N++;
      }
  }
  double f_i;
  bool label;
  //init FP TP counters
  double FP = 0;
  double TP = 0;
  double f_prev = -std::numeric_limits<double>::infinity();
  std::vector<std::pair<float,float> > R;
  //loop through all data
  for (int i = 0; i < L; i++) {
    f_i = data[i].first;
    label = data[i].second;
    if (f_i != f_prev)
      {
	// add points to roc curves
	this->TP.push_back(TP/P);
	this->FP.push_back(FP/N);

	f_prev = f_i;
      }
    if (label==1)
      {
	TP = TP + 1;
      }
    else
      {
	FP = FP + 1;
      }
  }
  //add point 1-1
  this->TP.push_back(TP/P);
  this->FP.push_back(FP/N);
}


