
#ifndef CORE_HPP
#define CORE_HPP


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <cassert>
#include <ctime>


// Temp:
#ifndef DRK_EN_LOGGING
#define DRK_EN_LOGGING
#endif
#ifndef DRK_EN_ASSERTS
#define DRK_EN_ASSERTS
#endif


namespace Drk
{
    ////////// Refs //////////
    
    template <typename T>
    using Ptr = std::shared_ptr<T>;
    
    template <typename T, typename ... Args>
    constexpr Ptr<T> make_ptr(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    
    ////////// Logging //////////
    #ifdef DRK_EN_LOGGING

        #define DRK_LOGGER_INIT(name) Logger::init(name)
        #define DRK_LOG(type, msg)    Logger::log(LogType::type, msg)

        enum class LogType;

        class Logger // Singleton
        {
        public:
            static void init(const char* name="");
            static void log(LogType type, const char* msg);
            static void log(LogType type, const std::string& msg);
            static void save(void);

            Logger(const char* name);
            ~Logger(void);
            Logger(Logger&) = delete;
            Logger& operator=(const Logger&) = delete;

        private:
            std::ofstream logfile;

            static Ptr<Logger> instance;
        };

        enum class LogType
        {
            INFO,
            WARN,
            ERR,
            ASSERT
        };

        std::ostream& operator<<(std::ostream& os, LogType& type);

    #else // Unimplemented
        #define DRK_LOGGER_INIT(name)
        #define DRK_LOG(type, msg)
    #endif // DRK_EN_LOGGING


    ////////// Asserts //////////
    #ifdef DRK_EN_ASSERTS

        // std::filesystem::path(__FILE__).filename().string() ???
        #define DRK_ASSERT(cond, msg)                    \
        do {                                             \
            if (!(cond))                                 \
            {                                            \
                Assert::failed(msg, __FILE__, __LINE__); \
                assert(false);                           \
            }                                            \
        } while (false)
        
        namespace Assert
        {
            void failed(const std::string& msg, const std::string& file, int line);
        }

    #else // Unimplemented 
        #define DRK_ASSERT(cond, msg)
    #endif // DRK_EN_ASSERTS
}


#endif // CORE_HPP
