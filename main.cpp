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

// example on how to read a file with classification data 
// and get the ROC curve 
int main(int argc, char *argv[])
{
  // format of the file: 
  // column 0 -> classification scores (higher is for positive class)
  // column 1 -> class labels (1 is positive class)
  ROC roc("classification_result_example.txt");
  // the format of the output file is 
  // column 0 -> False positive points in curve
  // column 1 -> True positive points in curve
  roc.writeToFile("roc.txt");
  // roc.txt can then be plotted with gnuplot, mathGL etc. 
  return 0;
}

