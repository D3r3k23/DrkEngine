
#ifdef LOG_H
#define LOG_H


#include <fstream>
#include <string>
#include <ctime>


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
        static bool ready = false;
    };
}


#ifdef EN_LOGGING
    #define LOG(type, msg) { Drk::Logger::log(type, msg); }
    Drk::Logger::init();
#else
    #define LOG(type, msg)
#endif


#endif // LOG_H
