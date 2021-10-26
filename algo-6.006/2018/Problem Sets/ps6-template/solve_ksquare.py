def is_solved(config):
    "Return whether input config is solved"
    ##################
    # YOUR CODE HERE #
    ##################
    return True 

def move(config, mv):
    "Return a new configuration made by moving config by move mv"
    k = len(config)
    (s, i) = mv         # s in ("row", "col") and i in range(k)
    ##################
    # YOUR CODE HERE #
    ##################
    return tuple([tuple(row) for row in config])

def solve_ksquare(config):
    "Return a list of moves that solves config"
    ##################
    # YOUR CODE HERE #
    ##################
    return []
