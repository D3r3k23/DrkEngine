#include "Core.hpp"

#if defined(DRK_EN_LOGGING) || defined(DRK_EN_ASSERTS)
    #include <format>
#endif

#if defined(DRK_EN_LOGGING)
    #include <chrono>
#endif

namespace Drk
{
    ////////// Logging //////////
    #if 1 // defined(DRK_EN_LOGGING)

        // Logger private static instance
        Logger* Logger::s_instance = nullptr;

        // Logger public static functions

        void Logger::init(const char* name)
        {
            s_instance = new Logger(name);
            DRK_LOG(INFO, "Log file opened.");
        }

        void Logger::log(LogType type, std::string_view msg)
        {
            DRK_ASSERT(s_instance, "Logger not initialized");
            s_instance->log_internal(type, msg);
        }

        void Logger::save(void)
        {
            DRK_ASSERT(s_instance, "Logger not initialized");
            DRK_LOG(INFO, "Log file closed.");
            s_instance->save_internal();
        }

        // Logger constructor & destructor

        Logger::Logger(const char* name)
        {
            using Days    = std::chrono::days;
            using Seconds = std::chrono::seconds;

            auto now = std::chrono::system_clock::now();

            const std::chrono::year_month_day    ymd(std::chrono::floor<Days>(now));
            const std::chrono::hh_mm_ss<Seconds> hms(std::chrono::floor<Seconds>(now));

            const auto fn = std::format("logs/{}_drk_engine_{}.{}.{}.{}.{}.{}.log",
                name,
                ymd.month(),
                ymd.day(),
                ymd.year(),
                hms.hours(),
                hms.minutes(),
                hms.seconds()
            );

            // const std::stringstream fn;
            // fn << "logs/";
            // fn << name << "_drk_engine" << "_";
            // fn << ymd.month() << ".";
            // fn << ymd.day() << ".";
            // fn << ymd.year() << "_";
            // fn << hms.hours() << ":";
            // fn << hms.minutes()  << ":";
            // fn << hms.seconds()  << ".log";

            log_file.open(fn);
            DRK_ASSERT(log_file.is_open(), "Couldn't open log file: " + fn);
        }

        Logger::~Logger(void)
        {
            save_internal();
        }

        // Logger private functions

        void Logger::log_internal(LogType type, std::string_view msg)
        {
            log_file << "[" << type << "]  " << msg << "\n";
        }

        void Logger::save_internal(void)
        {
            log_file.close();
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
    #if defined(DRK_EN_ASSERTS)

        void assert_failed(std::string_view msg, std::string_view file, int line)
        {
            const auto file_name  = std::filesystem::path(file).filename();
            const auto assert_msg = std::format("{}:{}: {}", file_name, line, msg);
            std::cout << "Assert: " << assert_msg << std::endl; // Remove later?

            DRK_LOG(ASSERT, assert_msg);
            DRK_LOGGER_SAVE();

            DRK_DEBUG_BREAK;
        }

    #endif // DRK_EN_ASSERTS
}
