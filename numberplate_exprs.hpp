
#ifndef NUMBERPLATE_EXPRS
#define NUMBERPLATE_EXPRS
#include<string>
#include<functional>
#include<array>
namespace numberplate{
    class four_terms_expr{
        std::string pretty_;
        std::function<double(double,double,double,double)> calc_;
        public:
        four_terms_expr(const char *pretty,decltype(calc_) calc);
        std::string pretty() const;//変数部分がA,B,C,Dのまま
        std::string pretty(double,double,double,double) const;//変数部分を置換
        double operator()(double arg0,double arg1,double arg2,double arg3) const;
    };
    inline std::array<four_terms_expr,528> EXPRS={
    
        four_terms_expr(u8"   -A    \n─────────\nB⋅(C - D)",[](double A,double B,double C,double D){return -A/(B*(C - D));}),
        
        four_terms_expr(u8"A⋅B - C\n───────\n   D   ",[](double A,double B,double C,double D){return (A*B - C)/D;}),
        
        four_terms_expr(u8"      B   \nA + ──────\n    -C - D",[](double A,double B,double C,double D){return A + B/(-C - D);}),
        
        four_terms_expr(u8"C⋅(A + B) - D",[](double A,double B,double C,double D){return C*(A + B) - D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB + C + D",[](double A,double B,double C,double D){return -A/(B + C + D);}),
        
        four_terms_expr(u8"    B⋅D\nA + ───\n     C ",[](double A,double B,double C,double D){return A + B*D/C;}),
        
        four_terms_expr(u8"  ⎛     C⎞\nA⋅⎜-B - ─⎟\n  ⎝     D⎠",[](double A,double B,double C,double D){return A*(-B - C/D);}),
        
        four_terms_expr(u8"  A   \n──────\n     C\n-B + ─\n     D",[](double A,double B,double C,double D){return A/(-B + C/D);}),
        
        four_terms_expr(u8"        C\nA + B + ─\n        D",[](double A,double B,double C,double D){return A + B + C/D;}),
        
        four_terms_expr(u8"C⋅(-A - B) - D",[](double A,double B,double C,double D){return C*(-A - B) - D;}),
        
        four_terms_expr(u8"D⋅(-A⋅B - C)",[](double A,double B,double C,double D){return D*(-A*B - C);}),
        
        four_terms_expr(u8"-A⋅C⋅D \n───────\n   B   ",[](double A,double B,double C,double D){return -A*C*D/B;}),
        
        four_terms_expr(u8"-(A + B) \n─────────\n   C⋅D   ",[](double A,double B,double C,double D){return -(A + B)/(C*D);}),
        
        four_terms_expr(u8"-A - B\n──────\n-C + D",[](double A,double B,double C,double D){return (-A - B)/(-C + D);}),
        
        four_terms_expr(u8"     -B - C\n-A - ──────\n       D   ",[](double A,double B,double C,double D){return -A - (-B - C)/D;}),
        
        four_terms_expr(u8"    A     \n──────────\nB⋅(-C - D)",[](double A,double B,double C,double D){return A/(B*(-C - D));}),
        
        four_terms_expr(u8"-A - B⋅(-C - D)",[](double A,double B,double C,double D){return -A - B*(-C - D);}),
        
        four_terms_expr(u8"  A  \n─────\nB⋅C⋅D",[](double A,double B,double C,double D){return A/(B*C*D);}),
        
        four_terms_expr(u8"A⋅(B + C)\n─────────\n    D    ",[](double A,double B,double C,double D){return A*(B + C)/D;}),
        
        four_terms_expr(u8"A⋅(B + C⋅D)",[](double A,double B,double C,double D){return A*(B + C*D);}),
        
        four_terms_expr(u8"C⋅D⋅(-A + B)",[](double A,double B,double C,double D){return C*D*(-A + B);}),
        
        four_terms_expr(u8"-A⋅(B - C⋅D)",[](double A,double B,double C,double D){return -A*(B - C*D);}),
        
        four_terms_expr(u8"-A⋅(-C + D) \n────────────\n     B      ",[](double A,double B,double C,double D){return -A*(-C + D)/B;}),
        
        four_terms_expr(u8"    B - C\nA - ─────\n      D  ",[](double A,double B,double C,double D){return A - (B - C)/D;}),
        
        four_terms_expr(u8"    A + B\nD - ─────\n      C  ",[](double A,double B,double C,double D){return D - (A + B)/C;}),
        
        four_terms_expr(u8"A⋅B    \n─── - D\n C     ",[](double A,double B,double C,double D){return A*B/C - D;}),
        
        four_terms_expr(u8"A⋅B⋅C⋅D",[](double A,double B,double C,double D){return A*B*C*D;}),
        
        four_terms_expr(u8"      B  \nA - ─────\n    C - D",[](double A,double B,double C,double D){return A - B/(C - D);}),
        
        four_terms_expr(u8"    A    \n─────────\nB + C - D",[](double A,double B,double C,double D){return A/(B + C - D);}),
        
        four_terms_expr(u8"    B    \nA - ─ + D\n    C    ",[](double A,double B,double C,double D){return A - B/C + D;}),
        
        four_terms_expr(u8"(A - B)⋅(C + D)",[](double A,double B,double C,double D){return (A - B)*(C + D);}),
        
        four_terms_expr(u8"-C⋅D⋅(A - B)",[](double A,double B,double C,double D){return -C*D*(A - B);}),
        
        four_terms_expr(u8"  ⎛     B⎞\nD⋅⎜-A - ─⎟\n  ⎝     C⎠",[](double A,double B,double C,double D){return D*(-A - B/C);}),
        
        four_terms_expr(u8"-A⋅(-B - C) + D",[](double A,double B,double C,double D){return -A*(-B - C) + D;}),
        
        four_terms_expr(u8"     A + B\n-D + ─────\n       C  ",[](double A,double B,double C,double D){return -D + (A + B)/C;}),
        
        four_terms_expr(u8"D⋅(A - B)\n─────────\n    C    ",[](double A,double B,double C,double D){return D*(A - B)/C;}),
        
        four_terms_expr(u8"  A       \n────── + D\n-B + C    ",[](double A,double B,double C,double D){return A/(-B + C) + D;}),
        
        four_terms_expr(u8"-C⋅(A - B) - D",[](double A,double B,double C,double D){return -C*(A - B) - D;}),
        
        four_terms_expr(u8"-A⋅(B - C + D)",[](double A,double B,double C,double D){return -A*(B - C + D);}),
        
        four_terms_expr(u8"A⋅D⋅(B - C)",[](double A,double B,double C,double D){return A*D*(B - C);}),
        
        four_terms_expr(u8"   A     \n- ─── - D\n  B⋅C    ",[](double A,double B,double C,double D){return -A/(B*C) - D;}),
        
        four_terms_expr(u8"-C⋅D⋅(A + B)",[](double A,double B,double C,double D){return -C*D*(A + B);}),
        
        four_terms_expr(u8"A + B⋅C\n───────\n   D   ",[](double A,double B,double C,double D){return (A + B*C)/D;}),
        
        four_terms_expr(u8"-A - B⋅C\n────────\n   D    ",[](double A,double B,double C,double D){return (-A - B*C)/D;}),
        
        four_terms_expr(u8"A⋅(-B - C) - D",[](double A,double B,double C,double D){return A*(-B - C) - D;}),
        
        four_terms_expr(u8"D⋅(A + B)\n─────────\n    C    ",[](double A,double B,double C,double D){return D*(A + B)/C;}),
        
        four_terms_expr(u8"   -A     \n──────────\nD⋅(-B - C)",[](double A,double B,double C,double D){return -A/(D*(-B - C));}),
        
        four_terms_expr(u8"C⋅D⋅(A - B)",[](double A,double B,double C,double D){return C*D*(A - B);}),
        
        four_terms_expr(u8"    B    \nA + ─ + D\n    C    ",[](double A,double B,double C,double D){return A + B/C + D;}),
        
        four_terms_expr(u8"A - D⋅(-B - C)",[](double A,double B,double C,double D){return A - D*(-B - C);}),
        
        four_terms_expr(u8"  A        \n- ─ - C + D\n  B        ",[](double A,double B,double C,double D){return -A/B - C + D;}),
        
        four_terms_expr(u8"A⋅(B + C + D)",[](double A,double B,double C,double D){return A*(B + C + D);}),
        
        four_terms_expr(u8"    A    \n─────────\nD⋅(B + C)",[](double A,double B,double C,double D){return A/(D*(B + C));}),
        
        four_terms_expr(u8"-A - B + C - D",[](double A,double B,double C,double D){return -A - B + C - D;}),
        
        four_terms_expr(u8"A⋅B + C + D",[](double A,double B,double C,double D){return A*B + C + D;}),
        
        four_terms_expr(u8"   -A     \n──────────\nD⋅(-B + C)",[](double A,double B,double C,double D){return -A/(D*(-B + C));}),
        
        four_terms_expr(u8"  A   C\n- ─ - ─\n  B   D",[](double A,double B,double C,double D){return -A/B - C/D;}),
        
        four_terms_expr(u8"C⋅D⋅(A + B)",[](double A,double B,double C,double D){return C*D*(A + B);}),
        
        four_terms_expr(u8"-A⋅(-B - C) \n────────────\n     D      ",[](double A,double B,double C,double D){return -A*(-B - C)/D;}),
        
        four_terms_expr(u8"A + B⋅(C + D)",[](double A,double B,double C,double D){return A + B*(C + D);}),
        
        four_terms_expr(u8"  A  \n─────\nB    \n─ + D\nC    ",[](double A,double B,double C,double D){return A/(B/C + D);}),
        
        four_terms_expr(u8"  A      \n───── - D\nB - C    ",[](double A,double B,double C,double D){return A/(B - C) - D;}),
        
        four_terms_expr(u8"A + B + C + D",[](double A,double B,double C,double D){return A + B + C + D;}),
        
        four_terms_expr(u8"-A⋅B - C - D",[](double A,double B,double C,double D){return -A*B - C - D;}),
        
        four_terms_expr(u8"  A    \n- ─ + C\n  B    \n───────\n   D   ",[](double A,double B,double C,double D){return (-A/B + C)/D;}),
        
        four_terms_expr(u8"    A     \n──────────\n-B - C + D",[](double A,double B,double C,double D){return A/(-B - C + D);}),
        
        four_terms_expr(u8"       B   \n-A + ──────\n     -C + D",[](double A,double B,double C,double D){return -A + B/(-C + D);}),
        
        four_terms_expr(u8"         C\n-A - B + ─\n         D",[](double A,double B,double C,double D){return -A - B + C/D;}),
        
        four_terms_expr(u8"A - B⋅(C - D)",[](double A,double B,double C,double D){return A - B*(C - D);}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B + C - D",[](double A,double B,double C,double D){return -A/(-B + C - D);}),
        
        four_terms_expr(u8"A⋅(-B⋅C - D)",[](double A,double B,double C,double D){return A*(-B*C - D);}),
        
        four_terms_expr(u8"A - B⋅(-C + D)",[](double A,double B,double C,double D){return A - B*(-C + D);}),
        
        four_terms_expr(u8"  A    \n- ─ - C\n  B    \n───────\n   D   ",[](double A,double B,double C,double D){return (-A/B - C)/D;}),
        
        four_terms_expr(u8"D⋅(-A + B⋅C)",[](double A,double B,double C,double D){return D*(-A + B*C);}),
        
        four_terms_expr(u8"-C⋅(-A + B) - D",[](double A,double B,double C,double D){return -C*(-A + B) - D;}),
        
        four_terms_expr(u8"    A       \n- ────── + D\n  -B + C    ",[](double A,double B,double C,double D){return -A/(-B + C) + D;}),
        
        four_terms_expr(u8"-A⋅B + C - D",[](double A,double B,double C,double D){return -A*B + C - D;}),
        
        four_terms_expr(u8"      C\nA⋅B + ─\n      D",[](double A,double B,double C,double D){return A*B + C/D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nD⋅(B - C)",[](double A,double B,double C,double D){return -A/(D*(B - C));}),
        
        four_terms_expr(u8"   A   \n───────\n  B    \n- ─ + D\n  C    ",[](double A,double B,double C,double D){return A/(-B/C + D);}),
        
        four_terms_expr(u8"A⋅(-C + D)\n──────────\n    B     ",[](double A,double B,double C,double D){return A*(-C + D)/B;}),
        
        four_terms_expr(u8"A⋅B⋅D\n─────\n  C  ",[](double A,double B,double C,double D){return A*B*D/C;}),
        
        four_terms_expr(u8"    B + C\nA - ─────\n      D  ",[](double A,double B,double C,double D){return A - (B + C)/D;}),
        
        four_terms_expr(u8"-A - B + C\n──────────\n    D     ",[](double A,double B,double C,double D){return (-A - B + C)/D;}),
        
        four_terms_expr(u8"-A⋅(-B - C) - D",[](double A,double B,double C,double D){return -A*(-B - C) - D;}),
        
        four_terms_expr(u8"   A   \n───────\nB - C⋅D",[](double A,double B,double C,double D){return A/(B - C*D);}),
        
        four_terms_expr(u8"A⋅(-B⋅C + D)",[](double A,double B,double C,double D){return A*(-B*C + D);}),
        
        four_terms_expr(u8"     A - B\n-D + ─────\n       C  ",[](double A,double B,double C,double D){return -D + (A - B)/C;}),
        
        four_terms_expr(u8"    B\nA - ─\n    C\n─────\n  D  ",[](double A,double B,double C,double D){return (A - B/C)/D;}),
        
        four_terms_expr(u8"    B⋅C\nA + ───\n     D ",[](double A,double B,double C,double D){return A + B*C/D;}),
        
        four_terms_expr(u8"   ⎛    C⎞\n-A⋅⎜B - ─⎟\n   ⎝    D⎠",[](double A,double B,double C,double D){return -A*(B - C/D);}),
        
        four_terms_expr(u8"A + B⋅(-C + D)",[](double A,double B,double C,double D){return A + B*(-C + D);}),
        
        four_terms_expr(u8"   ⎛  B    ⎞\n-A⋅⎜- ─ - D⎟\n   ⎝  C    ⎠",[](double A,double B,double C,double D){return -A*(-B/C - D);}),
        
        four_terms_expr(u8"-A - B\n──────\nC - D ",[](double A,double B,double C,double D){return (-A - B)/(C - D);}),
        
        four_terms_expr(u8"A⋅B - C⋅D",[](double A,double B,double C,double D){return A*B - C*D;}),
        
        four_terms_expr(u8"A - B + C - D",[](double A,double B,double C,double D){return A - B + C - D;}),
        
        four_terms_expr(u8"(A + B)⋅(C + D)",[](double A,double B,double C,double D){return (A + B)*(C + D);}),
        
        four_terms_expr(u8"   ⎛  B    ⎞\n-A⋅⎜- ─ + D⎟\n   ⎝  C    ⎠",[](double A,double B,double C,double D){return -A*(-B/C + D);}),
        
        four_terms_expr(u8"C⋅(A + B) + D",[](double A,double B,double C,double D){return C*(A + B) + D;}),
        
        four_terms_expr(u8"-A - D⋅(-B + C)",[](double A,double B,double C,double D){return -A - D*(-B + C);}),
        
        four_terms_expr(u8"-A + D⋅(B + C)",[](double A,double B,double C,double D){return -A + D*(B + C);}),
        
        four_terms_expr(u8"A - B⋅(C + D)",[](double A,double B,double C,double D){return A - B*(C + D);}),
        
        four_terms_expr(u8"-A⋅D⋅(B - C)",[](double A,double B,double C,double D){return -A*D*(B - C);}),
        
        four_terms_expr(u8"A + D⋅(-B - C)",[](double A,double B,double C,double D){return A + D*(-B - C);}),
        
        four_terms_expr(u8"   -A    \n─────────\nD⋅(B + C)",[](double A,double B,double C,double D){return -A/(D*(B + C));}),
        
        four_terms_expr(u8"         C\n-A + B + ─\n         D",[](double A,double B,double C,double D){return -A + B + C/D;}),
        
        four_terms_expr(u8"    A      \n- ───── - D\n  B - C    ",[](double A,double B,double C,double D){return -A/(B - C) - D;}),
        
        four_terms_expr(u8"-A⋅(-B + C) \n────────────\n     D      ",[](double A,double B,double C,double D){return -A*(-B + C)/D;}),
        
        four_terms_expr(u8"A        \n─ - C + D\nB        ",[](double A,double B,double C,double D){return A/B - C + D;}),
        
        four_terms_expr(u8"       B   \n-A - ──────\n     -C + D",[](double A,double B,double C,double D){return -A - B/(-C + D);}),
        
        four_terms_expr(u8"  ⎛    C⎞\nA⋅⎜B + ─⎟\n  ⎝    D⎠",[](double A,double B,double C,double D){return A*(B + C/D);}),
        
        four_terms_expr(u8"    B⋅C\nA - ───\n     D ",[](double A,double B,double C,double D){return A - B*C/D;}),
        
        four_terms_expr(u8"D⋅(-A - B - C)",[](double A,double B,double C,double D){return D*(-A - B - C);}),
        
        four_terms_expr(u8"    A     \n──────────\n-B + C + D",[](double A,double B,double C,double D){return A/(-B + C + D);}),
        
        four_terms_expr(u8"A⋅D\n───\nB⋅C",[](double A,double B,double C,double D){return A*D/(B*C);}),
        
        four_terms_expr(u8"(A - B)⋅(-C + D)",[](double A,double B,double C,double D){return (A - B)*(-C + D);}),
        
        four_terms_expr(u8"A⋅B    \n─── + D\n C     ",[](double A,double B,double C,double D){return A*B/C + D;}),
        
        four_terms_expr(u8"-C⋅(-A - B) \n────────────\n     D      ",[](double A,double B,double C,double D){return -C*(-A - B)/D;}),
        
        four_terms_expr(u8"  -A    \n────────\n-B⋅C + D",[](double A,double B,double C,double D){return -A/(-B*C + D);}),
        
        four_terms_expr(u8"-A⋅B \n─────\nC + D",[](double A,double B,double C,double D){return -A*B/(C + D);}),
        
        four_terms_expr(u8"  A  \n─────\n    C\nB - ─\n    D",[](double A,double B,double C,double D){return A/(B - C/D);}),
        
        four_terms_expr(u8"A + B - C - D",[](double A,double B,double C,double D){return A + B - C - D;}),
        
        four_terms_expr(u8"A + B⋅C - D",[](double A,double B,double C,double D){return A + B*C - D;}),
        
        four_terms_expr(u8"-A + D⋅(-B + C)",[](double A,double B,double C,double D){return -A + D*(-B + C);}),
        
        four_terms_expr(u8"-A + B\n──────\nC + D ",[](double A,double B,double C,double D){return (-A + B)/(C + D);}),
        
        four_terms_expr(u8"A - B⋅(-C - D)",[](double A,double B,double C,double D){return A - B*(-C - D);}),
        
        four_terms_expr(u8"-A + B - C⋅D",[](double A,double B,double C,double D){return -A + B - C*D;}),
        
        four_terms_expr(u8"-A + D⋅(B - C)",[](double A,double B,double C,double D){return -A + D*(B - C);}),
        
        four_terms_expr(u8"    A    \n─────────\nB - C - D",[](double A,double B,double C,double D){return A/(B - C - D);}),
        
        four_terms_expr(u8"D⋅(A - B⋅C)",[](double A,double B,double C,double D){return D*(A - B*C);}),
        
        four_terms_expr(u8"      B \n-A + ───\n     C⋅D",[](double A,double B,double C,double D){return -A + B/(C*D);}),
        
        four_terms_expr(u8"D⋅(-A + B - C)",[](double A,double B,double C,double D){return D*(-A + B - C);}),
        
        four_terms_expr(u8"    A    \n─────────\nB⋅(C + D)",[](double A,double B,double C,double D){return A/(B*(C + D));}),
        
        four_terms_expr(u8"D⋅(A + B - C)",[](double A,double B,double C,double D){return D*(A + B - C);}),
        
        four_terms_expr(u8"D⋅(A - B + C)",[](double A,double B,double C,double D){return D*(A - B + C);}),
        
        four_terms_expr(u8"A + B + C\n─────────\n    D    ",[](double A,double B,double C,double D){return (A + B + C)/D;}),
        
        four_terms_expr(u8"-A - B + C + D",[](double A,double B,double C,double D){return -A - B + C + D;}),
        
        four_terms_expr(u8"D⋅(A - B - C)",[](double A,double B,double C,double D){return D*(A - B - C);}),
        
        four_terms_expr(u8"-A⋅B⋅C \n───────\n   D   ",[](double A,double B,double C,double D){return -A*B*C/D;}),
        
        four_terms_expr(u8"     A - B\n-D - ─────\n       C  ",[](double A,double B,double C,double D){return -D - (A - B)/C;}),
        
        four_terms_expr(u8"-(-A - B) \n──────────\n   C⋅D    ",[](double A,double B,double C,double D){return -(-A - B)/(C*D);}),
        
        four_terms_expr(u8"A      \n─ + C⋅D\nB      ",[](double A,double B,double C,double D){return A/B + C*D;}),
        
        four_terms_expr(u8"  A⋅C    \n- ─── - D\n   B     ",[](double A,double B,double C,double D){return -A*C/B - D;}),
        
        four_terms_expr(u8"     B    \n-A + ─ + D\n     C    ",[](double A,double B,double C,double D){return -A + B/C + D;}),
        
        four_terms_expr(u8"   A    \n────────\n-B⋅C - D",[](double A,double B,double C,double D){return A/(-B*C - D);}),
        
        four_terms_expr(u8"A - B - C - D",[](double A,double B,double C,double D){return A - B - C - D;}),
        
        four_terms_expr(u8"  A      \n- ─ + C⋅D\n  B      ",[](double A,double B,double C,double D){return -A/B + C*D;}),
        
        four_terms_expr(u8"-A⋅(B⋅C - D)",[](double A,double B,double C,double D){return -A*(B*C - D);}),
        
        four_terms_expr(u8"A + B + C⋅D",[](double A,double B,double C,double D){return A + B + C*D;}),
        
        four_terms_expr(u8"A + B⋅(-C - D)",[](double A,double B,double C,double D){return A + B*(-C - D);}),
        
        four_terms_expr(u8"    A     \n──────────\nD⋅(-B - C)",[](double A,double B,double C,double D){return A/(D*(-B - C));}),
        
        four_terms_expr(u8"     B - C\n-A + ─────\n       D  ",[](double A,double B,double C,double D){return -A + (B - C)/D;}),
        
        four_terms_expr(u8"   ⎛     C⎞\n-A⋅⎜-B + ─⎟\n   ⎝     D⎠",[](double A,double B,double C,double D){return -A*(-B + C/D);}),
        
        four_terms_expr(u8"-A⋅B + C + D",[](double A,double B,double C,double D){return -A*B + C + D;}),
        
        four_terms_expr(u8"A - B\n─────\nC + D",[](double A,double B,double C,double D){return (A - B)/(C + D);}),
        
        four_terms_expr(u8"  -A   \n───────\nB⋅C + D",[](double A,double B,double C,double D){return -A/(B*C + D);}),
        
        four_terms_expr(u8"A - B⋅C - D",[](double A,double B,double C,double D){return A - B*C - D;}),
        
        four_terms_expr(u8"    A     \n──────────\nD⋅(-B + C)",[](double A,double B,double C,double D){return A/(D*(-B + C));}),
        
        four_terms_expr(u8"A⋅C⋅D\n─────\n  B  ",[](double A,double B,double C,double D){return A*C*D/B;}),
        
        four_terms_expr(u8"-A⋅B⋅(C - D)",[](double A,double B,double C,double D){return -A*B*(C - D);}),
        
        four_terms_expr(u8"-A⋅(B⋅C + D)",[](double A,double B,double C,double D){return -A*(B*C + D);}),
        
        four_terms_expr(u8"        C\nA - B - ─\n        D",[](double A,double B,double C,double D){return A - B - C/D;}),
        
        four_terms_expr(u8"       B  \n-A + ─────\n     C + D",[](double A,double B,double C,double D){return -A + B/(C + D);}),
        
        four_terms_expr(u8"C⋅(-A - B)\n──────────\n    D     ",[](double A,double B,double C,double D){return C*(-A - B)/D;}),
        
        four_terms_expr(u8"(-A + B)⋅(C - D)",[](double A,double B,double C,double D){return (-A + B)*(C - D);}),
        
        four_terms_expr(u8"A⋅(-B - C)\n──────────\n    D     ",[](double A,double B,double C,double D){return A*(-B - C)/D;}),
        
        four_terms_expr(u8"  A      \n───── + D\nB - C    ",[](double A,double B,double C,double D){return A/(B - C) + D;}),
        
        four_terms_expr(u8"A   C\n─ - ─\nB   D",[](double A,double B,double C,double D){return A/B - C/D;}),
        
        four_terms_expr(u8"A⋅B⋅C - D",[](double A,double B,double C,double D){return A*B*C - D;}),
        
        four_terms_expr(u8"   A    \n────────\n-B + C⋅D",[](double A,double B,double C,double D){return A/(-B + C*D);}),
        
        four_terms_expr(u8"-A⋅B⋅(-C - D)",[](double A,double B,double C,double D){return -A*B*(-C - D);}),
        
        four_terms_expr(u8"-C⋅D⋅(-A - B)",[](double A,double B,double C,double D){return -C*D*(-A - B);}),
        
        four_terms_expr(u8"A + B\n─────\nC + D",[](double A,double B,double C,double D){return (A + B)/(C + D);}),
        
        four_terms_expr(u8"-A - D⋅(B - C)",[](double A,double B,double C,double D){return -A - D*(B - C);}),
        
        four_terms_expr(u8"        C\nA + B - ─\n        D",[](double A,double B,double C,double D){return A + B - C/D;}),
        
        four_terms_expr(u8"D⋅(-A - B)\n──────────\n    C     ",[](double A,double B,double C,double D){return D*(-A - B)/C;}),
        
        four_terms_expr(u8"(-A + B)⋅(-C - D)",[](double A,double B,double C,double D){return (-A + B)*(-C - D);}),
        
        four_terms_expr(u8"A⋅(-B + C) - D",[](double A,double B,double C,double D){return A*(-B + C) - D;}),
        
        four_terms_expr(u8"-C⋅(-A + B) + D",[](double A,double B,double C,double D){return -C*(-A + B) + D;}),
        
        four_terms_expr(u8"A⋅C    \n─── + D\n B     ",[](double A,double B,double C,double D){return A*C/B + D;}),
        
        four_terms_expr(u8"     -B + C\n-A - ──────\n       D   ",[](double A,double B,double C,double D){return -A - (-B + C)/D;}),
        
        four_terms_expr(u8"(-A - B)⋅(C - D)",[](double A,double B,double C,double D){return (-A - B)*(C - D);}),
        
        four_terms_expr(u8"-A + B\n──────\n-C + D",[](double A,double B,double C,double D){return (-A + B)/(-C + D);}),
        
        four_terms_expr(u8"A⋅(-B - C - D)",[](double A,double B,double C,double D){return A*(-B - C - D);}),
        
        four_terms_expr(u8"D⋅(A⋅B - C)",[](double A,double B,double C,double D){return D*(A*B - C);}),
        
        four_terms_expr(u8"   -A    \n─────────\nB - C + D",[](double A,double B,double C,double D){return -A/(B - C + D);}),
        
        four_terms_expr(u8"    A       \n- ────── + D\n  -B - C    ",[](double A,double B,double C,double D){return -A/(-B - C) + D;}),
        
        four_terms_expr(u8"    -B - C\nA + ──────\n      D   ",[](double A,double B,double C,double D){return A + (-B - C)/D;}),
        
        four_terms_expr(u8"    A    \n─────────\nD⋅(B - C)",[](double A,double B,double C,double D){return A/(D*(B - C));}),
        
        four_terms_expr(u8" A⋅B \n─────\nC + D",[](double A,double B,double C,double D){return A*B/(C + D);}),
        
        four_terms_expr(u8"  A   C\n- ─ + ─\n  B   D",[](double A,double B,double C,double D){return -A/B + C/D;}),
        
        four_terms_expr(u8"  A  \n─────\nB    \n─ - D\nC    ",[](double A,double B,double C,double D){return A/(B/C - D);}),
        
        four_terms_expr(u8"A⋅(-B + C + D)",[](double A,double B,double C,double D){return A*(-B + C + D);}),
        
        four_terms_expr(u8"(A + B)⋅(-C + D)",[](double A,double B,double C,double D){return (A + B)*(-C + D);}),
        
        four_terms_expr(u8"    A - B\nD + ─────\n      C  ",[](double A,double B,double C,double D){return D + (A - B)/C;}),
        
        four_terms_expr(u8"A + B - C + D",[](double A,double B,double C,double D){return A + B - C + D;}),
        
        four_terms_expr(u8"  A      \n───── - D\nB + C    ",[](double A,double B,double C,double D){return A/(B + C) - D;}),
        
        four_terms_expr(u8"A + B⋅C + D",[](double A,double B,double C,double D){return A + B*C + D;}),
        
        four_terms_expr(u8"-A⋅(B + C - D)",[](double A,double B,double C,double D){return -A*(B + C - D);}),
        
        four_terms_expr(u8" -A  \n─────\nB⋅C⋅D",[](double A,double B,double C,double D){return -A/(B*C*D);}),
        
        four_terms_expr(u8"  A       \n────── - D\n-B - C    ",[](double A,double B,double C,double D){return A/(-B - C) - D;}),
        
        four_terms_expr(u8"A - B - C + D",[](double A,double B,double C,double D){return A - B - C + D;}),
        
        four_terms_expr(u8" A⋅D  \n──────\n-B - C",[](double A,double B,double C,double D){return A*D/(-B - C);}),
        
        four_terms_expr(u8"     -B + C\n-A + ──────\n       D   ",[](double A,double B,double C,double D){return -A + (-B + C)/D;}),
        
        four_terms_expr(u8"-A - B + C⋅D",[](double A,double B,double C,double D){return -A - B + C*D;}),
        
        four_terms_expr(u8"A⋅(B - C⋅D)",[](double A,double B,double C,double D){return A*(B - C*D);}),
        
        four_terms_expr(u8"  A⋅B    \n- ─── + D\n   C     ",[](double A,double B,double C,double D){return -A*B/C + D;}),
        
        four_terms_expr(u8"-A⋅(B - C - D)",[](double A,double B,double C,double D){return -A*(B - C - D);}),
        
        four_terms_expr(u8"    -A + B\nD - ──────\n      C   ",[](double A,double B,double C,double D){return D - (-A + B)/C;}),
        
        four_terms_expr(u8"    A      \n- ───── + D\n  B - C    ",[](double A,double B,double C,double D){return -A/(B - C) + D;}),
        
        four_terms_expr(u8"-A + B - C + D",[](double A,double B,double C,double D){return -A + B - C + D;}),
        
        four_terms_expr(u8"       B  \n-A + ─────\n     C - D",[](double A,double B,double C,double D){return -A + B/(C - D);}),
        
        four_terms_expr(u8"A⋅(-B + C)\n──────────\n    D     ",[](double A,double B,double C,double D){return A*(-B + C)/D;}),
        
        four_terms_expr(u8"A⋅D⋅(-B - C)",[](double A,double B,double C,double D){return A*D*(-B - C);}),
        
        four_terms_expr(u8"   ⎛B    ⎞\n-A⋅⎜─ + D⎟\n   ⎝C    ⎠",[](double A,double B,double C,double D){return -A*(B/C + D);}),
        
        four_terms_expr(u8"A - B + C + D",[](double A,double B,double C,double D){return A - B + C + D;}),
        
        four_terms_expr(u8"-A + B + C - D",[](double A,double B,double C,double D){return -A + B + C - D;}),
        
        four_terms_expr(u8"     B    \n-A - ─ - D\n     C    ",[](double A,double B,double C,double D){return -A - B/C - D;}),
        
        four_terms_expr(u8"-A⋅(-B + C) - D",[](double A,double B,double C,double D){return -A*(-B + C) - D;}),
        
        four_terms_expr(u8"-A⋅(B - C) - D",[](double A,double B,double C,double D){return -A*(B - C) - D;}),
        
        four_terms_expr(u8"C⋅(A - B) - D",[](double A,double B,double C,double D){return C*(A - B) - D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB⋅(C + D)",[](double A,double B,double C,double D){return -A/(B*(C + D));}),
        
        four_terms_expr(u8"A⋅(B - C) + D",[](double A,double B,double C,double D){return A*(B - C) + D;}),
        
        four_terms_expr(u8"A⋅D⋅(B + C)",[](double A,double B,double C,double D){return A*D*(B + C);}),
        
        four_terms_expr(u8"     -A + B\n-D + ──────\n       C   ",[](double A,double B,double C,double D){return -D + (-A + B)/C;}),
        
        four_terms_expr(u8"A⋅B⋅(C - D)",[](double A,double B,double C,double D){return A*B*(C - D);}),
        
        four_terms_expr(u8"D⋅(A + B⋅C)",[](double A,double B,double C,double D){return D*(A + B*C);}),
        
        four_terms_expr(u8"D⋅(-A - B⋅C)",[](double A,double B,double C,double D){return D*(-A - B*C);}),
        
        four_terms_expr(u8"  -A    \n────────\n-B - C⋅D",[](double A,double B,double C,double D){return -A/(-B - C*D);}),
        
        four_terms_expr(u8"A - B⋅C + D",[](double A,double B,double C,double D){return A - B*C + D;}),
        
        four_terms_expr(u8"         C\n-A - B - ─\n         D",[](double A,double B,double C,double D){return -A - B - C/D;}),
        
        four_terms_expr(u8"A⋅(B - C + D)",[](double A,double B,double C,double D){return A*(B - C + D);}),
        
        four_terms_expr(u8"-A + B⋅C⋅D",[](double A,double B,double C,double D){return -A + B*C*D;}),
        
        four_terms_expr(u8"    A     \n──────────\n-B - C - D",[](double A,double B,double C,double D){return A/(-B - C - D);}),
        
        four_terms_expr(u8"       B   \n-A + ──────\n     -C - D",[](double A,double B,double C,double D){return -A + B/(-C - D);}),
        
        four_terms_expr(u8"-C⋅(-A - B) - D",[](double A,double B,double C,double D){return -C*(-A - B) - D;}),
        
        four_terms_expr(u8"A⋅B⋅(-C - D)",[](double A,double B,double C,double D){return A*B*(-C - D);}),
        
        four_terms_expr(u8"    A - B\nD - ─────\n      C  ",[](double A,double B,double C,double D){return D - (A - B)/C;}),
        
        four_terms_expr(u8"A + D⋅(-B + C)",[](double A,double B,double C,double D){return A + D*(-B + C);}),
        
        four_terms_expr(u8"  A  \n─────\n    C\nB + ─\n    D",[](double A,double B,double C,double D){return A/(B + C/D);}),
        
        four_terms_expr(u8"     B⋅D\n-A + ───\n      C ",[](double A,double B,double C,double D){return -A + B*D/C;}),
        
        four_terms_expr(u8"  A   \n──────\n     C\n-B - ─\n     D",[](double A,double B,double C,double D){return A/(-B - C/D);}),
        
        four_terms_expr(u8"     B    \n-A + ─ - D\n     C    ",[](double A,double B,double C,double D){return -A + B/C - D;}),
        
        four_terms_expr(u8"  ⎛     B⎞\nD⋅⎜-A + ─⎟\n  ⎝     C⎠",[](double A,double B,double C,double D){return D*(-A + B/C);}),
        
        four_terms_expr(u8"  A⋅C    \n- ─── + D\n   B     ",[](double A,double B,double C,double D){return -A*C/B + D;}),
        
        four_terms_expr(u8"A⋅C    \n─── - D\n B     ",[](double A,double B,double C,double D){return A*C/B - D;}),
        
        four_terms_expr(u8"-A + B + C\n──────────\n    D     ",[](double A,double B,double C,double D){return (-A + B + C)/D;}),
        
        four_terms_expr(u8"-A - B\n──────\n C⋅D  ",[](double A,double B,double C,double D){return (-A - B)/(C*D);}),
        
        four_terms_expr(u8"A    \n─ + C\nB    \n─────\n  D  ",[](double A,double B,double C,double D){return (A/B + C)/D;}),
        
        four_terms_expr(u8"-A⋅B⋅C⋅D",[](double A,double B,double C,double D){return -A*B*C*D;}),
        
        four_terms_expr(u8"A⋅(-B + C⋅D)",[](double A,double B,double C,double D){return A*(-B + C*D);}),
        
        four_terms_expr(u8"-A⋅(-B - C⋅D)",[](double A,double B,double C,double D){return -A*(-B - C*D);}),
        
        four_terms_expr(u8"-A⋅D \n─────\n B⋅C ",[](double A,double B,double C,double D){return -A*D/(B*C);}),
        
        four_terms_expr(u8"    A       \n- ────── - D\n  -B - C    ",[](double A,double B,double C,double D){return -A/(-B - C) - D;}),
        
        four_terms_expr(u8"  -A   \n───────\nB⋅C - D",[](double A,double B,double C,double D){return -A/(B*C - D);}),
        
        four_terms_expr(u8"     B - C\n-A - ─────\n       D  ",[](double A,double B,double C,double D){return -A - (B - C)/D;}),
        
        four_terms_expr(u8"  ⎛  A    ⎞\nD⋅⎜- ─ + C⎟\n  ⎝  B    ⎠",[](double A,double B,double C,double D){return D*(-A/B + C);}),
        
        four_terms_expr(u8"A    \n─ - C\nB    \n─────\n  D  ",[](double A,double B,double C,double D){return (A/B - C)/D;}),
        
        four_terms_expr(u8"A - B⋅C⋅D",[](double A,double B,double C,double D){return A - B*C*D;}),
        
        four_terms_expr(u8"(-A - B)⋅(-C + D)",[](double A,double B,double C,double D){return (-A - B)*(-C + D);}),
        
        four_terms_expr(u8"       B  \n-A - ─────\n     C - D",[](double A,double B,double C,double D){return -A - B/(C - D);}),
        
        four_terms_expr(u8"  ⎛  A    ⎞\nD⋅⎜- ─ - C⎟\n  ⎝  B    ⎠",[](double A,double B,double C,double D){return D*(-A/B - C);}),
        
        four_terms_expr(u8"  A      \n- ─ - C⋅D\n  B      ",[](double A,double B,double C,double D){return -A/B - C*D;}),
        
        four_terms_expr(u8"    B\nA + ─\n    C\n─────\n  D  ",[](double A,double B,double C,double D){return (A + B/C)/D;}),
        
        four_terms_expr(u8"    A     \n──────────\n-B + C - D",[](double A,double B,double C,double D){return A/(-B + C - D);}),
        
        four_terms_expr(u8"-A⋅(C - D) \n───────────\n     B     ",[](double A,double B,double C,double D){return -A*(C - D)/B;}),
        
        four_terms_expr(u8" A⋅D \n─────\nB + C",[](double A,double B,double C,double D){return A*D/(B + C);}),
        
        four_terms_expr(u8"       B  \n-A - ─────\n     C + D",[](double A,double B,double C,double D){return -A - B/(C + D);}),
        
        four_terms_expr(u8"  A⋅B    \n- ─── - D\n   C     ",[](double A,double B,double C,double D){return -A*B/C - D;}),
        
        four_terms_expr(u8"-D⋅(-A - B) \n────────────\n     C      ",[](double A,double B,double C,double D){return -D*(-A - B)/C;}),
        
        four_terms_expr(u8"-A⋅D  \n──────\n-B - C",[](double A,double B,double C,double D){return -A*D/(-B - C);}),
        
        four_terms_expr(u8"-A⋅(-B - C + D)",[](double A,double B,double C,double D){return -A*(-B - C + D);}),
        
        four_terms_expr(u8"A⋅B⋅C + D",[](double A,double B,double C,double D){return A*B*C + D;}),
        
        four_terms_expr(u8"-A⋅B + C\n────────\n   D    ",[](double A,double B,double C,double D){return (-A*B + C)/D;}),
        
        four_terms_expr(u8"     -A + B\n-D - ──────\n       C   ",[](double A,double B,double C,double D){return -D - (-A + B)/C;}),
        
        four_terms_expr(u8"-A + B\n──────\nC - D ",[](double A,double B,double C,double D){return (-A + B)/(C - D);}),
        
        four_terms_expr(u8"A⋅B\n───\nC⋅D",[](double A,double B,double C,double D){return A*B/(C*D);}),
        
        four_terms_expr(u8"  -A   \n───────\n  B    \n- ─ - D\n  C    ",[](double A,double B,double C,double D){return -A/(-B/C - D);}),
        
        four_terms_expr(u8"A        \n─ - C - D\nB        ",[](double A,double B,double C,double D){return A/B - C - D;}),
        
        four_terms_expr(u8"-A⋅(-C - D) \n────────────\n     B      ",[](double A,double B,double C,double D){return -A*(-C - D)/B;}),
        
        four_terms_expr(u8"D⋅(-A - B + C)",[](double A,double B,double C,double D){return D*(-A - B + C);}),
        
        four_terms_expr(u8"A⋅(-B + C) + D",[](double A,double B,double C,double D){return A*(-B + C) + D;}),
        
        four_terms_expr(u8"  ⎛    B⎞\nD⋅⎜A - ─⎟\n  ⎝    C⎠",[](double A,double B,double C,double D){return D*(A - B/C);}),
        
        four_terms_expr(u8"-A⋅D⋅(-B - C)",[](double A,double B,double C,double D){return -A*D*(-B - C);}),
        
        four_terms_expr(u8"     B    \n-A - ─ + D\n     C    ",[](double A,double B,double C,double D){return -A - B/C + D;}),
        
        four_terms_expr(u8"D⋅(A⋅B + C)",[](double A,double B,double C,double D){return D*(A*B + C);}),
        
        four_terms_expr(u8"   -A    \n─────────\nB - C - D",[](double A,double B,double C,double D){return -A/(B - C - D);}),
        
        four_terms_expr(u8"A⋅(B - C) - D",[](double A,double B,double C,double D){return A*(B - C) - D;}),
        
        four_terms_expr(u8"  ⎛    C⎞\nA⋅⎜B - ─⎟\n  ⎝    D⎠",[](double A,double B,double C,double D){return A*(B - C/D);}),
        
        four_terms_expr(u8"    -B - C\nA - ──────\n      D   ",[](double A,double B,double C,double D){return A - (-B - C)/D;}),
        
        four_terms_expr(u8"A - D⋅(B - C)",[](double A,double B,double C,double D){return A - D*(B - C);}),
        
        four_terms_expr(u8"A        \n─ + C - D\nB        ",[](double A,double B,double C,double D){return A/B + C - D;}),
        
        four_terms_expr(u8"  ⎛  B    ⎞\nA⋅⎜- ─ - D⎟\n  ⎝  C    ⎠",[](double A,double B,double C,double D){return A*(-B/C - D);}),
        
        four_terms_expr(u8"-A⋅D⋅(B + C)",[](double A,double B,double C,double D){return -A*D*(B + C);}),
        
        four_terms_expr(u8"-A + B\n──────\n-C - D",[](double A,double B,double C,double D){return (-A + B)/(-C - D);}),
        
        four_terms_expr(u8"-A + B⋅C + D",[](double A,double B,double C,double D){return -A + B*C + D;}),
        
        four_terms_expr(u8"A⋅(-B + C - D)",[](double A,double B,double C,double D){return A*(-B + C - D);}),
        
        four_terms_expr(u8"A - B⋅C\n───────\n   D   ",[](double A,double B,double C,double D){return (A - B*C)/D;}),
        
        four_terms_expr(u8" A⋅B  \n──────\n-C + D",[](double A,double B,double C,double D){return A*B/(-C + D);}),
        
        four_terms_expr(u8"-C⋅(-A + B) \n────────────\n     D      ",[](double A,double B,double C,double D){return -C*(-A + B)/D;}),
        
        four_terms_expr(u8"  ⎛  B    ⎞\nA⋅⎜- ─ + D⎟\n  ⎝  C    ⎠",[](double A,double B,double C,double D){return A*(-B/C + D);}),
        
        four_terms_expr(u8"-A + B⋅(C + D)",[](double A,double B,double C,double D){return -A + B*(C + D);}),
        
        four_terms_expr(u8"    A      \n- ───── - D\n  B + C    ",[](double A,double B,double C,double D){return -A/(B + C) - D;}),
        
        four_terms_expr(u8"C⋅(-A + B) + D",[](double A,double B,double C,double D){return C*(-A + B) + D;}),
        
        four_terms_expr(u8"  A      \n───── + D\nB + C    ",[](double A,double B,double C,double D){return A/(B + C) + D;}),
        
        four_terms_expr(u8"       C\n-A⋅B - ─\n       D",[](double A,double B,double C,double D){return -A*B - C/D;}),
        
        four_terms_expr(u8"     B⋅D\n-A - ───\n      C ",[](double A,double B,double C,double D){return -A - B*D/C;}),
        
        four_terms_expr(u8"-A⋅B⋅D \n───────\n   C   ",[](double A,double B,double C,double D){return -A*B*D/C;}),
        
        four_terms_expr(u8"-A - D⋅(B + C)",[](double A,double B,double C,double D){return -A - D*(B + C);}),
        
        four_terms_expr(u8" A     \n─── - D\nB⋅C    ",[](double A,double B,double C,double D){return A/(B*C) - D;}),
        
        four_terms_expr(u8"  A       \n────── + D\n-B - C    ",[](double A,double B,double C,double D){return A/(-B - C) + D;}),
        
        four_terms_expr(u8"-A - B⋅(C - D)",[](double A,double B,double C,double D){return -A - B*(C - D);}),
        
        four_terms_expr(u8"   ⎛B    ⎞\n-A⋅⎜─ - D⎟\n   ⎝C    ⎠",[](double A,double B,double C,double D){return -A*(B/C - D);}),
        
        four_terms_expr(u8"-A⋅C \n─────\n B⋅D ",[](double A,double B,double C,double D){return -A*C/(B*D);}),
        
        four_terms_expr(u8"-A⋅B⋅C - D",[](double A,double B,double C,double D){return -A*B*C - D;}),
        
        four_terms_expr(u8"   A    \n────────\n-B⋅C + D",[](double A,double B,double C,double D){return A/(-B*C + D);}),
        
        four_terms_expr(u8"-(-A + B) \n──────────\n   C⋅D    ",[](double A,double B,double C,double D){return -(-A + B)/(C*D);}),
        
        four_terms_expr(u8"A⋅B - C + D",[](double A,double B,double C,double D){return A*B - C + D;}),
        
        four_terms_expr(u8"-A + B - C - D",[](double A,double B,double C,double D){return -A + B - C - D;}),
        
        four_terms_expr(u8"A⋅(B + C) - D",[](double A,double B,double C,double D){return A*(B + C) - D;}),
        
        four_terms_expr(u8"D⋅(A + B + C)",[](double A,double B,double C,double D){return D*(A + B + C);}),
        
        four_terms_expr(u8"-A - B - C + D",[](double A,double B,double C,double D){return -A - B - C + D;}),
        
        four_terms_expr(u8"-A⋅(-B + C) + D",[](double A,double B,double C,double D){return -A*(-B + C) + D;}),
        
        four_terms_expr(u8"     B + C\n-A - ─────\n       D  ",[](double A,double B,double C,double D){return -A - (B + C)/D;}),
        
        four_terms_expr(u8"   ⎛     C⎞\n-A⋅⎜-B - ─⎟\n   ⎝     D⎠",[](double A,double B,double C,double D){return -A*(-B - C/D);}),
        
        four_terms_expr(u8"-A + B⋅(C - D)",[](double A,double B,double C,double D){return -A + B*(C - D);}),
        
        four_terms_expr(u8"A - B \n──────\n-C - D",[](double A,double B,double C,double D){return (A - B)/(-C - D);}),
        
        four_terms_expr(u8"-A⋅(B - C) + D",[](double A,double B,double C,double D){return -A*(B - C) + D;}),
        
        four_terms_expr(u8"     -A - B\n-D - ──────\n       C   ",[](double A,double B,double C,double D){return -D - (-A - B)/C;}),
        
        four_terms_expr(u8" -A   \n──────\n     C\n-B + ─\n     D",[](double A,double B,double C,double D){return -A/(-B + C/D);}),
        
        four_terms_expr(u8"C⋅(A - B) + D",[](double A,double B,double C,double D){return C*(A - B) + D;}),
        
        four_terms_expr(u8"A + B + C - D",[](double A,double B,double C,double D){return A + B + C - D;}),
        
        four_terms_expr(u8"-A - B⋅C + D",[](double A,double B,double C,double D){return -A - B*C + D;}),
        
        four_terms_expr(u8"    -A - B\nD + ──────\n      C   ",[](double A,double B,double C,double D){return D + (-A - B)/C;}),
        
        four_terms_expr(u8"    -A + B\nD + ──────\n      C   ",[](double A,double B,double C,double D){return D + (-A + B)/C;}),
        
        four_terms_expr(u8"-C⋅(A - B) \n───────────\n     D     ",[](double A,double B,double C,double D){return -C*(A - B)/D;}),
        
        four_terms_expr(u8"-C⋅(A + B) - D",[](double A,double B,double C,double D){return -C*(A + B) - D;}),
        
        four_terms_expr(u8"-A + B⋅(-C + D)",[](double A,double B,double C,double D){return -A + B*(-C + D);}),
        
        four_terms_expr(u8"-A⋅D \n─────\nB + C",[](double A,double B,double C,double D){return -A*D/(B + C);}),
        
        four_terms_expr(u8"-A⋅B⋅(C + D)",[](double A,double B,double C,double D){return -A*B*(C + D);}),
        
        four_terms_expr(u8"A⋅(C - D)\n─────────\n    B    ",[](double A,double B,double C,double D){return A*(C - D)/B;}),
        
        four_terms_expr(u8"-A⋅(B + C⋅D)",[](double A,double B,double C,double D){return -A*(B + C*D);}),
        
        four_terms_expr(u8"-A⋅B - C\n────────\n   D    ",[](double A,double B,double C,double D){return (-A*B - C)/D;}),
        
        four_terms_expr(u8"(-A - B)⋅(-C - D)",[](double A,double B,double C,double D){return (-A - B)*(-C - D);}),
        
        four_terms_expr(u8"A⋅(B⋅C - D)",[](double A,double B,double C,double D){return A*(B*C - D);}),
        
        four_terms_expr(u8"(-A + B)⋅(C + D)",[](double A,double B,double C,double D){return (-A + B)*(C + D);}),
        
        four_terms_expr(u8"A + B \n──────\n-C - D",[](double A,double B,double C,double D){return (A + B)/(-C - D);}),
        
        four_terms_expr(u8"A⋅(B - C)\n─────────\n    D    ",[](double A,double B,double C,double D){return A*(B - C)/D;}),
        
        four_terms_expr(u8"-C⋅(-A - B) + D",[](double A,double B,double C,double D){return -C*(-A - B) + D;}),
        
        four_terms_expr(u8"C⋅(-A + B)\n──────────\n    D     ",[](double A,double B,double C,double D){return C*(-A + B)/D;}),
        
        four_terms_expr(u8"-C⋅(A + B) \n───────────\n     D     ",[](double A,double B,double C,double D){return -C*(A + B)/D;}),
        
        four_terms_expr(u8"-A - B⋅(C + D)",[](double A,double B,double C,double D){return -A - B*(C + D);}),
        
        four_terms_expr(u8"   -A    \n─────────\nB + C - D",[](double A,double B,double C,double D){return -A/(B + C - D);}),
        
        four_terms_expr(u8"A⋅(-C - D)\n──────────\n    B     ",[](double A,double B,double C,double D){return A*(-C - D)/B;}),
        
        four_terms_expr(u8"A⋅(C + D)\n─────────\n    B    ",[](double A,double B,double C,double D){return A*(C + D)/B;}),
        
        four_terms_expr(u8"-A + D⋅(-B - C)",[](double A,double B,double C,double D){return -A + D*(-B - C);}),
        
        four_terms_expr(u8"  ⎛     C⎞\nA⋅⎜-B + ─⎟\n  ⎝     D⎠",[](double A,double B,double C,double D){return A*(-B + C/D);}),
        
        four_terms_expr(u8"     B + C\n-A + ─────\n       D  ",[](double A,double B,double C,double D){return -A + (B + C)/D;}),
        
        four_terms_expr(u8"      B   \nA + ──────\n    -C + D",[](double A,double B,double C,double D){return A + B/(-C + D);}),
        
        four_terms_expr(u8"-C⋅D⋅(-A + B)",[](double A,double B,double C,double D){return -C*D*(-A + B);}),
        
        four_terms_expr(u8"-A⋅B + C⋅D",[](double A,double B,double C,double D){return -A*B + C*D;}),
        
        four_terms_expr(u8"-A⋅(-B + C + D)",[](double A,double B,double C,double D){return -A*(-B + C + D);}),
        
        four_terms_expr(u8"        C\nA - B + ─\n        D",[](double A,double B,double C,double D){return A - B + C/D;}),
        
        four_terms_expr(u8"   A   \n───────\nB + C⋅D",[](double A,double B,double C,double D){return A/(B + C*D);}),
        
        four_terms_expr(u8"D⋅(-A + B)\n──────────\n    C     ",[](double A,double B,double C,double D){return D*(-A + B)/C;}),
        
        four_terms_expr(u8"-A⋅B  \n──────\n-C - D",[](double A,double B,double C,double D){return -A*B/(-C - D);}),
        
        four_terms_expr(u8"A + B⋅C⋅D",[](double A,double B,double C,double D){return A + B*C*D;}),
        
        four_terms_expr(u8"C⋅D⋅(-A - B)",[](double A,double B,double C,double D){return C*D*(-A - B);}),
        
        four_terms_expr(u8"   A   \n───────\nB⋅C + D",[](double A,double B,double C,double D){return A/(B*C + D);}),
        
        four_terms_expr(u8"     B⋅C\n-A - ───\n      D ",[](double A,double B,double C,double D){return -A - B*C/D;}),
        
        four_terms_expr(u8"A   C\n─ + ─\nB   D",[](double A,double B,double C,double D){return A/B + C/D;}),
        
        four_terms_expr(u8"A⋅(B⋅C + D)",[](double A,double B,double C,double D){return A*(B*C + D);}),
        
        four_terms_expr(u8"      B \n-A - ───\n     C⋅D",[](double A,double B,double C,double D){return -A - B/(C*D);}),
        
        four_terms_expr(u8"     B\n-A - ─\n     C\n──────\n  D   ",[](double A,double B,double C,double D){return (-A - B/C)/D;}),
        
        four_terms_expr(u8"    A    \n─────────\nB + C + D",[](double A,double B,double C,double D){return A/(B + C + D);}),
        
        four_terms_expr(u8"C⋅(-A + B) - D",[](double A,double B,double C,double D){return C*(-A + B) - D;}),
        
        four_terms_expr(u8"A        \n─ + C + D\nB        ",[](double A,double B,double C,double D){return A/B + C + D;}),
        
        four_terms_expr(u8"-A⋅(B + C) - D",[](double A,double B,double C,double D){return -A*(B + C) - D;}),
        
        four_terms_expr(u8"A - B - C⋅D",[](double A,double B,double C,double D){return A - B - C*D;}),
        
        four_terms_expr(u8"(A - B)⋅(C - D)",[](double A,double B,double C,double D){return (A - B)*(C - D);}),
        
        four_terms_expr(u8"-A⋅(B + C + D)",[](double A,double B,double C,double D){return -A*(B + C + D);}),
        
        four_terms_expr(u8"A      \n─ - C⋅D\nB      ",[](double A,double B,double C,double D){return A/B - C*D;}),
        
        four_terms_expr(u8"C⋅(A - B)\n─────────\n    D    ",[](double A,double B,double C,double D){return C*(A - B)/D;}),
        
        four_terms_expr(u8" A⋅D  \n──────\n-B + C",[](double A,double B,double C,double D){return A*D/(-B + C);}),
        
        four_terms_expr(u8"  A        \n- ─ - C - D\n  B        ",[](double A,double B,double C,double D){return -A/B - C - D;}),
        
        four_terms_expr(u8"A + B - C⋅D",[](double A,double B,double C,double D){return A + B - C*D;}),
        
        four_terms_expr(u8"(A - B)⋅(-C - D)",[](double A,double B,double C,double D){return (A - B)*(-C - D);}),
        
        four_terms_expr(u8"       B   \n-A - ──────\n     -C - D",[](double A,double B,double C,double D){return -A - B/(-C - D);}),
        
        four_terms_expr(u8"A⋅B + C⋅D",[](double A,double B,double C,double D){return A*B + C*D;}),
        
        four_terms_expr(u8"A - B \n──────\n-C + D",[](double A,double B,double C,double D){return (A - B)/(-C + D);}),
        
        four_terms_expr(u8"    A    \n─────────\nB - C + D",[](double A,double B,double C,double D){return A/(B - C + D);}),
        
        four_terms_expr(u8"      B  \nA - ─────\n    C + D",[](double A,double B,double C,double D){return A - B/(C + D);}),
        
        four_terms_expr(u8"A - D⋅(-B + C)",[](double A,double B,double C,double D){return A - D*(-B + C);}),
        
        four_terms_expr(u8"A + D⋅(B + C)",[](double A,double B,double C,double D){return A + D*(B + C);}),
        
        four_terms_expr(u8"-A + B⋅(-C - D)",[](double A,double B,double C,double D){return -A + B*(-C - D);}),
        
        four_terms_expr(u8" -A  \n─────\nB    \n─ + D\nC    ",[](double A,double B,double C,double D){return -A/(B/C + D);}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B - C + D",[](double A,double B,double C,double D){return -A/(-B - C + D);}),
        
        four_terms_expr(u8"C⋅(A + B)\n─────────\n    D    ",[](double A,double B,double C,double D){return C*(A + B)/D;}),
        
        four_terms_expr(u8"     -A - B\n-D + ──────\n       C   ",[](double A,double B,double C,double D){return -D + (-A - B)/C;}),
        
        four_terms_expr(u8"  A        \n- ─ + C - D\n  B        ",[](double A,double B,double C,double D){return -A/B + C - D;}),
        
        four_terms_expr(u8"-A⋅B  \n──────\n-C + D",[](double A,double B,double C,double D){return -A*B/(-C + D);}),
        
        four_terms_expr(u8"      B   \nA - ──────\n    -C + D",[](double A,double B,double C,double D){return A - B/(-C + D);}),
        
        four_terms_expr(u8"A⋅(B + C - D)",[](double A,double B,double C,double D){return A*(B + C - D);}),
        
        four_terms_expr(u8"-A + B⋅C - D",[](double A,double B,double C,double D){return -A + B*C - D;}),
        
        four_terms_expr(u8"A + B \n──────\n-C + D",[](double A,double B,double C,double D){return (A + B)/(-C + D);}),
        
        four_terms_expr(u8"-A⋅(-B⋅C - D)",[](double A,double B,double C,double D){return -A*(-B*C - D);}),
        
        four_terms_expr(u8"       C\n-A⋅B + ─\n       D",[](double A,double B,double C,double D){return -A*B + C/D;}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B - C - D",[](double A,double B,double C,double D){return -A/(-B - C - D);}),
        
        four_terms_expr(u8"-A⋅(B - C) \n───────────\n     D     ",[](double A,double B,double C,double D){return -A*(B - C)/D;}),
        
        four_terms_expr(u8" -A  \n─────\n    C\nB + ─\n    D",[](double A,double B,double C,double D){return -A/(B + C/D);}),
        
        four_terms_expr(u8" -A   \n──────\n     C\n-B - ─\n     D",[](double A,double B,double C,double D){return -A/(-B - C/D);}),
        
        four_terms_expr(u8"    A      \n- ───── + D\n  B + C    ",[](double A,double B,double C,double D){return -A/(B + C) + D;}),
        
        four_terms_expr(u8"    A     \n──────────\nB⋅(-C + D)",[](double A,double B,double C,double D){return A/(B*(-C + D));}),
        
        four_terms_expr(u8"A⋅(B - C - D)",[](double A,double B,double C,double D){return A*(B - C - D);}),
        
        four_terms_expr(u8" A⋅D \n─────\nB - C",[](double A,double B,double C,double D){return A*D/(B - C);}),
        
        four_terms_expr(u8"A⋅B⋅(C + D)",[](double A,double B,double C,double D){return A*B*(C + D);}),
        
        four_terms_expr(u8"  -A   \n───────\n  B    \n- ─ + D\n  C    ",[](double A,double B,double C,double D){return -A/(-B/C + D);}),
        
        four_terms_expr(u8"-A⋅(-B + C⋅D)",[](double A,double B,double C,double D){return -A*(-B + C*D);}),
        
        four_terms_expr(u8"-A + B⋅C\n────────\n   D    ",[](double A,double B,double C,double D){return (-A + B*C)/D;}),
        
        four_terms_expr(u8" A     \n─── + D\nB⋅C    ",[](double A,double B,double C,double D){return A/(B*C) + D;}),
        
        four_terms_expr(u8"A + D⋅(B - C)",[](double A,double B,double C,double D){return A + D*(B - C);}),
        
        four_terms_expr(u8"     B\n-A + ─\n     C\n──────\n  D   ",[](double A,double B,double C,double D){return (-A + B/C)/D;}),
        
        four_terms_expr(u8"      C\nA⋅B - ─\n      D",[](double A,double B,double C,double D){return A*B - C/D;}),
        
        four_terms_expr(u8"-A⋅B \n─────\nC - D",[](double A,double B,double C,double D){return -A*B/(C - D);}),
        
        four_terms_expr(u8"     B \nA + ───\n    C⋅D",[](double A,double B,double C,double D){return A + B/(C*D);}),
        
        four_terms_expr(u8"-A + B + C⋅D",[](double A,double B,double C,double D){return -A + B + C*D;}),
        
        four_terms_expr(u8"  -A   \n───────\nB - C⋅D",[](double A,double B,double C,double D){return -A/(B - C*D);}),
        
        four_terms_expr(u8"-A⋅(-B⋅C + D)",[](double A,double B,double C,double D){return -A*(-B*C + D);}),
        
        four_terms_expr(u8"  ⎛B    ⎞\nA⋅⎜─ + D⎟\n  ⎝C    ⎠",[](double A,double B,double C,double D){return A*(B/C + D);}),
        
        four_terms_expr(u8"-A⋅B⋅C + D",[](double A,double B,double C,double D){return -A*B*C + D;}),
        
        four_terms_expr(u8"    B⋅D\nA - ───\n     C ",[](double A,double B,double C,double D){return A - B*D/C;}),
        
        four_terms_expr(u8"-A⋅B - C + D",[](double A,double B,double C,double D){return -A*B - C + D;}),
        
        four_terms_expr(u8"A - D⋅(B + C)",[](double A,double B,double C,double D){return A - D*(B + C);}),
        
        four_terms_expr(u8"    A    \n─────────\nB⋅(C - D)",[](double A,double B,double C,double D){return A/(B*(C - D));}),
        
        four_terms_expr(u8"-A + B\n──────\n C⋅D  ",[](double A,double B,double C,double D){return (-A + B)/(C*D);}),
        
        four_terms_expr(u8" A⋅B  \n──────\n-C - D",[](double A,double B,double C,double D){return A*B/(-C - D);}),
        
        four_terms_expr(u8"A⋅(B + C) + D",[](double A,double B,double C,double D){return A*(B + C) + D;}),
        
        four_terms_expr(u8"-A⋅(B + C) \n───────────\n     D     ",[](double A,double B,double C,double D){return -A*(B + C)/D;}),
        
        four_terms_expr(u8"     -B - C\n-A + ──────\n       D   ",[](double A,double B,double C,double D){return -A + (-B - C)/D;}),
        
        four_terms_expr(u8"-A + B + C + D",[](double A,double B,double C,double D){return -A + B + C + D;}),
        
        four_terms_expr(u8"   A    \n────────\n-B - C⋅D",[](double A,double B,double C,double D){return A/(-B - C*D);}),
        
        four_terms_expr(u8"-A⋅B⋅(-C + D)",[](double A,double B,double C,double D){return -A*B*(-C + D);}),
        
        four_terms_expr(u8"A⋅B⋅C\n─────\n  D  ",[](double A,double B,double C,double D){return A*B*C/D;}),
        
        four_terms_expr(u8"-A - B⋅C - D",[](double A,double B,double C,double D){return -A - B*C - D;}),
        
        four_terms_expr(u8"    -A - B\nD - ──────\n      C   ",[](double A,double B,double C,double D){return D - (-A - B)/C;}),
        
        four_terms_expr(u8"     A + B\n-D - ─────\n       C  ",[](double A,double B,double C,double D){return -D - (A + B)/C;}),
        
        four_terms_expr(u8"    B - C\nA + ─────\n      D  ",[](double A,double B,double C,double D){return A + (B - C)/D;}),
        
        four_terms_expr(u8"D⋅(-A + B + C)",[](double A,double B,double C,double D){return D*(-A + B + C);}),
        
        four_terms_expr(u8"(-A + B)⋅(-C + D)",[](double A,double B,double C,double D){return (-A + B)*(-C + D);}),
        
        four_terms_expr(u8"  ⎛A    ⎞\nD⋅⎜─ + C⎟\n  ⎝B    ⎠",[](double A,double B,double C,double D){return D*(A/B + C);}),
        
        four_terms_expr(u8"A⋅D⋅(-B + C)",[](double A,double B,double C,double D){return A*D*(-B + C);}),
        
        four_terms_expr(u8"-C⋅(A + B) + D",[](double A,double B,double C,double D){return -C*(A + B) + D;}),
        
        four_terms_expr(u8"   ⎛    C⎞\n-A⋅⎜B + ─⎟\n   ⎝    D⎠",[](double A,double B,double C,double D){return -A*(B + C/D);}),
        
        four_terms_expr(u8"-A - B - C⋅D",[](double A,double B,double C,double D){return -A - B - C*D;}),
        
        four_terms_expr(u8"         C\n-A + B - ─\n         D",[](double A,double B,double C,double D){return -A + B - C/D;}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B + C + D",[](double A,double B,double C,double D){return -A/(-B + C + D);}),
        
        four_terms_expr(u8"-A⋅(C + D) \n───────────\n     B     ",[](double A,double B,double C,double D){return -A*(C + D)/B;}),
        
        four_terms_expr(u8"A⋅(-B - C⋅D)",[](double A,double B,double C,double D){return A*(-B - C*D);}),
        
        four_terms_expr(u8"-A - B - C - D",[](double A,double B,double C,double D){return -A - B - C - D;}),
        
        four_terms_expr(u8"  ⎛A    ⎞\nD⋅⎜─ - C⎟\n  ⎝B    ⎠",[](double A,double B,double C,double D){return D*(A/B - C);}),
        
        four_terms_expr(u8"-A⋅D  \n──────\n-B + C",[](double A,double B,double C,double D){return -A*D/(-B + C);}),
        
        four_terms_expr(u8"A + B⋅(C - D)",[](double A,double B,double C,double D){return A + B*(C - D);}),
        
        four_terms_expr(u8" -A  \n─────\n    C\nB - ─\n    D",[](double A,double B,double C,double D){return -A/(B - C/D);}),
        
        four_terms_expr(u8"   A   \n───────\nB⋅C - D",[](double A,double B,double C,double D){return A/(B*C - D);}),
        
        four_terms_expr(u8"      B  \nA + ─────\n    C + D",[](double A,double B,double C,double D){return A + B/(C + D);}),
        
        four_terms_expr(u8"(A + B)⋅(C - D)",[](double A,double B,double C,double D){return (A + B)*(C - D);}),
        
        four_terms_expr(u8"-A - B - C\n──────────\n    D     ",[](double A,double B,double C,double D){return (-A - B - C)/D;}),
        
        four_terms_expr(u8"-D⋅(-A + B) \n────────────\n     C      ",[](double A,double B,double C,double D){return -D*(-A + B)/C;}),
        
        four_terms_expr(u8"  A       \n────── - D\n-B + C    ",[](double A,double B,double C,double D){return A/(-B + C) - D;}),
        
        four_terms_expr(u8"-A - D⋅(-B - C)",[](double A,double B,double C,double D){return -A - D*(-B - C);}),
        
        four_terms_expr(u8"  ⎛    B⎞\nD⋅⎜A + ─⎟\n  ⎝    C⎠",[](double A,double B,double C,double D){return D*(A + B/C);}),
        
        four_terms_expr(u8"A⋅B + C\n───────\n   D   ",[](double A,double B,double C,double D){return (A*B + C)/D;}),
        
        four_terms_expr(u8"-A⋅(-B + C - D)",[](double A,double B,double C,double D){return -A*(-B + C - D);}),
        
        four_terms_expr(u8"A - B\n─────\n C⋅D ",[](double A,double B,double C,double D){return (A - B)/(C*D);}),
        
        four_terms_expr(u8"(A + B)⋅(-C - D)",[](double A,double B,double C,double D){return (A + B)*(-C - D);}),
        
        four_terms_expr(u8"   -A     \n──────────\nB⋅(-C - D)",[](double A,double B,double C,double D){return -A/(B*(-C - D));}),
        
        four_terms_expr(u8"D⋅(-A⋅B + C)",[](double A,double B,double C,double D){return D*(-A*B + C);}),
        
        four_terms_expr(u8"-A + B - C\n──────────\n    D     ",[](double A,double B,double C,double D){return (-A + B - C)/D;}),
        
        four_terms_expr(u8"A + B - C\n─────────\n    D    ",[](double A,double B,double C,double D){return (A + B - C)/D;}),
        
        four_terms_expr(u8"A - B + C\n─────────\n    D    ",[](double A,double B,double C,double D){return (A - B + C)/D;}),
        
        four_terms_expr(u8"C⋅(-A - B) + D",[](double A,double B,double C,double D){return C*(-A - B) + D;}),
        
        four_terms_expr(u8"-A⋅B \n─────\n C⋅D ",[](double A,double B,double C,double D){return -A*B/(C*D);}),
        
        four_terms_expr(u8"    -B + C\nA - ──────\n      D   ",[](double A,double B,double C,double D){return A - (-B + C)/D;}),
        
        four_terms_expr(u8"    B + C\nA + ─────\n      D  ",[](double A,double B,double C,double D){return A + (B + C)/D;}),
        
        four_terms_expr(u8"A⋅(-B - C + D)",[](double A,double B,double C,double D){return A*(-B - C + D);}),
        
        four_terms_expr(u8"A⋅C\n───\nB⋅D",[](double A,double B,double C,double D){return A*C/(B*D);}),
        
        four_terms_expr(u8"  A        \n- ─ + C + D\n  B        ",[](double A,double B,double C,double D){return -A/B + C + D;}),
        
        four_terms_expr(u8"  -A    \n────────\n-B⋅C - D",[](double A,double B,double C,double D){return -A/(-B*C - D);}),
        
        four_terms_expr(u8"-A - B\n──────\nC + D ",[](double A,double B,double C,double D){return (-A - B)/(C + D);}),
        
        four_terms_expr(u8"A - B - C\n─────────\n    D    ",[](double A,double B,double C,double D){return (A - B - C)/D;}),
        
        four_terms_expr(u8"-A⋅(B + C) + D",[](double A,double B,double C,double D){return -A*(B + C) + D;}),
        
        four_terms_expr(u8"    B    \nA - ─ - D\n    C    ",[](double A,double B,double C,double D){return A - B/C - D;}),
        
        four_terms_expr(u8"A + B\n─────\n C⋅D ",[](double A,double B,double C,double D){return (A + B)/(C*D);}),
        
        four_terms_expr(u8"-A⋅D \n─────\nB - C",[](double A,double B,double C,double D){return -A*D/(B - C);}),
        
        four_terms_expr(u8"   A   \n───────\n  B    \n- ─ - D\n  C    ",[](double A,double B,double C,double D){return A/(-B/C - D);}),
        
        four_terms_expr(u8"A - B\n─────\nC - D",[](double A,double B,double C,double D){return (A - B)/(C - D);}),
        
        four_terms_expr(u8"-A - B\n──────\n-C - D",[](double A,double B,double C,double D){return (-A - B)/(-C - D);}),
        
        four_terms_expr(u8"     B \nA - ───\n    C⋅D",[](double A,double B,double C,double D){return A - B/(C*D);}),
        
        four_terms_expr(u8"-A - B⋅(-C + D)",[](double A,double B,double C,double D){return -A - B*(-C + D);}),
        
        four_terms_expr(u8"-D⋅(A - B) \n───────────\n     C     ",[](double A,double B,double C,double D){return -D*(A - B)/C;}),
        
        four_terms_expr(u8" A⋅B \n─────\nC - D",[](double A,double B,double C,double D){return A*B/(C - D);}),
        
        four_terms_expr(u8"A⋅B - C - D",[](double A,double B,double C,double D){return A*B - C - D;}),
        
        four_terms_expr(u8"    -B + C\nA + ──────\n      D   ",[](double A,double B,double C,double D){return A + (-B + C)/D;}),
        
        four_terms_expr(u8"A + B\n─────\nC - D",[](double A,double B,double C,double D){return (A + B)/(C - D);}),
        
        four_terms_expr(u8"(-A - B)⋅(C + D)",[](double A,double B,double C,double D){return (-A - B)*(C + D);}),
        
        four_terms_expr(u8"    A + B\nD + ─────\n      C  ",[](double A,double B,double C,double D){return D + (A + B)/C;}),
        
        four_terms_expr(u8"    B    \nA + ─ - D\n    C    ",[](double A,double B,double C,double D){return A + B/C - D;}),
        
        four_terms_expr(u8"A - B + C⋅D",[](double A,double B,double C,double D){return A - B + C*D;}),
        
        four_terms_expr(u8"    A       \n- ────── - D\n  -B + C    ",[](double A,double B,double C,double D){return -A/(-B + C) - D;}),
        
        four_terms_expr(u8"-A - B⋅C⋅D",[](double A,double B,double C,double D){return -A - B*C*D;}),
        
        four_terms_expr(u8"      B  \nA + ─────\n    C - D",[](double A,double B,double C,double D){return A + B/(C - D);}),
        
        four_terms_expr(u8"-D⋅(A + B) \n───────────\n     C     ",[](double A,double B,double C,double D){return -D*(A + B)/C;}),
        
        four_terms_expr(u8"  -A    \n────────\n-B + C⋅D",[](double A,double B,double C,double D){return -A/(-B + C*D);}),
        
        four_terms_expr(u8"     B⋅C\n-A + ───\n      D ",[](double A,double B,double C,double D){return -A + B*C/D;}),
        
        four_terms_expr(u8"-C⋅(A - B) + D",[](double A,double B,double C,double D){return -C*(A - B) + D;}),
        
        four_terms_expr(u8"   -A     \n──────────\nB⋅(-C + D)",[](double A,double B,double C,double D){return -A/(B*(-C + D));}),
        
        four_terms_expr(u8"A⋅B + C - D",[](double A,double B,double C,double D){return A*B + C - D;}),
        
        four_terms_expr(u8"   A     \n- ─── + D\n  B⋅C    ",[](double A,double B,double C,double D){return -A/(B*C) + D;}),
        
        four_terms_expr(u8"A⋅B⋅(-C + D)",[](double A,double B,double C,double D){return A*B*(-C + D);}),
        
        four_terms_expr(u8"      B   \nA - ──────\n    -C - D",[](double A,double B,double C,double D){return A - B/(-C - D);}),
        
        four_terms_expr(u8"-A⋅D⋅(-B + C)",[](double A,double B,double C,double D){return -A*D*(-B + C);}),
        
        four_terms_expr(u8"A⋅(-B - C) + D",[](double A,double B,double C,double D){return A*(-B - C) + D;}),
        
        four_terms_expr(u8"  ⎛B    ⎞\nA⋅⎜─ - D⎟\n  ⎝C    ⎠",[](double A,double B,double C,double D){return A*(B/C - D);}),
        
        four_terms_expr(u8"-A⋅B - C⋅D",[](double A,double B,double C,double D){return -A*B - C*D;}),
        
        four_terms_expr(u8"-A⋅(-B - C - D)",[](double A,double B,double C,double D){return -A*(-B - C - D);}),
        
        four_terms_expr(u8"  -A   \n───────\nB + C⋅D",[](double A,double B,double C,double D){return -A/(B + C*D);}),
        
        four_terms_expr(u8"-(A - B) \n─────────\n   C⋅D   ",[](double A,double B,double C,double D){return -(A - B)/(C*D);}),
        
        four_terms_expr(u8" -A  \n─────\nB    \n─ - D\nC    ",[](double A,double B,double C,double D){return -A/(B/C - D);}),
        
    };
}
#endif