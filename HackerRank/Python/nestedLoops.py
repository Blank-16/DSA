
if __name__ == '__main__':
    total = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        total.append([name, score])
        
    total_scores = []
    for i in range(len(total)):
        total_scores.append(total[i][1])
    allOutputs = sorted(set(total_scores))
    SecondOutput = allOutputs[1]
    # print(SecondOutput)
    
    da = []
    for i in range(len(total)):
        if(total[i][1] == SecondOutput):
            da.append(total[i][0])
    da = sorted(da)
    for i in range(len(da)):
        print(da[i])
    