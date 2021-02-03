
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
    enum class LogType { INFO, WARN, ERROR }

    class Logger
    {
    public:
        static void init()
        {
            logtime = gmtime(nullptr);
            fn = "logs/drk_engine"                + "_";
            fn += std::to_string(logtime.tm_mon)  + ".";
            fn += std::to_string(logtime.tm_mday) + ".";
            fn += std::to_string(logtine.tm_year) + "_";
            fn += std::to_string(logtime.tm_hour) + ":";
            fn += std::to_string(logtine.tm_min)  + ":";
            fn += std::to_string(logtime.tm_sec)  + ".";
            fn += ".log";
            
            if (logfile.fopen(fn))
                read = true;
        }
        
        static void log(LogType type, std::string msg)
        {
            if (!ready)
                init();
            logfile << "[" << type_str(type) << "]  " << msg << std::endl;
        }
    
        static std::string type_str(LogType type)
        {
            switch (type)
            {
            case INFO : return "Info   ";
            case WARN : return "Warning";
            case ERR  : return "Error  ";
            default   : return "";
            }
        }
    
    private:
        static std::ofstream logfile;
        static std::tm* logtime;
        static std::string fn;
        static bool ready;
    };
}


#ifdef DRK_LOG
    #define LOG(type, msg) Drk::Logger::log(type, msg)
    Drk::Logger::init();
#else
    #define LOG(type, msg)
#endif


////////// Assert //////////

namespace Drk
{
    class Assert
    {
        static void failed(const std::string& msg, const char* file, int line)
        {
            std::string log_msg("Assert: " + (std::string)file + " [" std::to_string(line) "] " + msg);
            LOG(LogType::ERROR, log_msg);
        }
    }
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


#endif // CORE_H
