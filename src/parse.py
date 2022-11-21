import pandas as pd

# f = open('./entry/routes.csv')

# airport = []

# for i in f:
#   j = i.split(',')[2]
#   airport.append(j)

# airset = set(airport)
# # print(airset)

# f = open('./entry/airport-codes.csv')
# for i in f:
#   j = i.split(',')[4]
#   print(j)
df = pd.read_csv('./entry/routes.csv')
df