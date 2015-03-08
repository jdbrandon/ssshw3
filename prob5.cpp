/*
  (c) 2004-2014, Coverity, Inc.  All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Coverity, Inc. and its licensors, and is supplied subject to,
  and may be used only by Coverity customers in accordance with the terms and
  conditions of a previously executed license agreement between Coverity and that
  customer.
*/

// hello.c
// trivial Extend checker

#include "extend-lang.hpp"     // Extend API

START_EXTEND_CHECKER( hello, int_store );

ANALYZE_TREE()
{
  CallSite strncatcall("strncat");
  Array a,b;
  Expr c;
  Const_int d;
  
  int v;
  if(MATCH(a)){
    cout << "array: " << a <<endl;
  }

  if(MATCH(strncatcall(a,b,c))){

    cout << "strncatcall "<< a << " " << b << " " << c <<endl;
  }
  
  if(MATCH(d)){
    SET_STATE(d,d.llval());
  }

  if(MATCH(a = b)){
    COPY_STATE(a,b);
  }
}

END_EXTEND_CHECKER();

MAKE_MAIN( hello )

// EOF