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

#include "data_parser.h"

int main()
{
// Requisite printf statement - Class 4, 23-Feb-2022
  string name("Nicholas");
  float num = 5.569483303;
  printf("Greetings. My name--%s.\n%.2f\n", name.c_str(), num);

// I. Printing SKU, Brand, and Year for each record  
  // define variables
  string sku, brand, category, year, price;
  vector<string> vSKU, vBrand, vCategory, vYear;
  vector<float> vPrice;
  
  // opening the file
  ifstream in_stream("data.csv");
  
  // if the file is open, execute
  if (!in_stream.fail())
  {
    string header;
    getline(in_stream, header);

    while (in_stream.peek() != EOF)  // while eof is NOT reached (avoids reading past eof)
    {
      // fields: sku, brand, category, year, price
      
      getline(in_stream, sku, ',');
      vSKU.push_back(sku);
      
      getline(in_stream, brand, ',');
      vBrand.push_back(brand);
      
      getline(in_stream, category, ',');
      vCategory.push_back(category);
      
      getline(in_stream, year, ',');
      vYear.push_back(year);
      
      getline(in_stream, price, '\n');
      stringstream sprice(price);
      float fPrice;
      sprice >> fPrice;
      vPrice.push_back(fPrice);
    }
    
    in_stream.close();
  } else {
      cout << "Unable to open file";
  }
  
  // output series of lines "SKU Brand Year" to text file
  ofstream out_stream("data_analysis.txt");
  
  out_stream << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl;
  if ( vSKU.size() == vBrand.size() && vSKU.size() == vYear.size() )
  {
    for (int j = 0; j < vSKU.size(); j++)
    {
      out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
    }
  }
  out_stream << endl << endl;
  
  
// II. Feature 1: Printing the average price per brand and per category  
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
  out_stream << endl << endl;
  
  
// III. Feature 2: Printing the years and their associated SKUs
  map< string, set<string> > dataMap;
  fill_dataMap(vYear, vSKU, dataMap);
  out_stream << "List of SKUs by year" << endl;
  print_dataMap(dataMap, out_stream);
  
  
// IV. End of program
  out_stream.close();
}




/* print_averageMap
*/
void print_averageMap(map< string, pair<float,int> >& averageMap, ofstream& out_stream)
{
  for (map< string, pair<float,int> >::iterator it = averageMap.begin(); it != averageMap.end(); it++)
  {
    string name = it -> first;
    pair<float, int> val = it -> second;
    float average = val.first/val.second;
    
    // code to allow for automatic malloc in formatting character buffer
    size_t size = snprintf(NULL, 0, "%s\t%15.2f", name.c_str(), average);
    char *buffer = (char*)malloc(size+1);
    sprintf(buffer, "%s\t%15.2f", name.c_str(), average);
    
    out_stream << buffer << endl;
  }
  
  return;
}




void print_dataMap(map< string, set<string> >& dataMap, ofstream& out_stream)
{
  for (map< string, set<string> >::iterator it = dataMap.begin(); it != dataMap.end(); it++)
  {
    out_stream << it->first << " (" << it->second.size() << "): ";
    for (set<string>::iterator set_it = it->second.begin(); set_it != it->second.end(); set_it++)
    {
      out_stream << *set_it << " ";
    }
    out_stream << endl;
  }
}




/* fill_averageMap
  Fills a map (owners) using two vectors labeled one and many.
  The map is filled by unique values from <one>, they act as the keys while an index is stored as the value.
  The map values act as matching indices that allow an owner to be associated with the data in the vector.
*/
void fill_averageMap(vector<string>& names, vector<float>& prices, map< string, pair<float,int> >& averageMap)
{
  if (names.size() == prices.size())
  {
    averageMap.clear();
    
    for (int i = 0; i < names.size(); i++)
    {
      pair<float, int> val(prices[i], 1);
      if ( !averageMap.insert(make_pair(names[i], val)).second )
      {
        averageMap.find(names[i])->second.first += prices[i];
        averageMap.find(names[i])->second.second++;
      }
    }
  }
  
  return;
}




void fill_dataMap(vector<string>& names, vector<string>& data, map< string, set<string> >& dataMap)
{
  if (names.size() == data.size())
  {
    dataMap.clear();
    
    for (int i = 0; i < names.size(); i++)
    {
      pair< string, set<string> > pr;
      pr.first = names[i];
      
      dataMap.insert(pr).second;
      dataMap.find(names[i])->second.insert(data[i]);
    }
  }
  
  return;
}
