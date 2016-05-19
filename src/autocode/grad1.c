/*
 * Qcint is a general GTO integral library for computational chemistry
 * Copyright (C) 2014- Qiming Sun <osirpt.sun@gmail.com>
 *
 * This file is part of Qcint.
 *
 * Qcint is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Description: code generated by  gen-code.cl
 */
#include <pmmintrin.h>
#include <stdlib.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g2e.h"
#include "g3c2e.h"
#include "g2c2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "fblas.h"
#include "c2f.h"
/* <NABLA i|OVLP |j> */
static void CINTgout1e_cint1e_ipovlp_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout += 3;
}}
FINT cint1e_ipovlp_sph(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ipovlp_sph;
return CINT1e_drv(opij, &envs, 1, &c2s_sph_1e); }
C2F_(cint1e_ipovlp_sph)
/* <NABLA i|OVLP |P DOT P j> */
static void CINTgout1e_cint1e_ipkin_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double *g3 = g2  + envs->g_size * 3;
double *g4 = g3  + envs->g_size * 3;
double *g5 = g4  + envs->g_size * 3;
double *g6 = g5  + envs->g_size * 3;
double *g7 = g6  + envs->g_size * 3;
double *g8 = g7  + envs->g_size * 3;
double s[27];
G1E_D_J(g1, g0, i_l+1, j_l+0);
G1E_D_J(g2, g0, i_l+1, j_l+1);
G1E_D_J(g3, g2, i_l+1, j_l+0);
G1E_D_I(g4, g0, i_l+0, j_l);
G1E_D_I(g5, g1, i_l+0, j_l);
G1E_D_I(g6, g2, i_l+0, j_l);
G1E_D_I(g7, g3, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g7[ix] * g0[iy] * g0[iz];
s[1] = g6[ix] * g1[iy] * g0[iz];
s[2] = g6[ix] * g0[iy] * g1[iz];
s[3] = g5[ix] * g2[iy] * g0[iz];
s[4] = g4[ix] * g3[iy] * g0[iz];
s[5] = g4[ix] * g2[iy] * g1[iz];
s[6] = g5[ix] * g0[iy] * g2[iz];
s[7] = g4[ix] * g1[iy] * g2[iz];
s[8] = g4[ix] * g0[iy] * g3[iz];
s[9] = g3[ix] * g4[iy] * g0[iz];
s[10] = g2[ix] * g5[iy] * g0[iz];
s[11] = g2[ix] * g4[iy] * g1[iz];
s[12] = g1[ix] * g6[iy] * g0[iz];
s[13] = g0[ix] * g7[iy] * g0[iz];
s[14] = g0[ix] * g6[iy] * g1[iz];
s[15] = g1[ix] * g4[iy] * g2[iz];
s[16] = g0[ix] * g5[iy] * g2[iz];
s[17] = g0[ix] * g4[iy] * g3[iz];
s[18] = g3[ix] * g0[iy] * g4[iz];
s[19] = g2[ix] * g1[iy] * g4[iz];
s[20] = g2[ix] * g0[iy] * g5[iz];
s[21] = g1[ix] * g2[iy] * g4[iz];
s[22] = g0[ix] * g3[iy] * g4[iz];
s[23] = g0[ix] * g2[iy] * g5[iz];
s[24] = g1[ix] * g0[iy] * g6[iz];
s[25] = g0[ix] * g1[iy] * g6[iz];
s[26] = g0[ix] * g0[iy] * g7[iz];
gout[0] += + (-1*s[0]) + (-1*s[4]) + (-1*s[8]);
gout[1] += + (-1*s[9]) + (-1*s[13]) + (-1*s[17]);
gout[2] += + (-1*s[18]) + (-1*s[22]) + (-1*s[26]);
gout += 3;
}}
FINT cint1e_ipkin_sph(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ipkin_sph;
return CINT1e_drv(opij, &envs, 0.5, &c2s_sph_1e); }
C2F_(cint1e_ipkin_sph)
/* <NABLA i|NUC |j> */
static void CINTgout1e_cint1e_ipnuc_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout += 3;
}}
FINT cint1e_ipnuc_sph(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_ipnuc_sph;
return CINT1e_nuc_drv(opij, &envs, 1, &c2s_sph_1e); }
C2F_(cint1e_ipnuc_sph)
/* <NABLA i|RINV |j> */
static void CINTgout1e_cint1e_iprinv_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double *g2 = g1  + envs->g_size * 3;
double s[3];
G1E_D_I(g1, g0, i_l+0, j_l);
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g1[ix] * g0[iy] * g0[iz];
s[1] = g0[ix] * g1[iy] * g0[iz];
s[2] = g0[ix] * g0[iy] * g1[iz];
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout += 3;
}}
FINT cint1e_iprinv_sph(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_iprinv_sph;
return CINT1e_rinv_drv(opij, &envs, 1, &c2s_sph_1e); }
C2F_(cint1e_iprinv_sph)
/* <i|RINV |j> */
static void CINTgout1e_cint1e_rinv_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0  + envs->g_size * 3;
double s[1];
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
s[0] = g0[ix] * g0[iy] * g0[iz];
gout[0] += + s[0];
gout += 1;
}}
FINT cint1e_rinv_sph(double *opij, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {0, 0, 0, 0, 0, 1, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_cint1e_rinv_sph;
return CINT1e_rinv_drv(opij, &envs, 1, &c2s_sph_1e); }
C2F_(cint1e_rinv_sph)
/* <k NABLA i|R12 |j l> : i,j \in electron 1; k,l \in electron 2
 * = (NABLA i j|R12 |k l) */
static void CINTgout2e_cint2e_ip1_sph(double *g,
double *gout, const FINT *idx, const CINTEnvVars *envs, FINT gout_empty) {
const double *env = envs->env;
const FINT nf = envs->nf;
const FINT i_l = envs->i_l;
const FINT j_l = envs->j_l;
const FINT k_l = envs->k_l;
const FINT l_l = envs->l_l;
const double *ri = envs->ri;
const double *rj = envs->rj;
const double *rk = envs->rk;
const double *rl = envs->rl;
FINT ix, iy, iz, i, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double s[3];
G2E_D_I(g1, g0, i_l+0, j_l, k_l, l_l);
__m128d r0, r1, r2, r3;
for (n = 0; n < nf; n++, idx+=3) {
ix = idx[0];
iy = idx[1];
iz = idx[2];
switch (envs->nrys_roots) {
case 1:
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
break;
case 2:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
break;
case 3:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
s[0] += g1[ix+2] * g0[iy+2] * g0[iz+2];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
s[1] += g0[ix+2] * g1[iy+2] * g0[iz+2];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
s[2] += g0[ix+2] * g0[iy+2] * g1[iz+2];
break;
case 4:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g1+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g1+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
break;
case 5:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g1+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
s[0] += g1[ix+4] * g0[iy+4] * g0[iz+4];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g1+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
s[1] += g0[ix+4] * g1[iy+4] * g0[iz+4];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
s[2] += g0[ix+4] * g0[iy+4] * g1[iz+4];
break;
case 6:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g1+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g1+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g1+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g1+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
break;
case 7:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g1+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g1+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
s[0] += g1[ix+6] * g0[iy+6] * g0[iz+6];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g1+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g1+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
s[1] += g0[ix+6] * g1[iy+6] * g0[iz+6];
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
s[2] += g0[ix+6] * g0[iy+6] * g1[iz+6];
break;
default:
r0 = _mm_load_pd(g1+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g1+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g1+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g1+ix+6);
r1 = _mm_load_pd(g0+iy+6);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+6);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+0, r0);
for (i = 8; i < envs->nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];}
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g1+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g0+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g1+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g1+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+6);
r1 = _mm_load_pd(g1+iy+6);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g0+iz+6);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+1, r0);
for (i = 8; i < envs->nrys_roots; i++) {
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];}
r0 = _mm_load_pd(g0+ix  );
r1 = _mm_load_pd(g0+iy  );
r0 = _mm_mul_pd(r0, r1);
r1 = _mm_load_pd(g1+iz  );
r0 = _mm_mul_pd(r0, r1);
r2 = _mm_load_pd(g0+ix+2);
r1 = _mm_load_pd(g0+iy+2);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+2);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+4);
r1 = _mm_load_pd(g0+iy+4);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+4);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r2 = _mm_load_pd(g0+ix+6);
r1 = _mm_load_pd(g0+iy+6);
r2 = _mm_mul_pd(r2, r1);
r1 = _mm_load_pd(g1+iz+6);
r2 = _mm_mul_pd(r2, r1);
r0 = _mm_add_pd(r0, r2);
r0 = _mm_hadd_pd(r0, r0);
_mm_storeh_pd(s+2, r0);
for (i = 8; i < envs->nrys_roots; i++) {
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];}
break;}
if (gout_empty) {
gout[0] = + s[0];
gout[1] = + s[1];
gout[2] = + s[2];
gout += 3;
} else {
gout[0] += + s[0];
gout[1] += + s[1];
gout[2] += + s[2];
gout += 3;
}}}
void cint2e_ip1_sph_optimizer(CINTOpt **opt, const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTuse_all_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
FINT cint2e_ip1_sph(double *opijkl, const FINT *shls,
const FINT *atm, const FINT natm,
const FINT *bas, const FINT nbas, const double *env, CINTOpt *opt) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int2e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout2e_cint2e_ip1_sph;
envs.common_factor *= 1;
return CINT2e_spheric_drv(opijkl, &envs, opt);
}
OPTIMIZER2F_(cint2e_ip1_sph_optimizer);
C2Fo_(cint2e_ip1_sph)
