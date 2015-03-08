/*
  (c) 2003-2014, Coverity, Inc.  All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Coverity, Inc. and its licensors, and is supplied subject to,
  and may be used only by Coverity customers in accordance with the terms and
  conditions of a previously executed license agreement between Coverity and that
  customer.
*/

// test1/hello.test.c
// test input for 'hello' checker

int foo()
{
  int x = 1;
  x += 5;
  int y = rand();
  //y = 0;
  x = y + 5;
  strcat(0,0);
  strcpy(0,0);
  return x;
}

// EOF