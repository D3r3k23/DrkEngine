
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
    
    void Logger::log(LogType type, const char* msg)
    {
        if (!ready)
            init();
        logfile << "[" << type << "]  " << msg << std::endl;
    }
    
    void Logger::log(LogType type, const std::string& msg)
    {
        log(type, msg.c_str());
    }
    
    void Logger::save(void)
    {
        logfile.close();
    }
    
    ostream& operator<<(ostream& os, LogType type)
    {
        switch (type)
        {
        case INFO : os << "Info   ";
        case WARN : os << "Warning";
        case ERR  : os << "Error  ";
        default   : os << " ";
        }
        
        return os;
    }
    
    
    void Assert::failed(const char* msg, const char* file, int line)
    {
        std::string log_msg("Assert: " + std::string(file) + " [" std::to_string(line) "] " + std::string(msg));
        LOG(LogType::ERROR, log_msg);
    }
}
