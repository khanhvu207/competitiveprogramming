import random


def isWin(userChoice, computerChoice):
    winning = {"rock": "scissors",
               "paper": "rock",
               "scissors": "paper",
               }
    return winning[userChoice] == computerChoice


def printFinalScore(score):
    winner = max(score.keys(), key=score.get)
    print("The final score is:")
    print("Computer: {}".format(score["Computer"]))
    print("User: {}".format(score["User"]))
    print("\n{} has won the game!".format(winner))


def getUserChoice(choices):
    userChoice = ""
    while userChoice not in choices:
        userChoice = input("\nRock, paper or scissors? You can also enter 0, 1 or 2.\n").lower()
        if userChoice.isnumeric() and int(userChoice) in range(3):
            userChoice = choices[int(userChoice)]
    return userChoice


def memoization(gameHistory):
    choices = ['rock', 'paper', 'scissors']
    counter = [0] * 3

    HumanMovesHistory = []
    for game in gameHistory:
        HumanMovesHistory.append(game[0])

    gameLength = len(HumanMovesHistory)

    if gameLength < 5:
        return random.choice(choices)

    last2move = [HumanMovesHistory[gameLength - 2], HumanMovesHistory[gameLength - 1]]

    for i in range(0, gameLength - 3):
        if HumanMovesHistory[i] == last2move[0] and HumanMovesHistory[i + 1] == last2move[1]:
            if HumanMovesHistory[i + 2] == choices[0]:
                counter[0] += 1
            elif HumanMovesHistory[i + 2] == choices[1]:
                counter[1] += 1
            elif HumanMovesHistory[i + 2] == choices[2]:
                counter[2] += 1

    maxCounter = max(counter)

    if maxCounter == 0:
        return random.choice(choices)

    for i in range(3):
        if maxCounter == counter[i]:
            return choices[i]


def getStatisticsPrediction(gameHistory):
    choices = ["rock", "paper", "scissors"]
    stats = {"win": {"same": 0, "opponents": 0, "unused": 0},
             "lose": {"same": 0, "opponents": 0, "unused": 0},
             "draw": {"same": 0, "opponents": 0, "unused": 0}}

    group = "none"

    for i, [userChoice, computerChoice] in enumerate(gameHistory):
        if i + 1 == len(gameHistory):
            break

        nextUserMove = gameHistory[i + 1][0]

        if userChoice == computerChoice:
            group = "draw"
        elif isWin(userChoice, computerChoice):
            group = "win"
        else:
            group = "lose"

        if nextUserMove == userChoice:
            move = "same"
        elif nextUserMove == computerChoice:
            move = "opponents"
        else:
            move = "unused"

        stats[group][move] += 1

    if group == "none":
        return random.choice(choices)

    lastGame = gameHistory[-1]

    choices.remove(lastGame[0])
    if gameHistory[-1][0] in choices:
        choices.remove(lastGame[0])

    lastMoves = {"same": lastGame[0],
                 "opponents": lastGame[1],
                 "unused": choices[0]}
    # print(stats)
    return lastMoves[max(stats[group].keys(), key=stats[group].get)]


def getScore(gameHistory, functionName):
    score = 0
    amount = min(20, len(gameHistory))
    gameHistory = gameHistory[-amount:]

    for i in range(len(gameHistory)):
        partOfGameHistory = gameHistory[:i]
        # print(partOfGameHistory)

        prediction = functionName(partOfGameHistory)
        realMove = gameHistory[i][0]
        if prediction == realMove:
            score += 1

        # print(prediction, realMove)
    return score


def getCounter(move):
    counters = {"paper": "scissors",
                "rock": "paper",
                "scissors": "rock",
                }
    return counters[move]


def getOptimalChoice(gameHistory):
    memoScore = getScore(gameHistory, memoization)
    statScore = getScore(gameHistory, getStatisticsPrediction)

    print("Memo score: {} Stat score:{}".format(memoScore, statScore))

    if memoScore > statScore:
        prediction = memoization(gameHistory)
    else:
        prediction = getStatisticsPrediction(gameHistory)

    return getCounter(prediction)


def main():
    choices = ["rock", "paper", "scissors"]
    score = {"Computer": 0, "User": 0}
    userInput = ""
    gameHistory = []

    print("Enter 'start new game' to start the game")

    while userInput != "start new game":
        userInput = input("What to do? ").strip().lower()

    while max(score.values()) < 444:

        # computerChoice = random.choice(choices)
        userChoice = getUserChoice(choices)
        computerChoice = getOptimalChoice(gameHistory)

        print("_" * 60)

        print("You picked {}. The computer picked {}".format(userChoice, computerChoice))
        if userChoice == computerChoice:
            print("Draw!")
        elif isWin(userChoice, computerChoice):
            print("Win!")
            score["User"] += 1
        else:
            print("Lose!")
            score["Computer"] += 1

        gameHistory.append([userChoice, computerChoice])
        print(score)
        print("_" * 60)
    printFinalScore(score)


if __name__ == '__main__':
    main()
