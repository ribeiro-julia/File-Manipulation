# File-Manipulation-with-C++-

A C++ program that converts an specific .CSV file to a structured binary file, while performing data cleaning and validation. It's main purpose it's to help people learning the basics in file manipulation in C++ 

## License
	GPL-3.0

## Features

- Reads athlete event data from a .csv file
- Cleans unwanted characters (parentheses and hyphens)
- Converts data to a structured binary format
- Error handling for file operations
- Interactive console menu

## Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- Standard C++ libraries

## Data Structure

The program uses the following structure for each record:
```cpp
struct dataFormat {
    char id[6];
    char name[30];
    char city[20];
    char sport[30];
    char event[20];
    char noc[3];
};
