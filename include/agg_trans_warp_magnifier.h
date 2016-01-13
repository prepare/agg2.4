#pragma once

namespace agg { 
  class trans_warp_magnifier {
    public:
        trans_warp_magnifier() : m_xc(0.0), m_yc(0.0), m_magn(1.0), m_radius(1.0) {}

        void center(double x, double y) { m_xc = x; m_yc = y; }
        void magnification(double m)    { m_magn = m;         }
        void radius(double r)           { m_radius = r;       }

        double xc()            const { return m_xc; }
        double yc()            const { return m_yc; }
        double magnification() const { return m_magn;   }
        double radius()        const { return m_radius; }

        void transform(double* x, double* y) const;
        void inverse_transform(double* x, double* y) const;

    private:
        double m_xc;
        double m_yc;
        double m_magn;
        double m_radius;
    };
}
