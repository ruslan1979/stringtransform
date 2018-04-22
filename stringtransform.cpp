#include "stringtransform.h"

using namespace std;

//word removal
void stringtransform::removeword(string& input_string, const string& word) {
    //SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    //SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    setlocale(0, "");
    
    if (word == "")
        return;
    
    // transform a string to uppercase
    string transformed_word = word;
    transform(transformed_word.begin(), transformed_word.end(), transformed_word.begin(), ::toupper);
    
    string::size_type wordlength = word.length();
    
    // transfor the input_string to uppercase    
    string transformed_string = input_string;
    transform(transformed_string.begin(), transformed_string.end(), transformed_string.begin(), ::toupper);

    string::size_type pos = string::npos;
    while ((pos  = transformed_string.find(transformed_word))!= string::npos){
        transformed_string.erase(pos, wordlength);
        input_string.erase(pos, wordlength);
    }        
}


// sort is taken from Algorithms P.II by R.Sedgewick
// http://www.informit.com/articles/article.aspx?p=2180073&seqNum=4
void stringtransform::sort(vector<string> &a) {
        sort(a, 0, a.size() - 1, 0);
}

int charAt(string str, int d) {
    return (d < str.length()) ? str[d] : - 1;
}

void  stringtransform::sort(vector<string>& a, int lo, int hi, int d) {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
        
    if (hi <= lo) 
        return;
    
    int lt = lo, gt = hi;
    
    string transformed_lo = a[lo];
    transform(transformed_lo.begin(), transformed_lo.end(), transformed_lo.begin(), ::toupper);
    int v = charAt(transformed_lo, d);
    
    int i = lo + 1;
    while (i <= gt) {
        string transformed_ai = a[i];
        transform(transformed_ai.begin(), transformed_ai.end(), transformed_ai.begin(), ::toupper);
        
        int t = charAt(transformed_ai, d);
        if (t < v) 
            swap(a[lt++], a[i++]);
        else if (t > v) 
            swap(a[i], a[gt--]);
        else
            i++;
    }
    
    sort(a, lo, lt - 1, d);
    if (v >= 0) 
        sort(a, lt, gt, d + 1); 
    sort(a, gt+1, hi, d);    
}