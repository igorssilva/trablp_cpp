#include <fstream>
#include "fileio.h"
#include <algorithm>
#include <vector>
using std::vector;

vector<string> split(const string &content, const char &c)
{
    string buff{""};
    vector<string> v;

    for (auto n : content)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}

vector<vector<string>> create_array_file(string content)
{
    content.erase(std::remove(content.begin(), content.end(),'\r'), content.end());
    vector<string> blocks = split(content, '\n\n');


 
}