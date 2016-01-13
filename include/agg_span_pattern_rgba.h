#pragma once
#include "agg_basics.h"

namespace agg {
  template<class Source> class span_pattern_rgba {
  public:
      typedef Source source_type;
      typedef typename source_type::color_type color_type;
      typedef typename source_type::order_type order_type;
      typedef typename color_type::value_type value_type;
      typedef typename color_type::calc_type calc_type;

      span_pattern_rgba() {}
      //{{{
      span_pattern_rgba(source_type& src,
                        unsigned offset_x, unsigned offset_y) :
          m_src(&src),
          m_offset_x(offset_x),
          m_offset_y(offset_y)
      {}
      //}}}

      void   attach(source_type& v)      { m_src = &v; }
      source_type& source()       { return *m_src; }
      const  source_type& source() const { return *m_src; }

      void       offset_x(unsigned v) { m_offset_x = v; }
      void       offset_y(unsigned v) { m_offset_y = v; }
      unsigned   offset_x() const { return m_offset_x; }
      unsigned   offset_y() const { return m_offset_y; }
      void       alpha(value_type) {}
      value_type alpha() const { return 0; }

      void prepare() {}
      //{{{
      void generate(color_type* span, int x, int y, unsigned len)
      {
          x += m_offset_x;
          y += m_offset_y;
          const value_type* p = (const value_type*)m_src->span(x, y, len);
          do
          {
              span->r = p[order_type::R];
              span->g = p[order_type::G];
              span->b = p[order_type::B];
              span->a = p[order_type::A];
              p = (const value_type*)m_src->next_x();
              ++span;
          }
          while(--len);
      }
      //}}}

  private:
      source_type* m_src;
      unsigned     m_offset_x;
      unsigned     m_offset_y;
  };
}
