WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
/**
 * The C++ version of the C library header stdlib.h.
 * The general way to convert between the C version and the C++ version is to drop the ".h" part
 * and also to prepend "c" to the start
 */
#include <cstdlib>

/**
 * C++-specific standard library headers
 *
 * iostream - contains declarations and types for outputting to std::cout and std::cerr with
 * operator<< (known as the output stream operator).
 * See main() for an example
 *
 * string - contains the definition of std::string
 * Note: a std::string is NOT a const char *, but contains member functions .data() and .c_str()
 * which return a const char *.
 * These are VIEWS and not copies -- the original std::string object must be alive and valid to use these.
 *
 * vector - contains the definition of std::vector.
 * This is a dynamic array implementation. Basically a pointer and a size bundled as one.
 *
 * array - a C++ typesafe wrapper around a C-style array.
 * Behaves exactly like a regular array with the addition of being able to use it in
 * for(const elem_type &e : arr)-style ranged for-loops.
 */
#include <iostream>
#include <string>
#include <vector>
#include <array>

/**
 * Our header file for this activity
 */
#include <cpp101/fold.hpp>

/**
 * An anonymous namespace.
 * See cpp101/fold.hpp for a more general discussion of namespaces
 *
 * The main peculiarities of an anonymous namespace are:
 * - Things inside the anon. namespace can only be referenced inside this .cpp file
 * - Everything inside the anon. namespace has internal aka. static linkage. This means that other .cpp files
 * cannot use what's inside here.
 * Exactly equivalent to static helper functions from C.
 * Don't need to use :: to access what's in here.
 */
namespace {
    int plus(int lhs, int rhs) {
        return lhs + rhs;
    }

    double plus(double lhs, double rhs) {
        return lhs + rhs;
    }

    int mult(int lhs, int rhs) {
        return lhs * rhs;
    }

    double mult(double lhs, double rhs) {
        return lhs * rhs;
    }
}

/**
 *
 * Notice the implementation of a function within a namespace has the name of the function fully qualified with the
 * namespace name.
 *
 * You can also define the function in namespace-scope like so:
 *
 * namespace cpp101 {
 *      int fold(const std::vector<int> &nums) {
 *         // impl
*       }
 * }
 *
 * and this allows you to leave off the namespace qualification.
 *
 * @param nums: a vector of numbers to be folded
 * @return the folded number.
 */
int cpp101::fold(const std::vector<int> &nums) {
    return fold(nums, plus, 0);
}

/**
 *
 * Same as above but more general.
 *
 * Notice here that even elements from the namespace must be fully qualified if not inside namespace-scope
 * i.e. OpFnI must be cpp101::OpFnI.
 *
 * Again, to leave this off, just enter namespace scope. The compiler merges all declarations and definitions before
 * the linker glues everything together.
 *
 * @param nums
 * @param operation
 * @param init
 * @return
 */
int cpp101::fold(const std::vector<int> &nums, cpp101::OpFnI operation, int init) {
    /**
     * This is a ranged for-loop
     * It was introduced in the C++11 standard revision, and can be used with all standard library containers, namely:
     * vector -> returns each element
     * string -> returns chars
     * array -> same as vector
     * deque (double-ended queue) -> same as vector
     * list (a doubly-linked-list) -> same as vector
     * etc.
     *
     * The full list of std containers can be found on cppreference.com.
     *
     * You'll probably only need vector, string, and array.
     */
    for (const int &num : nums) {
        init = operation(init, num);
    }

    return init;
}

double cpp101::fold(const std::vector<double> &nums) {
    return fold(nums, plus, 0.0);
}

double cpp101::fold(const std::vector<double> &nums, cpp101::OpFnD operation, double init) {
    /**
     * C-style for-loops still work too!
     *
     * Unlike COMP6771, you are free to use whatever kind of for-loop you want.
     */
    for (int i = 0; i < nums.size(); ++i) {
        init = operation(init, nums[i]);
    }

    return init;
}

int main() {
    const std::vector<int> int_list = {2, 2, 3};
    const std::vector<double> double_list = {3.5, 2.0, 1.0};

    /**
     * Another small difference from C : nullptr.
     *
     * Exactly the same as NULL.
     * Probably...
     * - #define NULL (void *)0;
     * - void *nullptr = NULL;
     *
     * exists somewhere in the standard library.
     * Note: you cannot redefine nullptr as it is a keyword.
     *
     */
    int *ptr = nullptr;

    /**
     * The C++ compiler is smart enough that it can do overload resolution not only on straight function calls...
     * ... but also in passing function pointers around too!
     *
     * In practice, you'll hardly ever do this (and for this course you never will have to), but it is one of the things
     * to be aware of.
     */
    const int fold1 = cpp101::fold(int_list, mult, 1);
    const double fold2 = cpp101::fold(double_list, mult, 1.0);

    /**
     * std::cout, std::cerr, and less importantly, std::cin are standard streams.
     * The way to use them is as below:
     * - use the << operator to output things
     * there are automatic conversions for all the fundamental types (int, char, bool, etc) and also std::string.
     * Newlines can either be a literal newline "\n" or the special std::endl.
     * std::endl only differs in that it forces a flush of the write-buffer, meaning it is not thread-safe.
     *
     * Use cout for non-errors, cerr for errors.
     */
    std::cout << "int: " << fold1 << "\n";
    std::cout << "double: " << fold2 << "\n";
    std::cout << ptr << std::endl;

    /**
     * macros for successful program execution and otherwise haven't changed from COMP1511
     */
    return EXIT_SUCCESS;
}