

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    # print(student_marks[])
    
    score = student_marks.get(query_name)
    
    if score is not None:
        avg = 0
        num = sum(score)
        avg = num/len(score)
        print("%.2f" % avg)
    else:
        print("Student not found")
    
    