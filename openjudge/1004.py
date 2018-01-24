import sys

sum = 0.0
for lin in sys.stdin:
    sum += float(lin)

print("${0:.2f}".format( sum/12.0))

