

def mySqrt(x: int) -> int:
	if x < 2: return x
	
	lo, hi = 2, x // 2

	
	# termination: lo + 1 = hi
	while lo <= hi:
		mid = (lo + hi) // 2

		print(lo, hi, mid)
		
		num = mid * mid
		
		if num > x:
			print("num > x")
			hi = mid - 1
		elif num < x:
			print("num < x")
			lo = mid + 1
		else:
			return mid
		
	print("final", lo, hi, mid)
	# why hi?
	return hi


ans = mySqrt(10)
print("ans", ans)