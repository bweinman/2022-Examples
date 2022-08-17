// bwprint.h by Bill Weinman <http://bw.org/>
// Copyright (c) 2021-22 BHG LLC
// This code is free and open source without restriction
// Please include attribution above
// updated 2022-08-16
//
// This code requires either the C++20 <format> library,
// or the libfmt library from <https://fmt.dev/>
//
// Once C++23 is released, along with std::print(), this code
// will become obsolete.
//
// NOTE BENE: It's generally considered extremely bad practice to add user
// code to the std namespace. In this case, I chose to violate that rule
// with the knowledge that this code will be obsoleted by equivalent
// functionality in C++23. At that time, the user may simply replace this
// #include with <print> and leave the rest of their code alone. I think
// that's a good case to violate the rule. If you disagree, simply change
// the BWP_NAMESPACE macro to bw or whatever name you prefer.

#ifndef BW_PRINT
#define BW_PRINT

#include <iostream>
#include <string_view>
#include <cstdio>
#include <format>

// namespace for print() is std or bw
// make this std if you dare

// #define BWP_NAMESPACE bw
#define BWP_NAMESPACE std

// print function is missing from c++20 format library
namespace BWP_NAMESPACE {

    using std::format;
    using std::formatter;
    using std::vformat;
    using std::make_format_args;

    constexpr const char * bwp_version = "1.0.17";

    // default to stdout
    // print(string_view format-string, args...)
    template<typename... Args>
    constexpr void print(const std::string_view& str_fmt, Args&&... args) {
        fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
    }

    // send to FILE*
    // print(FILE*, string_view format-string, args...)
    template<typename... Args>
    constexpr void print(FILE* fdest, const std::string_view& str_fmt, Args&&... args) {
        fputs(vformat(str_fmt, make_format_args(args...)).c_str(), fdest);
    }

    // send to ostream
    // print(ostream, string_view format-string, args...)
    template<typename... Args>
    constexpr void print(std::ostream& ostream_dest, const std::string_view& str_fmt, Args&&... args) {
        ostream_dest << vformat(str_fmt, make_format_args(args...));
    }

    // no parameter pack cstr
    // print(const char * str)
    void print(const char* str) {
        fputs(str, stdout);
    }

    // no parameter pack string_view
    // print(const string & str)
    void print(const std::string_view& str) {
        fputs(str.data(), stdout);
    }

    // no parameter pack string
    // print(const string & str)
    void print(const std::string& str) {
        fputs(str.c_str(), stdout);
    }
}

// using BWP_NAMESPACE::print;

#endif // BWPRINT
