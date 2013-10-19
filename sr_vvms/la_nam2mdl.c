/****************************************************************
 *								*
 *	Copyright 2001 Sanchez Computer Associates, Inc.	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

/* la_nam2mdl.c : hardware name converted to hardware model
   used in      : la_edit.c, lm_edit.c
*/
#include "mdef.h"
#include "ladef.h"

#define HWSIZ	212
typedef struct
{
	char	nam[HWLEN] ;		/* model name	  */
	short	mdl        ;		/* hardware model */
} hw_model ;
readonly hw_model hw[HWSIZ]=
       {{"\0",0},
	{"V780",         1}, {"V782",         2}, {"V750",         3}, {"V730",         4}, {"V785",         5},
	{"VUV1",         6}, {"VWS1",         7}, {"VUV2",         8}, {"VWS2",         9}, {"VWSD",        10},
	{"V8600",       11}, {"V8650",       12}, {"V8200",       13}, {"V8300",       14}, {"V8530",       15},
	{"V8550",       16}, {"V8700",       17}, {"V8800",       18}, {"VWS2000",     19}, {"VUV2000",     20},
	{"VWSD2000",    21}, {"V009",        22}, {"V8250",       23}, {"V8350",       24}, {"V3600",       25},
	{"V3600W",      26}, {"V3600D",      27}, {"V9CC",        28}, {"V6210_T",     28}, {"V6210",       28},
	{"V3820",       29}, {"V3520L",      30}, {"V8PS",        31}, {"V8840",       31}, {"V9RR",        32},
	{"VUV2_S",      33}, {"VUV2_J",      34}, {"VWS2_T",      35}, {"VWS2_J",      36}, {"VWSD_T",      37},
	{"VWSD_J",      38}, {"VUV2000_S",   39}, {"VUV2000_J",   40}, {"VWS2000_T",   41}, {"VWS2000_J",   42},
	{"VWSD2000_T",  43}, {"VWSD2000_J",  44}, {"V3600_S",     45}, {"V3600_J",     46}, {"V3600W_T",    47},
	{"V3600W_J",    48}, {"V3600D_T",    49}, {"V3600D_J",    50}, {"V3820_S",     51}, {"V3820_J",     52},
	{"V3820L_T",    53}, {"V3520L_J",    54}, {"V8250L",      55}, {"V8250L_J",    56}, {"VCV",         57},
	{"VCVWS",       58}, {"VCVWSD",      59}, {"VCV_S",       60}, {"VCV_J",       61}, {"VCVWS_T",     62},
	{"VCVWS_J",     63}, {"VCVWSD_T",    64}, {"VCVWSD_J",    65}, {"V8500",       66}, {"V8370",       67},
	{"V8650P",      68}, {"V6220_T",     69}, {"V6220",       69}, {"V6230_T",     70}, {"V6230",       70},
	{"V6240_T",     71}, {"V6240",       71}, {"V6250_T",     72}, {"V6250",       72}, {"V6260_T",     73},
 	{"V6260",       73}, {"V6270_T",     74}, {"V6270",       74}, {"V6280_T",     75}, {"V6280",       75},
	{"V6310_T",     76}, {"V6215",       76}, {"V6320_T",     77}, {"V6225",       77}, {"V6330_T",     78},
	{"V6235",       78}, {"V6340_T",     79}, {"V6245",       79}, {"V6350_T",     80}, {"V6255",       80},
	{"V6360_T",     81}, {"V6265",       81}, {"V6370_T",     82}, {"V6275",       82}, {"V6380_T",     83},
	{"V6285",       83}, {"V8810",       84}, {"V8820",       85}, {"V8830",       86}, {"V3400",       87},
	{"V3400W",      88}, {"V3400D",      89}, {"V3400_S",     90}, {"V3400_J",     91}, {"V3400W_T",    92},
	{"V3400W_J",    93}, {"V3400D_T",    94}, {"V3400D_J",    95}, {"VUV2000_O",   96}, {"VWS2000_O",   97},
	{"VWSD2000_O",  98}, {"VWSK2000",    99}, {"V6210_S",    100}, {"V6220_S",    101}, {"V6230_S",    102},
	{"V6240_S",    103}, {"V6250_S",    104}, {"V6260_S",    105}, {"V6270_S",    106}, {"V6280_S",    107},
	{"V6310_S",    108}, {"V6215_S",    108}, {"V6320_S",    109}, {"V6225_S",    109}, {"V6330_S",    110},
	{"V6235_S",    110}, {"V6340_S",    111}, {"V6245_S",    111}, {"V6350_S",    112}, {"V6255_S",    112},
	{"V6360_S",    113}, {"V6265_S",    113}, {"V6370_S",    114}, {"V6275_S",    114}, {"V6380_S",    115},
	{"V6285_S",    115}, {"V6200_J",    116}, {"V6300_J",    117}, {"V6205_J",    117}, {"V3900",      118},
	{"V3900_S",    119}, {"V3900D",     120}, {"V3900D_T",   121}, {"V3900_J",    122}, {"V3900D_J",   123},
	{"V2000A",     124}, {"V2000A_S",   125}, {"V2000AW",    126}, {"V2000AD",    127}, {"V2000AW_T",  128},
	{"V2000AD_T",  129}, {"V2000A_J",   130}, {"V2000AW_J",  131}, {"V2000AD_J",  132}, {"V3840",      133},
	{"V3840_S",    134}, {"V3540L",     135}, {"V3840L_T",   136}, {"V3860",      137}, {"V3860_S",    138},
	{"V3560L",     139}, {"V3860L_T",   140}, {"V3880",      141}, {"V3880_S",    142}, {"V3580L",     143},
	{"V3880L_T",   144}, {"V38A0",      145}, {"V38A0_S",    146}, {"VPV",        147}, {"VPVWS",      148},
	{"VPVWSD",     149}, {"VPV_S",      150}, {"VPV_J",      151}, {"VPVWS_T",    152}, {"VPVWS_J",    153},
	{"VPVWSD_T",   154}, {"VPVWSD_J",   155}, {"VTM",        156}, {"VTM_S",      157}, {"VTM_J",      158},
	{"V9RR10_T",   159}, {"V9RR20_T",   160}, {"V9RR30_T",   161}, {"V9RR40_T",   162}, {"V9RR50_T",   163},
	{"V9RR60_T",   164}, {"V9RR70_T",   165}, {"V9RR80_T",   166}, {"V9RR10_S",   167}, {"V9RR20_S",   168},
	{"V9RR30_S",   169}, {"V9RR40_S",   170}, {"V9RR50_S",   171}, {"V9RR60_S",   172}, {"V9RR70_S",   173},
	{"V9RR80_S",   174}, {"V9RR10_J",   175}, {"Vxxx10",     176}, {"Vxxx20",     177}, {"Vyyy10",     178},
	{"Vyyy20",     179}, {"Vyyy30",     180}, {"Vyyy40",     181}, {"V6305E_T",   182}, {"V6305E_S",   183},
	{"V6305E_J",   184}};

bool la_nam2mdl (
int4	*mdl ,						/* returns - hw. model	*/
short	w ,						/* nam length		*/
char	nam[] )						/* hardware name	*/
{
	int 	k,j ;
	bool	match ;

	if (w>=2 && nam[0]=='0' && nam[1]=='X' )	/* name is hex number	*/
	{
		match = lib$cvt_htb((int4)(w-2),nam+2,mdl) ;
	}
	else						/* name is string V...	*/
	{
		match = (w==0) ; k = 1 ;
		while (!match && k!=HWSIZ)
		{
			j = 0 ;
			while (j!=w && hw[k].nam[j]==nam[j])
			{
				j++ ;
			}
			match = ((j==w) && (hw[k].nam[w]==0)) ;
			k++ ;
		}
		*mdl = hw[k-1].mdl ;
	}
	return match ;
}
