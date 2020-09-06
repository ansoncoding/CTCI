#include "pch.h"
#include <chrono>
#include "../Performance/Performance.h"

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
#if 0
int main() {

    using namespace std::chrono;
    // milliseconds is an  
    // instantiation of duration:- 1 second 
    milliseconds mil(1000);

    mil = mil * 60;

    std::cout << "duration (in periods): ";
    std::cout << mil.count() << " milliseconds." << std::endl;

    std::cout << "milliseconds::period::num " << milliseconds::period::num << " den " << milliseconds::period::den << std::endl;
    
    std::cout << "duration (in seconds): " << (mil.count() * milliseconds::period::num / milliseconds::period::den);
    std::cout << " seconds." << std::endl;
    long fibAnswer;
    auto start = steady_clock::now();

    {
        Timer timer;
        
        fibAnswer = fibonacci(42);
    }
    auto end = steady_clock::now();
    std::cout << "f(42) = " << fibAnswer << std::endl;
    duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    //==========================================================================
    std::cout << endl << endl;
    const auto p0 = time_point<system_clock>{};
    const auto p1 = system_clock::now();
    const auto p2 = p1 - hours(24);

    std::time_t epoch_time = system_clock::to_time_t(p0);
    std::cout << "epoch: " << std::ctime(&epoch_time);
    std::time_t today_time = system_clock::to_time_t(p1);
    std::cout << "today: " << std::ctime(&today_time);

    std::cout << "hours since epoch: " << duration_cast<hours>(p1.time_since_epoch()).count() << std::endl;
    std::cout << "yesterday, hours since epoch: " << duration_cast<hours>(p2.time_since_epoch()).count()  << std::endl;
    //==========================================================================
    constexpr auto year = 31556952ll;
    using shakes = duration<int, std::ratio<1, 100000000>>;
    using jiffies = duration<int, std::centi>;
    using microfortnights = duration<float, std::ratio<14 * 24 * 60 * 60, 1000000>>;
    using nanocenturies = duration<float, std::ratio<100 * year, 1000000000>>;

    seconds sec(1);

    std::cout << "1 second is:" << std::endl;

    // integer scale conversion with no precision loss: no cast
    std::cout << microseconds(sec).count() << " microseconds" << std::endl
              << shakes(sec).count()       << " shakes"       << std::endl
              << jiffies(sec).count()      << " jiffies"      << std::endl;

    // integer scale conversion with precision loss: requires a cast
    std::cout << duration_cast<minutes>(sec).count() << " minutes" << std::endl;

    // floating-point scale conversion: no cast
    std::cout << microfortnights(sec).count() << " microfortnights" << std::endl
              << nanocenturies(sec).count()   << " nanocenturies"   << std::endl;
    system("pause");
}
#endif