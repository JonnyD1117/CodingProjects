# CodingProjects
This repo contains numerous miscellaneous projects designed to help me understand, implement, and test coding ideas and concepts.

## Assembly 
Directory for containing assembly code for fun and profit.

## Computer Graphics

## Computer Vision 
Directory containing projects to play-around with and implement different computer vision concepts and algorithms. 

Current projects include... 
- [x] Zero Normalized Cross-Correlation [but its SLOW :( ]
- [] Stereo Block Matching 
- [] Stereo Correspondence via Dynamic Programming 
- [] Semi-Global Matching
- [x] Template Matching 
- [] Camera Modeling & Calibration 

## Data Structures

Implements C++ STL-like data structures for practicing Modern C++ techniques and learning data structures and algorithms. These data structures attempt to implement as many of the features that are currently available on STL containers such as using iterators and adaptors. Time permitting it would be interesting to try and write a custom memory allocator for some of these implementations. Additionally, these custom containers attempt to use some level of Unit Testing to ensure that everything is functioning as expected. 

- [x] Array 
- [x] Linked List 
- [x] Matrices [Not Complete but basic matrix multiplication works]
- [x] Dynamic Arrays
- [] Queue 
- [] Priority Queue
- [] Hash Maps / Associative Arrays 
- [] Graph
- [] Set
- [] Stack
- [] Deque
- [] Tree
- [] Heap

## Eigen Practice
Eigen is C++ Matrix library that is ubiquitous throughout many C++ applications requiring Linear Algebra. The objective of this project is to learn the fundamentals of the Eigen. At the moment, my main ideas for "trying-out" Eigen involve either dummy Linear Algebra problems or linear state-space control ideas.

## Functional-Style Finite State Machine

## JsonParser
The objective of this project is to understand and implement a simple Json parser that allows for encoding a Json file into a useable OOP structure that can be queried and decoded. 

This requires tokenization of the input file (or string) which can then be fed into the Json Parser that is responsible for the creation of a `JsonObject` which can be used directly, similar to a dictionary in Python. 

## Machine Learning 

## Mathematics 



## Modeling & Simulation 

### Quadcopter Model
### Guidance, Navigation, & Control 

### Finite Element Analysis

## Networking Practice 

This project is my playground for learning the basics of computer networking with a particular focus on using TCP/IP, asynchronous networking, as well as exploring different networking libraries like ZMQ.


## PyBind11

PyBind11 is a useful library that enables compiled code written in C++ to be directly invoked by the Python interpreter. This enables the easy of writing scripts in Python that invoke method that would benefit from the native speed of compiled C++ binaries. This is useful for performing large computations in C++ and then sending the result to Python where it can easily be displayed using `Matplotlib` or other modules.

My main objective with this project is to gain competency in PyBind11 for use with simulation that I would like to interact with from Python but run in C++.


## Robotics 

Current this project is my scratch pad for interesting robotics concepts, algorithms, and code that I would like to try and work on. 