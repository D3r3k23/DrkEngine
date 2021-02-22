
#include "Core.hpp"


namespace Drk
{
    ////////// Logging //////////
    #ifdef DRK_EN_LOGGING

        // Logger public static member functions

        void Logger::init(void)
        {
            instance = new Logger;
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
            delete instance;
        }


        // Logger private members

        Logger* Logger::instance = nullptr;

        Logger::Logger(void)
        {
            std::tm* logtime = gmtime(nullptr);
            std::string fp = "logs/drk_engine_"
              + std::to_string(logtime->tm_mon)  + "."
              + std::to_string(logtime->tm_mday) + "."
              + std::to_string(logtime->tm_year) + "_"
              + std::to_string(logtime->tm_hour) + ":"
              + std::to_string(logtime->tm_min)  + ":"
              + std::to_string(logtime->tm_sec)  + ".log";

            logfile.open(fp, std::ofstream::out);
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
            case LogType::INFO   : os << "Info   ";
            case LogType::WARN   : os << "Warning";
            case LogType::ERR    : os << "Error  ";
            case LogType::ASSERT : os << "Assert ";
            default: ;
            }

            return os;
        }

    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #ifdef DRK_EN_ASSERTS  

        void assert_failed(const std::string& msg, const std::string& file, int line)
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
