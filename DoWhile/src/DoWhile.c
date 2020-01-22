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
DoWhile_init(void)
{
    doWhile = &doWhileObj;
    doWhile->state = StateA;
    doWhile->x = 0;
    doWhile->out = 0;
}

int
DoWhile_dispatch(int event)
{
    switch(doWhile->state)
    {
        case StateA:
            switch(event)
            {
                case Start:
                    doWhile->i = 0;
                    doWhile->state = StateB;
                    break;
                case Up:
                    ++doWhile->x;
                    break;
                case Down:
                    if (doWhile->x > 0)
                    {
                        --doWhile->x;
                    }
                    break;
                default:
                    break;
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
