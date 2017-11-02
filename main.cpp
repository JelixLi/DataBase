#include "test.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
    DataBase_Pic agt;
    agt.DataBase_Init("localhost","root","lj1512510237","test",3306,NULL,0);

    agt.Get_Contents("pic");
}