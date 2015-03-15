/*
  (c) 2004-2014, Coverity, Inc.  All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Coverity, Inc. and its licensors, and is supplied subject to,
  and may be used only by Coverity customers in accordance with the terms and
  conditions of a previously executed license agreement between Coverity and that
  customer.
*/

// s4_shift_negative.cpp

#include "extend-lang.hpp"     // Extend API

START_EXTEND_CHECKER( s4_shift_negative, int_store );

ANALYZE_TREE()
{
  Var a;
  Expr b,c;
  Const_int d;
  int v;
  
  if(MATCH(d)){
    if(d.llval() < 0){
      SET_STATE(CURRENT_TREE,0);
    }else if(d.llval() == 0){
      SET_STATE(CURRENT_TREE,1);
    }else if(d.llval() > 0){
      SET_STATE(CURRENT_TREE,2);
    }
    
  }
  if(MATCH(a = b)){
    COPY_STATE(a,b);
  }

  if(MATCH(b << c) || MATCH(b >> c)){
    if(GET_STATE(c,v) && v == 0){
      OUTPUT_ERROR("should not bit shift by a negative number");
      //cout << "ERROR: Cannot bit shift by a negative number " << CURRENT_TREE << endl;
    }
  }
}

END_EXTEND_CHECKER();

MAKE_MAIN( s4_shift_negative )

// EOF