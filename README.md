# **Campus Navigation System**

## Project Description
A Navigational System that helps a user to find the shortest path to his/her destination from any starting point within the campus using C++ Data Structures, Dijkstra Algorithm and Graphics. User is asked to enter the source and destination after which the shortest path is shown to the user in terms of directions("Left","Right","Straight") along with a graphical representation of the path. The Campus data is stored in the form of text files. This Navigation System can be implemented for any kind of campus such as schools,colleges,offices,libraries etc. We have chosen our college CEG as an example.

## Creators
- [Arunachalam M](https://github.com/ArunachalamM101202)
- [Sanjay Pranao BG](https://github.com/JohnWick19)
- [Srirambabu R](https://github.com/rk-srirambabu)

## Table of Contents
- [Data Structures Used](#a)
- [Algorithms Used](#b)
- [OOPS Concepts Used](#c)
- [Image of the Campus Map](#d)
- [Graph Representation of the Campus](#e)
- [Why did we do this Project](#f)
- [Challenges Faced](#g)
- [What did we learn from this project?](#h)
- [Licence](#i)

## Data Structures Used <a id="a"></a>
- Directed Graph (using adjacency list)
- Hashmap
- Priority Queue
- Pairs
- Vectors

## Algorithms Used <a id="b"></a>
- Dijkstra's Algorithm

## OOPS Concepts Used <a id="c"></a>
- Class and Object
- Constructors
- Destructors
- Exception Handling
- File Handling

## Image of the Campus Map <a id="d"></a>
![alt text](https://github.com/CEG-Dragons/Campus-Navigation-System/blob/main/Project_files/map.jpeg)

## Graph Representation of the Campus <a id="e"></a>
![alt text](https://github.com/CEG-Dragons/Campus-Navigation-System/blob/main/Project_files/Graph_Image.png)
## Working Demo
To be included soon

## Why did we do this Project? <a id="f"></a>
Our college is very large and often visitors tend to lose their path in the campus. Often times even students get confused with the route to their departments or hostels. Our college does have a huge map in the front, but it is just a plain map which is difficult to read and understand directions. Some people spend a lot of time in searching for a building within the campus. To solve this problem we decided to create a campus navigation system that will provide the shortest path from one point to another, not only within our campus but to all campuses. This helps in saving a lot of time for everyone as they simply enter where they are, where they want to go and within few seconds they get the clear path and don't need to waste a lot of time enquiring others for directions

## Challenges Faced <a id="g"></a>
We faced a lot of new challenges while building this project. The first major challenge was to decide how to create a standard way to represent any campus in the form of a graph. This was solved by using File Handling as we required only the names of the buildings to be included, how the buildings are connected with one another and the distance between each adjacent building. The next challenge we faced was to convert the shortest path obtained in the form of numbers into directions. We solved this by storing them in a vector and using maps to print the direction based on the relationship between buidings given as input. The final problem we faced were edge cases which was found during intensive testing of the project. We have included a file [corner_cases.txt](https://github.com/CEG-Dragons/Campus-Navigation-System/blob/main/Project_files/corner_cases.txt) which stores the edge cases we encountered during testing.

## What did we learn from this project? <a id="h"></a>
We were able to explore in depth about the implementation of graph data structures in C++ in this project. We were able to apply many algorithms and data structures from STL(Standard Template Library) which helped us enhance our knowledge about STL. We were able to understand implmentation of File handling and how each file is accessed. This project also helped us to use the concepts of Object Oriented Programming in real time.

## Licence <a id="i"></a>
Campus Navigational System Project is licenced under MIT Licence. Read [MIT Licence](https://github.com/CEG-Dragons/Campus-Navigation-System/blob/main/LICENSE) to know more
