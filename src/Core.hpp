#ifndef DRK_ENGINE_CORE_HPP
#define DRK_ENGINE_CORE_HPP

#include <memory>

#if defined(DRK_DEBUG)
    #define DRK_EN_LOGGING
    #define DRK_EN_ASSERTS
#endif

#if defined(DRK_EN_LOGGING)
    #include <fstream>
    #include <string_view>
#endif

#if defined(DRK_EN_ASSERTS)
    #ifdef __linux__
        #include <signal.h>
        #define DRK_DEBUG_BREAK() raise(SIGTRAP)
    #elif _WIN32
        #define DRK_DEBUG_BREAK() __debugbreak()
    #endif
#endif

namespace Drk
{
    ////////// Ptr //////////

    template <typename T>
    using Ptr = std::unique_ptr<T>;

    template <typename T, typename ... Args>
    constexpr Ptr<T> make_ptr(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }


    ////////// Logging //////////
    #if defined(DRK_EN_LOGGING)

        #define DRK_LOGGER_INIT(name) Drk::Logger::init(name)
        #define DRK_LOG(type, msg)    Drk::Logger::log(Drk::LogType::type, msg)
        #define DRK_LOGGER_SAVE()     Drk::Logger::save()

        enum class LogType
        {
            INFO,
            WARN,
            ERR,
            ASSERT
        };

        class Logger
        {
        private:
            static Ptr<Logger> s_instance; // Singleton

        public:
            static void init(const char* name, const char* dir=nullptr);
            static void log(LogType type, std::string_view msg);
            static void save(void);
            static bool initialized(void);

            Logger(const char* name, const char* dir);
            ~Logger(void);

            Logger(Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

        private:
            void log_internal(LogType type, std::string_view msg);
            void save_internal(void);

            std::ofstream log_file;
        };

        std::string to_string(LogType type);

    #else // Unimplemented
        #define DRK_LOGGER_INIT(name)
        #define DRK_LOG(type, msg)
        #define DRK_LOGGER_SAVE()
    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #if defined(DRK_EN_ASSERTS)

        #define DRK_ASSERT(cond, msg)                   \
        do {                                            \
            if (!(cond))                                \
                assert_failed(msg, __FILE__, __LINE__); \
        } while (false)

        void assert_failed(std::string_view msg, std::string_view file, int line);

    #else // Unimplemented
        #define DRK_ASSERT(cond, msg)
    #endif // DRK_EN_ASSERTS
}

#endif // DRK_ENGINE_CORE_HPP
