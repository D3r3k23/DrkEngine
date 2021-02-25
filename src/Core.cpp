
#include "Core.hpp"


namespace Drk
{
    ////////// Logging //////////
    #ifdef DRK_EN_LOGGING

        Ptr<Logger> Logger::instance = nullptr; // Logger private static instance


        // Logger public static members

        void Logger::init(const char* name)
        {
            instance = make_ptr<Logger>(name);
        }

        void Logger::log(LogType type, const char* msg)
        {
            if (!instance)
                init();

            instance->logfile << "[" << type << "]  " << msg << "\n";
        }

        void Logger::log(LogType type, const std::string& msg)
        {
            log(type, msg.c_str());
        }

        void Logger::save(void)
        {
            if (instance)
                instance->logfile.close();
        }


        // Logger constructor & destructor

        Logger::Logger(const char* name)
        {
            std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm* logtime = std::localtime(&now);
            std::string fp = "logs/"
              + std::string(name) + "_drk_engine" + "_"
              + std::to_string(logtime->tm_mon)   + "."
              + std::to_string(logtime->tm_mday)  + "."
              + std::to_string(logtime->tm_year)  + "_"
              + std::to_string(logtime->tm_hour)  + ":"
              + std::to_string(logtime->tm_min)   + ":"
              + std::to_string(logtime->tm_sec)   + ".log";

            logfile.open(fp);
            if (!logfile.is_open())
                std::cout << "Couldn't open log file: " << fp << std::endl;
        }

        Logger::~Logger(void)
        {
            save();
        }


        // LogType

        std::ostream& operator<<(std::ostream& os, LogType& type)
        {
            switch (type)
            {
            case LogType::INFO   : os << " Info  "; break;
            case LogType::WARN   : os << "Warning"; break;
            case LogType::ERR    : os << " Error "; break;
            case LogType::ASSERT : os << "Assert "; break;
            default: ;
            }

            return os;
        }

    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #ifdef DRK_EN_ASSERTS  

        void Assert::failed(const std::string& msg, const std::string& file, int line)
        {
            std::string assert_msg(file + ":" + std::to_string(line) + ": " + msg);
            std::cout << "Assert: " << assert_msg << std::endl;

            #ifdef DRK_EN_LOGGING
                DRK_LOG(ASSERT, assert_msg);
                Logger::save();
            #endif // DRK_EN_LOGGING
        }

    #endif // DRK_EN_ASSERTS
}
