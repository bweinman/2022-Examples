//  formatter.cpp
//  as of 2022-05-03 bw [bw.org]

#include <format>
#include <print>
#include <string_view>
#include <numbers>

using std::print;
using std::string_view;
using std::numbers::pi;

template<typename T>
struct Frac {
    T n;
    T d;
};

// format specialization for Frac<T>
template <typename T>
struct std::formatter<Frac<T>> : std::formatter<unsigned> {
    template <typename Context>
    auto format(const Frac<T>& f, Context& ctx) const {
        return format_to(ctx.out(), "{}/{}", f.n, f.d);
    }
};

int main() {
    const int inta {47};
    const char * human {"earthlings"};
    const string_view alien {"vulcans"};
    const double df_pi {pi};

    print("Hello {}\n", human);
    print("Hello {} we are {}\n", human, alien);
    print("Hello {1} we are {0}\n", human, alien);

    print("π is {}\n", df_pi);
    print("π is {:.5}\n", df_pi);
    print("inta is {1}, π is {0:.5}\n", df_pi, inta);

    print("inta is [{:*<10}]\n", inta);
    print("inta is [{:0>10}]\n", inta);
    print("inta is [{:^10}]\n", inta);
    print("inta is [{:_^10}]\n", inta);

    print("{:>8}: [{:04X}]\n", "Hex", inta);
    print("{:>8}: [{:4o}]\n", "Octal", inta);
    print("{:>8}: [{:4d}]\n", "Decimal", inta);

    Frac<long> n {3, 5};
    print("Frac: {}\n", n);
}
