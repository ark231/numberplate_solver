
#include"numberplate_exprs.hpp"
#include<stdexcept>
namespace{
    std::string replace_var(std::string src,double arg0,double arg1,double arg2,double arg3){
        if((arg0<0||9<arg0)||(arg1<0||9<arg1)||(arg2<0||9<arg2)||(arg3<0||9<arg3)){
            throw std::runtime_error("more than one digit into one-character-wide var");
        }
        std::string result=src;
        for(auto itr=result.begin();itr!=result.end();itr++){
            switch(*itr){ 
                case 'A':
                    *itr=std::to_string(arg0)[0];
                    break;
                case 'B':
                    *itr=std::to_string(arg1)[0];
                    break;
                case 'C':
                    *itr=std::to_string(arg2)[0];
                    break;
                case 'D':
                    *itr=std::to_string(arg3)[0];
                    break;
            }
        }
        return result;
    }
}
namespace numberplate{
    four_terms_expr::four_terms_expr(const char *pretty,const char *pretty_oneline,decltype(calc_) calc):pretty_(pretty),pretty_oneline_(pretty_oneline),calc_(calc){}
    std::string four_terms_expr::pretty() const{return this->pretty_;}
    std::string four_terms_expr::pretty_oneline() const{return this->pretty_oneline_;}
    std::string four_terms_expr::pretty(double arg0,double arg1,double arg2,double arg3) const{
        return replace_var(this->pretty_,arg0,arg1,arg2,arg3);
    }
    std::string four_terms_expr::pretty_oneline(double arg0,double arg1,double arg2,double arg3) const{
        return replace_var(this->pretty_oneline_,arg0,arg1,arg2,arg3);
    }
    double four_terms_expr::operator()(double arg0,double arg1,double arg2,double arg3) const{
        return this->calc_(arg0,arg1,arg2,arg3);
    }
}
    