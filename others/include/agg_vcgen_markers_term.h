#pragma once

#include "agg_basics.h"
#include "agg_vertex_sequence.h"

namespace agg {
  class vcgen_markers_term {
  public:
    vcgen_markers_term() : m_curr_id(0), m_curr_idx(0) {}

    // Vertex Generator Interface
    void remove_all();
    void add_vertex(double x, double y, unsigned cmd);

    // Vertex Source Interface
    void rewind(unsigned path_id);
    unsigned vertex(double* x, double* y);

  private:
    vcgen_markers_term(const vcgen_markers_term&);
    const vcgen_markers_term& operator = (const vcgen_markers_term&);

    //{{{
    struct coord_type
    {
        double x, y;

        coord_type() {}
        coord_type(double x_, double y_) : x(x_), y(y_) {}
    };
    //}}}

    typedef pod_bvector<coord_type, 6> coord_storage;

    coord_storage m_markers;
    unsigned      m_curr_id;
    unsigned      m_curr_idx;
    };
  }
