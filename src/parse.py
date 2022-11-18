# import pandas

f = open('./entry/routes.csv')


airport = []

for i in f:
  j = i.split(',')[2]
  print(j)