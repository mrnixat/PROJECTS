#ifndef SML_H
#define SML_H

//********************************************************************
//
// sml.h
// CSCI 241 Assignment 8
//
// Created by Yousuf Khan, Niko Tsakiridis
// ZID: Z2004989, Z1986104
//
//********************************************************************

// Input & Output Operations
// *************************
#define READ 11
#define WRITE 12

// Store & Load Operations
// ***********************
#define STORE 21
#define LOAD 22


// Arithmetic Operations
// *********************
#define ADD 31
#define SUBTRACT 32
#define MULTIPLY 33
#define DIVIDE 34

// Transfer of Control Operations
// ******************************
#define BRANCH 41
#define BRANCHZERO 42
#define BRANCHNEG 43
#define HALT 44


// DEFAULT
// *******
#define DEFAULT 7777   // Default value for empty memory elements

#endif