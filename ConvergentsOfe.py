#  ************************************************************
#  *  Problem - Convergents of 'e'
#  *  Solved by - N0T1C3
#  ************************************************************/
#  
#     Answer = 272
# 

import math
v = [2]
for i in range(33):
    v.append(1)
	v.append(2*(i+1))
	if(i!=32):
		v.append(1)
num , den = 1, 1
for item in reversed(v):
	temp = den 
	den = item*den+num
	num = temp
	gc = math.gcd(num, den)
	num //= gc
  den //= gc
	# print(str(den) + " / "+ str(num))

#print(str(den) + " / " + str(num))
ans = 0;
while(den) :
	ans += den%10
	den //= 10
print(ans)
