#ifndef DEFINE_HPP
#define DEFINE_HPP

// ENUMS

typedef enum e_colors {
  red = 0,
  dark_green = 1,
  gress_green = 2,
  yellow = 3,
  magenta = 4,
  blue = 5,
  white = 6,
  orange = 7,
  reset = 8
} t_colors;

typedef enum e_log_level {
  TEST = 0,
  WARNING = 1,
  ERROR = 2,
  NOTE = 3,
  EXCEPTION = 4
} t_log_level;

// NUMBER DEFINES

#define MIN_PRINTABLE 32
#define MAX_PRINTABLE 126

// MESSAGES
#define WRONG_ARGS                                                             \
  "Wrong number of arguments. Input one argument: ./scalaConverter 1Arg"
#define MIXED_INPUT                                                            \
  "Mixed Input: input number or chars, not both mixed together"
#define WRONG_SIGNS                                                            \
  "Wrong signs found: just one character or numbers with -/+ at the beginning "

#endif
