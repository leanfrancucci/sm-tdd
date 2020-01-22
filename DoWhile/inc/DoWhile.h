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
typedef enum Event Event;
enum Event
{
    Start, Alpha, Up, Down
};

typedef enum State State;
enum State
{
    StateA, StateB, StateC
};

/* ------------------------------- Data types ------------------------------ */
typedef struct DoWhile DoWhile;
struct DoWhile
{
    State state;    /* it should be a private attribute */
    int x;          /* it should be a private attribute */
    int i;          /* it should be a private attribute */
    int out;
};

/* -------------------------- External variables --------------------------- */
extern DoWhile *doWhile;

/* -------------------------- Function prototypes -------------------------- */
void DoWhile_init(void);
State DoWhile_dispatch(Event event);

/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif

/* ------------------------------ End of file ------------------------------ */
