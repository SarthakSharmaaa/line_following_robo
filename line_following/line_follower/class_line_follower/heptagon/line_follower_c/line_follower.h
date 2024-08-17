/* --- Generated the 5/5/2024 at 23:41 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 11:24:39 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
typedef struct Line_follower__pid_mem {
  int v_6;
  int v_5;
  int v_3;
  int v_2;
} Line_follower__pid_mem;

typedef struct Line_follower__pid_out {
  int v_l;
  int v_r;
} Line_follower__pid_out;

void Line_follower__pid_reset(Line_follower__pid_mem* self);

void Line_follower__pid_step(int sen0, int sen1, int sen2, int sen3,
                             int sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self);

typedef struct Line_follower__cpid_mem {
  int v_22;
  int v_21;
  int v_19;
  int v_18;
} Line_follower__cpid_mem;

typedef struct Line_follower__cpid_out {
  int pid;
} Line_follower__cpid_out;

void Line_follower__cpid_reset(Line_follower__cpid_mem* self);

void Line_follower__cpid_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, Line_follower__cpid_out* _out,
                              Line_follower__cpid_mem* self);

typedef struct Line_follower__left_mem {
  Line_follower__cpid_mem cpid;
  Line_follower__cpid_mem cpid_1;
} Line_follower__left_mem;

typedef struct Line_follower__left_out {
  int l;
} Line_follower__left_out;

void Line_follower__left_reset(Line_follower__left_mem* self);

void Line_follower__left_step(int dir, int sen0, int sen1, int sen2,
                              int sen3, int sen4,
                              Line_follower__left_out* _out,
                              Line_follower__left_mem* self);

typedef struct Line_follower__right_mem {
  Line_follower__cpid_mem cpid;
  Line_follower__cpid_mem cpid_2;
} Line_follower__right_mem;

typedef struct Line_follower__right_out {
  int r;
} Line_follower__right_out;

void Line_follower__right_reset(Line_follower__right_mem* self);

void Line_follower__right_step(int dir, int sen0, int sen1, int sen2,
                               int sen3, int sen4,
                               Line_follower__right_out* _out,
                               Line_follower__right_mem* self);

typedef struct Line_follower__main_mem {
  Line_follower__st_2 ck;
  int v_61;
  int v_59;
  int v_55;
  int v_70;
  int v_68;
  int v_64;
  int v_98;
  int v_96;
  int v_92;
  int v_116;
  int v_114;
  int v_110;
  Line_follower__st v_132;
  int v_138;
  int v_136;
  int v_134;
  int v_145;
  int v_143;
  int v_140;
  Line_follower__st_1 v_220;
  int v_222;
  int v_221;
  int v_48;
  int v_46;
  int v_44;
  int v_42;
  int pnr_2;
  int count_1;
  Line_follower__left_mem left;
  Line_follower__right_mem right;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_left, int ir_right, int sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
