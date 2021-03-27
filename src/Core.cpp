
#include "Core.hpp"


namespace Drk
{
    ////////// Logging //////////
    #ifdef DRK_EN_LOGGING

        // Logger private static instance
        std::unique_ptr<Logger> Logger::s_instance = nullptr;

        // Logger public static functions

        void Logger::init(const char* name)
        {
            s_instance = std::make_unique<Logger>(name);
            DRK_LOG(INFO, "Log file opened.");
        }

        void Logger::log(LogType type, const char* msg)
        {
            if (!s_instance)
                init();

            s_instance->log_internal(type, msg);
        }

        void Logger::log(LogType type, const std::string& msg)
        {
            if (!s_instance)
                init();

            s_instance->log_internal(type, msg.c_str());
        }

        void Logger::save(void)
        {
            if (s_instance)
                s_instance->save_internal();
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
            DRK_ASSERT(logfile.is_open(), "Couldn't open log file: " + fp);
        }

        Logger::~Logger(void)
        {
            save();
        }

        // Logger private functions

        void Logger::log_internal(LogType type, const char* msg)
        {
            logfile << "[" << type << "]  " << msg << "\n";
        }

        void Logger::save_internal(void)
        {
            DRK_LOG(INFO, "Log file closed.");
            logfile.close();
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
            const std::string assert_msg(file + ":" + std::to_string(line) + ": " + msg);
            std::cout << "Assert: " << assert_msg << std::endl; // Remove later?

            DRK_LOG(ASSERT, assert_msg);
            DRK_LOGGER_SAVE();

            DRK_DEBUG_BREAK;
        }

    #endif // DRK_EN_ASSERTS
}
