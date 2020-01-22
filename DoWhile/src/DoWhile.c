/**
 *  \file   DoWhile.c
 *  \brief  Implements the DoWhile specifications.
 */

/* -------------------------- Development history -------------------------- */
/*
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci  lf@vortexmakes.com
 */

/* --------------------------------- Notes --------------------------------- */
/* ----------------------------- Include files ----------------------------- */
#include "DoWhile.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
DoWhile *doWhile = (DoWhile *)0;

/* ---------------------------- Local variables ---------------------------- */
static DoWhile doWhileObj;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
void
DoWhile_init(int x)
{
    doWhile = &doWhileObj;
    doWhile->state = StateA;
    doWhile->x = x;
    doWhile->out = 0;
}

int
DoWhile_dispatch(int event)
{
    switch(doWhile->state)
    {
        case StateA:
            if (event == Start)
            {
                doWhile->i = 0;
                doWhile->state = StateB;
            }
            break;
        case StateB:
            if (event == Alpha)
            {
                ++doWhile->i;
                if (doWhile->i == doWhile->x)
                {
                    doWhile->out = doWhile->i;
                    doWhile->state = StateC;
                }
            }
            break;
        default:
            break;
    }
    return doWhile->state;
}

/* ------------------------------ End of file ------------------------------ */
