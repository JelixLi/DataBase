#include <iostream>
#include <string>
#include <vector>
#include <mysql/mysql.h>

using namespace std;

int main(int argc,char* argv[])
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(
        &mysql,"localhost","root","lj1512510237","test",3306,NULL,0
    );

    string sql="show tables";

    mysql_query(&mysql,sql.c_str());
    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);

    vector<string> allTable;
    MYSQL_ROW row=mysql_fetch_row(result);
    while(row!=NULL)
    {
        allTable.push_back(*row);
        row=mysql_fetch_row(result);
    }

    for(vector<string>::const_iterator cit=allTable.begin();
    cit!=allTable.end();
    ++cit)
    {
        cout<<*cit<<"\t";
    }
}