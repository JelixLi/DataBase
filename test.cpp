
#include "test.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

DataBase_Pic::DataBase_Pic(){}

bool DataBase_Pic::IF_CONFIG=false;

void DataBase_Pic::DataBase_Init(const char *host,
    const char *user,
    const char *passwd,
    const char *db,
    unsigned int port,
    const char *unix_socket,
    unsigned long clientflag)
{
    mysql_init(&mysql);
    mysql_real_connect(
        &mysql,host,user,passwd,db,port,unix_socket,clientflag
    );
    IF_CONFIG=true;
}

void DataBase_Pic::Get_Contents(const char* table)
{
    if(IF_CONFIG==false)
    {
        cout<<"database haven't been inited"<<endl;
        return;
    }

    string cmd;
    cmd.append("select * from ");
    cmd.append(table);
    mysql_query(&mysql,cmd.c_str());
    MYSQL_RES *result=NULL;
    result=mysql_store_result(&mysql);

    //get row nums
    int row_count=mysql_num_rows(result);
    cout<<"row number:"<<row_count<<endl;

    //get field nums
    int field_count = mysql_num_fields( result );
    cout << "field count : " << field_count << endl;

    //get field contents
    MYSQL_FIELD* field = NULL;
    for( int i = 0; i < field_count; ++i)
    {
        field = mysql_fetch_field_direct( result, i );
        cout << field->name << "\t";
    }
    cout << endl;

    //get row contents
    MYSQL_ROW row = NULL;
    row = mysql_fetch_row( result );
    while ( NULL != row )
    {
        for( int i = 0; i < field_count; ++i)
        {
            cout << row[i] << "\t";
        }
        cout << endl;
        row = mysql_fetch_row( result );
    }

    //free buffer memory
    mysql_free_result(result);

}

void DataBase_Pic::Get_Tables()
{
    if(IF_CONFIG==false)
    {
        cout<<"database haven't been inited"<<endl;
        return;
    }
    
    string cmd="show tables";
    
    mysql_query(&mysql,cmd.c_str());
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
        cout<<*cit<<"\n";
    }

    //free buffer memory
    mysql_free_result(result);
}