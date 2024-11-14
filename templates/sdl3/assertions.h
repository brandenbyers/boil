#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

// Helper macro for generic comparison assertions
#define _c_assert_compare(expected, actual, op, fmt) \
  ((expected)op(actual) ? (true) : (assertion_failed_fmt(__FILE__, __LINE__, #expected, #actual, #op, fmt, expected, actual), false))

// Integer comparisons (signed)
#define c_assert_int_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%d")
#define c_assert_int_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%d")
#define c_assert_int_lt(expected, actual) _c_assert_compare(expected, actual, <, "%d")
#define c_assert_int_le(expected, actual) _c_assert_compare(expected, actual, <=, "%d")
#define c_assert_int_gt(expected, actual) _c_assert_compare(expected, actual, >, "%d")
#define c_assert_int_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%d")

// Integer comparisons (unsigned)
#define c_assert_uint_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%u")
#define c_assert_uint_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%u")
#define c_assert_uint_lt(expected, actual) _c_assert_compare(expected, actual, <, "%u")
#define c_assert_uint_le(expected, actual) _c_assert_compare(expected, actual, <=, "%u")
#define c_assert_uint_gt(expected, actual) _c_assert_compare(expected, actual, >, "%u")
#define c_assert_uint_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%u")

// Long integer comparisons (signed)
#define c_assert_long_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%ld")
#define c_assert_long_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%ld")
#define c_assert_long_lt(expected, actual) _c_assert_compare(expected, actual, <, "%ld")
#define c_assert_long_le(expected, actual) _c_assert_compare(expected, actual, <=, "%ld")
#define c_assert_long_gt(expected, actual) _c_assert_compare(expected, actual, >, "%ld")
#define c_assert_long_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%ld")

// Long integer comparisons (unsigned)
#define c_assert_ulong_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%lu")
#define c_assert_ulong_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%lu")
#define c_assert_ulong_lt(expected, actual) _c_assert_compare(expected, actual, <, "%lu")
#define c_assert_ulong_le(expected, actual) _c_assert_compare(expected, actual, <=, "%lu")
#define c_assert_ulong_gt(expected, actual) _c_assert_compare(expected, actual, >, "%lu")
#define c_assert_ulong_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%lu")

// Long long integer comparisons (signed)
#define c_assert_llong_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%lld")
#define c_assert_llong_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%lld")
#define c_assert_llong_lt(expected, actual) _c_assert_compare(expected, actual, <, "%lld")
#define c_assert_llong_le(expected, actual) _c_assert_compare(expected, actual, <=, "%lld")
#define c_assert_llong_gt(expected, actual) _c_assert_compare(expected, actual, >, "%lld")
#define c_assert_llong_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%lld")

// Long long integer comparisons (unsigned)
#define c_assert_ullong_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%llu")
#define c_assert_ullong_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%llu")
#define c_assert_ullong_lt(expected, actual) _c_assert_compare(expected, actual, <, "%llu")
#define c_assert_ullong_le(expected, actual) _c_assert_compare(expected, actual, <=, "%llu")
#define c_assert_ullong_gt(expected, actual) _c_assert_compare(expected, actual, >, "%llu")
#define c_assert_ullong_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%llu")

// Size_t comparisons
#define c_assert_size_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%zu")
#define c_assert_size_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%zu")
#define c_assert_size_lt(expected, actual) _c_assert_compare(expected, actual, <, "%zu")
#define c_assert_size_le(expected, actual) _c_assert_compare(expected, actual, <=, "%zu")
#define c_assert_size_gt(expected, actual) _c_assert_compare(expected, actual, >, "%zu")
#define c_assert_size_ge(expected, actual) _c_assert_compare(expected, actual, >=, "%zu")

// Floating point comparisons (with epsilon)
#define c_assert_float_eq(expected, actual, epsilon) \
  (fabs((expected) - (actual)) <= (epsilon) ? (true) : (assertion_failed_float(__FILE__, __LINE__, #expected, #actual, expected, actual, epsilon), false))

#define c_assert_double_eq(expected, actual, epsilon) \
  (fabs((expected) - (actual)) <= (epsilon) ? (true) : (assertion_failed_double(__FILE__, __LINE__, #expected, #actual, expected, actual, epsilon), false))

// Pointer comparisons
#define c_assert_ptr_eq(expected, actual) _c_assert_compare(expected, actual, ==, "%p")
#define c_assert_ptr_ne(expected, actual) _c_assert_compare(expected, actual, !=, "%p")
#define c_assert_ptr_null(ptr) _c_assert_compare(ptr, NULL, ==, "%p")
#define c_assert_ptr_not_null(ptr) _c_assert_compare(ptr, NULL, !=, "%p")

// String comparisons
#define c_assert_str_eq(expected, actual) \
  (strcmp(expected, actual) == 0 ? (true) : (assertion_failed_str(__FILE__, __LINE__, #expected, #actual, expected, actual), false))

#define c_assert_str_ne(expected, actual) \
  (strcmp(expected, actual) != 0 ? (true) : (assertion_failed_str(__FILE__, __LINE__, #expected, #actual, expected, actual), false))

#define c_assert_strn_eq(expected, actual, n) \
  (strncmp(expected, actual, n) == 0 ? (true) : (assertion_failed_strn(__FILE__, __LINE__, #expected, #actual, expected, actual, n), false))

// Bitwise operations
#define c_assert_bits_set(value, mask) \
  (((value) & (mask)) == (mask) ? (true) : (assertion_failed_bits(__FILE__, __LINE__, #value, #mask, value, mask, "set"), false))

#define c_assert_bits_clear(value, mask) \
  (((value) & (mask)) == 0 ? (true) : (assertion_failed_bits(__FILE__, __LINE__, #value, #mask, value, mask, "clear"), false))

#define c_assert_bits_any_set(value, mask) \
  (((value) & (mask)) != 0 ? (true) : (assertion_failed_bits(__FILE__, __LINE__, #value, #mask, value, mask, "any set"), false))

#define c_assert_bits_any_clear(value, mask) \
  (((value) & (mask)) != (mask) ? (true) : (assertion_failed_bits(__FILE__, __LINE__, #value, #mask, value, mask, "any clear"), false))

// Range comparisons
#define c_assert_in_range(value, min, max) \
  (((value) >= (min) && (value) <= (max)) ? (true) : (assertion_failed_range(__FILE__, __LINE__, #value, value, min, max), false))

#define c_assert_not_in_range(value, min, max) \
  (((value) < (min) || (value) > (max)) ? (true) : (assertion_failed_not_range(__FILE__, __LINE__, #value, value, min, max), false))

// Boolean assertions
#define c_assert_true(value) _c_assert_compare(value, true, ==, "%d")
#define c_assert_false(value) _c_assert_compare(value, false, ==, "%d")

// Implementation functions
static inline void assertion_failed_fmt(const char *file, int line,
                                        const char *expected_expr, const char *actual_expr,
                                        const char *op, const char *fmt,
                                        long long expected, long long actual)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected: %s %s %s\n", expected_expr, op, actual_expr);
  fprintf(stderr, "Values  : ");
  fprintf(stderr, fmt, expected);
  fprintf(stderr, " %s ", op);
  fprintf(stderr, fmt, actual);
  fprintf(stderr, "\n");
  exit(1);
}

static inline void assertion_failed_float(const char *file, int line,
                                          const char *expected_expr, const char *actual_expr,
                                          float expected, float actual, float epsilon)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected: %s == %s (within %g)\n", expected_expr, actual_expr, epsilon);
  fprintf(stderr, "Values  : %g != %g (diff: %g)\n", expected, actual, fabs(expected - actual));
  exit(1);
}

static inline void assertion_failed_double(const char *file, int line,
                                           const char *expected_expr, const char *actual_expr,
                                           double expected, double actual, double epsilon)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected: %s == %s (within %g)\n", expected_expr, actual_expr, epsilon);
  fprintf(stderr, "Values  : %g != %g (diff: %g)\n", expected, actual, fabs(expected - actual));
  exit(1);
}

static inline void assertion_failed_str(const char *file, int line,
                                        const char *expected_expr, const char *actual_expr,
                                        const char *expected, const char *actual)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected: %s = \"%s\"\n", expected_expr, expected);
  fprintf(stderr, "Actual  : %s = \"%s\"\n", actual_expr, actual);
  exit(1);
}

static inline void assertion_failed_strn(const char *file, int line,
                                         const char *expected_expr, const char *actual_expr,
                                         const char *expected, const char *actual, size_t n)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected first %zu chars: %s = \"%.*s\"\n", n, expected_expr, (int)n, expected);
  fprintf(stderr, "Actual first %zu chars  : %s = \"%.*s\"\n", n, actual_expr, (int)n, actual);
  exit(1);
}

static inline void assertion_failed_bits(const char *file, int line,
                                         const char *value_expr, const char *mask_expr,
                                         unsigned long long value, unsigned long long mask,
                                         const char *expected_state)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected bits to be %s\n", expected_state);
  fprintf(stderr, "Value: %s = 0x%llx\n", value_expr, value);
  fprintf(stderr, "Mask : %s = 0x%llx\n", mask_expr, mask);
  fprintf(stderr, "Bits : 0x%llx\n", value & mask);
  exit(1);
}

static inline void assertion_failed_range(const char *file, int line,
                                          const char *value_expr,
                                          long long value, long long min, long long max)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected %s to be in range [%lld, %lld]\n", value_expr, min, max);
  fprintf(stderr, "Actual value: %lld\n", value);
  exit(1);
}

static inline void assertion_failed_not_range(const char *file, int line,
                                              const char *value_expr,
                                              long long value, long long min, long long max)
{
  fprintf(stderr, "Assertion failed: %s:%d\n", file, line);
  fprintf(stderr, "Expected %s to be outside range [%lld, %lld]\n", value_expr, min, max);
  fprintf(stderr, "Actual value: %lld\n", value);
  exit(1);
}

#endif // ASSERTIONS_H
