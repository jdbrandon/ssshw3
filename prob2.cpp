/*
  (c) 2004-2014, Coverity, Inc.  All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Coverity, Inc. and its licensors, and is supplied subject to,
  and may be used only by Coverity customers in accordance with the terms and
  conditions of a previously executed license agreement between Coverity and that
  customer.
*/

// s2_secure_coding.cpp

#include "extend-lang.hpp"     // Extend API

START_EXTEND_CHECKER( s2_secure_coding, simple );

ANALYZE_TREE()
{
  const char* names[4];
  names[0] = "strcpy";
  names[1] = "strcat";
  names[2] = "strncat";
  names[3] = "printf";
  Fun f(Fun::matchMultipleNames, names);
  //CallSite f(namedSybmols(names));
  if(MATCH(f)){
    OUTPUT_ERROR("use of possibly unsafe function");
  } 
}

END_EXTEND_CHECKER();

MAKE_MAIN( s2_secure_coding )

// EOF