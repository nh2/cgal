// Copyright (c) 2007 Fernando Luis Cacciola Carballal. All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
// Author(s)     : Fernando Cacciola <fernando_cacciola@ciudad.com.ar>

#ifndef CGAL_STRAIGHT_SKELETON_ASSERTIONS_H
#define CGAL_STRAIGHT_SKELETON_ASSERTIONS_H

#if defined(CGAL_STRAIGHT_SKELETON_NO_POSTCONDITIONS) \
  || defined(CGAL_NO_POSTCONDITIONS) \
  || (!defined(CGAL_STRAIGHT_SKELETON_CHECK_EXPENSIVE) && !defined(CGAL_CHECK_EXPENSIVE)) \
  || defined(NDEBUG)
#  define CGAL_stskel_expensive_postcondition(EX)         (static_cast<void>(0))
#  define CGAL_stskel_expensive_postcondition_msg(EX,MSG) (static_cast<void>(0))
#  define CGAL_stskel_expensive_postcondition_code(CODE)
#else
#  define CGAL_stskel_expensive_postcondition(EX)         (CGAL::possibly(EX)?(static_cast<void>(0)): ::CGAL::postcondition_fail( # EX , __FILE__, __LINE__))
#  define CGAL_stskel_expensive_postcondition_msg(EX,MSG) (CGAL::possibly(EX)?(static_cast<void>(0)): ::CGAL::postcondition_fail( # EX , __FILE__, __LINE__, MSG))
#  define CGAL_stskel_expensive_postcondition_code(CODE)  CODE
#endif 


namespace CGAL {

namespace {

template<class Handle> inline bool handle_assigned ( Handle const& aH )
{
  Handle null ;
  return aH != null ;
}

}

} // end namespace CGAL

#endif // CGAL_STRAIGHT_SKELETON_ASSERTIONS_H //
// EOF //
 
