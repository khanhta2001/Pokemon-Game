"""
Starter code for the Pokemon class of the Pokemon Project

@Author: Brian Law
"""
import math
import random
from typing import List

import pokeconstants
import pokemove
import io_functions

class Pokemon:
    """
    A class representing individual Pokemon.
    """

    def __init__(self, name: str, level: int, iv: dict, ev: dict, moves: List[str]):
        """Initializes the pokemon, their statistics, and their moves
        :param name: The pokemon's name
        :param lvl: The pokemon's level
        :param iv: A list of the pokemon's IV stats
        :param ev: A list of the pokemon's EV stats
        :param moves: A list of the pokemon's moveset
        """

        self.name = name

        self.level = level

        self.iv = {'Attack' : iv[0], 'Defense' : iv[1], 'Speed' : iv[2], 'Special' : iv[3], 'HP' : iv[4]}

        self.ev = {'Attack' : ev[0], 'Defense' : ev[1], 'Speed' : ev[2], 'Special' : ev[3], 'HP' : ev[4]}

        self.moves = []

        for move in moves:
          self.moves.append(pokeconstants.MOVES.get(move))
        self.status = None

        self.current_hp = self.calc_stat("HP")

    def calc_stat(self, stat_name: str) -> float:
        """Calculates a non-HP stat for a pokemon (special, defense, special attack/defense, and speed)

        :param base: the pokemon's base stat
        :param iv: the pokemon's IV
        :param ev: the pokemon's EV
        :param level: the pokemon's level
        :return: the stat's value
        """
        if stat_name == 'HP':
           return math.floor(((float(pokeconstants.POKE_DATA[self.name][stat_name]) + float(self.iv['HP'])) * 2 + math.floor(float(math.sqrt(self.ev['HP'])) / 4)) * self.level / 100) + float(self.level) + 10

        if stat_name == 'Defense':
          return math.floor(((float(pokeconstants.POKE_DATA[self.name]['Defense']) + float(self.iv['Defense'])) * 2 + math.floor(math.sqrt(float(self.ev['Defense'])) / 4)) * float(self.level) / 100) + 5

        else:
          # base is replaced with stat_name
          return math.floor(((float(pokeconstants.POKE_DATA[self.name][stat_name]) + float(self.iv[stat_name])) * 2 + math.floor(math.sqrt(float(self.ev[stat_name])) / 4)) * float(self.level) / 100) + 5

    def choose_random_move(self):
        """ Randomly determines which move a Pokemon is going to use

        Move elements are as follows:
        [str: name, str: type, int: power, float: accuracy, int: PP, str: effect, float: effect chance]

        :param moves: a 2D list of the Pokemon's moves
        :return: the list representing the chosen move
        """
        index = random.randint(0, len(self.moves) - 1)
        a = self.moves[index]

        return a

    def __str__(self):
        return "pokemon name: {self.name} and its level: {self.level}".format(self = self)

    def __repr__(self):
        return "pokemon name: {a} and its level: {b}".format(a = self.name, b = self.level)