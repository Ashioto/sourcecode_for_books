def cal_(s, start, end, current_num, result):
    if current_num==0:
        print ''.join(result)
        return

    for i in range(start,end+1-(current_num-1)):
        result.append(s[i])
        cal_(s, i + 1, end, current_num - 1, result)
        result.pop()

def cal(s, num):
    result = []
    cal_(s, 0, len(s)-1, num, result)

s = 'abcdef'
cal(s,3)