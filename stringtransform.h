#if !defined(STRINGTRANSFORM_H)
#define STRINGTRANSFORM_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include <algorithm>
#include <map>
#include <windows.h>
#include <sstream>

using namespace std;

namespace stringtransform {
	
	void removeword(string& input_strings, const string& word);	
    
    void sort(vector<string>& a);
    
    void sort(vector<string>& a, int lo, int hi, int d);
}

#endif