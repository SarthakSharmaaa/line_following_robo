/* --- Generated the 5/5/2024 at 23:41 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 11:24:39 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_2 Line_follower__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_White")==0)) {
    return Line_follower__St_2_White;
  };
  if ((strcmp(s, "St_2_Black")==0)) {
    return Line_follower__St_2_Black;
  };
}

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf) {
  switch (x) {
    case Line_follower__St_2_White:
      strcpy(buf, "St_2_White");
      break;
    case Line_follower__St_2_Black:
      strcpy(buf, "St_2_Black");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Straight2")==0)) {
    return Line_follower__St_1_Straight2;
  };
  if ((strcmp(s, "St_1_Straight1")==0)) {
    return Line_follower__St_1_Straight1;
  };
  if ((strcmp(s, "St_1_Straight")==0)) {
    return Line_follower__St_1_Straight;
  };
  if ((strcmp(s, "St_1_StopTemp")==0)) {
    return Line_follower__St_1_StopTemp;
  };
  if ((strcmp(s, "St_1_DoParking")==0)) {
    return Line_follower__St_1_DoParking;
  };
}

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf) {
  switch (x) {
    case Line_follower__St_1_Straight2:
      strcpy(buf, "St_1_Straight2");
      break;
    case Line_follower__St_1_Straight1:
      strcpy(buf, "St_1_Straight1");
      break;
    case Line_follower__St_1_Straight:
      strcpy(buf, "St_1_Straight");
      break;
    case Line_follower__St_1_StopTemp:
      strcpy(buf, "St_1_StopTemp");
      break;
    case Line_follower__St_1_DoParking:
      strcpy(buf, "St_1_DoParking");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_Startpark")==0)) {
    return Line_follower__St_Startpark;
  };
  if ((strcmp(s, "St_Reset")==0)) {
    return Line_follower__St_Reset;
  };
  if ((strcmp(s, "St_Parkright")==0)) {
    return Line_follower__St_Parkright;
  };
  if ((strcmp(s, "St_Parkleft")==0)) {
    return Line_follower__St_Parkleft;
  };
  if ((strcmp(s, "St_Parked")==0)) {
    return Line_follower__St_Parked;
  };
  if ((strcmp(s, "St_Inter")==0)) {
    return Line_follower__St_Inter;
  };
  if ((strcmp(s, "St_Check")==0)) {
    return Line_follower__St_Check;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_Startpark:
      strcpy(buf, "St_Startpark");
      break;
    case Line_follower__St_Reset:
      strcpy(buf, "St_Reset");
      break;
    case Line_follower__St_Parkright:
      strcpy(buf, "St_Parkright");
      break;
    case Line_follower__St_Parkleft:
      strcpy(buf, "St_Parkleft");
      break;
    case Line_follower__St_Parked:
      strcpy(buf, "St_Parked");
      break;
    case Line_follower__St_Inter:
      strcpy(buf, "St_Inter");
      break;
    case Line_follower__St_Check:
      strcpy(buf, "St_Check");
      break;
    default:
      break;
  };
  return buf;
}

