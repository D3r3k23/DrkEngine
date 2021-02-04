
#ifndef APPLICATION_H
#define APPLICATION_H


#include <DrkEngine.h>

#include <iostream>
#include <string>
#include <fstream>

class Application
{
public:
    Application();
    ~Application();
    void run(void);

private:
    Drk::DrkEngine drk;
};


#endif // APPLICATION_H
