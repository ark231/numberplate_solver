#!/usr/bin/env python3
import itertools

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
    pass

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

def calc(expression_str,fast_exit=False):
    operators=extract_operators(expression_str)
    #print(operators)
    for operator_combination in itertools.product(*operators):
        replaced_expr=replace_with_operator(expression_str,operator_combination)
        print(replaced_expr)
    

def main():
    brackets=create_brackets([number('A'),number('B'),number('C'),number('D')])
    for meta_bracket in brackets:
        #print(meta_bracket.to_string())
        calc(meta_bracket.to_string())


if __name__ == "__main__":
    main()
