#include "Core.hpp"

#if defined(DRK_EN_LOGGING) || defined(DRK_EN_ASSERTS)
    #include <string>
    #include <format>
    #include <filesystem>
#endif

#if defined(DRK_EN_LOGGING)
    #include <chrono>
#endif

#if defined(DRK_EN_ASSERTS)
    #include <iostream>
#endif

namespace Drk
{
    ////////// Logging //////////
    #if defined(DRK_EN_LOGGING)

        // Logger private static instance
        Ptr<Logger> Logger::s_instance = nullptr;


        // Logger public static functions

        void Logger::init(const char* name, const char* dir)
        {
            if (!dir)
                dir = "logs";

            s_instance = make_ptr<Logger>(name, dir);
            DRK_LOG(INFO, "Log file opened.");
        }

        void Logger::log(LogType type, std::string_view msg)
        {
            DRK_ASSERT(initialized(), "Logger not initialized");
            s_instance->log_internal(type, msg);
        }

        void Logger::save(void)
        {
            DRK_ASSERT(initialized(), "Logger not initialized");
            s_instance->save_internal();
        }

        // Logger constructor

        Logger::Logger(const char* name, const char* dir)
        {
            using Days    = std::chrono::days;
            using Seconds = std::chrono::seconds;

            auto now = std::chrono::system_clock::now();

            const std::chrono::year_month_day    ymd(std::chrono::floor<Days>(now));
            const std::chrono::hh_mm_ss<Seconds> hms(std::chrono::floor<Seconds>(now));

            const auto fn = std::format("{}/{}_drk_engine_{}.{}.{}.{}.{}.{}.log",
                dir,
                name,
                ymd.month(),
                ymd.day(),
                ymd.year(),
                hms.hours(),
                hms.minutes(),
                hms.seconds()
            );

            if (!std::filesystem::is_directory(dir))
                std::filesystem::create_directories(dir);

            log_file.open(fn);
            DRK_ASSERT(log_file.is_open(), "Couldn't open log file: " + fn);
            DRK_LOG(INFO, "Log file opened");
        }

        Logger::~Logger(void)
        {
            DRK_LOG(INFO, "Log file closed.");
            log_file.close();
        }

        // Logger private functions

        void Logger::log_internal(LogType type, std::string_view msg)
        {
            log_file << std::format("[{}] {}", to_string(type), msg) << '\n';
        }

        void Logger::save_internal(void)
        {
            log_file.flush();
        }

        bool Logger::initialized(void)
        {
            return s_instance != nullptr;
        }


        // LogType

        std::string to_string(LogType type)
        {
            switch (type)
            {
            case LogType::INFO   : return " Info  "; break;
            case LogType::WARN   : return "Warning"; break;
            case LogType::ERR    : return " Error "; break;
            case LogType::ASSERT : return "Assert "; break;
            default: return "";
            }
        }

    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #if defined(DRK_EN_ASSERTS)

        void assert_failed(std::string_view msg, std::string_view file, int line)
        {
            const auto file_name  = std::filesystem::path(file).filename();
            const auto assert_msg = std::format("{}:{}: {}", file_name, line, msg);
            std::cout << "Assert: " << assert_msg << '\n';

            if (Logger::initialized())
            {
                DRK_LOG(ASSERT, assert_msg);
                DRK_LOGGER_SAVE();
            }
            DRK_DEBUG_BREAK;
        }

    #endif // DRK_EN_ASSERTS
}
