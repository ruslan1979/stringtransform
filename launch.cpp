#include "stringtransform.h"

using namespace std;

void parse_cl_arguments(map<string, string>& args, const int argcount, char *argvals[]){
    
    vector<string> params;
    for (unsigned int i = 0; i != argcount; ++i) {
        params.push_back(argvals[i]);
    }
    
    for (unsigned int i = 0; i != params.size(); i += 2) {
        args.insert(make_pair(params[i], params[i + 1]));
    }
}

int main(int argc, char* argv[]) {
    cout << "+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n"
         << "+*                                              +*\n"
         << "+* Removal words and sorting strings  in a file +*\n"
         << "+*                                              +*\n"
         << "+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n"
         << endl;
                  
    if (argc != 7) {
        cout << "Insufficient parameters are entered\n"
             << "Params are: \n"
             << "-i /path/to/input/file \n"
             << "-t /path/to/output/file \n"
             << "-w an excluded word";
        return 1;         
    }
    
    map<string,string> args;
    
    parse_cl_arguments(args, argc - 1, argv + 1);
     
    ifstream input(args["-i"]);
    ofstream output(args["-t"]);
    string word = args["-w"];
    
    vector<string> strings;
    for (string line; getline(input, line);) {
        strings.push_back(line);
    }

    input.close();
    
    for (unsigned int i = 0; i != strings.size(); ++i) {        
        stringtransform::removeword(strings[i], word);        
    }
    
    stringtransform::sort(strings);
        
    for (auto line : strings) 
        output << line << endl;
    
    output.close();    
    
    cout << "The process is complete";
    return 0;
}