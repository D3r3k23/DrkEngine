
#include "Core.h"


namespace Drk
{
    std::ostream& operator<<(std::ostream& os, LogType& type)
    {
        switch (type)
        {
        case LogType::INFO : os << "Info   ";
        case LogType::WARN : os << "Warning";
        case LogType::ERR  : os << "Error  ";
        default: ;
        }
        
        return os;
    }

    bool Logger::ready = false; // init bool ready
    
    void Logger::init(void)
    {
        logtime = gmtime(nullptr);
        fp = "logs/drk_engine_";
        fp += std::to_string(logtime->tm_mon)  + ".";
        fp += std::to_string(logtime->tm_mday) + ".";
        fp += std::to_string(logtime->tm_year) + "_";
        fp += std::to_string(logtime->tm_hour) + ":";
        fp += std::to_string(logtime->tm_min)  + ":";
        fp += std::to_string(logtime->tm_sec)  + ".";
        fp += ".log";
        
        logfile.open(fp, std::ofstream::out);
            
        if (logfile.fail())
            std::cout << "Error: Could not open log file." << std::endl;
        else
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
    
    
    void Assert::failed(const std::string& msg, const std::string& file, int line)
    {
        std::string log_msg("Assert: " + file + " [" + std::to_string(line) + "] " + msg);
        Logger::save();
        LOG(LogType::ERR, log_msg);
    }
}
