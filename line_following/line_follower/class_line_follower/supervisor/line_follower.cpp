/* --- Generated the 5/5/2024 at 23:41 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 11:24:39 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__pid_reset(Line_follower__pid_mem* self) {
  self->v_5 = true;
  self->v_2 = true;
}

void Line_follower__pid_step(long sen0, long sen1, long sen2, long sen3,
                             long sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self) {
  
  long v_15;
  long v_14;
  long v_13;
  long v_12;
  long v_11;
  long v_10;
  long v_9;
  long v_8;
  long v_7;
  long v_4;
  long v_1;
  long v;
  long error;
  long i;
  long p;
  long d;
  long temp;
  long pid;
  if (self->v_5) {
    v_7 = 0;
  } else {
    v_7 = self->v_6;
  };
  v = (sen1+sen0);
  v_1 = (v-sen3);
  error = (v_1-sen4);
  d = (error-v_7);
  v_10 = (d/10000);
  v_4 = (self->v_3+error);
  if (self->v_2) {
    i = 0;
  } else {
    i = v_4;
  };
  v_8 = (i/100);
  p = error;
  v_9 = (p+v_8);
  temp = (v_9+v_10);
  v_11 = (temp<0);
  if (v_11) {
    pid = -20;
  } else {
    pid = 20;
  };
  v_15 = (30+pid);
  v_14 = (pid==0);
  if (v_14) {
    _out->v_r = 50;
  } else {
    _out->v_r = v_15;
  };
  v_13 = (30-pid);
  v_12 = (pid==0);
  if (v_12) {
    _out->v_l = 50;
  } else {
    _out->v_l = v_13;
  };
  self->v_6 = error;
  self->v_5 = false;
  self->v_3 = i;
  self->v_2 = false;;
}

void Line_follower__cpid_reset(Line_follower__cpid_mem* self) {
  self->v_21 = true;
  self->v_18 = true;
}

void Line_follower__cpid_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, Line_follower__cpid_out* _out,
                              Line_follower__cpid_mem* self) {
  
  long v_27;
  long v_26;
  long v_25;
  long v_24;
  long v_23;
  long v_20;
  long v_17;
  long v_16;
  long v;
  long e;
  long i;
  long d;
  if (self->v_21) {
    v_23 = 0;
  } else {
    v_23 = self->v_22;
  };
  v = (sen0+sen1);
  v_16 = (v+sen3);
  v_17 = (v_16+sen4);
  e = (v_17-3200);
  v_24 = (Line_follower__kp*e);
  d = (e-v_23);
  v_27 = (Line_follower__kd*d);
  v_20 = (self->v_19+e);
  if (self->v_18) {
    i = 0;
  } else {
    i = v_20;
  };
  v_25 = (Line_follower__ki*i);
  v_26 = (v_24+v_25);
  _out->pid = (v_26+v_27);
  self->v_22 = e;
  self->v_21 = false;
  self->v_19 = i;
  self->v_18 = false;;
}

void Line_follower__left_reset(Line_follower__left_mem* self) {
  Line_follower__cpid_reset(&self->cpid_1);
  Line_follower__cpid_reset(&self->cpid);
}

void Line_follower__left_step(long dir, long sen0, long sen1, long sen2,
                              long sen3, long sen4,
                              Line_follower__left_out* _out,
                              Line_follower__left_mem* self) {
  Line_follower__cpid_out Line_follower__cpid_out_st;
  
  long v_31;
  long v_30;
  long v_29;
  long v_28;
  long v;
  long d[6];
  v_31 = (dir-10);
  Line_follower__cpid_step(sen0, sen1, sen2, sen3, sen4,
                           &Line_follower__cpid_out_st, &self->cpid_1);
  v_29 = Line_follower__cpid_out_st.pid;
  v_30 = (40+v_29);
  Line_follower__cpid_step(sen0, sen1, sen2, sen3, sen4,
                           &Line_follower__cpid_out_st, &self->cpid);
  v = Line_follower__cpid_out_st.pid;
  v_28 = (40-v);
  d[0] = 0;
  d[1] = 40;
  d[2] = v_28;
  d[3] = v_30;
  d[4] = 40;
  d[5] = 30;
  if (((v_31<6)&&(0<=v_31))) {
    _out->l = d[v_31];
  } else {
    _out->l = 0;
  };;
}

void Line_follower__right_reset(Line_follower__right_mem* self) {
  Line_follower__cpid_reset(&self->cpid_2);
  Line_follower__cpid_reset(&self->cpid);
}

void Line_follower__right_step(long dir, long sen0, long sen1, long sen2,
                               long sen3, long sen4,
                               Line_follower__right_out* _out,
                               Line_follower__right_mem* self) {
  Line_follower__cpid_out Line_follower__cpid_out_st;
  
  long v_35;
  long v_34;
  long v_33;
  long v_32;
  long v;
  long d[6];
  v_35 = (dir-10);
  Line_follower__cpid_step(sen0, sen1, sen2, sen3, sen4,
                           &Line_follower__cpid_out_st, &self->cpid_2);
  v_33 = Line_follower__cpid_out_st.pid;
  v_34 = (40-v_33);
  Line_follower__cpid_step(sen0, sen1, sen2, sen3, sen4,
                           &Line_follower__cpid_out_st, &self->cpid);
  v = Line_follower__cpid_out_st.pid;
  v_32 = (40+v);
  d[0] = 0;
  d[1] = 40;
  d[2] = v_32;
  d[3] = v_34;
  d[4] = 40;
  d[5] = 30;
  if (((v_35<6)&&(0<=v_35))) {
    _out->r = d[v_35];
  } else {
    _out->r = 0;
  };;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__right_reset(&self->right);
  Line_follower__left_reset(&self->left);
  self->v_222 = 0;
  self->v_221 = false;
  self->v_220 = Line_follower__St_1_Straight;
  self->v_46 = true;
  self->v_42 = true;
  self->count_1 = 0;
  self->pnr_2 = false;
  self->ck = Line_follower__St_2_White;
  self->v_140 = true;
  self->v_138 = 0;
  self->v_136 = 0;
  self->v_134 = false;
  self->v_132 = Line_follower__St_Startpark;
  self->v_110 = true;
  self->v_92 = true;
  self->v_64 = true;
  self->v_55 = true;
}

void Line_follower__main_step(long sen0, long sen1, long sen2, long sen3,
                              long sen4, long ir_left, long ir_right, long sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__left_out Line_follower__left_out_st;
  Line_follower__right_out Line_follower__right_out_st;
  
  long v_39;
  long v_38;
  long v_37;
  long v_36;
  long v;
  long r_4_St_2_Black;
  Line_follower__st_2 s_2_St_2_Black;
  long r_4_St_2_White;
  Line_follower__st_2 s_2_St_2_White;
  long v_62;
  long v_60;
  long v_58;
  long v_57;
  long v_56;
  long v_54;
  long time_4;
  long v_71;
  long v_69;
  long v_67;
  long v_66;
  long v_65;
  long v_63;
  long time_3;
  long v_80;
  long v_79;
  long v_78;
  long v_77;
  long v_76;
  long v_75;
  long v_74;
  long v_73;
  long v_72;
  long v_99;
  long v_97;
  long v_95;
  long v_94;
  long v_93;
  long v_91;
  Line_follower__st v_90;
  long v_89;
  Line_follower__st v_88;
  long v_87;
  Line_follower__st v_86;
  long v_85;
  long v_84;
  long v_83;
  long v_82;
  long v_81;
  long time_2;
  long v_108;
  long v_107;
  long v_106;
  long v_105;
  long v_104;
  long v_103;
  long v_102;
  long v_101;
  long v_100;
  long v_130;
  long v_129;
  long v_128;
  long v_127;
  long v_126;
  long v_125;
  long v_124;
  long v_123;
  long v_122;
  long v_121;
  long v_120;
  long v_119;
  long v_118;
  long v_117;
  long v_115;
  long v_113;
  long v_112;
  long v_111;
  long v_109;
  long time_1;
  long v_131;
  long nr_St_Parked;
  Line_follower__st ns_St_Parked;
  long cntr_St_Parked;
  long cntl_St_Parked;
  long dir_St_2_Black_St_1_DoParking_St_Parked;
  long v_r_St_2_Black_St_1_DoParking_St_Parked;
  long v_l_St_2_Black_St_1_DoParking_St_Parked;
  long nr_St_Parkleft;
  Line_follower__st ns_St_Parkleft;
  long cntr_St_Parkleft;
  long cntl_St_Parkleft;
  long dir_St_2_Black_St_1_DoParking_St_Parkleft;
  long v_r_St_2_Black_St_1_DoParking_St_Parkleft;
  long v_l_St_2_Black_St_1_DoParking_St_Parkleft;
  long nr_St_Parkright;
  Line_follower__st ns_St_Parkright;
  long cntr_St_Parkright;
  long cntl_St_Parkright;
  long dir_St_2_Black_St_1_DoParking_St_Parkright;
  long v_r_St_2_Black_St_1_DoParking_St_Parkright;
  long v_l_St_2_Black_St_1_DoParking_St_Parkright;
  long nr_St_Reset;
  Line_follower__st ns_St_Reset;
  long cntr_St_Reset;
  long cntl_St_Reset;
  long dir_St_2_Black_St_1_DoParking_St_Reset;
  long v_r_St_2_Black_St_1_DoParking_St_Reset;
  long v_l_St_2_Black_St_1_DoParking_St_Reset;
  long nr_St_Inter;
  Line_follower__st ns_St_Inter;
  long cntr_St_Inter;
  long cntl_St_Inter;
  long dir_St_2_Black_St_1_DoParking_St_Inter;
  long v_r_St_2_Black_St_1_DoParking_St_Inter;
  long v_l_St_2_Black_St_1_DoParking_St_Inter;
  long nr_St_Check;
  Line_follower__st ns_St_Check;
  long cntr_St_Check;
  long cntl_St_Check;
  long dir_St_2_Black_St_1_DoParking_St_Check;
  long v_r_St_2_Black_St_1_DoParking_St_Check;
  long v_l_St_2_Black_St_1_DoParking_St_Check;
  long nr_St_Startpark;
  Line_follower__st ns_St_Startpark;
  long cntr_St_Startpark;
  long cntl_St_Startpark;
  long dir_St_2_Black_St_1_DoParking_St_Startpark;
  long v_r_St_2_Black_St_1_DoParking_St_Startpark;
  long v_l_St_2_Black_St_1_DoParking_St_Startpark;
  Line_follower__st ck_3;
  long v_137;
  long v_135;
  long v_133;
  Line_follower__st ns;
  long r_2;
  long nr;
  long pnr;
  long cntr_1;
  long cntl_1;
  long cntl;
  long cntr;
  long v_146;
  long v_144;
  long v_142;
  long v_141;
  long v_139;
  long time;
  long v_167;
  long v_166;
  long v_165;
  long v_164;
  long v_163;
  long v_162;
  long v_161;
  long v_160;
  long v_159;
  long v_158;
  Line_follower__st_1 v_157;
  long v_156;
  long v_155;
  long v_154;
  long v_153;
  long v_152;
  long v_151;
  long v_150;
  long v_149;
  long v_148;
  long v_147;
  long v_176;
  long v_175;
  long v_174;
  long v_173;
  long v_172;
  long v_171;
  long v_170;
  long v_169;
  long v_168;
  long v_219;
  long v_218;
  long v_217;
  long v_216;
  long v_215;
  long v_214;
  long v_213;
  long v_212;
  long v_211;
  long v_210;
  Line_follower__st_1 v_209;
  long v_208;
  long v_207;
  long v_206;
  long v_205;
  long v_204;
  long v_203;
  long v_202;
  long v_201;
  long v_200;
  long v_199;
  long v_198;
  long v_197;
  long v_196;
  long v_195;
  long v_194;
  long v_193;
  long v_192;
  long v_191;
  long v_190;
  long v_189;
  long v_188;
  long v_187;
  long v_186;
  long v_185;
  long v_184;
  long v_183;
  long v_182;
  long v_181;
  long v_180;
  long v_179;
  long v_178;
  long v_177;
  long nr_1_St_1_DoParking;
  Line_follower__st_1 ns_1_St_1_DoParking;
  long count1_St_1_DoParking;
  long count_St_2_Black_St_1_DoParking;
  long dir_St_2_Black_St_1_DoParking;
  long v_r_St_2_Black_St_1_DoParking;
  long v_l_St_2_Black_St_1_DoParking;
  long nr_1_St_1_StopTemp;
  Line_follower__st_1 ns_1_St_1_StopTemp;
  long count1_St_1_StopTemp;
  long count_St_2_Black_St_1_StopTemp;
  long dir_St_2_Black_St_1_StopTemp;
  long v_r_St_2_Black_St_1_StopTemp;
  long v_l_St_2_Black_St_1_StopTemp;
  long nr_1_St_1_Straight2;
  Line_follower__st_1 ns_1_St_1_Straight2;
  long count1_St_1_Straight2;
  long count_St_2_Black_St_1_Straight2;
  long dir_St_2_Black_St_1_Straight2;
  long v_r_St_2_Black_St_1_Straight2;
  long v_l_St_2_Black_St_1_Straight2;
  long nr_1_St_1_Straight1;
  Line_follower__st_1 ns_1_St_1_Straight1;
  long count1_St_1_Straight1;
  long count_St_2_Black_St_1_Straight1;
  long dir_St_2_Black_St_1_Straight1;
  long v_r_St_2_Black_St_1_Straight1;
  long v_l_St_2_Black_St_1_Straight1;
  long nr_1_St_1_Straight;
  Line_follower__st_1 ns_1_St_1_Straight;
  long count1_St_1_Straight;
  long count_St_2_Black_St_1_Straight;
  long dir_St_2_Black_St_1_Straight;
  long v_r_St_2_Black_St_1_Straight;
  long v_l_St_2_Black_St_1_Straight;
  Line_follower__st_1 ck_2;
  long v_53;
  long v_52;
  long v_51;
  long v_50;
  long v_49;
  long v_47;
  long v_45;
  long v_43;
  long v_41;
  long v_40;
  Line_follower__st_1 ns_1;
  long r_3;
  long nr_1;
  long pnr_1;
  long count1_1;
  long error1;
  long p1;
  long i1;
  long d1;
  long temp1;
  long pid1;
  long count1;
  long v_240;
  long v_239;
  long v_238;
  long v_237;
  long v_236;
  long v_235;
  long v_234;
  long v_233;
  long v_232;
  long v_231;
  long v_230;
  long v_229;
  long v_228;
  long v_227;
  long v_226;
  long v_225;
  long v_224;
  long v_223;
  long r_6;
  long r_5;
  long l;
  long r;
  long sum;
  long nr_2_St_2_Black;
  Line_follower__st_2 ns_2_St_2_Black;
  long count_St_2_Black;
  long sen_St_2_Black[5];
  long dir_St_2_Black;
  long v_r_St_2_Black;
  long v_l_St_2_Black;
  long nr_2_St_2_White;
  Line_follower__st_2 ns_2_St_2_White;
  long count_St_2_White;
  long sen_St_2_White[5];
  long dir_St_2_White;
  long v_r_St_2_White;
  long v_l_St_2_White;
  Line_follower__st_2 ck_1;
  Line_follower__st_2 s_2;
  Line_follower__st_2 ns_2;
  long r_4;
  long nr_2;
  long sen[5];
  long count;
  switch (self->ck) {
    case Line_follower__St_2_White:
      v_38 = (sen2<800);
      v_36 = (sen4>800);
      v = (sen0>800);
      v_37 = (v&&v_36);
      v_39 = (v_37&&v_38);
      if (v_39) {
        r_4_St_2_White = true;
        s_2_St_2_White = Line_follower__St_2_Black;
      } else {
        r_4_St_2_White = self->pnr_2;
        s_2_St_2_White = Line_follower__St_2_White;
      };
      s_2 = s_2_St_2_White;
      r_4 = r_4_St_2_White;
      break;
    case Line_follower__St_2_Black:
      r_4_St_2_Black = self->pnr_2;
      s_2_St_2_Black = Line_follower__St_2_Black;
      s_2 = s_2_St_2_Black;
      r_4 = r_4_St_2_Black;
      break;
    default:
      break;
  };
  ck_1 = s_2;
  switch (ck_1) {
    case Line_follower__St_2_White:
      count_St_2_White = self->count_1;
      v_230 = (sen3>800);
      if (v_230) {
        v_231 = 13;
      } else {
        v_231 = 11;
      };
      v_229 = (sen1>800);
      if (v_229) {
        v_232 = 12;
      } else {
        v_232 = v_231;
      };
      v_227 = (sen4>800);
      v_226 = (sen0>800);
      v_223 = (sen0+sen1);
      v_224 = (v_223+sen2);
      v_225 = (v_224+sen3);
      sum = (v_225+sen4);
      v_228 = (sum>4000);
      if (v_228) {
        v_233 = 10;
      } else {
        v_233 = v_232;
      };
      if (v_227) {
        v_234 = 15;
      } else {
        v_234 = v_233;
      };
      if (v_226) {
        dir_St_2_White = 14;
      } else {
        dir_St_2_White = v_234;
      };
      nr_2_St_2_White = false;
      ns_2_St_2_White = Line_follower__St_2_White;
      r_5 = r_4;
      r_6 = r_4;
      ns_2 = ns_2_St_2_White;
      nr_2 = nr_2_St_2_White;
      _out->dir = dir_St_2_White;
      if (r_6) {
        Line_follower__right_reset(&self->right);
      };
      Line_follower__right_step(_out->dir, sen0, sen1, sen2, sen3, sen4,
                                &Line_follower__right_out_st, &self->right);
      r = Line_follower__right_out_st.r;
      v_239 = (r<0);
      if (v_239) {
        v_240 = 0;
      } else {
        v_240 = r;
      };
      v_238 = (r>50);
      if (v_238) {
        v_r_St_2_White = 50;
      } else {
        v_r_St_2_White = v_240;
      };
      if (r_5) {
        Line_follower__left_reset(&self->left);
      };
      Line_follower__left_step(_out->dir, sen0, sen1, sen2, sen3, sen4,
                               &Line_follower__left_out_st, &self->left);
      l = Line_follower__left_out_st.l;
      v_236 = (l<0);
      if (v_236) {
        v_237 = 0;
      } else {
        v_237 = l;
      };
      v_235 = (l>50);
      if (v_235) {
        v_l_St_2_White = 50;
      } else {
        v_l_St_2_White = v_237;
      };
      count = count_St_2_White;
      _out->v_l = v_l_St_2_White;
      _out->v_r = v_r_St_2_White;
      sen_St_2_White[0] = sen0;
      sen_St_2_White[1] = sen1;
      sen_St_2_White[2] = sen2;
      sen_St_2_White[3] = sen3;
      sen_St_2_White[4] = sen4;
      {
        long _3;
        for (_3 = 0; _3 < 5; ++_3) {
          sen[_3] = sen_St_2_White[_3];
        }
      };
      break;
    case Line_follower__St_2_Black:
      if (r_4) {
        count1_1 = 0;
        pnr_1 = false;
      } else {
        count1_1 = self->v_222;
        pnr_1 = self->v_221;
      };
      r_3 = pnr_1;
      if (r_4) {
        ck_2 = Line_follower__St_1_Straight;
      } else {
        ck_2 = self->v_220;
      };
      if (self->v_46) {
        v_47 = true;
      } else {
        v_47 = r_4;
      };
      if (v_47) {
        v_49 = 0;
      } else {
        v_49 = self->v_48;
      };
      if (self->v_42) {
        v_43 = true;
      } else {
        v_43 = r_4;
      };
      v_40 = (sen1+sen0);
      v_41 = (v_40-sen3);
      error1 = (v_41-sen4);
      d1 = (error1-v_49);
      v_52 = (d1/10000);
      v_45 = (self->v_44+error1);
      if (v_43) {
        i1 = 0;
      } else {
        i1 = v_45;
      };
      v_50 = (i1/100);
      p1 = error1;
      v_51 = (p1+v_50);
      temp1 = (v_51+v_52);
      v_53 = (temp1<0);
      if (v_53) {
        pid1 = -20;
      } else {
        pid1 = 20;
      };
      nr_2_St_2_Black = false;
      ns_2_St_2_Black = Line_follower__St_2_Black;
      ns_2 = ns_2_St_2_Black;
      nr_2 = nr_2_St_2_Black;
      switch (ck_2) {
        case Line_follower__St_1_Straight:
          count1_St_1_Straight = count1_1;
          v_212 = (sen3<900);
          if (v_212) {
            v_213 = 3;
          } else {
            v_213 = 1;
          };
          v_211 = (sen1<900);
          if (v_211) {
            dir_St_2_Black_St_1_Straight = 2;
          } else {
            dir_St_2_Black_St_1_Straight = v_213;
          };
          count_St_2_Black_St_1_Straight = 0;
          v_206 = (sen4>800);
          v_204 = (sen3<800);
          v_202 = (sen2<800);
          v_200 = (sen1<800);
          v_199 = (sen0<800);
          v_201 = (v_199&&v_200);
          v_203 = (v_201&&v_202);
          v_205 = (v_203&&v_204);
          v_207 = (v_205&&v_206);
          v_195 = (sen4>800);
          v_196 = !(v_195);
          v_193 = (sen3<800);
          v_191 = (sen2<800);
          v_189 = (sen1<800);
          v_188 = (sen0>800);
          v_190 = (v_188&&v_189);
          v_192 = (v_190&&v_191);
          v_194 = (v_192&&v_193);
          v_197 = (v_194&&v_196);
          v_185 = (sen4>800);
          v_186 = !(v_185);
          v_183 = (sen3<800);
          v_181 = (sen2<800);
          v_179 = (sen1<800);
          v_178 = (sen0<800);
          v_180 = (v_178&&v_179);
          v_182 = (v_180&&v_181);
          v_184 = (v_182&&v_183);
          v_187 = (v_184&&v_186);
          v_198 = (v_187||v_197);
          v_208 = (v_198||v_207);
          if (v_208) {
            v_210 = true;
            v_209 = Line_follower__St_1_Straight1;
          } else {
            v_210 = false;
            v_209 = Line_follower__St_1_Straight;
          };
          count_St_2_Black = count_St_2_Black_St_1_Straight;
          count1 = count1_St_1_Straight;
          v_177 = (count1==5);
          if (v_177) {
            nr_1_St_1_Straight = true;
            ns_1_St_1_Straight = Line_follower__St_1_StopTemp;
          } else {
            nr_1_St_1_Straight = v_210;
            ns_1_St_1_Straight = v_209;
          };
          ns_1 = ns_1_St_1_Straight;
          nr_1 = nr_1_St_1_Straight;
          dir_St_2_Black = dir_St_2_Black_St_1_Straight;
          break;
        case Line_follower__St_1_Straight1:
          v_169 = (sen3<900);
          if (v_169) {
            v_170 = 3;
          } else {
            v_170 = 1;
          };
          v_168 = (sen1<900);
          if (v_168) {
            dir_St_2_Black_St_1_Straight1 = 2;
          } else {
            dir_St_2_Black_St_1_Straight1 = v_170;
          };
          count1_St_1_Straight1 = (count1_1+1);
          count_St_2_Black_St_1_Straight1 = 0;
          if (true) {
            nr_1_St_1_Straight1 = true;
          } else {
            nr_1_St_1_Straight1 = false;
          };
          if (true) {
            ns_1_St_1_Straight1 = Line_follower__St_1_Straight2;
          } else {
            ns_1_St_1_Straight1 = Line_follower__St_1_Straight1;
          };
          count_St_2_Black = count_St_2_Black_St_1_Straight1;
          count1 = count1_St_1_Straight1;
          ns_1 = ns_1_St_1_Straight1;
          nr_1 = nr_1_St_1_Straight1;
          dir_St_2_Black = dir_St_2_Black_St_1_Straight1;
          break;
        case Line_follower__St_1_Straight2:
          count1_St_1_Straight2 = count1_1;
          v_160 = (sen3<900);
          if (v_160) {
            v_161 = 3;
          } else {
            v_161 = 1;
          };
          v_159 = (sen1<900);
          if (v_159) {
            dir_St_2_Black_St_1_Straight2 = 2;
          } else {
            dir_St_2_Black_St_1_Straight2 = v_161;
          };
          count_St_2_Black_St_1_Straight2 = 0;
          v_155 = (sen4>800);
          v_153 = (sen3>800);
          v_151 = (sen2<800);
          v_149 = (sen1>800);
          v_148 = (sen0>800);
          v_150 = (v_148&&v_149);
          v_152 = (v_150&&v_151);
          v_154 = (v_152&&v_153);
          v_156 = (v_154&&v_155);
          if (v_156) {
            v_158 = true;
            v_157 = Line_follower__St_1_Straight;
          } else {
            v_158 = false;
            v_157 = Line_follower__St_1_Straight2;
          };
          count_St_2_Black = count_St_2_Black_St_1_Straight2;
          count1 = count1_St_1_Straight2;
          v_147 = (count1==5);
          if (v_147) {
            nr_1_St_1_Straight2 = true;
            ns_1_St_1_Straight2 = Line_follower__St_1_StopTemp;
          } else {
            nr_1_St_1_Straight2 = v_158;
            ns_1_St_1_Straight2 = v_157;
          };
          ns_1 = ns_1_St_1_Straight2;
          nr_1 = nr_1_St_1_Straight2;
          dir_St_2_Black = dir_St_2_Black_St_1_Straight2;
          break;
        case Line_follower__St_1_StopTemp:
          count1_St_1_StopTemp = count1_1;
          count_St_2_Black_St_1_StopTemp = self->count_1;
          v_144 = (self->v_143-1);
          if (sec) {
            v_146 = v_144;
          } else {
            v_146 = self->v_145;
          };
          v_141 = (r_4||r_3);
          if (self->v_140) {
            v_142 = true;
          } else {
            v_142 = v_141;
          };
          if (v_142) {
            time = 30;
          } else {
            time = v_146;
          };
          v_r_St_2_Black_St_1_StopTemp = 0;
          v_l_St_2_Black_St_1_StopTemp = 0;
          dir_St_2_Black_St_1_StopTemp = 0;
          v_139 = (time==0);
          if (v_139) {
            nr_1_St_1_StopTemp = true;
            ns_1_St_1_StopTemp = Line_follower__St_1_DoParking;
          } else {
            nr_1_St_1_StopTemp = false;
            ns_1_St_1_StopTemp = Line_follower__St_1_StopTemp;
          };
          count_St_2_Black = count_St_2_Black_St_1_StopTemp;
          count1 = count1_St_1_StopTemp;
          ns_1 = ns_1_St_1_StopTemp;
          nr_1 = nr_1_St_1_StopTemp;
          dir_St_2_Black = dir_St_2_Black_St_1_StopTemp;
          break;
        case Line_follower__St_1_DoParking:
          v_137 = (r_4||r_3);
          if (v_137) {
            cntr_1 = 0;
          } else {
            cntr_1 = self->v_138;
          };
          v_135 = (r_4||r_3);
          if (v_135) {
            cntl_1 = 0;
          } else {
            cntl_1 = self->v_136;
          };
          count1_St_1_DoParking = count1_1;
          count_St_2_Black_St_1_DoParking = self->count_1;
          v_133 = (r_4||r_3);
          if (v_133) {
            pnr = false;
          } else {
            pnr = self->v_134;
          };
          r_2 = pnr;
          v_131 = (r_4||r_3);
          if (v_131) {
            ck_3 = Line_follower__St_Startpark;
          } else {
            ck_3 = self->v_132;
          };
          nr_1_St_1_DoParking = false;
          ns_1_St_1_DoParking = Line_follower__St_1_DoParking;
          count_St_2_Black = count_St_2_Black_St_1_DoParking;
          count1 = count1_St_1_DoParking;
          ns_1 = ns_1_St_1_DoParking;
          nr_1 = nr_1_St_1_DoParking;
          switch (ck_3) {
            case Line_follower__St_Startpark:
              v_129 = (ir_right==0);
              if (v_129) {
                v_130 = 1;
              } else {
                v_130 = 0;
              };
              cntr_St_Startpark = (cntr_1+v_130);
              v_127 = (ir_left==0);
              if (v_127) {
                v_128 = 1;
              } else {
                v_128 = 0;
              };
              cntl_St_Startpark = (cntl_1+v_128);
              v_125 = (sen4<550);
              if (v_125) {
                v_126 = 100;
              } else {
                v_126 = 60;
              };
              v_124 = (sen0<550);
              if (v_124) {
                v_r_St_2_Black_St_1_DoParking_St_Startpark = 100;
              } else {
                v_r_St_2_Black_St_1_DoParking_St_Startpark = v_126;
              };
              v_122 = (sen4<550);
              if (v_122) {
                v_123 = 100;
              } else {
                v_123 = 60;
              };
              v_121 = (sen0<550);
              if (v_121) {
                v_l_St_2_Black_St_1_DoParking_St_Startpark = 100;
              } else {
                v_l_St_2_Black_St_1_DoParking_St_Startpark = v_123;
              };
              v_119 = (sen4<550);
              if (v_119) {
                v_120 = 4;
              } else {
                v_120 = 1;
              };
              v_118 = (sen0<550);
              if (v_118) {
                dir_St_2_Black_St_1_DoParking_St_Startpark = 3;
              } else {
                dir_St_2_Black_St_1_DoParking_St_Startpark = v_120;
              };
              v_115 = (self->v_114-1);
              if (sec) {
                v_117 = v_115;
              } else {
                v_117 = self->v_116;
              };
              v_111 = (r_4||r_3);
              v_112 = (v_111||r_2);
              if (self->v_110) {
                v_113 = true;
              } else {
                v_113 = v_112;
              };
              if (v_113) {
                time_1 = 4;
              } else {
                time_1 = v_117;
              };
              v_109 = (time_1==0);
              if (v_109) {
                nr_St_Startpark = true;
                ns_St_Startpark = Line_follower__St_Check;
              } else {
                nr_St_Startpark = false;
                ns_St_Startpark = Line_follower__St_Startpark;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Startpark;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Startpark;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Startpark;
              cntl = cntl_St_Startpark;
              cntr = cntr_St_Startpark;
              ns = ns_St_Startpark;
              nr = nr_St_Startpark;
              break;
            case Line_follower__St_Check:
              cntr_St_Check = cntr_1;
              cntl_St_Check = cntl_1;
              v_107 = (sen4<550);
              if (v_107) {
                v_108 = 100;
              } else {
                v_108 = 60;
              };
              v_106 = (sen0<550);
              if (v_106) {
                v_r_St_2_Black_St_1_DoParking_St_Check = 100;
              } else {
                v_r_St_2_Black_St_1_DoParking_St_Check = v_108;
              };
              v_104 = (sen4<550);
              if (v_104) {
                v_105 = 100;
              } else {
                v_105 = 60;
              };
              v_103 = (sen0<550);
              if (v_103) {
                v_l_St_2_Black_St_1_DoParking_St_Check = 100;
              } else {
                v_l_St_2_Black_St_1_DoParking_St_Check = v_105;
              };
              v_101 = (sen4<550);
              if (v_101) {
                v_102 = 4;
              } else {
                v_102 = 1;
              };
              v_100 = (sen0<550);
              if (v_100) {
                dir_St_2_Black_St_1_DoParking_St_Check = 3;
              } else {
                dir_St_2_Black_St_1_DoParking_St_Check = v_102;
              };
              if (true) {
                nr_St_Check = true;
              } else {
                nr_St_Check = false;
              };
              if (true) {
                ns_St_Check = Line_follower__St_Inter;
              } else {
                ns_St_Check = Line_follower__St_Check;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Check;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Check;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Check;
              cntl = cntl_St_Check;
              cntr = cntr_St_Check;
              ns = ns_St_Check;
              nr = nr_St_Check;
              break;
            case Line_follower__St_Inter:
              cntr_St_Inter = cntr_1;
              cntl_St_Inter = cntl_1;
              v_97 = (self->v_96-1);
              if (sec) {
                v_99 = v_97;
              } else {
                v_99 = self->v_98;
              };
              v_93 = (r_4||r_3);
              v_94 = (v_93||r_2);
              if (self->v_92) {
                v_95 = true;
              } else {
                v_95 = v_94;
              };
              if (v_95) {
                time_2 = 2;
              } else {
                time_2 = v_99;
              };
              dir_St_2_Black_St_1_DoParking_St_Inter = 0;
              v_r_St_2_Black_St_1_DoParking_St_Inter = 0;
              v_l_St_2_Black_St_1_DoParking_St_Inter = 0;
              if (true) {
                v_87 = true;
              } else {
                v_87 = false;
              };
              if (true) {
                v_86 = Line_follower__St_Reset;
              } else {
                v_86 = Line_follower__St_Inter;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Inter;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Inter;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Inter;
              cntl = cntl_St_Inter;
              v_84 = (cntl==0);
              v_81 = (cntl==0);
              cntr = cntr_St_Inter;
              v_85 = (cntr==0);
              if (v_85) {
                v_89 = true;
              } else {
                v_89 = v_87;
              };
              if (v_84) {
                v_91 = true;
              } else {
                v_91 = v_89;
              };
              if (v_85) {
                v_88 = Line_follower__St_Parkright;
              } else {
                v_88 = v_86;
              };
              if (v_84) {
                v_90 = Line_follower__St_Parkleft;
              } else {
                v_90 = v_88;
              };
              v_82 = (cntr==0);
              v_83 = (v_81&&v_82);
              if (v_83) {
                nr_St_Inter = true;
                ns_St_Inter = Line_follower__St_Parkleft;
              } else {
                nr_St_Inter = v_91;
                ns_St_Inter = v_90;
              };
              ns = ns_St_Inter;
              nr = nr_St_Inter;
              break;
            case Line_follower__St_Reset:
              cntr_St_Reset = 0;
              cntl_St_Reset = 0;
              v_79 = (sen4<550);
              if (v_79) {
                v_80 = 100;
              } else {
                v_80 = 60;
              };
              v_78 = (sen0<550);
              if (v_78) {
                v_r_St_2_Black_St_1_DoParking_St_Reset = 100;
              } else {
                v_r_St_2_Black_St_1_DoParking_St_Reset = v_80;
              };
              v_76 = (sen4<550);
              if (v_76) {
                v_77 = 100;
              } else {
                v_77 = 60;
              };
              v_75 = (sen0<550);
              if (v_75) {
                v_l_St_2_Black_St_1_DoParking_St_Reset = 100;
              } else {
                v_l_St_2_Black_St_1_DoParking_St_Reset = v_77;
              };
              v_73 = (sen4<550);
              if (v_73) {
                v_74 = 4;
              } else {
                v_74 = 1;
              };
              v_72 = (sen0<550);
              if (v_72) {
                dir_St_2_Black_St_1_DoParking_St_Reset = 3;
              } else {
                dir_St_2_Black_St_1_DoParking_St_Reset = v_74;
              };
              if (true) {
                nr_St_Reset = true;
              } else {
                nr_St_Reset = false;
              };
              if (true) {
                ns_St_Reset = Line_follower__St_Startpark;
              } else {
                ns_St_Reset = Line_follower__St_Reset;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Reset;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Reset;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Reset;
              cntl = cntl_St_Reset;
              cntr = cntr_St_Reset;
              ns = ns_St_Reset;
              nr = nr_St_Reset;
              break;
            case Line_follower__St_Parkright:
              cntr_St_Parkright = cntr_1;
              cntl_St_Parkright = cntl_1;
              v_69 = (self->v_68-1);
              if (sec) {
                v_71 = v_69;
              } else {
                v_71 = self->v_70;
              };
              v_65 = (r_4||r_3);
              v_66 = (v_65||r_2);
              if (self->v_64) {
                v_67 = true;
              } else {
                v_67 = v_66;
              };
              if (v_67) {
                time_3 = 3;
              } else {
                time_3 = v_71;
              };
              dir_St_2_Black_St_1_DoParking_St_Parkright = 5;
              v_r_St_2_Black_St_1_DoParking_St_Parkright = 70;
              v_l_St_2_Black_St_1_DoParking_St_Parkright = 30;
              v_63 = (time_3==0);
              if (v_63) {
                nr_St_Parkright = true;
                ns_St_Parkright = Line_follower__St_Parked;
              } else {
                nr_St_Parkright = false;
                ns_St_Parkright = Line_follower__St_Parkright;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Parkright;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Parkright;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Parkright;
              cntl = cntl_St_Parkright;
              cntr = cntr_St_Parkright;
              ns = ns_St_Parkright;
              nr = nr_St_Parkright;
              break;
            case Line_follower__St_Parkleft:
              cntr_St_Parkleft = cntr_1;
              cntl_St_Parkleft = cntl_1;
              v_60 = (self->v_59-1);
              if (sec) {
                v_62 = v_60;
              } else {
                v_62 = self->v_61;
              };
              v_56 = (r_4||r_3);
              v_57 = (v_56||r_2);
              if (self->v_55) {
                v_58 = true;
              } else {
                v_58 = v_57;
              };
              if (v_58) {
                time_4 = 3;
              } else {
                time_4 = v_62;
              };
              dir_St_2_Black_St_1_DoParking_St_Parkleft = 6;
              v_r_St_2_Black_St_1_DoParking_St_Parkleft = 30;
              v_l_St_2_Black_St_1_DoParking_St_Parkleft = 70;
              v_54 = (time_4==0);
              if (v_54) {
                nr_St_Parkleft = true;
                ns_St_Parkleft = Line_follower__St_Parked;
              } else {
                nr_St_Parkleft = false;
                ns_St_Parkleft = Line_follower__St_Parkleft;
              };
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Parkleft;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Parkleft;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Parkleft;
              cntl = cntl_St_Parkleft;
              cntr = cntr_St_Parkleft;
              ns = ns_St_Parkleft;
              nr = nr_St_Parkleft;
              break;
            case Line_follower__St_Parked:
              cntr_St_Parked = cntr_1;
              cntl_St_Parked = cntl_1;
              dir_St_2_Black_St_1_DoParking_St_Parked = 0;
              v_r_St_2_Black_St_1_DoParking_St_Parked = 0;
              v_l_St_2_Black_St_1_DoParking_St_Parked = 0;
              nr_St_Parked = false;
              ns_St_Parked = Line_follower__St_Parked;
              v_l_St_2_Black_St_1_DoParking = v_l_St_2_Black_St_1_DoParking_St_Parked;
              v_r_St_2_Black_St_1_DoParking = v_r_St_2_Black_St_1_DoParking_St_Parked;
              dir_St_2_Black_St_1_DoParking = dir_St_2_Black_St_1_DoParking_St_Parked;
              cntl = cntl_St_Parked;
              cntr = cntr_St_Parked;
              ns = ns_St_Parked;
              nr = nr_St_Parked;
              break;
            default:
              break;
          };
          dir_St_2_Black = dir_St_2_Black_St_1_DoParking;
          break;
        default:
          break;
      };
      _out->dir = dir_St_2_Black;
      count = count_St_2_Black;
      switch (ck_2) {
        case Line_follower__St_1_Straight:
          v_218 = (_out->dir==3);
          if (v_218) {
            v_219 = pid1;
          } else {
            v_219 = 40;
          };
          v_217 = (_out->dir==2);
          if (v_217) {
            v_r_St_2_Black_St_1_Straight = 0;
          } else {
            v_r_St_2_Black_St_1_Straight = v_219;
          };
          v_215 = (_out->dir==3);
          if (v_215) {
            v_216 = 0;
          } else {
            v_216 = 40;
          };
          v_214 = (_out->dir==2);
          if (v_214) {
            v_l_St_2_Black_St_1_Straight = pid1;
          } else {
            v_l_St_2_Black_St_1_Straight = v_216;
          };
          v_l_St_2_Black = v_l_St_2_Black_St_1_Straight;
          v_r_St_2_Black = v_r_St_2_Black_St_1_Straight;
          break;
        case Line_follower__St_1_Straight1:
          v_175 = (_out->dir==3);
          if (v_175) {
            v_176 = pid1;
          } else {
            v_176 = 40;
          };
          v_174 = (_out->dir==2);
          if (v_174) {
            v_r_St_2_Black_St_1_Straight1 = 0;
          } else {
            v_r_St_2_Black_St_1_Straight1 = v_176;
          };
          v_172 = (_out->dir==3);
          if (v_172) {
            v_173 = 0;
          } else {
            v_173 = 40;
          };
          v_171 = (_out->dir==2);
          if (v_171) {
            v_l_St_2_Black_St_1_Straight1 = pid1;
          } else {
            v_l_St_2_Black_St_1_Straight1 = v_173;
          };
          v_l_St_2_Black = v_l_St_2_Black_St_1_Straight1;
          v_r_St_2_Black = v_r_St_2_Black_St_1_Straight1;
          break;
        case Line_follower__St_1_Straight2:
          v_166 = (_out->dir==3);
          if (v_166) {
            v_167 = pid1;
          } else {
            v_167 = 40;
          };
          v_165 = (_out->dir==2);
          if (v_165) {
            v_r_St_2_Black_St_1_Straight2 = 0;
          } else {
            v_r_St_2_Black_St_1_Straight2 = v_167;
          };
          v_163 = (_out->dir==3);
          if (v_163) {
            v_164 = 0;
          } else {
            v_164 = 40;
          };
          v_162 = (_out->dir==2);
          if (v_162) {
            v_l_St_2_Black_St_1_Straight2 = pid1;
          } else {
            v_l_St_2_Black_St_1_Straight2 = v_164;
          };
          v_l_St_2_Black = v_l_St_2_Black_St_1_Straight2;
          v_r_St_2_Black = v_r_St_2_Black_St_1_Straight2;
          break;
        case Line_follower__St_1_DoParking:
          v_l_St_2_Black = v_l_St_2_Black_St_1_DoParking;
          v_r_St_2_Black = v_r_St_2_Black_St_1_DoParking;
          break;
        case Line_follower__St_1_StopTemp:
          v_l_St_2_Black = v_l_St_2_Black_St_1_StopTemp;
          v_r_St_2_Black = v_r_St_2_Black_St_1_StopTemp;
          break;
        default:
          break;
      };
      _out->v_l = v_l_St_2_Black;
      _out->v_r = v_r_St_2_Black;
      sen_St_2_Black[0] = sen0;
      sen_St_2_Black[1] = sen1;
      sen_St_2_Black[2] = sen2;
      sen_St_2_Black[3] = sen3;
      sen_St_2_Black[4] = sen4;
      {
        long _4;
        for (_4 = 0; _4 < 5; ++_4) {
          sen[_4] = sen_St_2_Black[_4];
        }
      };
      self->v_222 = count1;
      self->v_221 = nr_1;
      self->v_220 = ns_1;
      self->v_48 = error1;
      self->v_46 = false;
      self->v_44 = i1;
      self->v_42 = false;
      break;
    default:
      break;
  };
  self->count_1 = count;
  self->pnr_2 = nr_2;
  self->ck = ns_2;
  switch (ck_1) {
    case Line_follower__St_2_Black:
      switch (ck_2) {
        case Line_follower__St_1_StopTemp:
          self->v_145 = time;
          self->v_143 = time;
          self->v_140 = false;
          break;
        case Line_follower__St_1_DoParking:
          self->v_138 = cntr;
          self->v_136 = cntl;
          self->v_134 = nr;
          self->v_132 = ns;
          switch (ck_3) {
            case Line_follower__St_Startpark:
              self->v_116 = time_1;
              self->v_114 = time_1;
              self->v_110 = false;
              break;
            case Line_follower__St_Inter:
              self->v_98 = time_2;
              self->v_96 = time_2;
              self->v_92 = false;
              break;
            case Line_follower__St_Parkright:
              self->v_70 = time_3;
              self->v_68 = time_3;
              self->v_64 = false;
              break;
            case Line_follower__St_Parkleft:
              self->v_61 = time_4;
              self->v_59 = time_4;
              self->v_55 = false;
              break;
            default:
              break;
          };
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

