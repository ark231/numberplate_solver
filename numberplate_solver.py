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

def calc(expression_str,value_dict,desired_result=10,fast_exit=False):
    operators=extract_operators(expression_str)
    #print(operators)
    ok_exprs=set()
    for operator_combination in itertools.product(*operators):
        replaced_expr=replace_with_operator(expression_str,operator_combination)
        #print(replaced_expr)
        A,B,C,D=sympy.symbols("A,B,C,D")
        expr=sympy.parse_expr(replaced_expr)
        eval_result=expr.subs(value_dict)
        if eval_result==desired_result:
            ok_exprs.add(expr)
            if fast_exit:
                break
    return ok_exprs

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
    

def main(argc,argv):
    input_data=parse_args(argc,argv)
    brackets=create_brackets([number('A'),number('B'),number('C'),number('D')])
    ok_exprs=set()
    for meta_bracket in brackets:
        #print(meta_bracket.to_string())
        ok_exprs=ok_exprs|calc(meta_bracket.to_string(),input_data["numbers"])
    output_result(ok_exprs,input_data["numbers"])


if __name__ == "__main__":
    main(len(sys.argv),sys.argv)
