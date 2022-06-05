#include <iostream>
#include <string>
namespace tok
{
struct Token {
    constexpr Token(uint32_t v) : _value{v} {}

   private:
    uint32_t _value;
    friend auto& operator<<(auto& str, const Token& t);
};
consteval Token operator""_tok(long long unsigned value) { return Token(value); }
constexpr Token operator""_tok(long double value){ return value>0 ? 1:2; }

auto& operator<<(auto& stream, const Token& token) { return stream << token._value; }
}  // namespace tok
std::string operator""_S(char8_t const * str, [[maybe_unused]] std::size_t size) {
    return {reinterpret_cast<const char*>(str),size};
}
std::string operator""_S(char const * str, [[maybe_unused]] std::size_t size) {
    return {str,str+size};
}
int main(int, char**)
{
    using namespace tok;

    constexpr auto t1 = 1'042_tok;
    std::cout << "token1: " << t1 << "\n";
    constexpr auto t2 = 1042.2_tok;
    std::cout << "token2: " << t2 << "\n";

    auto s1 = u8"Hi \U0001F600"_S;
    auto s2 = "Hi \U0001F600"_S;
    std::cout << s1 << "\n";
    std::cout << s2 << "\n";
    return 0;
}
