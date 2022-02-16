// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code!

/* Homework Objective: fix this program to match the requirements listed.
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
  All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

/* Student Information
  Shterenberg, Simon
  3142 CISC, EW6
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> pairing_oneToMany(vector<string> vNames, vector<string> vValues);

int main() {

  // define variables
  string sku, brand, category, year, price;
  vector<int> vSKU;
  vector<string> vBrand;
  vector<string> vCategory;
  vector<int> vYear;
  vector<float> vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); // opening the file

  if (!in_stream.fail()) { // if the file is open, execute
    string header;
    getline(in_stream, header);

    while (in_stream.peek() != EOF) { // while eof is NOT reached (avoids reading past eof)
      // fields: sku, brand, category, year, price
      
      getline(in_stream, sku, ',');
      stringstream ssku(sku);
      int iSKU = 0;
      ssku >> iSKU;
      vSKU.push_back(iSKU);
      
      getline(in_stream, brand, ',');
      vBrand.push_back(brand);
      
      getline(in_stream, category, ',');
      vCategory.push_back(category);
      
      getline(in_stream, year, ',');
      stringstream syear(year);
      int iYear;
      syear >> iYear;
      vYear.push_back(iYear);
      
      getline(in_stream, price, '\n');
      stringstream sprice(price);
      float fPrice;
      sprice >> fPrice;
      vPrice.push_back(fPrice);
    }
    
    in_stream.close(); // closing the file cout << "Number of entries: " << i-1 << endl;
  } else {
      cout << "Unable to open file";
  }
  
  // output values to text file
  ofstream out_stream("data_analysis.txt");
  
  out_stream << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl;
  for (int j = 0; j < vSKU.size(); j++) {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
  }
  
  // 
  
  out_stream.close();
  cout << endl;
}

/* owner
  owner pairs a single string with many floating point values.
*/
struct owner {
  string name;
  vector<float> values;
}



/* pairing_oneToMany
  Takes two vectors of type string and returns a vector of type owner.
  Fills the owner vector by pairing unique values from the names vector with associated values from the values vector, the pairings are stored in the owner structure.
*/
vector<int> pairing_oneToMany(vector<string> vNames, vector<string> vValues) {
  vectors<string> uniqueNames;
  vector<int> vOwners;
  if vNames.size() == vMany.size() {
    return vOwners;
  }
  
  for (int i = 0; i < vOne.size(); i++) {
    if (find(uniqueNames.begin(), uniqueNames.end(), vOne[i]) == uniqueNames.end()) {
      
    } else {
    }
  }
  
  return vOwners;
}
