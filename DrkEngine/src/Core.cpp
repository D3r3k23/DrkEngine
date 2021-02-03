
#include "Core.h"


namespace Drk
{
    bool Logger::ready = false; // init
    
    void Logger::init(void)
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
            ready = true;
    }
    
    void Logger::log(LogType type, std::string msg)
    {
        if (!ready)
            init();
        logfile << "[" << type_str(type) << "]  " << msg << std::endl;
    }
    
    std::string Logger::type_str(LogType type)
    {
        switch (type)
        {
        case INFO : return "Info   ";
        case WARN : return "Warning";
        case ERR  : return "Error  ";
        default   : return "";
        }
    }
    
    
    void Assert::failed(const std::string& msg, const char* file, int line)
    {
        std::string log_msg("Assert: " + (std::string)file + " [" std::to_string(line) "] " + msg);
        LOG(LogType::ERROR, log_msg);
    }
}
