WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#ifndef CPP101_FOLD_HPP
#define CPP101_FOLD_HPP

#include <vector>

/**
 * A named namespace
 *
 * New in C++, namespaces are the primary mechanism by which we modularise our code declarations and definitions.
 * You can place anything inside of a namespace and it will always be referred to as
 * <namespace name>::<the thing>.
 * This :: (pronounced colon-colon) is called the "scope" operator, as a namespace creates a new lexical scope.
 *
 * We will be using them extensively in this course.
 *
 * There is also something known as an "anonymous namespace", which you can read about in src/main.cpp.
 */
namespace cpp101 {
    /**
     * These are "using declarations".
     * They are the C++ way of doing type aliases (typedefs).
     * Their primary benefit is that they read left-to-right and are subject to scoping rules.
     * e.g. you can use them in functions to quickly shorten a type name and that alias will only be valid
     * in that function scope.
     */
    using OpFnI = int(*)(int, int);

    /**
     * These specific type aliases are to function pointers.
     * As the name implies, a function pointer is a pointer to a function that can be called with ().
     * Their format is <return_type>(*fn_ptr_name)(<param_type>p1).
     * Note: when used in type aliases, you do not need to name the function pointer.
     *
     * Therefore, OpFnD is a pointer to a function that takes in 2 doubles and returns a double.
     */
    using OpFnD = double(*)(double, double);

    /**
     * nums has the peculiar "&" type...
     * No, this is not the address-of operator, this is known as a C++ reference.
     * References are exactly the same as pointers with only 2 exceptions:
     * - references cannot be rebound.
     *   this implies they also must be initialised.
     *   e.g. int &j; is illegal, but
     *        int i = 0; int &j = i; is not.
     *        int &j = nullptr or int &j = null; is also illegal (there is no "null reference" in C++)
     * - references are automatically dereferenced for you.
     *
     *   if you have an object, you can simply access its member functions via the . operator just like in Java
     */
    int fold(const std::vector<int> &nums);
    int fold(const std::vector<int> &nums, OpFnI operation, int init);


    /**
     * These are examples of static polymorphism via function overloading.
     * In C++ and not in C, you can have different functions which all have the same name.
     * The only requirement is that:
     * - there are differing number of parameters; or
     * - at least 1 parameter has a different type.
     *
     * For reference types (pointers and references), a:
     * - const char * and char * are considered separate, as is const char& and char&
     * - However, char * const is the same as char *, as the const in the former relates to the constness of a
     * local variable, which the compiler does not care about (local variable constness only affects the
     * implementation, not the interface. The compiler only uses the interface to resolve an overloaded function call).
     *
     * To read more about this weird constness, google "top vs. bottom level const c++"
     */
    double fold(const std::vector<double> &nums);
    double fold(const std::vector<double> &nums, OpFnD operation, double init);

}

#endif