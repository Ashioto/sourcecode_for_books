#-*- coding:utf-8 -*-
def cal_(s, start, end, current_num, total_num, result):
    if current_num==0:
        print ''.join(result[0:total_num])
        return

    for i in range(start,end+1-(current_num-1)):  #第一个字符所能到达的最大长度处，为（end-1）-（current_num-1），即后面至少要有（current_num-1）个数。
        result[total_num - current_num] = s[i]
        cal_(s, i + 1, end, current_num - 1, total_num, result)  #递归调用，从 **下一个字符开始** ，层数减一

def cal(s, num):
    result = [i for i in range(len(s))]
    cal_(s, 0, len(s)-1, num, num, result)

s = 'abcdef'
cal(s,4)
