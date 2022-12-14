/*
 * Copyright (c) 2011-2014, 2017, 2021 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/*===========================================================================

                     radar_filters.h

  OVERVIEW:

  Source code borrowed from QCA_MAIN DFS module

  DEPENDENCIES:

  Are listed for each API below.

===========================================================================*/

/*===========================================================================

                      EDIT HISTORY FOR FILE


  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.



  when        who     what, where, why
----------    ---    --------------------------------------------------------

===========================================================================*/





struct dfs_pulse dfs_fcc_radars[] = {
    // FCC NEW TYPE 0
    // {18,  1,  325, 1930, 0,  6,  7,  0,  1, 18,  0, 3,  0}, // 518 to 3066
    {18,  1,  700, 700, 0,  4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 0},
    {18,  1,  350, 350, 0,  4,  5,  0,  1, 18,  0, 3,  0, 5, 0, 0},

    // FCC TYPE 6
    // {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1}, // 333 +/- 7 us
    {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1, 1000, 0, 1},

    // FCC TYPE 2
    {23, 5, 4347, 6666, 0, 4, 8,  0,  7, 22,  0, 3,  0, 5, 0, 2},

    // FCC TYPE 3
    {18, 10, 2000, 5000, 0, 4,  6,  6, 13, 20,  0, 3, 0, 5, 0, 5},

    // FCC TYPE 4
    {16, 15, 2000, 5000, 0, 4,  5, 11, 23, 20,  0, 3, 0, 5, 0, 11},

    /*
     * FCC NEW TYPE 1
     * 518us to 938us pulses (min 56 pulses)
     */
    {57, 1, 1066, 1930, 0, 4, 20,  0,  1, 22,  0, 3,  0, 5, 0, 21},

    /*
     * FCC NEW TYPE 1
     * 938us to 2000 pulses (min 26 pulses)
     */
    {27, 1,  500, 1066, 0, 4, 13,  0,  1, 22,  0, 3,  0, 5, 0, 22},

    /*
     * FCC NEW TYPE 1
     * 2000 to 3067us pulses (min 17 pulses)
     */
    {18, 1,  325,  500, 0, 4, 9,  0,  1, 22,  0, 3,  0, 5, 0, 23},

};

struct dfs_pulse dfs_mkk4_radars[] = {
    /* following two filters are specific to Japan/MKK4 */
//    {18,  1,  720,  720, 1,  6,  6,  0,  1, 18,  0, 3, 17}, // 1389 +/- 6 us
//    {18,  4,  250,  250, 1, 10,  5,  1,  6, 18,  0, 3, 18}, // 4000 +/- 6 us
//    {18,  5,  260,  260, 1, 10,  6,  1,  6, 18,  0, 3, 19}, // 3846 +/- 7 us
    {18, 1, 720, 720, 0, 4, 6, 0, 1, 18, 0, 3, 0, 5, 0, 17}, // 1389 +/- 6 us
    {18, 4, 250, 250, 0, 4, 5, 1, 6, 18, 0, 3, 0, 5, 0, 18}, // 4000 +/- 6 us
    {18, 5, 260, 260, 0, 4, 6, 1, 6, 18, 0, 3, 1, 5, 0, 19}, // 3846 +/- 7 us

    /* following filters are common to both FCC and JAPAN */

    // FCC TYPE 1
    // {18,  1,  325, 1930, 0,  6,  7,  0,  1, 18,  0, 3,  0}, // 518 to 3066
    {18,  1,  700, 700, 0,  4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 0},
    {18,  1,  350, 350, 0,  4,  5,  0,  1, 18,  0, 3,  0, 5, 0, 0},

    // FCC TYPE 6
    // {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0,  1}, // 333 +/- 7 us
    {9,   1, 3003, 3003, 1,  7,  5,  0,  1, 18,  0, 0, 1, 1000, 0, 1},

    // FCC TYPE 2
    {23, 5, 4347, 6666, 0, 4, 8,  0,  7, 22,  0, 3,  0, 5, 0, 2},

    // FCC TYPE 3
    {18, 10, 2000, 5000, 0, 4,  6,  6, 13, 22,  0, 3, 0, 5, 0, 5},

    // FCC TYPE 4
    {16, 15, 2000, 5000, 0, 4,  5, 11, 23, 22,  0, 3, 0, 5, 0, 11},
};

struct dfs_bin5pulse dfs_fcc_bin5pulses[] = {
        {5, 28, 105, 12, 17, 5},
};

struct dfs_bin5pulse dfs_jpn_bin5pulses[] = {
        {5, 28, 105, 12, 22, 5},
};
struct dfs_pulse dfs_etsi_radars[] = {

    /* TYPE staggered pulse */
    /* 0.8-2us, 2-3 bursts,300-400 PRF, 10 pulses each */
    {30, 2, 300, 400, 2, 30, 3, 0, 5, 15, 0, 0, 1, 5, 0, 31},   /* Type 5*/
    /* 0.8-2us, 2-3 bursts, 400-1200 PRF, 15 pulses each */
    {30, 2, 400, 1200, 2, 30, 7, 0, 5, 15, 0, 0, 0, 5, 0, 32},   /* Type 6 */

    /* constant PRF based */
    /* 0.8-5us, 200  300 PRF, 10 pulses */
    {10, 5, 200, 400, 0, 4, 5, 0, 8, 15, 0, 0, 2, 5, 0, 33},   /* Type 1 */
    {10, 5, 400, 600, 0, 4, 5, 0, 8, 15, 0, 0, 2, 5, 0, 37},   /* Type 1 */
    {10, 5, 600, 800, 0, 4, 5, 0, 8, 15, 0, 0, 2, 5, 0, 38},   /* Type 1 */
    {10, 5, 800, 1000, 0, 4, 5, 0, 8, 15, 0, 0, 2, 5, 0, 39},   /* Type 1 */
//  {10, 5,   200, 1000, 0, 24,  5,  0,  8, 15, 0,   0, 2, 33},

    /* 0.8-15us, 200-1600 PRF, 15 pulses */
    {15, 15, 200, 1600, 0, 4, 8, 0, 18, 22, 0, 0, 0, 5, 0, 34},    /* Type 2 */

    /* 0.8-15us, 2300-4000 PRF, 25 pulses*/
    {25, 15, 2300, 4000, 0, 4, 10, 0, 18, 22, 0, 0, 0, 5, 0, 35},  /* Type 3 */

    /* 20-30us, 2000-4000 PRF, 20 pulses*/
    {20, 30, 2000, 4000, 0, 4, 6, 19, 33, 24, 0, 0, 0, 24, 0, 36}, /* Type 4 */
};

/**
 * dfs_pulse dfs_china_radars - CHINA radar table.
 */
static struct dfs_pulse dfs_china_radars[] = {

	/* TYPE staggered pulse */
	/* Type 5*/
	/* 0.8-2us, 2-3 bursts,300-400 PRF, 12 pulses each */
	{36,  2,  300,  400, 2, 30,  3,  0,  5, 15, 0,   0, 1, 51},
	/* Type 6 */
	/* 0.8-2us, 2-3 bursts, 400-1200 PRF, 16 pulses each */
	{48,  2,  400, 1200, 2, 30,  7,  0,  5, 15, 0,   0, 0, 52},

	/* constant PRF based */
	/* Type 1 */
	/* 0.5-5us, 200  1000 PRF, 12 pulses */
	{12, 5,   200,  400, 0, 24,  5,  0,  8, 15, 0,   0, 2, 53},
	{12, 5,   400,  600, 0, 24,  5,  0,  8, 15, 0,   0, 2, 57},
	{12, 5,   600,  800, 0, 24,  5,  0,  8, 15, 0,   0, 2, 58},
	{12, 5,   800, 1000, 0, 24,  5,  0,  8, 15, 0,   0, 2, 59},

	/* Type 2 */
	/* 0.5-15us, 200-1600 PRF, 16 pulses */
	{16, 15,  200, 1600, 0, 24, 8,  0, 18, 24, 0,   0, 0, 54},

	/* Type 3 */
	/* 0.5-30us, 2300-4000 PRF, 24 pulses*/
	{24, 15, 2300, 4000,  0, 24, 10, 0, 33, 24, 0,   0, 0, 55},

	/* Type 4 */
	/* 20-30us, 2000-4000 PRF, 20 pulses*/
	{20, 30, 2000, 4000, 0, 24, 6, 19, 33, 24, 0,   0, 0, 56},

	/* 1us, 1000 PRF, 20 pulses */
	/* 1000 us PRI */
	{20,  1, 1000, 1000, 0,  6,  6,  0,  1, 18,  0, 3, 0, 50},
};

/**
 * dfs_pulse dfs_korea_radars - KOREA radar table.
 */
static struct dfs_pulse dfs_korea_radars[] = {
	/* Korea Type 1 */
	{18,  1,  700, 700,  0, 4,  5,  0,  1, 18,  0, 3,  1, 5, 0, 40},

	/* Korea Type 2 */
	{10,  1, 1800, 1800, 0, 4,  4,  0,  1, 18,  0, 3,  1, 5, 0, 41},

	/* Korea Type 3 */
	{70,  1,  330, 330,  0, 4, 20,  0,  2, 18,  0, 3,  1, 5, 0, 42},

	/* Korea Type 4 */
	{3,   1, 3003, 3003, 1, 7,  2,  0,  1, 18,  0, 0, 1,  1000, 0, 43},
};
