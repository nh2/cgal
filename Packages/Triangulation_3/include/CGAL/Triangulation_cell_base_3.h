// ============================================================================
//
// Copyright (c) 1998 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------------
//
// release       :
// release_date  :
//
// file          : include/CGAL/Triangulation_base_cell.h
// revision      : $Revision$
// author(s)     : Monique Teillaud <Monique.Teillaud@sophia.inria.fr>
//
// coordinator   : Mariette Yvinec <Mariette.Yvinec@sophia.inria.fr>
//
// ============================================================================
//
// cell of a triangulation of any dimension <=3
//
// ============================================================================

#ifndef CGAL_TRIANGULATION_BASE_CELL_H
#define CGAL_TRIANGULATION_BASE_CELL_H

#include <CGAL/triangulation_assertions.h>
#include <CGAL/Triangulation_short_names.h>

template < class Gt >
class CGAL_Triangulation_base_cell 
{

public:

  // CONSTRUCTORS

  inline
  CGAL_Triangulation_base_cell()
  {
    set_vertices();
    set_neighbors();
  }

  inline
  CGAL_Triangulation_base_cell( void* v0, void* v1, void* v2, void* v3)
  {
    set_vertices(v0, v1, v2, v3);
    set_neighbors();
  }

  inline
  CGAL_Triangulation_base_cell(void* v0, void* v1, void* v2, void* v3,
				      void* n0, void* n1, void* n2, void* n3)
  {
    set_vertices(v0, v1, v2, v3);
    set_neighbors(n0, n1, n2, n3);
  }

  // ACCESS FUNCTIONS

  inline 
  const void* vertex(int i) const
  {
    CGAL_triangulation_precondition( i == 0 || i == 1 || i == 2 || i==3 );
    return V[i];
  } 

  inline 
  bool has_vertex(const void* v) const
  {
    return (V[0] == v) || (V[1] == v) || (V[2]== v) || (V[3]== v);
  }
    
  inline 
  bool has_vertex(const void* v, int& i) const
  {
    if (v == V[0]) {
      i = 0;
      return true;
    }
    if (v == V[1]) {
      i = 1;
      return true;
    }
    if (v == V[2]) {
      i = 2;
      return true;
    }
    if (v == V[3]) {
      i = 3;
      return true;
    }
    return false;
  }
    
  inline 
  int vertex_index(const void* v) const
  {
    if (v == V[0]) {
      return 0;
    }
    if (v == V[1]) {
      return 1;
    }
    if (v == V[2]) {
      return 2;
    }
    if (v == V[3]) {
      return 3;
    }
    CGAL_triangulation_assertion(false); // we should not get here
    return -1;
  }

  inline 
  void* neighbor(int i) const
  {
    CGAL_triangulation_precondition( i == 0 || i == 1 || i == 2 || i == 3);
    return N[i];
  }
    
  inline 
  bool has_neighbor(const void* n) const
  {
    return (N[0] == n) || (N[1] == n) || (N[2] == n) || (N[3] == n);
  }
    
  inline 
  bool has_neighbor(const void* n, int& i) const
  {
    if(n == N[0]){
      i = 0;
      return true;
    }
    if(n == N[1]){
      i = 1;
      return true;
    }
    if(n == N[2]){
      i = 2;
      return true;
    }
    if(n == N[3]){
      i = 3;
      return true;
    }
    return false;
  }
    
  inline 
  int cell_index(const void* n) const
  {
    if (n == N[0]) {
      return 0;
    }
    if (n == N[1]) {
      return 1;
    }
    if (n == N[2]) {
      return 2;
    }
    if (n == N[3]) {
      return 3;
    }
    CGAL_triangulation_precondition(false); // we should not get here
    return -1;
  }
 
  // SETTING

  inline 
  void set_vertex(int i, void* v)
  {
    CGAL_triangulation_precondition( i == 0 || i == 1 || i == 2 || i == 3);
    V[i] = v;
  }
    
  inline 
  void set_neighbor(int i, void* n)
  {
    CGAL_triangulation_precondition( i == 0 || i == 1 || i == 2 || i == 3);
    N[i] = n;
  }

  inline 
  void set_vertices()
  {
    V[0] = NULL;
    V[1] = NULL;
    V[2] = NULL;
    V[3] = NULL;
  }
    
  inline 
  void set_vertices(void* v0,
		    void* v1,
		    void* v2,
		    void* v3)
  {
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;
    V[3] = v3;
  }
    
  inline 
  void set_neighbors()
  {
    N[0] = NULL;
    N[1] = NULL;
    N[2] = NULL;
    N[3] = NULL;
  }
    
  inline
  void set_neighbors(void* n0,
		     void* n1,
		     void* n2,
		     void* n3)
  {
    N[0] = n0;
    N[1] = n1;
    N[2] = n2;
    N[3] = n3;
  }

  // CHECKING

  // the following trivial is_valid allows
  // the user of derived cell base classes 
  // to add their own purpose checking
  bool is_valid() const
    {return true;}


private:
  void* V[4];
  void* N[4];
};
#endif CGAL_TRIANGULATION_BASE_CELL_H
