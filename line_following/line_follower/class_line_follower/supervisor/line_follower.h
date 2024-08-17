/* --- Generated the 5/5/2024 at 23:41 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 11:24:39 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__pid_mem {
  long v_6;
  long v_5;
  long v_3;
  long v_2;
} Line_follower__pid_mem;

typedef struct Line_follower__pid_out {
  long v_l;
  long v_r;
} Line_follower__pid_out;

void Line_follower__pid_reset(Line_follower__pid_mem* self);

void Line_follower__pid_step(long sen0, long sen1, long sen2, long sen3,
                             long sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self);

typedef struct Line_follower__cpid_mem {
  long v_22;
  long v_21;
  long v_19;
  long v_18;
} Line_follower__cpid_mem;

typedef struct Line_follower__cpid_out {
  long pid;
} Line_follower__cpid_out;

void Line_follower__cpid_reset(Line_follower__cpid_mem* self);

void Line_follower__cpid_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__cpid_out* _out,
                              Line_follower__cpid_mem* self);

typedef struct Line_follower__left_mem {
  Line_follower__cpid_mem cpid;
  Line_follower__cpid_mem cpid_1;
} Line_follower__left_mem;

typedef struct Line_follower__left_out {
  long l;
} Line_follower__left_out;

void Line_follower__left_reset(Line_follower__left_mem* self);

void Line_follower__left_step(long dir, long sen0, long sen1, long sen2,
                              long sen3, long sen4,
                              Line_follower__left_out* _out,
                              Line_follower__left_mem* self);

typedef struct Line_follower__right_mem {
  Line_follower__cpid_mem cpid;
  Line_follower__cpid_mem cpid_2;
} Line_follower__right_mem;

typedef struct Line_follower__right_out {
  long r;
} Line_follower__right_out;

void Line_follower__right_reset(Line_follower__right_mem* self);

void Line_follower__right_step(long dir, long sen0, long sen1, long sen2,
                               long sen3, long sen4,
                               Line_follower__right_out* _out,
                               Line_follower__right_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st_2 ck;
  long v_61;
  long v_59;
  long v_55;
  long v_70;
  long v_68;
  long v_64;
  long v_98;
  long v_96;
  long v_92;
  long v_116;
  long v_114;
  long v_110;
  Line_follower__st v_132;
  long v_138;
  long v_136;
  long v_134;
  long v_145;
  long v_143;
  long v_140;
  Line_follower__st_1 v_220;
  long v_222;
  long v_221;
  long v_48;
  long v_46;
  long v_44;
  long v_42;
  long pnr_2;
  long count_1;
  Line_follower__left_mem left;
  Line_follower__right_mem right;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  long v_l;
  long v_r;
  long dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long ir_left, long ir_right, long sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
