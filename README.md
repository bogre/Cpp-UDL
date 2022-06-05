# Cpp-UDL
## C++ User defined literals with examples
### Introduction
With c++20 standard, we can use literals in a forms shown in main.cpp, with Token
class, or with suffix _S UDL. Those are kinds of so-called COOKED UDLs and they could
have all in all, at most 12 overloads, for unsigned long long, long double, plus 10
overloads for different character types with size, like we can see in _S litteral
operator function.
We can't have signed UDLs, e.g. minus, "-" sign is not allowed in
'auto t3 = -1.22_tok //compilation error',
basically we are trying to use undefined unary minus operator for a type Token,
from an example in main.cpp


