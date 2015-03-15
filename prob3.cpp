/*
  (c) 2004-2014, Coverity, Inc.  All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Coverity, Inc. and its licensors, and is supplied subject to,
  and may be used only by Coverity customers in accordance with the terms and
  conditions of a previously executed license agreement between Coverity and that
  customer.
*/

// s3_no_rand_mod.cpp

#include "extend-lang.hpp"     // Extend API

START_EXTEND_CHECKER( s3_no_rand_mod, int_store );

ANALYZE_TREE()
{
  CallSite randcall("rand");
  Var a,e;
  Expr b,c,d;
  int v,w;
  
  if(MATCH(a = b)){
    //cout << "assigning: " << a << "value: " << b << endl;
    if(GET_STATE(a,v) && v == 1){
      if(!(GET_STATE(b,w) && w == 1)){
        OUTPUT_ERROR("possible bug: previously random variable changed to not random" << CURRENT_TREE);
        cout << "Detected bug "<< a << " assigned to not random" << CURRENT_TREE << endl;
        SET_STATE(a,2);
      }
    }
    if(GET_STATE(b,v) && v == 2){
      cout << "ERROR: assigned non-random value" << CURRENT_TREE << endl;
    }else if(GET_STATE(b,v) && v == 1){
      cout << "Assigning "<< a << " to random" << CURRENT_TREE << endl;
      SET_STATE(a,1);
    }

  }

  if(((MATCH(b + c)|| MATCH(b - c) || MATCH(b / c) || MATCH(b * c)) && ((GET_STATE(b,v)) || (GET_STATE(c,w)))) || MATCH(randcall)){
    if(MATCH(randcall) || v == 1 || w == 1){
      SET_STATE(CURRENT_TREE,1);
    }else if(v == 2 || w == 2){
      SET_STATE(CURRENT_TREE,2);
      OUTPUT_ERROR("possible bug: previously random variable changed to not random" << CURRENT_TREE);
      cout << "Detected bug assigned to not random" << CURRENT_TREE << endl;

    }

    
  }

  if(MATCH(Addr(e))){
    cout << "addr " << e << " " << CURRENT_TREE << endl;
    COPY_STATE(CURRENT_TREE, e);
  }

  if(MATCH(Pointer(a) = b) && GET_STATE(b,v)){
    cout << "pointer " << a << b << CURRENT_TREE << endl;
    COPY_STATE(a,b);
    COPY_STATE(CURRENT_TREE,a);
  }

  if(MATCH(Star(a) = b)){
    cout << "star " << a << b <<CURRENT_TREE<< endl;
    if(GET_STATE(a,v) && v == 1){
      if(!(GET_STATE(b,v) && v==1)){
        OUTPUT_ERROR("possible bug: previously random variable changed to not random" << CURRENT_TREE);
        cout << "Detected bug assigned to not random" << CURRENT_TREE << endl;
        SET_STATE(a,2);
        SET_STATE(CURRENT_TREE,2);
      }
    }
  }
  //if(MATCH(a = randcall)) {
   //   cout << "Assigning "<< a << " to random" << CURRENT_TREE << endl;
   // SET_STATE(a,1);
 // }
}

END_EXTEND_CHECKER();

MAKE_MAIN( s3_no_rand_mod )

// EOF