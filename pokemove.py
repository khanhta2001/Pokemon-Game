"""
Starter code for the PokeMove class of the Pokemon Project

@Author: Brian Law
"""
import random
from typing import Optional

class PokeMove:
    """
    A class representing a move that Pokemon can learn and use.
    """

    def __init__(self, name: str,	poketype: str, power: str, pp: str, accuracy: str, priority: str,	effect: str,	effect_chance: str):
        """Initializes Gen1 Pokemon moveset
        :param name: The name of the move
        :param type: The move's type
        :param power: The power stat of the move, if it has one
        :param pp: The power point of a move
        :param accuracy: The percentage chance that a move will go through
        :param priority: The move's priority to occur, if it exists
        :param effect: The move's effect it incurs when used, if it has one
        :param effect_chance: If the move has an effect, the percentage chance of the effect happening, if it has one
        """


        self.name = name
        self.poketype = poketype
        if power == '':
          self.power = power
        else:
          self.power = int(power)

        if pp == '':
          self.pp = pp
        else:
          self.pp = int(pp)

        if accuracy == '':
          self.accuracy = accuracy
        else:
          self.accuracy = int(accuracy)

        self.priority = priority

        if effect == '':
          self.effect = None
        else:
          self.effect = effect

        if effect_chance == '':
          self.effect_chance = None
        else:
          self.effect_chance = int(effect_chance)

    def __str__(self):
        return self.move_type

    def __repr__(self):
        return 'name = ' + self.name + ', type = ' + self.move_type + ', power = ' + self.power + ', pp = ' + self.pp + ', accuracy = ' + self.accuracy + ', priority = ' + self.priority + ', effect = ' + str(self.effect) + ', effect_chance = ' + str(self.effect_chance)
        return self.move_type

    # no accuracy = NEVER misses
    def eval_effect_chance(self):
      """Determines
      """

      if self.effect == False:
        return False
      elif self.effect_chance == False:
        return True
      else:
        if random.randint(1, 100) > self.effect_chance:
          return False
        else:
          return True