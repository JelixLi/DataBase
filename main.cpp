#include "test.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
    DataBase_Pic agt;
    agt.DataBase_Init("localhost","root","lj1512510237","test",3306,NULL,0);

    char *str[]={
        "NULL","\"test_1\"","\"/home/jieli/Pictures/cf1b9d16fdfaaf51a7558775855494eef11f7a41.jpg\""
    };
    vector<string> cmd(str,str+3);
    agt.DataBase_Insert("pic",cmd);
}