#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "ArgumentManager.h"
#include "hw2.h"

using namespace std;

int main(int argc, char* argv[])
{

    ArgumentManager am(argc,argv);

    string infilename = am.get("input");
    string sortname = am.get("sort");
    string outfilename = am.get("output");

    ifstream input(infilename);
    ifstream sort(sortname);
    ofstream output(outfilename);
    
    Student object;    

    //student record; //struct 
    
    string dataStr;
    while(getline(input,dataStr))
    {
        dataStr.erase(remove(dataStr.begin(),dataStr.end(),'\n'),dataStr.end());
        dataStr.erase(remove(dataStr.begin(),dataStr.end(),'\r'),dataStr.end());
        if(dataStr != ""){
        if(dataStr[0] == 'd'){
            object.deleteNode(dataStr.substr(7, 7));
            continue;
        }
        
        string id,first,last,dob,gpa;
        
        int cu1;
        int cu2;
        int cu3;
        int cu4;

    
        bool check1 = false;
        bool check2 = false;
        bool check3 =false;
        bool check4 = false;

        int size = dataStr.length();
    
        for(int i=0;i<size; i++)
        {
            if(dataStr[i] == ',' && check1 == false && check2 == false && check3 == false && check4 == false)
            {
            cu1 = i;
            check1 = true;
            }
            else if(dataStr[i] == ',' && check1 == true && check2 == false && check3 == false && check4 == false)
            {
            cu2 = i;
            check2 = true;
            }
            else if(dataStr[i] == ',' && check1 == true && check2 == true && check3 == false && check4 == false)
            {
            cu3 = i;
            check3 = true;
            }
            else if(dataStr[i] == ',' && check1 == true && check2 == true && check3 == true && check4 == false)
            {
            cu4 = i;
            check4 = true;
            }
        }
        
        id = dataStr.substr(1+3,cu1-4);
        first = dataStr.substr(cu1+1,cu2-cu1-1);
        last = dataStr.substr(cu2+1,cu3-cu2-1);
        dob = dataStr.substr(cu3+1,cu4-cu3-1);
        gpa = dataStr.substr(cu4+1,7);
            
        object.add(id,first,last,dob,gpa);
        }
    }
    

    object.bubbleSort("id");
    object.openFile(sort);
    object.print(output);

    return 0;
}

