
import unittest

from zipline_death import LongestZipline


tests = (
    (
        [4, 1, 2, 5, 3, 7, 6],
        4
    ),
)


def check(A, length):
    return LongestZipline(A) == length

class TestLongestZipline(unittest.TestCase):

    def test_01(self):
        self.assertTrue(check(tests[0][0], tests[0][1]))

if __name__ == "__main__":
    res = unittest.main(verbosity=3, exit=False)