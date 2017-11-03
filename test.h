
#include <mysql/mysql.h>
#include <vector>
#include <string>

using namespace std;

#ifndef DataBase_Pic
#define DateBase_Pic 

class DataBase_Pic{

public:
    DataBase_Pic();  //constuctor without arguements
    void Get_Tables(); //get tables
    void DataBase_Init(const char *host,
        const char *user,
        const char *passwd,
        const char *db,
        unsigned int port,
        const char *unix_socket,
        unsigned long clientflag);// init mysql database
    void Get_Contents(const char* table); //get the contents inside tables
    void DataBase_Close(); //close mysql
    void DataBase_Insert(const char* table,vector<string> value); //insert data
private:
    MYSQL mysql;
    static bool IF_CONFIG;
};

#endif
