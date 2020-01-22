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
    DoWhile_init();

    TEST_ASSERT_EQUAL(0, doWhile->x);
    TEST_ASSERT_EQUAL(0, doWhile->out);
    TEST_ASSERT_EQUAL(StateA, doWhile->state);
}

void
test_IncrementX(void)
{
    int state, nStep = 4, i;

    DoWhile_init();
    for (i = 0; i < nStep; ++i)
    {
        state = DoWhile_dispatch(Up);
    }

    TEST_ASSERT_EQUAL(nStep, doWhile->x);
    TEST_ASSERT_EQUAL(StateA, state);
}

void
test_DecrementX(void)
{
    int state;

    DoWhile_init();
    state = DoWhile_dispatch(Up);
    state = DoWhile_dispatch(Up);
    state = DoWhile_dispatch(Up);
    state = DoWhile_dispatch(Down);

    TEST_ASSERT_EQUAL(2, doWhile->x);
    TEST_ASSERT_EQUAL(StateA, state);
}

void
test_OutOfBoundsChangesNothing(void)
{
    int state;

    DoWhile_init();
    state = DoWhile_dispatch(Down);

    TEST_ASSERT_EQUAL(0, doWhile->x);
    TEST_ASSERT_EQUAL(StateA, state);
}

void
test_SingleIteration(void)
{
    int state;

    DoWhile_init();
    state = DoWhile_dispatch(Up);
    state = DoWhile_dispatch(Start);
    state = DoWhile_dispatch(Alpha);

    TEST_ASSERT_EQUAL(StateC, state);
    TEST_ASSERT_EQUAL(1, doWhile->out);
}

void
test_MultipleIterations(void)
{
    int i, state, nIter = 4;

    DoWhile_init();
    for (i = 0; i < nIter; ++i)
    {
        state = DoWhile_dispatch(Up);
    }
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
    int state;

    DoWhile_init();
    state = DoWhile_dispatch(Start);
    state = DoWhile_dispatch(Alpha);

    TEST_ASSERT_EQUAL(StateB, state);
    TEST_ASSERT_EQUAL(0, doWhile->out);
}

/* ------------------------------ End of file ------------------------------ */
