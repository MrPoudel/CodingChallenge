//Taken from: https://www.quora.com/What-are-the-differences-between-C++11-and-C++14-C++17
C++14 adds to C++11:

Relaxed constexpr constraints (the most expensive C++14 feature to implement, in my case)
Generic lambdas (e.g., [](auto p) { return p*2; })
Init-capture (e.g., [i = 2](auto p) { return p+i++; })
Variable templates
decltype(auto)
Deduced return types
Binary literals (e.g., 0b11101100)
Digit separators (e.g., 0b1110'1100)
[[deprecated]] and [[deprecated("msg")]]
Extend “aggregate class type” to include a class that would be a C++11 aggregate type if default member initializers were omitted
C++17 adds to this:

if constexpr (...)
Structured binding declarations (e.g., auto [x, y] = f();)
Mandatory copy-elision through a reformulation of value categories
Inline variables (allowing multiple definitions across translation units)
Stronger order of evaluation guarantees
Fold expressions (e.g., (pack + … + 0))
Nested namespace definitions (e.g., namespace Outer::Inner {})
Trigraphs are gone (yay!)
Init-statements in if/if constexpr/switch (e.g., if (auto x = f(); !x.empty()) …)
Class template argument deduction (e.g., pair p = { true, 1.0 };)
Hexadecimal floating-point literals (e.g., 0x3.ABCp-10)
u8 character literals (e.g., u8'x')
Generalization of nontype template arguments (e.g., X<&s.s> where s.s denotes a static data member can now be valid)
Over-aligned allocation/deallocation functions (operator new(size_t, align_val_t) etc.)
Attributes on namespaces
Attributes on enumerator constants
[[nodiscard]], [[maybe_unused]], and [[fallthrough]]
typename is permitted for template template parameter declarations (e.g., template<template<typename> typename X> struct …)
static_assert no longer requires a second (string literal) operand.
Tweak to the rules for deducing auto with a braced initializer
__has_include
