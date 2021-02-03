
#ifndef CORE_H
#define CORE_H


#include <fstream>
#include <string>
#include <ctime>

#include <cassert>
#include <filesystem>


////////// Logger //////////

namespace Drk
{
    enum class LogType { INFO, WARN, ERROR };

    class Logger
    {
    public:
        static void init(void);
        static void log(LogType type, std::string msg);
    
    private:
        static std::ofstream logfile;
        static std::tm* logtime;
        static std::string fn;
        static bool ready;
        
        static std::string type_str(LogType type);
    };

#ifdef DRK_LOG
    #define LOG(type, msg) Drk::Logger::log(type, msg)
#else
    #define LOG(type, msg)
#endif


////////// Assert //////////

    class Assert
    {
    public:
        static void failed(const std::string& msg, const char* file, int line);
    }

#ifdef DRK_ASSERT
    #define ASSERT(cond, msg) \
    do { \
        if (!(cond)) \
        { \
            Drk::Assert::failed(msg, std::filesystem::path(__FILE__).filename().string(), __LINE__); \
            std::assert(0); \
        } \
    } while (false)
#else
    #define ASSERT(cond, msg)
#endif
    
}


#endif // CORE_H
