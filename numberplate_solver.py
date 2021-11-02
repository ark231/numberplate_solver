#!/usr/bin/env python3

class number:
    def __init__(self,value):
        self.value=value

    def to_string(self,is_head=False):
        return str(self.value)

class bracket:
    def __init__(self,contents):
        self.contents=contents

    def to_string(self,is_head=False):
        result="("
        for content in self.contents:
            result+=content.to_string()+"<+-*/>"
        result=result[:-len("<+-*/>")]+")"
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

def main():
    brackets=create_brackets([number('A'),number('B'),number('C'),number('D')])
    for meta_bracket in brackets:
        print(meta_bracket.to_string())


if __name__ == "__main__":
    main()
