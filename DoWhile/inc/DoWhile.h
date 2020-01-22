/**
 *  \file   DoWhile.h
 *  \brief  Specifies DoWhile module.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci  lf@vortexmakes.com
 */

/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __DOWHILE_H__
#define __DOWHILE_H__

/* ----------------------------- Include files ----------------------------- */
/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
enum
{
    Start, Alpha, Up, Down
};

enum
{
    StateA, StateB, StateC
};

/* ------------------------------- Data types ------------------------------ */
typedef struct DoWhile DoWhile;
struct DoWhile
{
    int state;  /* it should be a private attribute */
    int x;      /* it should be a private attribute */
    int i;      /* it should be a private attribute */
    int out;
};

/* -------------------------- External variables --------------------------- */
extern DoWhile *doWhile;

/* -------------------------- Function prototypes -------------------------- */
void DoWhile_init(void);
int DoWhile_dispatch(int event);

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
