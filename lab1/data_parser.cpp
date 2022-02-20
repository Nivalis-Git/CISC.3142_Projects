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

void fill_averageMap(vector<string>& one, vector<float>& many, map< string, pair<float,int> >& owners);
void print_averageMap(map< string, pair<float,int> >& owners, ofstream& out_stream);

int main()
{
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
  if (!in_stream.fail())
  {
    string header;
    getline(in_stream, header);

    while (in_stream.peek() != EOF)  // while eof is NOT reached (avoids reading past eof)
    {
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
  for (int j = 0; j < vSKU.size(); j++)
  {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
  }
  
  out_stream << endl << endl;
  
  
  // II. Printing the average price per brand and per category
  
  // organize the requisite data
  map< string, pair<float, int> > averageMap;  // pairs unique string values with a pair conisisting of the sum of prices associated with that string and the number of such prices
  
  // print the average price per brand
  fill_averageMap(vBrand, vPrice, averageMap);
  out_stream << "Brand" << "\t" << "Average_Price" << endl;
  print_averageMap(averageMap, out_stream);
  
  out_stream << endl << endl;
  
  // print the average price per category
  fill_averageMap(vCategory, vPrice, averageMap);
  out_stream << "Category" << "\t" << "Average_Price" << endl;
  print_averageMap(averageMap, out_stream);
  
  out_stream.close();
  
  cout << endl;
}




/* printAverages
*/
void print_averageMap(map< string, pair<float,int> >& owners, ofstream& out_stream)
{
  for (map< string, pair<float,int> >::iterator it = owners.begin(); it != owners.end(); it++)
  {
    string owner = it -> first;
    pair<float, int> val = it -> second;
    float average = val.first/val.second;
    
    // code to allow for automatic malloc in formatting character buffer
    size_t size = snprintf(NULL, 0, "%s\t%15.2f", owner.c_str(), average);
    char *buffer = (char*)malloc(size+1);
    sprintf(buffer, "%s\t%15.2f", owner.c_str(), average);
    
    out_stream << buffer << endl;
  }
  
  return;
}




/* fill_averageMap
  Fills a map (owners) using two vectors labeled one and many.
  The map is filled by unique values from <one>, they act as the keys while an index is stored as the value.
  The map values act as matching indices that allow an owner to be associated with the data in the vector.
*/
void fill_averageMap(vector<string>& name, vector<float>& prices, map< string, pair<float,int> >& averageMap)
{
  if (name.size() == prices.size())
  {
    averageMap.clear();
    
    for (int i = 0; i < name.size(); i++)
    {
      pair<float, int> val(prices[i], 1);
      if ( !averageMap.insert(make_pair(name[i], val)).second )
      {
        averageMap.find(name[i])->second.first += prices[i];
        averageMap.find(name[i])->second.second++;
      }
    }
  }
  
  return;
}
