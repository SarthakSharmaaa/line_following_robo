/* --- Generated the 5/5/2024 at 23:41 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 11:24:39 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Line_follower__St_2_White,
  Line_follower__St_2_Black
} Line_follower__st_2;

Line_follower__st_2 Line_follower__st_2_of_string(char* s);

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf);

typedef enum {
  Line_follower__St_1_Straight2,
  Line_follower__St_1_Straight1,
  Line_follower__St_1_Straight,
  Line_follower__St_1_StopTemp,
  Line_follower__St_1_DoParking
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_Startpark,
  Line_follower__St_Reset,
  Line_follower__St_Parkright,
  Line_follower__St_Parkleft,
  Line_follower__St_Parked,
  Line_follower__St_Inter,
  Line_follower__St_Check
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const int Line_follower__kp = 1;

static const int Line_follower__ki = 100;

static const int Line_follower__kd = 10000;

#endif // LINE_FOLLOWER_TYPES_H
