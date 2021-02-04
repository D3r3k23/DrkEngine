
#include "Core.h"


namespace Drk
{
    ////////// Logging //////////

#ifdef DRK_EN_LOGGING

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
        fp = "logs/drk_engine_"
           + std::to_string(logtime->tm_mon)  + "."
           + std::to_string(logtime->tm_mday) + "."
           + std::to_string(logtime->tm_year) + "_"
           + std::to_string(logtime->tm_hour) + ":"
           + std::to_string(logtime->tm_min)  + ":"
           + std::to_string(logtime->tm_sec)
           + ".log";
        
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
    
#endif // DRK_EN_LOGGING


    ////////// Asserts //////////

#ifdef DRK_EN_ASSERTS  

    void Assert::failed(const std::string& msg, const std::string& file, int line)
    {
        std::string assert_msg("Assert: " + file + " [" + std::to_string(line) + "] " + msg);

        #ifdef DRK_EN_LOGGING
            Logger::log(LogType::ERR, assert_msg);
            Logger::save();
        #else
            std::cout << "Error: " << assert_msg << std::endl;
        #endif
    }

#endif // DRK_EN_ASSERTS
}
