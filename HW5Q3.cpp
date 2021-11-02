#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

//intitializing global map, hxy with string and vector arguments
map<string, vector<string>> hxy;

void three()
{
    //reads file
    ifstream ifs("EnglishWords.txt");
    string line;
    while (getline(ifs, line))
    {
        //filters out 3 character strings
        if (line.length() == 3)
        {
            //full word is variable des.
            //first 2 characters is stored in sub1
            //last 2 characters stored in sub 2
            string des = line;
            string sub1 = line.substr(0, 2);
            string sub2 = line.substr(1, 3);


            vector<string> toInsert;


            if (hxy.count(sub1) == 0)
            // if sub1 does not already exist as a key in the map add
            //it and and add the full word to the vectors
            {
                toInsert.clear();
                toInsert.push_back(des);
                hxy.insert({sub1, toInsert});
            }
            else
            {
              //otherwise add the word to the appropriate vector
                toInsert = hxy[sub1];
                toInsert.push_back(des);
                hxy[sub1] = toInsert;
            }

            if (hxy.count(sub2) == 0)
            // if sub2 does not already exist as a key in the map add
            //it and and add the full word to the vectors
            {
                toInsert.clear();
                toInsert.push_back(des);
                hxy.insert({sub2, toInsert});
            }
            else
            //otherwise add the word to the appropriate vector
            {
                toInsert = hxy[sub2];
                toInsert.push_back(des);
                hxy[sub2] = toInsert;
            }
        }
    }
}

void printVector(string y)
//this function prints the vector of 3 letter words that go with the 2 letter strings
{
    for (int n = 0; n < hxy[y].size(); n++)
    {
        cout << hxy[y].at(n) << endl;
    }
}

int main()
{
    cout << "Enter a two-letter string: ";
    //accepts the two letter string as variable x.
    string x;
    cin >> x;

    three();
    printVector(x);

    return 0;
}
