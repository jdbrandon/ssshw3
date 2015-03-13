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
  Expr c,e;
  Decl d;
  Const_int i;
  ArrayIndex ai(a,c);
  //cout << "CURRENT TREE: " << CURRENT_TREE << endl;
  int v;
  if(MATCH(d) && MATCH(Contains(a))){
    if(MATCH_TREE(b = c,a)){
    //cout << "arrayexpr: " << b <<endl;
      SET_STATE(b, ((array_type_t*)get_type_of_tree(b))->get_element_count());
    }else{
      //cout << "array: " << a <<endl;
      //cout << "Decl: "<< d << endl;
      //cout << "decl.var(): " << a <<" "<< ((array_type_t*)get_type_of_tree(d.var()))->get_element_count() << endl;
      SET_STATE(a, ((array_type_t*)get_type_of_tree(a))->get_element_count());
    }
  }

  if(MATCH(strncatcall(a,c,i))){
    //cout << "strncat on line num " << current_file_lineno() <<": possible overrun of array bounds. Destination: "<< a << " size: "<< v <<" <= " << i.llval() << endl;
    if(GET_STATE(a,v) && v<=i.llval()){
      cout << endl << "ERROR on line num " << current_file_lineno() <<": possible overrun of array bounds. Destination: "<< a << " size: "<< v <<" <= " << i.llval() << endl;
    }
  }
  
  if(MATCH(i)){
    //cout << "set "<< i << " to "<< i.llval() <<endl;
    SET_STATE(i,i.llval());
  }

  if(MATCH(c = e)){
  }
}

END_EXTEND_CHECKER();

MAKE_MAIN( hello )

// EOF