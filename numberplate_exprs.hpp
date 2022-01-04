
#ifndef NUMBERPLATE_EXPRS
#define NUMBERPLATE_EXPRS
#include<string>
#include<functional>
#include<array>
namespace numberplate{
    class four_terms_expr{
        std::string pretty_;
        std::string pretty_oneline_;
        std::function<double(double,double,double,double)> calc_;
        public:
        four_terms_expr(const char *pretty,const char *pretty_oneline,decltype(calc_) calc);
        std::string pretty() const;//変数部分がA,B,C,Dのまま
        std::string pretty(double,double,double,double) const;//変数部分を置換
        std::string pretty_oneline() const;//一行に収まるように出力
        std::string pretty_oneline(double,double,double,double) const;
        double operator()(double arg0,double arg1,double arg2,double arg3) const;
    };
    inline std::array<four_terms_expr,528> EXPRS={
    
        four_terms_expr(u8"A + B\n─────\nC - D",u8"(A + B)/(C - D)",[](double A,double B,double C,double D){return (A + B)/(C - D);}),
        
        four_terms_expr(u8"-A + B + C\n──────────\n    D     ",u8"(-A + B + C)/D",[](double A,double B,double C,double D){return (-A + B + C)/D;}),
        
        four_terms_expr(u8"C⋅D⋅(-A - B)",u8"C*D*(-A - B)",[](double A,double B,double C,double D){return C*D*(-A - B);}),
        
        four_terms_expr(u8"    A    \n─────────\nB - C + D",u8"A/(B - C + D)",[](double A,double B,double C,double D){return A/(B - C + D);}),
        
        four_terms_expr(u8"-A - D⋅(B - C)",u8"-A - D*(B - C)",[](double A,double B,double C,double D){return -A - D*(B - C);}),
        
        four_terms_expr(u8"   -A     \n──────────\nB⋅(-C - D)",u8"-A/(B*(-C - D))",[](double A,double B,double C,double D){return -A/(B*(-C - D));}),
        
        four_terms_expr(u8"-A - B - C⋅D",u8"-A - B - C*D",[](double A,double B,double C,double D){return -A - B - C*D;}),
        
        four_terms_expr(u8"-A⋅B⋅(C - D)",u8"-A*B*(C - D)",[](double A,double B,double C,double D){return -A*B*(C - D);}),
        
        four_terms_expr(u8" -A   \n──────\n     C\n-B - ─\n     D",u8"-A/(-B - C/D)",[](double A,double B,double C,double D){return -A/(-B - C/D);}),
        
        four_terms_expr(u8"-A⋅B - C\n────────\n   D    ",u8"(-A*B - C)/D",[](double A,double B,double C,double D){return (-A*B - C)/D;}),
        
        four_terms_expr(u8"-A - B\n──────\nC - D ",u8"(-A - B)/(C - D)",[](double A,double B,double C,double D){return (-A - B)/(C - D);}),
        
        four_terms_expr(u8"  ⎛  A    ⎞\nD⋅⎜- ─ - C⎟\n  ⎝  B    ⎠",u8"D*(-A/B - C)",[](double A,double B,double C,double D){return D*(-A/B - C);}),
        
        four_terms_expr(u8"      C\nA⋅B - ─\n      D",u8"A*B - C/D",[](double A,double B,double C,double D){return A*B - C/D;}),
        
        four_terms_expr(u8"  -A   \n───────\n  B    \n- ─ + D\n  C    ",u8"-A/(-B/C + D)",[](double A,double B,double C,double D){return -A/(-B/C + D);}),
        
        four_terms_expr(u8"-A + B + C + D",u8"-A + B + C + D",[](double A,double B,double C,double D){return -A + B + C + D;}),
        
        four_terms_expr(u8"  A⋅C    \n- ─── - D\n   B     ",u8"-A*C/B - D",[](double A,double B,double C,double D){return -A*C/B - D;}),
        
        four_terms_expr(u8"-A - B\n──────\nC + D ",u8"(-A - B)/(C + D)",[](double A,double B,double C,double D){return (-A - B)/(C + D);}),
        
        four_terms_expr(u8"-A⋅B  \n──────\n-C + D",u8"-A*B/(-C + D)",[](double A,double B,double C,double D){return -A*B/(-C + D);}),
        
        four_terms_expr(u8"D⋅(A - B + C)",u8"D*(A - B + C)",[](double A,double B,double C,double D){return D*(A - B + C);}),
        
        four_terms_expr(u8"(-A - B)⋅(C - D)",u8"(-A - B)*(C - D)",[](double A,double B,double C,double D){return (-A - B)*(C - D);}),
        
        four_terms_expr(u8"  -A   \n───────\n  B    \n- ─ - D\n  C    ",u8"-A/(-B/C - D)",[](double A,double B,double C,double D){return -A/(-B/C - D);}),
        
        four_terms_expr(u8"A + B \n──────\n-C + D",u8"(A + B)/(-C + D)",[](double A,double B,double C,double D){return (A + B)/(-C + D);}),
        
        four_terms_expr(u8"A        \n─ + C - D\nB        ",u8"A/B + C - D",[](double A,double B,double C,double D){return A/B + C - D;}),
        
        four_terms_expr(u8"  ⎛     B⎞\nD⋅⎜-A - ─⎟\n  ⎝     C⎠",u8"D*(-A - B/C)",[](double A,double B,double C,double D){return D*(-A - B/C);}),
        
        four_terms_expr(u8"-A⋅(-C - D) \n────────────\n     B      ",u8"-A*(-C - D)/B",[](double A,double B,double C,double D){return -A*(-C - D)/B;}),
        
        four_terms_expr(u8"C⋅(A - B) + D",u8"C*(A - B) + D",[](double A,double B,double C,double D){return C*(A - B) + D;}),
        
        four_terms_expr(u8"A⋅B    \n─── + D\n C     ",u8"A*B/C + D",[](double A,double B,double C,double D){return A*B/C + D;}),
        
        four_terms_expr(u8"       B   \n-A + ──────\n     -C + D",u8"-A + B/(-C + D)",[](double A,double B,double C,double D){return -A + B/(-C + D);}),
        
        four_terms_expr(u8"-A - B\n──────\n-C + D",u8"(-A - B)/(-C + D)",[](double A,double B,double C,double D){return (-A - B)/(-C + D);}),
        
        four_terms_expr(u8"         C\n-A + B - ─\n         D",u8"-A + B - C/D",[](double A,double B,double C,double D){return -A + B - C/D;}),
        
        four_terms_expr(u8"  ⎛    B⎞\nD⋅⎜A - ─⎟\n  ⎝    C⎠",u8"D*(A - B/C)",[](double A,double B,double C,double D){return D*(A - B/C);}),
        
        four_terms_expr(u8"-A + B⋅(-C + D)",u8"-A + B*(-C + D)",[](double A,double B,double C,double D){return -A + B*(-C + D);}),
        
        four_terms_expr(u8"-A + B⋅C + D",u8"-A + B*C + D",[](double A,double B,double C,double D){return -A + B*C + D;}),
        
        four_terms_expr(u8"-A + B\n──────\n-C - D",u8"(-A + B)/(-C - D)",[](double A,double B,double C,double D){return (-A + B)/(-C - D);}),
        
        four_terms_expr(u8"      B   \nA + ──────\n    -C - D",u8"A + B/(-C - D)",[](double A,double B,double C,double D){return A + B/(-C - D);}),
        
        four_terms_expr(u8"-A - B + C - D",u8"-A - B + C - D",[](double A,double B,double C,double D){return -A - B + C - D;}),
        
        four_terms_expr(u8"  ⎛A    ⎞\nD⋅⎜─ - C⎟\n  ⎝B    ⎠",u8"D*(A/B - C)",[](double A,double B,double C,double D){return D*(A/B - C);}),
        
        four_terms_expr(u8"     -B - C\n-A + ──────\n       D   ",u8"-A + (-B - C)/D",[](double A,double B,double C,double D){return -A + (-B - C)/D;}),
        
        four_terms_expr(u8"A - B + C - D",u8"A - B + C - D",[](double A,double B,double C,double D){return A - B + C - D;}),
        
        four_terms_expr(u8"-A⋅(-B - C⋅D)",u8"-A*(-B - C*D)",[](double A,double B,double C,double D){return -A*(-B - C*D);}),
        
        four_terms_expr(u8"D⋅(A - B - C)",u8"D*(A - B - C)",[](double A,double B,double C,double D){return D*(A - B - C);}),
        
        four_terms_expr(u8"A⋅(C - D)\n─────────\n    B    ",u8"A*(C - D)/B",[](double A,double B,double C,double D){return A*(C - D)/B;}),
        
        four_terms_expr(u8"A - B⋅(-C - D)",u8"A - B*(-C - D)",[](double A,double B,double C,double D){return A - B*(-C - D);}),
        
        four_terms_expr(u8"      B \n-A - ───\n     C⋅D",u8"-A - B/(C*D)",[](double A,double B,double C,double D){return -A - B/(C*D);}),
        
        four_terms_expr(u8"-A⋅D⋅(-B - C)",u8"-A*D*(-B - C)",[](double A,double B,double C,double D){return -A*D*(-B - C);}),
        
        four_terms_expr(u8"      B  \nA + ─────\n    C + D",u8"A + B/(C + D)",[](double A,double B,double C,double D){return A + B/(C + D);}),
        
        four_terms_expr(u8"(-A - B)⋅(C + D)",u8"(-A - B)*(C + D)",[](double A,double B,double C,double D){return (-A - B)*(C + D);}),
        
        four_terms_expr(u8"-A⋅B - C + D",u8"-A*B - C + D",[](double A,double B,double C,double D){return -A*B - C + D;}),
        
        four_terms_expr(u8"-A - B⋅C⋅D",u8"-A - B*C*D",[](double A,double B,double C,double D){return -A - B*C*D;}),
        
        four_terms_expr(u8"(A + B)⋅(-C + D)",u8"(A + B)*(-C + D)",[](double A,double B,double C,double D){return (A + B)*(-C + D);}),
        
        four_terms_expr(u8"-A + B - C\n──────────\n    D     ",u8"(-A + B - C)/D",[](double A,double B,double C,double D){return (-A + B - C)/D;}),
        
        four_terms_expr(u8"-A⋅(-B - C + D)",u8"-A*(-B - C + D)",[](double A,double B,double C,double D){return -A*(-B - C + D);}),
        
        four_terms_expr(u8"A⋅(B + C)\n─────────\n    D    ",u8"A*(B + C)/D",[](double A,double B,double C,double D){return A*(B + C)/D;}),
        
        four_terms_expr(u8"-A⋅B + C⋅D",u8"-A*B + C*D",[](double A,double B,double C,double D){return -A*B + C*D;}),
        
        four_terms_expr(u8"D⋅(-A⋅B - C)",u8"D*(-A*B - C)",[](double A,double B,double C,double D){return D*(-A*B - C);}),
        
        four_terms_expr(u8"       C\n-A⋅B - ─\n       D",u8"-A*B - C/D",[](double A,double B,double C,double D){return -A*B - C/D;}),
        
        four_terms_expr(u8"       B  \n-A + ─────\n     C - D",u8"-A + B/(C - D)",[](double A,double B,double C,double D){return -A + B/(C - D);}),
        
        four_terms_expr(u8"C⋅(A - B) - D",u8"C*(A - B) - D",[](double A,double B,double C,double D){return C*(A - B) - D;}),
        
        four_terms_expr(u8"A⋅(-B + C) + D",u8"A*(-B + C) + D",[](double A,double B,double C,double D){return A*(-B + C) + D;}),
        
        four_terms_expr(u8"   ⎛     C⎞\n-A⋅⎜-B + ─⎟\n   ⎝     D⎠",u8"-A*(-B + C/D)",[](double A,double B,double C,double D){return -A*(-B + C/D);}),
        
        four_terms_expr(u8"     B⋅C\n-A + ───\n      D ",u8"-A + B*C/D",[](double A,double B,double C,double D){return -A + B*C/D;}),
        
        four_terms_expr(u8"    A      \n- ───── + D\n  B + C    ",u8"-A/(B + C) + D",[](double A,double B,double C,double D){return -A/(B + C) + D;}),
        
        four_terms_expr(u8"     B + C\n-A + ─────\n       D  ",u8"-A + (B + C)/D",[](double A,double B,double C,double D){return -A + (B + C)/D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nD⋅(B + C)",u8"-A/(D*(B + C))",[](double A,double B,double C,double D){return -A/(D*(B + C));}),
        
        four_terms_expr(u8"A        \n─ + C + D\nB        ",u8"A/B + C + D",[](double A,double B,double C,double D){return A/B + C + D;}),
        
        four_terms_expr(u8"C⋅(-A + B) + D",u8"C*(-A + B) + D",[](double A,double B,double C,double D){return C*(-A + B) + D;}),
        
        four_terms_expr(u8"C⋅(A - B)\n─────────\n    D    ",u8"C*(A - B)/D",[](double A,double B,double C,double D){return C*(A - B)/D;}),
        
        four_terms_expr(u8"        C\nA - B + ─\n        D",u8"A - B + C/D",[](double A,double B,double C,double D){return A - B + C/D;}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B - C - D",u8"-A/(-B - C - D)",[](double A,double B,double C,double D){return -A/(-B - C - D);}),
        
        four_terms_expr(u8"-A⋅D⋅(B - C)",u8"-A*D*(B - C)",[](double A,double B,double C,double D){return -A*D*(B - C);}),
        
        four_terms_expr(u8"-A⋅C \n─────\n B⋅D ",u8"-A*C/(B*D)",[](double A,double B,double C,double D){return -A*C/(B*D);}),
        
        four_terms_expr(u8"-A⋅(C + D) \n───────────\n     B     ",u8"-A*(C + D)/B",[](double A,double B,double C,double D){return -A*(C + D)/B;}),
        
        four_terms_expr(u8"     B    \n-A - ─ - D\n     C    ",u8"-A - B/C - D",[](double A,double B,double C,double D){return -A - B/C - D;}),
        
        four_terms_expr(u8"A⋅(B - C) + D",u8"A*(B - C) + D",[](double A,double B,double C,double D){return A*(B - C) + D;}),
        
        four_terms_expr(u8"-A⋅D \n─────\nB + C",u8"-A*D/(B + C)",[](double A,double B,double C,double D){return -A*D/(B + C);}),
        
        four_terms_expr(u8"A - B \n──────\n-C - D",u8"(A - B)/(-C - D)",[](double A,double B,double C,double D){return (A - B)/(-C - D);}),
        
        four_terms_expr(u8"   ⎛     C⎞\n-A⋅⎜-B - ─⎟\n   ⎝     D⎠",u8"-A*(-B - C/D)",[](double A,double B,double C,double D){return -A*(-B - C/D);}),
        
        four_terms_expr(u8" A⋅B \n─────\nC - D",u8"A*B/(C - D)",[](double A,double B,double C,double D){return A*B/(C - D);}),
        
        four_terms_expr(u8"A + B - C\n─────────\n    D    ",u8"(A + B - C)/D",[](double A,double B,double C,double D){return (A + B - C)/D;}),
        
        four_terms_expr(u8"-A⋅B - C - D",u8"-A*B - C - D",[](double A,double B,double C,double D){return -A*B - C - D;}),
        
        four_terms_expr(u8"A - B - C⋅D",u8"A - B - C*D",[](double A,double B,double C,double D){return A - B - C*D;}),
        
        four_terms_expr(u8"A⋅B\n───\nC⋅D",u8"A*B/(C*D)",[](double A,double B,double C,double D){return A*B/(C*D);}),
        
        four_terms_expr(u8"    A       \n- ────── + D\n  -B + C    ",u8"-A/(-B + C) + D",[](double A,double B,double C,double D){return -A/(-B + C) + D;}),
        
        four_terms_expr(u8"A - D⋅(B + C)",u8"A - D*(B + C)",[](double A,double B,double C,double D){return A - D*(B + C);}),
        
        four_terms_expr(u8"  A  \n─────\nB    \n─ + D\nC    ",u8"A/(B/C + D)",[](double A,double B,double C,double D){return A/(B/C + D);}),
        
        four_terms_expr(u8"   -A    \n─────────\nB⋅(C + D)",u8"-A/(B*(C + D))",[](double A,double B,double C,double D){return -A/(B*(C + D));}),
        
        four_terms_expr(u8"-C⋅(-A - B) + D",u8"-C*(-A - B) + D",[](double A,double B,double C,double D){return -C*(-A - B) + D;}),
        
        four_terms_expr(u8"A⋅(-B + C) - D",u8"A*(-B + C) - D",[](double A,double B,double C,double D){return A*(-B + C) - D;}),
        
        four_terms_expr(u8"    A      \n- ───── - D\n  B + C    ",u8"-A/(B + C) - D",[](double A,double B,double C,double D){return -A/(B + C) - D;}),
        
        four_terms_expr(u8"-A - B + C\n──────────\n    D     ",u8"(-A - B + C)/D",[](double A,double B,double C,double D){return (-A - B + C)/D;}),
        
        four_terms_expr(u8"    A     \n──────────\nB⋅(-C - D)",u8"A/(B*(-C - D))",[](double A,double B,double C,double D){return A/(B*(-C - D));}),
        
        four_terms_expr(u8"         C\n-A + B + ─\n         D",u8"-A + B + C/D",[](double A,double B,double C,double D){return -A + B + C/D;}),
        
        four_terms_expr(u8"-(A + B) \n─────────\n   C⋅D   ",u8"-(A + B)/(C*D)",[](double A,double B,double C,double D){return -(A + B)/(C*D);}),
        
        four_terms_expr(u8"C⋅(-A + B) - D",u8"C*(-A + B) - D",[](double A,double B,double C,double D){return C*(-A + B) - D;}),
        
        four_terms_expr(u8"    -B + C\nA + ──────\n      D   ",u8"A + (-B + C)/D",[](double A,double B,double C,double D){return A + (-B + C)/D;}),
        
        four_terms_expr(u8"-A - B - C - D",u8"-A - B - C - D",[](double A,double B,double C,double D){return -A - B - C - D;}),
        
        four_terms_expr(u8"   -A     \n──────────\nD⋅(-B - C)",u8"-A/(D*(-B - C))",[](double A,double B,double C,double D){return -A/(D*(-B - C));}),
        
        four_terms_expr(u8"A⋅(B - C) - D",u8"A*(B - C) - D",[](double A,double B,double C,double D){return A*(B - C) - D;}),
        
        four_terms_expr(u8"-A⋅(B⋅C + D)",u8"-A*(B*C + D)",[](double A,double B,double C,double D){return -A*(B*C + D);}),
        
        four_terms_expr(u8"-A⋅(B + C⋅D)",u8"-A*(B + C*D)",[](double A,double B,double C,double D){return -A*(B + C*D);}),
        
        four_terms_expr(u8" A⋅D  \n──────\n-B + C",u8"A*D/(-B + C)",[](double A,double B,double C,double D){return A*D/(-B + C);}),
        
        four_terms_expr(u8"-A + B - C⋅D",u8"-A + B - C*D",[](double A,double B,double C,double D){return -A + B - C*D;}),
        
        four_terms_expr(u8"-(-A - B) \n──────────\n   C⋅D    ",u8"-(-A - B)/(C*D)",[](double A,double B,double C,double D){return -(-A - B)/(C*D);}),
        
        four_terms_expr(u8"-A + B\n──────\n C⋅D  ",u8"(-A + B)/(C*D)",[](double A,double B,double C,double D){return (-A + B)/(C*D);}),
        
        four_terms_expr(u8"-A⋅D  \n──────\n-B - C",u8"-A*D/(-B - C)",[](double A,double B,double C,double D){return -A*D/(-B - C);}),
        
        four_terms_expr(u8"     B⋅D\n-A + ───\n      C ",u8"-A + B*D/C",[](double A,double B,double C,double D){return -A + B*D/C;}),
        
        four_terms_expr(u8"  A  \n─────\n    C\nB + ─\n    D",u8"A/(B + C/D)",[](double A,double B,double C,double D){return A/(B + C/D);}),
        
        four_terms_expr(u8"    A    \n─────────\nB + C + D",u8"A/(B + C + D)",[](double A,double B,double C,double D){return A/(B + C + D);}),
        
        four_terms_expr(u8"    A       \n- ────── - D\n  -B + C    ",u8"-A/(-B + C) - D",[](double A,double B,double C,double D){return -A/(-B + C) - D;}),
        
        four_terms_expr(u8"A⋅B - C\n───────\n   D   ",u8"(A*B - C)/D",[](double A,double B,double C,double D){return (A*B - C)/D;}),
        
        four_terms_expr(u8"C⋅D⋅(A - B)",u8"C*D*(A - B)",[](double A,double B,double C,double D){return C*D*(A - B);}),
        
        four_terms_expr(u8"-C⋅(-A - B) - D",u8"-C*(-A - B) - D",[](double A,double B,double C,double D){return -C*(-A - B) - D;}),
        
        four_terms_expr(u8"-A + D⋅(B - C)",u8"-A + D*(B - C)",[](double A,double B,double C,double D){return -A + D*(B - C);}),
        
        four_terms_expr(u8"-A - B + C⋅D",u8"-A - B + C*D",[](double A,double B,double C,double D){return -A - B + C*D;}),
        
        four_terms_expr(u8"A⋅C    \n─── + D\n B     ",u8"A*C/B + D",[](double A,double B,double C,double D){return A*C/B + D;}),
        
        four_terms_expr(u8"-C⋅(-A + B) \n────────────\n     D      ",u8"-C*(-A + B)/D",[](double A,double B,double C,double D){return -C*(-A + B)/D;}),
        
        four_terms_expr(u8"A - B\n─────\nC - D",u8"(A - B)/(C - D)",[](double A,double B,double C,double D){return (A - B)/(C - D);}),
        
        four_terms_expr(u8"     B    \n-A + ─ - D\n     C    ",u8"-A + B/C - D",[](double A,double B,double C,double D){return -A + B/C - D;}),
        
        four_terms_expr(u8"D⋅(A + B - C)",u8"D*(A + B - C)",[](double A,double B,double C,double D){return D*(A + B - C);}),
        
        four_terms_expr(u8"-A⋅B - C⋅D",u8"-A*B - C*D",[](double A,double B,double C,double D){return -A*B - C*D;}),
        
        four_terms_expr(u8"-A⋅(-B + C) \n────────────\n     D      ",u8"-A*(-B + C)/D",[](double A,double B,double C,double D){return -A*(-B + C)/D;}),
        
        four_terms_expr(u8"-D⋅(A + B) \n───────────\n     C     ",u8"-D*(A + B)/C",[](double A,double B,double C,double D){return -D*(A + B)/C;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB + C - D",u8"-A/(B + C - D)",[](double A,double B,double C,double D){return -A/(B + C - D);}),
        
        four_terms_expr(u8"-A⋅B \n─────\nC + D",u8"-A*B/(C + D)",[](double A,double B,double C,double D){return -A*B/(C + D);}),
        
        four_terms_expr(u8"A⋅B⋅(C - D)",u8"A*B*(C - D)",[](double A,double B,double C,double D){return A*B*(C - D);}),
        
        four_terms_expr(u8"A⋅(B + C + D)",u8"A*(B + C + D)",[](double A,double B,double C,double D){return A*(B + C + D);}),
        
        four_terms_expr(u8"A - B⋅(C - D)",u8"A - B*(C - D)",[](double A,double B,double C,double D){return A - B*(C - D);}),
        
        four_terms_expr(u8"  ⎛  B    ⎞\nA⋅⎜- ─ + D⎟\n  ⎝  C    ⎠",u8"A*(-B/C + D)",[](double A,double B,double C,double D){return A*(-B/C + D);}),
        
        four_terms_expr(u8"  -A   \n───────\nB + C⋅D",u8"-A/(B + C*D)",[](double A,double B,double C,double D){return -A/(B + C*D);}),
        
        four_terms_expr(u8"A - D⋅(-B - C)",u8"A - D*(-B - C)",[](double A,double B,double C,double D){return A - D*(-B - C);}),
        
        four_terms_expr(u8"(-A + B)⋅(-C - D)",u8"(-A + B)*(-C - D)",[](double A,double B,double C,double D){return (-A + B)*(-C - D);}),
        
        four_terms_expr(u8"C⋅(-A - B) + D",u8"C*(-A - B) + D",[](double A,double B,double C,double D){return C*(-A - B) + D;}),
        
        four_terms_expr(u8" A⋅B  \n──────\n-C + D",u8"A*B/(-C + D)",[](double A,double B,double C,double D){return A*B/(-C + D);}),
        
        four_terms_expr(u8"    B    \nA - ─ - D\n    C    ",u8"A - B/C - D",[](double A,double B,double C,double D){return A - B/C - D;}),
        
        four_terms_expr(u8"A - B⋅(C + D)",u8"A - B*(C + D)",[](double A,double B,double C,double D){return A - B*(C + D);}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B + C + D",u8"-A/(-B + C + D)",[](double A,double B,double C,double D){return -A/(-B + C + D);}),
        
        four_terms_expr(u8"-A⋅D⋅(B + C)",u8"-A*D*(B + C)",[](double A,double B,double C,double D){return -A*D*(B + C);}),
        
        four_terms_expr(u8"A - B + C + D",u8"A - B + C + D",[](double A,double B,double C,double D){return A - B + C + D;}),
        
        four_terms_expr(u8"A - B - C + D",u8"A - B - C + D",[](double A,double B,double C,double D){return A - B - C + D;}),
        
        four_terms_expr(u8"     B - C\n-A - ─────\n       D  ",u8"-A - (B - C)/D",[](double A,double B,double C,double D){return -A - (B - C)/D;}),
        
        four_terms_expr(u8"A⋅C    \n─── - D\n B     ",u8"A*C/B - D",[](double A,double B,double C,double D){return A*C/B - D;}),
        
        four_terms_expr(u8"   ⎛    C⎞\n-A⋅⎜B - ─⎟\n   ⎝    D⎠",u8"-A*(B - C/D)",[](double A,double B,double C,double D){return -A*(B - C/D);}),
        
        four_terms_expr(u8"-A⋅B + C + D",u8"-A*B + C + D",[](double A,double B,double C,double D){return -A*B + C + D;}),
        
        four_terms_expr(u8"A + B + C\n─────────\n    D    ",u8"(A + B + C)/D",[](double A,double B,double C,double D){return (A + B + C)/D;}),
        
        four_terms_expr(u8"    A    \n─────────\nD⋅(B - C)",u8"A/(D*(B - C))",[](double A,double B,double C,double D){return A/(D*(B - C));}),
        
        four_terms_expr(u8"     B \nA - ───\n    C⋅D",u8"A - B/(C*D)",[](double A,double B,double C,double D){return A - B/(C*D);}),
        
        four_terms_expr(u8"A⋅(C + D)\n─────────\n    B    ",u8"A*(C + D)/B",[](double A,double B,double C,double D){return A*(C + D)/B;}),
        
        four_terms_expr(u8"   A    \n────────\n-B⋅C + D",u8"A/(-B*C + D)",[](double A,double B,double C,double D){return A/(-B*C + D);}),
        
        four_terms_expr(u8"    B + C\nA - ─────\n      D  ",u8"A - (B + C)/D",[](double A,double B,double C,double D){return A - (B + C)/D;}),
        
        four_terms_expr(u8"-A⋅D \n─────\n B⋅C ",u8"-A*D/(B*C)",[](double A,double B,double C,double D){return -A*D/(B*C);}),
        
        four_terms_expr(u8"    B    \nA + ─ + D\n    C    ",u8"A + B/C + D",[](double A,double B,double C,double D){return A + B/C + D;}),
        
        four_terms_expr(u8"    A + B\nD - ─────\n      C  ",u8"D - (A + B)/C",[](double A,double B,double C,double D){return D - (A + B)/C;}),
        
        four_terms_expr(u8"A + B⋅(-C - D)",u8"A + B*(-C - D)",[](double A,double B,double C,double D){return A + B*(-C - D);}),
        
        four_terms_expr(u8"    B\nA - ─\n    C\n─────\n  D  ",u8"(A - B/C)/D",[](double A,double B,double C,double D){return (A - B/C)/D;}),
        
        four_terms_expr(u8"-A⋅B⋅C⋅D",u8"-A*B*C*D",[](double A,double B,double C,double D){return -A*B*C*D;}),
        
        four_terms_expr(u8"    A    \n─────────\nB - C - D",u8"A/(B - C - D)",[](double A,double B,double C,double D){return A/(B - C - D);}),
        
        four_terms_expr(u8" A⋅D \n─────\nB - C",u8"A*D/(B - C)",[](double A,double B,double C,double D){return A*D/(B - C);}),
        
        four_terms_expr(u8"    A      \n- ───── + D\n  B - C    ",u8"-A/(B - C) + D",[](double A,double B,double C,double D){return -A/(B - C) + D;}),
        
        four_terms_expr(u8"A⋅B - C + D",u8"A*B - C + D",[](double A,double B,double C,double D){return A*B - C + D;}),
        
        four_terms_expr(u8"-A + B - C + D",u8"-A + B - C + D",[](double A,double B,double C,double D){return -A + B - C + D;}),
        
        four_terms_expr(u8" -A  \n─────\nB    \n─ - D\nC    ",u8"-A/(B/C - D)",[](double A,double B,double C,double D){return -A/(B/C - D);}),
        
        four_terms_expr(u8"-A - D⋅(-B + C)",u8"-A - D*(-B + C)",[](double A,double B,double C,double D){return -A - D*(-B + C);}),
        
        four_terms_expr(u8"-A⋅(-B⋅C + D)",u8"-A*(-B*C + D)",[](double A,double B,double C,double D){return -A*(-B*C + D);}),
        
        four_terms_expr(u8"-A⋅(B - C⋅D)",u8"-A*(B - C*D)",[](double A,double B,double C,double D){return -A*(B - C*D);}),
        
        four_terms_expr(u8"-A⋅(B⋅C - D)",u8"-A*(B*C - D)",[](double A,double B,double C,double D){return -A*(B*C - D);}),
        
        four_terms_expr(u8"-A - B⋅C - D",u8"-A - B*C - D",[](double A,double B,double C,double D){return -A - B*C - D;}),
        
        four_terms_expr(u8"    A    \n─────────\nB⋅(C + D)",u8"A/(B*(C + D))",[](double A,double B,double C,double D){return A/(B*(C + D));}),
        
        four_terms_expr(u8"C⋅(-A - B) - D",u8"C*(-A - B) - D",[](double A,double B,double C,double D){return C*(-A - B) - D;}),
        
        four_terms_expr(u8"-A⋅(B + C - D)",u8"-A*(B + C - D)",[](double A,double B,double C,double D){return -A*(B + C - D);}),
        
        four_terms_expr(u8"  A      \n───── + D\nB + C    ",u8"A/(B + C) + D",[](double A,double B,double C,double D){return A/(B + C) + D;}),
        
        four_terms_expr(u8"A⋅(-B + C + D)",u8"A*(-B + C + D)",[](double A,double B,double C,double D){return A*(-B + C + D);}),
        
        four_terms_expr(u8"-A⋅(B - C - D)",u8"-A*(B - C - D)",[](double A,double B,double C,double D){return -A*(B - C - D);}),
        
        four_terms_expr(u8"(-A + B)⋅(C + D)",u8"(-A + B)*(C + D)",[](double A,double B,double C,double D){return (-A + B)*(C + D);}),
        
        four_terms_expr(u8"A + B\n─────\nC + D",u8"(A + B)/(C + D)",[](double A,double B,double C,double D){return (A + B)/(C + D);}),
        
        four_terms_expr(u8"-A⋅B + C - D",u8"-A*B + C - D",[](double A,double B,double C,double D){return -A*B + C - D;}),
        
        four_terms_expr(u8"   ⎛    C⎞\n-A⋅⎜B + ─⎟\n   ⎝    D⎠",u8"-A*(B + C/D)",[](double A,double B,double C,double D){return -A*(B + C/D);}),
        
        four_terms_expr(u8" -A   \n──────\n     C\n-B + ─\n     D",u8"-A/(-B + C/D)",[](double A,double B,double C,double D){return -A/(-B + C/D);}),
        
        four_terms_expr(u8"     B \nA + ───\n    C⋅D",u8"A + B/(C*D)",[](double A,double B,double C,double D){return A + B/(C*D);}),
        
        four_terms_expr(u8"-A + B⋅C⋅D",u8"-A + B*C*D",[](double A,double B,double C,double D){return -A + B*C*D;}),
        
        four_terms_expr(u8"     A + B\n-D - ─────\n       C  ",u8"-D - (A + B)/C",[](double A,double B,double C,double D){return -D - (A + B)/C;}),
        
        four_terms_expr(u8"A⋅B⋅C + D",u8"A*B*C + D",[](double A,double B,double C,double D){return A*B*C + D;}),
        
        four_terms_expr(u8"A⋅B - C - D",u8"A*B - C - D",[](double A,double B,double C,double D){return A*B - C - D;}),
        
        four_terms_expr(u8"    A      \n- ───── - D\n  B - C    ",u8"-A/(B - C) - D",[](double A,double B,double C,double D){return -A/(B - C) - D;}),
        
        four_terms_expr(u8"A - B + C⋅D",u8"A - B + C*D",[](double A,double B,double C,double D){return A - B + C*D;}),
        
        four_terms_expr(u8"    B\nA + ─\n    C\n─────\n  D  ",u8"(A + B/C)/D",[](double A,double B,double C,double D){return (A + B/C)/D;}),
        
        four_terms_expr(u8"       C\n-A⋅B + ─\n       D",u8"-A*B + C/D",[](double A,double B,double C,double D){return -A*B + C/D;}),
        
        four_terms_expr(u8"-A - B⋅C\n────────\n   D    ",u8"(-A - B*C)/D",[](double A,double B,double C,double D){return (-A - B*C)/D;}),
        
        four_terms_expr(u8"  A       \n────── + D\n-B + C    ",u8"A/(-B + C) + D",[](double A,double B,double C,double D){return A/(-B + C) + D;}),
        
        four_terms_expr(u8"    B    \nA + ─ - D\n    C    ",u8"A + B/C - D",[](double A,double B,double C,double D){return A + B/C - D;}),
        
        four_terms_expr(u8"A + D⋅(B + C)",u8"A + D*(B + C)",[](double A,double B,double C,double D){return A + D*(B + C);}),
        
        four_terms_expr(u8"-A⋅(B - C + D)",u8"-A*(B - C + D)",[](double A,double B,double C,double D){return -A*(B - C + D);}),
        
        four_terms_expr(u8"D⋅(A + B + C)",u8"D*(A + B + C)",[](double A,double B,double C,double D){return D*(A + B + C);}),
        
        four_terms_expr(u8"  A      \n───── - D\nB + C    ",u8"A/(B + C) - D",[](double A,double B,double C,double D){return A/(B + C) - D;}),
        
        four_terms_expr(u8"      B   \nA - ──────\n    -C + D",u8"A - B/(-C + D)",[](double A,double B,double C,double D){return A - B/(-C + D);}),
        
        four_terms_expr(u8"  ⎛  B    ⎞\nA⋅⎜- ─ - D⎟\n  ⎝  C    ⎠",u8"A*(-B/C - D)",[](double A,double B,double C,double D){return A*(-B/C - D);}),
        
        four_terms_expr(u8"A - B⋅C + D",u8"A - B*C + D",[](double A,double B,double C,double D){return A - B*C + D;}),
        
        four_terms_expr(u8"A - B⋅(-C + D)",u8"A - B*(-C + D)",[](double A,double B,double C,double D){return A - B*(-C + D);}),
        
        four_terms_expr(u8"   A   \n───────\nB⋅C + D",u8"A/(B*C + D)",[](double A,double B,double C,double D){return A/(B*C + D);}),
        
        four_terms_expr(u8"    B⋅C\nA - ───\n     D ",u8"A - B*C/D",[](double A,double B,double C,double D){return A - B*C/D;}),
        
        four_terms_expr(u8"C⋅(-A + B)\n──────────\n    D     ",u8"C*(-A + B)/D",[](double A,double B,double C,double D){return C*(-A + B)/D;}),
        
        four_terms_expr(u8"-A⋅B⋅C \n───────\n   D   ",u8"-A*B*C/D",[](double A,double B,double C,double D){return -A*B*C/D;}),
        
        four_terms_expr(u8"    A - B\nD - ─────\n      C  ",u8"D - (A - B)/C",[](double A,double B,double C,double D){return D - (A - B)/C;}),
        
        four_terms_expr(u8"    -B - C\nA - ──────\n      D   ",u8"A - (-B - C)/D",[](double A,double B,double C,double D){return A - (-B - C)/D;}),
        
        four_terms_expr(u8"-A⋅(-B - C) \n────────────\n     D      ",u8"-A*(-B - C)/D",[](double A,double B,double C,double D){return -A*(-B - C)/D;}),
        
        four_terms_expr(u8"A⋅B⋅(-C + D)",u8"A*B*(-C + D)",[](double A,double B,double C,double D){return A*B*(-C + D);}),
        
        four_terms_expr(u8"   A   \n───────\nB⋅C - D",u8"A/(B*C - D)",[](double A,double B,double C,double D){return A/(B*C - D);}),
        
        four_terms_expr(u8"-A + B + C⋅D",u8"-A + B + C*D",[](double A,double B,double C,double D){return -A + B + C*D;}),
        
        four_terms_expr(u8"  A        \n- ─ - C + D\n  B        ",u8"-A/B - C + D",[](double A,double B,double C,double D){return -A/B - C + D;}),
        
        four_terms_expr(u8"-(A - B) \n─────────\n   C⋅D   ",u8"-(A - B)/(C*D)",[](double A,double B,double C,double D){return -(A - B)/(C*D);}),
        
        four_terms_expr(u8"-D⋅(-A + B) \n────────────\n     C      ",u8"-D*(-A + B)/C",[](double A,double B,double C,double D){return -D*(-A + B)/C;}),
        
        four_terms_expr(u8"A⋅B⋅C - D",u8"A*B*C - D",[](double A,double B,double C,double D){return A*B*C - D;}),
        
        four_terms_expr(u8"-A - B - C\n──────────\n    D     ",u8"(-A - B - C)/D",[](double A,double B,double C,double D){return (-A - B - C)/D;}),
        
        four_terms_expr(u8"    A       \n- ────── + D\n  -B - C    ",u8"-A/(-B - C) + D",[](double A,double B,double C,double D){return -A/(-B - C) + D;}),
        
        four_terms_expr(u8"  ⎛B    ⎞\nA⋅⎜─ + D⎟\n  ⎝C    ⎠",u8"A*(B/C + D)",[](double A,double B,double C,double D){return A*(B/C + D);}),
        
        four_terms_expr(u8"  A   C\n- ─ - ─\n  B   D",u8"-A/B - C/D",[](double A,double B,double C,double D){return -A/B - C/D;}),
        
        four_terms_expr(u8"-A⋅B  \n──────\n-C - D",u8"-A*B/(-C - D)",[](double A,double B,double C,double D){return -A*B/(-C - D);}),
        
        four_terms_expr(u8"      B  \nA - ─────\n    C - D",u8"A - B/(C - D)",[](double A,double B,double C,double D){return A - B/(C - D);}),
        
        four_terms_expr(u8"  A       \n────── - D\n-B + C    ",u8"A/(-B + C) - D",[](double A,double B,double C,double D){return A/(-B + C) - D;}),
        
        four_terms_expr(u8" A     \n─── + D\nB⋅C    ",u8"A/(B*C) + D",[](double A,double B,double C,double D){return A/(B*C) + D;}),
        
        four_terms_expr(u8"   A    \n────────\n-B + C⋅D",u8"A/(-B + C*D)",[](double A,double B,double C,double D){return A/(-B + C*D);}),
        
        four_terms_expr(u8"-A⋅(B - C) \n───────────\n     D     ",u8"-A*(B - C)/D",[](double A,double B,double C,double D){return -A*(B - C)/D;}),
        
        four_terms_expr(u8"A⋅C⋅D\n─────\n  B  ",u8"A*C*D/B",[](double A,double B,double C,double D){return A*C*D/B;}),
        
        four_terms_expr(u8" A⋅D  \n──────\n-B - C",u8"A*D/(-B - C)",[](double A,double B,double C,double D){return A*D/(-B - C);}),
        
        four_terms_expr(u8"  ⎛B    ⎞\nA⋅⎜─ - D⎟\n  ⎝C    ⎠",u8"A*(B/C - D)",[](double A,double B,double C,double D){return A*(B/C - D);}),
        
        four_terms_expr(u8"-A⋅(-B + C - D)",u8"-A*(-B + C - D)",[](double A,double B,double C,double D){return -A*(-B + C - D);}),
        
        four_terms_expr(u8"-A⋅(-B⋅C - D)",u8"-A*(-B*C - D)",[](double A,double B,double C,double D){return -A*(-B*C - D);}),
        
        four_terms_expr(u8"     A - B\n-D - ─────\n       C  ",u8"-D - (A - B)/C",[](double A,double B,double C,double D){return -D - (A - B)/C;}),
        
        four_terms_expr(u8"      C\nA⋅B + ─\n      D",u8"A*B + C/D",[](double A,double B,double C,double D){return A*B + C/D;}),
        
        four_terms_expr(u8"(A - B)⋅(C - D)",u8"(A - B)*(C - D)",[](double A,double B,double C,double D){return (A - B)*(C - D);}),
        
        four_terms_expr(u8"  ⎛    B⎞\nD⋅⎜A + ─⎟\n  ⎝    C⎠",u8"D*(A + B/C)",[](double A,double B,double C,double D){return D*(A + B/C);}),
        
        four_terms_expr(u8"A - B⋅C - D",u8"A - B*C - D",[](double A,double B,double C,double D){return A - B*C - D;}),
        
        four_terms_expr(u8"-C⋅D⋅(A + B)",u8"-C*D*(A + B)",[](double A,double B,double C,double D){return -C*D*(A + B);}),
        
        four_terms_expr(u8"  A        \n- ─ - C - D\n  B        ",u8"-A/B - C - D",[](double A,double B,double C,double D){return -A/B - C - D;}),
        
        four_terms_expr(u8"D⋅(-A - B⋅C)",u8"D*(-A - B*C)",[](double A,double B,double C,double D){return D*(-A - B*C);}),
        
        four_terms_expr(u8"A + B⋅(C - D)",u8"A + B*(C - D)",[](double A,double B,double C,double D){return A + B*(C - D);}),
        
        four_terms_expr(u8"A + B - C - D",u8"A + B - C - D",[](double A,double B,double C,double D){return A + B - C - D;}),
        
        four_terms_expr(u8"-A⋅B⋅(-C - D)",u8"-A*B*(-C - D)",[](double A,double B,double C,double D){return -A*B*(-C - D);}),
        
        four_terms_expr(u8"A⋅C\n───\nB⋅D",u8"A*C/(B*D)",[](double A,double B,double C,double D){return A*C/(B*D);}),
        
        four_terms_expr(u8"D⋅(A + B)\n─────────\n    C    ",u8"D*(A + B)/C",[](double A,double B,double C,double D){return D*(A + B)/C;}),
        
        four_terms_expr(u8"(A + B)⋅(C + D)",u8"(A + B)*(C + D)",[](double A,double B,double C,double D){return (A + B)*(C + D);}),
        
        four_terms_expr(u8"-D⋅(A - B) \n───────────\n     C     ",u8"-D*(A - B)/C",[](double A,double B,double C,double D){return -D*(A - B)/C;}),
        
        four_terms_expr(u8"  ⎛  A    ⎞\nD⋅⎜- ─ + C⎟\n  ⎝  B    ⎠",u8"D*(-A/B + C)",[](double A,double B,double C,double D){return D*(-A/B + C);}),
        
        four_terms_expr(u8"A + D⋅(-B - C)",u8"A + D*(-B - C)",[](double A,double B,double C,double D){return A + D*(-B - C);}),
        
        four_terms_expr(u8"    -A - B\nD - ──────\n      C   ",u8"D - (-A - B)/C",[](double A,double B,double C,double D){return D - (-A - B)/C;}),
        
        four_terms_expr(u8"    A       \n- ────── - D\n  -B - C    ",u8"-A/(-B - C) - D",[](double A,double B,double C,double D){return -A/(-B - C) - D;}),
        
        four_terms_expr(u8"A⋅B - C⋅D",u8"A*B - C*D",[](double A,double B,double C,double D){return A*B - C*D;}),
        
        four_terms_expr(u8"-C⋅D⋅(-A - B)",u8"-C*D*(-A - B)",[](double A,double B,double C,double D){return -C*D*(-A - B);}),
        
        four_terms_expr(u8"-A - B - C + D",u8"-A - B - C + D",[](double A,double B,double C,double D){return -A - B - C + D;}),
        
        four_terms_expr(u8"    B⋅D\nA - ───\n     C ",u8"A - B*D/C",[](double A,double B,double C,double D){return A - B*D/C;}),
        
        four_terms_expr(u8" A     \n─── - D\nB⋅C    ",u8"A/(B*C) - D",[](double A,double B,double C,double D){return A/(B*C) - D;}),
        
        four_terms_expr(u8"C⋅D⋅(-A + B)",u8"C*D*(-A + B)",[](double A,double B,double C,double D){return C*D*(-A + B);}),
        
        four_terms_expr(u8"-A⋅(-B - C - D)",u8"-A*(-B - C - D)",[](double A,double B,double C,double D){return -A*(-B - C - D);}),
        
        four_terms_expr(u8"A + B⋅(C + D)",u8"A + B*(C + D)",[](double A,double B,double C,double D){return A + B*(C + D);}),
        
        four_terms_expr(u8"  -A   \n───────\nB - C⋅D",u8"-A/(B - C*D)",[](double A,double B,double C,double D){return -A/(B - C*D);}),
        
        four_terms_expr(u8"       B   \n-A - ──────\n     -C - D",u8"-A - B/(-C - D)",[](double A,double B,double C,double D){return -A - B/(-C - D);}),
        
        four_terms_expr(u8"A⋅D⋅(-B + C)",u8"A*D*(-B + C)",[](double A,double B,double C,double D){return A*D*(-B + C);}),
        
        four_terms_expr(u8"    A     \n──────────\n-B + C - D",u8"A/(-B + C - D)",[](double A,double B,double C,double D){return A/(-B + C - D);}),
        
        four_terms_expr(u8"     B - C\n-A + ─────\n       D  ",u8"-A + (B - C)/D",[](double A,double B,double C,double D){return -A + (B - C)/D;}),
        
        four_terms_expr(u8"D⋅(-A - B)\n──────────\n    C     ",u8"D*(-A - B)/C",[](double A,double B,double C,double D){return D*(-A - B)/C;}),
        
        four_terms_expr(u8"A⋅(-B + C⋅D)",u8"A*(-B + C*D)",[](double A,double B,double C,double D){return A*(-B + C*D);}),
        
        four_terms_expr(u8"-A⋅C⋅D \n───────\n   B   ",u8"-A*C*D/B",[](double A,double B,double C,double D){return -A*C*D/B;}),
        
        four_terms_expr(u8"    A - B\nD + ─────\n      C  ",u8"D + (A - B)/C",[](double A,double B,double C,double D){return D + (A - B)/C;}),
        
        four_terms_expr(u8"-A + B\n──────\nC - D ",u8"(-A + B)/(C - D)",[](double A,double B,double C,double D){return (-A + B)/(C - D);}),
        
        four_terms_expr(u8"A⋅B + C + D",u8"A*B + C + D",[](double A,double B,double C,double D){return A*B + C + D;}),
        
        four_terms_expr(u8"    A     \n──────────\nD⋅(-B + C)",u8"A/(D*(-B + C))",[](double A,double B,double C,double D){return A/(D*(-B + C));}),
        
        four_terms_expr(u8"    A     \n──────────\n-B - C + D",u8"A/(-B - C + D)",[](double A,double B,double C,double D){return A/(-B - C + D);}),
        
        four_terms_expr(u8"   -A    \n─────────\nB - C + D",u8"-A/(B - C + D)",[](double A,double B,double C,double D){return -A/(B - C + D);}),
        
        four_terms_expr(u8"   A    \n────────\n-B⋅C - D",u8"A/(-B*C - D)",[](double A,double B,double C,double D){return A/(-B*C - D);}),
        
        four_terms_expr(u8"D⋅(-A - B - C)",u8"D*(-A - B - C)",[](double A,double B,double C,double D){return D*(-A - B - C);}),
        
        four_terms_expr(u8"    A + B\nD + ─────\n      C  ",u8"D + (A + B)/C",[](double A,double B,double C,double D){return D + (A + B)/C;}),
        
        four_terms_expr(u8"A - D⋅(-B + C)",u8"A - D*(-B + C)",[](double A,double B,double C,double D){return A - D*(-B + C);}),
        
        four_terms_expr(u8"  A  \n─────\n    C\nB - ─\n    D",u8"A/(B - C/D)",[](double A,double B,double C,double D){return A/(B - C/D);}),
        
        four_terms_expr(u8"  A      \n───── + D\nB - C    ",u8"A/(B - C) + D",[](double A,double B,double C,double D){return A/(B - C) + D;}),
        
        four_terms_expr(u8"-A + B - C - D",u8"-A + B - C - D",[](double A,double B,double C,double D){return -A + B - C - D;}),
        
        four_terms_expr(u8"-A + D⋅(-B + C)",u8"-A + D*(-B + C)",[](double A,double B,double C,double D){return -A + D*(-B + C);}),
        
        four_terms_expr(u8"     -A - B\n-D - ──────\n       C   ",u8"-D - (-A - B)/C",[](double A,double B,double C,double D){return -D - (-A - B)/C;}),
        
        four_terms_expr(u8"-A + B⋅C - D",u8"-A + B*C - D",[](double A,double B,double C,double D){return -A + B*C - D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB⋅(C - D)",u8"-A/(B*(C - D))",[](double A,double B,double C,double D){return -A/(B*(C - D));}),
        
        four_terms_expr(u8"A - D⋅(B - C)",u8"A - D*(B - C)",[](double A,double B,double C,double D){return A - D*(B - C);}),
        
        four_terms_expr(u8"A⋅(-C - D)\n──────────\n    B     ",u8"A*(-C - D)/B",[](double A,double B,double C,double D){return A*(-C - D)/B;}),
        
        four_terms_expr(u8"-A⋅B⋅(C + D)",u8"-A*B*(C + D)",[](double A,double B,double C,double D){return -A*B*(C + D);}),
        
        four_terms_expr(u8"    -A + B\nD - ──────\n      C   ",u8"D - (-A + B)/C",[](double A,double B,double C,double D){return D - (-A + B)/C;}),
        
        four_terms_expr(u8"-A⋅(-B - C) + D",u8"-A*(-B - C) + D",[](double A,double B,double C,double D){return -A*(-B - C) + D;}),
        
        four_terms_expr(u8"-A + B\n──────\n-C + D",u8"(-A + B)/(-C + D)",[](double A,double B,double C,double D){return (-A + B)/(-C + D);}),
        
        four_terms_expr(u8"  A      \n- ─ - C⋅D\n  B      ",u8"-A/B - C*D",[](double A,double B,double C,double D){return -A/B - C*D;}),
        
        four_terms_expr(u8"     A - B\n-D + ─────\n       C  ",u8"-D + (A - B)/C",[](double A,double B,double C,double D){return -D + (A - B)/C;}),
        
        four_terms_expr(u8"  A   \n──────\n     C\n-B - ─\n     D",u8"A/(-B - C/D)",[](double A,double B,double C,double D){return A/(-B - C/D);}),
        
        four_terms_expr(u8"-A⋅(B + C) + D",u8"-A*(B + C) + D",[](double A,double B,double C,double D){return -A*(B + C) + D;}),
        
        four_terms_expr(u8"A⋅B + C - D",u8"A*B + C - D",[](double A,double B,double C,double D){return A*B + C - D;}),
        
        four_terms_expr(u8"   A     \n- ─── + D\n  B⋅C    ",u8"-A/(B*C) + D",[](double A,double B,double C,double D){return -A/(B*C) + D;}),
        
        four_terms_expr(u8"D⋅(A⋅B + C)",u8"D*(A*B + C)",[](double A,double B,double C,double D){return D*(A*B + C);}),
        
        four_terms_expr(u8"   A   \n───────\n  B    \n- ─ + D\n  C    ",u8"A/(-B/C + D)",[](double A,double B,double C,double D){return A/(-B/C + D);}),
        
        four_terms_expr(u8"-A + B⋅C\n────────\n   D    ",u8"(-A + B*C)/D",[](double A,double B,double C,double D){return (-A + B*C)/D;}),
        
        four_terms_expr(u8"-C⋅(A + B) + D",u8"-C*(A + B) + D",[](double A,double B,double C,double D){return -C*(A + B) + D;}),
        
        four_terms_expr(u8"     A + B\n-D + ─────\n       C  ",u8"-D + (A + B)/C",[](double A,double B,double C,double D){return -D + (A + B)/C;}),
        
        four_terms_expr(u8"A + B + C - D",u8"A + B + C - D",[](double A,double B,double C,double D){return A + B + C - D;}),
        
        four_terms_expr(u8"A    \n─ + C\nB    \n─────\n  D  ",u8"(A/B + C)/D",[](double A,double B,double C,double D){return (A/B + C)/D;}),
        
        four_terms_expr(u8"  A      \n───── - D\nB - C    ",u8"A/(B - C) - D",[](double A,double B,double C,double D){return A/(B - C) - D;}),
        
        four_terms_expr(u8"A - B\n─────\nC + D",u8"(A - B)/(C + D)",[](double A,double B,double C,double D){return (A - B)/(C + D);}),
        
        four_terms_expr(u8"-A⋅(B + C) \n───────────\n     D     ",u8"-A*(B + C)/D",[](double A,double B,double C,double D){return -A*(B + C)/D;}),
        
        four_terms_expr(u8"   A   \n───────\n  B    \n- ─ - D\n  C    ",u8"A/(-B/C - D)",[](double A,double B,double C,double D){return A/(-B/C - D);}),
        
        four_terms_expr(u8"-A⋅B⋅D \n───────\n   C   ",u8"-A*B*D/C",[](double A,double B,double C,double D){return -A*B*D/C;}),
        
        four_terms_expr(u8"     -B + C\n-A - ──────\n       D   ",u8"-A - (-B + C)/D",[](double A,double B,double C,double D){return -A - (-B + C)/D;}),
        
        four_terms_expr(u8"(-A - B)⋅(-C - D)",u8"(-A - B)*(-C - D)",[](double A,double B,double C,double D){return (-A - B)*(-C - D);}),
        
        four_terms_expr(u8"       B   \n-A + ──────\n     -C - D",u8"-A + B/(-C - D)",[](double A,double B,double C,double D){return -A + B/(-C - D);}),
        
        four_terms_expr(u8"A⋅B⋅C⋅D",u8"A*B*C*D",[](double A,double B,double C,double D){return A*B*C*D;}),
        
        four_terms_expr(u8"         C\n-A - B - ─\n         D",u8"-A - B - C/D",[](double A,double B,double C,double D){return -A - B - C/D;}),
        
        four_terms_expr(u8"      B   \nA + ──────\n    -C + D",u8"A + B/(-C + D)",[](double A,double B,double C,double D){return A + B/(-C + D);}),
        
        four_terms_expr(u8"A + B⋅C + D",u8"A + B*C + D",[](double A,double B,double C,double D){return A + B*C + D;}),
        
        four_terms_expr(u8"A + B⋅(-C + D)",u8"A + B*(-C + D)",[](double A,double B,double C,double D){return A + B*(-C + D);}),
        
        four_terms_expr(u8"     -A + B\n-D - ──────\n       C   ",u8"-D - (-A + B)/C",[](double A,double B,double C,double D){return -D - (-A + B)/C;}),
        
        four_terms_expr(u8"-A - B⋅(-C - D)",u8"-A - B*(-C - D)",[](double A,double B,double C,double D){return -A - B*(-C - D);}),
        
        four_terms_expr(u8"-A⋅B + C\n────────\n   D    ",u8"(-A*B + C)/D",[](double A,double B,double C,double D){return (-A*B + C)/D;}),
        
        four_terms_expr(u8"  A        \n- ─ + C + D\n  B        ",u8"-A/B + C + D",[](double A,double B,double C,double D){return -A/B + C + D;}),
        
        four_terms_expr(u8"-A⋅(-B - C) - D",u8"-A*(-B - C) - D",[](double A,double B,double C,double D){return -A*(-B - C) - D;}),
        
        four_terms_expr(u8"A - B \n──────\n-C + D",u8"(A - B)/(-C + D)",[](double A,double B,double C,double D){return (A - B)/(-C + D);}),
        
        four_terms_expr(u8"    -B - C\nA + ──────\n      D   ",u8"A + (-B - C)/D",[](double A,double B,double C,double D){return A + (-B - C)/D;}),
        
        four_terms_expr(u8"-A⋅(B + C) - D",u8"-A*(B + C) - D",[](double A,double B,double C,double D){return -A*(B + C) - D;}),
        
        four_terms_expr(u8"(A - B)⋅(-C + D)",u8"(A - B)*(-C + D)",[](double A,double B,double C,double D){return (A - B)*(-C + D);}),
        
        four_terms_expr(u8"   A     \n- ─── - D\n  B⋅C    ",u8"-A/(B*C) - D",[](double A,double B,double C,double D){return -A/(B*C) - D;}),
        
        four_terms_expr(u8"  A  \n─────\nB⋅C⋅D",u8"A/(B*C*D)",[](double A,double B,double C,double D){return A/(B*C*D);}),
        
        four_terms_expr(u8"-C⋅(A + B) - D",u8"-C*(A + B) - D",[](double A,double B,double C,double D){return -C*(A + B) - D;}),
        
        four_terms_expr(u8"A⋅(-B - C⋅D)",u8"A*(-B - C*D)",[](double A,double B,double C,double D){return A*(-B - C*D);}),
        
        four_terms_expr(u8"A - B⋅C⋅D",u8"A - B*C*D",[](double A,double B,double C,double D){return A - B*C*D;}),
        
        four_terms_expr(u8"A⋅(-B - C)\n──────────\n    D     ",u8"A*(-B - C)/D",[](double A,double B,double C,double D){return A*(-B - C)/D;}),
        
        four_terms_expr(u8"  A       \n────── + D\n-B - C    ",u8"A/(-B - C) + D",[](double A,double B,double C,double D){return A/(-B - C) + D;}),
        
        four_terms_expr(u8"-A - B\n──────\n-C - D",u8"(-A - B)/(-C - D)",[](double A,double B,double C,double D){return (-A - B)/(-C - D);}),
        
        four_terms_expr(u8" -A  \n─────\nB⋅C⋅D",u8"-A/(B*C*D)",[](double A,double B,double C,double D){return -A/(B*C*D);}),
        
        four_terms_expr(u8"      B  \nA + ─────\n    C - D",u8"A + B/(C - D)",[](double A,double B,double C,double D){return A + B/(C - D);}),
        
        four_terms_expr(u8"-A⋅(C - D) \n───────────\n     B     ",u8"-A*(C - D)/B",[](double A,double B,double C,double D){return -A*(C - D)/B;}),
        
        four_terms_expr(u8"A   C\n─ - ─\nB   D",u8"A/B - C/D",[](double A,double B,double C,double D){return A/B - C/D;}),
        
        four_terms_expr(u8"A⋅D\n───\nB⋅C",u8"A*D/(B*C)",[](double A,double B,double C,double D){return A*D/(B*C);}),
        
        four_terms_expr(u8"    B⋅C\nA + ───\n     D ",u8"A + B*C/D",[](double A,double B,double C,double D){return A + B*C/D;}),
        
        four_terms_expr(u8"    B + C\nA + ─────\n      D  ",u8"A + (B + C)/D",[](double A,double B,double C,double D){return A + (B + C)/D;}),
        
        four_terms_expr(u8"A⋅(-B - C + D)",u8"A*(-B - C + D)",[](double A,double B,double C,double D){return A*(-B - C + D);}),
        
        four_terms_expr(u8"A⋅D⋅(-B - C)",u8"A*D*(-B - C)",[](double A,double B,double C,double D){return A*D*(-B - C);}),
        
        four_terms_expr(u8"  ⎛     C⎞\nA⋅⎜-B + ─⎟\n  ⎝     D⎠",u8"A*(-B + C/D)",[](double A,double B,double C,double D){return A*(-B + C/D);}),
        
        four_terms_expr(u8"  A⋅B    \n- ─── + D\n   C     ",u8"-A*B/C + D",[](double A,double B,double C,double D){return -A*B/C + D;}),
        
        four_terms_expr(u8"  A        \n- ─ + C - D\n  B        ",u8"-A/B + C - D",[](double A,double B,double C,double D){return -A/B + C - D;}),
        
        four_terms_expr(u8" A⋅B  \n──────\n-C - D",u8"A*B/(-C - D)",[](double A,double B,double C,double D){return A*B/(-C - D);}),
        
        four_terms_expr(u8" -A  \n─────\nB    \n─ + D\nC    ",u8"-A/(B/C + D)",[](double A,double B,double C,double D){return -A/(B/C + D);}),
        
        four_terms_expr(u8"A⋅(B + C) + D",u8"A*(B + C) + D",[](double A,double B,double C,double D){return A*(B + C) + D;}),
        
        four_terms_expr(u8"D⋅(-A + B⋅C)",u8"D*(-A + B*C)",[](double A,double B,double C,double D){return D*(-A + B*C);}),
        
        four_terms_expr(u8"        C\nA + B - ─\n        D",u8"A + B - C/D",[](double A,double B,double C,double D){return A + B - C/D;}),
        
        four_terms_expr(u8"   -A     \n──────────\nB⋅(-C + D)",u8"-A/(B*(-C + D))",[](double A,double B,double C,double D){return -A/(B*(-C + D));}),
        
        four_terms_expr(u8"   A    \n────────\n-B - C⋅D",u8"A/(-B - C*D)",[](double A,double B,double C,double D){return A/(-B - C*D);}),
        
        four_terms_expr(u8"  ⎛A    ⎞\nD⋅⎜─ + C⎟\n  ⎝B    ⎠",u8"D*(A/B + C)",[](double A,double B,double C,double D){return D*(A/B + C);}),
        
        four_terms_expr(u8"    A     \n──────────\n-B - C - D",u8"A/(-B - C - D)",[](double A,double B,double C,double D){return A/(-B - C - D);}),
        
        four_terms_expr(u8"-A - D⋅(B + C)",u8"-A - D*(B + C)",[](double A,double B,double C,double D){return -A - D*(B + C);}),
        
        four_terms_expr(u8"A + B⋅C - D",u8"A + B*C - D",[](double A,double B,double C,double D){return A + B*C - D;}),
        
        four_terms_expr(u8"-(-A + B) \n──────────\n   C⋅D    ",u8"-(-A + B)/(C*D)",[](double A,double B,double C,double D){return -(-A + B)/(C*D);}),
        
        four_terms_expr(u8"A⋅B⋅C\n─────\n  D  ",u8"A*B*C/D",[](double A,double B,double C,double D){return A*B*C/D;}),
        
        four_terms_expr(u8"    A    \n─────────\nD⋅(B + C)",u8"A/(D*(B + C))",[](double A,double B,double C,double D){return A/(D*(B + C));}),
        
        four_terms_expr(u8"  ⎛     C⎞\nA⋅⎜-B - ─⎟\n  ⎝     D⎠",u8"A*(-B - C/D)",[](double A,double B,double C,double D){return A*(-B - C/D);}),
        
        four_terms_expr(u8"(-A + B)⋅(-C + D)",u8"(-A + B)*(-C + D)",[](double A,double B,double C,double D){return (-A + B)*(-C + D);}),
        
        four_terms_expr(u8"      B   \nA - ──────\n    -C - D",u8"A - B/(-C - D)",[](double A,double B,double C,double D){return A - B/(-C - D);}),
        
        four_terms_expr(u8"    -A - B\nD + ──────\n      C   ",u8"D + (-A - B)/C",[](double A,double B,double C,double D){return D + (-A - B)/C;}),
        
        four_terms_expr(u8"A⋅D⋅(B - C)",u8"A*D*(B - C)",[](double A,double B,double C,double D){return A*D*(B - C);}),
        
        four_terms_expr(u8"  A       \n────── - D\n-B - C    ",u8"A/(-B - C) - D",[](double A,double B,double C,double D){return A/(-B - C) - D;}),
        
        four_terms_expr(u8"     -B + C\n-A + ──────\n       D   ",u8"-A + (-B + C)/D",[](double A,double B,double C,double D){return -A + (-B + C)/D;}),
        
        four_terms_expr(u8"A⋅B + C⋅D",u8"A*B + C*D",[](double A,double B,double C,double D){return A*B + C*D;}),
        
        four_terms_expr(u8"A - B - C - D",u8"A - B - C - D",[](double A,double B,double C,double D){return A - B - C - D;}),
        
        four_terms_expr(u8"D⋅(-A⋅B + C)",u8"D*(-A*B + C)",[](double A,double B,double C,double D){return D*(-A*B + C);}),
        
        four_terms_expr(u8"-C⋅D⋅(A - B)",u8"-C*D*(A - B)",[](double A,double B,double C,double D){return -C*D*(A - B);}),
        
        four_terms_expr(u8" A⋅D \n─────\nB + C",u8"A*D/(B + C)",[](double A,double B,double C,double D){return A*D/(B + C);}),
        
        four_terms_expr(u8"A⋅B⋅(-C - D)",u8"A*B*(-C - D)",[](double A,double B,double C,double D){return A*B*(-C - D);}),
        
        four_terms_expr(u8"D⋅(A - B)\n─────────\n    C    ",u8"D*(A - B)/C",[](double A,double B,double C,double D){return D*(A - B)/C;}),
        
        four_terms_expr(u8" -A  \n─────\n    C\nB + ─\n    D",u8"-A/(B + C/D)",[](double A,double B,double C,double D){return -A/(B + C/D);}),
        
        four_terms_expr(u8"  A    \n- ─ + C\n  B    \n───────\n   D   ",u8"(-A/B + C)/D",[](double A,double B,double C,double D){return (-A/B + C)/D;}),
        
        four_terms_expr(u8"  A⋅B    \n- ─── - D\n   C     ",u8"-A*B/C - D",[](double A,double B,double C,double D){return -A*B/C - D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB + C + D",u8"-A/(B + C + D)",[](double A,double B,double C,double D){return -A/(B + C + D);}),
        
        four_terms_expr(u8"     B    \n-A - ─ + D\n     C    ",u8"-A - B/C + D",[](double A,double B,double C,double D){return -A - B/C + D;}),
        
        four_terms_expr(u8"A⋅(B + C) - D",u8"A*(B + C) - D",[](double A,double B,double C,double D){return A*(B + C) - D;}),
        
        four_terms_expr(u8"A - B⋅C\n───────\n   D   ",u8"(A - B*C)/D",[](double A,double B,double C,double D){return (A - B*C)/D;}),
        
        four_terms_expr(u8"       B  \n-A - ─────\n     C + D",u8"-A - B/(C + D)",[](double A,double B,double C,double D){return -A - B/(C + D);}),
        
        four_terms_expr(u8"(A + B)⋅(-C - D)",u8"(A + B)*(-C - D)",[](double A,double B,double C,double D){return (A + B)*(-C - D);}),
        
        four_terms_expr(u8"A⋅(B⋅C + D)",u8"A*(B*C + D)",[](double A,double B,double C,double D){return A*(B*C + D);}),
        
        four_terms_expr(u8"A⋅(B + C⋅D)",u8"A*(B + C*D)",[](double A,double B,double C,double D){return A*(B + C*D);}),
        
        four_terms_expr(u8"A + D⋅(-B + C)",u8"A + D*(-B + C)",[](double A,double B,double C,double D){return A + D*(-B + C);}),
        
        four_terms_expr(u8"    B⋅D\nA + ───\n     C ",u8"A + B*D/C",[](double A,double B,double C,double D){return A + B*D/C;}),
        
        four_terms_expr(u8"        C\nA - B - ─\n        D",u8"A - B - C/D",[](double A,double B,double C,double D){return A - B - C/D;}),
        
        four_terms_expr(u8"A + B\n─────\n C⋅D ",u8"(A + B)/(C*D)",[](double A,double B,double C,double D){return (A + B)/(C*D);}),
        
        four_terms_expr(u8"A   C\n─ + ─\nB   D",u8"A/B + C/D",[](double A,double B,double C,double D){return A/B + C/D;}),
        
        four_terms_expr(u8"     -A - B\n-D + ──────\n       C   ",u8"-D + (-A - B)/C",[](double A,double B,double C,double D){return -D + (-A - B)/C;}),
        
        four_terms_expr(u8"-A⋅(B + C + D)",u8"-A*(B + C + D)",[](double A,double B,double C,double D){return -A*(B + C + D);}),
        
        four_terms_expr(u8"    A     \n──────────\nD⋅(-B - C)",u8"A/(D*(-B - C))",[](double A,double B,double C,double D){return A/(D*(-B - C));}),
        
        four_terms_expr(u8"  A      \n- ─ + C⋅D\n  B      ",u8"-A/B + C*D",[](double A,double B,double C,double D){return -A/B + C*D;}),
        
        four_terms_expr(u8"   ⎛  B    ⎞\n-A⋅⎜- ─ + D⎟\n   ⎝  C    ⎠",u8"-A*(-B/C + D)",[](double A,double B,double C,double D){return -A*(-B/C + D);}),
        
        four_terms_expr(u8"A + D⋅(B - C)",u8"A + D*(B - C)",[](double A,double B,double C,double D){return A + D*(B - C);}),
        
        four_terms_expr(u8"-A - B\n──────\n C⋅D  ",u8"(-A - B)/(C*D)",[](double A,double B,double C,double D){return (-A - B)/(C*D);}),
        
        four_terms_expr(u8"-A - B⋅(C - D)",u8"-A - B*(C - D)",[](double A,double B,double C,double D){return -A - B*(C - D);}),
        
        four_terms_expr(u8"A⋅(-B - C) + D",u8"A*(-B - C) + D",[](double A,double B,double C,double D){return A*(-B - C) + D;}),
        
        four_terms_expr(u8"        C\nA + B + ─\n        D",u8"A + B + C/D",[](double A,double B,double C,double D){return A + B + C/D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nD⋅(B - C)",u8"-A/(D*(B - C))",[](double A,double B,double C,double D){return -A/(D*(B - C));}),
        
        four_terms_expr(u8"A      \n─ - C⋅D\nB      ",u8"A/B - C*D",[](double A,double B,double C,double D){return A/B - C*D;}),
        
        four_terms_expr(u8"-C⋅(A + B) \n───────────\n     D     ",u8"-C*(A + B)/D",[](double A,double B,double C,double D){return -C*(A + B)/D;}),
        
        four_terms_expr(u8"-A - D⋅(-B - C)",u8"-A - D*(-B - C)",[](double A,double B,double C,double D){return -A - D*(-B - C);}),
        
        four_terms_expr(u8"A⋅B⋅(C + D)",u8"A*B*(C + D)",[](double A,double B,double C,double D){return A*B*(C + D);}),
        
        four_terms_expr(u8"-A - B⋅(C + D)",u8"-A - B*(C + D)",[](double A,double B,double C,double D){return -A - B*(C + D);}),
        
        four_terms_expr(u8"C⋅(A + B) + D",u8"C*(A + B) + D",[](double A,double B,double C,double D){return C*(A + B) + D;}),
        
        four_terms_expr(u8"-A⋅D \n─────\nB - C",u8"-A*D/(B - C)",[](double A,double B,double C,double D){return -A*D/(B - C);}),
        
        four_terms_expr(u8"    A    \n─────────\nB + C - D",u8"A/(B + C - D)",[](double A,double B,double C,double D){return A/(B + C - D);}),
        
        four_terms_expr(u8"    -B + C\nA - ──────\n      D   ",u8"A - (-B + C)/D",[](double A,double B,double C,double D){return A - (-B + C)/D;}),
        
        four_terms_expr(u8"A + B - C⋅D",u8"A + B - C*D",[](double A,double B,double C,double D){return A + B - C*D;}),
        
        four_terms_expr(u8"  -A    \n────────\n-B⋅C + D",u8"-A/(-B*C + D)",[](double A,double B,double C,double D){return -A/(-B*C + D);}),
        
        four_terms_expr(u8"-C⋅(-A - B) \n────────────\n     D      ",u8"-C*(-A - B)/D",[](double A,double B,double C,double D){return -C*(-A - B)/D;}),
        
        four_terms_expr(u8"   A   \n───────\nB + C⋅D",u8"A/(B + C*D)",[](double A,double B,double C,double D){return A/(B + C*D);}),
        
        four_terms_expr(u8"A⋅B + C\n───────\n   D   ",u8"(A*B + C)/D",[](double A,double B,double C,double D){return (A*B + C)/D;}),
        
        four_terms_expr(u8"A⋅(-B + C)\n──────────\n    D     ",u8"A*(-B + C)/D",[](double A,double B,double C,double D){return A*(-B + C)/D;}),
        
        four_terms_expr(u8"-A⋅(-C + D) \n────────────\n     B      ",u8"-A*(-C + D)/B",[](double A,double B,double C,double D){return -A*(-C + D)/B;}),
        
        four_terms_expr(u8"D⋅(-A + B + C)",u8"D*(-A + B + C)",[](double A,double B,double C,double D){return D*(-A + B + C);}),
        
        four_terms_expr(u8"A + B⋅C\n───────\n   D   ",u8"(A + B*C)/D",[](double A,double B,double C,double D){return (A + B*C)/D;}),
        
        four_terms_expr(u8"   -A    \n─────────\nB - C - D",u8"-A/(B - C - D)",[](double A,double B,double C,double D){return -A/(B - C - D);}),
        
        four_terms_expr(u8"     B + C\n-A - ─────\n       D  ",u8"-A - (B + C)/D",[](double A,double B,double C,double D){return -A - (B + C)/D;}),
        
        four_terms_expr(u8" A⋅B \n─────\nC + D",u8"A*B/(C + D)",[](double A,double B,double C,double D){return A*B/(C + D);}),
        
        four_terms_expr(u8"    B - C\nA - ─────\n      D  ",u8"A - (B - C)/D",[](double A,double B,double C,double D){return A - (B - C)/D;}),
        
        four_terms_expr(u8"D⋅(A - B⋅C)",u8"D*(A - B*C)",[](double A,double B,double C,double D){return D*(A - B*C);}),
        
        four_terms_expr(u8"    A     \n──────────\n-B + C + D",u8"A/(-B + C + D)",[](double A,double B,double C,double D){return A/(-B + C + D);}),
        
        four_terms_expr(u8"-A + B⋅(-C - D)",u8"-A + B*(-C - D)",[](double A,double B,double C,double D){return -A + B*(-C - D);}),
        
        four_terms_expr(u8"     B    \n-A + ─ + D\n     C    ",u8"-A + B/C + D",[](double A,double B,double C,double D){return -A + B/C + D;}),
        
        four_terms_expr(u8"A⋅(-B - C) - D",u8"A*(-B - C) - D",[](double A,double B,double C,double D){return A*(-B - C) - D;}),
        
        four_terms_expr(u8"    A     \n──────────\nB⋅(-C + D)",u8"A/(B*(-C + D))",[](double A,double B,double C,double D){return A/(B*(-C + D));}),
        
        four_terms_expr(u8"  ⎛    C⎞\nA⋅⎜B - ─⎟\n  ⎝    D⎠",u8"A*(B - C/D)",[](double A,double B,double C,double D){return A*(B - C/D);}),
        
        four_terms_expr(u8"A⋅B    \n─── - D\n C     ",u8"A*B/C - D",[](double A,double B,double C,double D){return A*B/C - D;}),
        
        four_terms_expr(u8"-A⋅(-B + C + D)",u8"-A*(-B + C + D)",[](double A,double B,double C,double D){return -A*(-B + C + D);}),
        
        four_terms_expr(u8"  -A    \n────────\n-B - C⋅D",u8"-A/(-B - C*D)",[](double A,double B,double C,double D){return -A/(-B - C*D);}),
        
        four_terms_expr(u8"A⋅D⋅(B + C)",u8"A*D*(B + C)",[](double A,double B,double C,double D){return A*D*(B + C);}),
        
        four_terms_expr(u8"C⋅(A + B) - D",u8"C*(A + B) - D",[](double A,double B,double C,double D){return C*(A + B) - D;}),
        
        four_terms_expr(u8"A + B + C + D",u8"A + B + C + D",[](double A,double B,double C,double D){return A + B + C + D;}),
        
        four_terms_expr(u8"A        \n─ - C + D\nB        ",u8"A/B - C + D",[](double A,double B,double C,double D){return A/B - C + D;}),
        
        four_terms_expr(u8"-A + B\n──────\nC + D ",u8"(-A + B)/(C + D)",[](double A,double B,double C,double D){return (-A + B)/(C + D);}),
        
        four_terms_expr(u8"(-A + B)⋅(C - D)",u8"(-A + B)*(C - D)",[](double A,double B,double C,double D){return (-A + B)*(C - D);}),
        
        four_terms_expr(u8"  A  \n─────\nB    \n─ - D\nC    ",u8"A/(B/C - D)",[](double A,double B,double C,double D){return A/(B/C - D);}),
        
        four_terms_expr(u8"A⋅(-B⋅C + D)",u8"A*(-B*C + D)",[](double A,double B,double C,double D){return A*(-B*C + D);}),
        
        four_terms_expr(u8"A⋅(B - C⋅D)",u8"A*(B - C*D)",[](double A,double B,double C,double D){return A*(B - C*D);}),
        
        four_terms_expr(u8"A⋅(B⋅C - D)",u8"A*(B*C - D)",[](double A,double B,double C,double D){return A*(B*C - D);}),
        
        four_terms_expr(u8"     B\n-A + ─\n     C\n──────\n  D   ",u8"(-A + B/C)/D",[](double A,double B,double C,double D){return (-A + B/C)/D;}),
        
        four_terms_expr(u8"      B \n-A + ───\n     C⋅D",u8"-A + B/(C*D)",[](double A,double B,double C,double D){return -A + B/(C*D);}),
        
        four_terms_expr(u8"A⋅(B + C - D)",u8"A*(B + C - D)",[](double A,double B,double C,double D){return A*(B + C - D);}),
        
        four_terms_expr(u8"A⋅(B - C - D)",u8"A*(B - C - D)",[](double A,double B,double C,double D){return A*(B - C - D);}),
        
        four_terms_expr(u8"A + B⋅C⋅D",u8"A + B*C*D",[](double A,double B,double C,double D){return A + B*C*D;}),
        
        four_terms_expr(u8"-C⋅(A - B) + D",u8"-C*(A - B) + D",[](double A,double B,double C,double D){return -C*(A - B) + D;}),
        
        four_terms_expr(u8"   ⎛  B    ⎞\n-A⋅⎜- ─ - D⎟\n   ⎝  C    ⎠",u8"-A*(-B/C - D)",[](double A,double B,double C,double D){return -A*(-B/C - D);}),
        
        four_terms_expr(u8"-A + D⋅(B + C)",u8"-A + D*(B + C)",[](double A,double B,double C,double D){return -A + D*(B + C);}),
        
        four_terms_expr(u8"  ⎛    C⎞\nA⋅⎜B + ─⎟\n  ⎝    D⎠",u8"A*(B + C/D)",[](double A,double B,double C,double D){return A*(B + C/D);}),
        
        four_terms_expr(u8"-A⋅B⋅(-C + D)",u8"-A*B*(-C + D)",[](double A,double B,double C,double D){return -A*B*(-C + D);}),
        
        four_terms_expr(u8"  -A   \n───────\nB⋅C + D",u8"-A/(B*C + D)",[](double A,double B,double C,double D){return -A/(B*C + D);}),
        
        four_terms_expr(u8"  A   \n──────\n     C\n-B + ─\n     D",u8"A/(-B + C/D)",[](double A,double B,double C,double D){return A/(-B + C/D);}),
        
        four_terms_expr(u8"    -A + B\nD + ──────\n      C   ",u8"D + (-A + B)/C",[](double A,double B,double C,double D){return D + (-A + B)/C;}),
        
        four_terms_expr(u8"A        \n─ - C - D\nB        ",u8"A/B - C - D",[](double A,double B,double C,double D){return A/B - C - D;}),
        
        four_terms_expr(u8"       B   \n-A - ──────\n     -C + D",u8"-A - B/(-C + D)",[](double A,double B,double C,double D){return -A - B/(-C + D);}),
        
        four_terms_expr(u8"-A - B⋅(-C + D)",u8"-A - B*(-C + D)",[](double A,double B,double C,double D){return -A - B*(-C + D);}),
        
        four_terms_expr(u8"D⋅(A + B⋅C)",u8"D*(A + B*C)",[](double A,double B,double C,double D){return D*(A + B*C);}),
        
        four_terms_expr(u8"-A - B⋅C + D",u8"-A - B*C + D",[](double A,double B,double C,double D){return -A - B*C + D;}),
        
        four_terms_expr(u8"     B⋅C\n-A - ───\n      D ",u8"-A - B*C/D",[](double A,double B,double C,double D){return -A - B*C/D;}),
        
        four_terms_expr(u8"-A - B + C + D",u8"-A - B + C + D",[](double A,double B,double C,double D){return -A - B + C + D;}),
        
        four_terms_expr(u8"(A - B)⋅(-C - D)",u8"(A - B)*(-C - D)",[](double A,double B,double C,double D){return (A - B)*(-C - D);}),
        
        four_terms_expr(u8"-A⋅B \n─────\n C⋅D ",u8"-A*B/(C*D)",[](double A,double B,double C,double D){return -A*B/(C*D);}),
        
        four_terms_expr(u8"    B    \nA - ─ + D\n    C    ",u8"A - B/C + D",[](double A,double B,double C,double D){return A - B/C + D;}),
        
        four_terms_expr(u8"D⋅(-A + B - C)",u8"D*(-A + B - C)",[](double A,double B,double C,double D){return D*(-A + B - C);}),
        
        four_terms_expr(u8"     -B - C\n-A - ──────\n       D   ",u8"-A - (-B - C)/D",[](double A,double B,double C,double D){return -A - (-B - C)/D;}),
        
        four_terms_expr(u8"  -A   \n───────\nB⋅C - D",u8"-A/(B*C - D)",[](double A,double B,double C,double D){return -A/(B*C - D);}),
        
        four_terms_expr(u8"A⋅(B - C + D)",u8"A*(B - C + D)",[](double A,double B,double C,double D){return A*(B - C + D);}),
        
        four_terms_expr(u8"      B  \nA - ─────\n    C + D",u8"A - B/(C + D)",[](double A,double B,double C,double D){return A - B/(C + D);}),
        
        four_terms_expr(u8"   ⎛B    ⎞\n-A⋅⎜─ + D⎟\n   ⎝C    ⎠",u8"-A*(B/C + D)",[](double A,double B,double C,double D){return -A*(B/C + D);}),
        
        four_terms_expr(u8"C⋅(A + B)\n─────────\n    D    ",u8"C*(A + B)/D",[](double A,double B,double C,double D){return C*(A + B)/D;}),
        
        four_terms_expr(u8"A⋅B⋅D\n─────\n  C  ",u8"A*B*D/C",[](double A,double B,double C,double D){return A*B*D/C;}),
        
        four_terms_expr(u8"  -A    \n────────\n-B + C⋅D",u8"-A/(-B + C*D)",[](double A,double B,double C,double D){return -A/(-B + C*D);}),
        
        four_terms_expr(u8"       B  \n-A + ─────\n     C + D",u8"-A + B/(C + D)",[](double A,double B,double C,double D){return -A + B/(C + D);}),
        
        four_terms_expr(u8"       B  \n-A - ─────\n     C - D",u8"-A - B/(C - D)",[](double A,double B,double C,double D){return -A - B/(C - D);}),
        
        four_terms_expr(u8"-C⋅(A - B) - D",u8"-C*(A - B) - D",[](double A,double B,double C,double D){return -C*(A - B) - D;}),
        
        four_terms_expr(u8"-A⋅(-B + C) + D",u8"-A*(-B + C) + D",[](double A,double B,double C,double D){return -A*(-B + C) + D;}),
        
        four_terms_expr(u8"   ⎛B    ⎞\n-A⋅⎜─ - D⎟\n   ⎝C    ⎠",u8"-A*(B/C - D)",[](double A,double B,double C,double D){return -A*(B/C - D);}),
        
        four_terms_expr(u8"A + B \n──────\n-C - D",u8"(A + B)/(-C - D)",[](double A,double B,double C,double D){return (A + B)/(-C - D);}),
        
        four_terms_expr(u8"A + B - C + D",u8"A + B - C + D",[](double A,double B,double C,double D){return A + B - C + D;}),
        
        four_terms_expr(u8"-C⋅(-A + B) + D",u8"-C*(-A + B) + D",[](double A,double B,double C,double D){return -C*(-A + B) + D;}),
        
        four_terms_expr(u8"     -A + B\n-D + ──────\n       C   ",u8"-D + (-A + B)/C",[](double A,double B,double C,double D){return -D + (-A + B)/C;}),
        
        four_terms_expr(u8"-A⋅B \n─────\nC - D",u8"-A*B/(C - D)",[](double A,double B,double C,double D){return -A*B/(C - D);}),
        
        four_terms_expr(u8"C⋅(-A - B)\n──────────\n    D     ",u8"C*(-A - B)/D",[](double A,double B,double C,double D){return C*(-A - B)/D;}),
        
        four_terms_expr(u8"-A⋅B⋅C + D",u8"-A*B*C + D",[](double A,double B,double C,double D){return -A*B*C + D;}),
        
        four_terms_expr(u8"  ⎛     B⎞\nD⋅⎜-A + ─⎟\n  ⎝     C⎠",u8"D*(-A + B/C)",[](double A,double B,double C,double D){return D*(-A + B/C);}),
        
        four_terms_expr(u8"-A⋅(B - C) + D",u8"-A*(B - C) + D",[](double A,double B,double C,double D){return -A*(B - C) + D;}),
        
        four_terms_expr(u8"A⋅(-C + D)\n──────────\n    B     ",u8"A*(-C + D)/B",[](double A,double B,double C,double D){return A*(-C + D)/B;}),
        
        four_terms_expr(u8"-C⋅D⋅(-A + B)",u8"-C*D*(-A + B)",[](double A,double B,double C,double D){return -C*D*(-A + B);}),
        
        four_terms_expr(u8"  A    \n- ─ - C\n  B    \n───────\n   D   ",u8"(-A/B - C)/D",[](double A,double B,double C,double D){return (-A/B - C)/D;}),
        
        four_terms_expr(u8"-A⋅D⋅(-B + C)",u8"-A*D*(-B + C)",[](double A,double B,double C,double D){return -A*D*(-B + C);}),
        
        four_terms_expr(u8"-D⋅(-A - B) \n────────────\n     C      ",u8"-D*(-A - B)/C",[](double A,double B,double C,double D){return -D*(-A - B)/C;}),
        
        four_terms_expr(u8"A - B\n─────\n C⋅D ",u8"(A - B)/(C*D)",[](double A,double B,double C,double D){return (A - B)/(C*D);}),
        
        four_terms_expr(u8"D⋅(-A + B)\n──────────\n    C     ",u8"D*(-A + B)/C",[](double A,double B,double C,double D){return D*(-A + B)/C;}),
        
        four_terms_expr(u8"D⋅(-A - B + C)",u8"D*(-A - B + C)",[](double A,double B,double C,double D){return D*(-A - B + C);}),
        
        four_terms_expr(u8"-A + B⋅(C - D)",u8"-A + B*(C - D)",[](double A,double B,double C,double D){return -A + B*(C - D);}),
        
        four_terms_expr(u8"A      \n─ + C⋅D\nB      ",u8"A/B + C*D",[](double A,double B,double C,double D){return A/B + C*D;}),
        
        four_terms_expr(u8"(A + B)⋅(C - D)",u8"(A + B)*(C - D)",[](double A,double B,double C,double D){return (A + B)*(C - D);}),
        
        four_terms_expr(u8"   -A     \n──────────\nD⋅(-B + C)",u8"-A/(D*(-B + C))",[](double A,double B,double C,double D){return -A/(D*(-B + C));}),
        
        four_terms_expr(u8"A - B + C\n─────────\n    D    ",u8"(A - B + C)/D",[](double A,double B,double C,double D){return (A - B + C)/D;}),
        
        four_terms_expr(u8"A⋅(-B + C - D)",u8"A*(-B + C - D)",[](double A,double B,double C,double D){return A*(-B + C - D);}),
        
        four_terms_expr(u8"(A - B)⋅(C + D)",u8"(A - B)*(C + D)",[](double A,double B,double C,double D){return (A - B)*(C + D);}),
        
        four_terms_expr(u8"-A + D⋅(-B - C)",u8"-A + D*(-B - C)",[](double A,double B,double C,double D){return -A + D*(-B - C);}),
        
        four_terms_expr(u8"A⋅(-B⋅C - D)",u8"A*(-B*C - D)",[](double A,double B,double C,double D){return A*(-B*C - D);}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B + C - D",u8"-A/(-B + C - D)",[](double A,double B,double C,double D){return -A/(-B + C - D);}),
        
        four_terms_expr(u8"-A⋅(-B + C) - D",u8"-A*(-B + C) - D",[](double A,double B,double C,double D){return -A*(-B + C) - D;}),
        
        four_terms_expr(u8"     B⋅D\n-A - ───\n      C ",u8"-A - B*D/C",[](double A,double B,double C,double D){return -A - B*D/C;}),
        
        four_terms_expr(u8"-A + B⋅(C + D)",u8"-A + B*(C + D)",[](double A,double B,double C,double D){return -A + B*(C + D);}),
        
        four_terms_expr(u8"-A⋅(-B + C⋅D)",u8"-A*(-B + C*D)",[](double A,double B,double C,double D){return -A*(-B + C*D);}),
        
        four_terms_expr(u8"     B\n-A - ─\n     C\n──────\n  D   ",u8"(-A - B/C)/D",[](double A,double B,double C,double D){return (-A - B/C)/D;}),
        
        four_terms_expr(u8"A⋅(B - C)\n─────────\n    D    ",u8"A*(B - C)/D",[](double A,double B,double C,double D){return A*(B - C)/D;}),
        
        four_terms_expr(u8"-A⋅D  \n──────\n-B + C",u8"-A*D/(-B + C)",[](double A,double B,double C,double D){return -A*D/(-B + C);}),
        
        four_terms_expr(u8"(-A - B)⋅(-C + D)",u8"(-A - B)*(-C + D)",[](double A,double B,double C,double D){return (-A - B)*(-C + D);}),
        
        four_terms_expr(u8"-C⋅(-A + B) - D",u8"-C*(-A + B) - D",[](double A,double B,double C,double D){return -C*(-A + B) - D;}),
        
        four_terms_expr(u8"A + B + C⋅D",u8"A + B + C*D",[](double A,double B,double C,double D){return A + B + C*D;}),
        
        four_terms_expr(u8"-C⋅(A - B) \n───────────\n     D     ",u8"-C*(A - B)/D",[](double A,double B,double C,double D){return -C*(A - B)/D;}),
        
        four_terms_expr(u8"   -A     \n──────────\n-B - C + D",u8"-A/(-B - C + D)",[](double A,double B,double C,double D){return -A/(-B - C + D);}),
        
        four_terms_expr(u8"  -A    \n────────\n-B⋅C - D",u8"-A/(-B*C - D)",[](double A,double B,double C,double D){return -A/(-B*C - D);}),
        
        four_terms_expr(u8"  A   C\n- ─ + ─\n  B   D",u8"-A/B + C/D",[](double A,double B,double C,double D){return -A/B + C/D;}),
        
        four_terms_expr(u8"-A + B + C - D",u8"-A + B + C - D",[](double A,double B,double C,double D){return -A + B + C - D;}),
        
        four_terms_expr(u8"-A⋅B⋅C - D",u8"-A*B*C - D",[](double A,double B,double C,double D){return -A*B*C - D;}),
        
        four_terms_expr(u8"-A⋅(B - C) - D",u8"-A*(B - C) - D",[](double A,double B,double C,double D){return -A*(B - C) - D;}),
        
        four_terms_expr(u8"  A⋅C    \n- ─── + D\n   B     ",u8"-A*C/B + D",[](double A,double B,double C,double D){return -A*C/B + D;}),
        
        four_terms_expr(u8"D⋅(A⋅B - C)",u8"D*(A*B - C)",[](double A,double B,double C,double D){return D*(A*B - C);}),
        
        four_terms_expr(u8" -A  \n─────\n    C\nB - ─\n    D",u8"-A/(B - C/D)",[](double A,double B,double C,double D){return -A/(B - C/D);}),
        
        four_terms_expr(u8"C⋅D⋅(A + B)",u8"C*D*(A + B)",[](double A,double B,double C,double D){return C*D*(A + B);}),
        
        four_terms_expr(u8"    B - C\nA + ─────\n      D  ",u8"A + (B - C)/D",[](double A,double B,double C,double D){return A + (B - C)/D;}),
        
        four_terms_expr(u8"    A    \n─────────\nB⋅(C - D)",u8"A/(B*(C - D))",[](double A,double B,double C,double D){return A/(B*(C - D));}),
        
        four_terms_expr(u8"A⋅(-B - C - D)",u8"A*(-B - C - D)",[](double A,double B,double C,double D){return A*(-B - C - D);}),
        
        four_terms_expr(u8"A    \n─ - C\nB    \n─────\n  D  ",u8"(A/B - C)/D",[](double A,double B,double C,double D){return (A/B - C)/D;}),
        
        four_terms_expr(u8"   A   \n───────\nB - C⋅D",u8"A/(B - C*D)",[](double A,double B,double C,double D){return A/(B - C*D);}),
        
        four_terms_expr(u8"         C\n-A - B + ─\n         D",u8"-A - B + C/D",[](double A,double B,double C,double D){return -A - B + C/D;}),
        
        four_terms_expr(u8"A - B - C\n─────────\n    D    ",u8"(A - B - C)/D",[](double A,double B,double C,double D){return (A - B - C)/D;}),
        
    };
}
#endif