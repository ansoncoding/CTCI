#include "pch.h"

// RAII (Resource Acquisition Is Initialization) A.K.A. Scope-Bound Resource Management(SBRM),
// a C++ programming technique which binds the life cycle of a resource that must be acquired before use to the lifetime of an object.
// E.g. allocated heap memory
//      thread of execution
//      open socket / file
//      locked mutex
//      disk space 
//      database connection

// RAII guarantees that the resource is available to any function that may access the object
// (resource availability is a class invariant, eliminating redundant runtime tests).
// It also guarantees that all resources are released when the lifetime of their controlling object ends, in reverse order of acquisition.
// Likewise, if resource acquisition fails(the constructor exits with an exception), all resources acquired by every fully-constructed member 
// and base subobject are released in reverse order of initialization.
// This leverages the core language features(object lifetime, scope exit, order of initialization and stack unwinding) to eliminate resource leaks 
// and guarantee exception safety.

// Encapsulate each resource into a class, where the constructor acquires the resource and establishes all class invariants or throws an exception if not able to do so
// the destructor releases the resourceand never throws exceptions;
// always use the resource via an instance of a RAII - class that either has automatic storage duration or temporary lifetime itself, or
// has lifetime that is bounded by the lifetime of an automatic or temporary object
// Move semantics make it possible to safely transfer resource ownership between objects, across scopes, and inand out of threads, while maintaining resource safety.

// Classes with open() / close(), lock() / unlock(), or init() / copyFrom() / destroy() member functions are typical examples of non - RAII classes

#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <chrono>

using namespace std;

std::mutex m;

void f() {};

bool everything_ok() { return false; }

void bad()
{
    m.lock();                    // acquire the mutex
    f();                         // if f() throws an exception, the mutex is never released
    if (!everything_ok()) return; // early return, the mutex is never released
    m.unlock();                  // if bad() reaches this statement, the mutex is released
}

void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if (!everything_ok()) return;       // early return, the mutex is released
}

//The C++ library classes that manage their own resources follow RAII : 
// - std::string
// - std::vector
// - std::thread
// Many others acquire their resources in constructors (which throw exceptions on errors),
// release them in their destructors(which never throw), and don't require explicit cleanup.

// In addition, the standard library offers several RAII wrappers to manage user - provided resources :

// Manage dynamically allocated memory:
// - std::unique_ptr 
// - std::shared_ptr
 
// Manage mutexes:
// std::lock_guard
// std::unique_lock
// std::scoped_lock (C++17)


// The class lock_guard is a mutex wrapper that provides a convenient RAII - style mechanism for owning a mutex for the duration of a scoped block.
// When a lock_guard object is created, it attempts to take ownership of the mutex it is given.
// When control leaves the scope in which the lock_guard object was created, the lock_guard is destructedand the mutex is released.
// The lock_guard class is non-copyable.

int g_i = 0;
std::mutex g_i_mutex;  // protects g_i
std::chrono::seconds sec(1);

void safe_increment()
{
    while (1) {
        {
            const std::lock_guard<std::mutex> lock(g_i_mutex);
            if (g_i < 100)
                ++g_i;
            else
                break;
            std::cout << std::this_thread::get_id() << ": " << g_i << '\n';
        }
        
        std::this_thread::sleep_for(sec);
    }
    // g_i_mutex is automatically released when lock
    // goes out of scope
}
#if 0
int main()
{
    std::cout << "main: " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "main: " << g_i << '\n';

    system("Pause");
}
#endif

// The class unique_lock is a general-purpose mutex ownership wrapper allowing deferred locking, time-constrained attempts at locking, 
// recursive locking, transfer of lock ownership, and use with condition variables.

// The class unique_lock is movable, but not copyable -- it meets the requirements of MoveConstructible and MoveAssignable but not of 
// CopyConstructible or CopyAssignable.

// The class unique_lock meets the BasicLockable requirements.
// If Mutex meets the Lockable requirements, unique_lock also meets the Lockable requirements(ex.: can be used in std::lock); 
// if Mutex meets the TimedLockable requirements, unique_lock also meets the TimedLockable requirements.

//std::unique_lock is mightier but more expansive than its small brother std::lock_guard.

// A std::unique_lock has additional features:
// - create it without an associated mutex
// - create it without a locked associated mutex
// - explicitly and repeatedly set or release the lock of the associated mutex
// - move the mutex
// - try to lock the mutex
// - delayed lock the associated mutex

// Motivating problem:
// When we have 2 threads each trying to do something with both critical sections we have a deadlock.

#if 0 
struct CriticalData {
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b) {

    a.mut.lock();
    std::cout << "get the first mutex" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    b.mut.lock();
    std::cout << "get the second mutex" << std::endl;
    // do something with a and b
    a.mut.unlock();
    b.mut.unlock();

}

int main() {

    CriticalData c1;
    CriticalData c2;

    std::thread t1([&] {deadLock(c1, c2); });
    std::thread t2([&] {deadLock(c2, c1); });

    t1.join();
    t2.join();

}
#endif

// The solution to having deadlocks? 
// Use unique_locks with defer
#if 0
struct CriticalData {
    std::mutex mut;
};

void noDeadLock(CriticalData& a, CriticalData& b) {

    std::unique_lock<std::mutex>guard1(a.mut, std::defer_lock);
    std::cout << "Thread: " << std::this_thread::get_id() << " first mutex" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::unique_lock<std::mutex>guard2(b.mut, std::defer_lock);
    std::cout << "    Thread: " << std::this_thread::get_id() << " second mutex" << std::endl;

    std::cout << "        Thread: " << std::this_thread::get_id() << " get both mutex" << std::endl;
    
    // The lock operation is performed atomically by using the variadic template std::lock.
    // std::lock can take many parameters (uses variadic template)
    // std::lock tries to get the all locks in an atomic step. So, std::lock either fails or gets all of them.
    std::lock(guard1, guard2); 

    // do something with a and b
}

// An alternative way to the above method is to get the mutexes first, then use adopt_lock to take care of the scope and cleanup
void noDeadLock2(CriticalData& a, CriticalData& b) {
    std::lock(a.mut, b.mut);
    std::cout << "Thread: " << std::this_thread::get_id() << " get both mutexs" << std::endl;
    std::lock_guard<std::mutex> guard1(a.mut, std::adopt_lock);
    std::lock_guard<std::mutex> guard2(b.mut, std::adopt_lock);
    cout << "released" << endl;
}

int main() {

    std::cout << std::endl;

    CriticalData c1;
    CriticalData c2;

    /*std::thread t1([&] {noDeadLock(c1, c2); });
    std::thread t2([&] {noDeadLock(c2, c1); });*/
    std::thread t1([&] {noDeadLock2(c1, c2); });
    std::thread t2([&] {noDeadLock2(c2, c1); });

    t1.join();
    t2.join();

    std::cout << std::endl;

    system("pause");

}
#endif
#if 0
struct Box {
    explicit Box(int num) : num_things{ num } {}

    int num_things;
    std::mutex m;
};

void transfer(Box& from, Box& to, int num, int max)
{
    
    while (1) {
        {
            // don't actually take the locks yet
            std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
            std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

            // lock both unique_locks without deadlock
            std::lock(lock1, lock2);
            
            if (from.num_things < num) {
                cout << "insufficient funds " << endl;
                break;
            }
            if (to.num_things > max) {
                cout << "max limit reached " << endl;
                break;
            }
            
            from.num_things -= num;
            to.num_things += num;
            cout << std::this_thread::get_id() << " from " << from.num_things << endl;
            cout << std::this_thread::get_id() << " to " << to.num_things << endl;
            
            // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
        }
        this_thread::sleep_for(sec);
        
    }
}

int main()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10, 200);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5, 200);

    t1.join();
    t2.join();

    system("pause");
}
#endif