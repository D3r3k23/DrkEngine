
#include "Application.h"


Application::Application()
{
    std::cout << "App created." << std::endl;
}

Application::~Application()
{

}

void Application::run(void)
{
    std::cout << "App running." << std::endl;
    // std::cout << Drk::get_five() << std::endl;

    std::ofstream file("test.txt");
    file << "Testing...";
}
