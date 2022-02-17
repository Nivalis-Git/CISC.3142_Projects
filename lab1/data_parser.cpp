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

void pairing_oneToMany(vector<string>& vOne, vector<string>& vMany, vector<stringstream>& vOwners);

int main() {

  // define variables
  string sku, brand, category, year, price;
  vector<int> vSKU;
  vector<string> vBrand;
  vector<string> vCategory;
  vector<int> vYear;
  vector<float> vPrice;
  
  // opening the file
  ifstream in_stream;
  in_stream.open("data.csv");
  
  // if the file is open, execute
  if (!in_stream.fail()) {
    string header;
    getline(in_stream, header);

    while (in_stream.peek() != EOF) {  // while eof is NOT reached (avoids reading past eof)
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
    
    in_stream.close();  // closing the file cout << "Number of entries: " << i-1 << endl;
  } else {
      cout << "Unable to open file";
  }
  
  // output series of "SKU Brand Year" to text file
  ofstream out_stream("data_analysis.txt");
  
  out_stream << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl;
  for (int j = 0; j < vSKU.size(); j++) {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
  }
  out_stream << endl << endl;
  
  // Calculating the average price per brand and per category
  vector<string> owners;      // tracks the unique owner values
  vector<float> sumOfPrices;  // tracks the sum of prices associated with an owner
  vector<int> countOfPrices;  // tracks the number of prices associated with an owner
  // the above vectors match their elements with the same indices, i.e. a[i]<-->b[i]<-->c[i]
  
  vector<string>::iterator it;
  for (int i = 0; i < vBrand.size(); i++) {
    it = find(owners.begin(), owners.end(), vBrand[i]);
    if (it == owners.end()) {            // if vBrand[i] does not exist then push the new values
      owners.push_back(vBrand[i]);
      sumOfPrices.push_back(vPrice[i]);
      countOfPrices.push_back(1);
    } else {                             // else update the correct existing values
      sumOfPrices[it-owners.begin()] += vPrice[i];
      countOfPrices[it-owners.begin()]++;
    }
  }
  
  out_stream << "Brand" << "\t" << "Average_Price" << endl;
  char* average;  // buffer for correctly formatted average
  for (int i = 0; i < owners.size(); i++) {
    sprintf(average, "%8.2f", sumOfPrices[i]/countOfPrices[i]);
    out_stream << owners[i] << "\t" << average << endl;
  }
  
  out_stream.close();
  
  cout << endl;
}
