#include "pch.h"


// std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object 
// when the unique_ptr goes out of scope.

// The object is disposed of, using the associated deleter when either of the following happens :
// - the managing unique_ptr object is destroyed
// - the managing unique_ptr object is assigned another pointer via operator= or reset().
// - The object is disposed of, using a potentially user-supplied deleter by calling get_deleter()(ptr).
// The default deleter uses the delete operator, which destroys the objectand deallocates the memory.
// A unique_ptr may alternatively own no object, in which case it is called empty.

// There are two versions of std::unique_ptr:

// 1) Manages a single object(e.g.allocated with new)
// 2) Manages a dynamically-allocated array of objects(e.g.allocated with new[])
// The class satisfies the requirements of MoveConstructible and MoveAssignable, but not the requirements of CopyConstructible nor CopyAssignable.
// Type requirements
// - Deleter must be FunctionObject or lvalue reference to a FunctionObject or lvalue reference to function, callable with an argument of type unique_ptr<T, Deleter>::pointer

// Only non-const unique_ptr can transfer the ownership of the managed object to another unique_ptr.
// If an object's lifetime is managed by a const std::unique_ptr, it is limited to the scope in which the pointer was created.

// std::unique_ptr is commonly used to manage the lifetime of objects, including:
// - providing exception safety to classes and functions that handle objects with dynamic lifetime, by guaranteeing deletion on both normal exit and exit through exception
// - passing ownership of uniquely-owned objects with dynamic lifetime into functions
// - acquiring ownership of uniquely-owned objects with dynamic lifetime from functions
// - as the element type in move-aware containers, such as std::vector, which hold pointers to dynamically - allocated objects(e.g. if polymorphic behavior is desired)

// std::unique_ptr may be constructed for an incomplete type T, such as to facilitate the use as a handle in the pImpl idiom.
// ---- "Pointer to implementation" or "pImpl" is a C++ programming technique that removes implementation details of a class 
// ---- from its object representation by placing them in a separate class, accessed through an opaque pointer
// If the default deleter is used, T must be complete at the point in code where the deleter is invoked, 
// which happens in the destructor, move assignment operator,and reset member function of std::unique_ptr. 
// (Conversely, std::shared_ptr can't be constructed from a raw pointer to incomplete type, but can be destroyed where T is incomplete). 
// Note that if T is a class template specialization, use of unique_ptr as an operand, e.g. !p requires T's parameters to be complete due to ADL.

// If T is a derived class of some base B, then std::unique_ptr<T> is implicitly convertible to std::unique_ptr<B>.The default deleter of the resulting std::unique_ptr<B> will use operator delete for B, leading to undefined behavior unless the destructor of B is virtual.Note that std::shared_ptr behaves differently : std::shared_ptr<B> will use the operator delete for the type Tand the owned object will be deleted correctly even if the destructor of B is not virtual.

// Unlike std::shared_ptr, std::unique_ptr may manage an object through any custom handle type that satisfies NullablePointer.
// This allows, for example, managing objects located in shared memory, by supplying a Deleter that defines typedef boost::offset_ptr pointer; 
// or another fancy pointer.


#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct B {
    virtual void bar() { 
        std::cout << "B::bar()\n"; 
    }
    virtual ~B() = default;
};

struct D : B
{
    D() { 
        std::cout << "D is created\n"; 
    }
    ~D() { 
        std::cout << "D is destroyed\n"; 
    }
    void bar() override { 
        std::cout << "D::bar()\n"; 
    }
};

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(std::FILE* fp) { 
    std::fclose(fp); 
}
#if 0
int main()
{
    std::cout << "unique ownership semantics demo\n";
    {
        // p is a unique_ptr that owns a D
        auto p = std::make_unique<D>(); 
        auto q = pass_through(std::move(p)); // move semantics, ownership transferred from p to q
        assert(!p); // now p owns nothing and holds a null pointer
        q->bar();   // and q owns the D object
    } // ~D called here

    std::cout << "Runtime polymorphism demo\n";
    {
        std::unique_ptr<B> p = std::make_unique<D>(); // p is a unique_ptr that owns a D
                                                      // as a pointer to base
        p->bar(); // virtual dispatch

        // unique_ptr can be stored in a container
        std::vector<std::unique_ptr<B>> v;   // create a vector of pointers to B
        v.push_back(std::make_unique<D>());  // v now contains one instance of D
        v.push_back(std::move(p));           // v now contains 2 elements: D, B
        v.emplace_back(new D);               // v now contains 3 elements: D, B, D
        for (auto& p : v) {
            p->bar(); // virtual dispatch
        }
    } // ~D called 3 times
    system("pause");
    std::cout << "Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"),
            &close_file);
        if (fp) // fopen could have failed; in which case fp holds a null pointer
            std::cout << (char)std::fgetc(fp.get()) << '\n';
    } // fclose() called here, but only if FILE* is not a null pointer
      // (that is, if fopen succeeded)

    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
        {
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });  // p owns D
        p->bar();
    } // the lambda above is called and D is destroyed

    std::cout << "Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p{ new D[3] };
    } // calls ~D 3 times

    system("pause");
}
#endif

// std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
// Several shared_ptr objects may own the same object.
// The object is destroyed and its memory deallocated when either of the following happens :
// - the last remaining shared_ptr owning the object is destroyed;
// - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().
// - The object is destroyed using delete - expression or a custom deleter that is supplied to shared_ptr during construction.

// A shared_ptr can share ownership of an object while storing a pointer to another object.
// This feature can be used to point to member objects while owning the object they belong to.
// The stored pointer is the one accessed by get(), the dereference and the comparison operators.
// The managed pointer is the one passed to the deleter when use count reaches zero.

// A shared_ptr may also own no objects, in which case it is called empty
// --- (an empty shared_ptr may have a non-null stored pointer if the aliasing constructor was used to create it).

// All specializations of shared_ptr meet the requirements of CopyConstructible, CopyAssignable, and LessThanComparable and
// are contextually convertible to bool.

// All member functions(including copy constructor and copy assignment) can be called by multiple threads on different instances of 
// shared_ptr without additional synchronization even if these instances are copies and share ownership of the same object.
// If multiple threads of execution access the same shared_ptr without synchronizationand any of those accesses uses a non-const member function 
// of shared_ptr then a data race will occur; the shared_ptr overloads of atomic functions can be used to prevent the data race.


// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
struct MediaAsset
{
    virtual ~MediaAsset() {
        cout << "Media asset destroyed " << endl;
    }
};

struct Song : public MediaAsset
{
    std::string artist;
    std::string title;
    Song(const std::string& artist_, const std::string& title_) :
        artist{ artist_ }, title{ title_ } {
        cout << "Song created " << endl;
    }
    void print() {
        cout << "Song " << title << " by " << artist << endl;
    }
};

struct Photo : public MediaAsset
{
    std::string date;
    std::string location;
    std::string subject;
    Photo(
        const std::string& date_,
        const std::string& location_,
        const std::string& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {
        cout << "Photo created " << endl; }

    void print() {
        cout << subject << " photo taken at " << location << " on " << date << endl;
    }
};

using namespace std;

#if 0
int main()
{
    {
        // Example 0 using raw pointers
        Song* rp = new Song("Muse", "The Explorers");
        rp->print();
        delete rp; // manual deletion - easy to leak memory
    }
    {
        // Example 1 create 3 media assets using shared pointer

        // Use make_shared function when possible <-- *** this is the best way****
        auto sp1 = make_shared<Song>("The Beatles", "Im Happy Just to Dance With You");

        // Ok, but slightly less efficient. 
        // Note: Using new expression as constructor argument
        // creates no named variable for other code to access.
        shared_ptr<Song> sp2(new Song("Lady Gaga", "Just Dance"));

        // When initialization must be separate from declaration, e.g. class members, 
        // initialize with nullptr to make your programming intent explicit.
        shared_ptr<Song> sp5(nullptr);
        //Equivalent to: shared_ptr<Song> sp5;
        sp5 = make_shared<Song>("Elton John", "I'm Still Standing");

        sp1->print();
        sp2->print();
        sp5->print();
        cout << "sp1 " << sp1.use_count() << endl;
        cout << "sp2 " << sp2.use_count() << endl;
        cout << "sp5 " << sp5.use_count() << endl;

        cout << "-----------------------------------------------------" << endl;
        
        // Example 2 copying and assigning to other shared pointer without creating new entities

        //Initialize with copy constructor. Increments ref count.
        auto sp3(sp2);

        //Initialize via assignment. Increments ref count.
        auto sp4 = sp2;

        //Initialize with nullptr. sp7 is empty.
        shared_ptr<Song> sp7(nullptr);

        // Initialize with another shared_ptr. sp1 and sp2
        // swap pointers as well as ref counts.
        sp1.swap(sp2);
        sp1->print();
        sp2->print();
        sp3->print();
        sp4->print();
        sp5->print();

        cout << "sp1 " << sp1.use_count() << endl;
        cout << "sp2 " << sp2.use_count() << endl;
        cout << "sp3 " << sp3.use_count() << endl;
        cout << "sp4 " << sp4.use_count() << endl;
        cout << "sp5 " << sp5.use_count() << endl;


    } // the 3 media assets created are destroyed here at end of scope
    cout << "-----------------------------------------------------" << endl;
    // Example 3

    vector<shared_ptr<Song>> v{
        make_shared<Song>("Bob Dylan", "The Times They Are A Changing"),
        make_shared<Song>("Aretha Franklin", "Bridge Over Troubled Water"),
        make_shared<Song>("Thalia", "Entre El Mar y Una Estrella")
    };

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
    {
        return s->artist.compare("Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        s->print();
    }


    // Example 4

    // You can use dynamic_pointer_cast, static_pointer_cast, and const_pointer_cast to cast a shared_ptr.
    // These functions resemble the dynamic_cast, static_cast, and const_cast operators.
    // The following example shows how to test the derived type of each element in a vector of shared_ptr of base classes, 
    // and then copy the elementsand display information about them.

    vector<shared_ptr<MediaAsset>> assets{
      make_shared<Song>("Himesh Reshammiya", "Tera Surroor"),
      make_shared<Song>("Penaz Masani", "Tu Dil De De"),
      make_shared<Photo>("2011-04-06", "Redmond, WA", "Soccer field at Microsoft.")
    };

    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [](shared_ptr<MediaAsset> p) -> bool
    {
        // Use dynamic_pointer_cast to test whether
        // element is a shared_ptr<Photo>.
        shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
        return temp.get() != nullptr;
    });

    for (const auto& p : photos)
    {
        // We know that the photos vector contains only 
        // shared_ptr<Photo> objects, so use static_cast.
        cout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }


    // Example 5
    // You can pass a shared_ptr to another function in the following ways :

    // 1) Pass the shared_ptr by value.
    // -- This invokes the copy constructor, increments the reference count, and makes the callee an owner.
    //    There's a small amount of overhead in this operation, which may be significant depending on how many shared_ptr objects you're passing.
    //    Use this option when the implied or explicit code contract between the caller and callee requires that the callee be an owner.

    // 2) Pass the shared_ptr by reference or const reference.
    // -- In this case, the reference count isn't incremented, and the callee can access the pointer as long as the caller doesn't go out of scope.
    //    Or, the callee can decide to create a shared_ptr based on the reference, and become a shared owner.
    //    Use this option when the caller has no knowledge of the callee, or when you must pass a shared_ptr and want to avoid the copy operation 
    //    for performance reasons.

    // 3) Pass the underlying pointer or a reference to the underlying object.
    // -- This enables the callee to use the object, but doesn't enable it to share ownership or extend the lifetime. 
    //    If the callee creates a shared_ptr from the raw pointer, the new shared_ptr is independent from the original, and doesn't control 
    //    the underlying resource.
    //    Use this option when the contract between the caller and callee clearly specifies that the caller retains ownership of the shared_ptr lifetime.

    // When you're deciding how to pass a shared_ptr, 
    // 1) determine whether the callee has to share ownership of the underlying resource
    // -- An "owner" is an object or function that can keep the underlying resource alive for as long as it needs it. 
    // -- If the caller has to guarantee that the callee can extend the life of the pointer beyond its (the function's) lifetime, use the 1st option.
    // -- If you don't care whether the callee extends the lifetime, then pass by reference and let the callee copy it or not.

    // 2) If you have to give a helper function access to the underlying pointer, and you know that the helper function will just use the pointer
    // and return before the calling function returns, then that function doesn't have to share ownership of the underlying pointer. 
    // -- It just has to access the pointer within the lifetime of the caller's shared_ptr.
    // -- In this case, it's safe to pass the shared_ptr by reference, or pass the raw pointer or a reference to the underlying object. 
    // -- Passing this way provides a small performance benefit, and may also help you express your programming intent.

    // Sometimes, for example in a std::vector<shared_ptr<T>>, you may have to pass each shared_ptr to a lambda expression body or named 
    // function object. If the lambda or function doesn't store the pointer, then pass the shared_ptr by reference to avoid invoking the copy 
    // constructor for each element.

    // In general, pass by reference unless you need to make a copy and keep the object alive
    
    // Initialize two separate raw pointers.
    // Note that they contain the same values.
    auto song1 = new Song("Village People", "YMCA");
    auto song2 = new Song("Village People", "YMCA");

    // Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    // Unrelated shared_ptrs are never equal.
    cout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    cout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;

    // Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    cout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;

    // Example 6

    system("pause");
}

#endif