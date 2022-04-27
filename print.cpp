//  print.cpp
//  as of 2022-04-21 bw [bw.org]
#include <format>
#include <print>

using std::print;

class I {
    int i_{};
public:
    I(const int& i) : i_{i} {}
    const int value() const { return i_; }
};

template <>
struct std::formatter<I>: std::formatter<unsigned> {
    template<typename FormatContext>
    auto format(const I& o, FormatContext& ctx) {
        return format_to(ctx.out(), "{}", o.value());
    }
};

int main() {
    int everything {42};
    print("the number is {}\n", everything);
    
    const I foo {73};
    print("the I is {}\n", foo);
}
