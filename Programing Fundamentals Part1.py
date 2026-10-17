Yoga = 6
Session = 7.25
Time_1 = round((6 * 7.25), 2)

ConcessionD = 0.3
PriceD = round((Time_1 * ConcessionD), 2)
TotalD = round((Time_1 - PriceD), 2)

TotalM = 200
Hours = TotalM // 60
Minutes = TotalM % 60

print("1. We combine by multiply and round to two decimal places", Time_1)

print("2. We can add our first discount by multiply and round it", PriceD, "we can subtract and round our final price", TotalD)

print("3. We divided them using one hour on hours", Hours, "and minutes", Minutes)

print("4. Our total for Yoga Session is", Time_1, "then our discount", TotalD, "lastly hours and minutes for the pool", Hours, "and", Minutes)