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

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>

class ROC {
public:

  ROC(std::string);
  ~ROC();

  std::vector<float> TP; //roc true positives
  std::vector<float> FP; //roc false positive

  void writeToFile(std::string);
  float get95ErrorRate(void);
  float getAreaUnderCurve(void);

private: 
  std::vector<std::pair<float,int> > data;
  void getROCFromData(std::vector<std::pair<float,int> >);
};
