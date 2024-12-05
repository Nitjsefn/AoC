#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> read_file()
{
    vector<vector<int>> vec;
    fstream file("./input");
    string line;
    while(getline(file, line))
    {
        int num;
        stringstream line_stream(line);
        vector<int> line_vec;
        while(line_stream >> num)
            line_vec.push_back(num);
        vec.push_back(line_vec);
    }
    return vec;
}

int main()
{
    auto input = read_file();
    //vector<vector<int>> input = {{7,6,4,2,1},{1,2,7,8,9},{9,7,6,2,1},{1,3,2,4,5 },{8,6,4,4,1 },{1,3,6,7,9 }};
    int output = 0;
    for(auto report : input)
    {
        int last_num = report[0];
        int dir = 0;
        for(int i = 1; i < report.size(); i++)
        {
            int num = report[i];
            if(dir == -1)
            {
                if((last_num - num) < 1 || (last_num - num) > 3)
                    break;
            }
            else if(dir == 1)
            {
                if((num - last_num) < 1 || (num - last_num) > 3)
                    break;
            }
            else if(dir == 0)
            {
                if(abs(num - last_num) < 1 || abs(num - last_num) > 3)
                    break;
                (num - last_num) > 0 ? dir = 1 : dir = -1;
            }
            if(i == report.size() - 1)
                output++;
            last_num = num;
        }
    }
    cout << output << endl;
}
