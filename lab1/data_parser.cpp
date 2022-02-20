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
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

int main() {
  // I. Printing SKU, Brand, and Year for each record
  
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
  
  
  // II. Printing the average price per brand and per category
  
  // one map and two vectors to store the requisite data
  map<string, int> owners;  // pairs unique string values with an index, allowing associated data to be accessed through matching indices, i.e. <owner,idx> ---> sum[idx], count[idx]
  vector<float> sumOfPrices;  // records the sum of prices associated with an owner
  vector<int> countOfPrices;  // records the number of prices associated with an owner
  
  // fill the map with unique string keys and update the associated vectors
  for (int i = 0, idx = 0; i < vBrand.size(); i++) {
    if ( owners.insert(make_pair(vBrand[i], idx)).second ) {  // if insertion is successful then create new vector entries
      idx++;
      sumOfPrices.push_back(vPrice[i]);
      countOfPrices.push_back(1);
    } else {  // else update the existing associated entries
      int val = owners.find(vBrand[i]) -> second;
      sumOfPrices[val] += vPrice[i];
      countOfPrices[val]++;
    }
  }
  
  // print the average price per
  out_stream << "Brand" << "\t" << "Average_Price" << endl;
  map<string,int>::iterator owners_it = owners.begin();  // iterator for map traversal
  for (owners_it; owners_it != owners.end(); owners_it++) {
    string owner = owners_it -> first;
    int idx = owners_it -> second;
    float average = sumOfPrices[idx]/countOfPrices[idx];
    
    // code to allow for automatic malloc in formatting character buffer
    size_t size = snprintf(NULL, 0, "%s\t%8.2f", owner.c_str(), average);
    char *buffer = (char*)malloc(size+1);
    sprintf(buffer, "%s\t%8.2f", owner.c_str(), average);
    
    out_stream << buffer << endl;
  }
  
  out_stream.close();
  
  cout << endl;
}
