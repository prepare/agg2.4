#pragma once
#include "agg_basics.h"

namespace agg {
  template<class ColorT> class span_solid {

    public:
      typedef ColorT color_type;

      void color(const color_type& c) { m_color = c; }
      const color_type& color() const { return m_color; }

      void prepare() {}

      //{{{
      void generate(color_type* span, int x, int y, unsigned len)
      {
          do { *span++ = m_color; } while(--len);
      }
      //}}}

    private:
      color_type m_color;
    };
  }
