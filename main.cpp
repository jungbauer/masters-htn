#include <string>
#include <iostream>

#include "Classes/Manager.h"

using namespace std;

bool extractArguments(int argc, char** argv, string &config);

int main( int argc, char* args[] )
{
    int output = -99;
    string config;
    if(extractArguments(argc, args, config) == false)
    {
        cerr << "ERROR - No config file given!" << endl;
    }
    else
    {
        //cerr << "Config == " << config << endl;
        Manager manager(config);
        output = manager.run();
    }

    return output;
}

bool extractArguments(int argc, char** argv, string &config)
{
    bool found = false;
    for(int i =0; i < argc; i++)
    {
        if(strcmp(argv[i],"-cf") == 0)
        {
            config = argv[i+1];
            found = true;
            i++;
        }
    }
    return found;
}
