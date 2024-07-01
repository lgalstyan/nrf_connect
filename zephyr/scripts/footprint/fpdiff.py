#!/usr/bin/env python3
# Copyright (c) 2021 Intel Corporation
#
# SPDX-License-Identifier: Apache-2.0

# A script to diff between two ram or rom reports generated by
# size_report. When you call call the ram_report or rom_report targets you
# end up with a json file in the build directory that can be used as input
# for this script.

# The output shows which symbols increased and which decreased in size and
# also tracked added/remove symbols as well.

# Example:
#    ./scripts/footprint/fpdiff.py ram1.json ram2.json

from anytree.importer import DictImporter
from anytree import PreOrderIter
from anytree.search  import find

import colorama
from colorama import Fore
import json
import argparse

importer = DictImporter()

def parse_args():
    parser = argparse.ArgumentParser(
                description="Compare footprint sizes of two builds.", allow_abbrev=False)
    parser.add_argument("file1", help="First file")
    parser.add_argument("file2", help="Second file")

    return parser.parse_args()

def main():
    colorama.init()

    args = parse_args()

    with open(args.file1, "r") as f:
        data1 = json.load(f)

    with open(args.file2, "r") as f:
        data2 = json.load(f)

    for idx, ch in enumerate(data1['symbols']['children']):
        root1 = importer.import_(ch)
        root2 = importer.import_(data2['symbols']['children'][idx])
        print(f"{root1.name}\n+++++++++++++++++++++")

        for node in PreOrderIter(root1):
            # pylint: disable=undefined-loop-variable
            n = find(root2, lambda node2: node2.identifier == node.identifier)
            if n:
                if n.size != node.size:
                    diff = n.size - node.size
                    if diff == 0:
                        continue
                    if not n.children or not n.parent:
                        if diff < 0:
                            print(f"{n.identifier} -> {Fore.GREEN}{diff}{Fore.RESET}")
                        else:
                            print(f"{n.identifier} -> {Fore.RED}+{diff}{Fore.RESET}")

            else:
                if not node.children:
                    print(f"{node.identifier} ({Fore.GREEN}-{node.size}{Fore.RESET}) disappeared.")

        for node in PreOrderIter(root2):
            n = find(root1, lambda node2: node2.identifier == node.identifier)
            if not n:
                if not node.children and node.size != 0:
                    print(f"{node.identifier} ({Fore.RED}+{node.size}{Fore.RESET}) is new.")


if __name__ == "__main__":
    main()
