#pragma once
#include "agg_conv_transform.h"

namespace agg {

  void arc_to_bezier(double cx, double cy, double rx, double ry, double start_angle, double sweep_angle, double* curve);

  class bezier_arc {
  public:
    bezier_arc() : m_vertex(26), m_num_vertices(0), m_cmd(path_cmd_line_to) {}
    //{{{
    bezier_arc(double x,  double y,
               double rx, double ry,
               double start_angle,
               double sweep_angle)
    {
        init(x, y, rx, ry, start_angle, sweep_angle);
    }
    //}}}
    //{{{
    //--------------------------------------------------------------------
    void init(double x,  double y,
              double rx, double ry,
              double start_angle,
              double sweep_angle);
    //}}}
    //{{{
    //--------------------------------------------------------------------
    void rewind(unsigned)
    {
        m_vertex = 0;
    }
    //}}}
    //{{{
    //--------------------------------------------------------------------
    unsigned vertex(double* x, double* y)
    {
        if(m_vertex >= m_num_vertices) return path_cmd_stop;
        *x = m_vertices[m_vertex];
        *y = m_vertices[m_vertex + 1];
        m_vertex += 2;
        return (m_vertex == 2) ? unsigned(path_cmd_move_to) : m_cmd;
    }
    //}}}

    // Supplemantary functions. num_vertices() actually returns doubled
    // number of vertices. That is, for 1 vertex it returns 2.
    unsigned  num_vertices() const { return m_num_vertices; }
    const double* vertices() const { return m_vertices;     }
    double*       vertices()       { return m_vertices;     }
  private:
    unsigned m_vertex;
    unsigned m_num_vertices;
    double   m_vertices[26];
    unsigned m_cmd;
    };


  class bezier_arc_svg {
  public:
    bezier_arc_svg() : m_arc(), m_radii_ok(false) {}
    //{{{
    bezier_arc_svg(double x1, double y1,
                   double rx, double ry,
                   double angle,
                   bool large_arc_flag,
                   bool sweep_flag,
                   double x2, double y2) :
        m_arc(), m_radii_ok(false)
    {
        init(x1, y1, rx, ry, angle, large_arc_flag, sweep_flag, x2, y2);
    }
    //}}}
    //{{{
    //--------------------------------------------------------------------
    void init(double x1, double y1,
              double rx, double ry,
              double angle,
              bool large_arc_flag,
              bool sweep_flag,
              double x2, double y2);
    //}}}
    bool radii_ok() const { return m_radii_ok; }
    //{{{
    void rewind(unsigned)
    {
        m_arc.rewind(0);
    }
    //}}}
    //{{{
    //--------------------------------------------------------------------
    unsigned vertex(double* x, double* y)
    {
        return m_arc.vertex(x, y);
    }
    //}}}

    // Supplemantary functions. num_vertices() actually returns doubled
    // number of vertices. That is, for 1 vertex it returns 2.
    unsigned  num_vertices() const { return m_arc.num_vertices(); }
    const double* vertices() const { return m_arc.vertices();     }
    double*       vertices()       { return m_arc.vertices();     }

  private:
    bezier_arc m_arc;
    bool       m_radii_ok;
  };
}
