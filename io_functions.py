from typing import Dict, Union, List

import pokemove


def read_type_chart(filename: str) -> Dict[str, Dict[str, float]]:
    """ Reads in a tabular format type chart into a nested dictionary for use.

    Input file format: Rows are the attack type. Columns are the defending Pokemon types.
    First row is a header row for types. Second row is a header for the y-axis columns. First column is a header column.

    :param filename: the filename for the type chart data
    :return: a dictionary mapping attack types to defending Pokemon types to the effectiveness multiplier {0, 0.5, 1, 2}
    """
    with open(filename) as f:
        lines = f.readlines()
    type_chart = {}

    # The type chart happens to have rows and columns in the same order, but just in case, this fetches
    # the column names (defense types) in order for parsing
    top_types = lines[0].rstrip('\n').split("\t")

    for row_no in range(2, len(lines)):
        split = lines[row_no].rstrip('\n').split('\t')
        attack_type = split[0]

        type_chart[attack_type] = {}

        for col_no in range(1, len(split)):
            defense_type = top_types[col_no]
            type_chart[attack_type][defense_type] = float(split[col_no])

    return type_chart


def read_type_physical(filename: str) -> Dict[str, bool]:
    """ Read in and process a listing of attack types and their physical/special nature.

    Input file format: tab-delimited, first column is special types, second column is physical types.
    First row is header row. Subsequent rows are Pokemon types or empty.

    :param filename: the name of a plaintext file listing which attack types are physical or special
    :return: a dictionary mapping attack types to a boolean indicating whether they are physical
    """
    with open(filename) as f:
        lines = f.readlines()[1:]
    type_physical_mapping = {}

    for line in lines:
        split = line.rstrip('\n').split('\t')

        if split[0]:  # need to check that this "cell" is not blank
            type_physical_mapping[split[0]] = False
        if split[1]:  # need to check that this "cell" is not blank
            type_physical_mapping[split[1]] = True

    return type_physical_mapping


def read_moves(filename: str) -> Dict[str, float]:
    """ Reads and processes a listing of all the moves in the game and their attributes.

    Input file format: tab-delimited, first column is Id, second is Name, and so on in the order seen below

    :param filename: the name of the text file containing the move's Id,	Name,	Type,	Power,	Pp,	Accuracy,	Priority,	Effect, and	Effect Chancel
    :return: a dictionary mapping the move names to the class PokeMove
    """
    with open(filename) as f:
        contents = f.read().splitlines()

    moves = {}

    for line in contents[1:]:
        line_split = line.split('\t')

        move_name = line_split[1]

        moves[move_name] = pokemove.PokeMove(line_split[1], line_split[2], line_split[3], line_split[4], line_split[5],
                                             line_split[6], line_split[7], line_split[8])
        # if line_split[3] not = '':
        # int(line_split[3])

    return moves


# accuracy = line[5]
# if accuracy == '':
# accuracy = None

def read_pokemon(filename: str):
    with open(filename) as file:
        contents = file.read().splitlines()

    pokemon = {}
    poke_list = []
    for line in contents[1:]:
        line_split = line.split('\t')
        if line_split[8] == "":
            line_split[8] = None
            pokemon_name = line_split[1]
            poke_list = []
            poke_list.append(line_split[7])
            pokemon[pokemon_name] = {}
            pokemon[pokemon_name]["HP"] = line_split[2]
            pokemon[pokemon_name]["Attack"] = line_split[3]
            pokemon[pokemon_name]["Defense"] = line_split[4]
            pokemon[pokemon_name]["Speed"] = line_split[5]
            pokemon[pokemon_name]["Special"] = line_split[6]
            pokemon[pokemon_name]["Type"] = poke_list


        else:
            pokemon_name = line_split[1]
            pokemon[pokemon_name] = {}
            pokemon[pokemon_name]["HP"] = line_split[2]
            pokemon[pokemon_name]["Attack"] = line_split[3]
            pokemon[pokemon_name]["Defense"] = line_split[4]
            pokemon[pokemon_name]["Speed"] = line_split[5]
            pokemon[pokemon_name]["Special"] = line_split[6]
            pokemon[pokemon_name]["Type"] = (line_split[7], line_split[8])

    return pokemon
