"""
Starter code for the main simulation of the Pokemon Project

@Author: Brian Law
"""
import math
import random
from typing import List, Tuple

import pokeconstants
import pokemon
import pokemove

# I needed counter to be a global counter, which is why it's here in the open
counter = random.randint(2,7)

def eval_crit(base_speed: int) -> bool:
  """ Determines whether a Pokemon's attack will critically hit.

  :param base_speed: the base speed stat of the attacking Pokemon
  :return: True iff a critical hit occurs
  """
  return random.randint(1, 512) < int(base_speed)


def calc_damage(level: int, power: int, attack: int, defense: int, stab_bonus: float, type_bonus: float, move_effect: str) -> int:
  """ Calculates the damage done when a pokemon attacks another pokemon

  :param level: the attacker's level
  :param power: the power of the attack
  :param attack: the attacker's attack/special stat
  :param defense: the defender's defense/special stat
  :param stab_bonus: whether the Same-Type-Attack-Bonus applies
  :param type_bonus: the type effectiveness modifier for the attack against the defender (0, 0.25, 0.5, 1, 2, or 4)
  :param move_effect: the type of move being used, to determine if this function is needed and to stop it from breaking
  :return: the damage dealt to the defender, if any
  """
  if move_effect == 'Sleep':
    return 0
  random_modifier = random.randint(85, 100) / 100
  return math.floor(((2 * level / 5 + 2) * power * attack / defense / 50 + 2) * random_modifier * stab_bonus * type_bonus)

def process_attack(attacker: pokemon.Pokemon, defender: pokemon.Pokemon, move: pokemove.PokeMove) -> List[str]:
  """

  :param attacker: the attacking Pokemon
  :param defender: the defending Pokemon
  :param move: the move being used by the attacking Pokemon
  :return: a list of the text output to be sent to the user
  """

  str_output = [attacker.name + ' uses ' + move.name + '!']

  # Accuracy
  if move.accuracy == None:
    pass
  else:
    if random.randint(1, 100) >= int(move.accuracy):
      str_output.append('It missed!')
      return str_output

  level = attacker.level
  if eval_crit(pokeconstants.POKE_DATA[attacker.name]['Speed']):
    level *= 2
    str_output.append('Critical hit!')

  if pokeconstants.PHYSICAL_TYPES[move.poketype]:
    # Considers the attack stat of a burning pokemon.
    if attacker.status == 'Burning':
      attacker_stat = attacker.calc_stat('Attack') / 2
    else:
      attacker_stat = attacker.calc_stat('Attack')
    defender_stat = defender.calc_stat('Defense')
  else:
    attacker_stat = attacker.calc_stat('Special')
    defender_stat = defender.calc_stat('Special')

  if move.poketype in pokeconstants.POKE_DATA[attacker.name]['Type']:
    stab_bonus = 1.5
  else:
    stab_bonus = 1
  type_bonus = get_type_effectiveness(move, pokeconstants.POKE_DATA[defender.name]['Type'])

  damage = calc_damage(level, move.power, attacker_stat, defender_stat, stab_bonus, type_bonus, move.effect)

  defender.current_hp = max(defender.current_hp - damage, 0)

  # Just because it was easy to implement.
  if move.poketype == 'Fire' and defender.status == 'Frozen':
    str_output.append(defender.name + ' was thawed! It\'s no longer frozen!')
    defender.status = None

  #Determine if defending pokemon is effected by a status of a move.

  if move.effect == 'Paralyze':
    if move.effect_chance == None:
      defender.status = 'Paralyzed'
      str_output.append(defender.name + ' is paralyzed! It may not attack!')
    else:
      if random.randint(1, 100) <= move.effect_chance:
        defender.status = 'Paralyzed'
        str_output.append(defender.name + ' is paralyzed! It may not attack!')

  if move.effect == 'Poison':
    if move.effect_chance == None:
      defender.status = 'Poisoned'
      str_output.append(defender.name + ' was poisoned.')
    else:
      if random.randint(1, 100) <= move.effect_chance:
        defender.status = 'Poisoned'
        str_output.append(defender.name + ' was poisoned.')

  global sleep_counter
  if move.effect == 'Sleep':
    defender.status = 'Sleeping'
    str_output.append(defender.name + ' fell asleep!')

  if move.effect == 'Burn':
    if random.randint(1, 100) <= move.effect_chance:
      defender.status = 'Burning'
      str_output.append(defender.name + ' was burned!')

  if move.effect == 'Freeze':
    if random.randint(1, 100) <= move.effect_chance:
      defender.status = 'Frozen'
      str_output.append(defender.name + ' was frozen solid!')



  #Outputs the effects of the status, if it is afflicted by one. Some effects, like ones that end the turn of a pokemon, are at the bottom of simulate_battle.

  if defender.status == 'Poisoned':
    defender.current_hp = defender.current_hp - math.floor(defender.current_hp * .0625)
    str_output.append(defender.name + '\'s hurt by poison!')

  if defender.status == 'Burning':
    defender.current_hp = defender.current_hp - math.floor(defender.current_hp * .0625)
    str_output.append(defender.name + '\'s hurt by the burn!')

  if type_bonus == 0:
    str_output.append("It doesn't affect " + defender.name)
  else:
    if type_bonus > 1:
      str_output.append("It's super-effective!")
    elif 0 < type_bonus < 1:
      str_output.append("It's not very effective...")
    str_output.append(defender.name + " takes " + str(damage) + " damage!")
  str_output.append(defender.name + " has " + str(defender.current_hp) + " HP remaining.")

  return str_output


def get_type_effectiveness(chosen_move: pokemove.PokeMove, defense_type) -> float:
  """ Calculates the type bonus modifier for a particular attack type against a Pokemon type.

  :param chosen_move: the attack being used
  :param defense_type: a list of the defending Pokemon's types, capitalized
  :return: the effectiveness multiplier for the attack {0, 0.25, 0.5, 1, 2, or 4)
  """
  result = 1
  for def_type in defense_type:
    result *= pokeconstants.TYPE_CHART[chosen_move.poketype][def_type]

  return result


def simulate_battle():
    pokemon1 = pokemon.Pokemon('Pikachu', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                               ['ThunderShock', 'Swift', 'Thunderbolt', 'Mega Punch'])
    pokemon1a = pokemon.Pokemon('Mew', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                                ['Pound', 'Mega Punch', 'Psychic'])
    pokemon1b = pokemon.Pokemon('Mewtwo', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                                ['Confusion', 'Psychic', 'Swift'])
    pokemon1c = pokemon.Pokemon('Blastoise', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Water Gun', 'Bite', 'Hydro Pump', 'Ice Beam'])
    pokemon1d = pokemon.Pokemon('Bulbasaur', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Tackle', 'Vine Whip', 'Razor Leaf', 'Solar Beam'])
    pokemon1e = pokemon.Pokemon('Charmander', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Scratch', 'Ember', 'Rage', 'Slash', 'Flamethrower', 'Fire Spin'])
    pokemon2 = pokemon.Pokemon('Pikachu', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                               ['ThunderShock', 'Swift', 'Thunderbolt', 'Mega Punch'])
    pokemon2a = pokemon.Pokemon('Mew', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                                ['Pound', 'Mega Punch', 'Psychic'])
    pokemon2b = pokemon.Pokemon('Mewtwo', 81, [8, 13, 90, 9, 7], [23140, 17280, 24795, 19625, 22850],
                                ['Confusion', 'Psychic', 'Swift'])
    pokemon2c = pokemon.Pokemon('Blastoise', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Water Gun', 'Bite', 'Hydro Pump', 'Ice Beam'])
    pokemon2d = pokemon.Pokemon('Bulbasaur', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Tackle', 'Vine Whip', 'Razor Leaf', 'Solar Beam'])
    pokemon2e = pokemon.Pokemon('Charmander', 81, [14, 9, 17, 8, 9], [28181, 15907, 3433, 13750, 19005],
                                ['Scratch', 'Ember', 'Rage', 'Slash', 'Flamethrower', 'Fire Spin'])
    team1 = []
    team1.append(pokemon1)
    team1.append(pokemon1a)
    team1.append(pokemon1b)
    team1.append(pokemon1c)
    team1.append(pokemon1d)
    team1.append(pokemon1e)
    team2 = []
    team2.append(pokemon2)
    team2.append(pokemon2a)
    team2.append(pokemon2b)
    team2.append(pokemon2c)
    team2.append(pokemon2d)
    team2.append(pokemon2e)

    x = 0
    y = 0
    global sleep_counter

    while x <= 5 and y <= 5:
        while team1[x].current_hp > 0 and team2[y].current_hp > 0:
            # Determine which Pokemon goes first; has to be done here, at the start

            # Considers the speed of a pokemon if it is paralyzed
            if team1[x].status == 'Paralyzed':
                pokemon1_speed = team1[x].calc_stat('Speed') / 4
            else:
                pokemon1_speed = team1[x].calc_stat('Speed')

            if team2[y].status == 'Paralyzed':
                pokemon2_speed = team2[y].calc_stat('Speed') / 4
            else:
                pokemon2_speed = team2[y].calc_stat('Speed')

            pokemon1_first = pokemon2_speed < pokemon1_speed or (
                        pokemon1_speed == pokemon2_speed and random.randint(0, 1) == 0)

            # A trick here to simplify code later. Use aliases for the Pokemon depending on their move order
            if pokemon1_first:
                first_pokemon = team1[x]
                second_pokemon = team1[x]
            else:
                first_pokemon = team2[y]
                second_pokemon = team1[x]

            # As mentioned earlier, statuses that affect the length of turns are deal with here in simulate_battle
            if team1[x].status != 'Sleeping':
                sleep_counter = counter

            if team1[x].status == 'Paralyzed' and random.randint(1, 4) == 1:
                print(team1[x].name + ' is paralyzed! It can\'t move!')

            elif team1[x].status == 'Frozen':
                print(team1[x].name + ' is frozen solid!')

            elif team1[x].status == 'Sleeping':
                sleep_counter -= 1
                if sleep_counter > 0:
                    print(team1[x].name + ' is fast asleep.')
                else:
                    print(team1[x].name + ' woke up!')
                    team1[x].status = None
                    sleep_counter = counter
                    pass

            else:
                move = first_pokemon.choose_random_move()

                output = process_attack(team1[x], team2[y], move)
                for output_line in output:
                    print(output_line)
                print('')

            if second_pokemon.current_hp > 0:

                if team2[y].status == 'Paralyzed' and random.randint(1, 4) == 1:
                    print(team2[y].name + ' is paralyzed! It can\'t move!')

                elif team2[y].status == 'Frozen':
                    print(team2[y].name + ' is frozen solid!')

                elif team2[y].status == 'Sleeping':
                    sleep_counter -= 1
                    if sleep_counter > 0:
                        print(team2[y].name + ' is fast asleep.')
                    else:
                        print(team2[y].name + ' woke up!')
                        team2[y].status = None
                        sleep_counter = counter
                        pass

                else:
                    move = second_pokemon.choose_random_move()

                    output = process_attack(team2[y], team1[x], move)
                    for output_line in output:
                        print(output_line)
                    print('')

                if team1[x].current_hp == 0:
                    print(team1[x].name + " has fainted!")
                    x += 1
                    if x == 5:
                        print("Team 2 has won the battle!")
                        break
                    else:
                        print(team1[x].name + " has joined the battle!")

                if team2[y].current_hp == 0:
                    print(team2[y].name + " has fainted!")
                    y += 1
                    if y == 5:
                        print("Team 1 has won the battle!")
                        break
                    else:
                        print(team2[y].name + " has joined the battle!")