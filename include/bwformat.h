// bwformat.h by Bill Weinman <http://bw.org/>
// Copyright (c) 2021-22 BHG LLC
// This code is free and open source without restriction
// Please include attribution above
// updated 2022-04-26
//
// This header emulates the <format> header in C++20
//
// NOTE BENE: It's generally considered extremely bad practice to add user
// code to the std namespace. In this case, I chose to violate that rule
// with the knowledge that this code will be obsoleted by an equivalent
// header in C++2x. At that time, the user may simply replace this
// #include with <format> and leave the rest of their code alone. I think
// that's a good case to violate the rule. If you disagree, simply change
// the BWP_NAMESPACE macro to bw or whatever name you prefer.

#ifndef BW_FORMAT
#define BW_FORMAT

#include <version>

#ifdef __cpp_lib_format
#   error "use the std format lib"
#elif __has_include(<fmt/core.h>)
#   include <fmt/core.h>
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wdeprecated-declarations"
#       include <fmt/chrono.h>
#   pragma clang diagnostic pop
#   define BWP_FMT_LIB "libfmt"
#   define BWP_FMTNS fmt
#else
#   error "no format lib"
#endif // __cpp_lib_format

#ifdef BWP_FMT_LIB

#ifndef __cpp_lib_format

// to properly emulate <format> these must be in std namespace
namespace std {
    using BWP_FMTNS::format;
    using BWP_FMTNS::formatter;
    using BWP_FMTNS::vformat;
    using BWP_FMTNS::make_format_args;
}

#endif // __cpp_lib_format
#endif // BWP_FMT_LIB
#endif // BWFORMAT
