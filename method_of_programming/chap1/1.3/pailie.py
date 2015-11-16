def cal_result(string, current_num, total_num, result):
    if current_num==0:
        print ''.join(result)
        return
    for i in range(total_num):
        result[total_num - current_num] = string[i]
        cal_result(string, current_num-1, total_num, result)

def cal(s):
    result = [i for i in range(len(s))]
    # result = []
    cal_result(s, len(s), len(s), result)

s = 'abc'
cal(s)