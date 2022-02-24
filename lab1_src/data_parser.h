#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>

using namespace std;

void fill_averageMap(vector<string>& names, vector<float>& prices, map< string, pair<float,int> >& averageMap);
void fill_dataMap(vector<string>& names, vector<string>& data, map< string, set<string> >& dataMap);

void print_averageMap(map< string, pair<float,int> >& averageMap, ofstream& out_stream);
void print_dataMap(map< string, set<string> >& dataMap, ofstream& out_stream);
