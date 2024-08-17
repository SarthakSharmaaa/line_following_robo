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

void Line_follower__pid_step(int sen0, int sen1, int sen2, int sen3,
                             int sen4, Line_follower__pid_out* _out,
                             Line_follower__pid_mem* self) {
  
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_4;
  int v_1;
  int v;
  int error;
  int i;
  int p;
  int d;
  int temp;
  int pid;
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

void Line_follower__cpid_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, Line_follower__cpid_out* _out,
                              Line_follower__cpid_mem* self) {
  
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_20;
  int v_17;
  int v_16;
  int v;
  int e;
  int i;
  int d;
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

void Line_follower__left_step(int dir, int sen0, int sen1, int sen2,
                              int sen3, int sen4,
                              Line_follower__left_out* _out,
                              Line_follower__left_mem* self) {
  Line_follower__cpid_out Line_follower__cpid_out_st;
  
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v;
  int d[6];
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

void Line_follower__right_step(int dir, int sen0, int sen1, int sen2,
                               int sen3, int sen4,
                               Line_follower__right_out* _out,
                               Line_follower__right_mem* self) {
  Line_follower__cpid_out Line_follower__cpid_out_st;
  
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v;
  int d[6];
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

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int ir_left, int ir_right, int sec,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Line_follower__left_out Line_follower__left_out_st;
  Line_follower__right_out Line_follower__right_out_st;
  
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v;
  int r_4_St_2_Black;
  Line_follower__st_2 s_2_St_2_Black;
  int r_4_St_2_White;
  Line_follower__st_2 s_2_St_2_White;
  int v_62;
  int v_60;
  int v_58;
  int v_57;
  int v_56;
  int v_54;
  int time_4;
  int v_71;
  int v_69;
  int v_67;
  int v_66;
  int v_65;
  int v_63;
  int time_3;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_73;
  int v_72;
  int v_99;
  int v_97;
  int v_95;
  int v_94;
  int v_93;
  int v_91;
  Line_follower__st v_90;
  int v_89;
  Line_follower__st v_88;
  int v_87;
  Line_follower__st v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int time_2;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_130;
  int v_129;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_115;
  int v_113;
  int v_112;
  int v_111;
  int v_109;
  int time_1;
  int v_131;
  int nr_St_Parked;
  Line_follower__st ns_St_Parked;
  int cntr_St_Parked;
  int cntl_St_Parked;
  int dir_St_2_Black_St_1_DoParking_St_Parked;
  int v_r_St_2_Black_St_1_DoParking_St_Parked;
  int v_l_St_2_Black_St_1_DoParking_St_Parked;
  int nr_St_Parkleft;
  Line_follower__st ns_St_Parkleft;
  int cntr_St_Parkleft;
  int cntl_St_Parkleft;
  int dir_St_2_Black_St_1_DoParking_St_Parkleft;
  int v_r_St_2_Black_St_1_DoParking_St_Parkleft;
  int v_l_St_2_Black_St_1_DoParking_St_Parkleft;
  int nr_St_Parkright;
  Line_follower__st ns_St_Parkright;
  int cntr_St_Parkright;
  int cntl_St_Parkright;
  int dir_St_2_Black_St_1_DoParking_St_Parkright;
  int v_r_St_2_Black_St_1_DoParking_St_Parkright;
  int v_l_St_2_Black_St_1_DoParking_St_Parkright;
  int nr_St_Reset;
  Line_follower__st ns_St_Reset;
  int cntr_St_Reset;
  int cntl_St_Reset;
  int dir_St_2_Black_St_1_DoParking_St_Reset;
  int v_r_St_2_Black_St_1_DoParking_St_Reset;
  int v_l_St_2_Black_St_1_DoParking_St_Reset;
  int nr_St_Inter;
  Line_follower__st ns_St_Inter;
  int cntr_St_Inter;
  int cntl_St_Inter;
  int dir_St_2_Black_St_1_DoParking_St_Inter;
  int v_r_St_2_Black_St_1_DoParking_St_Inter;
  int v_l_St_2_Black_St_1_DoParking_St_Inter;
  int nr_St_Check;
  Line_follower__st ns_St_Check;
  int cntr_St_Check;
  int cntl_St_Check;
  int dir_St_2_Black_St_1_DoParking_St_Check;
  int v_r_St_2_Black_St_1_DoParking_St_Check;
  int v_l_St_2_Black_St_1_DoParking_St_Check;
  int nr_St_Startpark;
  Line_follower__st ns_St_Startpark;
  int cntr_St_Startpark;
  int cntl_St_Startpark;
  int dir_St_2_Black_St_1_DoParking_St_Startpark;
  int v_r_St_2_Black_St_1_DoParking_St_Startpark;
  int v_l_St_2_Black_St_1_DoParking_St_Startpark;
  Line_follower__st ck_3;
  int v_137;
  int v_135;
  int v_133;
  Line_follower__st ns;
  int r_2;
  int nr;
  int pnr;
  int cntr_1;
  int cntl_1;
  int cntl;
  int cntr;
  int v_146;
  int v_144;
  int v_142;
  int v_141;
  int v_139;
  int time;
  int v_167;
  int v_166;
  int v_165;
  int v_164;
  int v_163;
  int v_162;
  int v_161;
  int v_160;
  int v_159;
  int v_158;
  Line_follower__st_1 v_157;
  int v_156;
  int v_155;
  int v_154;
  int v_153;
  int v_152;
  int v_151;
  int v_150;
  int v_149;
  int v_148;
  int v_147;
  int v_176;
  int v_175;
  int v_174;
  int v_173;
  int v_172;
  int v_171;
  int v_170;
  int v_169;
  int v_168;
  int v_219;
  int v_218;
  int v_217;
  int v_216;
  int v_215;
  int v_214;
  int v_213;
  int v_212;
  int v_211;
  int v_210;
  Line_follower__st_1 v_209;
  int v_208;
  int v_207;
  int v_206;
  int v_205;
  int v_204;
  int v_203;
  int v_202;
  int v_201;
  int v_200;
  int v_199;
  int v_198;
  int v_197;
  int v_196;
  int v_195;
  int v_194;
  int v_193;
  int v_192;
  int v_191;
  int v_190;
  int v_189;
  int v_188;
  int v_187;
  int v_186;
  int v_185;
  int v_184;
  int v_183;
  int v_182;
  int v_181;
  int v_180;
  int v_179;
  int v_178;
  int v_177;
  int nr_1_St_1_DoParking;
  Line_follower__st_1 ns_1_St_1_DoParking;
  int count1_St_1_DoParking;
  int count_St_2_Black_St_1_DoParking;
  int dir_St_2_Black_St_1_DoParking;
  int v_r_St_2_Black_St_1_DoParking;
  int v_l_St_2_Black_St_1_DoParking;
  int nr_1_St_1_StopTemp;
  Line_follower__st_1 ns_1_St_1_StopTemp;
  int count1_St_1_StopTemp;
  int count_St_2_Black_St_1_StopTemp;
  int dir_St_2_Black_St_1_StopTemp;
  int v_r_St_2_Black_St_1_StopTemp;
  int v_l_St_2_Black_St_1_StopTemp;
  int nr_1_St_1_Straight2;
  Line_follower__st_1 ns_1_St_1_Straight2;
  int count1_St_1_Straight2;
  int count_St_2_Black_St_1_Straight2;
  int dir_St_2_Black_St_1_Straight2;
  int v_r_St_2_Black_St_1_Straight2;
  int v_l_St_2_Black_St_1_Straight2;
  int nr_1_St_1_Straight1;
  Line_follower__st_1 ns_1_St_1_Straight1;
  int count1_St_1_Straight1;
  int count_St_2_Black_St_1_Straight1;
  int dir_St_2_Black_St_1_Straight1;
  int v_r_St_2_Black_St_1_Straight1;
  int v_l_St_2_Black_St_1_Straight1;
  int nr_1_St_1_Straight;
  Line_follower__st_1 ns_1_St_1_Straight;
  int count1_St_1_Straight;
  int count_St_2_Black_St_1_Straight;
  int dir_St_2_Black_St_1_Straight;
  int v_r_St_2_Black_St_1_Straight;
  int v_l_St_2_Black_St_1_Straight;
  Line_follower__st_1 ck_2;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_47;
  int v_45;
  int v_43;
  int v_41;
  int v_40;
  Line_follower__st_1 ns_1;
  int r_3;
  int nr_1;
  int pnr_1;
  int count1_1;
  int error1;
  int p1;
  int i1;
  int d1;
  int temp1;
  int pid1;
  int count1;
  int v_240;
  int v_239;
  int v_238;
  int v_237;
  int v_236;
  int v_235;
  int v_234;
  int v_233;
  int v_232;
  int v_231;
  int v_230;
  int v_229;
  int v_228;
  int v_227;
  int v_226;
  int v_225;
  int v_224;
  int v_223;
  int r_6;
  int r_5;
  int l;
  int r;
  int sum;
  int nr_2_St_2_Black;
  Line_follower__st_2 ns_2_St_2_Black;
  int count_St_2_Black;
  int sen_St_2_Black[5];
  int dir_St_2_Black;
  int v_r_St_2_Black;
  int v_l_St_2_Black;
  int nr_2_St_2_White;
  Line_follower__st_2 ns_2_St_2_White;
  int count_St_2_White;
  int sen_St_2_White[5];
  int dir_St_2_White;
  int v_r_St_2_White;
  int v_l_St_2_White;
  Line_follower__st_2 ck_1;
  Line_follower__st_2 s_2;
  Line_follower__st_2 ns_2;
  int r_4;
  int nr_2;
  int sen[5];
  int count;
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
        int _3;
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
        int _4;
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

