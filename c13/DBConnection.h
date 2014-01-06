#ifndef _DBCONNECTION_H_
#define _DBCONNECTION_H_

#include <exception>
#include <iostream>
#include <string>

class DBConnectionException : public std::exception { 
  public:
    DBConnectionException(const char *fname, int lineNum, const std::string &msg = ""):message(msg) { }
    const char *what()  const noexcept {
      return message.c_str();
    }
  private:
    std::string fname;
    int lineNum;
    std::string message;
};

#define MakeDBConnectionException(msg) (DBConnectionException{__FILE__, __LINE__, msg}) 

class DBConnection
{
  public:
    DBConnection(int aID):id(aID) { }
    int get() {
      if (id % 2 == 0) {
        throw MakeDBConnectionException("get failed.");
      }
      return id;
    }
    void close() {
      if (id == 4) {
        throw MakeDBConnectionException("close failed.");
      }
      std::cout << "Close " << id << " connection OK." << std::endl;
    }
    ~DBConnection() {
      try {
        close();
      } catch (const DBConnectionException &e) {
        std::cout << e.what() << std::endl;
        throw;
      }
    }
  private:
    int id;
};

#endif //_DBCONNECTION_H_
