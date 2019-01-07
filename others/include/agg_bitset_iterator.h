#pragma once

#include "agg_basics.h"

namespace agg {

  class bitset_iterator {
  public:
    //{{{
    bitset_iterator(const int8u* bits, unsigned offset = 0) :
        m_bits(bits + (offset >> 3)),
        m_mask(0x80 >> (offset & 7))
    {}
    //}}}
    //{{{
    void operator ++ ()
    {
        m_mask >>= 1;
        if(m_mask == 0)
        {
            ++m_bits;
            m_mask = 0x80;
        }
    }
    //}}}
    //{{{
    unsigned bit() const
    {
        return (*m_bits) & m_mask;
    }
    //}}}

  private:
    const int8u* m_bits;
    int8u        m_mask;
  };
}
