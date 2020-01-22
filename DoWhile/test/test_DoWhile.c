/**
 *  \file   test_DoWhile.c
 *  \brief  Unit test for DoWhile module.
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
#include "unity.h"
#include "DoWhile.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
void 
setUp(void)
{
}

void 
tearDown(void)
{
}

void
test_AfterInitilizingDataAreSet(void)
{
    int x;

    x = 8;
    DoWhile_init(x);

    TEST_ASSERT_EQUAL(StateA, doWhile->state);
    TEST_ASSERT_EQUAL(x, doWhile->x);
    TEST_ASSERT_EQUAL(0, doWhile->out);
}

void
test_SingleIteration(void)
{
    int state, nIter = 1;

    DoWhile_init(nIter);
    state = DoWhile_dispatch(Start);
    state = DoWhile_dispatch(Alpha);

    TEST_ASSERT_EQUAL(StateC, state);
    TEST_ASSERT_EQUAL(nIter, doWhile->out);
}

void
test_MultipleIterations(void)
{
    int i, state, nIter = 4;

    DoWhile_init(nIter);
    state = DoWhile_dispatch(Start);
    for (i = 0; i < nIter; ++i)
    {
        state = DoWhile_dispatch(Alpha);
    }

    TEST_ASSERT_EQUAL(StateC, state);
    TEST_ASSERT_EQUAL(nIter, doWhile->out);
}

void
test_NoneIteration(void)
{
    int i, state, nIter = 0;

    DoWhile_init(nIter);
    state = DoWhile_dispatch(Start);
    for (i = 0; i < nIter; ++i)
    {
        state = DoWhile_dispatch(Alpha);
    }

    TEST_ASSERT_EQUAL(StateB, state);
    TEST_ASSERT_EQUAL(nIter, doWhile->out);
}

/* ------------------------------ End of file ------------------------------ */
