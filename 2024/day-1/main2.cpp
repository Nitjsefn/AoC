#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <fstream>

using namespace std;

int32_t pop_min(vector<int32_t> &);
void readFromFile(vector<int32_t> &, vector<int32_t> &);

int main()
{
    //vector<int32_t> vec1 = {3, 4, 2, 1, 3, 3}, vec2 = {4, 3, 5, 3, 9, 3};
    vector<int32_t> vec1, vec2;
    int32_t sum = 0;

    readFromFile(vec1, vec2);

    if(vec1.size() != vec2.size())
        return 1;

    for(auto el : vec1)
    {
        int32_t count = 0;
        for(auto el2 : vec2)
            if(el == el2)
                count++;
        sum += el * count;
    }

    cout << sum << endl;
    return 0;
}

void readFromFile(vector<int32_t> &v1, vector<int32_t> &v2)
{
    ifstream file("input.txt");
    int32_t data;
    while(file >> data)
    {
        v1.push_back(data);
        file >> data;
        v2.push_back(data);
    }
}
