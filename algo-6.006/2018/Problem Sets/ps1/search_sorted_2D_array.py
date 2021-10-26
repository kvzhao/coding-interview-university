def search_sorted_2D_array_v1(A, v):
    '''
    Return tuple (x, y) such that A[y][x] == v, or None.
    Input:  A | Array of equal length arrays of integers 
              |     representing the rows of a 2D array
              |     where A[y][x] >= A[y - 1][x] and
              |           A[y][x] >= A[y][x - 1] 
              |     for all (x, y) in range.
            v | An integer to search for in A.
    '''

    for y in range(len(A)):
        left, right = 0, len(A[0]) - 1
        while left <= right:
            x = (left + right) // 2
            val = A[y][x]
            if val == v:
                return (x, y)
            elif val < v:
                left = x + 1
            else:
                right = x - 1
    return None


def search_sorted_2D_array(A, v):

    def search_subarray(A, v, x0, y0, x1, y1):

        if (x1 < x0) or (y1 < y0):
            return None

        val = A[y1][x0]

        if val > v:
            return search_subarray(A, v, x0, y0, x1, y1 - 1)
        if val < v:
            return search_subarray(A, v, x0 + 1, y0, x1, y1)

        return (x0, y1)

    # upper-left, bottom-right
    return search_subarray(A, v, 0, 0, len(A[0]) - 1, len(A) - 1)
