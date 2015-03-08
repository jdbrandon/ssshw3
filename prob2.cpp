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

START_EXTEND_CHECKER( hello, simple );

ANALYZE_TREE()
{
  //cout << "ANALYZE_TREE: " << CURRENT_TREE << endl;
  //OUTPUT_ERROR("ANALYZE_TREE: " << CURRENT_TREE);
  const char* names[2];
  names[0] = "strcpy";
  names[1] = "strcat";
  Fun f(Fun::matchMultipleNames, names);
  //CallSite f(namedSybmols(names));
  if( MATCH(f) ) cout << "call: " << CURRENT_TREE << endl;
}

END_EXTEND_CHECKER();

MAKE_MAIN( hello )

// EOF