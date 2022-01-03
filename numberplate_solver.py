#!/usr/bin/env python3
import itertools
import sympy
import sys

class number:
    def __init__(self,value):
        self.value=value

    def to_string(self,is_head=False):
        if not is_head:
            return str(self.value)
        else:
            return f"(< ->{str(self.value)})"

class bracket:
    def __init__(self,contents):
        self.contents=contents

    def to_string(self,is_head=False):
        result_inner=""
        current_is_head=True #unused unless is_head is True
        for content in self.contents:
            if  current_is_head == False:
                result_inner+=content.to_string()+"<+-*/>"
            else:
                result_inner+=content.to_string(True)+"<+-*/>"
                current_is_head=False
        result_inner=result_inner[:-len("<+-*/>")]
        result=f"({result_inner})"
        if is_head:
            result=f"(< ->{result})"
        return result

def create_brackets(values):
    result=[]
    result.append(bracket(values))
    result.append(bracket([bracket(values[0:2])]+values[2:4]))
    result.append(bracket([bracket(values[0:2]),bracket(values[2:4])]))
    result.append(bracket([bracket(values[0:3]),values[3]]))
    result.append(bracket([bracket([bracket(values[0:2]),values[2]]),values[3]]))
    result.append(bracket([bracket([values[0],bracket(values[1:3])]),values[3]]))
    result.append(bracket([values[0],bracket(values[1:3]),values[3]]))
    result.append(bracket([values[0],bracket(values[1:4])]))
    result.append(bracket([values[0],bracket([bracket(values[1:3]),values[3]])]))
    result.append(bracket([values[0],bracket([values[1],bracket(values[2:4])])]))
    result.append(bracket(values[0:2]+[bracket(values[2:4])]))
    return result

def parse_args(argc,argv):
    if argc <4+1:
        print("error: too few arguments")
        exit(-1)
    else:
        result={}
        result["numbers"]={'A':int(argv[1]),'B':int(argv[2]),'C':int(argv[3]),'D':int(argv[4])}
        result["forc"] = False
        if argc > 5:
            if argv[5] == "--forc":
                result["forc"] = True
        return result

def extract_operators(expression_str):
    result=[]
    expr_itr=iter(expression_str)
    while True:
        try:
            if next(expr_itr)=='<':
                operators=[]
                current_char=next(expr_itr)
                while current_char != '>':
                    operators.append(current_char)
                    current_char=next(expr_itr)
                result.append(operators)
        except StopIteration:
            break
    return result
        
def replace_with_operator(expression_str,operators):
    result=list(expression_str)
    expr_itr=iter(expression_str)
    is_in_operator = False
    idx_current_operator=0
    for i in range(len(expression_str)):
        if result[i] =='<':
            is_in_operator = True
            result[i] = ' '
        elif result[i] =='>':
            is_in_operator = False
            result[i] = operators[idx_current_operator]
            idx_current_operator+=1
        elif is_in_operator:
            result[i] = ' '
    return "".join(result).replace(' ','')

def calc(expression_str,value_dict,desired_result=10,fast_exit=False,no_check=False):
    operators=extract_operators(expression_str)
    #print(operators)
    ok_exprs=set()
    exprs=set()
    for operator_combination in itertools.product(*operators):
        replaced_expr=replace_with_operator(expression_str,operator_combination)
        #print(replaced_expr)
        A,B,C,D=sympy.symbols("A,B,C,D")
        expr=sympy.parse_expr(replaced_expr)
        exprs.add(expr)
        if not no_check:
            eval_result=expr.subs(value_dict)
            if eval_result==desired_result:
                ok_exprs.add(expr)
                if fast_exit:
                    break
    return (ok_exprs,exprs)

def output_result(ok_exprs,value_dict,output_configs={"spoiler":True}):
    if len(ok_exprs)==0:
        print("no solution found")
    else:
        print(f"{len(ok_exprs)} solutions found")
        if output_configs["spoiler"]:
            print("found solutions:")
            for ok_expr in ok_exprs:
                output=sympy.pretty(ok_expr)
                for symbol,value in value_dict.items():
                    output=output.replace(symbol,str(value))
                print(output)
    
def output_cpp(exprs):
    header="""
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
    inline std::array<four_terms_expr,$(len(exprs))> EXPRS={
    """.replace("$(len(exprs))",str(len(exprs)))
    for expr in exprs:
        header+="""
        four_terms_expr(u8"$PRETTY",[](double A,double B,double C,double D){return $CODE;}),
        """.replace("$PRETTY",sympy.pretty(expr).replace("\n","\\n")).replace("$CODE",sympy.ccode(expr))
    header+="""
    };
}
#endif"""
    implementation="""
#include"numberplate_exprs.hpp"
#include<stdexcept>
namespace numberplate{
    four_terms_expr::four_terms_expr(const char *pretty,decltype(calc_) calc):pretty_(pretty),calc_(calc){}
    std::string four_terms_expr::pretty() const{return this->pretty_;}
    std::string four_terms_expr::pretty(double arg0,double arg1,double arg2,double arg3) const{
        if((arg0<0||9<arg0)||(arg1<0||9<arg1)||(arg2<0||9<arg2)||(arg3<0||9<arg3)){
            throw std::runtime_error("more than one digit into one-character-wide var");
        }
        std::string result=this->pretty_;
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
    double four_terms_expr::operator()(double arg0,double arg1,double arg2,double arg3) const{
        return this->calc_(arg0,arg1,arg2,arg3);
    }
}
    """
    with open("numberplate_exprs.hpp","w") as headerfile:
        headerfile.write(header)
    with open("numberplate_exprs.cpp","w") as implfile:
        implfile.write(implementation)

def main(argc,argv):
    input_data=parse_args(argc,argv)
    brackets=create_brackets([number('A'),number('B'),number('C'),number('D')])
    ok_exprs=set()
    exprs=set()
    for meta_bracket in brackets:
        #print(meta_bracket.to_string())
        calc_results=calc(meta_bracket.to_string(),input_data["numbers"],no_check=input_data["forc"])
        ok_exprs=ok_exprs|calc_results[0]
        exprs=exprs|calc_results[1]
    if not input_data["forc"]:
        output_result(ok_exprs,input_data["numbers"])
    else:
        output_cpp(exprs)


if __name__ == "__main__":
    main(len(sys.argv),sys.argv)
