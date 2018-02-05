# US_COINS
US_COINS = [100, 25, 10, 5, 1]


# change()
#
# recursively generates all permutations for the change that can be made using coins
#  with the values in coins for the given amount of money specified in cents by amountCents
#
# coins - See US_COINS = [100, 25, 10, 5, 1]
# amount_cents - the total we are making change for in "cents"
def change(coins, amount_cents):
    if amount_cents == 0:
        yield []
    for coin in coins:
        if coin <= amount_cents:
            for solution in change(coins, amount_cents-coin):
                yield solution + [coin]


# test()
#
# Implement unit tests to verify functionality
#
# Called if __name__=="__main__"
def test():
    print 'Running unit tests...'
    list_6 = list(change(US_COINS, 6))
    assert len(list_6) == 3

    list_27 = list(change(US_COINS, 27))
    for permutation in list_27:
        assert sum(permutation) == 27

    list_50 = list(change(US_COINS, 30))
    for permutation in list_50:
        assert sum(permutation) == 30
    print 'Passed.'


# If anybody ever runs this file, run the unit tests
if __name__ == '__main__':
    test()

    print 'Running Demo...'
    print 'Coin permutations for 6 cents:', list(change(US_COINS, 6))
    print 'Coin permutations for 7 cents:', list(change(US_COINS, 7))
    print 'Coin permutations for 8 cents:', list(change(US_COINS, 8))
